<?php
/**
 * @file
 * souriau_cache_control.default_elysia_cron_rules.inc
 */

/**
 * Implements hook_default_elysia_cron_rules().
 */
function souriau_cache_control_default_elysia_cron_rules() {
  $cron_rules = array();

  $cron_rule = new stdClass;
  $cron_rule->disabled = FALSE; /* Edit this to true to make a default cron_rule disabled initially */
  $cron_rule->api_version = 1;
  $cron_rule->name = 'cache_control_cron';
  $cron_rule->disable = NULL;
  $cron_rule->rule = NULL;
  $cron_rule->weight = NULL;
  $cron_rule->context = NULL;
  $cron_rules['cache_control_cron'] = $cron_rule;

  return $cron_rules;

}
