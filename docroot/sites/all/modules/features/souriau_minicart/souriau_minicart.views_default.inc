<?php
/**
 * @file
 * souriau_minicart.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_minicart_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_minicart';
  $view->description = 'Display a shopping cart update form.';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Souriau minicart';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Shopping cart';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view own commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'rendered_entity' => 'rendered_entity',
    'sku' => 'sku',
    'edit_quantity' => 'edit_quantity',
    'edit_delete' => 'edit_delete',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'rendered_entity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sku' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_quantity' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_delete' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Field: Commerce Line item: Product */
  $handler->display->display_options['fields']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_product']['label'] = 'PART NUMBER';
  $handler->display->display_options['fields']['commerce_product']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_product']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_product']['type'] = 'commerce_product_reference_sku_plain';
  $handler->display->display_options['fields']['commerce_product']['settings'] = array(
    'view_mode' => 'token',
    'page' => 0,
  );
  /* Field: Commerce Line item: Product */
  $handler->display->display_options['fields']['commerce_product_1']['id'] = 'commerce_product_1';
  $handler->display->display_options['fields']['commerce_product_1']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product_1']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product_1']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_product_1']['label'] = 'ADDED ITEMS';
  $handler->display->display_options['fields']['commerce_product_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_product_1']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['commerce_product_1']['settings'] = array(
    'view_mode' => 'node_minicart_summary',
    'page' => 1,
  );
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Commerce Line Item: Delete button */
  $handler->display->display_options['fields']['edit_delete']['id'] = 'edit_delete';
  $handler->display->display_options['fields']['edit_delete']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['edit_delete']['field'] = 'edit_delete';
  $handler->display->display_options['fields']['edit_delete']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['edit_delete']['label'] = '';
  $handler->display->display_options['fields']['edit_delete']['alter']['text'] = '[rendered_entity]
[sku]
[edit_quantity]
[edit_delete]';
  $handler->display->display_options['fields']['edit_delete']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_delete']['element_default_classes'] = FALSE;
  /* Sort criterion: Commerce Line Item: Line item ID */
  $handler->display->display_options['sorts']['line_item_id']['id'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['table'] = 'commerce_line_item';
  $handler->display->display_options['sorts']['line_item_id']['field'] = 'line_item_id';
  $handler->display->display_options['sorts']['line_item_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Contextual filter: Commerce Order: Order ID */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Line Item: Line item is of a product line item type */
  $handler->display->display_options['filters']['product_line_item_type']['id'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['table'] = 'commerce_line_item';
  $handler->display->display_options['filters']['product_line_item_type']['field'] = 'product_line_item_type';
  $handler->display->display_options['filters']['product_line_item_type']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['filters']['product_line_item_type']['value'] = '1';
  $handler->display->display_options['filters']['product_line_item_type']['group'] = 0;
  $translatables['souriau_minicart'] = array(
    t('Defaults'),
    t('Shopping cart'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Line items referenced by commerce_line_items'),
    t('PART NUMBER'),
    t('ADDED ITEMS'),
    t('Quantity'),
    t('.'),
    t(','),
    t('[rendered_entity]
[sku]
[edit_quantity]
[edit_delete]'),
    t('All'),
  );
  $export['souriau_minicart'] = $view;

  return $export;
}
