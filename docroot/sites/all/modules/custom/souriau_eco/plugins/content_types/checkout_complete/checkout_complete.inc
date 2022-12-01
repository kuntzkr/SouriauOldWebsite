<?php

/**
 * @file
 * Commerce panels integration plugin to handle the checkout complete message.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'single' => TRUE,
  'title' => t('Commerce Checkout Complete message'),
  'description' => t('The Checkout complete message and registaration form.'),
  'category' => t('SOURIAU'),
  'hook theme' => 'souriau_eco_checkout_complete_content_type_theme',
);

/**
 * Output function for the commerce checkout form.
 */
function souriau_eco_checkout_complete_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language, $user;
  $langcode = $language->language;

  $_html = array();

  $order = isset($panel_args) ? clone($panel_args[0]) : NULL;
  $checkout_page = isset($panel_args) ? $panel_args[1] : NULL;

  $block = new stdClass();

  // First check to make sure we have a valid order.
  if ($order) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order);

    // Order number.
    $_html['order_number'] = $order->order_number;
  }

  $data['_html'] = $_html;

  $block->content = theme('souriau_eco_checkout_complete', $data);

  return $block;
}

/**
 * A blank form so we have a place to have context settings.
 */
function souriau_eco_checkout_complete_content_type_edit_form($form, &$form_state) {
  // Provide a blank form so we have a place to have context setting.
  return $form;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_eco_checkout_complete_content_type_theme(&$theme, $plugin) {
  $theme['souriau_eco_checkout_complete'] = array(
    'path'      => $plugin['path'],
    'template'  => 'souriau-eco-checkout-complete',
    'variables' => array('params' => array()),
  );
}
