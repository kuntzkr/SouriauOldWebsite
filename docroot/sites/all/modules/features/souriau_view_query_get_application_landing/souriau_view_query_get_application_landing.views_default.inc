<?php
/**
 * @file
 * souriau_view_query_get_application_landing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_view_query_get_application_landing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_query_get_singularity';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Query Get Singularity';
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
  /* Contextual filter: Content: Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'node';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'not';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    1 => '1',
  );
  $translatables['souriau_query_get_singularity'] = array(
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
  $export['souriau_query_get_singularity'] = $view;

  return $export;
}
