<?php
/**
 * @file
 * Plugin to provide user access on Single order page.
 */

$plugin = [
  'title' => t('Souriau Eco: Access to Single Order page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'description' => t('Souriau Eco: Provide user access on single order page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'callback' => 'souriau_eco_access_single_order',
  'summary' => 'souriau_eco_access_single_order_summary',
  'required context' => array(
    new ctools_context_required(t('ERP Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'erp_order'),
  ),
];

/**
 * Check for access.
 */
function souriau_eco_access_single_order($conf, $context) {
  global $user;

  // Block to anonymous users.
  if (user_is_anonymous()) {
    return FALSE;
  }

  // Grant access by permission.
  if (user_access('bypass_access_order_history')) {
    return TRUE;
  }

  // Load wrapper.
  $user_wrapper = entity_metadata_wrapper('user', $user);

  // Check on access status.
  $access_status = $user_wrapper->field_order_history_access_st->value();
  if ($access_status != 'approved') {
    return FALSE;
  }

  // Access to Single erp-order.
  if ($context[0] && $context[0]->data) {
    $user_ect_numbers = $user_wrapper->field_ect_customer_numbers->value();
    $erp_order_id = $context[0]->data;
    $order = souriau_eco_load_user_orders_info(['order_id' => $erp_order_id]);
    if (!in_array($order->cust_erp_code, $user_ect_numbers)) {
      return FALSE;
    }
  }

  return TRUE;
}

/**
 * Provide a summary description.
 */
function souriau_eco_access_single_order_summary($conf, $context) {
  return t('Grand user access to own single order page.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
}
