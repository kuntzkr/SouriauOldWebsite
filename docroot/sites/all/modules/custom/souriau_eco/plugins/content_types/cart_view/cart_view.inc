<?php

/**
 * @file
 * Commerce panels integration plugin to handle the Cart form.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Commerce Cart View'),
  'description' => t('The Commerce Cart View'),
  'category' => t('SOURIAU'),
  'render last' => TRUE,
);

/**
 * Output function for the commerce checkout form.
 */
function souriau_eco_cart_view_content_type_render($subtype = NULL, $conf = NULL, $panel_args = NULL, $context = NULL) {
  global $user;

  // Load the commerce checkout pages to be able to call
  // the function commerce_checkout_router().
  module_load_include('inc', 'commerce_cart', 'includes/commerce_cart.pages');

  // Default to displaying an empty message.
  $content = '';
  // Get empty cart message.
  $content = theme('empty_cart_page');

  // First check to make sure we have a valid order.
  if ($order = commerce_cart_order_load($user->uid)) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order);

    // Only show the cart form if we found product line items.
    if (commerce_line_items_quantity($wrapper->commerce_line_items, commerce_product_line_item_types()) > 0) {

      // Add the form for editing the cart contents.
      $content = commerce_embed_view('commerce_cart_form', 'panel_cart', array($order->order_id), 'cart');
    }
  }

  $block = new stdClass();
  $block->content = $content;

  if (empty($_POST) && function_exists('qtools_api__cache_tag_apply')) {
    $order_id = empty($order->order_id) ? 0 : $order->order_id;
    qtools_api__cache_tag_apply(qtools_api__cache_tag('commerce_order', $order_id));
  }

  return $block;
}

/**
 * A blank form so we have a place to have context settings.
 */
function souriau_eco_cart_view_content_type_edit_form($form, &$form_state) {
  // Provide a blank form so we have a place to have context setting.
  return $form;
}
