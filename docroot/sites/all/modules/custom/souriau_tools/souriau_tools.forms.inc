<?php
/**
 * @file
 * Tools forms.
 */

/**
 * Tools form caller.
 *
 * @param object $node
 *   Tool Node.
 * @param string $code
 *   Tool Code.
 *
 * @return array|string
 *   Form API array or HTML string.
 */
function souriau_tools_integration_form_caller($node, $code = '') {
  switch ($code) {
    case "cross_reference":
      module_load_include('inc', 'souriau_toolkit', 'includes/souriau_toolkit.cross_ref');
      return drupal_get_form("souriau_toolkit_cross_ref_main_form", $node);

    case "conduit_size_calc":
      module_load_include('inc', 'souriau_toolkit', 'includes/souriau_toolkit.conduit_size_calc');
      return drupal_get_form("souriau_toolkit_counduit_size_calc_main_form", $node);

    case "build_a_backshell":
      module_load_include('inc', 'souriau_toolkit', 'includes/souriau_toolkit.build_backshell');
      return drupal_get_form("souriau_toolkit_backshell_main_form", $node);

    case "arinc_600_configurator":
      module_load_include('inc', 'souriau_toolkit', 'includes/souriau_toolkit.arinc_build');
      return drupal_get_form("souriau_toolkit_arinc_main_form", $node);

    default:
      return drupal_get_form("souriau_tools_cross_sell_form", $node);
  }
}

/**
 * Implements hook_form.
 */
function souriau_tools_cross_sell_form($form, &$form_state, $node) {
  $form['wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'wrapper',
      ]
    ]
  ];

  $form['wrapper']['part_number'] = [
    '#type' => 'textfield',
    '#title' => 'Competitor Part Number',
  ];

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
    '#value' => t('FIND A MATCH', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#souriau_settings' => [
      'color' => 'blue',
    ],
    '#ajax' => [
      'callback' => 'souriau_tools_ajax_callback',
      'wrapper' => 'tools-form-result',
      'effect' => 'fade',
    ],
  ];
  return $form;
}
