<?php
/**
 * @file
 * souriau_ct_product_landing.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_ct_product_landing_ctools_plugin_api($module = NULL, $api = NULL) {
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
function souriau_ct_product_landing_image_default_styles() {
  $styles = array();

  // Exported image style: product_thumbnails.
  $styles['product_thumbnails'] = array(
    'label' => 'Product Thumbnails',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 255,
          'height' => 144,
          'upscale' => 0,
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
function souriau_ct_product_landing_node_info() {
  $items = array(
    'productlanding' => array(
      'name' => t('Product Landing'),
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
