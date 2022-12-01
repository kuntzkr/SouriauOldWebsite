<?php

/**
 * @file
 * souriau_cpt_sku.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_cpt_sku_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_commerce_product__sku';
  $strongarm->value = array(
    'extra_fields' => array(
      'display' => array(
        'sku' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '0',
          ),
          'part_number' => array(
            'visible' => FALSE,
            'weight' => '166',
          ),
        ),
        'status' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '5',
          ),
          'part_number' => array(
            'visible' => FALSE,
            'weight' => '168',
          ),
        ),
        'title' => array(
          'default' => array(
            'visible' => TRUE,
            'weight' => '1',
          ),
        ),
      ),
      'form' => array(
        'sku' => array(
          'weight' => '0',
        ),
        'status' => array(
          'weight' => '12',
        ),
        'title' => array(
          'weight' => '2',
        ),
      ),
    ),
    'view_modes' => array(
      'commerce_line_item_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_display' => array(
        'custom_settings' => FALSE,
      ),
      'commerce_line_item_token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'line_item' => array(
        'custom_settings' => TRUE,
      ),
      'node_application_landing_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_application_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_applicationdomain_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_capability_landing_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_capabilitydomain_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_cart_summary' => array(
        'custom_settings' => FALSE,
      ),
      'node_category_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'node_full' => array(
        'custom_settings' => FALSE,
      ),
      'node_genericlanding' => array(
        'custom_settings' => FALSE,
      ),
      'node_homepage' => array(
        'custom_settings' => FALSE,
      ),
      'node_minicart_summary' => array(
        'custom_settings' => FALSE,
      ),
      'node_news_landing_pane_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'node_news_pane_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'node_part_number' => array(
        'custom_settings' => FALSE,
      ),
      'node_product_landing_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_product_range_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_rss' => array(
        'custom_settings' => FALSE,
      ),
      'node_search_autocomplete' => array(
        'custom_settings' => FALSE,
      ),
      'node_search_results' => array(
        'custom_settings' => FALSE,
      ),
      'node_subcategory_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'node_token' => array(
        'custom_settings' => FALSE,
      ),
      'node_tool_page' => array(
        'custom_settings' => FALSE,
      ),
      'node_toolkitlanding' => array(
        'custom_settings' => FALSE,
      ),
      'part_number' => array(
        'custom_settings' => TRUE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
  );
  $export['field_bundle_settings_commerce_product__sku'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_regions_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_regions_pattern'] = $strongarm;

  return $export;
}
