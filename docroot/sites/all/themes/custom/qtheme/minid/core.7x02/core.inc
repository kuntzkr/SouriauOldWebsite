<?php
/**
 * @file
 * MiniD core compatible with Drupal 7x.
 *
 * version 7x-02.
 */

// ==================================== Drupals JS of supported modules.
$GLOBALS['drupal_js']['jquery'] = ['file' => minid_path('root', 'misc/jquery.js')];
$GLOBALS['drupal_js']['jquery.once'] = ['file' => minid_path('root', 'misc/jquery.once.js')];
$GLOBALS['drupal_js']['drupal'] = ['file' => minid_path('root', 'misc/drupal.js')];
$GLOBALS['drupal_js']['ajax'] = ['file' => minid_path('root', 'misc/ajax.js')];

// Module: Qtools.
$GLOBALS['drupal_js']['qtools.base'] = ['file' => minid_path('root', 'sites/all/modules/custom/qtools/js/qtools.base.js')];
$GLOBALS['drupal_js']['qtools.ajax'] = ['file' => minid_path('root', 'sites/all/modules/custom/qtools/js/qtools.ajax.js'), 'requires' => array('ajax')];

// Core js.
$GLOBALS['drupal_js']['core.jquerysign'] = ['file' => minid_path('core', 'core.jquerysign.js')];

define('REPLACEMENT_HASH', 'MINIFYHTML' . md5($_SERVER['REQUEST_TIME']));

// Page types.
define('MINID_MENU_CALLBACK', 'callback');
define('MINID_MENU_PANEL', 'panel');
define('MINID_MENU_AJAX', 'ajax');

// Special value for menu returned page.
define('MINID_BLOCK_PAGE_CONTENT', '__MINID_BLOCK_PAGE_CONTENT__');
define('MINID_BLOCK_ENTITY_VIEW', '__MINID_BLOCK_ENTITY_VIEW__');

// Load debugger.
require_once minid_path('core', 'krumo/class.krumo.php');

// Load dev's files.
require_once minid_path('theme', 'minid.theme.inc');
require_once minid_path('theme', 'minid.module.inc');

// Load core base.
require_once minid_path('core', 'core.base.inc');

// Load drupal API.
require_once minid_path('core', 'core.api.' . minid_config('version_api') . '.inc');

// Load slicer's files.
require_once 'slice_config.inc';
require_once 'slice_preprocess.inc';
require_once 'slice_menu.inc';
