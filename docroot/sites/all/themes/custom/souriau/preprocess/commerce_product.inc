<?php

/**
 * @file
 * Preprocess commerce_product.
 */

/**
 * Implements hook_preprocess_ENTITY__BUNDLE__VIEW_MODE().
 */
function souriau_preprocess_commerce_product__sku__part_number(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $sku = $variables['commerce_product'];
  $fields = field_info_instances('commerce_product');
  $fields = $fields['sku'];

  $domain = domain_get_domain();
  $domain_configuration = domain_conf_variable_get($domain['domain_id'], 'souriau_common_sku_attributes');

  $field_translatable = souriau_search_get_sku_translatable_fields();

  $_html['tech_data'] = '';
  $sort_array = [];
  foreach ($fields as $field_name => $field) {
    if (!in_array($field_name, array_keys($domain_configuration)) || !$domain_configuration[$field_name]['enabled']) {
      continue;
    }

    $items = field_get_items('commerce_product', $sku, $field_name);
    if (empty($items)) {
      continue;
    }

    $values = [];
    foreach ($items as $item) {
      if ($field['widget']['type'] == 'options_onoff' && $item['value'] == TRUE) {
        $item['value'] = t('Yes', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      }
      elseif ($field['widget']['type'] == 'options_onoff' && $item['value'] == FALSE) {
        $item['value'] = t('No', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      }
      $value = field_view_value('commerce_product', $sku, $field_name, $item, 'default');
      if (in_array($field_name, $field_translatable)) {
        $value['#markup'] = t($value['#markup'], [], ['context' => SOURIAU_COMMON_T_SKU]);
      }
      $values[] = render($value);
    }
    // Prepare sort array.
    $sort_array[$domain_configuration[$field_name]['weight']]['value'] = implode('<br />', $values);
    $sort_array[$domain_configuration[$field_name]['weight']]['label'] = $field['label'];
  }
  // Sort array by weight.
  ksort($sort_array);

  // Data to template.
  $_html['tech_data'] = $sort_array;
}

/**
 * Implements hook_preprocess_ENTITY_TYPE__BUNDLE__VIEW_MODE().
 */
function souriau_preprocess_commerce_product__sku__node_cart_summary(&$variables) {
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $product = $variables['commerce_product'];
  $product_wrapper = entity_metadata_wrapper('commerce_product', $product);
  $_data['partnumber_title'] = '';
  $_data['partnumber_url'] = '';
  $_data['display_name'] = '';
  $_html['image'] = '';

  if (!empty($product->field_sku_images)) {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $product_wrapper->field_sku_images[0]->value(),
      '#attributes' => [],
    ];
    $_html['image'] = drupal_render($image);
  }

  $part_number = souriau_common_load_part_number_by_sku($product->sku);
  if (!$part_number) {
    watchdog('souriau eco', 'Shopping cart page: unknown part number for !sku', ['!sku' => $product->sku], WATCHDOG_WARNING);
    return;
  }
  $part_number_wrapper = entity_metadata_wrapper('node', $part_number);
  $_data['partnumber_title'] = $part_number_wrapper->label();
  $_data['partnumber_url'] = $part_number_wrapper->url->value();
  $main_product_range = souriau_common_get_main_product_range($part_number);
  if (!$main_product_range) {
    watchdog('souriau eco', 'Shopping cart page: Unknown main product range for !sku', ['!sku' => $product->sku], WATCHDOG_WARNING);
    return;
  }
  if (empty($main_product_range->field_product_series)) {
    watchdog('souriau eco', 'Shopping cart page: unknown main product range series for !sku', ['!sku' => $product->sku], WATCHDOG_WARNING);
    return;
  }
  $main_product_range_wrapper = entity_metadata_wrapper('node', $main_product_range);
  $_data['display_name'] = $main_product_range_wrapper->field_product_series->label();
}

/**
 * Implements hook_preprocess_ENTITY_TYPE__BUNDLE__VIEW_MODE().
 */
function souriau_preprocess_commerce_product__sku__node_minicart_summary(&$variables) {
  souriau_preprocess_commerce_product__sku__node_cart_summary($variables);
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $product = $variables['commerce_product'];
  $_data['sku'] = $product->sku;
}
