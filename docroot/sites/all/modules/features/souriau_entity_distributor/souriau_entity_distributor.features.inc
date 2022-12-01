<?php

/**
 * @file
 * souriau_entity_distributor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_entity_distributor_ctools_plugin_api($module = NULL, $api = NULL) {
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
function souriau_entity_distributor_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function souriau_entity_distributor_eck_bundle_info() {
  $items = array(
    'distributor_distributor' => array(
      'machine_name' => 'distributor_distributor',
      'entity_type' => 'distributor',
      'name' => 'distributor',
      'label' => 'Distributor',
      'config' => array(
        'managed_properties' => array(
          'created' => 'created',
          'changed' => 'changed',
          'title' => 'title',
          'language' => 0,
        ),
        'multilingual' => 0,
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function souriau_entity_distributor_eck_entity_type_info() {
  $items = array(
    'distributor' => array(
      'name' => 'distributor',
      'label' => 'Distributor',
      'properties' => array(
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
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
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
