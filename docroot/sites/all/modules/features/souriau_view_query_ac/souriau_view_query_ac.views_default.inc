<?php
/**
 * @file
 * souriau_view_query_ac.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_view_query_ac_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_view_queries_ac';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau View Queries AC';
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
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'productrange' => 'productrange',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    0 => '0',
  );

  /* Display: Category */
  $handler = $view->new_display('entityreference', 'Category', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'category' => 'category',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Product Range */
  $handler = $view->new_display('entityreference', 'Product Range', 'entityreference_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_pr_code_p' => 'field_pr_code_p',
    'title' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Product Range Code P */
  $handler->display->display_options['fields']['field_pr_code_p']['id'] = 'field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['table'] = 'field_data_field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['field'] = 'field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['label'] = '';
  $handler->display->display_options['fields']['field_pr_code_p']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pr_code_p']['alter']['text'] = '[title] ([field_pr_code_p])';
  $handler->display->display_options['fields']['field_pr_code_p']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'productrange' => 'productrange',
    'productrangehub' => 'productrangehub',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Product Range - with Code & Title */
  $handler = $view->new_display('entityreference', 'Product Range - with Code & Title', 'entityreference_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_pr_code_p' => 'field_pr_code_p',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Product Range Code P */
  $handler->display->display_options['fields']['field_pr_code_p']['id'] = 'field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['table'] = 'field_data_field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['field'] = 'field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['label'] = '';
  $handler->display->display_options['fields']['field_pr_code_p']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_pr_code_p']['alter']['text'] = '([field_pr_code_p])';
  $handler->display->display_options['fields']['field_pr_code_p']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'productrange' => 'productrange',
    'productrangehub' => 'productrangehub',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Sub-Category */
  $handler = $view->new_display('entityreference', 'Sub-Category', 'entityreference_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'subcategory' => 'subcategory',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Application domain */
  $handler = $view->new_display('entityreference', 'Application domain', 'entityreference_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'applicationdomain' => 'applicationdomain',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Application */
  $handler = $view->new_display('entityreference', 'Application', 'entityreference_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Capability Domain */
  $handler = $view->new_display('entityreference', 'Capability Domain', 'entityreference_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'capabilitydomain' => 'capabilitydomain',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Capability */
  $handler = $view->new_display('entityreference', 'Capability', 'entityreference_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'capability' => 'capability',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: tool */
  $handler = $view->new_display('entityreference', 'tool', 'entityreference_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'tool' => 'tool',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Part Number */
  $handler = $view->new_display('entityreference', 'Part Number', 'entityreference_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Resource */
  $handler = $view->new_display('entityreference', 'Resource', 'entityreference_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Webform */
  $handler = $view->new_display('entityreference', 'Webform', 'entityreference_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'webform' => 'webform',
  );
  /* Filter criterion: Content: Webform type (field_webform_type) */
  $handler->display->display_options['filters']['field_webform_type_value']['id'] = 'field_webform_type_value';
  $handler->display->display_options['filters']['field_webform_type_value']['table'] = 'field_data_field_webform_type';
  $handler->display->display_options['filters']['field_webform_type_value']['field'] = 'field_webform_type_value';
  $handler->display->display_options['filters']['field_webform_type_value']['value'] = array(
    'registration_webform' => 'registration_webform',
  );

  /* Display: Product Range Hub */
  $handler = $view->new_display('entityreference', 'Product Range Hub', 'entityreference_13');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'field_pr_code_p' => 'field_pr_code_p',
    'title' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Product Range Code P */
  $handler->display->display_options['fields']['field_pr_code_p']['id'] = 'field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['table'] = 'field_data_field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['field'] = 'field_pr_code_p';
  $handler->display->display_options['fields']['field_pr_code_p']['label'] = '';
  $handler->display->display_options['fields']['field_pr_code_p']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'productrangehub' => 'productrangehub',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Capability Domain & Capability */
  $handler = $view->new_display('entityreference', 'Capability Domain & Capability', 'entityreference_14');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'capability' => 'capability',
    'capabilitydomain' => 'capabilitydomain',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: news */
  $handler = $view->new_display('entityreference', 'news', 'news');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'news' => 'news',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );

  /* Display: Application domain & Application */
  $handler = $view->new_display('entityreference', 'Application domain & Application', 'entityreference_15');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
    'applicationdomain' => 'applicationdomain',
  );
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );
  $translatables['souriau_view_queries_ac'] = array(
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
    t('Category'),
    t('Product Range'),
    t('Title'),
    t('[title] ([field_pr_code_p])'),
    t('Product Range - with Code & Title'),
    t('([field_pr_code_p])'),
    t('Sub-Category'),
    t('Application domain'),
    t('Application'),
    t('Capability Domain'),
    t('Capability'),
    t('tool'),
    t('Part Number'),
    t('Resource'),
    t('Webform'),
    t('Product Range Hub'),
    t('Capability Domain & Capability'),
    t('news'),
    t('Application domain & Application'),
  );
  $export['souriau_view_queries_ac'] = $view;

  return $export;
}
