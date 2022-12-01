<?php
/**
 * @file
 * souriau_entity_advice.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_entity_advice_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dashboard_advices';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_advice';
  $view->human_name = 'Dashboard Advices';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dashboard Advices';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    11 => '11',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_advice_title' => 'field_advice_title',
    'field_advice_video' => 'field_advice_video',
    'edit_link' => 'edit_link',
    'delete_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_advice_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_advice_video' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '&ensp;',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Advice: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_advice';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Advice: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_advice';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Advice: Video */
  $handler->display->display_options['fields']['field_advice_video']['id'] = 'field_advice_video';
  $handler->display->display_options['fields']['field_advice_video']['table'] = 'field_data_field_advice_video';
  $handler->display->display_options['fields']['field_advice_video']['field'] = 'field_advice_video';
  $handler->display->display_options['fields']['field_advice_video']['click_sort_column'] = 'input';
  $handler->display->display_options['fields']['field_advice_video']['type'] = 'youtube_thumbnail';
  $handler->display->display_options['fields']['field_advice_video']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Advice: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_advice';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Operations';
  /* Field: Advice: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_advice';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['text'] = 'delete';
  /* Filter criterion: Advice: advice type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_advice';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advice' => 'advice',
  );
  /* Filter criterion: Advice: Id */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'eck_advice';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['label'] = 'Id';
  $handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['identifier'] = 'id';
  $handler->display->display_options['filters']['id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Advice: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_advice';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/dashboard/advices';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Advices';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['dashboard_advices'] = array(
    t('Master'),
    t('Dashboard Advices'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Id'),
    t('.'),
    t(','),
    t('Title'),
    t('Video'),
    t('Operations'),
    t('Delete link'),
    t('delete'),
    t('Page'),
  );
  $export['dashboard_advices'] = $view;

  $view = new view();
  $view->name = 'souriau_query_get_advices';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_advice';
  $view->human_name = 'Souriau Query Get Advices';
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
  /* Field: Advice: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_advice';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Filter criterion: Advice: advice type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_advice';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advice' => 'advice',
  );

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
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
  $translatables['souriau_query_get_advices'] = array(
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
    t('Entity Reference'),
  );
  $export['souriau_query_get_advices'] = $view;

  return $export;
}
