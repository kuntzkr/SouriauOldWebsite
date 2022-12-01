<?php
/**
 * @file
 * souriau_ct_product.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_ct_product_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advices|node|product|form';
  $field_group->group_name = 'group_advices';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advices',
    'weight' => '1',
    'children' => array(
      0 => 'field_advices',
      1 => 'field_advices_description',
      2 => 'field_advices_image',
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
  $field_groups['group_advices|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cross_sell|node|product|form';
  $field_group->group_name = 'group_cross_sell';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cross sell',
    'weight' => '4',
    'children' => array(
      0 => 'field_complementary_part_number',
      1 => 'field_pn_replacement',
      2 => 'field_recommendation',
      3 => 'field_legacy_data',
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
  $field_groups['group_cross_sell|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|product|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'field_sku_products',
      1 => 'field_parent_product_range',
      2 => 'field_sticky',
      3 => 'title',
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
  $field_groups['group_general|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|product|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moderation',
    'weight' => '2',
    'children' => array(
      0 => 'field_edition',
      1 => 'field_draft',
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
  $field_groups['group_moderation|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system|node|product|form';
  $field_group->group_name = 'group_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System',
    'weight' => '3',
    'children' => array(
      0 => 'domain',
      1 => 'metatags',
      2 => 'path',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'System',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_system|node|product|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advices');
  t('Cross sell');
  t('General');
  t('Moderation');
  t('System');

  return $field_groups;
}
