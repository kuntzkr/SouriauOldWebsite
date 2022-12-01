<?php
/**
 * @file
 * souriau_homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function souriau_homepage_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_beginner_guides|node|homepage|form';
  $field_group->group_name = 'group_beginner_guides';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Beginner guides',
    'weight' => '1',
    'children' => array(
      0 => 'field_beginner_guide',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-beginner-guides field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_beginner_guides|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|homepage|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '2',
    'children' => array(
      0 => 'field_categories_description',
      1 => 'field_hot_categories',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-categories field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_categories|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_color|paragraphs_item|homepage_slides|form';
  $field_group->group_name = 'group_color';
  $field_group->entity_type = 'paragraphs_item';
  $field_group->bundle = 'homepage_slides';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Color',
    'weight' => '7',
    'children' => array(
      0 => 'field_slide_bg_color',
      1 => 'field_slide_cta_bg_color',
      2 => 'field_slide_cta_font_color',
      3 => 'field_slide_font_color',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Color',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-color field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_color|paragraphs_item|homepage_slides|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|homepage|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
      1 => 'field_ect_description',
      2 => 'field_ect_image',
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
  $field_groups['group_general|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_get_started_banner|node|homepage|form';
  $field_group->group_name = 'group_get_started_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Get Started banner',
    'weight' => '4',
    'children' => array(
      0 => 'field_banner_title',
      1 => 'field_banner_description',
      2 => 'field_cta_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-get-started-banner field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_get_started_banner|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moderation|node|homepage|form';
  $field_group->group_name = 'group_moderation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
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
  $field_groups['group_moderation|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news|node|homepage|form';
  $field_group->group_name = 'group_news';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'News and events',
    'weight' => '5',
    'children' => array(
      0 => 'field_news',
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
  $field_groups['group_news|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promoted_tools|node|homepage|form';
  $field_group->group_name = 'group_promoted_tools';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promoted Tools',
    'weight' => '6',
    'children' => array(
      0 => 'field_promoted_tools',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promoted-tools field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promoted_tools|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_promo|node|homepage|form';
  $field_group->group_name = 'group_promo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promotion messages',
    'weight' => '2',
    'children' => array(
      0 => 'field_promotion_messages',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promo field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_promo|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slider|node|homepage|form';
  $field_group->group_name = 'group_slider';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Slider',
    'weight' => '1',
    'children' => array(
      0 => 'field_slides',
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
  $field_groups['group_slider|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_system|node|homepage|form';
  $field_group->group_name = 'group_system';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'System',
    'weight' => '8',
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
  $field_groups['group_system|node|homepage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_top_products|node|homepage|form';
  $field_group->group_name = 'group_top_products';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Top products',
    'weight' => '3',
    'children' => array(
      0 => 'field_products',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-top-products field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_top_products|node|homepage|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Beginner guides');
  t('Categories');
  t('Color');
  t('General');
  t('Get Started banner');
  t('Moderation');
  t('News and events');
  t('Promoted Tools');
  t('Promotion messages');
  t('Slider');
  t('System');
  t('Top products');

  return $field_groups;
}
