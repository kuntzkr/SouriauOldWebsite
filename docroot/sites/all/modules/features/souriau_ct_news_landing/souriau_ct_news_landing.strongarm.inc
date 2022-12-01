<?php
/**
 * @file
 * souriau_ct_news_landing.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_ct_news_landing_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__news_landing';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'search_autocomplete' => array(
        'custom_settings' => FALSE,
      ),
      'search_results' => array(
        'custom_settings' => FALSE,
      ),
      'product_landing_page' => array(
        'custom_settings' => FALSE,
      ),
      'category_page' => array(
        'custom_settings' => FALSE,
      ),
      'subcategory_page' => array(
        'custom_settings' => FALSE,
      ),
      'product_range_page' => array(
        'custom_settings' => FALSE,
      ),
      'application_page' => array(
        'custom_settings' => FALSE,
      ),
      'applicationdomain_page' => array(
        'custom_settings' => FALSE,
      ),
      'application_landing_page' => array(
        'custom_settings' => FALSE,
      ),
      'news_pane_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'capability_landing_page' => array(
        'custom_settings' => FALSE,
      ),
      'capabilitydomain_page' => array(
        'custom_settings' => FALSE,
      ),
      'part_number' => array(
        'custom_settings' => FALSE,
      ),
      'cart_summary' => array(
        'custom_settings' => FALSE,
      ),
      'news_landing_pane_teaser' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '3',
        ),
        'metatags' => array(
          'weight' => '6',
        ),
        'title' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '4',
        ),
        'language' => array(
          'weight' => '5',
        ),
        'rabbit_hole' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__news_landing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_news_landing';
  $strongarm->value = '4';
  $export['language_content_type_news_landing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_news_landing';
  $strongarm->value = array();
  $export['menu_options_news_landing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_news_landing';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_news_landing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_news_landing';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_news_landing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_news_landing';
  $strongarm->value = '1';
  $export['node_preview_news_landing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_news_landing';
  $strongarm->value = 1;
  $export['node_submitted_news_landing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_ch-ch_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_ch-ch_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_en-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_en-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_en-en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_en-en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_en-gb_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_en-gb_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_en-int_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_en-int_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_en-us_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_en-us_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_es-sp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_es-sp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_fr-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_fr-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_fr-fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_fr-fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_it_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_it_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_jp-jp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_jp-jp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_lang-copy_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_lang-copy_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_na_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_na_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_test_code_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_test_code_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_news_landing_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_news_landing_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_news_landing';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_news_landing'] = $strongarm;

  return $export;
}
