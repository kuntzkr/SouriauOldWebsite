<?php
/**
 * @file
 * Souriau Compare Part Numbers: Part Number List.
 */

$plugin = [
  'title' => t('SOURIAU Compare: Part Number List', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'description' => t('SOURIAU Compare: Part Number List', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'render callback' => 'souriau_compare_part_number_list_content_type_render',
  'hook theme' => 'souriau_compare_part_number_list_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
];

/**
 * Implements hook_content_type_render().
 */
function souriau_compare_part_number_list_content_type_render($subtype, $conf, $panel_args) {
  return (object) [
    'content' => souriau_compare_part_number_list_content(),
  ];
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_compare_part_number_list_content_type_theme(&$theme, $plugin) {
  $theme['souriau_compare_part_number_list'] = [
    'path' => $plugin['path'],
    'template' => 'part-number-list',
    'variables' => [
      'part_numbers' => [],
    ],
  ];

  $theme['souriau_compare_part_number_list_item'] = [
    'path' => $plugin['path'],
    'template' => 'part-number-list-item',
    'variables' => [
      'product_title'  => NULL,
      'product_code'   => NULL,
      'product_image'  => NULL,
      'product_id'     => NULL,
      'product_series' => NULL,
      'where_to_buy'   => NULL,
    ],
  ];
}
