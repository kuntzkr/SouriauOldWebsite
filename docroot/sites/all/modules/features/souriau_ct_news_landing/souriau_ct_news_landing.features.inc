<?php
/**
 * @file
 * souriau_ct_news_landing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_news_landing_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function souriau_ct_news_landing_node_info() {
  $items = array(
    'news_landing' => array(
      'name' => t('News Landing'),
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
