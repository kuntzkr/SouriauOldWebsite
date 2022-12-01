<?php
/**
 * @file
 * souriau_ct_news_landing.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_ct_news_landing_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|news_landing|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_landing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '1',
    'children' => array(
      0 => 'field_description',
      1 => 'title_field',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_general|node|news_landing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|news_landing|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_landing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moderation',
    'weight' => '2',
    'children' => array(
      0 => 'field_draft',
      1 => 'field_edition',
      2 => 'field_log',
      3 => 'field_modification_type',
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
  $field_groups['group_moderation|node|news_landing|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system|node|news_landing|form';
  $field_group->group_name = 'group_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_landing';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System',
    'weight' => '3',
    'children' => array(
      0 => 'domain',
      1 => 'metatags',
      2 => 'path',
      3 => 'redirect',
      4 => 'xmlsitemap',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-system field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_system|node|news_landing|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('General');
  t('Moderation');
  t('System');

  return $field_groups;
}
