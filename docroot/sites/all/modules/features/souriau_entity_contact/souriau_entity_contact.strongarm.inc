<?php
/**
 * @file
 * souriau_entity_contact.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_entity_contact_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_contact__contact';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_contact__contact'] = $strongarm;

  return $export;
}
