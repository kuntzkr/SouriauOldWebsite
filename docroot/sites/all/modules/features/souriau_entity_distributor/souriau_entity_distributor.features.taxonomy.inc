<?php

/**
 * @file
 * souriau_entity_distributor.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function souriau_entity_distributor_taxonomy_default_vocabularies() {
  return array(
    'vad_series' => array(
      'name' => 'VAD Series',
      'machine_name' => 'vad_series',
      'description' => 'For Value Added Distributors',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
