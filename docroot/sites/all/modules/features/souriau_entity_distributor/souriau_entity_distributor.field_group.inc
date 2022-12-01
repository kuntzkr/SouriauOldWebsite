<?php

/**
 * @file
 * souriau_entity_distributor.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_entity_distributor_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|distributor|distributor|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'distributor';
  $field_group->bundle = 'distributor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_distributor_code',
      1 => 'field_distributor_name',
      2 => 'field_email',
      3 => 'field_postal_address',
      4 => 'field_url',
      5 => 'field_type',
      6 => 'field_distributor_brand',
      7 => 'field_contact_person',
      8 => 'field_vad_series',
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
  $field_groups['group_general|distributor|distributor|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_links|distributor|distributor|form';
  $field_group->group_name = 'group_links';
  $field_group->entity_type = 'distributor';
  $field_group->bundle = 'distributor';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Links',
    'weight' => '1',
    'children' => array(
      0 => 'field_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-links field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_links|distributor|distributor|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('General');
  t('Links');

  return $field_groups;
}
