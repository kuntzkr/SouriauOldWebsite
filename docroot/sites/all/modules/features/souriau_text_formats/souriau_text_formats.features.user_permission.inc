<?php
/**
 * @file
 * souriau_text_formats.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function souriau_text_formats_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full'.
  $permissions['use text format full'] = array(
    'name' => 'use text format full',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format simple'.
  $permissions['use text format simple'] = array(
    'name' => 'use text format simple',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'client' => 'client',
      'customer_service' => 'customer_service',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
