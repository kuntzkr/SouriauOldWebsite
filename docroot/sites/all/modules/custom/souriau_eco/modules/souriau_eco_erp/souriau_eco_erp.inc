<?php

/**
 * @file
 * File souriau_eco_erp_erp.inc.
 */

define('SOURIAU_ECO_ERP_REQUEST_TYPE', 'xml');

/**
 * Client token.
 */
function souriau_eco_erp_get_client_token() {
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  return isset($site_commerce_settings['erp']['client_token']) ? $site_commerce_settings['erp']['client_token'] : '57FE074A-7A07-4B28-892F-D7B6278A19B2';
}

/**
 * Mouser URLs.
 *
 * @param string $operation
 *   Operation name.
 *
 * @return string
 *   Request URL.
 */
function _souriau_eco_erp_mouser_urls($operation) {
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $url = isset($site_commerce_settings['erp']['mouser_url']) ? $site_commerce_settings['erp']['mouser_url'] : 'https://tpltest.services.mouser.com';
  $path = [
    'get_product' => '/api/products/getProduct',
    'cart_request' => '/api/transfer/request',
    'get_order_history' => '/api/orders/getOrderHistory',
  ];
  return isset($path[$operation]) ? $url . $path[$operation] : FALSE;
}

/**
 * Check Samples Stock for given $part_number.
 *
 * @param string $part_number
 *   Part Number SKU identifer.
 *
 * @return int
 *   Amount of Stock level for the Sample Part Number.
 */
function souriau_eco_erp_get_samples_stock($part_number, $quantity = 1) {
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $ecommerce_stock_system = isset($site_commerce_settings['stock']['system']) ? $site_commerce_settings['stock']['system'] : 'worldwide_stock';

  if ('mouser_stock' == $ecommerce_stock_system) {
    // Get MOUSER Samples stock for the part_number.
    return souriau_eco_erp_get_samples_stock_from_mouser_erp($part_number, $quantity);
  }
  // Get WORLD_WIDE Samples stock for the part_number.
  return souriau_eco_erp_get_samples_stock_from_external_db($part_number);
}

/**
 * Get MOUSER Samples Stock level getter from MOUSER API.
 *
 * @param string $part_number
 *   Part number SKU identifer.
 * @param int $quantity
 *   Quantity of product.
 *
 * @return int
 *   Samples Stock level for given part number.
 */
function souriau_eco_erp_get_samples_stock_from_mouser_erp($part_number, $quantity) {
  // Client identifier.
  $client_token = souriau_eco_erp_get_client_token();
  $stock = 0;
  $xml = _souriau_eco_erp_get_stock_level_prepare_request($client_token, $part_number, $quantity, SOURIAU_ECO_ERP_REQUEST_TYPE);

  // Return Mouser data.
  $response = souriau_eco_erp_get_response(_souriau_eco_erp_mouser_urls('get_product'), $xml);
  if (variable_get('log_add_to_cart', FALSE)) {
    watchdog('souriau_eco_erp', print_r($response, TRUE), []);
  }
  if (!empty($response['Errors'])) {
    $error = reset($response['Errors']);
    watchdog('souriau_eco_erp', 'Error while trying to get stock level for %part_number from Mouser: %message', ['%part_number' => $part_number, '%message' => $error['Message']]);
  }

  if (!empty($response['ProductInfo'])) {
    $product = $response['ProductInfo'];
    $stock = $product['StockQuantity'];
    if (variable_get('log_add_to_cart', FALSE)) {
      watchdog('souriau_eco_erp', 'For %part_number the Mouser stock is: %stock', ['%part_number' => $part_number, '%stock' => $stock]);
    }
  }
  return $stock ? $stock : 0;
}

/**
 * Get WORLD_WIDE Samples Stock level getter from external DB.
 *
 * @param string $part_number
 *   Part number SKU identifer.
 *
 * @return int
 *   Samples Stock level for given part number.
 */
function souriau_eco_erp_get_samples_stock_from_external_db($part_number, $is_mouser = FALSE) {
  module_load_include('inc', 'souriau_common', 'souriau_common.rdb');
  $stock_items = souriau_common_rdb_get_part_number_stock_status($part_number, TRUE, $is_mouser);
  if (!$stock_items) {
    return 0;
  }
  $item = reset($stock_items);
  return isset($item->quantity) ? $item->quantity : 0;
}

