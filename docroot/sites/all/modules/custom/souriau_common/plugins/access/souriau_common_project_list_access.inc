<?php
/**
 * @file
 * Plugin to provide user access on Own Project List page.
 */

$plugin = [
  'title' => t('Souriau Common: Access to Own Project List Page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'description' => t('Souriau Eco: Provide user access on own project list page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'callback' => 'souriau_eco_access_own_project_list',
  'summary' => 'souriau_eco_access_own_project_list_summary',
  'required context' => array(
    new ctools_context_required(t('User', [], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'user'),
  ),
];

/**
 * Check for access.
 */
function souriau_eco_access_own_project_list($conf, $context) {
  global $user;

  // Block to anonymous users.
  if (user_is_anonymous()) {
    return FALSE;
  }

  // Grant access by permission.
  if (user_access('bypass_myprojects_access')) {
    return TRUE;
  }

  // Access to project list page.
  if (!empty($context[0]->data) && ($context[0]->data->uid != $user->uid)) {
    // If context-user_id doesn't match with current user_id, access denied.
    return FALSE;
  }

  return TRUE;
}

/**
 * Provide a summary description.
 */
function souriau_eco_access_own_project_list_summary($conf, $context) {
  return t('Grand user access to own project list page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}
