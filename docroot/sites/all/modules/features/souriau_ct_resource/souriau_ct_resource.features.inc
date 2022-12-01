<?php
/**
 * @file
 * souriau_ct_resource.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_resource_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function souriau_ct_resource_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function souriau_ct_resource_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favourate Resource".
  $flags['favourate_resource'] = array(
    'entity_type' => 'node',
    'title' => 'Favourate Resource',
    'global' => 0,
    'types' => array(
      0 => 'resource',
    ),
    'flag_short' => 'favourate',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'favourate',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'search_autocomplete' => 0,
      'search_results' => 0,
      'product_landing_page' => 0,
      'category_page' => 0,
      'subcategory_page' => 0,
      'product_range_page' => 0,
      'application_page' => 0,
      'applicationdomain_page' => 0,
      'application_landing_page' => 0,
      'news_pane_teaser' => 0,
      'capability_landing_page' => 0,
      'capabilitydomain_page' => 0,
      'part_number' => 0,
      'cart_summary' => 0,
      'minicart_summary' => 0,
      'news_landing_pane_teaser' => 0,
      'tool_page' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'souriau_ct_resource',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function souriau_ct_resource_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
