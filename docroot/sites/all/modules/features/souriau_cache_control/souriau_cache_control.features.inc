<?php
/**
 * @file
 * souriau_cache_control.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_cache_control_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
