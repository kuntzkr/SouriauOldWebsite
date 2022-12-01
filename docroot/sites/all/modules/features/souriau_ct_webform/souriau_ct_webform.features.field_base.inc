<?php
/**
 * @file
 * souriau_ct_webform.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function souriau_ct_webform_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_webform_type'.
  $field_bases['field_webform_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_webform_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'registration_webform' => 'Registration webform',
        'contact_webform' => 'Contact webform',
        'other' => 'Other',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
