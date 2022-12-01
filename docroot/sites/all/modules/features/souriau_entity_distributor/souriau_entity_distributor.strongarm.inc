<?php

/**
 * @file
 * souriau_entity_distributor.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_entity_distributor_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_distributor__distributor';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_distributor__distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_taxonomy_term__distributor_country';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_taxonomy_term__distributor_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_distributor__distributor';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'created' => array(
          'weight' => '2',
        ),
        'changed' => array(
          'weight' => '3',
        ),
        'language' => array(
          'weight' => '4',
        ),
        'name' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'created' => array(
          'teaser' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'changed' => array(
          'teaser' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'language' => array(
          'teaser' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_distributor__distributor'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_taxonomy_term__distributor_country';
  $strongarm->value = TRUE;
  $export['metatag_enable_taxonomy_term__distributor_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_distributor_country';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_distributor_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_vad_series';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_vad_series'] = $strongarm;

  return $export;
}
