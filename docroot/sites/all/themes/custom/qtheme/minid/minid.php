<?php
/**
 * @file
 * Minid index file.
 */

require_once 'settings.php';
require_once minid_path('core', 'core.inc');

/**
 * t() shadow.
 */
function _t($text) {
  return $text;
}

/**
 * Wrapper to get globals.
 */
function minid_config($name) {
  $callback = 'minid_config_' . $name;
  if (function_exists($callback)) {
    return $callback();
  }
  elseif (isset($GLOBALS[$name])) {
    return $GLOBALS[$name];
  }
}

/**
 * Get path to given resource.
 */
function minid_path($type, $path) {
  global $path_root, $path_theme, $path_qtheme;
  if ($type == 'root') {
    $path = $path_root . '/' . $path;
  }
  elseif ($type == 'theme') {
    $path = $path_theme . '/' . $path;
  }
  elseif ($type == 'core') {
    $path = $path_qtheme . '/minid/core.' . minid_config('version_core') . '/' . $path;
  }

  return $path;
}

/**
 * Include all inc files in directory.
 */
function minid_include_directory($directory) {
  if (!empty($directory)) {
    $files = scandir($directory);
    foreach ($files as $file) {
      if (strpos($file, '.inc') > 0) {
        require_once $directory . '/' . $file;
      }
    }
  }
}

// Invoke page processing.
minid_start();
