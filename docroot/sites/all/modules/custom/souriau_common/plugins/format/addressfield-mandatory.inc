<?php

/**
 * @file
 * A specific handler for CH.
 */

$plugin = array(
  'title' => t('Souriau add-on: set Mandatory Fields From BO'),
  'format callback' => 'souriau_common_format_address_mandatory',
  'type' => 'mandatory',
  'weight' => 120,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function souriau_common_format_address_mandatory(&$format, $address, $context = array()) {
  if ($context['mode'] != 'form') {
    // Nothing to do here.
    return;
  }

  $settings = $context['instance']['widget']['settings'];
  $required = $settings['required_fields'];
  foreach ($required as $key => $field) {
    foreach ($format as &$block) {
      if (isset($block[$key][$key])) {
        $block[$key][$key]['#required'] = !empty($field) ? TRUE : FALSE;
      }
      elseif (isset($block[$key])) {
        $block[$key]['#required'] = !empty($field) ? TRUE : FALSE;
      }
    }
  }
}
