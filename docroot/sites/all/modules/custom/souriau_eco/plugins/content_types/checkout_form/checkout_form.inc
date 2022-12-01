<?php

/**
 * @file
 * Commerce panels integration plugin to handle the checkout form.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('SOURIAU: Commerce Checkout Form', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'description' => t('SOURIAU: Commerce Checkout Form', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'hook theme' => 'souriau_eco_checkout_form_content_type_theme',
  'render callback' => 'souriau_eco_checkout_form_content_type_render',
);

/**
 * Output function for the commerce checkout form.
 */
function souriau_eco_checkout_form_content_type_render($subtype, $conf, $panel_args, $context) {

  $order = isset($panel_args) ? clone($panel_args[0]) : NULL;
  $checkout_page = isset($panel_args) ? $panel_args[1] : NULL;

  $block = new stdClass();

  module_load_include('inc', 'commerce_checkout', 'includes/commerce_checkout.pages');

  $render_params = [
    '#theme' => 'souriau_eco_checkout_form_' . $checkout_page['page_id'],
    '#form' => commerce_checkout_router($order, $checkout_page),
    '#order' => $order,
    '#checkout_page' => $checkout_page,
  ];

  $block->content = drupal_render($render_params);
  return $block;
}

/**
 * A blank form so we have a place to have context settings.
 */
function souriau_eco_checkout_form_content_type_edit_form($form, &$form_state) {
  // Provide a blank form so we have a place to have context setting.
  return $form;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_eco_checkout_form_content_type_theme(&$theme, $plugin) {
  $theme['souriau_eco_checkout_form_shipping'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-checkout-form',
    'variables' => [
      'form' => NULL,
    ],
  ];

  $theme['souriau_eco_checkout_form_complete'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-checkout-form-complete',
    'variables' => [
      'order' => NULL,
    ],
  ];

  $theme['souriau_eco_checkout_form_list_address_item'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-checkout-form-address-item',
    'render element' => 'element',
  ];
  $theme['souriau_eco_checkout_form_list_address'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-checkout-form-address',
    'render element' => 'element',
  ];
}
