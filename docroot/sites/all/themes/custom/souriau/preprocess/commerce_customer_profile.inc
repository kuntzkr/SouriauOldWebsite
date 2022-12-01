<?php
/**
 * @file
 * Commerce Customer Profile theming.
 */

/**
 * Implements hook_preprocess_ENTITY_TYPE__BUNDLE__VIEW_MODE().
 */
function souriau_preprocess_commerce_customer_profile__shipping__addressbook(&$vars) {

  $commerce_customer_profile = entity_metadata_wrapper('commerce_customer_profile', $vars['commerce_customer_profile']);

  $vars['address'] = (object) [
    'address_name' => $commerce_customer_profile->field_address_name->value(),
    'country' => $commerce_customer_profile->commerce_customer_address->country->label(),
    'customer_name' => $commerce_customer_profile->commerce_customer_address->name_line->value(),
    'postal_code' => $commerce_customer_profile->commerce_customer_address->postal_code->value(),
    'city' => $commerce_customer_profile->commerce_customer_address->locality->value(),
    'phone_number' => $commerce_customer_profile->commerce_customer_address->phone_number->value(),
    'mobile_number' => $commerce_customer_profile->commerce_customer_address->mobile_number->value(),
    'address_line_1' => $commerce_customer_profile->commerce_customer_address->thoroughfare->value(),
    'address_line_2' => $commerce_customer_profile->commerce_customer_address->premise->value(),
  ];

}
