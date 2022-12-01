<?php
/**
 * @file
 * souriau_ct_generic_landing.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function souriau_ct_generic_landing_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_generic_link'.
  $field_bases['field_generic_link'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_generic_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 1,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_link_bg_color'.
  $field_bases['field_link_bg_color'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_link_bg_color',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'jquery_colorpicker',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'jquery_colorpicker',
  );

  return $field_bases;
}
