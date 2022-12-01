<?php
/**
 * @file
 * souriau_ct_capability_domain.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_ct_capability_domain_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_capabilitydomain';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_capabilitydomain';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_capabilitydomain';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_capabilitydomain';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_capabilitydomain';
  $strongarm->value = array(
    0 => 'DOMAIN_ALL',
    1 => 'DOMAIN_ACTIVE',
  );
  $export['domain_node_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'draft_moderation_node_capabilitydomain';
  $strongarm->value = '2';
  $export['draft_moderation_node_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_capabilitydomain';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_capabilitydomain';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__capabilitydomain';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_node__capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__capabilitydomain';
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
      'news_page' => array(
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
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '8',
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
          'capability_landing_page' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'sharethis' => array(
          'capability_landing_page' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_capabilitydomain';
  $strongarm->value = '4';
  $export['language_content_type_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_capabilitydomain';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_capabilitydomain';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__capabilitydomain';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_capabilitydomain';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_capabilitydomain';
  $strongarm->value = '1';
  $export['node_preview_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_capabilitydomain';
  $strongarm->value = 1;
  $export['node_submitted_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_ch-ch_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_ch-ch_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_en-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_en-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_en-en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_en-en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_en-gb_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_en-gb_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_en-int_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_en-int_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_en-us_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_en-us_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_es-sp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_es-sp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_fr-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_fr-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_fr-fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_fr-fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_it_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_it_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_jp-jp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_jp-jp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_lang-copy_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_lang-copy_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_na_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_na_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_pattern';
  $strongarm->value = '[node:souriau_alias]/[node:souriau_default_translation_title]';
  $export['pathauto_node_capabilitydomain_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_test_code_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_test_code_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_capabilitydomain_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_capabilitydomain_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_capabilitydomain';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_capabilitydomain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_capabilitydomain';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_capabilitydomain'] = $strongarm;

  return $export;
}
