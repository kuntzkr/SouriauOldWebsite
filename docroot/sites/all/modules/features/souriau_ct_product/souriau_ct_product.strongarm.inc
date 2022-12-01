<?php
/**
 * @file
 * souriau_ct_product.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_ct_product_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_product';
  $strongarm->value = 'edit-workflow';
  $export['additional_settings__active_tab_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_product';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_product';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_product';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'domain_node_product';
  $strongarm->value = array(
    0 => 'DOMAIN_ALL',
    1 => 'DOMAIN_ACTIVE',
  );
  $export['domain_node_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'draft_moderation_node_product';
  $strongarm->value = '0';
  $export['draft_moderation_node_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_hide_translation_links_product';
  $strongarm->value = 1;
  $export['entity_translation_hide_translation_links_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_node_metadata_product';
  $strongarm->value = '0';
  $export['entity_translation_node_metadata_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_translation_settings_node__product';
  $strongarm->value = array(
    'default_language' => 'und',
    'hide_language_selector' => 0,
    'exclude_language_none' => 0,
    'lock_language' => 0,
    'shared_fields_original_only' => 0,
  );
  $export['entity_translation_settings_node__product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__product';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'domain' => array(
          'weight' => '8',
        ),
        'metatags' => array(
          'weight' => '7',
        ),
        'path' => array(
          'weight' => '6',
        ),
        'xmlsitemap' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '-5',
        ),
        'rabbit_hole' => array(
          'weight' => '0',
        ),
        'redirect' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(
        'product:sku' => array(
          'default' => array(
            'weight' => '-10',
            'visible' => FALSE,
          ),
          'search_autocomplete' => array(
            'weight' => '65',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '42',
            'visible' => FALSE,
          ),
        ),
        'product:title' => array(
          'default' => array(
            'weight' => '-5',
            'visible' => FALSE,
          ),
          'search_autocomplete' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'cart_summary' => array(
            'weight' => '44',
            'visible' => FALSE,
          ),
        ),
        'product:status' => array(
          'default' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'search_autocomplete' => array(
            'weight' => '1',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '62',
            'visible' => FALSE,
          ),
        ),
        'product:commerce_price' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '83',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '45',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_aviation' => array(
          'default' => array(
            'weight' => '53',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '51',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_avionics' => array(
          'default' => array(
            'weight' => '55',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '53',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_backshell_delivery' => array(
          'default' => array(
            'weight' => '35',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '35',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_breaking_capability' => array(
          'default' => array(
            'weight' => '25',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '22',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '73',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_commercial_marine' => array(
          'default' => array(
            'weight' => '64',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '62',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_company' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '2',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '46',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_connector_type' => array(
          'default' => array(
            'weight' => '9',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '55',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_delivery' => array(
          'default' => array(
            'weight' => '23',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '71',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_gender' => array(
          'default' => array(
            'weight' => '15',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '65',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_size_awg' => array(
          'default' => array(
            'weight' => '20',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '81',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_size_mm' => array(
          'default' => array(
            'weight' => '21',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '84',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_type' => array(
          'default' => array(
            'weight' => '13',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '60',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_core_section_mm2' => array(
          'default' => array(
            'weight' => '27',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '24',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '91',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_coupling' => array(
          'default' => array(
            'weight' => '11',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '67',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_current_a' => array(
          'default' => array(
            'weight' => '22',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '113',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_defense' => array(
          'default' => array(
            'weight' => '59',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '57',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_energy' => array(
          'default' => array(
            'weight' => '46',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '44',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_engines_wing_landgear' => array(
          'default' => array(
            'weight' => '54',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '52',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_entertainmentbroadcast' => array(
          'default' => array(
            'weight' => '45',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '43',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_environmental' => array(
          'default' => array(
            'weight' => '12',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '141',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_function' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '82',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '140',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_ground_army' => array(
          'default' => array(
            'weight' => '60',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '58',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_in_flight' => array(
          'default' => array(
            'weight' => '56',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '54',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_industrial' => array(
          'default' => array(
            'weight' => '36',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '37',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_infrastructure' => array(
          'default' => array(
            'weight' => '41',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '39',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_instrument_measurement' => array(
          'default' => array(
            'weight' => '36',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '30',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_layout' => array(
          'default' => array(
            'weight' => '17',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '166',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_lighting_building' => array(
          'default' => array(
            'weight' => '43',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '41',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_machinery_robotics' => array(
          'default' => array(
            'weight' => '37',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '32',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_marine' => array(
          'default' => array(
            'weight' => '63',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '61',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_mating_cycles' => array(
          'default' => array(
            'weight' => '33',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '31',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '126',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_medical' => array(
          'default' => array(
            'weight' => '40',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '38',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_military_aircraft' => array(
          'default' => array(
            'weight' => '58',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '56',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_military_marine' => array(
          'default' => array(
            'weight' => '65',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '63',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_mining' => array(
          'default' => array(
            'weight' => '39',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '36',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_missiles_weapons' => array(
          'default' => array(
            'weight' => '61',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '59',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_motorsport' => array(
          'default' => array(
            'weight' => '66',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '64',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_nuclear' => array(
          'default' => array(
            'weight' => '49',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '47',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_of_contacts' => array(
          'default' => array(
            'weight' => '19',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '86',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_off_road' => array(
          'default' => array(
            'weight' => '38',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '34',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_oil_gas' => array(
          'default' => array(
            'weight' => '48',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '46',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_plating' => array(
          'default' => array(
            'weight' => '7',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '76',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_plug_type' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '63',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_portable_energy' => array(
          'default' => array(
            'weight' => '50',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '48',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_power_distribution' => array(
          'default' => array(
            'weight' => '57',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '55',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_railway' => array(
          'default' => array(
            'weight' => '51',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '49',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_receptacle_mount_type' => array(
          'default' => array(
            'weight' => '8',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '58',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_renewable_energy' => array(
          'default' => array(
            'weight' => '47',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '45',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_salt_spray' => array(
          'default' => array(
            'weight' => '14',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '121',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_sealing_level' => array(
          'default' => array(
            'weight' => '34',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '33',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '128',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_shell_continuity_mohm' => array(
          'default' => array(
            'weight' => '32',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '29',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '124',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_shell_material' => array(
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '70',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_shell_size' => array(
          'default' => array(
            'weight' => '16',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '78',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_standard' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '80',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '50',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_telecom_datacom' => array(
          'default' => array(
            'weight' => '42',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '40',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_temp_max_c' => array(
          'default' => array(
            'weight' => '30',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '27',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '134',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_temp_max_f' => array(
          'default' => array(
            'weight' => '31',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '28',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '135',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_temp_min_c' => array(
          'default' => array(
            'weight' => '28',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '129',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_temp_min_f' => array(
          'default' => array(
            'weight' => '29',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '132',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_traffic_equipment' => array(
          'default' => array(
            'weight' => '44',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '42',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_unmanned_vehicules' => array(
          'default' => array(
            'weight' => '62',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '60',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_voltage_v' => array(
          'default' => array(
            'weight' => '24',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_vrms' => array(
          'default' => array(
            'weight' => '18',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '120',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_wire_awg' => array(
          'default' => array(
            'weight' => '26',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '7',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_wiring_interconnsys' => array(
          'default' => array(
            'weight' => '52',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '50',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_samples_in_regions' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '79',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '51',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_view_in_regions' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '81',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '47',
            'visible' => FALSE,
          ),
        ),
        'domain' => array(
          'default' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
          'search_autocomplete' => array(
            'weight' => '78',
            'visible' => FALSE,
          ),
          'cart_summary' => array(
            'weight' => '49',
            'visible' => FALSE,
          ),
        ),
        'product:field_samples_exception' => array(
          'cart_summary' => array(
            'weight' => '54',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_active_part_technology' => array(
          'cart_summary' => array(
            'weight' => '20',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_application' => array(
          'cart_summary' => array(
            'weight' => '164',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_backshell_angle' => array(
          'cart_summary' => array(
            'weight' => '72',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_backshell_type' => array(
          'cart_summary' => array(
            'weight' => '59',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_body' => array(
          'cart_summary' => array(
            'weight' => '105',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_diam_max_inch' => array(
          'cart_summary' => array(
            'weight' => '88',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_diam_max_mm' => array(
          'cart_summary' => array(
            'weight' => '97',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_diam_min_inch' => array(
          'cart_summary' => array(
            'weight' => '80',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_diam_min_mm' => array(
          'cart_summary' => array(
            'weight' => '87',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_diameter' => array(
          'cart_summary' => array(
            'weight' => '64',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_ending' => array(
          'cart_summary' => array(
            'weight' => '104',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_length_m' => array(
          'cart_summary' => array(
            'weight' => '82',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_cable_type' => array(
          'cart_summary' => array(
            'weight' => '75',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_certification_csa' => array(
          'cart_summary' => array(
            'weight' => '183',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_certification_iec' => array(
          'cart_summary' => array(
            'weight' => '187',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_certification_ul' => array(
          'cart_summary' => array(
            'weight' => '163',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_color_stripes_marking' => array(
          'cart_summary' => array(
            'weight' => '16',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_complementary_part_num' => array(
          'cart_summary' => array(
            'weight' => '90',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_connector_accessory_op' => array(
          'cart_summary' => array(
            'weight' => '100',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_connector_side_1' => array(
          'cart_summary' => array(
            'weight' => '77',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_connector_side_2' => array(
          'cart_summary' => array(
            'weight' => '102',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_active_part_te' => array(
          'cart_summary' => array(
            'weight' => '30',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_compatibilitie' => array(
          'cart_summary' => array(
            'weight' => '53',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_packaging' => array(
          'cart_summary' => array(
            'weight' => '11',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_plating' => array(
          'cart_summary' => array(
            'weight' => '57',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_contact_standard' => array(
          'cart_summary' => array(
            'weight' => '52',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_current_breaking_capac' => array(
          'cart_summary' => array(
            'weight' => '161',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_description_sealing_le' => array(
          'cart_summary' => array(
            'weight' => '66',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_ending_1' => array(
          'cart_summary' => array(
            'weight' => '98',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_ending_2' => array(
          'cart_summary' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_ferrule_holder' => array(
          'cart_summary' => array(
            'weight' => '36',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_ferrule_material' => array(
          'cart_summary' => array(
            'weight' => '32',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_fiber_dimension' => array(
          'cart_summary' => array(
            'weight' => '39',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_fiber_optic_contact_te' => array(
          'cart_summary' => array(
            'weight' => '18',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_fire_smoke' => array(
          'cart_summary' => array(
            'weight' => '146',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_first_mate_last_break_' => array(
          'cart_summary' => array(
            'weight' => '107',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_flammability_rating' => array(
          'cart_summary' => array(
            'weight' => '180',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_fluids' => array(
          'cart_summary' => array(
            'weight' => '151',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_gender_side_1' => array(
          'cart_summary' => array(
            'weight' => '83',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_gender_side_2' => array(
          'cart_summary' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_halogen_free' => array(
          'cart_summary' => array(
            'weight' => '143',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_height_mm' => array(
          'cart_summary' => array(
            'weight' => '149',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_insert_material' => array(
          'cart_summary' => array(
            'weight' => '112',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_insulation_grip' => array(
          'cart_summary' => array(
            'weight' => '28',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_last_mate_first_break_' => array(
          'cart_summary' => array(
            'weight' => '109',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_layout_1' => array(
          'cart_summary' => array(
            'weight' => '92',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_layout_2' => array(
          'cart_summary' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_legacy' => array(
          'cart_summary' => array(
            'weight' => '56',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_length_mm' => array(
          'cart_summary' => array(
            'weight' => '153',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_manufacturing_process' => array(
          'cart_summary' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_mating_connector' => array(
          'cart_summary' => array(
            'weight' => '68',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_max_curr_cavity_s00' => array(
          'cart_summary' => array(
            'weight' => '196',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_max_curr_cavity_s000' => array(
          'cart_summary' => array(
            'weight' => '197',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_max_curr_cavity_s0000' => array(
          'cart_summary' => array(
            'weight' => '198',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_maximum_current_cavity' => array(
          'cart_summary' => array(
            'weight' => '195',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_module' => array(
          'cart_summary' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_05mm' => array(
          'cart_summary' => array(
            'weight' => '116',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_07mm' => array(
          'cart_summary' => array(
            'weight' => '117',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_09mm' => array(
          'cart_summary' => array(
            'weight' => '119',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_100mm' => array(
          'cart_summary' => array(
            'weight' => '142',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_10mm' => array(
          'cart_summary' => array(
            'weight' => '122',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_120mm' => array(
          'cart_summary' => array(
            'weight' => '144',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_15mm' => array(
          'cart_summary' => array(
            'weight' => '125',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_16mm' => array(
          'cart_summary' => array(
            'weight' => '127',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_20mm' => array(
          'cart_summary' => array(
            'weight' => '130',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_25mm' => array(
          'cart_summary' => array(
            'weight' => '131',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_30mm' => array(
          'cart_summary' => array(
            'weight' => '133',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_36mm' => array(
          'cart_summary' => array(
            'weight' => '136',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_50mm' => array(
          'cart_summary' => array(
            'weight' => '138',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_70mm' => array(
          'cart_summary' => array(
            'weight' => '139',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_coax_cts' => array(
          'cart_summary' => array(
            'weight' => '147',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_elio' => array(
          'cart_summary' => array(
            'weight' => '145',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_power_co' => array(
          'cart_summary' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s00' => array(
          'cart_summary' => array(
            'weight' => '41',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s000' => array(
          'cart_summary' => array(
            'weight' => '111',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s0000' => array(
          'cart_summary' => array(
            'weight' => '114',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s10' => array(
          'cart_summary' => array(
            'weight' => '26',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s12' => array(
          'cart_summary' => array(
            'weight' => '24',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s12_mini' => array(
          'cart_summary' => array(
            'weight' => '40',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s14' => array(
          'cart_summary' => array(
            'weight' => '23',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s16' => array(
          'cart_summary' => array(
            'weight' => '21',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s16_mini' => array(
          'cart_summary' => array(
            'weight' => '108',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s2' => array(
          'cart_summary' => array(
            'weight' => '38',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s20' => array(
          'cart_summary' => array(
            'weight' => '19',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s22d' => array(
          'cart_summary' => array(
            'weight' => '17',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s26' => array(
          'cart_summary' => array(
            'weight' => '15',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s4' => array(
          'cart_summary' => array(
            'weight' => '37',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s6' => array(
          'cart_summary' => array(
            'weight' => '34',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s8_coax_' => array(
          'cart_summary' => array(
            'weight' => '31',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s8_power' => array(
          'cart_summary' => array(
            'weight' => '29',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_s8_quadr' => array(
          'cart_summary' => array(
            'weight' => '33',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_signal_c' => array(
          'cart_summary' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_nut_material' => array(
          'cart_summary' => array(
            'weight' => '110',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_overmolding_material' => array(
          'cart_summary' => array(
            'weight' => '13',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_packaging_quantity' => array(
          'cart_summary' => array(
            'weight' => '93',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_pcb_diameter_mm' => array(
          'cart_summary' => array(
            'weight' => '25',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_pcb_length' => array(
          'cart_summary' => array(
            'weight' => '27',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_pcb_length_out_connect' => array(
          'cart_summary' => array(
            'weight' => '159',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_pcb_tail_angle' => array(
          'cart_summary' => array(
            'weight' => '22',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_pitch' => array(
          'cart_summary' => array(
            'weight' => '99',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_plating_detail' => array(
          'cart_summary' => array(
            'weight' => '162',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_product_range' => array(
          'cart_summary' => array(
            'weight' => '101',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_product_series_code' => array(
          'cart_summary' => array(
            'weight' => '61',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_replacement' => array(
          'cart_summary' => array(
            'weight' => '95',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_s10_contact_rating' => array(
          'cart_summary' => array(
            'weight' => '193',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_s12_contact_rating' => array(
          'cart_summary' => array(
            'weight' => '192',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_s16_contact_rating' => array(
          'cart_summary' => array(
            'weight' => '191',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_s20_contact_rating' => array(
          'cart_summary' => array(
            'weight' => '190',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_s22_contact_rating' => array(
          'cart_summary' => array(
            'weight' => '189',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_s26_contact_rating' => array(
          'cart_summary' => array(
            'weight' => '188',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_s8_contact_rating' => array(
          'cart_summary' => array(
            'weight' => '194',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_shielding' => array(
          'cart_summary' => array(
            'weight' => '137',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_shock' => array(
          'cart_summary' => array(
            'weight' => '156',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_size_contact' => array(
          'cart_summary' => array(
            'weight' => '12',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_souriau_equivalent_par' => array(
          'cart_summary' => array(
            'weight' => '69',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_suitable_for' => array(
          'cart_summary' => array(
            'weight' => '85',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_current_csa' => array(
          'cart_summary' => array(
            'weight' => '181',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_current_iec' => array(
          'cart_summary' => array(
            'weight' => '186',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_current_ul' => array(
          'cart_summary' => array(
            'weight' => '160',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_voltage_csa' => array(
          'cart_summary' => array(
            'weight' => '165',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_voltage_iec' => array(
          'cart_summary' => array(
            'weight' => '185',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_voltage_rating_21' => array(
          'cart_summary' => array(
            'weight' => '200',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_voltage_rating_se' => array(
          'cart_summary' => array(
            'weight' => '199',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_test_voltage_ul' => array(
          'cart_summary' => array(
            'weight' => '158',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_touchproof' => array(
          'cart_summary' => array(
            'weight' => '152',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_type_accessory' => array(
          'cart_summary' => array(
            'weight' => '74',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_type_fiber' => array(
          'cart_summary' => array(
            'weight' => '35',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_type_tool' => array(
          'cart_summary' => array(
            'weight' => '79',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_uv' => array(
          'cart_summary' => array(
            'weight' => '148',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_vibrations' => array(
          'cart_summary' => array(
            'weight' => '154',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_voltage_iec_v' => array(
          'cart_summary' => array(
            'weight' => '115',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_voltage_ul_v' => array(
          'cart_summary' => array(
            'weight' => '118',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_weight_g' => array(
          'cart_summary' => array(
            'weight' => '155',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_weight_plastics_g' => array(
          'cart_summary' => array(
            'weight' => '157',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_width_mm' => array(
          'cart_summary' => array(
            'weight' => '150',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_wire_acceptance_maxi_a' => array(
          'cart_summary' => array(
            'weight' => '5',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_wire_acceptance_maxi_m' => array(
          'cart_summary' => array(
            'weight' => '103',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_wire_acceptance_mini_a' => array(
          'cart_summary' => array(
            'weight' => '106',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_wire_acceptance_mini_m' => array(
          'cart_summary' => array(
            'weight' => '96',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_with_ground_cavity' => array(
          'cart_summary' => array(
            'weight' => '89',
            'visible' => FALSE,
          ),
        ),
        'product:field_view_exception' => array(
          'cart_summary' => array(
            'weight' => '48',
            'visible' => FALSE,
          ),
        ),
        'product:title_field' => array(
          'cart_summary' => array(
            'weight' => '43',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_3d_model' => array(
          'cart_summary' => array(
            'weight' => '184',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_attachments' => array(
          'cart_summary' => array(
            'weight' => '182',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_images' => array(
          'cart_summary' => array(
            'weight' => '1',
            'visible' => TRUE,
          ),
        ),
        'product:field_sku_recommended_part_num' => array(
          'cart_summary' => array(
            'weight' => '94',
            'visible' => FALSE,
          ),
        ),
        'product:field_sku_number_cavity_13mm' => array(
          'cart_summary' => array(
            'weight' => '123',
            'visible' => FALSE,
          ),
        ),
        'sharethis' => array(
          'cart_summary' => array(
            'weight' => '201',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_product';
  $strongarm->value = '0';
  $export['language_content_type_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_product';
  $strongarm->value = array();
  $export['menu_options_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_product';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_product';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_product';
  $strongarm->value = '1';
  $export['node_preview_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_product';
  $strongarm->value = 0;
  $export['node_submitted_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_ch-ch_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_ch-ch_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_en-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_en-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_en-en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_en-en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_en-gb_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_en-gb_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_en-int_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_en-int_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_en-us_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_en-us_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_en_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_es-sp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_es-sp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_fr-ca_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_fr-ca_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_fr-fr_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_fr-fr_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_it_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_it_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_jp-jp_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_jp-jp_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_lang-copy_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_lang-copy_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_na_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_na_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_pattern';
  $strongarm->value = '[node:souriau_alias]/[node:field-parent-product-range]/[node:title]';
  $export['pathauto_node_product_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_test_code_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_test_code_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_product_und_pattern';
  $strongarm->value = '';
  $export['pathauto_node_product_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publish_button_content_type_product';
  $strongarm->value = 1;
  $export['publish_button_content_type_product'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_node_product';
  $strongarm->value = array(
    'status' => '1',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_node_product'] = $strongarm;

  return $export;
}
