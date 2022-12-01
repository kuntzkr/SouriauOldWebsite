<?php

/**
 * @file
 * Domain specific facets block.
 */

$plugin = array(
  'title' => t('Souriau Search Results block'),
  'description' => t('Souriau Search Results block.'),
  'single' => TRUE,
  'render callback' => 'souriau_search_search_block_render',
  'hook theme' => 'souriau_search_search_block_content_type_theme',
  'defaults' => array(),
  'edit form' => 'souriau_search_search_block_edit_form',
  'category' => array(t('Sauriau: Search')),
  'render last' => TRUE,
);

/**
 * Implements hook_content_type_theme().
 */
function souriau_search_search_block_content_type_theme(&$theme, $plugin) {
  $theme['souriau_search_search'] = [
    'path' => $plugin['path'] . '/theme',
    'template' => 'souriau-search',
    'variables' => [
      'form' => NULL,
      'tabs' => NULL,
      'results' => NULL,
      'filters' => NULL,
      'search_infos' => NULL,
      'filter_forms' => NULL,
      'next_page' => NULL,
      'comparator_string' => '',
    ],
  ];
  $theme['souriau_search_nav'] = [
    'path' => $plugin['path'] . '/theme',
    'template' => 'souriau-search-nav',
    'variables' => [
      'tabs' => NULL,
    ],
  ];
  $theme['souriau_search_filter'] = [
    'path' => $plugin['path'] . '/theme',
    'template' => 'souriau-search-filter',
    'variables' => [
      'tabs' => NULL,
    ],
  ];
  $theme['souriau_search_info'] = [
    'path' => $plugin['path'] . '/theme',
    'template' => 'souriau-search-info',
    'variables' => [
      'count' => 0,
      'filters' => []
    ],
  ];
  $theme['active_filters'] = [
    'path' => $plugin['path'] . '/theme',
    'template' => 'souriau-search-active-filters',
    'variables' => [
      'items' => [],
    ],
  ];
  $theme['active_filter_item'] = [
    'path' => $plugin['path'] . '/theme',
    'template' => 'souriau-search-active-filter-item',
    'variables' => [
      'title' => NULL,
      'machine_name' => NULL,
      'value' => NULL,
      'type' => NULL,
    ],
  ];
}

/**
 * Implementation of edit form builder.
 */
function souriau_search_search_block_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Plugin render callback.
 */
function souriau_search_search_block_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $tabs = [];
  $data = [
    'keyword' => isset($args[0]) ? $args[0] : '',
  ];
  if (!empty($_GET)) {
    $data = souriau_search_get_preprocess();
  }
  if (isset($_GET['active_tab']) && $_GET['active_tab'] == 'part-number') {
    $tabs = ['product'];
  }
  $filters = souriau_search_product_filter_form_process($data);
  $results = souriau_search_apply_filter_helper($tabs, $filters, FALSE);
  $active_tab = isset($_GET['active_tab']) ? $_GET['active_tab'] : 'all';
  $tab_titles = souriau_search_tabs_info($active_tab);
  $settings['souriauSearchPager'] = [];
  foreach ($tab_titles as $tab_id => $tab_info) {
    $tab_titles[$tab_id]['total'] = $results['count'][$tab_id];
    $settings['souriauSearchPager']['NextPage'][$tab_titles[$tab_id]['html_id']] = $results['next_page'][$tab_id];
  }
  $settings['souriauSearchPager']['IndexName'] = PRODUCT_SEARCH_INDEX;
  $comparator_data = isset($_COOKIE['Drupal_visitor_part_numbers']) ? explode(',', $_COOKIE['Drupal_visitor_part_numbers']) : [];
  $comparator_data = array_filter($comparator_data);
  $comparator_count = count($comparator_data);
  $comparator_string = $comparator_count == 0 ? '' : format_plural($comparator_count, t('1 item added', [], ['context' => SOURIAU_COMMON_T_OTHER]), t('@count items added', [], ['context' => SOURIAU_COMMON_T_OTHER]));
  $render = [
    '#theme' => 'souriau_search_search',
    '#attached' => [
      'js' => [
        drupal_get_path('module', 'souriau_search') . '/plugins/content_types/souriau_search_results/js/souriau_search_pager.js',
        [
          'data' => $settings,
          'type' => 'setting',
        ]
      ],
    ],
    '#tabs' => [
      '#theme' => 'souriau_search_nav',
      '#tabs' => $tab_titles,
    ],
    '#filters' => [
      'product' => [
        '#theme' => 'souriau_search_filter',
        '#tabs' => 'product',
      ],
    ],
    '#filter_forms' => [
      'product' => drupal_get_form('souriau_search_product_filter_form', 'product', $filters['keyword']),
    ],
    '#search_infos' => [
      'product' => [
        '#theme' => 'souriau_search_info',
        '#count' => format_plural($results['count']['product'], '1 item', '@count items'),
        '#filters' => isset($results['active_filters']) ? $results['active_filters'] : NULL,
      ],
    ],
    '#results' => $results['results'],
    '#next_page' => $results['next_page'],
    '#comparator_string' => $comparator_string,
  ];
  $block->content = render($render);

  return $block;
}
