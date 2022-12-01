<?php
/**
 * @file
 * souriau_entity_distributor.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function souriau_entity_distributor_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-admin-menu_distributors:admin/dashboard/distributors.
  $menu_links['menu-admin-menu_distributors:admin/dashboard/distributors'] = array(
    'menu_name' => 'menu-admin-menu',
    'link_path' => 'admin/dashboard/distributors',
    'router_path' => 'admin/dashboard/distributors',
    'link_title' => 'Distributors',
    'options' => array(
      'identifier' => 'menu-admin-menu_distributors:admin/dashboard/distributors',
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
  t('Distributors');

  return $menu_links;
}
