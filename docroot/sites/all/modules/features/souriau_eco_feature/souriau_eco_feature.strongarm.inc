<?php
/**
 * @file
 * souriau_eco_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_eco_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'commerce_customer_profile_shipping_addressbook';
  $strongarm->value = 1;
  $export['commerce_customer_profile_shipping_addressbook'] = $strongarm;

  return $export;
}
