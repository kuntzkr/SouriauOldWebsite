<?php
/**
 * @file
 * souriau_beginner_guide.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_beginner_guide_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_query_get_application_domains';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Query Get Application Domains';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_application_target_id']['id'] = 'field_application_target_id';
  $handler->display->display_options['relationships']['field_application_target_id']['table'] = 'field_data_field_application';
  $handler->display->display_options['relationships']['field_application_target_id']['field'] = 'field_application_target_id';
  $handler->display->display_options['relationships']['field_application_target_id']['label'] = 'Child Application';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'applicationdomain' => 'applicationdomain',
  );
  /* Filter criterion: Content: Part Number Available (field_part_number_available) */
  $handler->display->display_options['filters']['field_part_number_available_value']['id'] = 'field_part_number_available_value';
  $handler->display->display_options['filters']['field_part_number_available_value']['table'] = 'field_data_field_part_number_available';
  $handler->display->display_options['filters']['field_part_number_available_value']['field'] = 'field_part_number_available_value';
  $handler->display->display_options['filters']['field_part_number_available_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Part Number Available (field_part_number_available) */
  $handler->display->display_options['filters']['field_part_number_available_value_1']['id'] = 'field_part_number_available_value_1';
  $handler->display->display_options['filters']['field_part_number_available_value_1']['table'] = 'field_data_field_part_number_available';
  $handler->display->display_options['filters']['field_part_number_available_value_1']['field'] = 'field_part_number_available_value';
  $handler->display->display_options['filters']['field_part_number_available_value_1']['relationship'] = 'field_application_target_id';
  $handler->display->display_options['filters']['field_part_number_available_value_1']['value'] = array(
    1 => '1',
  );
  $translatables['souriau_query_get_application_domains'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Child Application'),
  );
  $export['souriau_query_get_application_domains'] = $view;

  $view = new view();
  $view->name = 'souriau_query_get_application_per_domain';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Query Get Application per Domain';
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
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_application_target_id']['id'] = 'field_application_target_id';
  $handler->display->display_options['relationships']['field_application_target_id']['table'] = 'field_data_field_application';
  $handler->display->display_options['relationships']['field_application_target_id']['field'] = 'field_application_target_id';
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
  $handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_1']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field_1']['relationship'] = 'field_application_target_id';
  $handler->display->display_options['fields']['title_field_1']['label'] = '';
  $handler->display->display_options['fields']['title_field_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field_1']['link_to_entity'] = 0;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_application_target_id';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Field: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_application_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'field_application_target_id';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );
  /* Filter criterion: Content: Part Number Available (field_part_number_available) */
  $handler->display->display_options['filters']['field_part_number_available_value']['id'] = 'field_part_number_available_value';
  $handler->display->display_options['filters']['field_part_number_available_value']['table'] = 'field_data_field_part_number_available';
  $handler->display->display_options['filters']['field_part_number_available_value']['field'] = 'field_part_number_available_value';
  $handler->display->display_options['filters']['field_part_number_available_value']['relationship'] = 'field_application_target_id';
  $handler->display->display_options['filters']['field_part_number_available_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_part_number_available_value']['expose']['operator_id'] = 'field_part_number_available_value_op';
  $handler->display->display_options['filters']['field_part_number_available_value']['expose']['label'] = 'Part Number Available (field_part_number_available)';
  $handler->display->display_options['filters']['field_part_number_available_value']['expose']['operator'] = 'field_part_number_available_value_op';
  $handler->display->display_options['filters']['field_part_number_available_value']['expose']['identifier'] = 'field_part_number_available_value';
  $translatables['souriau_query_get_application_per_domain'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_application'),
    t('All'),
    t('Part Number Available (field_part_number_available)'),
  );
  $export['souriau_query_get_application_per_domain'] = $view;

  return $export;
}
