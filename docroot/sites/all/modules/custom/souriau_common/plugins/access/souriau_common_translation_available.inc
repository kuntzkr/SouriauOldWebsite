<?php
/**
 * @file
 * Plugin to provide access control/visibility based on domain context.
 */

$plugin = array(
  'title' => t('Souriau Common: Translation available', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'description' => t('Souriau Common: Translation available', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
  'callback' => 'souriau_common_translation_available',
  'settings form' => 'souriau_common_translation_available_settings_form',
  'summary' => 'souriau_common_translation_available_summary',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

/**
 * Settings form for the access plugin.
 */
function souriau_common_translation_available_settings_form(&$form, &$form_state, $conf) {
  if (!module_exists('domain')) {
    $form['settings']['list'] = array(
      '#markup' => t('Domain module not enabled, match will always fail.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    );
  }

  return $form;
}

/**
 * Check for access.
 */
function souriau_common_translation_available($conf, $context) {
  if (!module_exists('entity_translation')) {
    return FALSE;
  }

  global $language_content;
  $access = user_access('view unpublished production editions');
  if (!$access) {
    if (empty($context->data)) {
      watchdog('souriau_common', 'Node: Translation available. Error: Empty context in access check.', array(), WATCHDOG_WARNING);
    }
    else {
      $t9n_handler = entity_translation_get_handler('node', $context->data);
      $translations = $t9n_handler->getTranslations();
      if ($data = $translations->data[$language_content->language]) {
        $access = !empty($data['status']);
      }
    }
  }

  return $access;
}

/**
 * Provide a summary description.
 */
function souriau_common_translation_available_summary($conf, $context) {
  if (!module_exists('entity_translation')) {
    return t('Entity translation module not enabled, access = FALSE.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
  }
  return t('Returns true if published translation available.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
}
