<?php
/**
 * @file
 * souriau_entity_project.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_entity_project_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|project|project|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'project';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_project_title',
      1 => 'field_project_description',
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
  $field_groups['group_general|project|project|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_partnumbers|project|project|form';
  $field_group->group_name = 'group_partnumbers';
  $field_group->entity_type = 'project';
  $field_group->bundle = 'project';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Part Numbers',
    'weight' => '1',
    'children' => array(
      0 => 'field_part_numbers',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-partnumbers field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_partnumbers|project|project|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('General');
  t('Part Numbers');

  return $field_groups;
}
