<?php
/**
 * @file
 * Domain specific facets block.
 */

$plugin = [
  'title' => t('SOURIAU Common: Contact Page Where To Buy Block', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: Contact Page Where To Buy Block', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'single' => TRUE,
  'render callback' => 'souriau_common_where_to_buy_block_render',
  'defaults' => [],
  'edit form' => 'souriau_common_where_to_buy_block_edit_form',
  'hook theme' => 'souriau_common_where_to_buy_block_theme',
  'category' => [t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_ADMIN])],
  'icon' => NULL,
  'all contexts' => TRUE,
];

/**
 * Implementation of edit form builder.
 */
function souriau_common_where_to_buy_block_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Plugin render callback.
 */
function souriau_common_where_to_buy_block_render($subtype, $conf, $args, $context) {
  global $language;
  $block = new stdClass();
  $block->title = NULL;
  $data = [];
  $souriau_settings = variable_get('souriau_common_settings');
  // Loading data from backend variable admin UI.
  $data['_html']['contact_information'] = i18n_variable_get('contact_form_description', $language->language);
  $data['_html']['redirect-url'] = l(
    t('WHERE TO BUY', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    format_string('our-distributors'),
    [
      'attributes' => [
        'class' => [
          'btn', 'orange-btn-hover',
        ],
      ],
    ]
  );
  $block->content = theme('where_to_buy', $data);
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_where_to_buy_block_theme(&$theme, $plugin) {
  $theme['where_to_buy'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-where-to-buy',
    'variables' => [
      '_html' => NULL,
    ],
  ];
}
