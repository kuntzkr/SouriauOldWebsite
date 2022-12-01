<?php
/**
 * @file
 * souriau_ct_resource.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_ct_resource_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|resource|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_video',
      1 => 'field_catchline_text',
      2 => 'field_description',
      3 => 'field_resource_type',
      4 => 'field_resource_category',
      5 => 'field_resource_image',
      6 => 'title_field',
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
  $field_groups['group_general|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|resource|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moderation',
    'weight' => '4',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_draft',
      2 => 'field_log',
      3 => 'field_modification_type',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Moderation',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-moderation field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_moderation|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_registration|node|resource|form';
  $field_group->group_name = 'group_registration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Registration',
    'weight' => '3',
    'children' => array(
      0 => 'field_registration_webform',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-registration field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_registration|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|resource|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '1',
    'children' => array(
      0 => 'field_related_resource',
      1 => 'field_product_range',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_content|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system|node|resource|form';
  $field_group->group_name = 'group_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System',
    'weight' => '5',
    'children' => array(
      0 => 'domain',
      1 => 'metatags',
      2 => 'path',
      3 => 'xmlsitemap',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'System',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-system field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_system|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_visibility|node|resource|form';
  $field_group->group_name = 'group_visibility';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Visibility',
    'weight' => '2',
    'children' => array(
      0 => 'field_resource_private',
      1 => 'field_resouce_landing',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-visibility field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_visibility|node|resource|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('General');
  t('Moderation');
  t('Registration');
  t('Related content');
  t('System');
  t('Visibility');

  return $field_groups;
}
