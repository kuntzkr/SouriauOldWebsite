<?php
/**
 * @file
 * Plugin to provide an argument handler for a erp-order (%erp-order).
 */

$plugin = array(
  'title' => t("ERP Order"),
  // Keyword to use for %erp_order.
  'keyword' => 'erp_order',
  'description' => t('An argument that can be used to get the commerce checkout page as a context.'),
  'context' => 'erp_order_panels_argument_commerce_checkout_page',
  'no ui' => FALSE,
);

/**
 * Discover if this argument gives us the order we crave.
 */
function erp_order_panels_argument_commerce_checkout_page($arg = NULL, $conf = NULL, $empty = FALSE) {
  // If unset it wants a generic, unfilled context.
  if (empty($arg)) {
    $context = ctools_context_create_empty('erp_order');
    $context->type = 'erp_order';
    return $context;
  }

  $context = ctools_context_create('erp_order', $arg);
  $context->original_argument = $arg;
  $context->type = 'erp_order';

  return $context;
}