/**
 * Prepare xml for mouser request.
 *
 * @param string $client_token
 *   Client token.
 * @param string $part_number
 *   Part number value.
 * @param int $quantity
 *   Quantity.
 *
 * @return string
 *   XML.
 */
function _souriau_eco_erp_get_stock_level_prepare_request($client_token, $part_number, $quantity, $type) {
  $encode_array = [
    'ClientToken' => $client_token,
    'ProductRequest' => [
      'ManufacturerPartNumber' => $part_number,
      'Quantity' => $quantity,
    ],
  ];
  if ($type == 'xml') {
    return format_xml_elements(['GetProduct' => $encode_array]);
  }
  return drupal_json_encode($encode_array);
}

/**
 * Mouser caller.
 */
function souriau_eco_erp_get_response($url, $data, &$order = NULL) {
  // Request headers.
  $headers = ['Content-Type' => 'text/xml; charset=UTF-8'];
  if ('json' == SOURIAU_ECO_ERP_REQUEST_TYPE) {
    $headers = ['Content-Type' => 'text/json; charset=UTF-8'];
  }

  $options = [
    'method' => 'POST',
    'data' => $data,
    'headers' => $headers,
  ];

  if (!empty($order)) {
    $order->goid = souriau_eco_erp_history_log($order, ['req_data' => $data]);
  }

  $response = drupal_http_request($url, $options);

  if ($response->code != 200) {
    $status_message = !empty($response->status_message) ? '<br /> ' . $response->status_message : '';
    $error = t('Error while trying to get response from mouser. Check your request and try again later', [], ['context' => SOURIAU_COMMON_T_OTHER]) . $status_message;
    watchdog('souriau_eco_erp', $error, [], 1);
  }

  if (!empty($order)) {
    souriau_eco_erp_history_log($order, ['resp_data' => $response->data, 'goid' => $order->goid], $response, 'update');
  }

  return souriau_eco_erp_parse_response($response->data, SOURIAU_ECO_ERP_REQUEST_TYPE, $response);
}

/**
 * Simple XML parser.
 *
 * @param object $element
 *   SimpleXMLElement.
 * @param string $type
 *   Data type: xml|json.
 * @param object $response
 *   Response from Drupal_http_request().
 * @param bool $skip
 *   Skip checking $type xml, for prevent multiply load simplexml_load_string().
 *
 * @return mixed
 *   Parsed xml.
 */
function souriau_eco_erp_parse_response($element, $type, $response = NULL, $skip = FALSE) {
  if (empty($element)) {
    // Nothing to do here.
    return [];
  }
  if (!in_array($type, ['json', 'xml'])) {
    // Nothing to do here.
    return [];
  }
  $parsed_array = [];

  if ($type == 'json') {
    // Todo: check decode json.
    $parsed_array = drupal_json_decode($element);
    return !is_null($parsed_array) ? $parsed_array : [];
  }

  if (!$skip) {
    try {
      libxml_use_internal_errors(TRUE);
      $element = new SimpleXMLElement($element);
    }
    catch (Exception $e) {
      watchdog('souriau_eco_erp', 'Exception %message in !function.', [
        '%message' => $e->getMessage(),
        '!function' => __FUNCTION__,
      ], WATCHDOG_WARNING);
      return [];
    }
  }

  foreach ($element->children() as $key => $child) {
    if (count($child->children()) > 0) {
      $parsed_array[$key] = souriau_eco_erp_parse_response($child, SOURIAU_ECO_ERP_REQUEST_TYPE, NULL, TRUE);
    }
    else {
      $parsed_array[$key] = (string) $child;
    }
  }

  if (!empty($response) && $response->code != 200) {
    $parsed_array['Errors'][] = ['StatusCode' => $response->code . ': ' . $response->status_message];
  }

  return $parsed_array;
}

/**
 * ERP system notifier.
 *
 * @param object $order
 *   Commerce_order.
 * @param string|bool $manual
 *   XML request from BO, or FALSE.
 *
 * @return bool
 *   Success notify or not.
 */
