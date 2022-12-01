<?php

/**
 * @file
 * souriau_cpt_sku.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function souriau_cpt_sku_commerce_product_default_types() {
  $items = array(
    'sku' => array(
      'type' => 'sku',
      'name' => 'SKU',
      'description' => '',
      'help' => '',
      'revision' => 0,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_cpt_sku_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
