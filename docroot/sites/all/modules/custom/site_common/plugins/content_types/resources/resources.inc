<?php
/**
 * @file
 * Plugin to handle resources content type.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Site Common: Resources', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'defaults' => array(
    'js_sync' => '',
    'js_asynk' => '',
  ),
  'icon' => 'icon_node.png',
  'category' => t('Site Common', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
);

/**
 * Output function.
 */
function site_common_resources_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();

  // Sync js.
  $js_sync = explode(PHP_EOL, $conf['js_sync']);
  foreach (array_filter($js_sync) as $line) {
    list($type, $name, $path) = explode('|', trim($line));
    if (!empty($type) && !empty($name) && !empty($path)) {
      drupal_add_js(drupal_get_path($type, $name) . '/' . $path);
    }
  }

  // Async js.
  $js_async = explode(PHP_EOL, $conf['js_async']);
  foreach (array_filter($js_async) as $line) {
    list($type, $name, $path) = explode('|', trim($line));
    if (!empty($type) && !empty($name) && !empty($path)) {
      site_common_add_async_js(drupal_get_path($type, $name) . '/' . $path);
    }
  }

  // Proces saved WID.
  $block->content = '';

  return $block;
}

/**
 * Form builder.
 */
function site_common_resources_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['js_sync'] = array(
    '#type' => 'textarea',
    '#title' => t('Synchronous JavasSript files', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => !empty($conf['js_sync']) ? $conf['js_sync'] : '',
  );
  $form['js_async'] = array(
    '#type' => 'textarea',
    '#title' => t('Asynchronous JavasSript files', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => !empty($conf['js_async']) ? $conf['js_async'] : '',
  );
  return $form;
}

/**
 * Validate handler.
 */
function site_common_resources_content_type_edit_form_validate(&$form, &$form_state) {
}

/**
 * Submit handler.
 */
function site_common_resources_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('js_sync', 'js_async') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a slider.
 */
function site_common_resources_content_type_admin_title($subtype, $conf) {
  return t('Site Common: Resources', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
}
