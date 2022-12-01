<?php
/**
 * @file
 * Views plugin for translation language link.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class souriau_common_views_handler_field_language_link extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['language']  = 'language';
    $this->additional_fields['entity_id']  = 'entity_id';
    $this->additional_fields['entity_type'] = 'entity_type';
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
    // Ensure user has access to edit translations.
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
    return $this->render_link($value, $values);
  }

  /**
   * {@inheritdoc}
   */
  private function render_link($data, $values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $entity = entity_load_single($data['entity_type'], $data['entity_id']);
    $handler = entity_translation_get_handler($data['entity_type'], $entity);
    if ($handler->getAccess('view')) {
      $languages = language_list();
      $this->options['alter']['make_link'] = TRUE;
      if (isset($languages[$data['language']])) {
        $this->options['alter']['language'] = $languages[$data['language']];
      }
      $this->options['alter']['query']    = drupal_get_destination();

      // Check if the Translation is Published.
      $translations = $handler->getTranslations();
      $langcode = $data['language'];

      // Hide link if entity has Moderation workflow
      // and Production entity is not published yet.
      if (!empty($entity->is_draft)) {
        $production = entity_load_single($data['entity_type'], $entity->edition_id);
        if (!$production->status) {
          return;
        }
        $handlerprod = entity_translation_get_handler($data['entity_type'], $production);
        $translations = $handlerprod->getTranslations();
      }
      // Hide link if the translation is not published.
      if (!empty($translations->data[$langcode]) && !empty($translations->data[$langcode]['status'])) {
        return $text;
      }
    }
  }

}
