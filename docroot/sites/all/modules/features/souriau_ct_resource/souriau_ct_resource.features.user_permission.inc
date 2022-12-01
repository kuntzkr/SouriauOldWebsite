<?php
/**
 * @file
 * souriau_ct_resource.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function souriau_ct_resource_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'flag favourate_resource'.
  $permissions['flag favourate_resource'] = array(
    'name' => 'flag favourate_resource',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag favourate_resource'.
  $permissions['unflag favourate_resource'] = array(
    'name' => 'unflag favourate_resource',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
