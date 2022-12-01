<?php
/**
 * @file
 * File souriau_eco.inc.
 */

/**
 * Creates a Drupal Ajax 'souriau_eco_reset_address_form' command.
 *
 * Call this command for reset form for creation new customer address.
 *
 * This command is implemented by
 * Drupal.ajax.prototype.commands.souriau_eco_reset_address_form()
 *
 * @return array
 *   Ajax command.
 */
function souriau_eco_reset_address_form() {
  return [
    'command' => 'souriau_eco_reset_address_form',
    'url' => url('souriau/ajax/address/create/form'),
  ];
}

/**
 * Stock level getter.
 *
 * @param string $part_number
 *   Part number SKU identifer.
 *
 * @return int
 *   Stock level for given part number.
 */
function souriau_eco_get_stock_level($part_number) {
  // Get distributor managing system.
  $souriau_setting = variable_get('souriau_distributor_settings', []);
  $distributor_system = isset($souriau_setting['manage']['setting']) ? $souriau_setting['manage']['setting'] : FALSE;
  if ($distributor_system) {
    // Return tipity callback.
    $tipity_data = souriau_common_tipity_service($part_number);
    if (empty($tipity_data)) {
      return 0;
    }
    $item = reset($tipity_data);
    return isset($item['quantity']) ? $item['quantity'] : 0;
  }

  // Get information about stock from external DB.
  module_load_include('inc', 'souriau_common', 'souriau_common.rdb');
  $distributors = souriau_common_rdb_get_part_number_stock_status($part_number);
  if (!$distributors) {
    return 0;
  }
  $item = reset($distributors);
  return isset($item->quantity) ? $item->quantity : 0;
}

/**
 * Create GTM script for commerce.
 *
 * @param object $order
 *   Commerce_order.
 *
 * @return string
 *   Encoded string.
 */
function souriau_eco_create_gtm_script($order) {
  $script = 'var dataLayer = dataLayer || []; ';

  if (!($order instanceof EntityMetadataWrapper)) {
    $order = entity_metadata_wrapper('commerce_order', $order);
  }

  $products = [];
  // Loop through the products on the order.
  foreach ($order->commerce_line_items as $line_item_wrapper) {
    $properties = $line_item_wrapper->getPropertyInfo();
    $product_data = [];

    if (isset($properties['commerce_product'])) {
      $product_id = $line_item_wrapper->commerce_product->getIdentifier();
      if (!empty($product_id)) {
        $sku = $line_item_wrapper->commerce_product->sku->value();
        $pn = entity_metadata_wrapper('node', souriau_common_load_part_number_by_sku($sku));
        // Build the item arguments.
        $product_data = [
          'sku' => $sku,
          'name' => $pn->title->value(),
          'price' => 0,
          'quantity' => (int) $line_item_wrapper->quantity->value(),
        ];
      }
    }

    if (!empty($product_data)) {
      $products[] = $product_data;
    }
  }

  // Build the transaction arguments.
  $transaction = array(
    'transactionId' => $order->order_id->value(),
    'transactionAffiliation' => variable_get('site_name', ''),
    'transactionTotal' => commerce_currency_amount_to_decimal($order->commerce_order_total->amount->value(), $order->commerce_order_total->currency_code->value()),
    'transactionProducts' => $products,
  );

  // Add the transaction line to the JS array.
  $script .= 'dataLayer.push(' . drupal_json_encode($transaction) . ');';

  return $script;
}
