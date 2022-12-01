<?php
/**
 * @file
 * souriau_my_projects.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_my_projects_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_project_csv';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_project';
  $view->human_name = 'Souriau Project CSV';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Souriau Project CSV';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    2 => '2',
    9 => '9',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Project: Part numbers (field_part_numbers) */
  $handler->display->display_options['relationships']['field_part_numbers_value']['id'] = 'field_part_numbers_value';
  $handler->display->display_options['relationships']['field_part_numbers_value']['table'] = 'field_data_field_part_numbers';
  $handler->display->display_options['relationships']['field_part_numbers_value']['field'] = 'field_part_numbers_value';
  $handler->display->display_options['relationships']['field_part_numbers_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_part_numbers_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_part_number_target_id']['id'] = 'field_part_number_target_id';
  $handler->display->display_options['relationships']['field_part_number_target_id']['table'] = 'field_data_field_part_number';
  $handler->display->display_options['relationships']['field_part_number_target_id']['field'] = 'field_part_number_target_id';
  $handler->display->display_options['relationships']['field_part_number_target_id']['relationship'] = 'field_part_numbers_value';
  $handler->display->display_options['relationships']['field_part_number_target_id']['required'] = TRUE;
  /* Field: Paragraphs item: Part number */
  $handler->display->display_options['fields']['field_part_number']['id'] = 'field_part_number';
  $handler->display->display_options['fields']['field_part_number']['table'] = 'field_data_field_part_number';
  $handler->display->display_options['fields']['field_part_number']['field'] = 'field_part_number';
  $handler->display->display_options['fields']['field_part_number']['relationship'] = 'field_part_numbers_value';
  $handler->display->display_options['fields']['field_part_number']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Part Number */
  $handler->display->display_options['fields']['field_sku_products_1']['id'] = 'field_sku_products_1';
  $handler->display->display_options['fields']['field_sku_products_1']['table'] = 'field_data_field_sku_products';
  $handler->display->display_options['fields']['field_sku_products_1']['field'] = 'field_sku_products';
  $handler->display->display_options['fields']['field_sku_products_1']['relationship'] = 'field_part_number_target_id';
  $handler->display->display_options['fields']['field_sku_products_1']['label'] = 'SKU';
  $handler->display->display_options['fields']['field_sku_products_1']['type'] = 'commerce_product_reference_sku_plain';
  $handler->display->display_options['fields']['field_sku_products_1']['settings'] = array(
    'show_quantity' => 0,
    'default_quantity' => '1',
    'combine' => 1,
    'show_single_product_attributes' => 0,
    'line_item_type' => 'product',
  );
  /* Field: Paragraphs item: Notes */
  $handler->display->display_options['fields']['field_notes']['id'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['table'] = 'field_data_field_notes';
  $handler->display->display_options['fields']['field_notes']['field'] = 'field_notes';
  $handler->display->display_options['fields']['field_notes']['relationship'] = 'field_part_numbers_value';
  /* Contextual filter: Project: Id */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'eck_project';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Project: project type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_project';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'csv_export');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'project.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'user/projects/%/csv';
  $translatables['souriau_project_csv'] = array(
    t('Master'),
    t('Souriau Project CSV'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Paragraph item from field_part_numbers'),
    t('Content entity referenced from field_part_number'),
    t('Part number'),
    t('SKU'),
    t('Notes'),
    t('All'),
    t('Data export'),
  );
  $export['souriau_project_csv'] = $view;

  $view = new view();
  $view->name = 'souriau_query_user_project_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_project';
  $view->human_name = 'Souriau Query User Project List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Project: Part numbers (field_part_numbers) */
  $handler->display->display_options['relationships']['field_part_numbers_value']['id'] = 'field_part_numbers_value';
  $handler->display->display_options['relationships']['field_part_numbers_value']['table'] = 'field_data_field_part_numbers';
  $handler->display->display_options['relationships']['field_part_numbers_value']['field'] = 'field_part_numbers_value';
  $handler->display->display_options['relationships']['field_part_numbers_value']['delta'] = '-1';
  /* Field: Project: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_project';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  /* Sort criterion: Project: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_project';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Project: Author */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'eck_project';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Paragraphs item: Part number (field_part_number) */
  $handler->display->display_options['arguments']['field_part_number_target_id']['id'] = 'field_part_number_target_id';
  $handler->display->display_options['arguments']['field_part_number_target_id']['table'] = 'field_data_field_part_number';
  $handler->display->display_options['arguments']['field_part_number_target_id']['field'] = 'field_part_number_target_id';
  $handler->display->display_options['arguments']['field_part_number_target_id']['relationship'] = 'field_part_numbers_value';
  $handler->display->display_options['arguments']['field_part_number_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_part_number_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_part_number_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_part_number_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Project: project type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_project';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  $translatables['souriau_query_user_project_list'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Paragraph item from field_part_numbers'),
    t('Id'),
    t('.'),
    t(','),
    t('Title'),
    t('All'),
  );
  $export['souriau_query_user_project_list'] = $view;

  $view = new view();
  $view->name = 'userzone_my_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_project';
  $view->human_name = 'Userzone My Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Messages */
  $handler->display->display_options['empty']['messages']['id'] = 'messages';
  $handler->display->display_options['empty']['messages']['table'] = 'views';
  $handler->display->display_options['empty']['messages']['field'] = 'messages';
  /* Relationship: Project: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_project';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Relationship: Project: Part numbers (field_part_numbers) */
  $handler->display->display_options['relationships']['field_part_numbers_value']['id'] = 'field_part_numbers_value';
  $handler->display->display_options['relationships']['field_part_numbers_value']['table'] = 'field_data_field_part_numbers';
  $handler->display->display_options['relationships']['field_part_numbers_value']['field'] = 'field_part_numbers_value';
  $handler->display->display_options['relationships']['field_part_numbers_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_part_number_target_id']['id'] = 'field_part_number_target_id';
  $handler->display->display_options['relationships']['field_part_number_target_id']['table'] = 'field_data_field_part_number';
  $handler->display->display_options['relationships']['field_part_number_target_id']['field'] = 'field_part_number_target_id';
  $handler->display->display_options['relationships']['field_part_number_target_id']['relationship'] = 'field_part_numbers_value';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = '';
  $handler->display->display_options['fields']['field_project_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_title']['element_default_classes'] = FALSE;
  /* Field: Project: Description */
  $handler->display->display_options['fields']['field_project_description']['id'] = 'field_project_description';
  $handler->display->display_options['fields']['field_project_description']['table'] = 'field_data_field_project_description';
  $handler->display->display_options['fields']['field_project_description']['field'] = 'field_project_description';
  $handler->display->display_options['fields']['field_project_description']['label'] = '';
  $handler->display->display_options['fields']['field_project_description']['element_type'] = '0';
  $handler->display->display_options['fields']['field_project_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_project_description']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_project_description']['element_default_classes'] = FALSE;
  /* Field: COUNT(Paragraphs item: Paragraphs item ID) */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'paragraphs_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_part_numbers_value';
  $handler->display->display_options['fields']['item_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['item_id']['label'] = '';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  /* Field: MIN(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_part_number_target_id';
  $handler->display->display_options['fields']['nid']['group_type'] = 'min';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Project: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_project';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Sort criterion: Project: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_project';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['null']['validate']['type'] = 'user';
  $handler->display->display_options['arguments']['null']['validate']['fail'] = 'ignore';
  $translatables['userzone_my_projects'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('User'),
    t('Paragraph item from field_part_numbers'),
    t('Content entity referenced from field_part_number'),
    t('.'),
    t(','),
    t('All'),
  );
  $export['userzone_my_projects'] = $view;

  return $export;
}
