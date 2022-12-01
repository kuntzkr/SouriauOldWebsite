<?php
/**
 * @file
 * souriau_dashboard.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function souriau_dashboard_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-admin-menu_all:admin/dashboard.
  $menu_links['menu-admin-menu_all:admin/dashboard'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard',
    'router_path' => 'admin/dashboard',
    'link_title' => 'All',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu_all:admin/dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admin-menu_all:admin/dashboard/all.
  $menu_links['menu-admin-menu_all:admin/dashboard/all'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard/all',
    'router_path' => 'admin/dashboard/all',
    'link_title' => 'All',
    'options' => array(
      'identifier' => 'menu-admin-menu_all:admin/dashboard/all',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-admin-menu_all:admin/dashboard',
  );
  // Exported menu link: menu-admin-menu_import-log:admin/reports/feeds.
  $menu_links['menu-admin-menu_import-log:admin/reports/feeds'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/reports/feeds',
    'router_path' => 'admin/reports/feeds',
    'link_title' => 'Import log',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu_import-log:admin/reports/feeds',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 25,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-admin-menu_import:admin/dashboard/import',
  );
  // Exported menu link: menu-admin-menu_import:admin/dashboard/import.
  $menu_links['menu-admin-menu_import:admin/dashboard/import'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard/import',
    'router_path' => 'admin/dashboard/import',
    'link_title' => 'Import',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu_import:admin/dashboard/import',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admin-menu_my-content:admin/dashboard/my-content.
  $menu_links['menu-admin-menu_my-content:admin/dashboard/my-content'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard/my-content',
    'router_path' => 'admin/dashboard/my-content',
    'link_title' => 'My Content',
    'options' => array(
      'identifier' => 'menu-admin-menu_my-content:admin/dashboard/my-content',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-admin-menu_all:admin/dashboard',
  );
  // Exported menu link: menu-admin-menu_poll:admin/dashboard/souriau-poll.
  $menu_links['menu-admin-menu_poll:admin/dashboard/souriau-poll'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard/souriau-poll',
    'router_path' => 'admin/dashboard/souriau-poll',
    'link_title' => 'Poll',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu_poll:admin/dashboard/souriau-poll',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admin-menu_products-list:admin/dashboard/products.
  $menu_links['menu-admin-menu_products-list:admin/dashboard/products'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard/products',
    'router_path' => 'admin/dashboard/products',
    'link_title' => 'Products List',
    'options' => array(
      'identifier' => 'menu-admin-menu_products-list:admin/dashboard/products',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
    'parent_identifier' => 'menu-admin-menu_products:admin/dashboard/products',
  );
  // Exported menu link: menu-admin-menu_products:admin/dashboard/products.
  $menu_links['menu-admin-menu_products:admin/dashboard/products'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard/products',
    'router_path' => 'admin/dashboard/products',
    'link_title' => 'Products',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-admin-menu_products:admin/dashboard/products',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-admin-menu_site-menu:admin/souriau/souriau_main_menu.
  $menu_links['menu-admin-menu_site-menu:admin/souriau/souriau_main_menu'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/souriau/souriau_main_menu',
    'router_path' => 'admin/souriau/souriau_main_menu',
    'link_title' => 'Site Menu',
    'options' => array(
      'identifier' => 'menu-admin-menu_site-menu:admin/souriau/souriau_main_menu',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('All');
  t('Import');
  t('Import log');
  t('My Content');
  t('Poll');
  t('Products');
  t('Products List');
  t('Site Menu');

  return $menu_links;
}
