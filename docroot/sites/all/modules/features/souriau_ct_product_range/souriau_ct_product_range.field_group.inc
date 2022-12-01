<?php
/**
 * @file
 * souriau_ct_product_range.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_ct_product_range_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_application|node|productrange|form';
  $field_group->group_name = 'group_application';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Application',
    'weight' => '2',
    'children' => array(
      0 => 'field_application_catchline',
      1 => 'field_paragraph_aplication',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-application field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_application|node|productrange|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cross_sell|node|productrange|form';
  $field_group->group_name = 'group_cross_sell';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cross sell',
    'weight' => '4',
    'children' => array(
      0 => 'field_complementary_product_rang',
      1 => 'field_similar_product_ranges',
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
  $field_groups['group_cross_sell|node|productrange|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_default_pn_values|node|productrange|form';
  $field_group->group_name = 'group_default_pn_values';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Default PN Values',
    'weight' => '5',
    'children' => array(
      0 => 'field_pn_advices',
      1 => 'field_pn_advices_description',
      2 => 'field_pn_advices_image',
      3 => 'field_pn_description',
      4 => 'field_pn_key_features',
      5 => 'field_pn_catalog',
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
  $field_groups['group_default_pn_values|node|productrange|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|productrange|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '1',
    'children' => array(
      0 => 'field_image',
      1 => 'field_key_features',
      2 => 'title_field',
      3 => 'field_product_series',
      4 => 'field_paragraphs',
      5 => 'field_downloads',
      6 => 'field_part_number_available',
      7 => 'field_pr_code_p',
      8 => 'field_tool',
      9 => 'field_do_not_index_in_solr',
      10 => 'field_search_keywords',
      11 => 'field_second_level_title',
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
  $field_groups['group_general|node|productrange|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|productrange|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moderation',
    'weight' => '7',
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
  $field_groups['group_moderation|node|productrange|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news|node|productrange|form';
  $field_group->group_name = 'group_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
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
  $field_groups['group_news|node|productrange|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preview|node|productrange|form';
  $field_group->group_name = 'group_preview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preview',
    'weight' => '6',
    'children' => array(
      0 => 'field_key_words',
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
  $field_groups['group_preview|node|productrange|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system|node|productrange|form';
  $field_group->group_name = 'group_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'productrange';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System',
    'weight' => '8',
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
  $field_groups['group_system|node|productrange|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Application');
  t('Cross sell');
  t('Default PN Values');
  t('General');
  t('Moderation');
  t('News');
  t('Preview');
  t('System');

  return $field_groups;
}
