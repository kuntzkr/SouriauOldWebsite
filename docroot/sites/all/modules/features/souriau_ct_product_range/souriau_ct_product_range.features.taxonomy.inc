<?php
/**
 * @file
 * souriau_ct_product_range.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function souriau_ct_product_range_taxonomy_default_vocabularies() {
  return array(
    'key_words' => array(
      'name' => 'Key words',
      'machine_name' => 'key_words',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'product_series' => array(
      'name' => 'Product Series',
      'machine_name' => 'product_series',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'search_keywords' => array(
      'name' => 'Search keywords',
      'machine_name' => 'search_keywords',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'tags' => array(
      'name' => 'Tags',
      'machine_name' => 'tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
