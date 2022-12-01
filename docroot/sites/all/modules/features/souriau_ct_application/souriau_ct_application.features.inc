<?php
/**
 * @file
 * souriau_ct_application.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_application_ctools_plugin_api($module = NULL, $api = NULL) {
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
function souriau_ct_application_node_info() {
  $items = array(
    'application' => array(
      'name' => t('Application'),
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
function souriau_ct_application_paragraphs_info() {
  $items = array(
    'application_example' => array(
      'name' => 'Application Example',
      'bundle' => 'application_example',
      'locked' => '1',
    ),
    'application_paragraph' => array(
      'name' => 'Application Paragraph',
      'bundle' => 'application_paragraph',
      'locked' => '1',
    ),
  );
  return $items;
}
