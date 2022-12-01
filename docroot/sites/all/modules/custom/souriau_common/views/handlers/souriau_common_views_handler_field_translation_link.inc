<?php
/**
 * @file
 * Views plugin for translation link.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class souriau_common_views_handler_field_translation_link extends views_handler_field {

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
      $path = $handler->getViewPath();
      $links = array();
      if ($path) {
        $links = EntityTranslationDefaultHandler::languageSwitchLinks($path);
      }
      $languages = language_list();
      $language = isset($languages[$data['language']]) ? $languages[$data['language']] : language_default();
      $link = isset($links->links[$data['language']]['href']) ? $links->links[$data['language']] : array('href' => $path, 'language' => $language);

      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['language']  = $link['language'];
      $this->options['alter']['path']      = $link['href'];
      $this->options['alter']['query']     = drupal_get_destination();
      return $text;
    }
  }

}
