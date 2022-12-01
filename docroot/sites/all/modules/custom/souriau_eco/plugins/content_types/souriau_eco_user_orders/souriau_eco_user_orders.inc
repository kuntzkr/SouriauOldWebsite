<?php
/**
 * @file
 * ERP User Orders.
 */

$plugin = [
  'title' => t('SOURIAU Eco: User orders page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'description' => t('SOURIAU Eco: User orders page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'content_types' => 'souriau_eco_user_orders',
  'single' => TRUE,
  'render callback' => 'souriau_eco_user_orders_content_type_render',
  'hook theme' => 'souriau_eco_user_orders_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'required context' => new ctools_context_required(
    t('User', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'user'
  ),
];

/**
 * Implements hook_content_type_render().
 */
function souriau_eco_user_orders_content_type_render($subtype, $conf, $panel_args, ctools_context $context) {

  $sections = [
    SOURIAU_ECO_ERP_ORDER_STATUS_NO_SHIPPED => '#progress_orders',
    SOURIAU_ECO_ERP_ORDER_STATUS_SHIPPED => '#completed_orders',
  ];

  $customer = $context->data;
  $customer_wrapper = entity_metadata_wrapper('user', $customer);
  $customer_erp_numbers = $customer_wrapper->field_ect_customer_numbers->value();

  $limit = SOURIAU_ECO_ERP_ORDER_ITEMS_PER_PAGE;

  $block = new stdClass();
  $block->title = NULL;

  $render_params = [
    '#theme' => 'souriau_eco_user_orders',
  ];

  $statuses = [
    SOURIAU_ECO_ERP_ORDER_STATUS_NO_SHIPPED,
    SOURIAU_ECO_ERP_ORDER_STATUS_SHIPPED,
  ];

  foreach ($statuses as $status) {
    $total = souriau_eco_load_user_orders_count($customer_erp_numbers, $status);

    $page = pager_default_initialize($total, $limit, $status);
    $offset = $page * $limit;

    $render_params[$sections[$status]] = [
      '#theme' => 'souriau_eco_user_orders_table',
      '#orders' => souriau_eco_load_user_orders(
        $customer_erp_numbers, $status, $offset, $limit
      ),
      '#pager' => theme('pager', [
        'element' => $status,
        'quantity' => $total,
        'tags' => [
          0 => t('«', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
          1 => t('‹', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
          3 => t('›', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
          4 => t('»', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
        ],
      ]),
    ];
  }

  $block->content = drupal_render($render_params);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_eco_user_orders_content_type_theme(&$theme, $plugin) {
  $theme['souriau_eco_user_orders'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-user-orders',
    'variables' => [
      'progress_orders' => [],
      'completed_orders' => [],
    ],
  ];

  $theme['souriau_eco_user_orders_table'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-user-orders-table',
    'variables' => [
      'orders' => [],
      'pager' => '',
    ],
  ];
}
