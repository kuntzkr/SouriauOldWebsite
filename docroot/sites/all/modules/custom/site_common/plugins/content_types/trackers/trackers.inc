<?php
/**
 * @file
 * Plugin to handle Trackers content type.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Site Common: Trackers', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'defaults' => array(
    'tracker_id' => '',
  ),
  'icon' => 'icon_node.png',
  'category' => t('Site Common', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
);

/**
 * Output function.
 */
function site_common_trackers_content_type_render($subtype, $conf, $panel_args) {
  $block = new stdClass();

  // Get tracker content.
  $content = variable_get($conf['tracker_id'], NULL);
  drupal_alter('site_common_tracker', $content, $conf['tracker_id']);
  $block->content = $content;
  return $block;
}

/**
 * Form builder.
 */
function site_common_trackers_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['tracker_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Tracker variable name'),
    '#default_value' => !empty($conf['tracker_id']) ? $conf['tracker_id'] : '',
  );
  return $form;
}

/**
 * Validate handler.
 */
function site_common_trackers_content_type_edit_form_validate(&$form, &$form_state) {
}

/**
 * Submit handler.
 */
function site_common_trackers_content_type_edit_form_submit($form, &$form_state) {
  foreach (array('tracker_id') as $key) {
    $form_state['conf'][$key] = $form_state['values'][$key];
  }
}

/**
 * Returns the administrative title for a slider.
 */
function site_common_trackers_content_type_admin_title($subtype, $conf) {
  return t('Site Common: Trackers [@name]', array(
    '@name' => $conf['tracker_id'],
  ), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
}
