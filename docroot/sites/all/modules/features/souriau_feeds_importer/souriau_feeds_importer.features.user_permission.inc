<?php

/**
 * @file
 * souriau_feeds_importer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function souriau_feeds_importer_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'tamper souriau_master_file_product_importer'.
  $permissions['tamper souriau_master_file_product_importer'] = array(
    'name' => 'tamper souriau_master_file_product_importer',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper souriau_master_file_sku_importer'.
  $permissions['tamper souriau_master_file_sku_importer'] = array(
    'name' => 'tamper souriau_master_file_sku_importer',
    'roles' => array(),
    'module' => 'feeds_tamper',
  );

  return $permissions;
}
