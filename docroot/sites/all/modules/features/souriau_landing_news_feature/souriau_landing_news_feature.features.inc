<?php
/**
 * @file
 * souriau_landing_news_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function souriau_landing_news_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function souriau_landing_news_feature_image_default_styles() {
  $styles = array();

  // Exported image style: news_preview_image.
  $styles['news_preview_image'] = array(
    'label' => 'News preview image',
    'effects' => array(
      9 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 460,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
