<?php
/**
 * @file
 * Forms.
 */

/**
 * Implements hook_form().
 */
function souriau_eco_erp_ui_form($form, &$form_state) {
  $args = func_get_args();
  $order = array_pop($args);

  module_load_include('inc', 'souriau_eco_erp', 'souriau_eco_erp.db');
  module_load_include('inc', 'souriau_eco_erp', 'souriau_eco_erp.pages');
  $erp_logs = souriau_eco_erp_db_select(['order_id' => $order->order_number]);
  if (!empty($erp_logs)) {
    $last_log = array_shift($erp_logs);
    // Return information about last request.
    $form = _souriau_eco_erp_ui_form_last_responce($last_log);
  }

  $form['erp'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Request XML'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#description' => t('ERP request XML.'),
    '#weight' => 5,
  ];

  $form['erp']['xml'] = array(
    '#title' => t('ERP XML'),
    '#type' => 'textarea',
    '#default_value' => isset($last_log) ? $last_log->req_data : _souriau_eco_erp_notify_erp_system_prepare_request($order, SOURIAU_ECO_ERP_REQUEST_TYPE),
    '#weight' => -1,
  );
  $form['erp']['send'] = [
    '#type' => 'submit',
    '#value' => 'send request'
  ];

  if (!empty($erp_logs)) {
    // Set request history, without last.
    $form['history'] = _souriau_eco_erp_ui_form_history($erp_logs);
  }
  return $form;
}

/**
 * Helper function. Display information about last request.
 */
