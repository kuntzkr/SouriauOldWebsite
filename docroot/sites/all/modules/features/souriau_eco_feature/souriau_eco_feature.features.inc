<?php
/**
 * @file
 * souriau_eco_feature.features.inc
 */

/**
 * Implements hook_default_commerce_order_type().
 */
function souriau_eco_feature_default_commerce_order_type() {
  $items = array();
  $items['samples_order'] = entity_import('commerce_order_type', '{
    "type" : "samples_order",
    "help" : "",
    "data" : null,
    "name" : "Samples Order"
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_eco_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function souriau_eco_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
