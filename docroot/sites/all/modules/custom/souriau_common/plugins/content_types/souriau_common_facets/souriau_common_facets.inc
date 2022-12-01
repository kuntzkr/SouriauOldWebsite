<?php
/**
 * @file
 * Domain specific facets block.
 */

$plugin = array(
  'title' => t('Souriau Facets block'),
  'description' => t('Souriau Facets domain specific configurable block.'),
  'single' => TRUE,
  'render callback' => 'souriau_common_facets_block_render',
  'defaults' => array(),
  'edit form' => 'souriau_common_facets_block_edit_form',
  'category' => array(t('Facet API')),
  'render last' => TRUE,
);

/**
 * Implementation of edit form builder.
 */
function souriau_common_facets_block_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Plugin render callback.
 */
function souriau_common_facets_block_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->content = '';

  $_domain = domain_get_domain();
  $facet_settings = domain_conf_variable_get($_domain['domain_id'], 'souriau_common_fasets');
  $visible_facets = array();
  foreach ($facet_settings as $facet_name => $facet_setting) {
    if ($facet_setting['enabled'] != 1) {
      continue;
    }
    $visible_facets[] = array(
      'weight' => $facet_setting['weight'],
      'name' => $facet_name,
    );
  }

  uasort($visible_facets, 'drupal_sort_weight');

  $map = facetapi_get_delta_map();
  foreach ($visible_facets as $visible_facet) {
    foreach (facetapi_get_searcher_info() as $searcher => $searcher_info) {
      if ($searcher_info['instance'] != 'products_search_index') {
        continue;
      }
      // @todo Apply cache settings for the searcher?
      $cache = facetapi_get_block_cache_setting($searcher, 'block');
      if ($facet = facetapi_facet_load($visible_facet['name'], $searcher)) {
        $string = facetapi_build_delta($searcher, 'block', $visible_facet['name']);
        $facet_block_delta = array_search($string, $map);
        $facet_block = module_invoke('facetapi', 'block_view', $facet_block_delta);
        $block->content .= render($facet_block['content']);
      }
    }
  }

  return $block;
}
