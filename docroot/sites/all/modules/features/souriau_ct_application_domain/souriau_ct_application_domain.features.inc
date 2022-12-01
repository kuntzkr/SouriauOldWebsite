<?php
/**
 * @file
 * souriau_ct_application_domain.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_application_domain_ctools_plugin_api($module = NULL, $api = NULL) {
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
function souriau_ct_application_domain_node_info() {
  $items = array(
    'applicationdomain' => array(
      'name' => t('Application Domain'),
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
