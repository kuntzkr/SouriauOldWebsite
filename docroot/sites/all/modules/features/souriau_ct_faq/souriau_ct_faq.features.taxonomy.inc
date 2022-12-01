<?php
/**
 * @file
 * souriau_ct_faq.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function souriau_ct_faq_taxonomy_default_vocabularies() {
  return array(
    'questions_theme' => array(
      'name' => 'Questions theme',
      'machine_name' => 'questions_theme',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
