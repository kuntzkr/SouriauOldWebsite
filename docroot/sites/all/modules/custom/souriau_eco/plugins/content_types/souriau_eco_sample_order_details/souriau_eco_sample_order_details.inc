<?php
/**
 * @file
 * User Sample Order details.
 */

$plugin = [
  'title' => t('SOURIAU Eco: Sample Orders Details Page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'description' => t('SOURIAU Eco: Sample Orders Details Page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'content_types' => 'souriau_eco_sample_order_details',
  'single' => TRUE,
  'render callback' => 'souriau_eco_sample_order_details_content_type_render',
  'hook theme' => 'souriau_eco_sample_order_details_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
];

/**
 * Implements hook_content_type_render().
 */
function souriau_eco_sample_order_details_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language;
  $block = new stdClass();
  $block->title = NULL;
  $data = [];
  // Load commerce order object.
  $order = commerce_order_load($panel_args[1]);
  $data['order'] = $order;
  // Get order details.
  $data['uid'] = $panel_args[0];
  $data['created_date'] = date("m/d/Y", $order->created);
  $data['changed_date'] = date("m/d/Y", $order->changed);
  // Get shipping infomation.
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order)->language($language->language);
  $data['shipping_info'] = $order_wrapper->commerce_customer_shipping->commerce_customer_address->value();
  $data['lineitems'] = views_embed_view('user_sample_orders_details', 'default', $panel_args[0], $panel_args[1]);
  // Theme template used.
  $block->content = theme('souriau_eco_sample_order_details', $data);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_eco_sample_order_details_content_type_theme(&$theme, $plugin) {
  $theme['souriau_eco_sample_order_details'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-sample-order-details',
  ];
}
