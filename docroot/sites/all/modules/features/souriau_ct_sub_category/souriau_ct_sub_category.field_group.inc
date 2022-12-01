<?php
/**
 * @file
 * souriau_ct_sub_category.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_ct_sub_category_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cross_sell|node|subcategory|form';
  $field_group->group_name = 'group_cross_sell';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subcategory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cross sell',
    'weight' => '1',
    'children' => array(
      0 => 'field_cross_sell_product_range',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cross-sell field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cross_sell|node|subcategory|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_extra|node|subcategory|form';
  $field_group->group_name = 'group_extra';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subcategory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Extra',
    'weight' => '2',
    'children' => array(
      0 => 'field_in_grouping',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-extra field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_extra|node|subcategory|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|subcategory|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subcategory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_description',
      1 => 'field_image',
      2 => 'field_product_range',
      3 => 'title_field',
      4 => 'field_downloads',
      5 => 'field_part_number_available',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'General',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_general|node|subcategory|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|subcategory|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subcategory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moderation',
    'weight' => '5',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_draft',
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
  $field_groups['group_moderation|node|subcategory|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system|node|subcategory|form';
  $field_group->group_name = 'group_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subcategory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System',
    'weight' => '4',
    'children' => array(
      0 => 'domain',
      1 => 'metatags',
      2 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_system|node|subcategory|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Cross sell');
  t('Extra');
  t('General');
  t('Moderation');
  t('System');

  return $field_groups;
}
