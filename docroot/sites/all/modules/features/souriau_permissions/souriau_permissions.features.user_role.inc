<?php

/**
 * @file
 * souriau_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function souriau_permissions_user_default_roles() {
  $roles = array();

  // Exported role: news_tags_manager.
  $roles['news_tags_manager'] = array(
    'name' => 'news_tags_manager',
    'weight' => 20,
  );

  // Exported role: sample_manager.
  $roles['sample_manager'] = array(
    'name' => 'sample_manager',
    'weight' => 14,
  );

  return $roles;
}
