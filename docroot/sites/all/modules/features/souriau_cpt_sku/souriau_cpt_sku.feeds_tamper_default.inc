<?php
/**
 * @file
 * souriau_cpt_sku.feeds_tamper_default.inc
 */

/**
 * Implements hook_feeds_tamper_default().
 */
function souriau_cpt_sku_feeds_tamper_default() {
  $export = array();

  $feeds_tamper = new stdClass();
  $feeds_tamper->disabled = FALSE; /* Edit this to true to make a default feeds_tamper disabled initially */
  $feeds_tamper->api_version = 2;
  $feeds_tamper->id = 'souriau_master_file_sku_importer-application-explode';
  $feeds_tamper->importer = 'souriau_master_file_sku_importer';
  $feeds_tamper->source = 'application';
  $feeds_tamper->plugin_id = 'explode';
  $feeds_tamper->settings = array(
    'separator' => '|',
    'limit' => '',
    'real_separator' => '|',
  );
  $feeds_tamper->weight = 1;
  $feeds_tamper->description = 'Explode';
  $export['souriau_master_file_sku_importer-application-explode'] = $feeds_tamper;

  return $export;
}
