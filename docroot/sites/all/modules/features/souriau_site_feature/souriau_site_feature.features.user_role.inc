<?php
/**
 * @file
 * souriau_site_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function souriau_site_feature_user_default_roles() {
  $roles = array();

  // Exported role: Webmaster.
  $roles['Webmaster'] = array(
    'name' => 'Webmaster',
    'weight' => 3,
  );

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: application_contributor.
  $roles['application_contributor'] = array(
    'name' => 'application_contributor',
    'weight' => 6,
  );

  // Exported role: capability_contributor.
  $roles['capability_contributor'] = array(
    'name' => 'capability_contributor',
    'weight' => 7,
  );

  // Exported role: client.
  $roles['client'] = array(
    'name' => 'client',
    'weight' => 13,
  );

  // Exported role: customer_service.
  $roles['customer_service'] = array(
    'name' => 'customer_service',
    'weight' => 12,
  );

  // Exported role: delete_data.
  $roles['delete_data'] = array(
    'name' => 'delete_data',
    'weight' => 17,
  );

  // Exported role: global_contributor.
  $roles['global_contributor'] = array(
    'name' => 'global_contributor',
    'weight' => 15,
  );

  // Exported role: global_publisher.
  $roles['global_publisher'] = array(
    'name' => 'global_publisher',
    'weight' => 16,
  );

  // Exported role: home_page_update.
  $roles['home_page_update'] = array(
    'name' => 'home_page_update',
    'weight' => 18,
  );

  // Exported role: product_contributor.
  $roles['product_contributor'] = array(
    'name' => 'product_contributor',
    'weight' => 5,
  );

  // Exported role: product_suggessions_editor.
  $roles['product_suggessions_editor'] = array(
    'name' => 'product_suggessions_editor',
    'weight' => 19,
  );

  // Exported role: resource_contributor.
  $roles['resource_contributor'] = array(
    'name' => 'resource_contributor',
    'weight' => 10,
  );

  // Exported role: resource_manager.
  $roles['resource_manager'] = array(
    'name' => 'resource_manager',
    'weight' => 11,
  );

  // Exported role: trade_compliance.
  $roles['trade_compliance'] = array(
    'name' => 'trade_compliance',
    'weight' => 8,
  );

  // Exported role: сatalog_manager.
  $roles['сatalog_manager'] = array(
    'name' => 'сatalog_manager',
    'weight' => 9,
  );

  return $roles;
}
