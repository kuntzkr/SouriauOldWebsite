<?php
/**
 * @file
 * Views plugin for translation edit link.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class souriau_common_views_handler_field_translation_edit_link extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['language']  = 'language';
    $this->additional_fields['entity_id']  = 'entity_id';
    $this->additional_fields['entity_type'] = 'entity_type';
    if (module_exists('draft_moderation')) {
      $this->additional_fields['workflow'] = 'workflow';
    }
  }

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
    parent::options_form($form, $form_state);
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   */
  public function access() {
    // Later Ensure user has access to edit translations.
    return TRUE;
  }

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $value = array();
    $value['language']    = $this->get_value($values, 'language');
    $value['entity_id']   = $this->get_value($values, 'entity_id');
    $value['entity_type'] = $this->get_value($values, 'entity_type');
    if (module_exists('draft_moderation')) {
      $value['workflow'] = $this->get_value($values, 'workflow');
    }
    return $this->render_link($value, $values);
  }

  /**
   * {@inheritdoc}
   */
  private function render_link($data, $values) {
    if (!module_exists('draft_moderation')) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    $entity = entity_load_single($data['entity_type'], $data['entity_id']);
    $handler = entity_translation_get_handler($data['entity_type'], $entity);
    $languages = entity_translation_languages();

    // Ensure user has access to edit translations.
    if (!isset($languages[$data['language']])) {
      return;
    }
    if (!$handler->getAccess('update') || !$handler->getTranslationAccess($data['language'])) {
      return;
    }

    if ('distributor' != $data['entity_type']) {
      list(,, $bundle) = entity_extract_ids($data['entity_type'], $entity);
      $mode = draft_moderation_supported_type($bundle, $data['entity_type']);
      if (empty($mode)) {
        return;
      }
      if (!$entity->is_draft && !user_access('edit production editions')) {
        return;
      }
      if (!_draft_moderation_check_access($mode, $data)) {
        return;
      }
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = $handler->getEditPath($data['language']);
    // $this->options['alter']['query'] = drupal_get_destination();
    $this->options['alter']['language'] = $languages[$data['language']];
    return $text;
  }

}
