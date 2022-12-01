<?php

/**
 * @file
 * Arinc 600 configurator tool.
 */

module_load_include('inc', 'souriau_toolkit', 'includes/souriau_toolkit.arinc_build.db');

/**
 * Return arinc form fields.
 */
function souriau_toolkit_arinc_main_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'souriau_toolkit', 'includes/souriau_toolkit.arinc_build');
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $empty_select = [t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER])];

  souriau_toolkit_arinc_wrappers($form, $values);
  souriau_toolkit_arinc_shell($form, $values);
  souriau_toolkit_arinc_mounting($form, $values, $empty_select);
  souriau_toolkit_arinc_sig_inserts($form, $values, $empty_select);
  souriau_toolkit_arinc_pow_inserts($form, $values, $empty_select);
  souriau_toolkit_arinc_package($form, $values, $empty_select);
  souriau_toolkit_arinc_submission($form, $values, $empty_select);

  return $form;
}

/**
 * Main function to call all shell section properties.
 */
function souriau_toolkit_arinc_wrappers(&$form, $values) {
  $form['wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'b-two-cols',
      ],
    ],
  ];

  $form['wrapper']['left'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'column',
        'a-left',
      ],
    ],
  ];

  $form['wrapper']['right'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'column',
        'a-right',
      ],
    ],
  ];

  $form['wrapper']['left']['shell_wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'box',
      ],
    ],
  ];

  $form['wrapper']['left']['shell_wrapper']['heading'] = [
    '#markup' => '<h2>' . t('Shell', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</h2>',
  ];

  $form['wrapper']['left']['polz_wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'box',
      ],
    ],
  ];

  $form['wrapper']['left']['polz_wrapper']['heading'] = [
    '#markup' => '<h2>' . t('Polarization', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</h2>',
  ];

  $form['wrapper']['right']['insert_wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'box',
      ],
    ],
  ];

  $form['wrapper']['right']['insert_wrapper']['heading'] = [
    '#markup' => '<h2>' . t('Insert Configuration', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</h2>',
  ];

  $form['wrapper']['right']['packaging_wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'box',
      ],
    ],
  ];

  $form['wrapper']['right']['packaging_wrapper']['heading'] = [
    '#markup' => '<h2>' . t('Packaging', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</h2>',
  ];

}

/**
 * Main function to call all shell section pending properties.
 */
