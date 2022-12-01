<?php
/**
 * @file
 * souriau_advpoll.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_advpoll_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_query_get_latest_poll';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Query Get Latest Poll';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Souriau Poll Form';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'advpoll' => 'advpoll',
  );
  /* Filter criterion: Content: Close poll (advpoll_closed) */
  $handler->display->display_options['filters']['advpoll_closed_value']['id'] = 'advpoll_closed_value';
  $handler->display->display_options['filters']['advpoll_closed_value']['table'] = 'field_data_advpoll_closed';
  $handler->display->display_options['filters']['advpoll_closed_value']['field'] = 'advpoll_closed_value';
  $handler->display->display_options['filters']['advpoll_closed_value']['value'] = array(
    'open' => 'open',
  );
  /* Filter criterion: Content: Poll availability -  start date (advpoll_dates) */
  $handler->display->display_options['filters']['advpoll_dates_value']['id'] = 'advpoll_dates_value';
  $handler->display->display_options['filters']['advpoll_dates_value']['table'] = 'field_data_advpoll_dates';
  $handler->display->display_options['filters']['advpoll_dates_value']['field'] = 'advpoll_dates_value';
  $handler->display->display_options['filters']['advpoll_dates_value']['operator'] = '<';
  $handler->display->display_options['filters']['advpoll_dates_value']['default_date'] = 'now';
  /* Filter criterion: Content: Poll availability - end date (advpoll_dates:value2) */
  $handler->display->display_options['filters']['advpoll_dates_value2']['id'] = 'advpoll_dates_value2';
  $handler->display->display_options['filters']['advpoll_dates_value2']['table'] = 'field_data_advpoll_dates';
  $handler->display->display_options['filters']['advpoll_dates_value2']['field'] = 'advpoll_dates_value2';
  $handler->display->display_options['filters']['advpoll_dates_value2']['operator'] = '>';
  $handler->display->display_options['filters']['advpoll_dates_value2']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['advpoll_dates_value2']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'souriau-poll-form';
  $translatables['souriau_query_get_latest_poll'] = array(
    t('Master'),
    t('Souriau Poll Form'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Nid'),
    t('Page'),
  );
  $export['souriau_query_get_latest_poll'] = $view;

  return $export;
}
