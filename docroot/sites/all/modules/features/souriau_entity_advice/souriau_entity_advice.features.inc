<?php
/**
 * @file
 * souriau_entity_advice.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_entity_advice_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function souriau_entity_advice_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function souriau_entity_advice_eck_bundle_info() {
  $items = array(
    'advice_advice' => array(
      'machine_name' => 'advice_advice',
      'entity_type' => 'advice',
      'name' => 'advice',
      'label' => 'Advice',
      'config' => array(
        'managed_properties' => array(
          'uid' => 'uid',
          'created' => 'created',
          'changed' => 'changed',
          'title' => 'title',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function souriau_entity_advice_eck_entity_type_info() {
  $items = array(
    'advice' => array(
      'name' => 'advice',
      'label' => 'Advice',
      'properties' => array(
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}
