<?php
/**
 * @file
 * souriau_ct_application_landing.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_ct_application_landing_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_applicationlanding';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_applicationlanding';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_applicationlanding';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_applicationlanding';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'draft_moderation_node_applicationlanding';
  $strongarm->value = '2';
  $export['draft_moderation_node_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_applicationlanding';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_applicationlanding';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__applicationlanding';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_node__applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__applicationlanding';
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
      'application_landing_page' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '3',
        ),
        'metatags' => array(
          'weight' => '5',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'domain' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
        'sharethis' => array(
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_applicationlanding';
  $strongarm->value = '4';
  $export['language_content_type_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_applicationlanding';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_applicationlanding';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__applicationlanding';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_applicationlanding';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_applicationlanding';
  $strongarm->value = '1';
  $export['node_preview_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_applicationlanding';
  $strongarm->value = 1;
  $export['node_submitted_applicationlanding'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_ch-ch_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_ch-ch_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_en-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_en-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_en-en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_en-en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_en-gb_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_en-gb_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_en-int_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_en-int_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_en-us_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_en-us_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_es-sp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_es-sp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_fr-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_fr-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_fr-fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_fr-fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_it_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_it_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_jp-jp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_jp-jp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_lang-copy_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_lang-copy_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_na_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_na_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_test_code_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_test_code_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_applicationlanding_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_applicationlanding_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_applicationlanding';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_applicationlanding'] = $strongarm;

  return $export;
}
