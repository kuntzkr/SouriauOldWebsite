<?php
/**
 * @file
 * souriau_ct_application.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_ct_application_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_application';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_application';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_application';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_application';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_application';
  $strongarm->value = array(
    0 => 'DOMAIN_ALL',
    1 => 'central_esterline_com',
  );
  $export['domain_node_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'draft_moderation_node_application';
  $strongarm->value = '2';
  $export['draft_moderation_node_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_application';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_application';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__application';
  $strongarm->value = array(
    'default_language' => 'xx-et-default',
    'hide_language_selector' => 1,
    'exclude_language_none' => 1,
    'lock_language' => 1,
    'shared_fields_original_only' => 1,
  );
  $export['entity_translation_settings_node__application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__application';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '9',
        ),
        'metatags' => array(
          'weight' => '12',
        ),
        'path' => array(
          'weight' => '11',
        ),
        'xmlsitemap' => array(
          'weight' => '10',
        ),
        'rabbit_hole' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'domain' => array(
          'search_autocomplete' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_paragraphs_item__application_example';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_paragraphs_item__application_example'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_paragraphs_item__application_paragraph';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_paragraphs_item__application_paragraph'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_application';
  $strongarm->value = '4';
  $export['language_content_type_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_application';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_application';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__application';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_application';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_application';
  $strongarm->value = '1';
  $export['node_preview_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_application';
  $strongarm->value = 1;
  $export['node_submitted_application'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_ch-ch_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_ch-ch_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_en-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_en-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_en-en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_en-en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_en-gb_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_en-gb_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_en-int_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_en-int_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_en-us_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_en-us_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_es-sp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_es-sp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_fr-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_fr-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_fr-fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_fr-fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_it_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_it_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_jp-jp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_jp-jp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_lang-copy_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_lang-copy_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_na_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_na_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_pattern';
  $strongarm->value = '[node:souriau_alias]/[node:souriau_default_translation_title]';
  $export['pathauto_node_application_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_test_code_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_test_code_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_application_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_application_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_application';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_application'] = $strongarm;

  return $export;
}
