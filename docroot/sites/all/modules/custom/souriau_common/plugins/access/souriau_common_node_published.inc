<?php
/**
 * @file
 * Plugin to provide access control/visibility based on domain context.
 */

$plugin = array(
  'title' => t('Souriau Common: Published on current Domain', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'description' => t('Souriau Common: Published on current Domain', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'callback' => 'souriau_common_access_published',
  'settings form' => 'souriau_common_access_published_settings_form',
  'summary' => 'souriau_common_access_published_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Settings form for the access plugin.
 */
function souriau_common_access_published_settings_form(&$form, &$form_state, $conf) {
  if (!module_exists('domain')) {
    $form['settings']['list'] = array(
      '#markup' => t('Domain module not enabled, match will always fail.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    );
  }

  return $form;
}

/**
 * Check for access.
 */
function souriau_common_access_published($conf, $context) {
  if (!module_exists('domain')) {
    return FALSE;
  }
  return souriau_common_availible_on_domain($context->data);
}

/**
 * Provide a summary description.
 */
function souriau_common_access_published_summary($conf, $context) {
  if (!module_exists('domain')) {
    return t('Domain module not enabled, access = FALSE.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
  }
  return t('Returns true if published on current Domain.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
}
