<?php

/**
 * @file
 * Contains SearchApiSouriauAlterLanguageControl.
 */

/**
 * Search API data alteration callback that filters items based on availible translations.
 */
class SearchApiSouriauAlterLanguageControl extends SearchApiAbstractAlterCallback {

  /**
   * Overrides SearchApiAbstractAlterCallback::supportsIndex().
   *
   * Only returns TRUE if the system is multilingual.
   *
   * @see drupal_multilingual()
   */
  public function supportsIndex(SearchApiIndex $index) {
    return drupal_multilingual();
  }

  /**
   * {@inheritdoc}
   */
  public function alterItems(array &$items) {
    foreach ($items as $i => &$item) {
      // Filter out items according to language, if translation unpublished.
      $entity_type = 'node';

      // Support Non-translatable entities in the one index.
      // NonTranslatable array:
      if (!isset($translatable[$item->type])) {
        $translatable[$item->type] = entity_translation_node_supported_type($item->type);
      }
      if (!$translatable[$item->type]) {
        continue;
      }

      $handler = entity_translation_get_handler($entity_type, $item);
      $translations = $handler->getTranslations();
      $lang_code = $item->language;
      if (!isset($translations->data[$lang_code])) {
        unset($items[$i]);
        continue;
      }
      $translation = $translations->data[$lang_code];
      if (!$translation['status']) {
        unset($items[$i]);
        continue;
      }
    }
  }

}
