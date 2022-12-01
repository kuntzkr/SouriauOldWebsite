<?php
/**
 * @file
 * souriau_entity_contact.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function souriau_entity_contact_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'contact-contact-field_postal_address'.
  $field_instances['contact-contact-field_postal_address'] = array(
    'bundle' => 'contact',
    'default_value' => array(
      0 => array(
        'thoroughfare' => '',
        'premise' => '',
        'postal_code' => '',
        'dependent_locality' => '',
        'locality' => '',
        'administrative_area' => '',
        'country' => '',
        'phone_number' => '',
        'fax_number' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'contact',
    'field_name' => 'field_postal_address',
    'label' => 'Postal address',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'site_default',
        'format_handlers' => array(
          'address' => 'address',
          'phone' => 'phone',
          'addressfield-email' => 'addressfield-email',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-administrative-area' => 0,
          'address-hide-locality' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
          'address-optional' => 0,
          'addressfield-civility' => 0,
          'addressfield-job-position' => 0,
          'addressfield-mandatory' => 0,
        ),
        'phone_number_fields' => array(
          'extension' => 0,
          'fax' => 'fax',
          'mobile' => 0,
          'phone' => 'phone',
        ),
        'required_fields' => array(
          'administrative_area' => 0,
          'dependent_locality' => 0,
          'locality' => 0,
          'postal_code' => 0,
          'premise' => 0,
          'thoroughfare' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Postal address');

  return $field_instances;
}