function _souriau_eco_erp_ui_form_last_responce($last_log) {
  // Response.
  $response = souriau_eco_erp_parse_response($last_log->resp_data, SOURIAU_ECO_ERP_REQUEST_TYPE);
  $rows[] = [
    format_date($last_log->created, 'medium'),
    souriau_eco_erp_pages_dprint_r($response, 1),
    $last_log->uid,
    $last_log->result,
    $last_log->status,
  ];
  $table = theme('table', [
    'header' => [
      t('Date'),
      t('Response'),
      t('User ID'),
      t('Result'),
      t('Status'),
    ],
    'rows' => $rows,
  ]);

  $form['last_item'] = [
    '#type'   => 'item',
    '#markup' => $table,
  ];

  $form['xml'] = [
    '#type'        => 'fieldset',
    '#title'       => t('Preview current xml build'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#description' => t('Shows the entity in the format of XML string that corresponds to ERP request.'),
    '#weight' => 1,
  ];
  $form['xml']['erp_request'] = [
    '#type'   => 'item',
    '#markup' => souriau_eco_erp_pages_dprint_r($last_log->req_data, 1),
  ];

  return $form;
}

/**
 * Helper function. Create table with history.
 *
 * @see souriau_eco_erp_ui_form()
 */
function _souriau_eco_erp_ui_form_history($erp_logs) {
  $form = [
    '#type'        => 'fieldset',
    '#title'       => t('History'),
    '#collapsible' => TRUE,
    '#collapsed'   => TRUE,
    '#description' => t('ERP requests history.'),
    '#weight' => 100,
  ];
  $rows = [];
  foreach ($erp_logs as $log) {
    $response = souriau_eco_erp_parse_response($log->resp_data, SOURIAU_ECO_ERP_REQUEST_TYPE);
    $rows[] = [
      format_date($log->created, 'medium'),
      souriau_eco_erp_pages_dprint_r($log->req_data, 1),
      souriau_eco_erp_pages_dprint_r($response, 1),
      $log->uid,
      $log->result,
      $log->status,
    ];
  }
  // Fill in table values.
  $history_table = theme('table', [
    'header' => [
      t('Date'),
      t('Request'),
      t('Response'),
      t('User ID'),
      t('Result'),
      t('Status'),
    ],
    'rows' => $rows,
  ]);
  // Add aditional fieldset.
  $form['history_fieldset'] = [
    '#type' => 'item',
    '#markup' => $history_table,
  ];
  return $form;
}

/**
 * Implements hook_form_submit.
 */
function souriau_eco_erp_ui_form_submit($form, &$form_state) {
  global $language;
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $orders = $form_state['build_info']['args'];
  $xml = $form_state['values']['xml'];
  $order = reset($orders);
  $redirect_url = souriau_eco_erp_notify_erp_system($order, $xml);
  if ($redirect_url === FALSE) {
    _souriau_eco_commerce_order_samples_order_notify_admins($order, $site_commerce_settings);
    drupal_set_message(t('Mouser order confirmation error, please check logs', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));
    return;
  }
  // Saving cart redirect URL.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order)->language($language->language);
  $order_wrapper->field_commerce_cart_url->set($redirect_url);
  commerce_order_save($order);
  // Logging all order confirmations done by site admin.
  watchdog('souriau_eco_erp', 'Order %order_number confirmation sent to mouser by Admin with Cart URL %redirect_url',
  ['%order_number' => $order->order_id, '%redirect_url' => $redirect_url]);
}

/**
 * Function to request confirmation before approval.
 */
function souriau_eco_erp_order_item_approve_callback($form, &$form_state, $order) {
  $form['order'] = [
    '#type' => 'value',
    '#value' => $order,
  ];

  return confirm_form($form, t('Are you sure you want to approve the sample order No - %order_number ?', ['%order_number' => $order->order_id], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'admin/dashboard/ecommerce/mouser-orders');

}

/**
 * Implements hook_form_submit, after approval notifies in erp and redirect to mouser 3pl site.
 */
function souriau_eco_erp_order_item_approve_callback_submit($form, &$form_state) {
  global $language;
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $redirect_url = souriau_eco_erp_notify_erp_system($form_state['values']['order'], FALSE);

  if ($redirect_url === FALSE) {
    _souriau_eco_commerce_order_samples_order_notify_admins($form_state['values']['order'], $site_commerce_settings);
    drupal_set_message(t('Mouser order confirmation error, please check logs', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));
    drupal_goto('admin/dashboard/ecommerce/mouser-orders');
    return;
  }

  // Saving cart redirect URL.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $form_state['values']['order'])->language($language->language);
  $order_wrapper->field_commerce_cart_url->set($redirect_url);
  commerce_order_save($form_state['values']['order']);
  drupal_goto($redirect_url);
}

/**
 * Function to handle return url after order confirmation on 3pl site by approver.
 */
function souriau_eco_erp_pages_confirm_callback() {
  global $language;
  module_load_include('inc', 'souriau_eco_erp', 'souriau_eco_erp.db');
  $parameters = drupal_get_query_parameters();
  if (empty($parameters['OrderID']) || empty($parameters['MouserOrderID'])) {
    drupal_access_denied();
    return;
  }
  $order = commerce_order_load($parameters['OrderID']);
  // Commerce order status and mouser order number update.
  commerce_order_status_update($order, 'completed');
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order)->language($language->language);
  $order_wrapper->field_commerce_mouser_status->set('processing');
  $order_wrapper->field_commerce_mouser_orderno->set($parameters['MouserOrderID']);

  commerce_order_save($order);
  drupal_set_message(t('Order approved and processing started, please check logs', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));
  // Fetching domain url from ERP request xml.
  $erp_logs = souriau_eco_erp_db_select(['order_id' => $order->order_number]);
  $last_log = array_shift($erp_logs);
  $erp_xml = souriau_eco_erp_parse_response($last_log->req_data, 'xml');
  drupal_goto(urldecode($erp_xml['Customer']['ProjectQuestions']['ExtraItems']['ArbitraryDataItem']['Value']) . '/admin/dashboard/ecommerce/mouser-orders');
}

/**
 * Function to request to confirm order manual cancelation by sample manager.
 */
function souriau_eco_erp_order_item_cancel_callback($form, &$form_state, $order) {
  $form['order'] = [
    '#type' => 'value',
    '#value' => $order,
  ];

  $form['cancel_reason']  = array(
    '#title' => t('Reason for Cancellation', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    '#type' => 'textarea',
    '#description' => t('Please specify reason for order cancellation', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    '#rows' => 3,
    '#cols' => 30,
    '#resizable' => TRUE,
    '#required' => TRUE,
  );

  return confirm_form($form, t('Are you sure you want to cancel the sample order No - %order_number ?', ['%order_number' => $order->order_id], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'admin/dashboard/ecommerce/mouser-orders');
}

/**
 * Implements hook_form_submit, order cancels and notify in erp and redirect to mouser order page.
 */
function souriau_eco_erp_order_item_cancel_callback_submit($form, &$form_state) {
  global $language;

  $order_wrapper = entity_metadata_wrapper('commerce_order', $form_state['values']['order'])->language($language->language);
  // Saving reason for order cancellation.
  $order_wrapper->field_commerce_cancel_desc->set($form_state['values']['cancel_reason']);
  $order_wrapper->field_commerce_mouser_status->set('canceled');
  // Commerce order status update.
  commerce_order_status_update($form_state['values']['order'], 'canceled');
  commerce_order_save($form_state['values']['order']);
  drupal_set_message(t('Order cancelled, please check logs', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));
  drupal_goto('admin/dashboard/ecommerce/mouser-orders');

}
