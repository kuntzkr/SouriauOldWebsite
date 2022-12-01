<?php
/**
 * @file
 * Plugin to provide user access on page orders.
 */

$plugin = [
  'title' => t('Souriau Eco: Access on page ERP Orders', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'description' => t('Souriau Eco: Provide user access on page ERP Orders', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'callback' => 'souriau_eco_access_orders',
  'summary' => 'souriau_eco_access_orders_summary',
  'required context' => array(
    new ctools_context_required(t('User', [], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'user'),
  ),
];

/**
 * Check for access.
 */
function souriau_eco_access_orders($conf, $context) {
  global $user;

  // Block to anonymous users.
  if (user_is_anonymous()) {
    return FALSE;
  }

  // Grant access by permission.
  if (user_access('bypass_access_order_history')) {
    return TRUE;
  }

  // Load user wrapper.
  $user_wrapper = entity_metadata_wrapper('user', $user);

  // Access to all orders page.
  if (!empty($context[0]->data) && ($context[0]->data->uid != $user->uid)) {
    // If context-user_id doesn't match with current user_id, access denied.
    return FALSE;
  }

  // Check on access status.
  $access_status = $user_wrapper->field_order_history_access_st->value();
  if ($access_status != 'approved') {
    return FALSE;
  }

  return TRUE;
}

/**
 * Provide a summary description.
 */
function souriau_eco_access_orders_summary($conf, $context) {
  return t('Grand user access to own orders page.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
}
