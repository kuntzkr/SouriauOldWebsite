<?php
/**
 * @file
 * Plugin to provide user access on Own Project page.
 */

$plugin = [
  'title' => t('Souriau User: Access to Own User Edit Page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'description' => t('Souriau User: Access to Own User Edit Page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'callback' => 'souriau_user_access_own_useredit',
  'summary' => 'souriau_user_access_own_useredit_summary',
  'required context' => array(
    new ctools_context_required(t('User', [], ['context' => SOURIAU_COMMON_T_USER]), 'user'),
  ),
];

/**
 * Check for access.
 */
function souriau_user_access_own_useredit($conf, $context) {
  global $user;

  // Block to anonymous users.
  if (user_is_anonymous()) {
    return FALSE;
  }

  // Grant access by permission.
  if (user_access('administer users')) {
    return TRUE;
  }

  if (!empty($context[0]->data) && ($context[0]->data->uid != $user->uid)) {
    // If context-user_id doesn't match with current user_id, access denied.
    return FALSE;
  }

  return TRUE;
}

/**
 * Provide a summary description.
 */
function souriau_user_access_own_useredit_summary($conf, $context) {
  return t('Grand user access to own user edit page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}
