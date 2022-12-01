<?php
/**
 * @file
 * Minicart callbacks and functions.
 */

/**
 * Get the Cart count.
 */
function souriau_common_minicart_get_cart_count() {
  global $user;
  $quantity = 0;

  $order = commerce_cart_order_load($user->uid);

  if ($order) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order);
    $line_items = $wrapper->commerce_line_items;
    $quantity = commerce_line_items_quantity($line_items, commerce_product_line_item_types());
  }

  return $quantity;
}

/**
 * Header cart count block builder function.
 */
function souriau_common_minicart_header_build_cart($minicart_ajax = TRUE) {
  global $is_https, $base_url;
  if (!souriau_common_sample_checkout_status()) {
    return;
  }

  $cart_count = 0;
  if ($minicart_ajax == TRUE) {
    $cart_count = souriau_common_minicart_get_cart_count();
  }
  $cart = [
    'title' => t('Cart', [], ['context' => SOURIAU_COMMON_T_HEADER]),
    'count' => $cart_count,
    'link_path' => ($cart_count == 0) ? 'cart' : 'checkout',
  ];

  $icon = [
    '#type' => 'svg_icon',
    '#icon' => 'ico-cart',
  ];
  $cart_link_title = drupal_render($icon) . $cart['title'];
  if ($cart_count > 0) {
    $cart_link_title .= '<span class="ico-count">' . $cart['count'] . '</span>';
  }
  $options = [
    'html'  => TRUE,
    'attributes' => [
      'class' => ['cart-link'],
      'id' => ['header-cart-count']
    ],
  ];

  $link_path = l(
    $cart_link_title,
    (!$is_https && module_exists('domain_alias')) ? $base_url . url($cart['link_path']) : $cart['link_path'],
    $options
  );

  $output = [
    'cart' => $cart,
    'link_path' => $link_path,
  ];
  return $output;
}

/**
 * Popup cart block.
 */
function souriau_common_header_build_popup_cart() {
  global $user;
  // Load the commerce checkout pages to be able to call.
  // the function commerce_checkout_router().
  module_load_include('inc', 'commerce_cart', 'includes/commerce_cart.pages');

  // Default to displaying an empty message.
  $content = '';
  $content = theme('empty_cart');

  // First check to make sure we have a valid order.
  if ($order = commerce_cart_order_load($user->uid)) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order);
    if (commerce_line_items_quantity($wrapper->commerce_line_items, commerce_product_line_item_types()) > 0) {
      // Add the form for editing the cart contents.
      $content = commerce_embed_view('souriau_minicart', 'panel_cart', [$order->order_id], 'cart');
    }
  }

  return $content;
}
