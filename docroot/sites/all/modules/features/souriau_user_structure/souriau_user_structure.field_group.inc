<?php

/**
 * @file
 * souriau_user_structure.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_user_structure_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email|user|user|form';
  $field_group->group_name = 'group_email';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'LOGIN AND PASSWORD:',
    'weight' => '3',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'LOGIN AND PASSWORD:',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_email|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inline_checkboxes|user|user|form';
  $field_group->group_name = 'group_inline_checkboxes';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inline-checkboxes',
    'weight' => '7',
    'children' => array(
      0 => 'field_allow_usage_of_data',
      1 => 'field_subscribe_newsletter',
      2 => 'field_receive_sms_notifications',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Inline-checkboxes',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'inline-checkboxes',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_inline_checkboxes|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_data|user|user|form';
  $field_group->group_name = 'group_personal_data';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'YOUR INFOS:',
    'weight' => '4',
    'children' => array(
      0 => 'field_postal_address',
      1 => 'field_first_name',
      2 => 'field_last_name',
      3 => 'field_customer_type',
      4 => 'field_mouser_responsible_countri',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'YOUR INFOS:',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_personal_data|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preferences|user|user|form';
  $field_group->group_name = 'group_preferences';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preferences',
    'weight' => '6',
    'children' => array(
      0 => 'field_preference_application',
      1 => 'field_preference_sub_category',
      2 => 'field_preference_product_range',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Preferences',
      'instance_settings' => array(
        'required_fields' => 0,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_preferences|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user_order_history|user|user|form';
  $field_group->group_name = 'group_user_order_history';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Order history',
    'weight' => '12',
    'children' => array(
      0 => 'field_order_history_access_st',
      1 => 'field_ect_customer_id_requested',
      2 => 'field_ect_customer_numbers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-user-order-history field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_user_order_history|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Inline-checkboxes');
  t('LOGIN AND PASSWORD:');
  t('Order history');
  t('Preferences');
  t('YOUR INFOS:');

  return $field_groups;
}
