<?php
/**
 * @file
 * souriau_dashboard.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function souriau_dashboard_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-admin-menu.
  $menus['menu-admin-menu'] = array(
    'menu_name' => 'menu-admin-menu',
    'title' => 'Admin Menu',
    'description' => 'Menu on dashboard',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Menu');
  t('Menu on dashboard');

  return $menus;
}
