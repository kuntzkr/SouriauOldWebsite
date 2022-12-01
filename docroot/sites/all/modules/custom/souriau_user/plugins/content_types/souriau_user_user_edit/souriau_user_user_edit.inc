<?php

/**
 * @file
 * Breadcrumbs CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU User: User edit page', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'description' => t('SOURIAU User: User edit page', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'content_types' => 'souriau_user_user_edit',
  'single' => TRUE,
  'render callback' => 'souriau_user_user_edit_content_type_render',
  'edit form' => 'souriau_user_user_edit_content_type_edit_form',
  'hook theme' => 'souriau_user_user_edit_content_type_theme',
  'admin title' => 'souriau_user_user_edit_content_type_admin_title',
  'category' => t('SOURIAU'),
  'icon' => NULL,
  'render last' => TRUE,
  'required context' => array(
    new ctools_context_optional(t('User', array(), array('context' => SOURIAU_COMMON_T_ADMIN)), 'user'),
  ),

);

/**
 * Implements hook_content_type_render().
 */
function souriau_user_user_edit_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $domain = domain_get_domain();
  $access_form = !empty(domain_conf_variable_get($domain['domain_id'], 'backoffice_extras_history_access_block')) ? drupal_get_form('souriau_user_user_customer_id_form') : NULL;
  $redered_array = [
    '#theme' => 'souriau_user_edit',
    '#form' => drupal_get_form('souriau_user_user_edit_form'),
    '#access_form' => $access_form,
  ];
  $block->content = drupal_render($redered_array);

  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_user_user_edit_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Admin title callback.
 */
function souriau_user_user_edit_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU User: User edit form', array(), array('context' => SOURIAU_COMMON_T_ADMIN));
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_user_user_edit_content_type_theme(&$theme, $plugin) {
  $theme['souriau_user_edit'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-user-user-edit',
    'variables' => [
      'form' => NULL,
      'newsletter_form' => NULL,
      'access_form' => NULL,
    ],
  ];
}