function souriau_toolkit_arinc_shell(&$form, $values) {
  $form['wrapper']['left']['shell_wrapper']['basic_series'] = [
    '#type' => 'textfield',
    '#value' => 'SB6',
    '#title' => t('Basic Series', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#attributes' => ['readonly' => 'readonly'],
  ];

  $form['wrapper']['left']['shell_wrapper']['shell_size'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Shell Size', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => _souriau_toolkit_arinc_build_get_component_values('Shell Size'),
    '#required' => TRUE,
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_shell_size_callback',
      'effect' => 'fade',
    ],
  ];

  $shell_type_values = [];
  if (!empty($values['shell_size'])) {
    $shell_type_values = _souriau_toolkit_arinc_build_get_component_values('Shell Type', TRUE);
  }

  $form['wrapper']['left']['shell_wrapper']['shell_type'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Shell Type', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $shell_type_values,
    '#required' => TRUE,
    '#prefix' => '<div id="shell_type_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_contact_type_callback',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['left']['shell_wrapper']['connector'] = [
    '#type' => 'radios',
    '#title' => t('Connector', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => _souriau_toolkit_arinc_build_get_component_values('sealing type'),
    '#required' => TRUE,
    '#attributes' => [
      'class' => ['inline-radios'],
    ],
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_sealing_options_callback',
      'effect' => 'fade',
    ],
  ];

  $display = 'none';
  if (!empty($values['connector'])) {
    $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
    $connector_selected = $connector_options[$values['connector']];
    $display = ($connector_selected == 'Sealed') ? 'block' : 'none';
  }

  $form['wrapper']['left']['shell_wrapper']['sealing_type'] = [
    '#title' => t('Sealing Type (untick if necessary)', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#type' => 'checkboxes',
    '#options' => _souriau_toolkit_arinc_build_get_component_values('sealing feature', FALSE, FALSE, FALSE, _souriau_toolkit_arinc_build_get_component_parameters('Shell Type', $values['shell_type'])),
    '#prefix' => '<div id="arinc_sealing_feature_container" style="display:' . $display . '">',
    '#suffix' => '</div>',
    '#attributes' => [
      'class' => ['inline-checkboxes'],
    ],
    '#attributes' => ['checked' => 'checked'],
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_find_sealingcode_callback',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['left']['shell_wrapper']['plating'] = [
    '#type' => 'radios',
    '#title' => t('Plating', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => _souriau_toolkit_arinc_build_get_component_values('arinc plating'),
    '#required' => TRUE,
    '#attributes' => [
      'class' => ['inline-radios'],
    ],
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_find_sealingcode_callback',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['left']['shell_wrapper']['grounding'] = [
    '#type' => 'radios',
    '#title' => t('Grounding', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => _souriau_toolkit_arinc_build_get_component_values('grounding'),
    '#required' => TRUE,
    '#attributes' => [
      'class' => ['inline-radios'],
    ],
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_find_sealingcode_callback',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['left']['shell_wrapper']['contact_type'] = [
    '#type' => 'textfield',
    '#title' => t('Contact Type', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#prefix' => '<div id="contact_type_field_container">',
    '#suffix' => '</div>',
    '#attributes' => [
      'readonly' => 'readonly',
      'id' => 'contact_type_field_id',
    ],
    '#required' => TRUE,
  ];

}

/**
 * Main function to load mounting releases.
 */
function souriau_toolkit_arinc_mounting(&$form, $values, $empty_select) {
  $mounting_release_values = [];
  if (!empty($values['shell_type'])) {
    $shell_type_selected = _souriau_toolkit_arinc_build_get_component_parameters('Shell Type', $values['shell_type']);
    $connector_selected = NULL;
    if (!empty($values['connector'])) {
      $connector_selected = strtolower(_souriau_toolkit_arinc_build_get_component_parameters('sealing type', $values['connector']));
    }
    // Load mnt rel as per connector type and shell type.
    $mounting_release_values = _souriau_toolkit_arinc_build_get_mount_release_values('Contact Mounting and Release', $shell_type_selected, $connector_selected);
  }

  $form['wrapper']['left']['shell_wrapper']['contact_mounting_release'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Contact Mounting and Release', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $mounting_release_values,
    '#required' => TRUE,
    '#prefix' => '<div id="mounting_release_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_find_sealingcode_callback',
      'effect' => 'fade',
    ],
  ];

  $mounting_style_values = $empty_select;
  if (!empty($values['shell_type'])) {
    // Load mnt style codes according to shell size, type and connector opted.
    $shell_size_selected = _souriau_toolkit_arinc_build_get_component_parameters('Shell Size', $values['shell_size']);
    $shell_type_selected = _souriau_toolkit_arinc_build_get_component_parameters('Shell Type', $values['shell_type']);
    $connector_selected = strtolower(_souriau_toolkit_arinc_build_get_component_parameters('sealing type', $values['connector']));
    $connector_identified = _souriau_toolkit_arinc_build_get_identify_class($form, $values);
    if (!empty($shell_size_selected) && !empty($shell_type_selected) && !empty($connector_selected) && isset($connector_identified)) {
      $mounting_styles = _souriau_toolkit_arinc_build_get_mnt_options($shell_size_selected, $shell_type_selected, $connector_selected, $connector_identified);
      $mounting_style_values = (!empty($mounting_styles)) ? _souriau_toolkit_arinc_build_load_mnt_options('Mounting Style', $mounting_styles) : $mounting_style_values;
    }
  }

  $form['wrapper']['left']['shell_wrapper']['mounting_style'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Mounting Style', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $mounting_style_values,
    '#required' => TRUE,
    '#prefix' => '<div id="mounting_style_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_find_sealingcode_callback',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['left']['shell_wrapper']['sealing_code'] = [
    '#type' => 'textfield',
    '#title' => t('Connector Class', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#attributes' => [
      'readonly' => 'readonly',
      'id' => 'sealing_code_field_id',
    ],
    '#required' => TRUE,
    '#prefix' => '<div id="sealing_code_field_container">',
    '#suffix' => '</div>',
  ];

  $polarization_code_values = [];
  if (!empty($values['mounting_style'])) {
    $polarization_code_values = _souriau_toolkit_arinc_build_get_component_values('Polarization Code', TRUE);
  }

  $form['wrapper']['left']['polz_wrapper']['polarization_codes'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Polarization Code', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $polarization_code_values,
    '#required' => TRUE,
    '#prefix' => '<div id="polarization_codes_container">',
    '#suffix' => '</div>',
  ];

}

/**
 * Main function to call signal cavities and code.
 */
function souriau_toolkit_arinc_sig_inserts(&$form, $values, $empty_select) {
  // Find selected shell size.
  $shell_options = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
  $selected_shell_size = (!empty($values)) ? $shell_options[$values['shell_size']] : NULL;

  $cavity_a_values = [];
  if (!empty($values['shell_size'])) {
    $cavity_a_values = _souriau_toolkit_arinc_build_get_component_values('CavityA', FALSE, FALSE, $selected_shell_size);
  }

  $form['wrapper']['right']['insert_wrapper']['cavity_a'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Cavity A', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $cavity_a_values,
    '#required' => TRUE,
    '#prefix' => '<div id="cavity_a_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_verify_cavities',
      'effect' => 'fade',
    ],
  ];

  $cavity_b_values = [];
  if (!empty($values['shell_size'])) {
    $cavity_b_values = _souriau_toolkit_arinc_build_get_component_values('CavityB', FALSE, FALSE, $selected_shell_size);
  }

  $form['wrapper']['right']['insert_wrapper']['cavity_b'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Cavity B', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $cavity_b_values,
    '#required' => TRUE,
    '#prefix' => '<div id="cavity_b_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_verify_cavities',
      'effect' => 'fade',
    ],
  ];

  $cavity_d_values = [];
  $cavity_e_values = [];
  if ($selected_shell_size == 3) {
    $cavity_d_values = $empty_select + _souriau_toolkit_arinc_build_get_component_values('CavityD', FALSE, FALSE, $selected_shell_size);
    $cavity_e_values = $empty_select + _souriau_toolkit_arinc_build_get_component_values('CavityE', FALSE, FALSE, $selected_shell_size);
  }

  $form['wrapper']['right']['insert_wrapper']['cavity_d'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Cavity D', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $cavity_d_values,
    '#prefix' => '<div id="cavity_d_container" style="display:none;">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_verify_cavities',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['right']['insert_wrapper']['cavity_e'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Cavity E', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $cavity_e_values,
    '#prefix' => '<div id="cavity_e_container" style="display:none;">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_verify_cavities',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['right']['insert_wrapper']['signal_insert_code'] = [
    '#type' => 'textfield',
    '#title' => t('Source Code', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#attributes' => [
      'readonly' => 'readonly',
      'id' => 'signal_insert_field_id',
    ],
    '#required' => TRUE,
    '#prefix' => '<div id="signal_insert_field_container">',
    '#suffix' => '</div>',
  ];

}

/**
 * Main function to call power cavities and code.
 */
function souriau_toolkit_arinc_pow_inserts(&$form, $values, $empty_select) {
  $shell_options = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
  $selected_shell_size = (!empty($values)) ? $shell_options[$values['shell_size']] : NULL;

  $cavity_c_values = [];
  if (!empty($values['shell_size'])) {
    $cavity_c_values = _souriau_toolkit_arinc_build_get_component_values('CavityC', FALSE, FALSE, $selected_shell_size);
  }

  $form['wrapper']['right']['insert_wrapper']['cavity_c'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Cavity C', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $cavity_c_values,
    '#required' => TRUE,
    '#prefix' => '<div id="cavity_c_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_verify_cavities',
      'effect' => 'fade',
    ],
  ];

  $cavity_f_values = [];
  if ($selected_shell_size == 3) {
    $cavity_f_values = $empty_select + _souriau_toolkit_arinc_build_get_component_values('CavityF', FALSE, FALSE, $selected_shell_size);
  }

  $form['wrapper']['right']['insert_wrapper']['cavity_f'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Cavity F', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $cavity_f_values,
    '#prefix' => '<div id="cavity_f_container" style="display:none;">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_verify_cavities',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['right']['insert_wrapper']['power_insert_code'] = [
    '#type' => 'textfield',
    '#title' => t('Source Code', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#attributes' => [
      'readonly' => 'readonly',
      'id' => 'power_insert_field_id',
    ],
    '#required' => TRUE,
    '#prefix' => '<div id="power_insert_field_container">',
    '#suffix' => '</div>',
  ];

}

/**
 * Main function to call package properties.
 */
function souriau_toolkit_arinc_package(&$form, $values, $empty_select) {
  $form['wrapper']['right']['packaging_wrapper']['no_contacts_flag'] = [
    '#title' => t('Connector required to deliver', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#type' => 'radios',
    '#attributes' => [
      'class' => ['inline-radios'],
    ],
    '#options' => [
      'with_contacts' => t('With Contacts', [], ['context' => SOURIAU_COMMON_T_OTHER]),
      'without_contacts' => t('Without Contacts', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    ],
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_get_shell_packages',
      'effect' => 'fade',
    ],
  ];
  $pkg_display = 'none';
  if (!empty($values['no_contacts_flag']) && $values['no_contacts_flag'] == 'with_contacts') {
    $pkg_display = 'block';
  }

  $signal_pkg_values = [];

  if ($values['no_contacts_flag'] == 'with_contacts') {
    $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
    $connector_selected = $connector_options[$values['connector']];

    $shell_size = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
    $shell_size_selected = $shell_size[$values['shell_size']];

    $shell_type_selected = _souriau_toolkit_arinc_build_get_component_parameters('Shell Type', $values['shell_type']);
    $mounting_release_selected = _souriau_toolkit_arinc_build_get_component_parameters('Contact Mounting and Release', $values['contact_mounting_release']);

    $package_allowed = _souriau_toolkit_arinc_build_find_package($shell_size_selected, $mounting_release_selected,
    $shell_type_selected, $connector_selected, $values['signal_insert_code'], $values['power_insert_code']);
  }
  if ($values['no_contacts_flag'] == 'with_contacts' && !empty($package_allowed->signal_22) && $package_allowed->signal_22 == 'yes') {
    $signal_pkg_values = $empty_select + _souriau_toolkit_arinc_build_get_packages('signal contact package', 0, FALSE);
  }

  $form['wrapper']['right']['packaging_wrapper']['signal'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Signal', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $signal_pkg_values,
    '#prefix' => '<div id="packaging_signal_field_container" style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_load_contact_kinds',
      'effect' => 'fade',
    ],
  ];

  $signal_pkg_types = $empty_select;
  if ($values['no_contacts_flag'] == 'with_contacts' && !empty($values['signal']) && !empty($package_allowed->signal_22) && $package_allowed->signal_22 == 'yes') {
    $signal_pkg_types += _souriau_toolkit_arinc_build_get_contact_kind('signal contact kind', $shell_size_selected, $mounting_release_selected);
  }

  $form['wrapper']['right']['packaging_wrapper']['signal_types'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Kind', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $signal_pkg_types,
    '#prefix' => '<div id="packaging_signal_types_field_container"  style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_load_contact_sizes',
      'effect' => 'fade',
    ],
  ];

  $signal_type_sizes = $empty_select;
  if ($values['no_contacts_flag'] == 'with_contacts' && !empty($values['signal_types']) && ($mounting_release_selected == 'H' || $mounting_release_selected == 'K')) {
    $signal_type_sizes += _souriau_toolkit_arinc_build_get_contact_sizes('signal contact package', $mounting_release_selected);
  }
  $form['wrapper']['right']['packaging_wrapper']['signal_type_sizes'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('PC Tail Length', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $signal_type_sizes,
    '#prefix' => '<div id="packaging_signal_sizes_field_container"  style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_package_code',
      'effect' => 'fade',
    ],
  ];

  $power_pkg_values = [];
  if ($values['no_contacts_flag'] == 'with_contacts' && (!empty($package_allowed->power_16) || !empty($package_allowed->power_20)) && ($package_allowed->power_16 == 'yes' || $package_allowed->power_20 == 'yes')) {
    $power_pkg_values = $empty_select + _souriau_toolkit_arinc_build_get_packages('power contact package', 0, FALSE);
  }

  $form['wrapper']['right']['packaging_wrapper']['power'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Power', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $power_pkg_values,
    '#prefix' => '<div id="packaging_power_field_container"  style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_load_contact_kinds',
      'effect' => 'fade',
    ],
  ];

  $power_pkg_types = $empty_select;
  if ($values['no_contacts_flag'] == 'with_contacts' && !empty($values['power']) && (!empty($package_allowed->power_16) || !empty($package_allowed->power_20)) && ($package_allowed->power_16 == 'yes' || $package_allowed->power_20 == 'yes')) {
    $power_pkg_types += _souriau_toolkit_arinc_build_get_contact_kind('power contact kind', $shell_size_selected, $mounting_release_selected);
  }

  $form['wrapper']['right']['packaging_wrapper']['power_types'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Kind', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $power_pkg_types,
    '#prefix' => '<div id="packaging_power_types_field_container"  style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_load_contact_sizes',
      'effect' => 'fade',
    ],
  ];

}

/**
 * Main function to handle arinc form submission.
 */
function souriau_toolkit_arinc_submission(&$form, $values, $empty_select) {
  $power_type_sizes = $empty_select;
  $pkg_display = 'none';

  if (!empty($values['no_contacts_flag']) && $values['no_contacts_flag'] == 'with_contacts') {
    $pkg_display = 'block';
  }
  if ($values['no_contacts_flag'] == 'with_contacts') {
    $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
    $connector_selected = $connector_options[$values['connector']];

    $shell_size = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
    $shell_size_selected = $shell_size[$values['shell_size']];

    $shell_type_selected = _souriau_toolkit_arinc_build_get_component_parameters('Shell Type', $values['shell_type']);
    $mounting_release_selected = _souriau_toolkit_arinc_build_get_component_parameters('Contact Mounting and Release', $values['contact_mounting_release']);

    $package_allowed = _souriau_toolkit_arinc_build_find_package($shell_size_selected, $mounting_release_selected,
    $shell_type_selected, $connector_selected, $values['signal_insert_code'], $values['power_insert_code']);
  }

  if ($values['no_contacts_flag'] == 'with_contacts' && ($mounting_release_selected == 'H' || $mounting_release_selected == 'K')) {
    $power_type_sizes += _souriau_toolkit_arinc_build_get_contact_sizes('power contact package', $mounting_release_selected);
  }
  $form['wrapper']['right']['packaging_wrapper']['power_type_sizes'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('PC Tail Length', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $power_type_sizes,
    '#prefix' => '<div id="packaging_power_sizes_field_container"  style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_package_code',
      'effect' => 'fade',
    ],
  ];

  $coax_contacts = [];
  if ($values['no_contacts_flag'] == 'with_contacts' && (!empty($package_allowed->coax_5) || !empty($package_allowed->coax_1)) && ($package_allowed->coax_5 == 'yes' || $package_allowed->coax_1 == 'yes')) {
    $coax_contacts = $empty_select + _souriau_toolkit_arinc_build_get_packages('coax contact package', 0);
  }
  if ($values['no_contacts_flag'] == 'with_contacts' && (!empty($package_allowed->coax_5) || !empty($package_allowed->coax_1)) && ($package_allowed->coax_5 == 'no' && $package_allowed->coax_1 == 'no')) {
    $coax_contacts = $empty_select + _souriau_toolkit_arinc_build_get_packages('coax contact package', 'NO');
  }
  $form['wrapper']['right']['packaging_wrapper']['coax_contacts'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Coax', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $coax_contacts,
    '#required' => FALSE,
    '#prefix' => '<div id="packaging_coax_field_container"  style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_package_code',
      'effect' => 'fade',
    ],
  ];

  $quadrax_contacts = [];

  if ($values['no_contacts_flag'] == 'with_contacts' && !empty($package_allowed->quadrax) && $package_allowed->quadrax == 'yes') {
    $quadrax_contacts = $empty_select + _souriau_toolkit_arinc_build_get_packages('quadrax contact package', 0);
  }
  $form['wrapper']['right']['packaging_wrapper']['quadrax_contacts'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Quadrax', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $quadrax_contacts,
    '#required' => FALSE,
    '#prefix' => '<div id="packaging_quadrax_field_container"  style="display:' . $pkg_display . ';">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_arinc_build_package_code',
      'effect' => 'fade',
    ],
  ];

  $form['wrapper']['right']['packaging_wrapper']['package_code'] = [
    '#type' => 'textfield',
    '#title' => t('Source Code', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#attributes' => [
      'readonly' => 'readonly',
      'id' => 'package_code_field_id',
    ],
    '#required' => FALSE,
    '#prefix' => '<div id="package_code_field_container">',
    '#suffix' => '</div>',
  ];

  // Actions configurator block, with submit button.
  $form['actions'] = [
    '#type' => 'actions',
    '#souriau_settings' => [
      'align' => 'center',
      'text_align' => 'center',
    ],
    '#weight' => 100,
  ];

  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => t('Build your ARINC 600 Connector', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#souriau_settings' => [
      'color' => 'blue',
    ],
    '#prefix' => '<div id="arinc_button_field_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'callback' => 'souriau_toolkit_arinc_ref_callback',
      'wrapper' => 'tools-form-result',
      'effect' => 'fade',
    ],
  ];

  $form['hidden_sealing_code'] = [
    '#type' => 'hidden',
    '#prefix' => '<div id="hidden_sealing_container">',
    '#suffix' => '</div>',
  ];

  $form['hidden_signal_code'] = [
    '#type' => 'hidden',
    '#prefix' => '<div id="hidden_signal_code_container">',
    '#suffix' => '</div>',
  ];

  $form['hidden_power_code'] = [
    '#type' => 'hidden',
    '#prefix' => '<div id="hidden_power_code_container">',
    '#suffix' => '</div>',
  ];

}

