<?php

/**
 * @file
 * souriau_feeds_importer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_feeds_importer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'feeds_process_limit';
  $strongarm->value = 150;
  $export['feeds_process_limit'] = $strongarm;

  return $export;
}
