<?php
/**
 * @file
 * Views integration for the souriau_eco_erp.
 */

/**
 * Implements hook_views_handlers().
 */
function souriau_eco_erp_views_handlers() {
  return [
    'info' => [
      'path' => drupal_get_path('module', 'souriau_eco_erp') . '/views/handlers',
    ],
    'handlers' => [
      'souriau_eco_erp_views_handler_erp_link' => [
        'parent' => 'views_handler_field',
      ],
      'souriau_eco_erp_views_handler_line_items' => [
        'parent' => 'views_handler_field',
      ],
    ],
  ];
}

/**
 * Implements hook_views_data_alter().
 */
function souriau_eco_erp_views_data_alter(&$data) {
  $data['commerce_order']['souriau_erp_link'] = [
    'group' => t('Commerce order'),
    'field' => [
      'title' => t('Edit ERP'),
      'help' => t('Provide edit ERP link.'),
      'handler' => 'souriau_eco_erp_views_handler_erp_link',
    ],
  ];
  $data['commerce_order']['commerce_line_items'] = [
    'group' => t('Commerce order'),
    'field' => [
      'title' => t('Line Items'),
      'help' => t('All line items of an order.'),
      'handler' => 'souriau_eco_erp_views_handler_line_items',
    ],
  ];
}
