<?php
/**
 * @file
 * Module logic and API.
 */

/**
 * Clean vocabulary.
 */
function site_common_vocabulary_clear($vid) {
  if (!is_numeric($vid)) {
    if ($vocabulary = taxonomy_vocabulary_machine_name_load($vid)) {
      $vid = $vocabulary->vid;
    }
    else {
      // Cant find vocabulary.
      return;
    }
  }
  $terms = taxonomy_term_load_multiple(array(), array('vid' => $vid));
  foreach ($terms as $term) {
    taxonomy_term_delete($term->tid);
  }
  return $terms;
}

/**
 * Get library path.
 */
function site_common_librarly_path($name) {
  // Check subsite.
  $suggestions = array(
    variable_get('site_common_librarly_path_' . $name, FALSE),
    conf_path() . '/libraries/' . $name,
    'sites/all/libraries/' . $name,
  );
  foreach (array_filter($suggestions) as $path) {
    if (file_exists($path)) {
      return $path;
    }
  }
}

/**
 * Replacement for user_edit_access().
 */
function site_common_user_edit_access($account) {
  return user_access(SITE_COMMON_PERM_USERS_MANAGE) || user_edit_access($account);
}

/**
 * Replacement for user_edit_access().
 */
function site_common_user_create_access($permissions) {
  global $user;
  // To access creation form user has to have "administer users" permission
  // as access check is done inside the form builder.
  $user_access = &drupal_static('user_access');
  $access = site_common_user_access($permissions);

  if ($access && $_GET['q'] == 'admin/people/create') {
    // This action is not that scary as by default user would have this permission anyway
    // so should not be a security problem.
    $user_access[$user->uid]['administer users'] = TRUE;
  }
  return $access;
}

/**
 * Check user acceess.
 */
function site_common_user_access($permissions, $account = NULL) {
  $access = FALSE;
  if (!is_array($permissions)) {
    $permissions = array($permissions);
  }
  while (!$access && $string = array_shift($permissions)) {
    $access = user_access($string, $account);
  }

  return $access;
}

/**
 * Parse CSS selector into html structure.
 */
function site_common_parse_selector($selector) {
  $tags = array();
  $tags_selectors = explode(' ', $selector);
  foreach ($tags_selectors as $tags_selector) {
    // Prepare variables.
    $tag = '';
    $id = '';
    $class = array();

    // Transform selector into attributes.
    $tmp = explode('#', $tags_selector);
    if (count($tmp) > 1) {
      $tag = array_shift($tmp);
    }
    $tmp = explode('.', $tmp[0]);
    if (empty($tag)) {
      $tag = array_shift($tmp);
      $class = $tmp;
    }
    else {
      $id = array_shift($tmp);
      $class = $tmp;
    }

    // Build tags.
    if (!empty($tag)) {
      $tags[] = array(
        '#tag' => $tag,
        '#attributes' => array_filter(array(
          'id' => $id,
          'class' => $class,
        )),
      );
    }
  }

  return $tags;
}

/**
 * Generic submit function that marks form as submitted.
 */
function site_common_form_submit_manual(&$form, &$form_state) {
  // Mark as submit.
  $form['#_submitted'] = TRUE;

  // This will skip redirect.
  $form_state['no_redirect'] = TRUE;

  // Pass $form_state back to form.
  $form['#_form_state'] = $form_state;
}

/**
 * Create Ajax clickable element.
 */
function site_common_ajax_link($title, $path, $options = array(), $method = 'POST', $sendid = FALSE) {
  // Generate link options.
  $options['attributes']['class'][] = 'site-common-ajax-call';
  $options['attributes']['class'][] = 'site-common-jqm-navigate-disabled';
  $options['attributes']['data-site-common-ajax-url'] = url($path, $options);
  if ($method != 'POST') {
    $options['attributes']['data-site-common-ajax-method'] = $method;
  }
  if ($sendid) {
    $options['attributes']['data-site-common-ajax-sendid'] = 'true';
  }

  // Return link.
  return l($title, '', $options);
}

/**
 * Create Ajax element.
 */
function site_common_ajax_elment($group, $path, $attributes = array(), $method = 'POST') {

  // Generate attributes.
  $attributes['class'][] = 'site-common-ajax-group-' . $group;
  $attributes['data-site-common-ajax-url'] = url($path, array('absolute' => TRUE));
  if ($method != 'POST') {
    $attributes['data-site-common-ajax-method'] = $method;
  }
  if (!isset($attributes['data'])) {
    $attributes['data'] = '';
  }
  // Return element.
  return site_common_render_tag('div', $attributes);
}

/**
 * Add async js if it is not already added.
 *
 * If script is already added, nothing ill be changed.
 */
function site_common_add_async_js($js_file, $type = FALSE, $name = FALSE) {
  $js_list = drupal_add_js();

  // If type and name not empty - this is args for drupal get path.
  if (!empty($type) && !empty($name)) {
    $js_file = drupal_get_path($type, $name) . '/' . $js_file;
  }

  // If this file is not yet added we add it as async load.
  // @see site_common_preprocess_html().
  if (empty($js_list[$js_file])) {
    //$js_file = url($js_file, array('absolute' => TRUE));
    drupal_add_js($js_file, array('async' => TRUE));
  }
}

/**
 * Flush derivatives for file.
 */
function site_common_flush_derivatives($uri) {
  if (!module_exists('image')) {
    return;
  }

  $styles = image_styles();
  foreach ($styles as $style_name => $style) {
    $derivative = image_style_path($style_name, $uri);
    if (file_exists($derivative)) {
      file_unmanaged_delete($derivative);
    }
  }
}

