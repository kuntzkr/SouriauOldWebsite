<?php
/**
 * @file
 * souriau_eco_feature.features.commerce_checkout_panes.inc
 */

/**
 * Implements hook_commerce_checkout_panes_default().
 */
function souriau_eco_feature_commerce_checkout_panes_default() {
  $panes = array();

  $panes['account'] = array(
    'page' => 'disabled',
    'weight' => -20,
    'pane_id' => 'account',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['cart_contents'] = array(
    'page' => 'checkout',
    'weight' => -20,
    'pane_id' => 'cart_contents',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['checkout_completion_message'] = array(
    'page' => 'complete',
    'fieldset' => 0,
    'pane_id' => 'checkout_completion_message',
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => 0,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['checkout_review'] = array(
    'page' => 'disabled',
    'fieldset' => 0,
    'pane_id' => 'checkout_review',
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -17,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['commerce_payment'] = array(
    'page' => 'disabled',
    'weight' => -16,
    'pane_id' => 'commerce_payment',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['commerce_payment_redirect'] = array(
    'page' => 'payment',
    'pane_id' => 'commerce_payment_redirect',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'weight' => -20,
    'enabled' => 1,
    'review' => 1,
  );

  $panes['commerce_shipping'] = array(
    'page' => 'disabled',
    'weight' => -19,
    'review' => 0,
    'pane_id' => 'commerce_shipping',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
  );

  $panes['customer_profile_billing'] = array(
    'page' => 'disabled',
    'weight' => -18,
    'pane_id' => 'customer_profile_billing',
    'fieldset' => 1,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 0,
    'review' => 1,
  );

  $panes['customer_profile_shipping'] = array(
    'page' => 'shipping',
    'weight' => -19,
    'pane_id' => 'customer_profile_shipping',
    'fieldset' => 0,
    'collapsible' => 0,
    'collapsed' => 0,
    'enabled' => 1,
    'review' => 1,
  );

  return $panes;
}
