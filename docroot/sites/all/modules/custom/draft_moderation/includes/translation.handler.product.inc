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
class DraftModerationProductHandler extends EntityTranslationCommerceProductHandler {

  /**
   * Returns the default language for the wrapped entity type and bundle.
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

}
