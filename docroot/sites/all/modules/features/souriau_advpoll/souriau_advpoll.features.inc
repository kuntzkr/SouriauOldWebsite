<?php
/**
 * @file
 * souriau_advpoll.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_advpoll_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function souriau_advpoll_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function souriau_advpoll_node_info() {
  $items = array(
    'advpoll' => array(
      'name' => t('Advanced Poll'),
      'base' => 'node_content',
      'description' => t('Advanced Poll adds additional poll functionality, cookie voting, write-ins and voting modes.'),
      'has_title' => '1',
      'title_label' => t('Question'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
