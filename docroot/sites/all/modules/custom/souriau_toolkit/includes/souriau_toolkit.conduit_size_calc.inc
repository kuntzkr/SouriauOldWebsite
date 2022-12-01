<?php
/**
 * @file
 * Conduit size calculator tool.
 */

/**
 * The main callback page for the form.
 */
function souriau_toolkit_counduit_size_calc_main_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'souriau_toolkit', 'includes/souriau_toolkit.conduit_size_calc');
  // The rows and columns of the table are defined.
  $form['table'] = souriau_toolkit_counduit_size_calc_get_calculator_table();

  $form['wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'wrapper',
      ]
    ]
  ];

  // The fill rate dropdown is created.
  $form['wrapper']['fill_rate'] = [
    '#type' => 'select',
    '#title' => t('Select fill rate'),
    '#default_value' => '80',
    '#description' => t('80% is recommended. 98% in space limitation conditions'),
    '#attributes' => [
      'tabindex' => 11,
    ],
    '#ajax' => [
      'callback' => 'souriau_toolkit_counduit_size_calc_callback',
      'wrapper' => 'tools-form-result',
      'effect' => 'fade',
    ],
  ];

  // The option for fill rate is dynamically added.
  for ($option_value = 50; $option_value <= 90; $option_value += 10) {
    $form['wrapper']['fill_rate']['#options'][$option_value] = "$option_value%";
  }

  $form['wrapper']['fill_rate']['#options']['98'] = "98%";

  // Actions block, with submit button.
  $form['wrapper']['actions'] = [
    '#type' => 'actions',
    '#souriau_settings' => [
      'align' => 'center',
      'text_align' => 'center',
    ],
    '#weight' => 100,
  ];
  $form['wrapper']['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('CALCULATE', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#souriau_settings' => [
      'color' => 'blue',
    ],
    '#ajax' => [
      'callback' => 'souriau_toolkit_counduit_size_calc_callback',
      'wrapper' => 'tools-form-result',
      'effect' => 'fade',
    ],
  ];

  return $form;
}

/**
 * Helper function for generating calculator table.
 */
function souriau_toolkit_counduit_size_calc_get_calculator_table() {
  // The input fields are set inside a table.
  return [
    // Theme this part of the form as a table.
    '#theme' => 'conduit_size_form_table',
    // Pass header information to the theme function.
    '#header' => [
      ['data' => t('Wire Size:', [], ['context' => SOURIAU_COMMON_T_OTHER])],
      ['data' => t('1st', [], ['context' => SOURIAU_COMMON_T_OTHER])],
      ['data' => t('2nd', [], ['context' => SOURIAU_COMMON_T_OTHER])],
      ['data' => t('3rd', [], ['context' => SOURIAU_COMMON_T_OTHER])],
      ['data' => t('4th', [], ['context' => SOURIAU_COMMON_T_OTHER])],
      ['data' => t('5th', [], ['context' => SOURIAU_COMMON_T_OTHER])],
    ],
    // Rows in the form table.
    'rows' => [
      // Make it a tree for easier traversing of the entered values on submission.
      '#tree' => TRUE,
      // First row.
      'num_wires' => [
        'label' => [
          '#type' => 'markup',
          '#markup' => t('Number of wires:'),
        ],
        'one' => [
          '#type' => 'textfield',
          '#maxlength' => 3,
          '#size' => 3,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 1,
          ],
        ],
        'two' => [
          '#type' => 'textfield',
          '#maxlength' => 3,
          '#size' => 3,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 3,
          ],
        ],
        'three' => [
          '#type' => 'textfield',
          '#maxlength' => 3,
          '#size' => 3,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 5,
          ],
        ],
        'four' => [
          '#type' => 'textfield',
          '#maxlength' => 3,
          '#size' => 3,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 7,
          ],
        ],
        'five' => [
          '#type' => 'textfield',
          '#maxlength' => 3,
          '#size' => 3,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 9,
          ],
        ],
      ],
      'wire_diameter' => [
        'label' => [
          '#type' => 'markup',
          '#markup' => t('Wire diameter [inch]:'),
        ],
        'one' => [
          '#type' => 'textfield',
          '#maxlength' => 4,
          '#size' => 4,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 2,
          ],
        ],
        'two' => [
          '#type' => 'textfield',
          '#maxlength' => 4,
          '#size' => 4,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 4,
          ],
        ],
        'three' => [
          '#type' => 'textfield',
          '#maxlength' => 4,
          '#size' => 4,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 6,
          ],
        ],
        'four' => [
          '#type' => 'textfield',
          '#maxlength' => 4,
          '#size' => 4,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 8,
          ],
        ],
        'five' => [
          '#type' => 'textfield',
          '#maxlength' => 4,
          '#size' => 4,
          '#attributes' => [
            'autocomplete' => 'off',
            'tabindex' => 10,
          ],
        ],
      ],
    ],
  ];
}

