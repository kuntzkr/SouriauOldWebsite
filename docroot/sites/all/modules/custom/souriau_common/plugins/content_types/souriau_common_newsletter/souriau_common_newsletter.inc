<?php
/**
 * @file
 * Breadcrumbs CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU Common: Newsletter', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'description' => t('SOURIAU Common: Newsletter', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'content_types' => 'souriau_common_newsletter',
  'single' => TRUE,
  'render callback' => 'souriau_common_newsletter_content_type_render',
  'edit form' => 'souriau_common_newsletter_content_type_edit_form',
  'hook theme' => 'souriau_common_newsletter_content_type_theme',
  'admin title' => 'souriau_common_newsletter_content_type_admin_title',
  'category' => t('SOURIAU'),
  'icon' => NULL,
);

/**
 * Implements hook_content_type_render().
 */
function souriau_common_newsletter_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $data = [];

  $data['_html']['newsletter'] = theme('souriau_newsletter_newsletter_form');
  $block->content = theme('block_newsletter', $data);

  return $block;
}

/**
 * Admin title callback.
 */
function souriau_common_newsletter_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: Newsletter', array(), array('context' => SOURIAU_COMMON_T_ADMIN));
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_newsletter_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_newsletter_content_type_theme(&$theme, $plugin) {
  $theme['block_newsletter'] = array(
    'path' => $plugin['path'],
    'template' => 'souriau-common-newsletter',
    'variables' => array('params' => array()),
  );
}
