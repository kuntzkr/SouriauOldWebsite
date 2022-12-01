<?php
/**
 * @file
 * souriau_user_zone.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_user_zone_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
