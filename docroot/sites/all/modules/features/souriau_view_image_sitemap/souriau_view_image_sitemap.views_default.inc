<?php
/**
 * @file
 * souriau_view_image_sitemap.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_view_image_sitemap_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_google_imagemap';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Google Imagemap';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_sku_products_product_id']['id'] = 'field_sku_products_product_id';
  $handler->display->display_options['relationships']['field_sku_products_product_id']['table'] = 'field_data_field_sku_products';
  $handler->display->display_options['relationships']['field_sku_products_product_id']['field'] = 'field_sku_products_product_id';
  $handler->display->display_options['relationships']['field_sku_products_product_id']['required'] = TRUE;
  /* Relationship: Commerce Product: Images (field_sku_images:fid) */
  $handler->display->display_options['relationships']['field_sku_images_fid']['id'] = 'field_sku_images_fid';
  $handler->display->display_options['relationships']['field_sku_images_fid']['table'] = 'field_data_field_sku_images';
  $handler->display->display_options['relationships']['field_sku_images_fid']['field'] = 'field_sku_images_fid';
  $handler->display->display_options['relationships']['field_sku_images_fid']['relationship'] = 'field_sku_products_product_id';
  $handler->display->display_options['relationships']['field_sku_images_fid']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_product_range_target_id']['id'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['relationships']['field_parent_product_range_target_id']['table'] = 'field_data_field_parent_product_range';
  $handler->display->display_options['relationships']['field_parent_product_range_target_id']['field'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['relationships']['field_parent_product_range_target_id']['required'] = TRUE;
  /* Relationship: Field: Image (field_image:fid) */
  $handler->display->display_options['relationships']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['relationships']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['relationship'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['relationships']['field_image_fid']['required'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['relationship'] = 'field_sku_images_fid';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_sku_images_fid';
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid_1']['id'] = 'fid_1';
  $handler->display->display_options['fields']['fid_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid_1']['field'] = 'fid';
  $handler->display->display_options['fields']['fid_1']['relationship'] = 'field_image_fid';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri_1']['id'] = 'uri_1';
  $handler->display->display_options['fields']['uri_1']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri_1']['field'] = 'uri';
  $handler->display->display_options['fields']['uri_1']['relationship'] = 'field_image_fid';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
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
    'product' => 'product',
  );
  $translatables['souriau_google_imagemap'] = array(
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
    t('Products referenced by field_sku_products'),
    t('file from field_sku_images'),
    t('Content entity referenced from field_parent_product_range'),
    t('image from field_image'),
    t('Nid'),
    t('File ID'),
    t('Path'),
  );
  $export['souriau_google_imagemap'] = $view;

  return $export;
}
