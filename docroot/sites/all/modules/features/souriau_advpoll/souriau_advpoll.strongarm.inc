<?php
/**
 * @file
 * souriau_advpoll.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_advpoll_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'draft_moderation_node_advpoll';
  $strongarm->value = '2';
  $export['draft_moderation_node_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_advpoll';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_advpoll';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__advpoll';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 0,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_node__advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__advpoll';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'search_autocomplete' => array(
        'custom_settings' => TRUE,
      ),
      'search_results' => array(
        'custom_settings' => TRUE,
      ),
      'product_landing_page' => array(
        'custom_settings' => TRUE,
      ),
      'category_page' => array(
        'custom_settings' => TRUE,
      ),
      'subcategory_page' => array(
        'custom_settings' => TRUE,
      ),
      'product_range_page' => array(
        'custom_settings' => TRUE,
      ),
      'application_page' => array(
        'custom_settings' => TRUE,
      ),
      'applicationdomain_page' => array(
        'custom_settings' => TRUE,
      ),
      'application_landing_page' => array(
        'custom_settings' => TRUE,
      ),
      'news_pane_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'capability_landing_page' => array(
        'custom_settings' => TRUE,
      ),
      'capabilitydomain_page' => array(
        'custom_settings' => TRUE,
      ),
      'part_number' => array(
        'custom_settings' => TRUE,
      ),
      'cart_summary' => array(
        'custom_settings' => TRUE,
      ),
      'minicart_summary' => array(
        'custom_settings' => TRUE,
      ),
      'news_landing_pane_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'tool_page' => array(
        'custom_settings' => TRUE,
      ),
      'homepage' => array(
        'custom_settings' => TRUE,
      ),
      'toolkitlanding' => array(
        'custom_settings' => TRUE,
      ),
      'genericlanding' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '18',
        ),
        'metatags' => array(
          'weight' => '21',
        ),
        'path' => array(
          'weight' => '19',
        ),
        'rabbit_hole' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
        'xmlsitemap' => array(
          'weight' => '20',
        ),
        'language' => array(
          'weight' => '11',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_advpoll';
  $strongarm->value = '4';
  $export['language_content_type_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_advpoll';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_advpoll';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_advpoll';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_advpoll';
  $strongarm->value = '1';
  $export['node_preview_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_advpoll';
  $strongarm->value = 0;
  $export['node_submitted_advpoll'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_advpoll';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_advpoll'] = $strongarm;

  return $export;
}