/**
 * Check if this request is done using
 */
function site_common_is_xmlhttp() {
  if (!empty($_SERVER['HTTP_X_REQUESTED_WITH']) && strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest') {
    return TRUE;
  }
}

/**
 * Return module settings.
 */
function _site_common_settings($block, $setting, $default = NULL) {
  $settings = variable_get('site_common_settings');
  if (isset($settings[$block])) {
    return isset($settings[$block][$setting])
      ? $settings[$block][$setting]
      : $default;
  }
  return $default;
}

/**
 * Include site common js.
 *
 * @param $name
 *   (string) jquery_mobile
 */
function site_common_js_add($name = '', $force = FALSE, $settings = array()) {
  global $theme;

  // Get path and added scripts list.
  $options = NULL;
  $addfile = TRUE;
  $added_list = &drupal_static(__FUNCTION__ . '_list', array());
  $js_path = drupal_get_path('module', 'site_common') . '/js/site-common.' . str_replace('_', '-', $name) . '.js';

  // Add required script.
  if (!empty($name) && empty($added_list[$js_path])) {

    // Add requirements.
    qtools_api__js_add('base');

    // For JQM we need to load all drupal default scripts ahead of time.
    if ($name == 'jquery_mobile') {

      // If this file added, it is present on every page.
      $options['every_page'] = TRUE;

      // Invoke resource preload hook.
      module_invoke_all('site_common_preload_resources');

      // Invoke theme preload resources.
      $theme_hook = $theme . '_site_common_preload_resources';
      if (function_exists($theme_hook)) {
        $theme_hook();
      }
    }

    // Asynk require ajax.
    if ($name == 'async') {
      site_common_js_add('ajax');
    }

    // Add Ajax requirements.
    if ($name == 'ajax') {
      // Add qtools libs.
      qtools_api__js_add('ajax');
      qtools_api__js_add('autocomplete');
    }

    // Add js.
    if ($addfile) {
      drupal_add_js($js_path, $options);
    }
    drupal_add_js(array(
      'site_common' => array(
        $name => $settings,
      )
    ), 'setting');
    $added_list[] = $js_path;
  }
}

/**
 * Safe representation fo given string.
 */
function site_common_safe_string($string, $tags = '') {
  if (empty($tags)) {
    $string = strip_tags($string);
  }
  else {
    $string = filter_xss(strip_tags($string, $tags));
  }
  return $string;
}

/**
 * Render tag with given attributes.
 */
function site_common_render_tag($tag = 'div', array $attributes = array()) {

  // Extract tag data.
  if (isset($attributes['data'])) {
    $data = $attributes['data'];
    unset($attributes['data']);
  }
  else {
    $data = NULL;
  }

  // Support class arrays.
  if (!empty($attributes['class']) && is_array($attributes['class'])) {
    $attributes['class'] = implode(' ', $attributes['class']);
  }

  // Print tag.
  if ($data !== NULL) {
    $output = '<' . $tag . ' ' . drupal_attributes($attributes) . '>' . $data . '</' . $tag .'>';
  }
  else {
    $output = '<' . $tag . ' ' . drupal_attributes($attributes) . ' />';
  }

  return $output;
}

/**
 * Build ajax call command.
 * @param $type
 *   (string) Command type: call/view/form
 * @param $key
 *   (string) Depends on command url/view_name/form_id
 */
function site_common_ajax_command($type, $key, $data = array(), $name = '', $method = 'post', $spam = 5000) {
  return array(
    'command' => 'site_common_ajax',
    'type' => $type,
    'key' => $key,
    'data' => $data,
    'name' => $name,
    'method' => $method,
    'spam' => $spam,
  );
}

/**
 * Build command to load js to the page.
 */
function site_common_ajax_command_async_js($js_src) {

  // Add slash if path is relative.
  if (strpos($js_src, 'http') === FALSE && strpos($js_src, '/') != 0) {
    $js_src = '/' . $js_src;
  }

  return array(
    'command' => 'site_common_async_js',
    'js_src' => $js_src,
  );
}

/**
 * Ajax command to print data to console.
 * // DEPRECATED.
 */
function site_common_ajax_command_log($title, $data) {
  return qtools_api__ajax_command_log($title, $data);
}

/**
 * Check if user has specified role.
 */
function site_common_user_has_role($role, $account = NULL) {
  global $user;

  $has_role = FALSE;

  // Choose account to test against.
  if (empty($account)) {
    $account = $user;
  }

  $roles = $account->roles;
  if (in_array($role, $roles) || !empty($roles[$role])) {
    $has_role = TRUE;
  }
  return $has_role;
}

/**
 * Get user first/last role.
 */
function site_common_user_role($account = NULL, $first = TRUE) {
  global $user;

  $has_role = FALSE;

  // Choose account to test against.
  if (empty($account)) {
    $account = $user;
  }

  $roles = $account->roles;
  if (isset($roles[1])) {
    unset($roles[1]);
  }
  if (isset($roles[2])) {
    unset($roles[2]);
  }

  $keys = array_keys($roles);
  return $first
    ? reset($keys)
    : end($keys);
}

/**
 * Check if current theme is admin.
 * @param string $theme
 * @return boolean
 */
function site_common_is_admin_theme($theme = NULL) {
  if (empty($theme)) {
    global $theme;
  }
  $admin_theme = variable_get('admin_theme', 0);
  return !empty($admin_theme) && $admin_theme == $theme || empty($admin_theme);
}

