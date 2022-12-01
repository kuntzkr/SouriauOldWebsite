<?php
/**
 * @file
 * souriau_ct_capability.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_ct_capability_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|capability|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'capability';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
      1 => 'field_image',
      2 => 'field_downloads',
      3 => 'field_our_solution',
      4 => 'field_paragraphs',
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
  $field_groups['group_general|node|capability|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|capability|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'capability';
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
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-moderation field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_moderation|node|capability|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news|node|capability|form';
  $field_group->group_name = 'group_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'capability';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'News',
    'weight' => '3',
    'children' => array(
      0 => 'field_tags',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-news field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_news|node|capability|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preview|node|capability|form';
  $field_group->group_name = 'group_preview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'capability';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preview',
    'weight' => '1',
    'children' => array(
      0 => 'field_catchline',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-preview field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_preview|node|capability|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_ranges|node|capability|form';
  $field_group->group_name = 'group_product_ranges';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'capability';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Ranges',
    'weight' => '2',
    'children' => array(
      0 => 'field_product_range',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-product-ranges field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_product_ranges|node|capability|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system|node|capability|form';
  $field_group->group_name = 'group_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'capability';
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
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-system field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_system|node|capability|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('General');
  t('Moderation');
  t('News');
  t('Preview');
  t('Product Ranges');
  t('System');

  return $field_groups;
}
