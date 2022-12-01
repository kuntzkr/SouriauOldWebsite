<?php
/**
 * @file
 * Souriau Ecommerce tokens.
 */

/**
 * Implements hook_token_info_alter().
 */
function souriau_eco_token_info_alter(&$data) {
  // Tokens for orders.
  $data['tokens']['commerce-order']['lite-line-orders'] = [
    'name' => t('Line Orders Lite', [], ['context' => 'a drupal commerce order']),
    'description' => t('Lite variant of displaying line items'),
  ];
}

/**
 * Implements hook_tokens().
 */
function souriau_eco_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = [];

  if ($type == 'commerce-order' && !empty($data['commerce-order'])) {
    $order = $data['commerce-order'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'lite-line-orders':
          $replacements[$original] = souriau_eco_tokens_lite_line_orders($order);
          break;

        default:
          break;
      }
    }

    if ($owner_tokens = token_find_with_prefix($tokens, 'owner')) {
      $owner = user_load($order->uid);
      $replacements += token_generate('user', $owner_tokens, array('user' => $owner), $options);
    }

    foreach (array('created', 'changed') as $date) {
      if ($created_tokens = token_find_with_prefix($tokens, $date)) {
        $replacements += token_generate('date', $created_tokens, array('date' => $order->{$date}), $options);
      }
    }
  }

  return $replacements;
}

/**
 * Helper for replace token [commerce-order:lite-line-orders].
 */
function souriau_eco_tokens_lite_line_orders($order) {
  $wrapper = entity_metadata_wrapper('commerce_order', $order);
  $items = $wrapper->commerce_line_items->value();

  if (!is_array($items)) {
    return;
  }

  foreach ($items as $item) {
    $item_wrapper = entity_metadata_wrapper('commerce_line_item', $item);
    $sku = $item_wrapper->commerce_product->value();
    $product = souriau_common_load_part_number_by_sku($sku->sku);
    $title = $product->title;

    $rows[] = [
      'data' => [
        ['data' => $sku->sku, 'class' => ['col1'], 'valign' => 'top'],
        ['data' => $title, 'class' => ['col2'], 'valign' => 'top'],
        ['data' => $item->quantity, 'class' => ['col3'], 'valign' => 'top'],
      ],
      'no_striping' => TRUE,
    ];
  }

  $header = [
    t('Part Number', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    t('Product Name', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    t('Quantity', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  ];

  return theme('table', [
    'header' => $header,
    'rows' => $rows,
    'attributes' => [
      'border' => '1',
      'style' => ['border-collapse:collapse;'],
    ],
  ]);
}

/**
 * Implements hook_tokens_alter().
 */
function souriau_eco_tokens_alter(array &$replacements, array $context) {
  $data = $context['data'];
  $options = $context['options'];
  $tokens = $context['tokens'];

  if ($context['type'] == 'commerce-order' && isset($tokens['created'])) {
    return souriau_eco_tokens_alter_commerce_order($replacements, $tokens, $data, $options);
  }
}

/**
 * Alter tokens for commerce_order.
 */
function souriau_eco_tokens_alter_commerce_order($replacements, $tokens, $data, $options) {
  if (empty($data['commerce-order'])) {
    return;
  }

  $language_code = isset($options['language']) ? $options['language']->language : NULL;
  $order = $data['commerce-order'];

  $replacements[$tokens['created']] = format_date($order->created, 'souriau_date_short', '', NULL, $language_code);
}
