<?php
/**
 * @file
 * souriau_entity_project.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function souriau_entity_project_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'paragraphs_item-project_item-field_notes'.
  $field_instances['paragraphs_item-project_item-field_notes'] = array(
    'bundle' => 'project_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_notes',
    'label' => 'Notes',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'paragraphs_item-project_item-field_part_number'.
  $field_instances['paragraphs_item-project_item-field_part_number'] = array(
    'bundle' => 'project_item',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'paragraphs_editor_preview' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'paragraphs_item',
    'field_name' => 'field_part_number',
    'label' => 'Part number',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'project-project-field_part_numbers'.
  $field_instances['project-project-field_part_numbers'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'paragraphs',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'paragraphs_view',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'project',
    'field_name' => 'field_part_numbers',
    'label' => 'Part numbers',
    'required' => 0,
    'settings' => array(
      'add_mode' => 'button',
      'allowed_bundles' => array(
        'application_example' => -1,
        'application_paragraph' => -1,
        'homepage_beginner_guide' => -1,
        'homepage_categories' => -1,
        'homepage_promotion_links' => -1,
        'homepage_slides' => -1,
        'product_range_application_refenc' => -1,
        'product_range_paragraph' => -1,
        'project_item' => 'project_item',
        'tool_step' => -1,
      ),
      'bundle_weights' => array(
        'application_example' => 2,
        'application_paragraph' => 3,
        'homepage_beginner_guide' => 4,
        'homepage_categories' => 5,
        'homepage_promotion_links' => 6,
        'homepage_slides' => 7,
        'product_range_application_refenc' => 8,
        'product_range_paragraph' => 9,
        'project_item' => 20,
        'tool_step' => 10,
      ),
      'default_edit_mode' => 'open',
      'entity_translation_sync' => FALSE,
      'title' => 'Partnumber',
      'title_multiple' => 'Partnumbers',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'paragraphs',
      'settings' => array(),
      'type' => 'paragraphs_embed',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'project-project-field_project_description'.
  $field_instances['project-project-field_project_description'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'project',
    'field_name' => 'field_project_description',
    'label' => 'Description',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => '',
        'maxlength_js_enforce' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'maxlength_js_truncate_html' => 0,
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'project-project-field_project_title'.
  $field_instances['project-project-field_project_title'] = array(
    'bundle' => 'project',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'project',
    'field_name' => 'field_project_title',
    'label' => 'Title',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Notes');
  t('Part number');
  t('Part numbers');
  t('Title');

  return $field_instances;
}
