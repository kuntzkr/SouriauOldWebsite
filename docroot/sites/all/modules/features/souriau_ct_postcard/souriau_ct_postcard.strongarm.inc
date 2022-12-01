<?php
/**
 * @file
 * souriau_ct_postcard.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_ct_postcard_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_postcard';
  $strongarm->value = 'edit-display';
  $export['additional_settings__active_tab_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_nodes_main';
  $strongarm->value = '10';
  $export['default_nodes_main'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_postcard';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_postcard';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_postcard';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_postcard';
  $strongarm->value = array(
    0 => 'DOMAIN_ALL',
    1 => 'central_esterline_com',
  );
  $export['domain_node_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'draft_moderation_node_postcard';
  $strongarm->value = '2';
  $export['draft_moderation_node_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_postcard';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_postcard';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_actions_postcard';
  $strongarm->value = array();
  $export['expire_node_actions_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_custom_pages_postcard';
  $strongarm->value = '';
  $export['expire_node_custom_pages_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_custom_postcard';
  $strongarm->value = 0;
  $export['expire_node_custom_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_front_page_postcard';
  $strongarm->value = 0;
  $export['expire_node_front_page_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_node_page_postcard';
  $strongarm->value = 1;
  $export['expire_node_node_page_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_override_defaults_postcard';
  $strongarm->value = 0;
  $export['expire_node_override_defaults_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_reference_pages_postcard';
  $strongarm->value = 0;
  $export['expire_node_reference_pages_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'expire_node_term_pages_postcard';
  $strongarm->value = 0;
  $export['expire_node_term_pages_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__postcard';
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
          'weight' => '1',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '2',
        ),
        'xmlsitemap' => array(
          'weight' => '3',
        ),
        'metatags' => array(
          'weight' => '40',
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
          'default' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_postcard';
  $strongarm->value = '4';
  $export['language_content_type_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_postcard';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_postcard';
  $strongarm->value = '';
  $export['maxlength_js_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_postcard';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_postcard';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__postcard';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_postcard';
  $strongarm->value = array();
  $export['node_options_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_postcard';
  $strongarm->value = '1';
  $export['node_preview_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_revision_delete_number_postcard';
  $strongarm->value = '50';
  $export['node_revision_delete_number_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_revision_delete_track_postcard';
  $strongarm->value = 0;
  $export['node_revision_delete_track_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_postcard';
  $strongarm->value = 0;
  $export['node_submitted_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publish_button_content_type_postcard';
  $strongarm->value = 0;
  $export['publish_button_content_type_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'redirect_setting_name_postcard';
  $strongarm->value = 'rh_node_redirect';
  $export['redirect_setting_name_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_module_postcard';
  $strongarm->value = 'rh_node';
  $export['rh_module_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_action_postcard';
  $strongarm->value = '0';
  $export['rh_node_action_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_override_postcard';
  $strongarm->value = 0;
  $export['rh_node_override_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_postcard';
  $strongarm->value = '';
  $export['rh_node_redirect_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_response_postcard';
  $strongarm->value = '301';
  $export['rh_node_redirect_response_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'rh_node_redirect_type_postcard';
  $strongarm->value = 0;
  $export['rh_node_redirect_type_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'webform_node_postcard';
  $strongarm->value = 0;
  $export['webform_node_postcard'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_postcard';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_postcard'] = $strongarm;

  return $export;
}
