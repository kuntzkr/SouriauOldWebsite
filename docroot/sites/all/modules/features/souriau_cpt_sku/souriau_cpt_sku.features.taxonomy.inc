<?php

/**
 * @file
 * souriau_cpt_sku.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function souriau_cpt_sku_taxonomy_default_vocabularies() {
  return array(
    'regions' => array(
      'name' => 'Regions',
      'machine_name' => 'regions',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
