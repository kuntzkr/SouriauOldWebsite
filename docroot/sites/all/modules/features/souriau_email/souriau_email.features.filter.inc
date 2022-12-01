<?php

/**
 * @file
 * souriau_email.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function souriau_email_filter_default_formats() {
  $formats = array();

  // Exported format: Email inline.
  $formats['email_inline'] = array(
    'format' => 'email_inline',
    'name' => 'Email inline',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_emogrifier' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
