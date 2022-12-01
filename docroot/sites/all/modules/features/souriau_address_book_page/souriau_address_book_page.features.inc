<?php
/**
 * @file
 * souriau_address_book_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_address_book_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
