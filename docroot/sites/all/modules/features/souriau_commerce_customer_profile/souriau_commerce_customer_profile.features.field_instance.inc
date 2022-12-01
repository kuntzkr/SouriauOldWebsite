<?php
/**
 * @file
 * souriau_commerce_customer_profile.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function souriau_commerce_customer_profile_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'commerce_customer_profile-billing-commerce_customer_address'.
  $field_instances['commerce_customer_profile-billing-commerce_customer_address'] = array(
    'bundle' => 'billing',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'administrator' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'customer' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => -10,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'commerce_customer_address',
    'label' => 'Address',
    'required' => TRUE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'site_default',
        'format_handlers' => array(
          0 => 'address',
          1 => 'name-oneline',
        ),
        'phone_number_fields' => array(),
        'required_fields' => array(),
      ),
      'type' => 'addressfield_standard',
      'weight' => -10,
    ),
  );

  // Exported field_instance:
  // 'commerce_customer_profile-shipping-commerce_customer_address'.
  $field_instances['commerce_customer_profile-shipping-commerce_customer_address'] = array(
    'bundle' => 'shipping',
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
        'mobile_number' => '',
        'organisation_name' => '',
        'first_name' => '',
        'last_name' => '',
        'civility' => '',
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
        'weight' => -8,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'commerce_customer_address',
    'label' => 'Postal address',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => '',
        'format_handlers' => array(
          'address' => 'address',
          'phone' => 'phone',
          'organisation' => 'organisation',
          'name-full' => 'name-full',
          'addressfield-civility' => 'addressfield-civility',
          'addressfield-mandatory' => 'addressfield-mandatory',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-administrative-area' => 0,
          'address-hide-locality' => 0,
          'address-hide-country' => 0,
          'name-oneline' => 0,
          'address-optional' => 0,
          'addressfield-job-position' => 0,
        ),
        'phone_number_fields' => array(
          'extension' => 0,
          'fax' => 0,
          'mobile' => 'mobile',
          'phone' => 'phone',
        ),
        'required_fields' => array(
          'administrative_area' => 'administrative_area',
          'civility' => 0,
          'dependent_locality' => 0,
          'first_name' => 'first_name',
          'last_name' => 'last_name',
          'locality' => 'locality',
          'mobile_number' => 0,
          'organisation_name' => 'organisation_name',
          'phone_number' => 'phone_number',
          'postal_code' => 'postal_code',
          'premise' => 0,
          'thoroughfare' => 'thoroughfare',
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'commerce_customer_profile-shipping-field_address_name'.
  $field_instances['commerce_customer_profile-shipping-field_address_name'] = array(
    'bundle' => 'shipping',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -9,
      ),
    ),
    'entity_type' => 'commerce_customer_profile',
    'field_name' => 'field_address_name',
    'label' => 'Address Name',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Address Name');
  t('Postal address');

  return $field_instances;
}
