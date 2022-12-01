<?php
/**
 * @file
 * souriau_ct_sub_category.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function souriau_ct_sub_category_taxonomy_default_vocabularies() {
  return array(
    'grouping' => array(
      'name' => 'Grouping',
      'machine_name' => 'grouping',
      'description' => 'Used for grouping category hierarchy',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
