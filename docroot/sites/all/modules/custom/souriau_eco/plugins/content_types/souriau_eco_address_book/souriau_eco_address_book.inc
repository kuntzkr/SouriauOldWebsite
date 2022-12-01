<?php
/**
 * @file
 * Address Book.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU Eco: Address Book page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'description' => t('SOURIAU Eco: Address Book page', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'content_types' => 'souriau_eco_address_book',
  'single' => TRUE,
  'render callback' => 'souriau_eco_address_book_content_type_render',
  'hook theme' => 'souriau_eco_address_book_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  'required context' => new ctools_context_required(
    t('User', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'user'
  ),
);

/**
 * Implements hook_content_type_render().
 */
function souriau_eco_address_book_content_type_render($subtype, $conf, $panel_args, $context) {
  $module_path = drupal_get_path('module', 'souriau_eco');

  drupal_add_js($module_path . '/js/address-book.js');

  $user = $context->data;

  $block = new stdClass();
  $block->title = NULL;

  module_load_include('inc', 'commerce_addressbook', 'includes/commerce_addressbook.user');

  $render_array = [
    '#theme' => 'souriau_eco_address_book',
    '#form' => commerce_addressbook_profile_create($user, 'shipping'),
    '#addresses' => commerce_embed_view('souriau_commerce_addressbook', 'default', [$user->uid, 'shipping']),
  ];

  drupal_set_breadcrumb([]);

  $block->content = drupal_render($render_array);

  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_eco_address_book_content_type_theme(&$theme, $plugin) {
  $theme['souriau_eco_address_book'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-eco-address-book',
    'variables' => [
      'form' => NULL,
      'addresses' => [],
    ],
  ];
}

