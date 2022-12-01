<?php
/**
 * @file
 * souriau_entity_advice.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_entity_advice_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|advice|advice|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'advice';
  $field_group->bundle = 'advice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_advice_description',
      1 => 'field_advice_title',
      2 => 'title',
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
  $field_groups['group_general|advice|advice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media|advice|advice|form';
  $field_group->group_name = 'group_media';
  $field_group->entity_type = 'advice';
  $field_group->bundle = 'advice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Media',
    'weight' => '1',
    'children' => array(
      0 => 'field_advice_image',
      1 => 'field_advice_video',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_media|advice|advice|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('General');
  t('Media');

  return $field_groups;
}
