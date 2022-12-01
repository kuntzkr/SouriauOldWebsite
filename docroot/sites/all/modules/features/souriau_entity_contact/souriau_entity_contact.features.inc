<?php
/**
 * @file
 * souriau_entity_contact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_entity_contact_ctools_plugin_api($module = NULL, $api = NULL) {
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
function souriau_entity_contact_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function souriau_entity_contact_eck_bundle_info() {
  $items = array(
    'contact_contact' => array(
      'machine_name' => 'contact_contact',
      'entity_type' => 'contact',
      'name' => 'contact',
      'label' => 'Contact',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function souriau_entity_contact_eck_entity_type_info() {
  $items = array(
    'contact' => array(
      'name' => 'contact',
      'label' => 'Contact',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
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
      ),
    ),
  );
  return $items;
}
