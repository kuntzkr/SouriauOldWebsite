<?php

/**
 * @file
 * souriau_feeds_importer.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function souriau_feeds_importer_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = TRUE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'make unique field_code_p of CT product';
  $rule->name = 'CT_product_field_code_p';
  $rule->field_name = 'field_code_p';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'product';
  $rule->validator = 'field_validation_unique_validator';
  $rule->settings = array(
    'bypass' => 0,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
    'data' => 'global',
    'errors' => 0,
    'per_user' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
    ),
  );
  $rule->error_message = 'Not unique value : [existing-entity-label]';
  $export['CT_product_field_code_p'] = $rule;

  return $export;
}
