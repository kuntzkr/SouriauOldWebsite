<?php
/**
 * @file
 * Implements Did you know CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU Common: Did you know postcards', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: Did you know postcards', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'content_types' => 'souriau_common_did_you_know',
  'single' => TRUE,
  'render callback' => 'souriau_common_did_you_know_content_type_render',
  'edit form' => 'souriau_common_did_you_know_content_type_edit_form',
  'admin title' => 'souriau_common_did_you_know_content_type_admin_title',
  'hook theme' => 'souriau_common_did_you_know_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
];

/**
 * Implements hook_content_type_render().
 */
function souriau_common_did_you_know_content_type_render() {
  $block = new stdClass();
  $block->title = NULL;

  $block->content = theme(
    'block_did_you_know',
    ['_html' => _souriau_common_did_you_know_details()]
  );

  return $block;
}

/**
 * Custom function to generate data for video tutorials landing page.
 *
 * @return array
 *   HTML array to passed over template
 */
function _souriau_common_did_you_know_details() {
  $html = [];
  $souriau_variables = variable_get('souriau_site_settings_variables');
  $html['description'] = $souriau_variables['did_you_know']['description'];
  $html['postcards'] = views_embed_view('souriau_query_postcards', 'default');

  $breadcrumbs = [
    souriau_common_microdata_link(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'),
    souriau_common_microdata_tag(t('DID YOU KNOW', [], ['context' => SOURIAU_COMMON_T_OTHER]))
  ];
  $html['breadcrumbs'] = souriau_common_breadcrumbs(['breadcrumb' => $breadcrumbs]);

  return $html;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_did_you_know_content_type_theme(&$theme, $plugin) {
  $theme['block_did_you_know'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-did-you-know',
    'variables' => [
      '_html' => NULL,
    ],
  ];
}

/**
 * Admin title callback.
 */
function souriau_common_did_you_know_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: Did you know', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_did_you_know_content_type_edit_form($form, &$form_state) {
  return $form;
}
