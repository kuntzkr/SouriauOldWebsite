<?php
/**
 * @file
 * Domain specific facets block.
 */

$plugin = array(
  'title' => t('Souriau Autocomplete Search block'),
  'description' => t('Souriau Autocomplete Search block.'),
  'single' => TRUE,
  'render callback' => 'souriau_common_search_block_render',
  'defaults' => array(),
  'edit form' => 'souriau_common_search_block_edit_form',
  'category' => array(t('Facet API')),
  'render last' => TRUE,
);

/**
 * Implementation of edit form builder.
 */
function souriau_common_search_block_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Plugin render callback.
 */
function souriau_common_search_block_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $form = drupal_get_form('souriau_common_search_form');
  $block->content = render($form);

  return $block;
}
