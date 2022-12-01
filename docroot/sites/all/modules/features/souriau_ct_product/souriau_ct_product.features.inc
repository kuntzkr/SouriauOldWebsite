<?php
/**
 * @file
 * souriau_ct_product.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_product_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function souriau_ct_product_image_default_styles() {
  $styles = array();

  // Exported image style: part_number_image.
  $styles['part_number_image'] = array(
    'label' => 'Part Number image: 500x400',
    'effects' => array(
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 500,
          'height' => 400,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function souriau_ct_product_node_info() {
  $items = array(
    'product' => array(
      'name' => t('Part Number'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
