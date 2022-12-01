<?php
/**
 * @file
 * souriau_download_center.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function souriau_download_center_taxonomy_default_vocabularies() {
  return array(
    'dc_product_tree' => array(
      'name' => 'DC Product Tree',
      'machine_name' => 'dc_product_tree',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'document_languages' => array(
      'name' => 'Document languages',
      'machine_name' => 'document_languages',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'document_types' => array(
      'name' => 'Document types',
      'machine_name' => 'document_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
