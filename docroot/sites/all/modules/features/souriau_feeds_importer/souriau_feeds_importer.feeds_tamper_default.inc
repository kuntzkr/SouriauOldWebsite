<?php

/**
 * @file
 * souriau_feeds_importer.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function souriau_feeds_importer_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_product_importer-complementary_part_number-explode';
  $feeds_tamper->importer = 'souriau_master_file_product_importer';
  $feeds_tamper->source = 'complementary_part_number';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_product_importer-complementary_part_number-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_product_importer-complementary_pn-explode';
  $feeds_tamper->importer = 'souriau_master_file_product_importer';
  $feeds_tamper->source = 'complementary_pn';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_product_importer-complementary_pn-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_product_importer-legacy_data-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_product_importer';
  $feeds_tamper->source = 'legacy_data';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'false',
    'no_match_value' => FALSE,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_product_importer-legacy_data-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_product_importer-suggestion-explode';
  $feeds_tamper->importer = 'souriau_master_file_product_importer';
  $feeds_tamper->source = 'suggestion';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_product_importer-suggestion-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-3d_model-explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = '3d_model';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-3d_model-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-alternate_search_keywords-explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'alternate_search_keywords';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-alternate_search_keywords-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-application-application_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'application';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-application-application_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-application-explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'application';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-application-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-aviation-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Aviation';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-aviation-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-avionics-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Avionics';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-avionics-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-backshell_delivery-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Backshell Delivery';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-backshell_delivery-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-color_stripes_marking-convert_boolean_color_stripes_ma';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'color_stripes_marking';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-color_stripes_marking-convert_boolean_color_stripes_ma'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-commercial_marine-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Commercial Marine';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-commercial_marine-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-complementary_pn-complementary_pn_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'complementary_pn';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-complementary_pn-complementary_pn_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-contact_compatibility-explode_contact_compatibility';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'contact_compatibility';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-contact_compatibility-explode_contact_compatibility'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-current_breaking_capability-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Current Breaking Capability';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-current_breaking_capability-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-current_breaking_capability-convert_boolean_current_breaking';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'current_breaking_capability';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-current_breaking_capability-convert_boolean_current_breaking'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-defense-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Defense';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-defense-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-energy-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Energy';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-energy-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-engines__wing___landing_gear-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Engines, Wing & Landing Gear';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-engines__wing___landing_gear-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-entertainment___broadcast-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Entertainment & Broadcast';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-entertainment___broadcast-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-environment-explode_environment';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'environment';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-environment-explode_environment'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-function-explode_function';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'function';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-function-explode_function'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-ground_army-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Ground Army';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-ground_army-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-halogen_free-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'halogen_free';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-halogen_free-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-images-images_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'images';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Images Explode';
  $export['souriau_master_file_sku_importer-images-images_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-in-flight_entertainment___cabin_systems-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'In-Flight Entertainment & Cabin Systems';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-in-flight_entertainment___cabin_systems-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-infrastructure-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Infrastructure';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-infrastructure-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-instrumentation___measurement-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Instrumentation & Measurement';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-instrumentation___measurement-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-insulation_grip-convert_boolean_insulation_grip';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'insulation_grip';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-insulation_grip-convert_boolean_insulation_grip'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-legacy_data-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'legacy_data';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-legacy_data-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-lighting___building-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Lighting & Building';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-lighting___building-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-machinery___robotics-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Machinery & Robotics';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-machinery___robotics-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-marine-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Marine';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-marine-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-mating_connector-explode_mating_connector';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'mating_connector';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-mating_connector-explode_mating_connector'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-medical-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Medical';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-medical-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-military_aircraft-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Military Aircraft';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-military_aircraft-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-military_marine-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Military Marine';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-military_marine-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-mining-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Mining';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-mining-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-missiles___weapons-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Missiles & Weapons';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-missiles___weapons-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-motorsport-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Motorsport';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-motorsport-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-nuclear-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Nuclear';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-nuclear-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-off-road-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Off-Road';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-off-road-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-oil___gas-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Oil & Gas';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-oil___gas-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-pdf-pdf_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'pdf';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'PDF Explode';
  $export['souriau_master_file_sku_importer-pdf-pdf_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-portable_energy-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Portable Energy';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-portable_energy-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-power_distribution-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Power Distribution';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-power_distribution-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-product_series-product_series_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'product_series';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-product_series-product_series_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-railway-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Railway';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-railway-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-renewable_energy-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Renewable Energy';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-renewable_energy-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-sample_all-convert_boolean_sample_all';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'sample_all';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-sample_all-convert_boolean_sample_all'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-sample_exception-explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'sample_exception';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ',',
    'separator' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-sample_exception-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-sample_exception-sample_exception_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'sample_exception';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-sample_exception-sample_exception_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-samples_apac-find_replace';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Samples_APAC';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'Yes',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => 'APAC',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 2;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-samples_apac-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-samples_apac-find_replace_no';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Samples_APAC';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'No',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-samples_apac-find_replace_no'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-samples_eu-find_replace';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Samples_EU';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'Yes',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => 'EU',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-samples_eu-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-samples_eu-find_replace_no';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Samples_EU';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'No',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-samples_eu-find_replace_no'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-samples_us-find_replace';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Samples_US';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'Yes',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => 'US',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-samples_us-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-samples_us-find_replace_no';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Samples_US';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'No',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-samples_us-find_replace_no'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-shielding-convert_boolean_shielding';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'shielding';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-shielding-convert_boolean_shielding'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-standard-explode_standard';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'standard';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-standard-explode_standard'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-status-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'status';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'false',
    'no_match_value' => FALSE,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-status-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-suggestion-suggestion_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'suggestion';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-suggestion-suggestion_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-telecom___datacom-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Telecom & Datacom';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-telecom___datacom-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-traffic_equipment-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Traffic Equipment';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-traffic_equipment-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-unmanned_vehicules-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Unmanned Vehicules';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-unmanned_vehicules-convert_boolean'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_all-convert_boolean_view_all';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'view_all';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => '0',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => '1',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-view_all-convert_boolean_view_all'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_apac-find_replace';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'View_APAC';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'Yes',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => 'APAC',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 4;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-view_apac-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_apac-find_replace_no';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'View_APAC';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'No',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 3;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-view_apac-find_replace_no'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_eu-find_replace';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'View_EU';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'Yes',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => 'EU',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-view_eu-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_eu-find_replace_no';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'View_EU';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'No',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-view_eu-find_replace_no'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_exception-explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'view_exception';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => ',',
    'separator' => ',',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-view_exception-explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_exception-view_exception_explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'view_exception';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'limit' => '',
    'real_separator' => '|',
    'separator' => '|',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-view_exception-view_exception_explode'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_us-find_replace';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'View_US';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'Yes',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => 'US',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-view_us-find_replace'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-view_us-find_replace_no';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'View_US';
  $feeds_tamper->plugin_id = 'find_replace';
  $feeds_tamper->settings = array(
    'case_sensitive' => 0,
    'find' => 'No',
    'func' => 'str_ireplace',
    'regex' => FALSE,
    'replace' => '',
    'whole' => 0,
    'word_boundaries' => 0,
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Find replace';
  $export['souriau_master_file_sku_importer-view_us-find_replace_no'] = $feeds_tamper;

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = TRUE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-wiring_interconnect_systems-convert_boolean';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'Wiring Interconnect Systems';
  $feeds_tamper->plugin_id = 'convert_boolean';
  $feeds_tamper->settings = array(
    'false_value' => 'no',
    'match_case' => 0,
    'no_match' => 'null',
    'no_match_value' => NULL,
    'other_text' => '',
    'true_value' => 'yes',
  );
  $feeds_tamper->weight = 0;
  $feeds_tamper->description = 'Convert to boolean';
  $export['souriau_master_file_sku_importer-wiring_interconnect_systems-convert_boolean'] = $feeds_tamper;

  return $export;
}
