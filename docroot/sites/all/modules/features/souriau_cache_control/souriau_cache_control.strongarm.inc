<?php
/**
 * @file
 * souriau_cache_control.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function souriau_cache_control_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_control_dev_mode';
  $strongarm->value = 0;
  $export['cache_control_dev_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_control_enabled';
  $strongarm->value = 1;
  $export['cache_control_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_control_enable_for_admin_user';
  $strongarm->value = 0;
  $export['cache_control_enable_for_admin_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_control_expires';
  $strongarm->value = '360';
  $export['cache_control_expires'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_control_no_cache_content_types';
  $strongarm->value = array(
    'advpoll' => 0,
    'application' => 0,
    'applicationdomain' => 0,
    'applicationlanding' => 0,
    'capabilitieslanding' => 0,
    'capability' => 0,
    'capabilitydomain' => 0,
    'category' => 0,
    'cms_page' => 0,
    'faq' => 0,
    'genericlanding' => 0,
    'homepage' => 0,
    'news' => 0,
    'news_landing' => 0,
    'product' => 0,
    'productlanding' => 0,
    'productrange' => 0,
    'productrangehub' => 0,
    'resource' => 0,
    'subcategory' => 0,
    'tool' => 0,
    'toolkitlanding' => 0,
    'webform' => 0,
  );
  $export['cache_control_no_cache_content_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_control_roles';
  $strongarm->value = array(
    0 => 2,
    1 => 10,
    2 => 11,
    3 => 14,
    4 => 12,
    5 => 13,
    6 => 8,
    7 => 3,
    8 => 5,
    9 => 4,
    10 => 7,
    11 => 9,
  );
  $export['cache_control_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cache_control_storage_class';
  $strongarm->value = 'CacheControlSQLStorage';
  $export['cache_control_storage_class'] = $strongarm;

  return $export;
}
