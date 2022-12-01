<?php
/**
 * @file
 * Implements Training inquiry CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU Common: Training inquiry', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: Training inquiry postcards', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'content_types' => 'souriau_common_training_inquiry',
  'single' => TRUE,
  'render callback' => 'souriau_common_training_inquiry_content_type_render',
  'edit form' => 'souriau_common_training_inquiry_content_type_edit_form',
  'admin title' => 'souriau_common_training_inquiry_content_type_admin_title',
  'hook theme' => 'souriau_common_training_inquiry_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
];

/**
 * Implements hook_content_type_render().
 */
function souriau_common_training_inquiry_content_type_render() {
  $block = new stdClass();
  $block->title = NULL;

  $block->content = theme(
    'block_training_inquiry',
    ['_html' => _souriau_common_training_inquiry_details()]
  );

  return $block;
}

/**
 * Custom function to generate data for video tutorials landing page.
 *
 * @return array
 *   HTML array to passed over template
 */
function _souriau_common_training_inquiry_details() {
  $html = [];
  $webform_nid = variable_get('training_inquiry_webform_nid');

  $node = node_load($webform_nid);
  if (empty($node)) {
    drupal_not_found();
  }

  $webform = drupal_get_form('webform_client_form_' . $webform_nid, $node);

  $webform['actions']['submit']['#souriau_settings'] = [
    'hover_color' => 'orange',
  ];

  $webform['actions']['#attributes']['class'] = ['text-center', 'form-actions'];
  $webform['actions']['submit']['#value'] = t('SEND MY MESSAGE', [], ['context' => SOURIAU_COMMON_T_OTHER]);

  $html['webform'] = $webform;

  $breadcrumbs = [
    souriau_common_microdata_link(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'),
    souriau_common_microdata_tag(t('Training inquiry', [], ['context' => SOURIAU_COMMON_T_OTHER]))
  ];
  $html['breadcrumbs'] = souriau_common_breadcrumbs(['breadcrumb' => $breadcrumbs]);

  return $html;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_training_inquiry_content_type_theme(&$theme, $plugin) {
  $theme['block_training_inquiry'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-training-inquiry',
    'variables' => [
      '_html' => NULL,
    ],
  ];
}

/**
 * Admin title callback.
 */
function souriau_common_training_inquiry_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: Training inquiry', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_training_inquiry_content_type_edit_form($form, &$form_state) {
  return $form;
}
