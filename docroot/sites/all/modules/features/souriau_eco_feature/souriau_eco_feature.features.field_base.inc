<?php
/**
 * @file
 * souriau_eco_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function souriau_eco_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_customer_shipping'.
  $field_bases['commerce_customer_shipping'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_customer_shipping',
    'indexes' => array(
      'profile_id' => array(
        0 => 'profile_id',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_customer',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'options_list_limit' => 50,
      'profile_type' => 'shipping',
    ),
    'translatable' => 0,
    'type' => 'commerce_customer_profile_reference',
  );

  // Exported field_base: 'commerce_line_items'.
  $field_bases['commerce_line_items'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_line_items',
    'indexes' => array(
      'line_item_id' => array(
        0 => 'line_item_id',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_line_item',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'commerce_line_item_reference',
  );

  // Exported field_base: 'commerce_order_total'.
  $field_bases['commerce_order_total'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_order',
    ),
    'field_name' => 'commerce_order_total',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'field_commerce_cancel_desc'.
  $field_bases['field_commerce_cancel_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_cancel_desc',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_commerce_cart_url'.
  $field_bases['field_commerce_cart_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_cart_url',
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

  // Exported field_base: 'field_commerce_mouser_orderno'.
  $field_bases['field_commerce_mouser_orderno'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_mouser_orderno',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 50,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_commerce_mouser_status'.
  $field_bases['field_commerce_mouser_status'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_mouser_status',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 32,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_commerce_shipment_tracker'.
  $field_bases['field_commerce_shipment_tracker'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_shipment_tracker',
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

  // Exported field_base: 'field_commerce_shipped_date'.
  $field_bases['field_commerce_shipped_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_shipped_date',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'entity_translation_sync' => FALSE,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => 'UTC',
      'todate' => '',
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datestamp',
  );

  // Exported field_base: 'field_commerce_shipping_link'.
  $field_bases['field_commerce_shipping_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_shipping_link',
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

  // Exported field_base: 'field_commerce_shipping_provider'.
  $field_bases['field_commerce_shipping_provider'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_commerce_shipping_provider',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 100,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
