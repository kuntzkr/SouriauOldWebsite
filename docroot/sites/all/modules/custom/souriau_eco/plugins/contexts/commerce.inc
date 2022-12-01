<?php

/**
 * @file
 * Plugin to provide the context for Commerce Checkout.
 */

$plugin = array(
  'title' => t("Commerce Checkout Context"),
  'description' => t('Context required for the commerce checkout page'),
  'context' => 'souriau_eco_create_commerce',
  'keyword' => 'commerce_order',
  'context name' => 'commerce',
);

/**
 * Context create callback.
 *
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function souriau_eco_create_commerce($empty, $data = NULL, $conf = FALSE) {

  $context = new ctools_context('commerce');
  $context->plugin = 'commerce';

  if ($empty) {
    return $context;
  }

  if (!empty($data)) {
    $context->data = $data;

    return $context;
  }
  return;
}
