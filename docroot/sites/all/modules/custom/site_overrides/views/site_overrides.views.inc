<?php

/**
 * @file
 * Define the view field as a part of the commerce line item.
 */

/**
 * Implements hook_views_default_views().
 *
 * Function site_overrides_views_default_views(&$views).
 */
function site_overrides_views_default_views() {
  $view = array();
  $views_path = drupal_get_path('module', 'site_overrides') . '/views/alter';
  $files = file_scan_directory($views_path, '/\.inc$/');

  foreach ($files as $filepath => $file) {
    require_once $filepath;

    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
