<?php
/**
 * @file
 * User zone: My account Landing.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU User: My account landing', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU User: My account landing', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'content_types' => 'souriau_user_landing',
  'single' => TRUE,
  'render callback' => 'souriau_user_landing_content_type_render',
  'hook theme' => 'souriau_user_landing_content_type_theme',
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
function souriau_user_landing_content_type_render($subtype, $conf, $panel_args, $context) {
  $ctool_context = array_shift($context);
  $user = $ctool_context->data;

  $render_params = [
    '#theme' => 'souriau_user_landing',
  ];

  $variables = variable_get('souriau_site_settings_variables', '');
  $landing_text = isset($variables['user_zone']['landing_text']) ? $variables['user_zone']['landing_text'] : '';

  $user_links = [
    "user/{$user->uid}/edit-profile" => t('Edit my account', [], ['context' => SOURIAU_COMMON_T_USER]),
    "user/{$user->uid}/erp-orders" => t('My orders', [], ['context' => SOURIAU_COMMON_T_USER]),
    "user/{$user->uid}/projects" => t('My projects', [], ['context' => SOURIAU_COMMON_T_USER]),
    "user/{$user->uid}/addresses" => t('My address book', [], ['context' => SOURIAU_COMMON_T_USER]),
    "user/{$user->uid}/sample-orders" => t('My sample orders', [], ['context' => SOURIAU_COMMON_T_USER]),
    "user/{$user->uid}/delete-account" => t('Delete my account', [], ['context' => SOURIAU_COMMON_T_USER]),
  ];

  foreach ($user_links as $path => $title) {
    $menu_item = menu_get_item($path);

    if (!$menu_item || !$menu_item['access']) {
      unset($user_links[$path]);
    }

  }

  $render_params += [
    '#user_links' => $user_links,
    '#landing_text' => $landing_text,
  ];

  return (object) [
    'title' => NULL,
    'content' => drupal_render($render_params),
  ];
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_user_landing_content_type_theme(&$theme, $plugin) {
  $theme['souriau_user_landing'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-user-landing',
    'variables' => [
      'user_links' => [],
      'landing_text' => '',
    ],
  ];
}
