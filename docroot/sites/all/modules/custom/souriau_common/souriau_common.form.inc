<?php
/**
 * @file
 * Souriau Common forms.
 */

/**
 * Validator for Phone Number field.
 */
function souriau_common_form_phone_number_validate($element, &$form_state, $form) {
  global $language;

  if (!empty($element['#value']) || $element['#required']) {

    $patterns = variable_get('souriau_phone_number_element_validate_patterns', []);

    if (empty($patterns)) {
      return;
    }

    $pattern = '';
    if (isset($patterns[$language->language])) {
      $pattern = $patterns[$language->language];
    }
    elseif (isset($patterns['en-en'])) {
      $pattern = $patterns['en-en'];
    }

    if (empty($pattern)) {
      return;
    }

    $pattern = trim($pattern);
    $pattern = "/" . trim($pattern, "/") . "/";
    if (!preg_match($pattern, $element['#value'])) {
      form_error(
        $element,
        t('The phone number is not valid', [], ['context' => SOURIAU_COMMON_T_OTHER])
      );
    }
  }
}
