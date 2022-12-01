<?php
/**
 * @file
 * Implements views hooks.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class draft_moderation_views_handler_field_unpublish_link extends views_handler_field {
  function construct() {
    parent::construct();
//    $this->additional_fields['language']  = 'entity_translation_node_language';
    $this->additional_fields['entity_id']  = 'entity_id';
    $this->additional_fields['entity_type'] = 'entity_type';
    $this->additional_fields['workflow'] = 'workflow';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function access() {
    // Later Ensure user has access to edit translations.
    return TRUE;
  }

  function render($values) {
    $value = array();
    if (isset($values->entity_translation_node_language)) {
      $value['language'] = $values->entity_translation_node_language;
    }
//   $this->get_value($values, 'entity_translation_node_language');
    $value['entity_id']   = $this->get_value($values, 'entity_id');
    $value['entity_type'] = $this->get_value($values, 'entity_type');
    $value['workflow'] = $this->get_value($values, 'workflow');

    return $this->render_link($value, $values);
  }

  function render_link($data, $values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('Unpublish');
    $entity = entity_load_single($data['entity_type'], $data['entity_id']);
    list( , , $bundle) = entity_extract_ids($data['entity_type'], $entity);
    if ($moderation_mode = draft_moderation_supported_type($bundle, $data['entity_type'])) {
      if ($data['entity_type'] == 'node') {
        if ($entity->is_draft) {
          $entity = entity_load_single($data['entity_type'], $entity->edition_id);
        }
        if (draft_moderation_unpublish_access('update', $entity, $data['language'])) {
          $this->options['alter']['path'] = "node/$entity->nid/unpublish/" . $data['language'];
        }
        else {
          return;
        }
      }
    }
    else {
      if ($data['entity_type'] == 'node') {
        $this->options['alter']['path'] = "node/$entity->nid/unpublish";
      }
    }
    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['query'] = drupal_get_destination();
    return $text;
  }
}
