<?php

/**
 * @file
 * A specific handler for CH.
 */

$plugin = [
  'title' => t('Souriau add-on: Civility'),
  'format callback' => 'souriau_common_format_address_civility_generate',
  'type' => 'civility',
  'weight' => 100,
];

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function souriau_common_format_address_civility_generate(&$format, $address, $context = []) {
  $options = [
    'mr' => t('Mr.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'ms' => t('Ms.', [], ['context' => SOURIAU_COMMON_T_USER]),
  ];

  if ($context['mode'] == 'form') {

    $format['organisation_block']['#access'] = TRUE;

    $format['civility'] = [
      '#title' => t('Civility', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
      '#attributes' => [
        'class' => ['civility'],
      ],
      '#type' => 'select',
      '#required' => FALSE,
      '#weight' => -100,
      '#options' => $options,
      '#tag' => 'span',
      '#default_value' => isset($address['civility']) ? $address['civility'] : '',
      '#empty_value' => '',
    ];
    return;
  }
  $civility = isset($address['civility']) ? $address['civility'] : [''];

  // Add our own render callback for the format view.
  $format['name_block']['civility'] = [
    '#type' => 'addressfield_container',
    '#title' => t('Civility', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    '#weight' => -100,
    '#tag' => 'span',
    '#attributes' => ['class' => ['name-block', 'civility']],
    'civility' => [
      '#children' => check_plain($civility),
    ],
  ];

  $format['name_block']['#attributes']['class'][] = 'name-block';
  $format['name_block']['#weight'] = -80;
  $format['name_block']['first_name']['#prefix'] = ' ';
  $format['name_block']['first_name']['#tag'] = 'span';
  $format['name_block']['last_name']['#tag'] = 'span';
}
