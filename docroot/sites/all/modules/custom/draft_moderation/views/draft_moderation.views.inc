<?php

/**
 * @file
 * Implements views hooks.
 */

/**
 * Implements hook_views_handlers().
 */
function draft_moderation_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'draft_moderation') . '/views/handlers',
    ),
    'handlers' => array(
      'draft_moderation_views_handler_filter_workflow' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
      'draft_moderation_views_handler_field_publish_link' => array(
        'parent' => 'views_handler_field',
      ),
      'draft_moderation_views_handler_field_unpublish_link' => array(
        'parent' => 'views_handler_field',
      ),
      'draft_moderation_views_handler_field_status' => array(
        'parent' => 'views_handler_field_boolean',
      ),
      // @Checkit.
      'draft_moderation_views_handler_translation_relationship' => array(
        'parent' => 'views_handler_relationship',
      ),
    ),
  );
}

/**
 * Implements hook_views_data_alter().
 *
 * Add entity translation information to the various entity tables.
 */
function draft_moderation_views_data_alter(&$data) {
  if (module_exists('entity_translation')) {
    foreach (entity_get_info() as $type => $info) {
      if ($info['fieldable'] && isset($data[$info['base table']])) {
        $table = &$data[$info['base table']];
        $table['entity_translations'] = array(
          'title' => t('Entity translation: translations'),
          'help' => t('Translation information.'),
          'relationship' => array(
            'label' => t('Translations'),
            'base' => 'entity_translation',
            'base field' =>  'entity_id',
            'relationship table' =>  $info['base table'],
            'relationship field' => $info['entity keys']['id'],
            'handler' => 'draft_moderation_views_handler_translation_relationship',
            // We add our information here in the definition, so we can copy it
            // later.
            'left_table' => $info['base table'],
            'left_field' => $info['entity keys']['id'],
            'entity type' => $type,
          ),
        );
      }
    }
    $data['entity_translation']['workflow'] = array(
      'title' => t('Workflow status'),
      'help' => t('Indicates the workflow status of the translation.'),
      'field' => array(
        'handler' => 'draft_moderation_views_handler_field_workflow',
        'click sortable' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
        'name field' => 'title',
        'numeric' => TRUE,
      ),
      'filter' => array(
        'handler' => 'draft_moderation_views_handler_filter_workflow',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );

    $data['entity_translation']['status']['field'] = array(
      'handler' => 'draft_moderation_views_handler_field_status',
      'click sortable' => TRUE,
      'output formats' => array(
        'published-notpublished' => array(
          t('Published'),
          t('Not published')
        )
      )
    );

    $data['entity_translation']['status']['filter'] = array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Published'),
      'type' => 'yes-no',
      'use equal' => TRUE
    );
  }
}

/**
 * Implements hook_views_data().
 */
function draft_moderation_views_data() {
  $data = array();
  $data['entity_translation']['publish_translation'] = array(
    'group' => t('Entity translation'),
    'field' => array(
      'title' => t('Publish link'),
      'help' => t('Provide a simple link to publish the translation.'),
      'handler' => 'draft_moderation_views_handler_field_publish_link',
    ),
  );
  $data['entity_translation']['unpublish_translation'] = array(
    'group' => t('Entity translation'),
    'field' => array(
      'title' => t('Unpublish link'),
      'help' => t('Provide a simple link to unpublish the translation.'),
      'handler' => 'draft_moderation_views_handler_field_unpublish_link',
    ),
  );
  return $data;
}
