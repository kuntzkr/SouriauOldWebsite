<?php
/**
 * @file
 * Theme logic.
 */

/**
 * Returns debug options.
 */
function qtheme_debug($option) {
  return qtools_api__developer() && !empty($_GET[$option]);
}

/**
 * Theme field.
 */
function qtheme_field(&$variables) {
  // Prevent default field wrapping into odd divs.
  // this function MUST be present even if empty.
}

/**
 * Remove excluded css.
 */
function qtheme_css_alter(&$css) {
  global $theme;

  $info = system_get_info('theme', $theme);
  if (!empty($info['exclude_css'])) {
    foreach ($info['exclude_css'] as $module => $list) {
      $path = drupal_get_path('module', $module);
      foreach ($list as $item) {
        $exclude = $path . '/' . $item;
        if (!empty($css[$exclude])) {
          unset($css[$exclude]);
        }
      }
    }
  }
}

/**
 * Preprocess page.
 */
function qtheme_preprocess_html(&$variables) {
  // Get all ajax paths for miniD.
  $path = module_invoke_all('minid_ajax_path');
  drupal_add_js(['minid' => ['ajax_path' => $path]], 'setting');
}

/**
 * Render wrapper.
 */
function qtheme_render(&$content, $key, $default = '') {
  return array_key_exists($key, $content) ?
    drupal_render($content[$key]) :
    $default;
}

/**
 * Inner function to preprocess entity.
 */
function _qtheme_preprocess_entity(&$variables, $entity_type, $bundle = FALSE, $view_mode = FALSE) {
  global $theme;

  // Defaults.
  $entity = $variables[$entity_type];
  if (empty($variables['_html'])) {
    $variables['_html'] = array();
  }
  if (empty($variables['_data'])) {
    $variables['_data'] = array();
  }
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data['path_to_theme'] = drupal_get_path('theme', $theme);

  // Load preprocess file.
  $file = $_data['path_to_theme'] . '/preprocess/' . $entity_type . '.inc';
  $loaded = &drupal_static('qtheme_preprocess_entity_loaded', array());
  if (!isset($loaded[$file])) {
    if (is_file($file)) {
      require_once $file;
      $loaded[$file] = TRUE;
    }
    else {
      $loaded[$file] = FALSE;
    }
  }

  // Get bundle.
  if ($bundle === FALSE) {
    $ids = entity_extract_ids($entity_type, $entity);
    $bundle = $ids[2];
  }

  // Get view_mode for real entities.
  if ($view_mode === FALSE && is_object($entity)) {
    $view_mode = !empty($variables['elements']['#view_mode']) ?
      $variables['elements']['#view_mode'] :
      'full';
    $entity->view_mode = $view_mode;
  }

  // Run specific preprocess.
  $bundle = !empty($bundle) ?
    '__' . $bundle :
    '';
  $view_mode = !empty($view_mode) ?
    '__' . $view_mode :
    '';

  $preprocess[$theme . '_preprocess_' . $entity_type . $bundle . $view_mode] = FALSE;
  $preprocess[$theme . '_preprocess_' . $entity_type . $bundle] = FALSE;
  $preprocess[$theme . '_preprocess_' . $entity_type] = FALSE;;
  foreach ($preprocess as $function => $status) {
    if (function_exists($function)) {
      $function($variables);
      $preprocess[$function] = TRUE;
      break;
    }
  }

  // Debug.
  if (qtheme_debug('preprocess') && function_exists('dpm')) {
    $debug_function = 'dpm';
    $debug_function($preprocess);
  }

  // Add default templates.
  if (empty($variables['theme_hook_suggestions'])) {
    $variables['theme_hook_suggestions'] = [$entity_type . $bundle];
  }

  // Add specific templates.
  $default_types = array('node', 'taxonomy_term', 'form');
  if (in_array($entity_type, $default_types)) {
    foreach ($variables['theme_hook_suggestions'] as $theme_suggestion) {
      $variables['theme_hook_suggestions'][] = $theme_suggestion . $view_mode;
    }
  }
}

/**
 * Preprocess entity.
 */
function qtheme_preprocess_entity(&$variables) {
  // Extract values.
  $entity_type = $variables['entity_type'];

  // Run on supported entity only.
  $supported = variable_get('qtheme_preprocess_entity_supported', array(
    'config_pages',
    'field_collection_item',
    'paragraphs_item',
    'asset',
    'commerce_customer_profile',
    'commerce_product',
    'file',
  ));
  if (!in_array($entity_type, $supported)) {
    return;
  }

  // Remove extra wrappers.
  unset($variables['elements']['#theme_wrappers']);

  // Run common preprocess.
  _qtheme_preprocess_entity($variables, $entity_type);
}

/**
 * Preprocess node.
 */
function qtheme_preprocess_node(&$variables) {
  // Run common preprocess.
  _qtheme_preprocess_entity($variables, 'node');
}

/**
 * Preprocess taxonomy_term.
 */
function qtheme_preprocess_taxonomy_term(&$variables) {
  // Run common preprocess.
  _qtheme_preprocess_entity($variables, 'term');
}

/**
 * Preprocess comments.
 */
function qtheme_preprocess_comment(&$variables) {
  // Run common preprocess.
  _qtheme_preprocess_entity($variables, 'comment');
}

/**
 * Preprocess files.
 */
function qtheme_preprocess_file_entity(&$variables) {
  // Run common preprocess.
  _qtheme_preprocess_entity($variables, 'file');
}

/**
 * Preprocess forms in same manner as entity.
 */
function qtheme_preprocess_qtheme_form(&$variables) {
  $form = &$variables['form'];

  // Get "bundle" from form id.
  if ($form['#form_id'] == 'views_exposed_form') {
    $suggestion = str_replace('-', '_', $form['#id']);
  }
  else {
    $suggestion = $form['#form_id'];
  }

  // Run common preprocess.
  _qtheme_preprocess_entity($variables, 'form', $suggestion);
}


/**
 * Set custom meta theme for forms.
 */
function qtheme_form_alter(&$form, $form_state, $form_key) {
  if ($form_key == 'views_exposed_form' || $form['#theme'] == 'views_form_views_form') {
    // Do nothing for views forms.
    return;
  }
  $ignore = variable_get('qtheme_form_alter_ignore', array());

  // Add theme function.
  if (!in_array($form_key, $ignore)) {
    if (!is_array($form['#theme'])) {
      $form['#theme'] = array($form['#theme']);
    }
    if (!in_array('views_form_views_form', $form['#theme'])) {
      array_unshift($form['#theme'], 'qtheme_form');
    }
  }
}

/**
 * Implements hook_theme().
 */
function qtheme_theme($existing, $type, $theme, $path) {
  global $theme;
  $theme_path = drupal_get_path('theme', $theme);
  $qtheme_path = drupal_get_path('theme', 'qtheme');

  // Temp theme to find theme suggstions for form.
  $hooks['form'] = array(
    'render element' => 'form',
    'template' => 'form',
    'path' => $theme_path . '/templates',
  );
  $hooks += drupal_find_theme_templates($hooks, '.tpl.php', $theme_path);
  unset($hooks['form']);

  // Change base hook in found template to the meta one.
  foreach ($hooks as &$hook) {
    $hook['base hook'] = 'qtheme_form';
  }

  // Meta theme for all site forms.
  $hooks['qtheme_form'] = array(
    'render element' => 'form',
    'path' => $qtheme_path . '/templates',
    'template' => 'qtheme-form',
  );

  return $hooks;
}
