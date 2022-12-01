<?php
/**
 * @file
 * Plugin to provide user access on Own Project page.
 */

$plugin = [
  'title' => t('Souriau Common: Access to Own Project Page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'description' => t('Souriau Eco: Provide user access on own project page', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
  'callback' => 'souriau_eco_access_own_project',
  'summary' => 'souriau_eco_access_own_project_summary',
  'required context' => array(
    new ctools_context_required(t('Entity', [], ['context' => SOURIAU_COMMON_T_ADMIN]), 'project'),
  ),
];

/**
 * Check for access.
 */
function souriau_eco_access_own_project($conf, $context) {
  global $user;

  // Block to anonymous users.
  if (user_is_anonymous()) {
    return FALSE;
  }

  // Grant access by permission.
  if (user_access('bypass_myprojects_access')) {
    return TRUE;
  }

  // Access to Single project page.
  if ($context[0] && $context[0]->data) {
    $project_id = $context[0]->data->id;
    $project = entity_load_single('project', $project_id);
    $langcode = entity_language($project->type, $project);
    $wrapper = entity_metadata_wrapper($project->type, $project)->language($langcode);
    $entity_user = $wrapper->uid->value();
    if ($entity_user->uid == $user->uid) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Provide a summary description.
 */
function souriau_eco_access_own_project_summary($conf, $context) {
  return t('Grand user access to own project page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}
