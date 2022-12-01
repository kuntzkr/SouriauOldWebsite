<?php
/**
 * @file
 * souriau_ct_cms_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_cms_page_ctools_plugin_api($module = NULL, $api = NULL) {
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
function souriau_ct_cms_page_node_info() {
  $items = array(
    'cms_page' => array(
      'name' => t('Cms page'),
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
function souriau_ct_cms_page_paragraphs_info() {
  $items = array(
    'cms_page_paragraph' => array(
      'name' => 'Cms page paragraph',
      'bundle' => 'cms_page_paragraph',
      'locked' => '1',
    ),
  );
  return $items;
}
