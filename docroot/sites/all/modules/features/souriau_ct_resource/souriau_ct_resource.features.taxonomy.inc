<?php
/**
 * @file
 * souriau_ct_resource.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function souriau_ct_resource_taxonomy_default_vocabularies() {
  return array(
    'resource_category' => array(
      'name' => 'Resource category',
      'machine_name' => 'resource_category',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'resource_type' => array(
      'name' => 'Resource type',
      'machine_name' => 'resource_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
