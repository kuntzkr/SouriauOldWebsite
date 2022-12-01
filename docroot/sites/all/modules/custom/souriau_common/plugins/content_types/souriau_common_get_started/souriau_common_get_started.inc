<?php
/**
 * @file
 * Implements application domains CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU Common: Get Started', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'description' => t('SOURIAU Common: Get Started', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'content_types' => 'souriau_common_get_started',
  'single' => TRUE,
  'render callback' => 'souriau_common_get_started_content_type_render',
  'edit form' => 'souriau_common_get_started_content_type_edit_form',
  'admin title' => 'souriau_common_get_started_content_type_admin_title',
  'hook theme' => 'souriau_common_get_started_content_type_theme',
  'category' => t('SOURIAU', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
);

/**
 * Implements hook_content_type_render().
 */
function souriau_common_get_started_content_type_render() {
  $block = new stdClass();
  $block->title = NULL;

  $block->content = theme(
    'block_get_started',
    ['_html' => _souriau_common_get_started_details()]
  );

  return $block;
}

/**
 * Custom function to generate data for beginner guide page.
 *
 * @return array
 *   HTML array to passed over template
 */
function _souriau_common_get_started_details() {
  global $language;
  $html = [];
  $application_domains = views_get_view_result('souriau_query_get_application_domains', 'default');
  foreach ($application_domains as $application_domain) {
    if (!isset($html['application_domains'][$application_domain->nid])) {
      $entity = $application_domain->_field_data['nid']['entity'];
      $html['application_domains'][$application_domain->nid] = [
        'nid' => $application_domain->nid,
        'title' => souriau_common_get_field_value('node', $entity, 'title_field', $language->language),
      ];
    }
  }

  uasort($html['application_domains'], 'drupal_sort_title');
  $souriau_settings = variable_get('souriau_common_settings');
  $fid = (isset($souriau_settings['beginner_guide'])) ? $souriau_settings['beginner_guide']['beginner_guide_background'] : NULL;
  $image = [
    '#type' => 'figure_pic',
    '#image' => $fid,
    '#attributes' => [],
  ];
  $html['image'] = drupal_render($image);

  $breadcrumbs = [
    souriau_common_microdata_link(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'),
    souriau_common_microdata_tag(t('GET STARTED', [], ['context' => SOURIAU_COMMON_T_OTHER]))
  ];
  $html['breadcrumbs'] = souriau_common_breadcrumbs(['breadcrumb' => $breadcrumbs], 'b-white');

  return $html;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_get_started_content_type_theme(&$theme, $plugin) {
  $theme['block_get_started'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-get-started',
    'variables' => [
      '_html' => NULL,
    ],
  ];
}

/**
 * Admin title callback.
 */
function souriau_common_get_started_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: project', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_get_started_content_type_edit_form($form, &$form_state) {
  return $form;
}
