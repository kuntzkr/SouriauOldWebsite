<?php
/**
 * @file
 * User zone: My account Delete.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU User: My account delete', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU User: My account delete', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'content_types' => 'souriau_user_delete',
  'single' => TRUE,
  'render callback' => 'souriau_user_delete_content_type_render',
  'hook theme' => 'souriau_user_delete_content_type_theme',
  'category' => t('SOURIAU'),
  'icon' => NULL,
  'render last' => TRUE,
  'required context' => [
    new ctools_context_required(t('User', [], ['context' => SOURIAU_COMMON_T_ADMIN]), 'user'),
  ],
];

/**
 * Implements hook_content_type_render().
 */
function souriau_user_delete_content_type_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $_html = [];
  $ctool_context = array_shift($context);
  $user = $ctool_context->data;

  $_html['delete-link'] = l(
    t('DELETE MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    format_string('user/!uid/delete/nojs', ['!uid' => $user->uid]),
    [
      'attributes' => [
        'class' => [
          'ctools-use-modal', 'ctools-modal-souriau-modal-style',
          'btn', 'orange-btn',
        ],
      ],
    ]
  );

  $block->content = theme(
    'souriau_user_delete',
    ['_html' => $_html]
  );
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_user_delete_content_type_theme(&$theme, $plugin) {
  $theme['souriau_user_delete'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-user-delete',
    'variables' => [
      'user_links' => [],
      'landing_text' => '',
    ],
  ];
}
