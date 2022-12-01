<?php
/**
 * @file
 * Souriau Compare Part Numbers: Part Number Technical Data.
 */

$plugin = [
  'title' => t('SOURIAU Compare: Technical data comparison', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'description' => t('SOURIAU Compare: Technical data comparison', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'render callback' => 'souriau_compare_tech_data_content_type_render',
  'hook theme' => 'souriau_compare_tech_data_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
];

/**
 * Implements hook_content_type_render().
 */
function souriau_compare_tech_data_content_type_render($subtype, $conf, $panel_args) {
  return (object) [
    'content' => souriau_compare_tech_data_content(),
  ];
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_compare_tech_data_content_type_theme(&$theme, $plugin) {
  $theme['souriau_compare_tech_data'] = [
    'path' => $plugin['path'],
    'template' => 'technical-data-comparison',
    'variables' => [
      'tech_data' => [],
      'part_numbers' => [],
    ],
  ];
}
