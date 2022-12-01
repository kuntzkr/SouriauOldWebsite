<?php
/**
 * @file
 * souriau_ct_capability.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_ct_capability_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_capability';
  $strongarm->value = 'edit-webform';
  $export['additional_settings__active_tab_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_capability';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_capability';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_capability';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'draft_moderation_node_capability';
  $strongarm->value = '2';
  $export['draft_moderation_node_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_capability';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_capability';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__capability';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_node__capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__capability';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '9',
        ),
        'metatags' => array(
          'weight' => '10',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '7',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
        'language' => array(
          'weight' => '5',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'domain' => array(
          'capabilitydomain_page' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'capability_landing_page' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'sharethis' => array(
          'capabilitydomain_page' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_capability';
  $strongarm->value = '4';
  $export['language_content_type_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_capability';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_capability';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__capability';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_capability';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_capability';
  $strongarm->value = '1';
  $export['node_preview_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_capability';
  $strongarm->value = 1;
  $export['node_submitted_capability'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_ch-ch_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_ch-ch_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_en-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_en-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_en-en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_en-en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_en-gb_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_en-gb_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_en-int_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_en-int_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_en-us_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_en-us_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_es-sp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_es-sp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_fr-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_fr-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_fr-fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_fr-fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_it_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_it_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_jp-jp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_jp-jp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_lang-copy_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_lang-copy_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_na_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_na_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_pattern';
  $strongarm->value = '[node:souriau_alias]/[node:souriau_default_translation_title]';
  $export['pathauto_node_capability_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_test_code_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_test_code_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capability_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capability_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_capability';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_capability'] = $strongarm;

  return $export;
}
