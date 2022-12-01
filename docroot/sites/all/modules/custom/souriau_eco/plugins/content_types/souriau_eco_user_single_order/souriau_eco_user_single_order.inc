<?php
/**
 * @file
 * ERP User Orders.
 */

$plugin = [
  'title' => t('SOURIAU Eco: User Single Orders Page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'description' => t('SOURIAU Eco: User Single Order Page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'content_types' => 'souriau_eco_user_single_order',
  'single' => TRUE,
  'render callback' => 'souriau_eco_user_single_order_content_type_render',
  'hook theme' => 'souriau_eco_user_single_order_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'required context' => new ctools_context_required(
    t('ERP Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'erp_order'
  ),
];

/**
 * Implements hook_content_type_render().
 */
function souriau_eco_user_single_order_content_type_render($subtype, $conf, $panel_args, ctools_context $context) {
  $order_id = $context->data;

  $block = new stdClass();
  $block->title = NULL;
  $data = [];

  $order = souriau_eco_load_user_orders_info(['order_id' => $order_id]);
  // Order country.
  $country_list = country_get_list();
  $order->ship_to_ad_country = isset($country_list[$order->ship_to_ad_country_code]) ? drupal_strtoupper($country_list[$order->ship_to_ad_country_code]) : '';
  $data['order'] = $order;

  $table = '';
  if (!empty($order->order_items)) {
    $rows = [];
    foreach ($order->order_items as $key => $item) {
      // Line control.
      $line = 'line' . $key;

      // Prepare date.
      $line_creation_date = $item->so_line_creation_date ? format_date(strtotime($item->so_line_creation_date), 'souriau_date_short') : '';
      $line_last_shipping_date = $item->so_line_last_shipping_date ? format_date(strtotime($item->so_line_last_shipping_date), 'souriau_date_short') : '';
      $line_requested_delivery_date = $item->so_line_requested_delivery_date ? format_date(strtotime($item->so_line_requested_delivery_date), 'souriau_date_short_with_time') : '';

      // Cells of sub table.
      $cells = [
        'cell1' => '<div>' . t('UNIT PRICE', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) . '</div>' . number_format($item->so_line_unit_price_transaction_ordered, 2, '.', ' ') . ' ' . $item->so_line_currency,
        'cell2' => '<div>' . t('LEAD TIME REQUESTED', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) . '</div>' . $line_requested_delivery_date,
        'cell3' => '<div>' . t('STATUS', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) . '</div>' . $item->so_line_status,
        'cell4' => '<div>' . t('LAST SHIPPING DATE', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) . '</div>' . $line_last_shipping_date,
        'cell5' => '<div>' . t('ORDER LINE CREATION DATE', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) . '</div>' . $line_creation_date,
        'cell6' => '<div>' . t('ORDER LINE LAST UPDATE DATE', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) . '</div>' . $line_last_shipping_date,
      ];
      // Sub table, with line item details.
      $sub_table = theme('table', [
        'header' => [],
        'rows' => [
          [
            'data' => [
              $cells['cell1'],
              $cells['cell2'],
              $cells['cell3'],
            ],
            'no_striping' => TRUE
          ],
          [
            'data' => [
              $cells['cell4'],
              $cells['cell5'],
              $cells['cell6'],
            ],
            'no_striping' => TRUE
          ],
        ],
      ]);
      // Add table wrapper.
      $sub_table = '<div class="panel-body">' . $sub_table . '</div>';
      $sub_table = '<div id="' . $line . '" class="panel-collapse collapse" role="tabpanel" aria-expanded="false">' . $sub_table . '</div>';

      // Link for more information about line item.
      $link = l('<span class="screen-reader-text">' . t('open block', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) . '</span>', '#' . $line, [
        'attributes' => [
          'class' => ['collapsed'],
          'role' => 'button',
          'data-toggle' => 'collapse',
          'data-parent' => '#accordion',
          'aria-expanded' => 'false',
          'aria-controls' => $line,
        ],
        'external' => TRUE,
        'html' => TRUE,
      ]);

      // Add wrapper to link.
      $link = '<div class="b-open" role="tab">' . $link . '</div>';
      // Add quantity ordered.
      $link .= number_format($item->so_line_quantity_ordered, 0, '.', ' ');

      $rows[] = [
        'data' => [
          ['data' => $item->so_line_no, 'class' => ['col1']],
          ['data' => $item->so_part_number, 'class' => ['col2']],
          ['data' => $item->so_part_number_designation, 'class' => ['col3']],
          ['data' => $link],
        ],
        'no_striping' => TRUE,
      ];

      // Insert sub table with details about line item.
      $rows[] = [
        'data' => [
          ['data' => $sub_table, 'colspan' => 4, 'class' => ['accordion-block']],
        ],
        'no_striping' => TRUE,
      ];
    }
    $header = [
      t('ORDER LINE NUMBER', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
      t('PART NUMBER', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
      t('DESCRIPTION', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
      t('QUANTITY', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    ];
    $table = theme('table', ['header' => $header, 'rows' => $rows]);
  }
  $data['table'] = $table;

  $block->content = theme('souriau_eco_user_single_order', $data);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_eco_user_single_order_content_type_theme(&$theme, $plugin) {
  $theme['souriau_eco_user_single_order'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-user-single-order',
  ];
}
