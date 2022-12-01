<?php
/**
 * @file
 * Module hooks.
 */

/**
 * Creates form element _souriau_common_element_search_autocomplete_info().
 */
function _souriau_common_element_search_autocomplete_info() {

  $types['search_autocomplete'] = array(
    '#input' => TRUE,
    '#tree' => TRUE,
    '#process' => array('form_process_souriau_search_autocomplete'),
    '#pre_render' => array('form_pre_render_conditional_form_element'),
    '#file' => 'search_autocomplete.element.inc',
  );

  return $types;
}

/**
 * Implements search_autocomplete form element process.
 */
function form_process_souriau_search_autocomplete($element) {
  $element['search_key'] = array(
    '#type' => 'textfield',
    '#theme_wrappers' => [],
  );

  $index = search_api_index_load($element['#index']);
  $js_settings = array(
    'server' => $index->server,
    'index' => $element['#index'],
    'fields' => implode(',', $element['#fields']),
    'autocomplete_ui_path' => $element['#autocomplete_ui_path'],
  );

  $element['#attached']['library'][] = array('system', 'ui.autocomplete');
  $element['#attached']['js'][] = array(
    'data' => array('souriau_search_autocomplete' => array($element['#id'] => $js_settings)),
    'type' => 'setting',
  );
  $element['#attached']['js'][] = drupal_get_path('module', 'souriau_common') . '/js/souriau_search_autocomplete.js';

  return $element;
}

/**
 * Implements search_autocomplete().
 */
function theme_search_autocomplete($variables) {
  $element = $variables['element'];
  $attributes = array();
  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  $attributes['class'] = 'iban_multipart';

  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] .= ' ' . implode(' ', $element['#attributes']['class']);
  }
  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }

  return '<ul' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</ul>';
}
