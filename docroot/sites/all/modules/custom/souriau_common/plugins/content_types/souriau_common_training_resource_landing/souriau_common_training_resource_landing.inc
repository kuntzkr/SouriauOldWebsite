<?php
/**
 * @file
 * Implements Training resource CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU Common: Training Resource', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: Training Resource', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'content_types' => 'souriau_common_training_resource',
  'single' => TRUE,
  'render callback' => 'souriau_common_training_resource_content_type_render',
  'edit form' => 'souriau_common_training_resource_content_type_edit_form',
  'admin title' => 'souriau_common_training_resource_content_type_admin_title',
  'hook theme' => 'souriau_common_training_resource_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
];

/**
 * Implements hook_content_type_render().
 */
function souriau_common_training_resource_content_type_render() {
  $block = new stdClass();
  $block->title = NULL;

  $block->content = theme(
    'block_training_resource',
    ['_html' => _souriau_common_training_resource_details()]
  );

  return $block;
}

/**
 * Custom function to generate data for video tutorials landing page.
 *
 * @return array
 *   HTML array to passed over template
 */
function _souriau_common_training_resource_details() {
  $html = [];
  $html['all_resources'] = views_embed_view('souriau_query_training_center', 'training_center_resources_full');
  $html['favorites_resources'] = views_embed_view('souriau_query_training_center', 'training_center_my_favorites');
  $html['popular_resources'] = views_embed_view('souriau_query_training_center', 'training_center_resources_popular');

  $breadcrumbs = [
    souriau_common_microdata_link(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'),
    souriau_common_microdata_tag(t('VIDEO TUTORIALS', [], ['context' => SOURIAU_COMMON_T_OTHER]))
  ];
  $html['breadcrumbs'] = souriau_common_breadcrumbs(['breadcrumb' => $breadcrumbs]);

  return $html;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_training_resource_content_type_theme(&$theme, $plugin) {
  $theme['block_training_resource'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-training-resource-landing',
    'variables' => [
      '_html' => NULL,
    ],
  ];
}

/**
 * Admin title callback.
 */
function souriau_common_training_resource_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: Training Resource', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_training_resource_content_type_edit_form($form, &$form_state) {
  return $form;
}