/**
 * Callback for ajax submit.
 */
function souriau_toolkit_counduit_size_calc_callback($form, &$form_state) {
  $values = $form_state['values'];
  $validation = souriau_toolkit_counduit_size_calc_validate($values);
  $calculated_result = souriau_toolkit_counduit_size_calc_main_calculator($values);
  $commands = [];
  // Clear previous messages.
  $commands[] = ajax_command_remove('.pane-page-messages');
  if ($validation !== TRUE || !is_string($calculated_result)) {
    $commands[] = ($validation === TRUE) ? $calculated_result : $validation;
    $calculated_result = t('Sorry, calculation failed', [], ['context' => SOURIAU_COMMON_T_OTHER]);
    $commands[] = ajax_command_invoke('html, body', 'scrollTop', [0]);
  }
  else {
    $commands[] = souriau_common_ajax_set_message(
      '.pane-page-content',
      t('Calculation completed', [], ['context' => SOURIAU_COMMON_T_OTHER])
    );
  }

  $message = [
    '#markup' => '<div id="tools-form-result"><h4>' . $calculated_result . '</h4></div>'
  ];
  $commands[] = ajax_command_replace('#tools-form-result', drupal_render($message));
  $commands[] = ajax_command_souriau_common_jcf('refresh');

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Helper function for setting errors.
 */
function souriau_toolkit_counduit_size_calc_set_error($message) {
  return souriau_common_ajax_set_message('.pane-page-content', $message, 'error');
}

/**
 * The validation function for calculator.
 */
function souriau_toolkit_counduit_size_calc_validate($values) {
  $wire_validated = FALSE;
  $numeric_validated = FALSE;

  // Loop through the wires array.
  foreach ($values['rows']['num_wires'] as $wire) {
    // Check if atleast one wire is filled.
    if (!$wire_validated && !is_null($wire) && trim($wire) != '') {
      $wire_validated = TRUE;
    }

    // Check if the filled wire value is numeric.
    if (is_numeric($wire) || trim($wire) == '') {
      $numeric_validated = TRUE;
    }
    else {
      $numeric_validated = FALSE;
      break;
    }
  }

  // If wire numbers are numeric, then loop through the diameter array.
  if ($wire_validated && $numeric_validated) {
    foreach ($values['rows']['wire_diameter'] as $wire_diameter) {
      // Check if the diameters are numeric or not.
      if (is_numeric($wire_diameter) || trim($wire_diameter) == '') {
        $numeric_validated = TRUE;
        break;
      }
      else {
        $numeric_validated = FALSE;
      }
    }
  }

  // Set error if there any problem with wire value.
  if (!$wire_validated) {
    return souriau_toolkit_counduit_size_calc_set_error(
      t('Please fill atleast one value in the "Number of wires" boxes', [], ['context' => SOURIAU_COMMON_T_OTHER])
    );
  }

  // Set error if there is any problem with diameter value.
  if (!$numeric_validated) {
    return souriau_toolkit_counduit_size_calc_set_error(
      t('Please fill only numeric values in the boxes', [], ['context' => SOURIAU_COMMON_T_OTHER])
    );
  }

  return TRUE;
}

/**
 * The main submit handler.
 */
function souriau_toolkit_counduit_size_calc_main_calculator($values) {
  // Read the values from the input fields.
  $fill_rate = $values['fill_rate'];
  $num_wires = $values['rows']['num_wires'];
  $wire_diameter = $values['rows']['wire_diameter'];

  $total_wires = 0;
  $average_diameter = 0;

  // Calculate the total number of wires.
  foreach ($num_wires as $wire) {
    $total_wires += $wire;
  }

  if ($total_wires) {
    // Calculate the average diameter.
    foreach ($wire_diameter as $key => $diameter) {
      $average_diameter += ($diameter * $num_wires[$key]);
    }

    $average_diameter /= $total_wires;
    // Get the factor element.
    $factored = souriau_toolkit_counduit_size_calc_get_factored($total_wires, $average_diameter);

    if ($factored === FALSE) {
      return souriau_toolkit_counduit_size_calc_set_error(
        t('Too many wires', [], ['context' => SOURIAU_COMMON_T_OTHER])
      );
    }

    if (!is_null($factored)) {
      // Get the conduit size based on fill rate and factor.
      return souriau_toolkit_counduit_size_calc_get_conduit_size($fill_rate, $factored);
    }
  }

  return souriau_toolkit_counduit_size_calc_set_error(
    t('No Wires', [], ['context' => SOURIAU_COMMON_T_OTHER])
  );
}

/**
 * Function which returns the factor component for calculation.
 */
function souriau_toolkit_counduit_size_calc_get_factored($total_wires, $average_diameter) {
  $factored = NULL;

  if ($total_wires <= 2) {
    $factored = ($total_wires * 1.0) * ($average_diameter);
  }
  elseif ($total_wires <= 4) {
    $factored = (2 + (.2 * ($total_wires - 1))) * ($average_diameter);
  }
  elseif ($total_wires <= 6) {
    $factored = (2.7 + (.3 * ($total_wires - 5))) * ($average_diameter);
  }
  elseif ($total_wires <= 8) {
    $factored = (2.7 + (.3 * ($total_wires - 6))) * ($average_diameter);
  }
  elseif ($total_wires <= 10) {
    $factored = (3.8 + (.2 * ($total_wires - 9))) * ($average_diameter);
  }
  elseif ($total_wires <= 14) {
    $factored = (4 + (.15 * ($total_wires - 10))) * ($average_diameter);
  }
  elseif ($total_wires <= 15) {
    $factored = (4.8) * ($average_diameter);
  }
  elseif ($total_wires <= 20) {
    $factored = (5 + (.15 * ($total_wires - 16))) * ($average_diameter);
  }
  elseif ($total_wires <= 24) {
    $factored = (5.6 + (.1 * ($total_wires - 20))) * ($average_diameter);
  }
  elseif ($total_wires <= 28) {
    $factored = (6 + (.125 * ($total_wires - 24))) * ($average_diameter);
  }
  elseif ($total_wires <= 32) {
    $factored = (6.5 + (.1 * ($total_wires - 28))) * ($average_diameter);
  }
  elseif ($total_wires <= 36) {
    $factored = (6.9 + (.125 * ($total_wires - 32))) * ($average_diameter);
  }
  elseif ($total_wires <= 40) {
    $factored = (7.4 + (.075 * ($total_wires - 36))) * ($average_diameter);
  }
  elseif ($total_wires <= 80) {
    $factored = (7.7 + (.08 * ($total_wires - 40))) * ($average_diameter);
  }
  elseif ($total_wires <= 90) {
    $factored = (10.9 + (.07 * ($total_wires - 80))) * ($average_diameter);
  }
  elseif ($total_wires <= 125) {
    $factored = (11.6 + (.06 * ($total_wires - 90))) * ($average_diameter);
  }
  elseif ($total_wires <= 150) {
    $factored = (13.7 + (.052 * ($total_wires - 125))) * ($average_diameter);
  }
  elseif ($total_wires <= 200) {
    $factored = (15 + (.044 * ($total_wires - 150))) * ($average_diameter);
  }
  elseif ($total_wires <= 250) {
    $factored = (17.2 + (.042 * ($total_wires - 200))) * ($average_diameter);
  }
  elseif ($total_wires <= 300) {
    $factored = (19.3 + (.034 * ($total_wires - 200))) * ($average_diameter);
  }
  else {
    return FALSE;
  }

  return $factored;
}

/**
 * Function which returns the conduit size.
 *
 * @param string $fill_rate
 *   Fill rate.
 * @param string $factored
 *   Factored value.
 *
 * @return string
 *   Conduit size string.
 */
function souriau_toolkit_counduit_size_calc_get_conduit_size($fill_rate, $factored) {
  $conduit_size = NULL;
  foreach (souriau_toolkit_counduit_size_calc_get_standard_factored($fill_rate) as $key => $factored_standard) {
    if ($factored <= $factored_standard) {
      $conduit_size = souriau_toolkit_counduit_size_calc_get_standard($key);
      break;
    }
  }

  // If the result is null, show fill rate error message.
  if (is_null($conduit_size) && $fill_rate == 98) {
    return souriau_toolkit_counduit_size_calc_set_error(
      t('Too many wires', [], ['context' => SOURIAU_COMMON_T_OTHER])
    );
  }
  elseif (is_null($conduit_size)) {
    return souriau_toolkit_counduit_size_calc_set_error(
      t('@fill_rate% fill rate is too small', ['@fill_rate' => $fill_rate], ['context' => SOURIAU_COMMON_T_OTHER])
    );
  }

  return t('Conduit Size: @conduit_size', ['@conduit_size' => $conduit_size], ['context' => SOURIAU_COMMON_T_OTHER]);
}

/**
 * The function which defines the standard factors.
 *
 * @param string $fill_rate
 *   Fill rate.
 *
 * @return array
 *   Returns the factor components based on fill rate
 */
function souriau_toolkit_counduit_size_calc_get_standard_factored($fill_rate) {
  $factored_standard = [
    50 => [
      0.133,
      0.199,
      0.221,
      0.265,
      0.31,
      0.354,
      0.442,
      0.53,
      0.621,
      0.707,
      0.884,
      1.06,
      1.237,
      1.416,
    ],
    60 => [
      0.145,
      0.218,
      0.243,
      0.29,
      0.34,
      0.387,
      0.484,
      0.581,
      0.682,
      0.774,
      0.968,
      1.161,
      1.355,
      1.551,
    ],
    70 => [
      0.157,
      0.235,
      0.262,
      0.313,
      0.367,
      0.418,
      0.523,
      0.627,
      0.735,
      0.836,
      1.046,
      1.254,
      1.464,
      1.676,
    ],
    80 => [
      0.167,
      0.251,
      0.279,
      0.335,
      0.391,
      0.447,
      0.56,
      0.671,
      0.783,
      0.895,
      1.118,
      1.341,
      1.565,
      1.788,
    ],
    90 => [
      0.178,
      0.267,
      0.296,
      0.356,
      0.415,
      0.474,
      0.593,
      0.712,
      0.831,
      0.949,
      1.186,
      1.422,
      1.66,
      1.9,
    ],
    98 => [
      0.1868,
      0.2807,
      0.312,
      0.3746,
      0.4372,
      0.4998,
      0.625,
      0.7502,
      0.8754,
      1.0006,
      1.251,
      1.501,
      1.752,
      2.002,
    ],
  ];

  return $factored_standard[$fill_rate];
}

/**
 * The standard conduit size is defined here.
 *
 * @param string $key
 *   Array key for conduit size.
 *
 * @return string
 *   Returns the correct size for a factor key.
 */
function souriau_toolkit_counduit_size_calc_get_standard($key) {
  $conduit_size_standard = [
    '06 - 3/16 inches (I.D.)',
    '09 - 9/32 inches (I.D.)',
    '10 - 5/16inches (I.D.)',
    '12 - 3/8 inches (I.D.)',
    '14 - 7/16 inches (I.D.)',
    '16 - 1/2 inches (I.D.)',
    '20 - 5/8 inches (I.D.)',
    '24 - 3/4 inches (I.D.)',
    '28 - 7/8 inches (I.D.)',
    '32 - 1 inches (I.D.)',
    '40 - 1-1/4 inches (I.D.)',
    '48 - 1-1/2 inches (I.D.)',
    '56 - 1-3/4 inches (I.D.)',
    '64 - 2.000 inches (I.D.)',
  ];

  return $conduit_size_standard[$key];
}
