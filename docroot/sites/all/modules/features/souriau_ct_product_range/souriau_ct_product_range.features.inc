<?php
/**
 * @file
 * souriau_ct_product_range.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_product_range_ctools_plugin_api($module = NULL, $api = NULL) {
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
function souriau_ct_product_range_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function souriau_ct_product_range_node_info() {
  $items = array(
    'productrange' => array(
      'name' => t('Product Range'),
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

/**
 * Implements hook_paragraphs_info().
 */
function souriau_ct_product_range_paragraphs_info() {
  $items = array(
    'product_range_application_refenc' => array(
      'name' => 'Product Range Application Paragraph',
      'bundle' => 'product_range_application_refenc',
      'locked' => '1',
    ),
    'product_range_paragraph' => array(
      'name' => 'Product Range Paragraph',
      'bundle' => 'product_range_paragraph',
      'locked' => '1',
    ),
  );
  return $items;
}
