<?php
/**
 * @file
 * souriau_commerce_customer_profile.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function souriau_commerce_customer_profile_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_customer_address'.
  $field_bases['commerce_customer_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_customer_profile',
    ),
    'field_name' => 'commerce_customer_address',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'addressfield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_address_name'.
  $field_bases['field_address_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_address_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
