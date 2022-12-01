<?php
/**
 * @file
 * souriau_homepage.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function souriau_homepage_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Slider description max words';
  $rule->name = 'slider_description_max_words';
  $rule->field_name = 'field_slide_description';
  $rule->col = 'value';
  $rule->entity_type = 'paragraphs_item';
  $rule->bundle = 'homepage_slides';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '110',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      10 => 0,
      11 => 0,
      14 => 0,
      12 => 0,
      13 => 0,
      8 => 0,
      3 => 0,
      5 => 0,
      4 => 0,
      7 => 0,
      9 => 0,
    ),
    'errors' => 1,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'The maximum length of slider description is 110 characters.';
  $export['slider_description_max_words'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Slider title length';
  $rule->name = 'slider_title_length';
  $rule->field_name = 'field_slide_title';
  $rule->col = 'value';
  $rule->entity_type = 'paragraphs_item';
  $rule->bundle = 'homepage_slides';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '45',
    'bypass' => 0,
    'roles' => array(
      1 => 0,
      2 => 0,
      10 => 0,
      11 => 0,
      14 => 0,
      12 => 0,
      13 => 0,
      8 => 0,
      3 => 0,
      5 => 0,
      4 => 0,
      7 => 0,
      9 => 0,
    ),
    'errors' => 1,
    'condition' => 0,
    'condition_wrapper' => array(
      'condition_field' => '',
      'condition_operator' => 'equals',
      'condition_value' => '',
    ),
  );
  $rule->error_message = 'Slider title length should not exceed 45 characters.';
  $export['slider_title_length'] = $rule;

  return $export;
}
