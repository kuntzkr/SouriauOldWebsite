<?php
/**
 * @file
 * souriau_ct_postcard.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function souriau_ct_postcard_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_popup_text'.
  $field_bases['field_popup_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_popup_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  return $field_bases;
}
