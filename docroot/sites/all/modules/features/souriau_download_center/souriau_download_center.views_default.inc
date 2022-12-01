<?php
/**
 * @file
 * souriau_download_center.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_download_center_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_download_center';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_download_center_index';
  $view->human_name = 'Souriau download center';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Souriau download center';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view files';
  $handler->display->display_options['cache']['type'] = 'search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'b-product-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'download_center';
  /* Field: Indexed File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  /* Sort criterion: Indexed File: Souriau: Dc document type weight for sorting */
  $handler->display->display_options['sorts']['dc_dtype_weight']['id'] = 'dc_dtype_weight';
  $handler->display->display_options['sorts']['dc_dtype_weight']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['sorts']['dc_dtype_weight']['field'] = 'dc_dtype_weight';
  /* Sort criterion: Indexed File: Souriau: Sort weight */
  $handler->display->display_options['sorts']['dc_weight']['id'] = 'dc_weight';
  $handler->display->display_options['sorts']['dc_weight']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['sorts']['dc_weight']['field'] = 'dc_weight';
  /* Sort criterion: Indexed File: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Indexed File: Souriau: Reference Product Range Nid */
  $handler->display->display_options['arguments']['dc_reference_productrange']['id'] = 'dc_reference_productrange';
  $handler->display->display_options['arguments']['dc_reference_productrange']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['arguments']['dc_reference_productrange']['field'] = 'dc_reference_productrange';
  $handler->display->display_options['arguments']['dc_reference_productrange']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dc_reference_productrange']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dc_reference_productrange']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['dc_reference_productrange']['not'] = 0;
  /* Contextual filter: Indexed File: Brand */
  $handler->display->display_options['arguments']['field_brand']['id'] = 'field_brand';
  $handler->display->display_options['arguments']['field_brand']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['arguments']['field_brand']['field'] = 'field_brand';
  $handler->display->display_options['arguments']['field_brand']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_brand']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_brand']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_brand']['not'] = 0;
  /* Contextual filter: Indexed File: Souriau: Reference Application Nid */
  $handler->display->display_options['arguments']['dc_reference_application']['id'] = 'dc_reference_application';
  $handler->display->display_options['arguments']['dc_reference_application']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['arguments']['dc_reference_application']['field'] = 'dc_reference_application';
  $handler->display->display_options['arguments']['dc_reference_application']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dc_reference_application']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dc_reference_application']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['dc_reference_application']['not'] = 0;
  /* Contextual filter: Indexed File: Souriau: Reference Capability Nid */
  $handler->display->display_options['arguments']['dc_reference_capability']['id'] = 'dc_reference_capability';
  $handler->display->display_options['arguments']['dc_reference_capability']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['arguments']['dc_reference_capability']['field'] = 'dc_reference_capability';
  $handler->display->display_options['arguments']['dc_reference_capability']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['dc_reference_capability']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['dc_reference_capability']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['dc_reference_capability']['not'] = 0;
  /* Contextual filter: Indexed File: Language */
  $handler->display->display_options['arguments']['field_document_language']['id'] = 'field_document_language';
  $handler->display->display_options['arguments']['field_document_language']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['arguments']['field_document_language']['field'] = 'field_document_language';
  $handler->display->display_options['arguments']['field_document_language']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_document_language']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_document_language']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_document_language']['not'] = 0;
  /* Contextual filter: Indexed File: Document type */
  $handler->display->display_options['arguments']['field_document_type']['id'] = 'field_document_type';
  $handler->display->display_options['arguments']['field_document_type']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['arguments']['field_document_type']['field'] = 'field_document_type';
  $handler->display->display_options['arguments']['field_document_type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_document_type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_document_type']['break_phrase'] = 1;
  $handler->display->display_options['arguments']['field_document_type']['not'] = 0;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  /* Filter criterion: Indexed File: File name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['group'] = 1;
  /* Filter criterion: Indexed File: Souriau: Title for text search */
  $handler->display->display_options['filters']['dc_title']['id'] = 'dc_title';
  $handler->display->display_options['filters']['dc_title']['table'] = 'search_api_index_download_center_index';
  $handler->display->display_options['filters']['dc_title']['field'] = 'dc_title';
  $handler->display->display_options['filters']['dc_title']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['souriau_download_center'] = array(
    t('Master'),
    t('Souriau download center'),
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
    t('File ID'),
    t('.'),
    t(','),
    t('All'),
    t('Block'),
  );
  $export['souriau_download_center'] = $view;

  $view = new view();
  $view->name = 'souriau_query_get_productrange_by_series_code';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau query get ProductRange by series code';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'tid' => 'tid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'tid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Product Series (field_product_series) */
  $handler->display->display_options['relationships']['field_product_series_tid']['id'] = 'field_product_series_tid';
  $handler->display->display_options['relationships']['field_product_series_tid']['table'] = 'field_data_field_product_series';
  $handler->display->display_options['relationships']['field_product_series_tid']['field'] = 'field_product_series_tid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['relationship'] = 'field_product_series_tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Content: Product Series (field_product_series) */
  $handler->display->display_options['arguments']['field_product_series_tid']['id'] = 'field_product_series_tid';
  $handler->display->display_options['arguments']['field_product_series_tid']['table'] = 'field_data_field_product_series';
  $handler->display->display_options['arguments']['field_product_series_tid']['field'] = 'field_product_series_tid';
  $handler->display->display_options['arguments']['field_product_series_tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['field_product_series_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_product_series_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_product_series_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_series_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_product_series_tid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'productrange' => 'productrange',
    'productrangehub' => 'productrangehub',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $translatables['souriau_query_get_productrange_by_series_code'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('term from field_product_series'),
    t('.'),
    t(','),
    t('All'),
  );
  $export['souriau_query_get_productrange_by_series_code'] = $view;

  return $export;
}
