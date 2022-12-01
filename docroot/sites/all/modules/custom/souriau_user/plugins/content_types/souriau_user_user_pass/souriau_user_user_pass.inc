<?php
/**
 * @file
 * Breadcrumbs CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU User: User forgot password page', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'description' => t('SOURIAU User: User forgot password page', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'content_types' => 'souriau_user_user_pass',
  'single' => TRUE,
  'render callback' => 'souriau_user_user_pass_content_type_render',
  'edit form' => 'souriau_user_user_pass_content_type_edit_form',
  'hook theme' => 'souriau_user_user_pass_content_type_theme',
  'admin title' => 'souriau_user_user_pass_content_type_admin_title',
  'category' => t('SOURIAU'),
  'icon' => NULL,
  'render last' => TRUE,
);

/**
 * Implements hook_content_type_render().
 */
function souriau_user_user_pass_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $redered_array = [
    '#theme' => 'souriau_user_pass',
    '#form' => drupal_get_form('user_pass'),
  ];
  $block->content = drupal_render($redered_array);
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_user_user_pass_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Admin title callback.
 */
function souriau_user_user_pass_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU User: User forgot password form', array(), array('context' => SOURIAU_COMMON_T_ADMIN));
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_user_user_pass_content_type_theme(&$theme, $plugin) {
  $theme['souriau_user_pass'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-user-user-pass',
    'variables' => [
      'form' => NULL,
      'text' => NULL,
    ],
  ];
}
