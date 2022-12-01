<?php

/**
 * @file
 * Souriau views hooks.
 */

/**
 * Implements hook_views_handlers().
 */
function souriau_common_views_handlers() {
  return [
    'info' => [
      'path' => drupal_get_path('module', 'souriau_common') . '/views/handlers',
    ],
    'handlers' => [
      'souriau_common_views_handler_field_translation_edit_link' => [
        'parent' => 'views_handler_field',
      ],
      'souriau_common_views_handler_field_translation_link' => [
        'parent' => 'views_handler_field',
      ],
      'souriau_common_views_handler_field_language_link' => [
        'parent' => 'views_handler_field',
      ],
      'souriau_common_views_handler_field_link_clone' => [
        'parent' => 'views_handler_field_node_link_clone',
      ],
      'souriau_common_views_handler_field_project_part_number_sku' => [
        'parent' => 'views_handler_field',
      ],
    ],
  ];
}

/**
 * Implements hook_views_data().
 */
function souriau_common_views_data() {
  $data = [];

  $data['entity_translation']['edit_translation'] = [
    'group' => t('Entity translation'),
    'field' => [
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the translation.'),
      'handler' => 'souriau_common_views_handler_field_translation_edit_link',
    ],
  ];

  $data['entity_translation']['view_translation'] = [
    'group' => t('Entity translation'),
    'field' => [
      'title' => t('Link to translation'),
      'help' => t('Provide a simple link to view the translation.'),
      'handler' => 'souriau_common_views_handler_field_translation_link',
    ],
  ];

  $data['entity_translation']['language_link'] = [
    'group' => t('Entity translation'),
    'field' => [
      'title' => t('Link with translation language'),
      'help' => t('Provide a simple link with translation language.'),
      'handler' => 'souriau_common_views_handler_field_language_link',
    ],
  ];

  $data['project']['table']['group'] = t('Project');
  $data['project']['table']['join'] = [
    '#global' => [],
  ];
  $data['project']['project_part_number_sku'] = [
    'title' => t('Project Part Number SKU'),
    'help' => t('Part Number SKU of a project.'),
    'field' => [
      'handler' => 'souriau_common_views_handler_project_part_number_sku',
    ],
  ];

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function souriau_common_views_data_alter(&$views_data) {
  $views_data['node']['clone_node']['field']['handler'] = 'souriau_common_views_handler_field_link_clone';
}
