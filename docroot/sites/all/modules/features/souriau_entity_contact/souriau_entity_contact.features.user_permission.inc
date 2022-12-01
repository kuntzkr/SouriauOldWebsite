<?php
/**
 * @file
 * souriau_entity_contact.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function souriau_entity_contact_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add contact bundles'.
  $permissions['eck add contact bundles'] = array(
    'name' => 'eck add contact bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add contact contact entities'.
  $permissions['eck add contact contact entities'] = array(
    'name' => 'eck add contact contact entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer contact bundles'.
  $permissions['eck administer contact bundles'] = array(
    'name' => 'eck administer contact bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer contact contact entities'.
  $permissions['eck administer contact contact entities'] = array(
    'name' => 'eck administer contact contact entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete contact bundles'.
  $permissions['eck delete contact bundles'] = array(
    'name' => 'eck delete contact bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete contact contact entities'.
  $permissions['eck delete contact contact entities'] = array(
    'name' => 'eck delete contact contact entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit contact bundles'.
  $permissions['eck edit contact bundles'] = array(
    'name' => 'eck edit contact bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit contact contact entities'.
  $permissions['eck edit contact contact entities'] = array(
    'name' => 'eck edit contact contact entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list contact bundles'.
  $permissions['eck list contact bundles'] = array(
    'name' => 'eck list contact bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list contact contact entities'.
  $permissions['eck list contact contact entities'] = array(
    'name' => 'eck list contact contact entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view contact bundles'.
  $permissions['eck view contact bundles'] = array(
    'name' => 'eck view contact bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view contact contact entities'.
  $permissions['eck view contact contact entities'] = array(
    'name' => 'eck view contact contact entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage contact properties'.
  $permissions['manage contact properties'] = array(
    'name' => 'manage contact properties',
    'roles' => array(),
    'module' => 'eck',
  );

  return $permissions;
}