function souriau_eco_erp_notify_erp_system($order, $manual = FALSE) {
  // Prepare request.
  if ($manual) {
    $xml = $manual;
  }
  else {
    $xml = _souriau_eco_erp_notify_erp_system_prepare_request($order, SOURIAU_ECO_ERP_REQUEST_TYPE);
  }

  // Mouser response.
  $response = souriau_eco_erp_get_response(_souriau_eco_erp_mouser_urls('cart_request'), $xml, $order);

  if (empty($response['Errors'])) {
    watchdog('souriau_eco_erp', 'Order @order_id sent to ERP.', ['@order_id' => '#' . $order->order_number]);
    return $response['RedirectURL'];
  }
  $error = reset($response['Errors']);
  souriau_eco_erp_history_log($order, [
    'result' => $error['StatusCode'],
    'status' => 0,
    'goid' => $order->goid,
  ], NULL, 'update');

  return FALSE;
}

/**
 * Prepare xml for mouser request.
 *
 * @param object $order
 *   Order.
 *
 * @return string
 *   XML.
 */
function _souriau_eco_erp_notify_erp_system_prepare_request($order, $type) {
  global $language;
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order)->language($language->language);

  // Client Token.
  $client_token = souriau_eco_erp_get_client_token();

  // Has ever customer sent request to mouser.
  $is_mouser_know_user = _souriau_eco_erp_is_mouser_know_user($order->uid);

  // Prepare blocks for XML request.
  $customer = _souriau_eco_erp_notify_erp_system_prepare_customer_block($order, $order_wrapper, $is_mouser_know_user);
  $cart = _souriau_eco_erp_notify_erp_system_prepare_cart_block($order, $order_wrapper);

  // Checkout Request. New Customer and New Cart.
  $encode_array = [
    'ClientToken' => $client_token,
    'IsAnonymousCustomer' => $is_mouser_know_user ? 'false' : 'true',
    'SupplierOrderId' => $order->order_number,
    'Customer' => $customer,
    'Cart' => $cart,
  ];

  if ($type == 'xml') {
    // Return xml.
    return format_xml_elements(['CartRequest' => $encode_array]);
  }
  // Return json.
  return drupal_json_encode($encode_array);
}

/**
 * Preparing Customer block for notify ERP system.
 *
 * @param object $order
 *   Order object.
 * @param object $order_wrapper
 *   Order metadata wrapper.
 * @param bool $is_mouser_know_user
 *   Has ever customer sent request to mouser. TRUE|FALSE.
 *
 * @return array
 *   For prepare xml/json.
 */
function _souriau_eco_erp_notify_erp_system_prepare_customer_block($order, $order_wrapper, $is_mouser_know_user) {
  global $base_url, $language;
  if (empty($order_wrapper->commerce_customer_shipping->commerce_customer_address)) {
    return [];
  }
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $billing_info = $site_commerce_settings['stock']['billing'];
  $shipping_info = $order_wrapper->commerce_customer_shipping->commerce_customer_address->value();
  $shipping_block = [
    'FirstName' => $shipping_info['first_name'],
    'LastName' => $shipping_info['last_name'],
    'Title' => !empty($shipping_info['civility']) ? $shipping_info['civility'] : '-',
    'AddressLine1' => $shipping_info['thoroughfare'],
    'AddressLine2' => $shipping_info['premise'],
    'City' => !empty($shipping_info['locality']) ? $shipping_info['locality'] : '-',
    'CountryCode' => $shipping_info['country'],
    'RegionCode' => $shipping_info['administrative_area'],
    'PostalCode' => !empty($shipping_info['postal_code']) ? $shipping_info['postal_code'] : '-',
    'Company' => $shipping_info['organisation_name'],
    'EmailAddress' => 'souriau-customer@souriau.com',
    'Phone1' => $shipping_info['phone_number'],
    'Phone2' => $shipping_info['mobile_number'],
  ];
  // Fetching billing address from BO commerce settings.
  $billing_block = [
    'FirstName' => $billing_info['first_name'],
    'LastName' => $billing_info['last_name'],
    'Title' => $billing_info['title'],
    'AddressLine1' => $billing_info['adress_line1'],
    'AddressLine2' => $billing_info['adress_line2'],
    'City' => $billing_info['city'],
    'CountryCode' => $billing_info['country_code'],
    'RegionCode' => $billing_info['region_code'],
    'PostalCode' => $billing_info['postal_code'],
    'Company' => $billing_info['company'],
    'EmailAddress' => $billing_info['email_address'],
    'Phone1' => $billing_info['phone'],
  ];
  // Saving base url on XML request for sample manager redirection after approval return from mouser site.
  $project_q_block = [
    'ExtraItems' => [
      'ArbitraryDataItem' => [
        'Name' => 'domainURL',
        'Value' => urlencode($base_url) . '/' . $language->language,
      ]
    ]
  ];

  $customer_block = [
    'SupplierCustomerId' => $order->uid,
    'BillingAddress' => $billing_block,
    'ShippingAddress' => $shipping_block,
    'ProjectQuestions' => $project_q_block,
  ];

  if ($is_mouser_know_user) {
    return $customer_block;
  }

  return [
    'SupplierCustomerId' => $order->uid,
    'FirstName' => $shipping_info['first_name'],
    'LastName' => $shipping_info['last_name'],
    'EmailAddress' => 'souriau-customer@souriau.com',
    'BillingAddress' => $billing_block,
    'ShippingAddress' => $shipping_block,
    'ProjectQuestions' => $project_q_block,
  ];
}

