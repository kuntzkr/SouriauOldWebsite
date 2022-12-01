<?php
/**
 * @file
 * souriau_view_query_pathauto.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_view_query_pathauto_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'get_category_from_productrange_hub';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Query Get Category From Productrange hub';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: PR hub (field_cross_sell_pr_hub) */
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['id'] = 'field_cross_sell_pr_hub_target_id';
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['table'] = 'field_data_field_cross_sell_pr_hub';
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['field'] = 'field_cross_sell_pr_hub_target_id';
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_cross_sell_pr_hub_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'category' => 'category',
  );
  $translatables['get_category_from_productrange_hub'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Nid'),
    t('All'),
  );
  $export['get_category_from_productrange_hub'] = $view;

  $view = new view();
  $view->name = 'get_catogory_from_subcategory';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Query Get Catogory From Subcategory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Beginner Guide Subcategory (field_subcategory) */
  $handler->display->display_options['arguments']['field_subcategory_target_id']['id'] = 'field_subcategory_target_id';
  $handler->display->display_options['arguments']['field_subcategory_target_id']['table'] = 'field_data_field_subcategory';
  $handler->display->display_options['arguments']['field_subcategory_target_id']['field'] = 'field_subcategory_target_id';
  $handler->display->display_options['arguments']['field_subcategory_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_subcategory_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_subcategory_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_subcategory_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_subcategory_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'category' => 'category',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $translatables['get_catogory_from_subcategory'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Nid'),
    t('All'),
  );
  $export['get_catogory_from_subcategory'] = $view;

  $view = new view();
  $view->name = 'get_subcategory_from_productrange';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Query Get Subcategory From Productrange';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Product Range (field_product_range) */
  $handler->display->display_options['arguments']['field_product_range_target_id']['id'] = 'field_product_range_target_id';
  $handler->display->display_options['arguments']['field_product_range_target_id']['table'] = 'field_data_field_product_range';
  $handler->display->display_options['arguments']['field_product_range_target_id']['field'] = 'field_product_range_target_id';
  $handler->display->display_options['arguments']['field_product_range_target_id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_product_range_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_product_range_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_product_range_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_range_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'subcategory' => 'subcategory',
  );
  $translatables['get_subcategory_from_productrange'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Nid'),
    t('All'),
  );
  $export['get_subcategory_from_productrange'] = $view;

  return $export;
}
