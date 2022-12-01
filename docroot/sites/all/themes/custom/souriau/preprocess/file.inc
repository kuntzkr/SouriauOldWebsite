<?php
/**
 * @file
 * Preprocess commerce_product.
 */

/**
 * Implements hook_preprocess_ENTITY__BUNDLE__VIEW_MODE().
 */
function souriau_preprocess_file__document__download_center(&$variables) {
  _souriau_preprocess_files_download_center($variables);
}

/**
 * Implements hook_preprocess_ENTITY__BUNDLE__VIEW_MODE().
 */
function souriau_preprocess_file__3d_model__download_center(&$variables) {
  _souriau_preprocess_files_download_center($variables);
}

/**
 * Implements hook_preprocess_ENTITY__BUNDLE__VIEW_MODE().
 */
function souriau_preprocess_file__ipaper__download_center(&$variables) {
  _souriau_preprocess_files_download_center($variables);
}

/**
 * Helper function for preprocess files of Download center.
 */
function _souriau_preprocess_files_download_center(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $_data = _souriau_common_get_file_values__download_block($variables['file']);
}