/**
 * Has ever customer sent request to mouser?.
 *
 * Helper function for get information from log DB.
 */
function _souriau_eco_erp_is_mouser_know_user($uid) {
  module_load_include('inc', 'souriau_eco_erp', 'souriau_eco_erp.db');
  return !empty(souriau_eco_erp_db_select(['uid' => $uid, 'status' => 1], NULL, 1));
}

/**
 * Preparing Cart block for notify ERP system.
 *
 * @param object $order
 *   Order object.
 * @param object $order_wrapper
 *   Order metadata wrapper.
 *
 * @return array
 *   For prepare xml/json.
 */
function _souriau_eco_erp_notify_erp_system_prepare_cart_block($order, $order_wrapper) {
  $cart_items = [];
  $line_items = $order_wrapper->commerce_line_items->value();
  foreach ($line_items as $line_item) {
    // Load SKU.
    $sku = commerce_product_load($line_item->commerce_product[LANGUAGE_NONE][0]['product_id']);

    // Collect Line Items value.
    $line_item = [
      'ManufacturerPartNumber' => $sku->sku,
      'Quantity' => intval($line_item->quantity),
      'UnitPrice' => 1,
      'MaxDollars' => 1,
      'MaxQuantity' => intval($line_item->quantity),
      'IsSample' => 'true',
    ];

    // Prepare array according current request type.
    if ('json' == SOURIAU_ECO_ERP_REQUEST_TYPE) {
      $cart_items[] = $line_item;
    }
    else {
      $cart_items[] = [
        'key' => 'CartItem',
        'value' => $line_item,
      ];
    }
  }

  // Cart block.
  return [
    'IsFreeShipping' => 'true',
    'CartItems' => $cart_items,
  ];
}

/**
 * Logging ERP operations.
 *
 * @param object $order
 *   Sample Order obj.
 * @param string $data
 *   Transferred Data.
 * @param mixed $response
 *   Object, response from drupal_http_request() or NUll.
 * @param string $comment
 *   Comment from UI.
 */
function souriau_eco_erp_history_log($order, $data, $response = NULL, $operation = 'insert', $comment = '') {
  module_load_include('inc', 'souriau_eco_erp', 'souriau_eco_erp.db');

  // Insert timestamp.
  if (isset($data['req_data'])) {
    $data['created'] = time();
  }
  elseif (isset($data['resp_data'])) {
    $data['updated'] = time();
  }

  if (!empty($response)) {
    if ($response->code == 200) {
      $data += [
        'status' => 1,
        'result' => $response->code,
      ];
    }
    else {
      $data += [
        'status' => isset($status) ? $status : '',
        'result' => $response->code . ': ' . $response->status_message,
      ];
    }
  }

  $data += [
    'service' => 'Mouser',
    'order_id' => $order->order_number,
    'uid' => $order->uid,
  ];

  if (!empty($comment)) {
    $data['comment'] = $comment;
  }
  $function = 'souriau_eco_erp_db_' . $operation;
  if (function_exists($function)) {
    return $function($data);
  }
}

/**
 * Prepare xml for mouser request.
 *
 * @return string
 *   XML.
 */
function _souriau_eco_erp_get_order_history_prepare_request($mouser_order_no, $type) {
  $encode_array = [
    'ClientToken' => souriau_eco_erp_get_client_token(),
    'MouserOrderId' => $mouser_order_no,
  ];
  if ($type == 'xml') {
    return format_xml_elements(['OrderHistoryRequest' => $encode_array]);
  }
  return drupal_json_encode($encode_array);
}
