<?php
/**
 * @file
 * Domain specific facets block.
 */

$plugin = array(
  'title' => t('Souriau Download Center Search block'),
  'description' => t('Souriau Download Center Search block.'),
  'single' => TRUE,
  'render callback' => 'souriau_dc_search_block_render',
  'hook theme' => 'souriau_dc_search_block_content_type_theme',
  'defaults' => array(),
  'edit form' => 'souriau_dc_search_block_edit_form',
  'category' => array(t('Facet API')),
  'render last' => TRUE,
);

/**
 * Implements hook_content_type_theme().
 */
function souriau_dc_search_block_content_type_theme(&$theme, $plugin) {
  $theme['souriau_dc_search'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-dc-search',
    'variables' => [
      'form' => NULL,
      'results' => NULL,
      'next_page_link' => NULL,
    ],
  ];
}

/**
 * Implementation of edit form builder.
 */
function souriau_dc_search_block_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Plugin render callback.
 */
function souriau_dc_search_block_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $results = souriau_dc_apply_filter_helper([], FALSE);
  $settings['searchDCPager']['NextPage'] = $results['next_page'];

  $render = [
    '#theme' => 'souriau_dc_search',
    '#attached' => [
      'js' => [
        drupal_get_path('module', 'souriau_dc') . '/plugins/content_types/souriau_dc_search/js/souriau_dc_pager.js',
        [
          'data' => $settings,
          'type' => 'setting',
        ]
      ],
    ],
    '#form' => drupal_get_form('souriau_dc_search_form'),
    '#results' => $results['view'],
  ];
  drupal_add_js(drupal_get_path('module', 'souriau_dc') . '/plugins/content_types/souriau_dc_search/js/hummingbird-treeview.js');
  drupal_add_js(drupal_get_path('module', 'souriau_dc') . '/plugins/content_types/souriau_dc_search/js/custom.js');
  $total_pages = ceil($results['count'] / 15);

  souriau_site_seo_generate_html_head_rel_links($total_pages);
  $render['#next_page_link'] = souriau_site_seo_generate_next_page_link($total_pages);

  $block->content = render($render);

  return $block;
}