/**
 * Ajax submit handler for Arinc 600 configurator PN build.
 */
function souriau_toolkit_arinc_ref_callback($form, &$form_state) {
  $commands = [];
  $commands[] = ajax_command_remove('.pane-page-messages');
  $values = $form_state['values'];

  if ($form_state['values']['no_contacts_flag'] == 'with_contacts' && empty($values['package_code'])) {
    $error_message = t("Codification is not currently available.
    Please contact Souriau to confirm availability and define full part numbering.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
    form_set_error('package_code', $error_message);
  }
  $errors = form_get_errors();
  if ($errors) {
    $error_messages = [
      '#theme' => 'item_list',
      '#items' => array_unique($errors),
    ];
    $commands[] = ajax_command_replace('#tools-form-result', souriau_tools_result_processor('', ''));
    $commands[] = souriau_common_ajax_set_message('.pane-page-content', drupal_render($error_messages), 'error');
    $commands[] = ajax_command_html('#souriau-toolkit-arinc-main-form', drupal_render($form));
    return ['#type' => 'ajax', '#commands' => $commands];
  }

  $shell_wrap = $form['wrapper']['left']['shell_wrapper'];
  $shell_type_selected = _souriau_toolkit_arinc_build_get_component_parameters('Shell Type', $values['shell_type']);
  $mounting_release_selected = _souriau_toolkit_arinc_build_get_component_parameters('Contact Mounting and Release', $values['contact_mounting_release']);
  $mounting_style_selected = _souriau_toolkit_arinc_build_get_component_parameters('Mounting Style', $values['mounting_style']);
  $polarization_code_selected = _souriau_toolkit_arinc_build_get_component_parameters('Polarization Code', $values['polarization_codes']);

  $pkg_comb = [
    $values['basic_series'],
    $values['sealing_code'],
    $shell_wrap['shell_size']['#options'][$values['shell_size']],
    $shell_type_selected,
    $mounting_release_selected,
    $mounting_style_selected,
    $values['power_insert_code'],
    $values['contact_type'],
    $values['signal_insert_code'],
    $polarization_code_selected,
    $values['package_code'],
  ];
  $arinc_part_number = implode('', $pkg_comb);
  $commands[] = ajax_command_replace('#tools-form-result', souriau_tools_result_processor('', $arinc_part_number));

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Ajax function to load shell size values.
 */
function souriau_toolkit_arinc_build_shell_size_callback($form, &$form_state) {
  $commands = [];
  $commands[] = ajax_command_replace('#shell_type_container', drupal_render($form['wrapper']['left']['shell_wrapper']['shell_type']));
  // Find selected shell size.
  $shell_options = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
  $selected_shell_size = $shell_options[$form_state['values']['shell_size']];

  $cavity_visibility = ($selected_shell_size == 3) ? 'show' : 'hide';
  // Loading cavities for all shells.
  foreach (['a', 'b', 'c', 'd', 'e', 'f'] as $cavity) {
    $commands[] = ajax_command_replace('#cavity_' . $cavity . '_container', drupal_render($form['wrapper']['right']['insert_wrapper']['cavity_' . $cavity]));
  }
  $commands[] = ajax_command_invoke('#cavity_d_container, #cavity_e_container, #cavity_f_container', $cavity_visibility);
  $commands = array_merge($commands, _souriau_toolkit_arinc_build_do_validation($form, $form_state));
  $commands[] = ajax_command_souriau_common_jcf('refresh');

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Ajax function to load contact type, sealing code if shell type is not null.
 */
function souriau_toolkit_arinc_build_contact_type_callback($form, &$form_state) {
  $commands = [];
  if (!empty($form_state['values']['shell_type'])) {
    $contact_type = _souriau_toolkit_arinc_build_get_contact_type($form_state['values']['shell_type'], 'Shell Type');
    $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
    $form['wrapper']['left']['shell_wrapper']['contact_type']['#value'] = $contact_type;
    if (!empty($connector_options[$form_state['values']['connector']])) {
      $connector_selected = $connector_options[$form_state['values']['connector']];
      $commands[] = ajax_command_replace('#arinc_sealing_feature_container', drupal_render($form['wrapper']['left']['shell_wrapper']['sealing_type']));
      $sealing_visibility = ($connector_selected == 'Sealed') ? 'show' : 'hide';
      $commands[] = ajax_command_invoke('#arinc_sealing_feature_container', $sealing_visibility);
    }
  }
  else {
    // Handling empty shell type case and filling up contact type.
    $form['wrapper']['left']['shell_wrapper']['contact_type']['#value'] = NULL;
  }
  $commands[] = ajax_command_replace('#contact_type_field_container', drupal_render($form['wrapper']['left']['shell_wrapper']['contact_type']));
  $commands[] = ajax_command_replace('#mounting_release_container', drupal_render($form['wrapper']['left']['shell_wrapper']['contact_mounting_release']));
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  $commands = array_merge($commands, _souriau_toolkit_arinc_build_do_validation($form, $form_state));

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Ajax function to show/hide sealing options according to connector opted.
 */
function souriau_toolkit_arinc_build_sealing_options_callback($form, &$form_state) {
  $commands = [];
  $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
  $connector_selected = $connector_options[$form_state['values']['connector']];
  $commands[] = ajax_command_replace('#arinc_sealing_feature_container', drupal_render($form['wrapper']['left']['shell_wrapper']['sealing_type']));
  $sealing_visibility = ($connector_selected == 'Sealed') ? 'show' : 'hide';
  $commands[] = ajax_command_invoke('#arinc_sealing_feature_container', $sealing_visibility);

  $commands[] = ajax_command_replace('#mounting_release_container', drupal_render($form['wrapper']['left']['shell_wrapper']['contact_mounting_release']));
  $commands = array_merge($commands, _souriau_toolkit_arinc_build_do_validation($form, $form_state));
  $commands[] = ajax_command_souriau_common_jcf('refresh');

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Ajax function to find and fill sealing level code.
 */
function souriau_toolkit_arinc_build_find_sealingcode_callback($form, &$form_state) {
  $commands = [];
  // Clear previous messages.
  $commands[] = ajax_command_remove('.pane-page-messages');
  $commands = array_merge($commands, _souriau_toolkit_arinc_build_do_validation($form, $form_state));

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * General function to build and verify sealing code combination.
 */
function _souriau_toolkit_arinc_build_get_verify_sealing($form, &$form_state) {
  $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
  $connector_selected = $connector_options[$form_state['values']['connector']];
  $commands = [];
  $sealing_type_opted = '';
  if ($connector_selected == 'Sealed') {
    $sealing_type_opted = implode("#", array_keys(array_filter($form_state['values']['sealing_type'])));
  }

  $values = $form_state['values'];
  $components = [
    $values['shell_size'],
    $values['shell_type'],
    $values['connector'],
    ($connector_selected == 'Sealed') ? $sealing_type_opted : '',
    $values['plating'],
    $values['grounding'],
  ];
  $comb_conditional_id = implode('#', array_filter($components));
  $sealing_code = _souriau_toolkit_arinc_build_verify_sealing_code($comb_conditional_id, 'Sealing level and Plating', 'sealing level');
  if (isset($sealing_code->value)) {
    // Filling sealing code field.
    form_clear_error();
    $form['wrapper']['left']['shell_wrapper']['sealing_code']['#value'] = $sealing_code->value;
    $form['hidden_sealing_code']['#value'] = $sealing_code->component_value_id;
    $form_state['values']['hidden_sealing_code'] = $sealing_code->component_value_id;
  }
  else {
    // Setting sealing code error.
    $error_message = t("Codification is not currently available.
    Please contact Souriau to confirm availability and define full part numbering.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
    form_set_error('sealing_code', $error_message);
    $commands[] = souriau_common_ajax_set_message('.pane-page-content', $error_message, 'error');

    // If error then make sealing code and hidden sealing code to null.
    $form['wrapper']['left']['shell_wrapper']['sealing_code']['#value'] = NULL;
    $form['hidden_sealing_code']['#value'] = NULL;
    $form_state['values']['hidden_sealing_code'] = NULL;
  }
  // Rendering sealing code.
  $commands[] = ajax_command_html('#sealing_code_field_container', drupal_render($form['wrapper']['left']['shell_wrapper']['sealing_code']));
  $commands[] = ajax_command_html('#hidden_sealing_container', drupal_render($form['hidden_sealing_code']));
  $commands[] = ajax_command_souriau_common_jcf('refresh');

  return $commands;
}

/**
 * General function to load.
 */
function _souriau_toolkit_arinc_build_load_mounting_style($form, $form_state) {
  $commands = [];
  // Replacing mnt style container with required m style values.
  $commands[] = ajax_command_replace('#mounting_style_container', drupal_render($form['wrapper']['left']['shell_wrapper']['mounting_style']));
  // Replacing polarization container with polarization codes.
  $commands[] = ajax_command_replace('#polarization_codes_container', drupal_render($form['wrapper']['left']['polz_wrapper']['polarization_codes']));
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  return $commands;
}

/**
 * Common validations for sealing, m release and m style.
 */
function _souriau_toolkit_arinc_build_do_validation($form, $form_state) {
  $commands = [];
  $shell_size = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
  $shell_size_selected = $shell_size[$form_state['values']['shell_size']];

  if (!empty($form_state['values']['shell_size']) && !empty($form_state['values']['shell_type'])) {
    // Verify sealing code combination if grounding option selected.
    if (!empty($form_state['values']['grounding'])) {
      $commands = array_merge($commands, _souriau_toolkit_arinc_build_get_verify_sealing($form, $form_state));
    }
    // Loading mounting style if mr not null.
    if (!empty($form_state['values']['contact_mounting_release'])) {
      $commands = array_merge($commands, _souriau_toolkit_arinc_build_load_mounting_style($form, $form_state));
    }
    // Verify signal and power insert code if cavity A,B or C selected not null.
    if ($shell_size_selected <= 2 && (!empty($form_state['values']['cavity_a']) && !empty($form_state['values']['cavity_b'])) || !empty($form_state['values']['cavity_c'])) {
      $commands = array_merge($commands, souriau_toolkit_arinc_build_do_validation_cavities($form, $form_state));
    }
    // Verify signal, power code if cavity A,B,D,E or C,F selected not null.
    if ($shell_size_selected == 3 && (!empty($form_state['values']['cavity_a']) && !empty($form_state['values']['cavity_b'])
      && !empty($form_state['values']['cavity_d']) && !empty($form_state['values']['cavity_e'])) || (!empty($form_state['values']['cavity_c']) && !empty($form_state['values']['cavity_f']))) {
      $commands = array_merge($commands, souriau_toolkit_arinc_build_do_validation_cavities($form, $form_state));
    }
  }

  return $commands;
}

/**
 * General function to verify signal and power cavities.
 */
function souriau_toolkit_arinc_build_verify_cavities($form, &$form_state) {
  $commands[] = ajax_command_remove('.pane-page-messages');
  $commands = souriau_toolkit_arinc_build_do_validation_cavities($form, $form_state);

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Fucntion to verify signal and power cavities.
 */
function souriau_toolkit_arinc_build_do_validation_cavities($form, &$form_state) {
  // Verify signal insert cavity only if cavity A and B selected.
  $commands = [];
  $commands[] = ajax_command_remove('.pane-page-messages');
  $shell_size = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
  $shell_size_selected = $shell_size[$form_state['values']['shell_size']];
  // Verify signal and power insert code if cavity A,B or C selected not null.
  if (!empty($form_state['values']['shell_type']) && $shell_size_selected <= 2 && (!empty($form_state['values']['cavity_a']) && !empty($form_state['values']['cavity_b'])) || !empty($form_state['values']['cavity_c'])) {
    $commands = array_merge($commands, souriau_toolkit_arinc_build_verify_signal_cavity($form, $form_state));
    if (!empty($form_state['values']['shell_type']) && !empty($form_state['values']['cavity_c'])) {
      $commands = array_merge($commands, souriau_toolkit_arinc_build_verify_power_cavity($form, $form_state));
    }
  }
  // Verify shell 3.
  if (!empty($form_state['values']['shell_type']) && $shell_size_selected == 3 && (!empty($form_state['values']['cavity_a']) && !empty($form_state['values']['cavity_b'])
    && !empty($form_state['values']['cavity_d']) && !empty($form_state['values']['cavity_e'])) || (!empty($form_state['values']['cavity_c']) && !empty($form_state['values']['cavity_f']))) {
    $commands = array_merge($commands, souriau_toolkit_arinc_build_verify_signal_cavity($form, $form_state));
    if (!empty($form_state['values']['shell_type']) && !empty($form_state['values']['cavity_c']) && !empty($form_state['values']['cavity_f'])) {
      $commands = array_merge($commands, souriau_toolkit_arinc_build_verify_power_cavity($form, $form_state));
    }
  }
  $commands[] = ajax_command_souriau_common_jcf('refresh');

  return $commands;
}

/**
 * Function to verify signal cavities and generate source code.
 */
function souriau_toolkit_arinc_build_verify_signal_cavity($form, &$form_state) {
  // Verify no restriction cases.
  $commands = [];
  $commands_a = _souriau_toolkit_arinc_build_verify_norestriction('CavityA', $form_state['values']['cavity_a']);
  $commands_b = _souriau_toolkit_arinc_build_verify_norestriction('CavityB', $form_state['values']['cavity_b']);
  $commands_d = _souriau_toolkit_arinc_build_verify_norestriction('CavityD', $form_state['values']['cavity_d']);
  $commands_e = _souriau_toolkit_arinc_build_verify_norestriction('CavityE', $form_state['values']['cavity_e']);
  $values = $form_state['values'];
  if (is_object($commands_a) || is_object($commands_b) || is_object($commands_d) || is_object($commands_e)) {
    $no_restr_components = [
      $values['shell_size'],
      $values['shell_type'],
      $values['cavity_a'],
      $values['cavity_b'],
      $values['cavity_d'],
      $values['cavity_e'],
    ];
    $conditional_ids = implode('#', array_filter($no_restr_components));
    $signal_source_obj = _souriau_toolkit_arinc_build_get_cavity_code($conditional_ids, 'Signal Insert', 'Signal Insert A and B');
  }
  if (empty($signal_source_obj)) {
    // Verify with out restriction cases.
    $restr_components = [
      $values['shell_size'],
      $values['shell_type'],
      $values['cavity_a'],
      $values['cavity_b'],
      $values['cavity_d'],
      $values['cavity_e'],
      $values['contact_mounting_release'],
      $values['hidden_sealing_code'],
    ];
    $conditional_ids = implode('#', array_filter($restr_components));
    $signal_source_obj = _souriau_toolkit_arinc_build_get_cavity_code($conditional_ids, 'Signal Insert', 'Signal Insert A and B');
  }

  if (empty($signal_source_obj)) {
    // Verify with out restriction cases.
    $restr_components = [
      $values['shell_size'],
      $values['shell_type'],
      $values['cavity_a'],
      $values['cavity_b'],
      $values['cavity_d'],
      $values['cavity_e'],
      $values['contact_mounting_release'],
    ];
    $conditional_ids = implode('#', array_filter($restr_components));
    $signal_source_obj = _souriau_toolkit_arinc_build_get_cavity_code($conditional_ids, 'Signal Insert', 'Signal Insert A and B');
  }
  if (isset($signal_source_obj->value)) {
    $form['wrapper']['right']['insert_wrapper']['signal_insert_code']['#value'] = $signal_source_obj->value;
    $form['hidden_signal_code']['#value'] = $signal_source_obj->component_value_id;
    $form_state['values']['hidden_signal_code'] = $signal_source_obj->component_value_id;
  }
  else {
    $form['wrapper']['right']['insert_wrapper']['signal_insert_code']['#value'] = NULL;
    $form['hidden_signal_code']['#value'] = NULL;
    $form_state['values']['hidden_signal_code'] = NULL;
    $error_message = t("Codification is not currently available.
    Please contact Souriau to confirm availability and define full part numbering.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
    form_set_error('signal_insert_code', $error_message);
    $commands[] = souriau_common_ajax_set_message('.pane-page-content', $error_message, 'error');
  }
  $commands[] = ajax_command_html('#signal_insert_field_container', drupal_render($form['wrapper']['right']['insert_wrapper']['signal_insert_code']));
  $commands[] = ajax_command_html('#hidden_signal_code_container', drupal_render($form['hidden_signal_code']));
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  return $commands;
}

/**
 * Function to verify power cavities and generate source code.
 */
function souriau_toolkit_arinc_build_verify_power_cavity($form, &$form_state) {
  // Verify no restriction cases.
  $commands = [];
  $commands_c = _souriau_toolkit_arinc_build_verify_norestriction('CavityC', $form_state['values']['cavity_c']);
  $commands_f = _souriau_toolkit_arinc_build_verify_norestriction('CavityF', $form_state['values']['cavity_f']);
  $values = $form_state['values'];
  if (is_object($commands_c) || is_object($commands_f)) {
    $no_restr_components = [
      $values['shell_size'],
      $values['shell_type'],
      $values['cavity_c'],
      $values['cavity_f'],
    ];
    $conditional_ids = implode('#', array_filter($no_restr_components));
    $power_source_obj = _souriau_toolkit_arinc_build_get_cavity_code($conditional_ids, 'Power Insert', 'Power Insert');
  }
  if (empty($power_source_obj)) {
    // Verify with m release restriction cases.
    $restr_components = [
      $values['shell_size'],
      $values['shell_type'],
      $values['cavity_c'],
      $values['cavity_f'],
      $values['contact_mounting_release'],
      $values['hidden_sealing_code'],
    ];
    $conditional_ids = implode('#', array_filter($restr_components));
    $power_source_obj = _souriau_toolkit_arinc_build_get_cavity_code($conditional_ids, 'Power Insert', 'Power Insert');
  }
  if (empty($power_source_obj)) {
    // Verify with m release restriction cases.
    $restr_components = [
      $values['shell_size'],
      $values['shell_type'],
      $values['cavity_c'],
      $values['cavity_f'],
      $values['contact_mounting_release'],
    ];
    $conditional_ids = implode('#', array_filter($restr_components));
    $power_source_obj = _souriau_toolkit_arinc_build_get_cavity_code($conditional_ids, 'Power Insert', 'Power Insert');
  }
  if (isset($power_source_obj->value)) {
    $form['wrapper']['right']['insert_wrapper']['power_insert_code']['#value'] = $power_source_obj->value;
    $form['hidden_power_code']['#value'] = $power_source_obj->component_value_id;
    $form_state['values']['hidden_power_code'] = $power_source_obj->component_value_id;
  }
  else {
    $form['wrapper']['right']['insert_wrapper']['power_insert_code']['#value'] = NULL;
    $form['hidden_power_code']['#value'] = NULL;
    $form_state['values']['hidden_power_code'] = NULL;
    $error_message = t("Codification is not currently available.
    Please contact Souriau to confirm availability and define full part numbering.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
    form_set_error('power_insert_code', $error_message);
    $commands[] = souriau_common_ajax_set_message('.pane-page-content', $error_message, 'error');
  }
  $commands[] = ajax_command_html('#power_insert_field_container', drupal_render($form['wrapper']['right']['insert_wrapper']['power_insert_code']));
  $commands[] = ajax_command_html('#hidden_power_code_container', drupal_render($form['hidden_power_code']));
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  return $commands;
}

/**
 * Function to load shell packages for the loaded config.
 */
function souriau_toolkit_arinc_build_get_shell_packages($form, &$form_state) {
  $commands = souriau_toolkit_arinc_build_get_package_parameters($form, $form_state);
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * New function for loading package parameters.
 */
function souriau_toolkit_arinc_build_get_package_parameters($form, &$form_state) {
  $commands = [];
  $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
  $connector_selected = $connector_options[$form_state['values']['connector']];

  $shell_size = $form['wrapper']['left']['shell_wrapper']['shell_size']['#options'];
  $shell_size_selected = $shell_size[$form_state['values']['shell_size']];

  $shell_type_selected = _souriau_toolkit_arinc_build_get_component_parameters('Shell Type', $form_state['values']['shell_type']);
  $mounting_release_selected = _souriau_toolkit_arinc_build_get_component_parameters('Contact Mounting and Release', $form_state['values']['contact_mounting_release']);

  if ($form_state['values']['no_contacts_flag'] == 'with_contacts' && !empty($shell_size_selected) && !empty($shell_type_selected)) {
    $package_allowed = _souriau_toolkit_arinc_build_find_package($shell_size_selected, $mounting_release_selected,
    $shell_type_selected, $connector_selected, $form_state['values']['signal_insert_code'], $form_state['values']['power_insert_code']);

    if (!empty($package_allowed->signal_22) && $package_allowed->signal_22 == 'yes') {
      $commands[] = ajax_command_replace('#packaging_signal_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['signal']));
      $commands[] = ajax_command_invoke('#packaging_signal_field_container', 'show');
    }

    if ((!empty($package_allowed->power_16) || !empty($package_allowed->power_20)) && ($package_allowed->power_16 == 'yes' || $package_allowed->power_20 == 'yes')) {
      $commands[] = ajax_command_replace('#packaging_power_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['power']));
      $commands[] = ajax_command_invoke('#packaging_power_field_container', 'show');
    }

    if ((!empty($package_allowed->coax_5) || !empty($package_allowed->coax_1)) && ($package_allowed->coax_5 == 'yes' || $package_allowed->coax_1 == 'yes')) {
      $commands[] = ajax_command_replace('#packaging_coax_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['coax_contacts']));
      $commands[] = ajax_command_invoke('#packaging_coax_field_container', 'show');
    }

    if ((!empty($package_allowed->coax_5) || !empty($package_allowed->coax_1)) && ($package_allowed->coax_5 == 'no' && $package_allowed->coax_1 == 'no')) {
      $commands[] = ajax_command_replace('#packaging_coax_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['coax_contacts']));
      $commands[] = ajax_command_invoke('#packaging_coax_field_container', 'show');
    }

    if (!empty($package_allowed->quadrax) && $package_allowed->quadrax == 'yes') {
      $commands[] = ajax_command_replace('#packaging_quadrax_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['quadrax_contacts']));
      $commands[] = ajax_command_invoke('#packaging_quadrax_field_container', 'show');
    }
  }
  else {
    $form['wrapper']['right']['packaging_wrapper']['package_code']['#value'] = NULL;
    $commands[] = ajax_command_replace('#packaging_signal_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['signal']));
    $commands[] = ajax_command_invoke('#packaging_signal_field_container', 'hide');
    $commands[] = ajax_command_replace('#packaging_signal_types_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['signal_types']));
    $commands[] = ajax_command_invoke('#packaging_signal_types_field_container', 'hide');
    $commands[] = ajax_command_replace('#packaging_signal_sizes_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['signal_type_sizes']));
    $commands[] = ajax_command_invoke('#packaging_signal_sizes_field_container', 'hide');
    $commands[] = ajax_command_replace('#packaging_power_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['power']));
    $commands[] = ajax_command_invoke('#packaging_power_field_container', 'hide');
    $commands[] = ajax_command_replace('#packaging_power_types_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['power_types']));
    $commands[] = ajax_command_invoke('#packaging_power_types_field_container', 'hide');
    $commands[] = ajax_command_replace('#packaging_power_sizes_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['power_type_sizes']));
    $commands[] = ajax_command_invoke('#packaging_power_sizes_field_container', 'hide');
    $commands[] = ajax_command_replace('#packaging_coax_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['coax_contacts']));
    $commands[] = ajax_command_invoke('#packaging_coax_field_container', 'hide');
    $commands[] = ajax_command_replace('#packaging_quadrax_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['quadrax_contacts']));
    $commands[] = ajax_command_invoke('#packaging_quadrax_field_container', 'hide');
    $commands[] = ajax_command_replace('#package_code_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['package_code']));
  }
  $commands[] = ajax_command_souriau_common_jcf('refresh');

  return $commands;
}

/**
 * Function to load contact kinds as per mounting release.
 */
function souriau_toolkit_arinc_build_load_contact_kinds($form, &$form_state) {
  $triggerer = $form_state['triggering_element']['#name'];
  $mounting_release_selected = _souriau_toolkit_arinc_build_get_component_parameters('Contact Mounting and Release', $form_state['values']['contact_mounting_release']);
  $packaging_type_render = $triggerer . '_types';

  if (!empty($triggerer)) {
    $with_flag = _souriau_toolkit_arinc_build_get_component_parameters($triggerer . ' contact package', $form_state['values'][$triggerer]);
  }

  $commands[] = ajax_command_replace('#packaging_' . $packaging_type_render . '_field_container',
  drupal_render($form['wrapper']['right']['packaging_wrapper'][$packaging_type_render]));
  $commands[] = ajax_command_invoke('#packaging_' . $packaging_type_render . '_field_container', 'show');

  // Contact type sizes display selection.
  $display_flag = ($with_flag == 'with' && $form_state['values'][$packaging_type_render] > 0 && ($mounting_release_selected == 'H' || $mounting_release_selected == 'K')) ? 'show' : 'hide';

  // Reset contact type sizes to default.
  if ($display_flag == 'hide') {
    $form['wrapper']['right']['packaging_wrapper'][$triggerer . '_type_sizes']['#value'] = NULL;
    $form_state['values'][$triggerer . '_type_sizes'] = NULL;
  }
  $commands[] = ($triggerer == 'signal') ? ajax_command_replace('#packaging_signal_sizes_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['signal_type_sizes'])) :
  ajax_command_replace('#packaging_power_sizes_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['power_type_sizes']));
  // Show or Hide signal and power type sizes.
  $commands[] = ($triggerer == 'signal') ? ajax_command_invoke('#packaging_signal_sizes_field_container', $display_flag) :
  ajax_command_invoke('#packaging_power_sizes_field_container', $display_flag);

  $commands[] = ajax_command_souriau_common_jcf('refresh');
  if (!empty($form_state['values']['coax_contacts']) || !empty($form_state['values']['quadrax_contacts'])) {
    $commands = array_merge($commands, souriau_toolkit_arinc_build_find_pacakge($form, $form_state));
  }

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Function to load contact sizes as per selected mounting release.
 */
function souriau_toolkit_arinc_build_load_contact_sizes($form, &$form_state) {
  $triggerer = $form_state['triggering_element']['#name'];
  $with_kind = NULL;
  $with_flag = NULL;
  if (!empty($triggerer)) {
    $packaging_type = ($triggerer == 'signal_types') ? 'signal' : 'power';
    $with_flag = _souriau_toolkit_arinc_build_get_component_parameters($packaging_type . ' contact package', $form_state['values'][$packaging_type]);
    $with_kind = _souriau_toolkit_arinc_build_get_component_parameters($packaging_type . ' contact kind', $form_state['values'][$triggerer]);
  }
  $mounting_release_selected = _souriau_toolkit_arinc_build_get_component_parameters('Contact Mounting and Release', $form_state['values']['contact_mounting_release']);
  // Contact type sizes display selection.
  $display_flag = ($with_flag == 'with' && $form_state['values'][$triggerer] > 0 && $with_kind != 'Power Crimp Contacts'
  && ($mounting_release_selected == 'H' || $mounting_release_selected == 'K')) ? 'show' : 'hide';
  // Reset contact type sizes to default.
  if ($display_flag == 'hide') {
    $form['wrapper']['right']['packaging_wrapper'][$packaging_type . '_type_sizes']['#value'] = NULL;
    $form_state['values'][$packaging_type . '_type_sizes'] = NULL;
  }
  $commands[] = ($triggerer == 'signal_types') ? ajax_command_replace('#packaging_signal_sizes_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['signal_type_sizes'])) :
  ajax_command_replace('#packaging_power_sizes_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['power_type_sizes']));
  // Show or Hide signal and power type sizes.
  $commands[] = ($triggerer == 'signal_types') ? ajax_command_invoke('#packaging_signal_sizes_field_container', $display_flag) :
  ajax_command_invoke('#packaging_power_sizes_field_container', $display_flag);

  $commands[] = ajax_command_souriau_common_jcf('refresh');
  if (!empty($form_state['values']['coax_contacts']) || !empty($form_state['values']['quadrax_contacts'])) {
    $commands = array_merge($commands, souriau_toolkit_arinc_build_find_pacakge($form, $form_state));
  }

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * General function to build package codes.
 */
function souriau_toolkit_arinc_build_package_code($form, &$form_state) {
  $commands = souriau_toolkit_arinc_build_find_pacakge($form, $form_state);
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Function to find packaging codes.
 */
function souriau_toolkit_arinc_build_find_pacakge($form, &$form_state) {
  $commands = [];
  $commands[] = ajax_command_remove('.pane-page-messages');
  $values = $form_state['values'];
  $pkg_wrap = $form['wrapper']['right']['packaging_wrapper'];
  $pkg_codes = NULL;
  $check_required = _souriau_toolkit_arinc_build_checking_required('Packaging Code 1st letter');
  if ($check_required) {
    $pkg_sec_comb = [
      $values['contact_mounting_release'],
      $values['connector'],
      $values['hidden_power_code'],
      $values['hidden_signal_code'],
      $values['signal'],
      $values['signal_types'],
      $values['signal_type_sizes'],
      $values['power'],
      $values['power_types'],
      $values['power_type_sizes'],
    ];
    $pkg_pattern = implode('#', array_filter($pkg_sec_comb));
    $pkg_codes = _souriau_toolkit_arinc_build_find_pkg_codes($pkg_pattern, 'Packaging Code 1st letter');
  }
  if (empty($pkg_codes)) {
    $pkg_comb = [
      $values['contact_mounting_release'],
      $values['signal'],
      $values['signal_types'],
      $values['signal_type_sizes'],
      $values['power'],
      $values['power_types'],
      $values['power_type_sizes'],
    ];
    $pkg_pattern = implode('#', array_filter($pkg_comb));
    $pkg_codes = _souriau_toolkit_arinc_build_find_pkg_codes($pkg_pattern, 'Packaging Code First letter');
  }
  $pkg_fl = _souriau_toolkit_arinc_build_get_component_parameters('Packaging Code 1st letter', $pkg_codes);
  $pkg_sl = (!empty($values['coax_contacts'])) ? _souriau_toolkit_arinc_build_get_component_parameters('coax contact package', $values['coax_contacts']) : '';
  if (!empty($values['quadrax_contacts'])) {
    $qudrax_code = _souriau_toolkit_arinc_build_get_component_parameters('quadrax contact package', $values['quadrax_contacts']);
    $pkg_sl = ($qudrax_code == 'Q') ? $qudrax_code : $pkg_sl;
  }
  $mrelease = _souriau_toolkit_arinc_build_get_component_parameters('Contact Mounting and Release', $values['contact_mounting_release']);
  $shellsize = _souriau_toolkit_arinc_build_get_component_parameters('Shell Size', $values['shell_size']);
  $pkg_count = _souriau_toolkit_arinc_build_package_validation($mrelease, $shellsize, $pkg_fl, $pkg_sl);
  $package_ln = $pkg_fl . $pkg_sl;
  if (!empty($pkg_fl) && !empty($pkg_sl) && $package_ln != 'LN' && $pkg_count) {
    $form['wrapper']['right']['packaging_wrapper']['package_code']['#value'] = $pkg_fl . $pkg_sl;
  }
  else {
    $form['wrapper']['right']['packaging_wrapper']['package_code']['#value'] = NULL;
    if (!empty($values['coax_contacts']) && !empty($values['quadrax_contacts'])
      && $pkg_wrap['quadrax_contacts']['#options'][$values['quadrax_contacts']] != 'Delivered with PC Tail Quadrax'
      && $pkg_wrap['coax_contacts']['#options'][$values['coax_contacts']] != 'delivered without #5 coax without #1 coax') {
      $error_message = t("This configuration is not possible, Please choose either Coax OR Quadrax
      contact at a time.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
    }
    else {
      $error_message = t("Codification is not currently available.
      Please contact Souriau to confirm availability and define full part numbering.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
    }
    form_set_error('package_code', $error_message);
    $commands[] = souriau_common_ajax_set_message('.pane-page-content', $error_message, 'error');
    $commands[] = ajax_command_replace('#tools-form-result', souriau_tools_result_processor('', ''));
  }
  $commands[] = ajax_command_replace('#package_code_field_container', drupal_render($form['wrapper']['right']['packaging_wrapper']['package_code']));
  $commands[] = ajax_command_invoke('#package_code_field_container', 'show');
  $commands[] = ajax_command_souriau_common_jcf('refresh');

  return $commands;
}

/**
 * General function to identify connector class.
 */
function _souriau_toolkit_arinc_build_get_identify_class($form, $values) {
  $connector_options = $form['wrapper']['left']['shell_wrapper']['connector']['#options'];
  $connector_selected = $connector_options[$values['connector']];
  $sealing_type_opted = '';
  if ($connector_selected == 'Sealed') {
    $sealing_type_opted = implode("#", array_keys(array_filter($values['sealing_type'])));
  }
  $components = [
    $values['shell_size'],
    $values['shell_type'],
    $values['connector'],
    ($connector_selected == 'Sealed') ? $sealing_type_opted : '',
    $values['plating'],
    $values['grounding'],
  ];
  $comb_conditional_id = implode('#', array_filter($components));
  $sealing_code = _souriau_toolkit_arinc_build_verify_sealing_code($comb_conditional_id, 'Sealing level and Plating', 'sealing level');
  $connector_class = (isset($sealing_code->value)) ? $sealing_code->value : NULL;

  return $connector_class;
}
