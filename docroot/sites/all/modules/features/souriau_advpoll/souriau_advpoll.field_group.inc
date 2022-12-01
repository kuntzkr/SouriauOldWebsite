<?php
/**
 * @file
 * souriau_advpoll.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_advpoll_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_default_poll_settings|node|advpoll|form';
  $field_group->group_name = 'group_default_poll_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'advpoll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Default Poll Settings',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'advpoll_max_choices',
      2 => 'advpoll_options',
      3 => 'advpoll_mode',
      4 => 'advpoll_cookie_duration',
      5 => 'advpoll_results',
      6 => 'advpoll_behavior',
      7 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-default-poll-settings field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_default_poll_settings|node|advpoll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|advpoll|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'advpoll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '1',
    'children' => array(
      0 => 'advpoll_choice',
      1 => 'advpoll_dates',
      2 => 'advpoll_closed',
      3 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-general field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_general|node|advpoll|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|advpoll|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'advpoll';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moderation',
    'weight' => '3',
    'children' => array(
      0 => 'field_draft',
      1 => 'field_edition',
      2 => 'field_log',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-moderation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_moderation|node|advpoll|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Default Poll Settings');
  t('General');
  t('Moderation');

  return $field_groups;
}
