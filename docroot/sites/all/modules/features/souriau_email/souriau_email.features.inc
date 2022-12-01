<?php

/**
 * @file
 * souriau_email.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_email_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
