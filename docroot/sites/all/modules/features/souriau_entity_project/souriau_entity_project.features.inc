<?php
/**
 * @file
 * souriau_entity_project.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_entity_project_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function souriau_entity_project_eck_bundle_info() {
  $items = array(
    'project_project' => array(
      'machine_name' => 'project_project',
      'entity_type' => 'project',
      'name' => 'project',
      'label' => 'Project',
      'config' => array(
        'managed_properties' => array(
          'uid' => 'uid',
          'created' => 'created',
          'changed' => 'changed',
          'language' => 'language',
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
function souriau_entity_project_eck_entity_type_info() {
  $items = array(
    'project' => array(
      'name' => 'project',
      'label' => 'Project',
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
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_paragraphs_info().
 */
function souriau_entity_project_paragraphs_info() {
  $items = array(
    'project_item' => array(
      'name' => 'Project item',
      'bundle' => 'project_item',
      'locked' => '1',
    ),
  );
  return $items;
}
