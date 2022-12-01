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
  'title' => t('SOURIAU: Commerce Checkout Steps'),
  'description' => t('The checkout steps'),
  'category' => t('SOURIAU'),
);

/**
 * Output function for the commerce checkout form.
 */
function souriau_eco_checkout_steps_content_type_render($subtype, $conf, $panel_args, $context) {

  $order = isset($panel_args) ? clone($panel_args[0]) : NULL;
  $checkout_page = isset($panel_args) ? $panel_args[1] : NULL;

  $block = new stdClass();
  $steps = [
    t('CART', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) => [
      NULL,
    ],
    t('SHIPPING INFORMATION', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) => [
      'shipping',
    ],
    t('CONFIRMATION', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) => [
      'complete',
    ],
  ];

  $items = [];
  foreach ($steps as $step => $checkout_steps) {
    $item = ['data' => $step];
    if (in_array($checkout_page['page_id'], $checkout_steps)) {
      $item['class'] = ['active'];
    }
    $items[] = $item;
  }

  $list = [
    '#theme' => 'item_list',
    '#items' => $items,
    'type' => 'ul',
  ];

  $block->content = '<div class="b-steps"><div class="container">' . render($list) . '</div></div>';

  return $block;
}

/**
 * A blank form so we have a place to have context settings.
 */
function souriau_eco_checkout_steps_content_type_edit_form($form, &$form_state) {
  // Provide a blank form so we have a place to have context setting.
  return $form;
}
