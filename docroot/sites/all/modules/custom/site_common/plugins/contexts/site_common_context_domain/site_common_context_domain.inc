<?php
/**
 * @file
 * Context for current domain.
 *
 */

$plugin = array(
  'title' => t('Site Common: Current Domain', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'description' => t('Site Common: Current Domain', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'context name' => 'site_common_context_domain',
  'context' => 'site_common_context_domain_create',
  'keyword' => 'site_common_context_domain',
);

/**
 * Create a context.
 */
function site_common_context_domain_create($empty, $data = NULL, $conf = FALSE) {
  global $_domain;
  $context = new ctools_context('site_common_context_domain');
  $context->plugin = 'site_common_context_domain';
  if (!empty($_domain)) {
    $context->data = $_domain;
    $context->argument = $_domain['machine_name'];
  }
  else {
    $context->data = array();
  }
  return $context;
}
