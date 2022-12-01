<?php
/**
 * @file
 * souriau_secure_pages.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_secure_pages_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_code';
  $strongarm->value = '301';
  $export['securepages_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_debug';
  $strongarm->value = 0;
  $export['securepages_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_enable';
  $strongarm->value = '1';
  $export['securepages_enable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_forms';
  $strongarm->value = 'user_login
user_login_block';
  $export['securepages_forms'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_ignore';
  $strongarm->value = '*/ajax/*
*/autocomplete/*
batch*
batch/*
sites/default/files/advagg_css/*
sites/default/files/advagg_js/*';
  $export['securepages_ignore'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_pages';
  $strongarm->value = 'user
user/*
checkout
checkout/*';
  $export['securepages_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_roles';
  $strongarm->value = array(
    2 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
  );
  $export['securepages_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_secure';
  $strongarm->value = '1';
  $export['securepages_secure'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'securepages_switch';
  $strongarm->value = TRUE;
  $export['securepages_switch'] = $strongarm;

  return $export;
}
