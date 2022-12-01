<?php
/**
 * @file
 * Implements 403 CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU Common: 403', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: 403', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'single' => TRUE,
  'render callback' => 'souriau_common_403_content_type_render',
  'edit form' => 'souriau_common_403_content_type_edit_form',
  'hook theme' => 'souriau_common_403_content_type_theme',
  'admin title' => 'souriau_common_403_content_type_admin_title',
  'category' => t('SOURIAU'),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
];

/**
 * Implements hook_content_type_render().
 */
function souriau_common_403_content_type_render() {
  $block = new stdClass();
  $block->title = NULL;
  $block->content = theme('block_403');
  return $block;
}

/**
 * Admin title callback.
 */
function souriau_common_403_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: 403', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_403_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_403_content_type_theme(&$theme, $plugin) {
  $theme['block_403'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-403',
    'variables' => ['home_link' => url('<front>')],
  ];
}
