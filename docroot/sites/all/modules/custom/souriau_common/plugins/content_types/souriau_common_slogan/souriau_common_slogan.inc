<?php
/**
 * @file
 * Slogan CCT. For Homepage.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU Common: Slogan', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: Slogan', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'content_types' => 'souriau_common_slogan',
  'single' => TRUE,
  'render callback' => 'souriau_common_slogan_content_type_render',
  'edit form' => 'souriau_common_slogan_content_type_edit_form',
  'admin title' => 'souriau_common_slogan_content_type_admin_title',
  'hook theme' => 'souriau_common_slogan_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
];

/**
 * Implements hook_content_type_render().
 */
function souriau_common_slogan_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = [
    '#theme' => 'block_slogan',
    '#slogan' => t(variable_get('site_slogan', 'Reliable People, Reliable Solutions'), [], ['context' => SOURIAU_COMMON_T_OTHER]),
  ];

  $block->content = drupal_render($data);
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_slogan_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Admin title callback.
 */
function souriau_common_slogan_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: Slogan', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_slogan_content_type_theme(&$theme, $plugin) {
  $theme['block_slogan'] = [
    'path'      => $plugin['path'],
    'template'  => 'souriau-common-slogan',
    'variables' => ['slogan' => []],
  ];
}
