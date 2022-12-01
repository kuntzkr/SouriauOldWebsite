<?php
/**
 * @file
 * Implements application domains CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU Common: FAQ', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'description' => t('SOURIAU Common: FAQ', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'content_types' => 'souriau_common_faq',
  'single' => TRUE,
  'render callback' => 'souriau_common_faq_content_type_render',
  'edit form' => 'souriau_common_faq_content_type_edit_form',
  'admin title' => 'souriau_common_faq_content_type_admin_title',
  'hook theme' => 'souriau_common_faq_content_type_theme',
  'category' => t('SOURIAU', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
);

/**
 * Implements hook_content_type_render().
 */
function souriau_common_faq_content_type_render() {
  $block = new stdClass();
  $block->title = NULL;

  $block->content = theme(
    'block_faq',
    ['_html' => _souriau_common_faq_details()]
  );

  return $block;
}

/**
 * Custom function to generate data for beginner guide page.
 *
 * @return array
 *   HTML array to passed over template
 */
function _souriau_common_faq_details() {
  global $language;
  $html = [];

  $html['faq_data'] = views_get_view_result('souriau_query_get_theme_based_faq', 'default');

  return $html;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_faq_content_type_theme(&$theme, $plugin) {
  $theme['block_faq'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-faq',
    'variables' => [
      '_html' => NULL,
    ],
  ];
}

/**
 * Admin title callback.
 */
function souriau_common_faq_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: FAQ', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_faq_content_type_edit_form($form, &$form_state) {
  return $form;
}
