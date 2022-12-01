<?php
/**
 * @file
 * Souriau Compare Part Numbers.
 */

/**
 * Return part numbers ids of current user's session.
 */
function souriau_compare_load_part_numbers() {
  $cookie_name = 'Drupal_visitor_part_numbers';
  return isset($_COOKIE[$cookie_name]) ? explode(',', $_COOKIE[$cookie_name]) : [];
}

/**
 * Render html of tech data.
 */
function souriau_compare_tech_data_content() {

  global $language;

  $render = [
    '#theme' => 'souriau_compare_tech_data',
  ];

  $field_except = [
    'field_sku_view_in_regions',
    'field_view_exception',
    'field_sku_samples_in_regions',
    'field_samples_exception',
    'field_sku_legacy',
    'field_sku_product_series_code',
    'commerce_price',
    'field_sku_application',
    'field_sku_images',
    'field_sku_attachments',
    'field_sku_3d_model',
    'title',
    'field_sku_company',
  ];

  $part_numbers = souriau_compare_load_part_numbers();
  $part_numbers = node_load_multiple($part_numbers);

  $fields = field_info_instances('commerce_product');
  $fields = $fields['sku'];

  usort($fields, function($element_1, $element_2) {
    return (
      $element_1['display']['part_number']['weight'] > $element_2['display']['part_number']['weight']
    ) ? 1 : -1;
  });

  $data = [];

  foreach ($part_numbers as $part_number_nid => $part_number) {
    foreach ($fields as $field) {
      $field_name = $field['field_name'];
      $field_label = $field['label'];

      $value = souriau_compare_get_field_value($field_name, $field_except, $part_number, $language, $field);

      if ($field['widget']['type'] == 'options_onoff') {
        $value = ($value == 1) ? t('Yes', [], ['context' => SOURIAU_COMMON_T_OTHER]) : t('No', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      }
      if ($value !== FALSE) {
        $data[$field_label][$part_number_nid] = $value;
      }
    }
  }

  foreach ($data as $field_label => $values) {
    $_values = implode('', $values);
    $_values = str_replace('&nbsp;', '', $_values);
    $_values = trim($_values);

    if (empty($_values)) {
      unset($data[$field_label]);
    }
  }

  $render['#tech_data'] = $data;
  $render['#part_numbers'] = $part_numbers;

  return drupal_render($render);
}

/**
 * Extract value from part number field.
 *
 * @return string|false
 *   Return field value or false if field in $field_except.
 */
function souriau_compare_get_field_value($field_name, $field_except, $part_number, $language, $field) {
  if (in_array($field_name, $field_except)) {
    return FALSE;
  }

  $part_number_wrapper = entity_metadata_wrapper('node', $part_number)->language($language->language);
  $sku = $part_number_wrapper->field_sku_products->value();

  $field_display = field_get_display($field, 'part_number', $sku);
  if ($field_display['type'] == 'hidden') {
    return FALSE;
  }

  $commerce_product = entity_metadata_wrapper('commerce_product', $sku);

  $value = $commerce_product->{$field_name}->value();
  $value = is_array($value) ? $value : [$value];
  $value = implode(', ', $value);
  $value = empty($value) ? '&nbsp;' : $value;

  return $value;
}

/**
 * Render html of part number list.
 */
function souriau_compare_part_number_list_content() {

  global $language;

  ctools_include('modal');
  ctools_include('ajax');

  $render = [
    '#theme' => 'souriau_compare_part_number_list',
  ];

  $part_numbers = souriau_compare_load_part_numbers();
  if ($part_numbers) {
    $part_numbers = node_load_multiple($part_numbers);
    foreach ($part_numbers as $part_number_entity) {
      $part_number = [
        '#theme' => 'souriau_compare_part_number_list_item',
      ];

      $_part_number = entity_metadata_wrapper('node', $part_number_entity)->language($language->language);
      $sku = $_part_number->field_sku_products->value();

      $part_number['#product_id'] = $_part_number->nid->value();
      $part_number['#product_title'] = $_part_number->title->value();
      $part_number['#product_code'] = $sku->sku;
      $part_number['#product_image'] = '';

      if ($product_range = $_part_number->field_parent_product_range->value()) {

        $product_range = array_shift($product_range);
        if ($product_range = node_load($product_range->nid)) {
          $product_range = entity_metadata_wrapper('node', $product_range)->language($language->language);

          $product_series = $product_range->field_product_series->value();
          $part_number['#product_series'] = souriau_common_get_product_series_name($product_series);
        }
      }

      $part_number['#product_image'] = NULL;

      // Build image data.
      $images = field_get_items('commerce_product', $sku, 'field_sku_images');
      $image = isset($images[0]) ? array_shift($images) : [];
      $part_number['#product_image'] = [
        '#type' => 'figure_pic',
        '#image' => $image,
        '#style' => 'media_thumbnail',
        '#attributes' => [
          'style' => 'display: inline',
        ],
      ];
      $part_number['#product_image'] = drupal_render($part_number['#product_image']);

      $class = 'ctools-modal-souriau-modal-style ctools-use-modal btn orange-btn-hover';
      $w_btn_text = t('WHERE TO BUY', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      $where_to_buy_url = "souriau/ajax/distributors/{$sku->sku}/nojs";

      $part_number['#where_to_buy'] = ctools_modal_text_button(
        $w_btn_text, $where_to_buy_url, '', $class
      );

      $render['#part_numbers'][$part_number['#product_id']] = drupal_render($part_number);
    }
  }

  return drupal_render($render);
}
