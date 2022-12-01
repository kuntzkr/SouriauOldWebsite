<?php
/**
 * @file
 * souriau_site_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_site_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function souriau_site_feature_image_default_styles() {
  $styles = array();

  // Exported image style: complementary_product_thumb.
  $styles['complementary_product_thumb'] = array(
    'label' => 'Complementary Product Thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => 128,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: search_page_preview.
  $styles['search_page_preview'] = array(
    'label' => 'Search Page Preview',
    'effects' => array(
      8 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 192,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
