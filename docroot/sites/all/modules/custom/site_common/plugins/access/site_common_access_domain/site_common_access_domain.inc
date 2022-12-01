<?php
/**
 * @file
 * Plugin to provide access control/visibility based on domain context.
 */

$plugin = array(
  'title' => t('Site Common: Domain', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'description' => t('Site Common: Domain', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'callback' => 'site_common_access_domain',
  'settings form' => 'site_common_access_domain_settings_form',
  'summary' => 'site_common_access_domain_summary',
  'required context' => new ctools_context_required(t('Checked Domain', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)), 'site_common_context_domain'),
);

/**
 * Settings form for the access plugin.
 */
function site_common_access_domain_settings_form(&$form, &$form_state, $conf) {
  if (!module_exists('domain')) {
    $form['settings']['list'] = array(
      '#markup' => t('Domain module not enabled, match will always fail.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    );
  }
  else {
    $options = qtools_api__array_extract(domain_list_by_machine_name(), 'sitename');
    $form['settings']['list'] = array(
      '#type' => 'select',
      '#title' => t('Domains list', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#options' => $options,
      '#multiple' => TRUE,
    );
  }

  return $form;
}

/**
 * Check for access.
 */
function site_common_access_domain($conf, $context) {
  $access = FALSE;
  $domain_name = $context->argument;
  if (!empty($conf['list']) && in_array($domain_name, $conf['list'])) {
    $access = TRUE;
  }
  return $access;
}

/**
 * Provide a summary description.
 */
function site_common_access_domain_summary($conf, $context) {
  if (!module_exists('domain')) {
    return t('Domain module not enabled, access = FALSE.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
  }
  elseif (!empty($conf['list'])) {
    $names = array();
    $list = domain_list_by_machine_name();
    foreach ($conf['list'] as $domain_name) {
      $names[] = $list[$domain_name]['sitename'];
    }
    return t('@name in (@list) ', array(
      '@name' => $context->identifier,
      '@list' => implode(', ', $names),
    ), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
  }
  else {
    return t('Domain module not enabled, access = FALSE.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
  }
}
