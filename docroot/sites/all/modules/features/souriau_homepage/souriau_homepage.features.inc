<?php
/**
 * @file
 * souriau_homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_homepage_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function souriau_homepage_image_default_styles() {
  $styles = array();

  // Exported image style: news_and_events_image.
  $styles['news_and_events_image'] = array(
    'label' => 'News and Events Image',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 300,
          'height' => 300,
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
function souriau_homepage_node_info() {
  $items = array(
    'homepage' => array(
      'name' => t('Homepage'),
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

/**
 * Implements hook_paragraphs_info().
 */
function souriau_homepage_paragraphs_info() {
  $items = array(
    'homepage_promotion_links' => array(
      'name' => 'Homepage promotion links',
      'bundle' => 'homepage_promotion_links',
      'locked' => '1',
    ),
    'homepage_slides' => array(
      'name' => 'Homepage slides',
      'bundle' => 'homepage_slides',
      'locked' => '1',
    ),
  );
  return $items;
}
