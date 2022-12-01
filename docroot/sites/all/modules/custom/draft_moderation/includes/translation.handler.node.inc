<?php

/**
 * @file
 * Node translation handler for the entity translation module.
 */

/**
 * Node translation handler.
 *
 * Overrides default behaviours for Node properties.
 */
class DraftModerationNodeHandler extends EntityTranslationNodeHandler {

  /**
   * Return defaultLanguage.
   *
   * @see EntityTranslationHandlerInterface::getDefaultLanguage()
   */
  public function getDefaultLanguage() {
    if (!module_exists('domain_locale')) {
      return parent::getDefaultLanguage();
    }
    $settings = variable_get('entity_translation_settings_' . $this->entityType . '__' . $this->bundle, array());

    if (!empty($settings['default_language'])) {
      switch ($settings['default_language']) {
        case ENTITY_TRANSLATION_LANGUAGE_DEFAULT:
          // $default = domain_locale_language_default();
          $default_id = domain_default_id();
          $langcode = domain_conf_variable_get($default_id, 'language_default');
          if (!$langcode) {
            $default = domain_locale_language_default();
            $langcode = $default->language;
          }
          break;

        case ENTITY_TRANSLATION_LANGUAGE_CURRENT:
          $langcode = $GLOBALS[LANGUAGE_TYPE_CONTENT]->language;
          break;

        case ENTITY_TRANSLATION_LANGUAGE_AUTHOR:
          $langcode = $GLOBALS['user']->language;
          break;

        default:
          // An actual language code has been explicitly configured.
          $langcode = $settings['default_language'];
      }
    }
    else {
      // Fall back to the default language to keep backward compatibility.
      $default = domain_locale_language_default();
      $langcode = $default->language;
    }

    // Patch.
    if (is_object($langcode)) {
      $langcode = $langcode->language;
    }

    return $langcode;
  }

  /**
   * Set Translation as outdated.
   *
   * @see EntityTranslationHandlerInterface::setOutdated()
   */
  public function setOutdated($outdated) {
    if ($outdated) {
      $translations = $this->getTranslations();
      $form_langcode = $this->getFormLanguage();

      // Only if the original is changed
      // the other translations can be marked as outdated.
      if (empty($form_langcode) || $form_langcode != $translations->original) {
        return;
      }

      foreach ($translations->data as $langcode => &$translation) {
        if ($langcode != $form_langcode) {
          $translation['translate'] = 1;
        }
      }
    }
  }

  /**
   * Saves entity translation records to the storage.
   */
  protected function doSaveTranslations($translations, $table, $revision = FALSE) {
    // Delete and insert, rather than update, in case a value was added.
    $query = db_delete($table)
      ->condition('entity_type', $this->entityType)
      ->condition('entity_id', $this->entityId);
    // If we are storing translations for the current revision or we are
    // deleting the entity we should remove all translation data.
    $langcode = $translations->original;
    $hook = isset($translations->hook) ? $translations->hook : array();
    if ($revision && $this->isRevisionable() && (empty($hook[$langcode]['hook']) || $hook[$langcode]['hook'] != 'delete')) {
      $query->condition('revision_id', $this->revisionId);
    }
    $query->execute();

    if (count($translations->data)) {
      // @Important. Added Support for `workflow`.
      $columns = array(
        'entity_type',
        'entity_id',
        'revision_id',
        'language',
        'source',
        'uid',
        'status',
        'translate',
        'created',
        'changed',
        'workflow',
      );
      $query = db_insert($table)->fields($columns);

      // These values should override the translation ones as they are not
      // supposed to change.
      $overrides = array(
        'entity_type' => $this->entityType,
        'entity_id' => $this->entityId,
        'revision_id' => $this->isRevisionable() ? $this->revisionId : $this->entityId,
      );

      // These instead are just defaults.
      $defaults = array(
        'source' => '',
        'uid' => $GLOBALS['user']->uid,
        'translate' => 0,
        'status' => 0,
        'created' => REQUEST_TIME,
        'changed' => REQUEST_TIME,
        // By default all imported content is VALIDATED.
        'workflow' => DRAFT_MODERATION_WORKFLOW_VALIDATED,
      );

      foreach ($translations->data as $translation) {
        $translation = $overrides + $translation + $defaults;
        $query->values($translation);
      }

      $query->execute();
    }
  }

  /**
   * Entity Form submit handler.
   *
   * @see EntityTranslationHandlerInterface::entityFormSubmit()
   */
  public function entityFormSubmit($form, &$form_state) {
    if (!isset($form_state['values']['translation'])) {
      // Always publish the original values when we have no translations.
      $form_state['values']['translation'] = array('status' => TRUE);
    }
    $values = &$form_state['values']['translation'];

    if (!$this->isTranslationForm()) {
      // Inherit entity authoring information for the original values.
      $values['name'] = $form_state['values']['name'];
      if (!empty($form_state['values']['date'])) {
        $values['created'] = $form_state['values']['date'];
      }
    }

    $form_langcode = $this->getFormLanguage();
    $translations = $this->getTranslations();
    $is_translation = !empty($form_state['entity_translation']['is_translation']);
    $new_translation = !isset($translations->data[$form_langcode]);
    $values = isset($form_state['values']['translation']) ? $form_state['values']['translation'] : array();
    // Ensure every key has at least a default value. Subclasses may provide use
    // entity-specific values to alter them.
    $values += array(
      'status' => TRUE,
      'retranslate' => 0,
      'name' => $GLOBALS['user']->name,
    );

    if (!isset($translations->data[$form_langcode])) {
      // If we have a new translation the language is the original entity
      // language.
      $translation = $is_translation ? array('language' => $form_langcode, 'source' => $this->getSourceLanguage()) : array('language' => $form_langcode, 'source' => '');
    }
    else {
      $translation = $translations->data[$form_langcode];
    }

    if (isset($values['translate'])) {
      $translation['translate'] = intval($values['translate']);
    }
    else {
      $this->setOutdated($values['retranslate']);
    }

    // Handle possible language changes for the original values.
    if (!$is_translation) {
      $this->setOriginalLanguage($form_langcode);
    }

    $translation['status'] = intval($values['status']);
    $translation['uid'] = user_load_by_name($values['name'])->uid;
    $translation['created'] = empty($values['created']) ? REQUEST_TIME : strtotime($values['created']);

    // Default workflow_state.
    if (!isset($translation['workflow'])) {
      $translation['workflow'] = DRAFT_MODERATION_WORKFLOW_TO_VALIDATE;
    }

    // Set workflow value.
    if (isset($values['workflow'])) {
      $translation['workflow'] = $values['workflow'];
    }
    elseif (isset($form['translation']['workflow']['#value'])) {
      $translation['workflow'] = $form['translation']['workflow']['#value'];
    }

    $this->setTranslation($translation);

    // If no redirect has been explicitly set, go to the edit form for the
    // current form language.
    if ($new_translation && empty($form_state['redirect']) && !$this->isNewEntity()) {
      $form_state['redirect'] = $this->getEditPath($form_langcode);
    }
  }

}
