<?php

/**
 * @file
 * Build a Backshell tool.
 */

module_load_include('inc', 'souriau_toolkit', 'includes/souriau_toolkit.build_backshell.db');

/**
 * Formbuilder for Build a Backshell.
 */
function souriau_toolkit_backshell_main_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'souriau_toolkit', 'includes/souriau_toolkit.build_backshell');
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $blank_select = [t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER])];
  $product_values = $blank_select + souriau_toolkit_build_backshell_get_product();

  $form['wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => [
        'wrapper',
      ],
    ],
  ];

  $form['wrapper']['product'] = [
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Select a Product', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#options' => $product_values,
    '#prefix' => '<div id="product_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_build_backshell_basic_callback',
      'wrapper' => 'series_container',
      'effect' => 'fade',
    ],
  ];

  $series_values = [];
  if (!empty($values['product'])) {
    $series_values = souriau_toolkit_build_backshell_get_series($values['product']);
  }
  $series_values = $blank_select + $series_values;

  $form['wrapper']['series'] = [
    '#type' => 'select',
    'multiple' => FALSE,
    '#title' => t('Select a Series', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#validated' => TRUE,
    '#options' => $series_values,
    '#prefix' => '<div id="series_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_build_backshell_basic_callback',
      'wrapper' => 'partnumber_container',
      'effect' => 'fade',
    ],
  ];

  $partnumber_values = [];
  if (!empty($values['product']) && !empty($values['series'])) {
    $partnumber_values = souriau_toolkit_build_backshell_get_partnumber($values['series']);
  }
  if ($values['series'] == 23) {
    $values['partnumber'] = '179';
  }
  $partnumber_values = $blank_select + $partnumber_values;

  $form['wrapper']['partnumber'] = [
    '#type' => 'select',
    'multiple' => FALSE,
    '#title' => t('Select the Basic Part Number', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#validated' => TRUE,
    '#options' => $partnumber_values,
    '#prefix' => '<div id="partnumber_container">',
    '#suffix' => '</div>',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'souriau_toolkit_build_backshell_component_callback',
      'wrapper' => 'component_container',
      'effect' => 'fade',
    ],
    '#attributes' => [
      'class' => ['partnumberCss'],
    ],
  ];

  $form['wrapper']['component'] = [
    '#type' => 'container',
    '#attributes' => [
      'id' => 'component_container',
    ],
  ];
  if (!empty($values['partnumber'])) {
    // Dynamicaly loading all component and drop down
    // for the selected part number.
    $action_visibility = NULL;
    $component_list = souriau_toolkit_build_backshell_get_component($values['partnumber']);
    if (!empty($component_list)) {
      $action_visibility = 'element-hidden';
      $form['wrapper']['component'] = souriau_toolkit_build_backshell_create_part_component($component_list, $values['partnumber']);
    }

    // Actions block, with submit button.
    $form['wrapper']['component']['actions'] = [
      '#type' => 'actions',
      '#souriau_settings' => [
        'align' => 'center',
        'text_align' => 'center',
      ],
      '#weight' => 100,
      '#attributes' => [
        'class' => [
          $action_visibility,
        ],
        'id' => 'btn_container',
      ],
    ];
    $form['wrapper']['component']['actions']['confirm'] = [
      '#type' => 'submit',
      '#value' => t('GET YOUR PART NUMBER', [], ['context' => SOURIAU_COMMON_T_OTHER]),
      '#souriau_settings' => [
        'color' => 'blue',
      ],
      '#prefix' => '<div class="w-btn-stretch">',
      '#suffix' => '</div>',
      '#ajax' => [
        'callback' => 'souriau_toolkit_build_backshell_create_part_callback',
        'wrapper' => 'tools-form-result',
        'effect' => 'fade',
      ],
    ];
  }
  $form['#attached']['js'][] = drupal_get_path("module", "souriau_toolkit") . "/js/souriau_toolkit_build_backshell.js";
  return $form;
}

/**
 * Callback for ajax Listing of components for Part number.
 */
function souriau_toolkit_build_backshell_basic_callback($form, &$form_state) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $list_select = [t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER])];
  $triggerer = $form_state['triggering_element']['#name'];
  $commands = [];
  $commands[] = ajax_command_remove('.pane-page-messages');
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  if ($triggerer == 'product') {
    // If the change event is Select a Product.
    $form['wrapper']['series']['#value'] = '0';
    $commands[] = ajax_command_replace('#series_container', drupal_render($form['wrapper']['series']));
    $form['wrapper']['partnumber']['#options'] = $list_select;
  }
  elseif ($triggerer == 'series') {
    // If the change event is Select a Series.
    if ($values['series'] == souriau_toolkit_build_backshell_get_exceptional_data('PROT_COVER')) {
      // Directly loading component Part for Product - Protective Cover.
      $partnumber_values = souriau_toolkit_build_backshell_get_partnumber($values['series']);
      foreach ($partnumber_values as $part_key => $part_value) {
        $part_id = $part_key;
      }
      $form['wrapper']['partnumber']['#options'] = $partnumber_values;
      $commands[] = ajax_command_replace('#partnumber_container', drupal_render($form['wrapper']['partnumber']));
      $commands[] = [
        'command' => 'changePartNumber',
        'part_id' => $part_id,
      ];
      return ['#type' => 'ajax', '#commands' => $commands];
    }
  }
  $commands[] = ajax_command_replace('#partnumber_container', drupal_render($form['wrapper']['partnumber']));
  $commands[] = ajax_command_invoke('#component_container, #btn_container, #tools-form-result', 'hide');

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Callback for ajax Listing of Series or Part number.
 */
function souriau_toolkit_build_backshell_component_callback($form, &$form_state) {
  variable_set('souriau_toolkit_backshell_error', []);
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $commands[] = ajax_command_remove('.pane-page-messages');
  $commands[] = ajax_command_invoke('#tools-form-result', 'hide');
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  $part_number = $form['wrapper']['partnumber']['#options'][$values['partnumber']];
  $series = $form['wrapper']['series']['#options'][$values['series']];
  $redirect_partnumber = souriau_toolkit_build_backshell_get_exceptional_data('PN_' . substr($series, 0, 2) . '_' . $part_number);
  if (empty($redirect_partnumber)) {
    $commands[] = ajax_command_replace('#component_container', drupal_render($form['wrapper']['component']));
    return ['#type' => 'ajax', '#commands' => $commands];
  }

  // Redirect to another Part number.
  $redirect_prod = souriau_toolkit_build_backshell_get_exceptional_data('PROD_SER_90');
  $form['wrapper']['product']['#value'] = $redirect_prod;
  $commands[] = ajax_command_replace('#product_container', drupal_render($form['wrapper']['product']));
  $series_values = souriau_toolkit_build_backshell_get_series($redirect_prod);
  $form['wrapper']['series']['#options'] = $series_values;
  $commands[] = ajax_command_replace('#series_container', drupal_render($form['wrapper']['series']));
  $partnumber_values = souriau_toolkit_build_backshell_get_partnumber(souriau_toolkit_build_backshell_get_exceptional_data('SER_90'));
  $form['wrapper']['partnumber']['#options'] = $partnumber_values;
  $commands[] = ajax_command_replace('#partnumber_container', drupal_render($form['wrapper']['partnumber']));
  $commands[] = [
    'command' => 'changePartNumber',
    'part_id' => $redirect_partnumber,

  ];
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Callback for ajax Listing for each component change.
 */
function souriau_toolkit_build_backshell_each_comp_callback($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $commands = [];
  $commands[] = ajax_command_invoke('#tools-form-result', 'hide');
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  $error_cid = variable_get('souriau_toolkit_backshell_error', []);
  $error_message = t("Error: that dropdown should do something, but it doesn't", [], ['context' => SOURIAU_COMMON_T_OTHER]);
  $triggerer = $form_state['triggering_element']['#name'];
  $prev_comp_arr = $form['wrapper']['component']['#param_curid_' . $triggerer];
  $next_comp_arr = (!empty($form['wrapper']['component']['#param_nextid_' . $triggerer])) ? $form['wrapper']['component']['#param_nextid_' . $triggerer] : [];
  $prev_comp_value = NULL;
  $next_comp = (isset($next_comp_arr->component_id)) ? $next_comp_arr->component_id : NULL;
  $part_id = $prev_comp_arr->part_id;
  $prev_comp_id = $prev_comp_arr->component_id;
  $part_group_arr = [];
  $redirect_value = NULL;
  if (isset($next_comp_arr->relation_component) && $next_comp_arr->relation_component > 0) {
    $prev_comp_value = souriau_toolkit_build_backshell_get_component_value($values[$next_comp_arr->relation_component]);
  }
  if ($values['product'] == souriau_toolkit_build_backshell_get_exceptional_data('PROD_5')) {
    $redirect_value = souriau_toolkit_build_backshell_get_component_value($values[$prev_comp_id]);
    $part_group_arr = souriau_toolkit_build_backshell_part_group_part($prev_comp_id, $redirect_value);
  }
  $commands = souriau_toolkit_build_backshell_handle_exceptional_cases($form, $form_state, $prev_comp_id, $prev_comp_value, $part_group_arr, $redirect_value);
  if (!empty($commands)) {
    return ['#type' => 'ajax', '#commands' => $commands];
  }
  if (!is_null($prev_comp_arr->error_value)) {
    $error_value_arr = explode(",", $prev_comp_arr->error_value);
    foreach ($error_value_arr as $error_value) {
      if ($error_value == $prev_comp_value) {
        // Dispaly error messages for the wrong selection.
        form_set_error($prev_comp_id, $error_message);
        $commands[] = ajax_command_html('#comp_' . $prev_comp_id . '_container', drupal_render($form['wrapper']['component'][$prev_comp_id]));
        $error_cid[$prev_comp_id] = $prev_comp_id;
        variable_set('souriau_toolkit_backshell_error', $error_cid);
        $commands[] = souriau_common_ajax_set_message('.pane-page-content', $error_message, 'error');
        $commands[] = ajax_command_invoke('#btn_container', 'hide');
        return ['#type' => 'ajax', '#commands' => $commands];
      }
    }
  }

  if (empty($values[$prev_comp_id]) && $prev_comp_arr->relation == 1) {
    $commands[] = souriau_common_ajax_set_message('.pane-page-content', $error_message, 'error');
    $commands[] = ajax_command_invoke('html, body', 'scrollTop', [0]);
  }
  else {
    if ((empty($values[$next_comp]) || $prev_comp_arr->relation > 0) && $values[$prev_comp_id] != '0') {
      $related_pos1 = (isset($next_comp_arr->relation_component)) ? $next_comp_arr->relation_component : NULL;
      $related_pos2 = (isset($next_comp_arr->relation_component_2)) ? $next_comp_arr->relation_component_2 : NULL;
      $related_comp_value = NULL;
      if ($related_pos2 > 0) {
        $related_comp_value = souriau_toolkit_build_backshell_get_component_value($values[$related_pos2]);
      }
      $next_comp_value_arr = souriau_toolkit_build_backshell_next_component_value($next_comp, $prev_comp_value, $related_pos1, $related_pos2, $related_comp_value);
      $commands = souriau_toolkit_build_backshell_get_component_list($form, $form_state, $part_id, $prev_comp_id, $next_comp, $related_pos1, $next_comp_value_arr);
      $commands[] = ajax_command_remove('.pane-page-messages');
    }
    elseif (empty($values[$prev_comp_id])) {
      $related_pos1 = (isset($prev_comp_arr->relation_component)) ? $prev_comp_arr->relation_component : NULL;
      $related_pos2 = (isset($prev_comp_arr->relation_component_2)) ? $prev_comp_arr->relation_component_2 : NULL;
      $related_comp_value = NULL;
      if ($related_pos1 > 0) {
        $prev_comp_value = souriau_toolkit_build_backshell_get_component_value($values[$related_pos1]);
      }
      if ($related_pos2 > 0) {
        $related_comp_value = souriau_toolkit_build_backshell_get_component_value($values[$related_pos2]);
      }
      $next_comp_value_arr = souriau_toolkit_build_backshell_next_component_value($prev_comp_id, $prev_comp_value, $related_pos1, $related_pos2, $related_comp_value);
      $next_list_values["#"] = t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      $form['wrapper']['component'][$prev_comp_id]['#value'] = '#';
      foreach ($next_comp_value_arr as $ncomp_value) {
        $next_list_values[$ncomp_value->component_value_id . "#" . $ncomp_value->value] = $ncomp_value->display_name;
      }
      $form['wrapper']['component'][$prev_comp_id]['#options'] = $next_list_values;
      $commands[] = ajax_command_replace('#comp_' . $prev_comp_id . '_container', drupal_render($form['wrapper']['component'][$prev_comp_id]));
    }
  }
  $error_cid = variable_get('souriau_toolkit_backshell_error', []);
  foreach ($error_cid as $err_key => $err_value) {
    if (!empty($values[$err_value]) && $err_value == $prev_comp_id) {
      // Remove error messages.
      form_clear_error($err_value, NULL);
      $commands[] = ajax_command_html('#comp_' . $err_value . '_container', drupal_render($form['wrapper']['component'][$err_value]));
      unset($error_cid[$err_key]);
    }
  }
  variable_set('souriau_toolkit_backshell_error', $error_cid);

  $commands[] = [
    'command' => 'afterAjaxCallComponent',
    'isRelation' => $prev_comp_arr->relation,
    'component_id' => $prev_comp_arr->component_id,
    'isErrorOn' => count($error_cid),
  ];

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Common code for component change function each_comp_callback.
 */
function souriau_toolkit_build_backshell_get_component_list($form, $form_state, $partid, $prev_compid, $nextcomp, $rel_pos1, $next_comp_values) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $commands = [];
  $commands[] = ajax_command_invoke('#btn_container, #tools-form-result', 'hide');
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  $blank_list = [t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER])];
  $next_show_list_comp = souriau_toolkit_build_backshell_next_component($partid, $nextcomp);
  $reset_id = $nextcomp;
  $next_list_values = [];
  // Assigning '' because this is the component value for 'N/A'.
  $prev_compvalue = souriau_toolkit_build_backshell_get_component_value($values[$prev_compid]);
  if (count($next_comp_values) == 1) {
    // Display next filed, if currently selected field has only one value.
    if (trim($next_comp_values[0]->value) != "") {
      $next_list_values = $blank_list;
    }
    if (!empty($next_show_list_comp)) {
      // Call back the same function for Assign values to
      // next next drop down list.
      $prev_null_value = '';
      $next_comp_arr = souriau_toolkit_build_backshell_next_component_value($next_show_list_comp[0]->component_id, $prev_null_value, $next_show_list_comp[0]->relation_component);
      $reset_id = $next_show_list_comp[0]->component_id;
      if (empty($values[$nextcomp]) || $next_show_list_comp[0]->relation_component > '0') {
        $commands += souriau_toolkit_build_backshell_get_component_list($form, $form_state, $partid, $nextcomp, $next_show_list_comp[0]->component_id, $next_show_list_comp[0]->relation_component, $next_comp_arr);
      }
    }
  }
  elseif (count($next_comp_values) > 1) {
    // If the list has more than one value.
    if ($rel_pos1 > 0 || empty($values[$nextcomp])) {
      // The input selection is mandatory and show button.
      $next_list_values["0"] = t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      $form['wrapper']['component'][$nextcomp]['#value'] = '0';
    }
    else {
      // This checking for display of button in case of
      // deselcting the non manadatory field.
      $next_list_values["#"] = t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      $form['wrapper']['component'][$nextcomp]['#value'] = '#';
    }
  }
  // This block will list the values for next component.
  if ($nextcomp == souriau_toolkit_build_backshell_get_exceptional_data('PROTECT_' . $prev_compvalue)) {
    $form['wrapper']['component'][$nextcomp]['#title'] = t('Select Your Protective Cover', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }

  foreach ($next_comp_values as $ncomp_value) {
    $next_list_values[$ncomp_value->component_value_id . "#" . $ncomp_value->value] = $ncomp_value->display_name;
  }
  $form['wrapper']['component'][$nextcomp]['#options'] = $next_list_values;
  $commands[] = ajax_command_replace('#comp_' . $nextcomp . '_container', drupal_render($form['wrapper']['component'][$nextcomp]));

  $reset_list_comp = souriau_toolkit_build_backshell_components_reset($partid, $reset_id);
  foreach ($reset_list_comp as $r_comp_value) {
    // Empty all other drop down list if the next component has
    // more than one dependet component, Example: Selfseating/36-001.
    if ($r_comp_value->component_id > $reset_id) {
      $form['wrapper']['component'][$r_comp_value->component_id]['#options'] = $blank_list;
      $commands[] = ajax_command_replace('#comp_' . $r_comp_value->component_id . '_container', drupal_render($form['wrapper']['component'][$r_comp_value->component_id]));
    }
  }

  $reset_related_comp = souriau_toolkit_build_backshell_components_reset($partid, $prev_compid);
  foreach ($reset_related_comp as $rel_comp_value) {
    // Empty all other drop down list if the changed drop down has
    // more than one dependet component, Example: Selfseating/57-001.
    if ($rel_comp_value->component_id > $nextcomp) {
      $commands[] = ajax_command_replace('#comp_' . $rel_comp_value->component_id . '_container', drupal_render($form['wrapper']['component'][$rel_comp_value->component_id]));
    }
  }
  return $commands;
}

/**
 * Common function to list component.
 */
function souriau_toolkit_build_backshell_create_part_component($component_list, $part_id) {
  $previous_cid = NULL;
  $previous_cid_val = NULL;
  $form['wrapper']['component'] = [
    '#prefix' => '<div id="component_container">',
    '#suffix' => '</div>',
  ];
  foreach ($component_list as $key => $component) {
    $component_values = [];
    $component_id = $component->component_id;
    $component_pos = $component->component_position;
    $comp_list_values = [t('Select', [], ['context' => SOURIAU_COMMON_T_OTHER])];
    $default_value = '0';
    if ($component->show_list == 1) {
      // This block will display all the drop down values
      // for first component.
      if ($key == 0) {
        $component_values = souriau_toolkit_build_backshell_get_first_compvalue($part_id, $component_id, $component_pos);
      }
      else {
        if ($previous_cid_val != NULL) {
          $component_values = souriau_toolkit_build_backshell_next_component_value($component_id, $previous_cid_val, $previous_cid);
          $previous_cid_val = NULL;
        }
      }
      foreach ($component_values as $comp_value) {
        if ($component->selected_value != NULL && $component->selected_value == $comp_value->value) {
          $previous_cid_val = $comp_value->value;
          $default_value = $comp_value->component_value_id . "#" . $comp_value->value;
        }
        $comp_list_values[$comp_value->component_value_id . "#" . $comp_value->value] = $comp_value->display_name;
      }
      $previous_cid = $component_id;
      $form['wrapper']['component'][$component_id] = [
        '#type' => 'select',
        'multiple' => FALSE,
        '#title' => $component->component_type,
        '#validated' => TRUE,
        '#options' => $comp_list_values,
        '#default_value' => $default_value,
        '#prefix' => '<div id="comp_' . $component_id . '_container">',
        '#suffix' => '</div>',
        '#ajax' => [
          'event' => 'change',
          'callback' => 'souriau_toolkit_build_backshell_each_comp_callback',
          'wrapper' => 'comp_' . $component_id . '_container',
          'effect' => 'fade',
        ],
      ];
      $form['wrapper']['component']['#param_curid_' . $component_id] = $component_list[$key];
      for ($i = $key + 1; $i < count($component_list); $i++) {
        if ($component_list[$i]->show_list == 1) {
          $form['wrapper']['component']['#param_nextid_' . $component_id] = $component_list[$i];
          break;
        }
      }
      $form['wrapper']['component']['#param_curid_' . $component_id] = $component_list[$key];
      for ($i = $key + 1; $i < count($component_list); $i++) {
        if ($component_list[$i]->show_list == 1) {
          $form['wrapper']['component']['#param_nextid_' . $component_id] = $component_list[$i];
          break;
        }
      }
    }
    else {
      if (!isset($form['wrapper']['component'][$previous_cid]['#description'])) {
        $form['wrapper']['component'][$previous_cid]['#description'] = $component->component_type;
      }
      else {
        $form['wrapper']['component'][$previous_cid]['#description'] .= $component->component_type;
      }
    }
  }
  return $form['wrapper']['component'];
}

/**
 * Function to generate Part number.
 */
function souriau_toolkit_build_backshell_create_part_callback($form, &$form_state) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $part_id = $values['partnumber'];
  $product_id = $values['product'];
  $part_text = $form['wrapper']['partnumber']['#options'][$part_id];
  $loopi = 0;
  $finish_part_msg = NULL;
  $err_relation_2 = NULL;
  $display_dimension = TRUE;
  $error_components = souriau_toolkit_build_backshell_get_error($part_id);
  if (!empty($error_components)) {
    $err_relation_2 = (!empty($error_components[0]->relation_id_2)) ? souriau_toolkit_build_backshell_get_component_value($values[$error_components[0]->relation_id_2]) : NULL;
  }
  $error_part_msg  = souriau_toolkit_build_backshell_get_error_exist($form, $form_state, $error_components);
  switch ($product_id) {
    case souriau_toolkit_build_backshell_get_exceptional_data('PROD_1'): $part_number = substr($form['wrapper']['series']['#options'][$values['series']], 0, 2);
      $part_code = $part_number . $form['wrapper']['partnumber']['#options'][$part_id];
      break;

    case souriau_toolkit_build_backshell_get_exceptional_data('PROD_2'): $part_number = $form['wrapper']['partnumber']['#options'][$part_id];
      $ret_part = souriau_toolkit_build_backshell_get_exceptional_data($part_number);
      if (!is_null($ret_part)) {
        $part_number = $form['wrapper']['partnumber']['#options'][$ret_part];
      }
      $part_code = strtolower($form['wrapper']['partnumber']['#options'][$part_id]);
      break;

    case souriau_toolkit_build_backshell_get_exceptional_data('PROD_3'): $part_number = substr($part_text, 0, 2);
      $ret_pos_to_merge = souriau_toolkit_build_backshell_get_exceptional_data('COMP_' . substr($part_text, 0, 2));
      if (!is_null($ret_pos_to_merge)) {
        $pos_to_merge = $ret_pos_to_merge;
      }
      else {
        $pos_to_merge = 2;
      }
      $part_code = strtolower($form['wrapper']['partnumber']['#options'][$part_id]);
      break;

    default:
      $part_number = $part_text;
      $part_code = str_replace("/", "_", $form['wrapper']['partnumber']['#options'][$part_id]);
  }
  $create_comp_arr = souriau_toolkit_build_backshell_get_create_part_components($part_id);
  foreach ($create_comp_arr as $create_key => $create_value) {
    if (souriau_toolkit_build_backshell_get_exceptional_data(souriau_toolkit_build_backshell_get_component_value($values[$create_value->component_id])) == $create_value->component_id) {
      $display_dimension = FALSE;
    }
    $part_value = trim(souriau_toolkit_build_backshell_get_component_value($values[$create_value->component_id]));
    if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_1') && ($create_key == 1 || count($create_comp_arr) == 1)) {
      if (count($create_comp_arr) == 1) {
        $part_number .= '-';
      }
      $ret_component = souriau_toolkit_build_backshell_get_exceptional_data(str_replace("/", "_", $part_text));
      if (!is_null($ret_component)) {
        $ret_value = souriau_toolkit_build_backshell_get_component_value($values[$ret_component]);
        $part_code = substr($form['wrapper']['series']['#options'][$values['series']], 0, 2) . $ret_value;
        $part_number .= $ret_value;
      }
      else {
        $part_number .= $form['wrapper']['partnumber']['#options'][$part_id];
      }
    }
    if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_1') && $create_value->component_type_id == souriau_toolkit_build_backshell_get_exceptional_data("COMP_TYPE_" . $create_value->component_type_id)) {
      $finish_part_msg = souriau_toolkit_build_backshell_finish_part_msg($part_value);
    }
    if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_2') && !empty(souriau_toolkit_build_backshell_get_exceptional_data($part_value))) {
      $part_number = str_replace("-", "", $part_number) . 'G';
      break;
    }
    if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_3') && $loopi == $pos_to_merge) {
      $part_number .= substr($part_text, 2);
    }
    $part_number .= $create_value->special_character_prefix;
    if ($create_value->use_for_part_build == 'Yes') {
      $part_number .= $part_value;
    }
    $loopi++;

  }
  if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_1') && souriau_toolkit_build_backshell_get_exceptional_data("PART_03" . $part_text) == $err_relation_2 && $err_relation_2 != NULL && empty($finish_part_msg)) {
    $finish_part_msg = t("For part number: @part_number Shell Size 08 will require a type 2 adapter.", ['@part_number' => $part_number], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  $partnumber_desc_left = souriau_toolkit_build_backshell_get_partnumber_desc($form, $form_state, $create_comp_arr);
  $partnumber_desc_right = ($display_dimension) ? souriau_toolkit_build_backshell_get_partnumber_dimension($form, $form_state) : NULL;
  $partnumber_desc_footer = souriau_toolkit_build_backshell_get_partnumber_footer($product_id, $part_id);
  $image_folder = 'public://backshell_images/';
  $image = [
    '#type' => 'figure_pic',
    '#image' => ['uri' => $image_folder . $part_code . ".gif"],
    '#attributes' => [
      'title' => $part_code,
      'alt' => $part_code,
    ],
  ];
  $partnumber_image = '<div class="wysiwyg">' . drupal_render($image) . '</div>';
  $table_info = theme('table', [
    'rows' => [
      'data' => [$partnumber_desc_left, $partnumber_desc_right],
    ],
    'attributes' => ['cellpadding' => 15],
  ]
  );
  $partnumber_image .= '<div>' . render($table_info) . '</div>';
  $partnumber_image .= $partnumber_desc_footer;

  $commands[] = ajax_command_invoke('#tools-form-result', 'show');
  $commands[] = ajax_command_replace('#tools-form-result', souriau_tools_result_processor(NULL, $part_number));
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  $commands[] = [
    'command' => 'backshell_error_display',
    'error_message' => $error_part_msg,
    'finish_part_msg' => $finish_part_msg,
    'partnumber_image' => $partnumber_image,
  ];
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Function to get redirect values in case of exceptional data.
 */
function souriau_toolkit_build_backshell_get_exceptional_data($reference_name) {
  $except_id = NULL;
  $except_data_arr = souriau_toolkit_build_backshell_get_exceptions_data($reference_name);
  if (!empty($except_data_arr)) {
    $except_id = $except_data_arr[0]->reference_id;
  }
  return $except_id;
}

/**
 * Common function to get component values.
 */
function souriau_toolkit_build_backshell_get_component_value($comp_value) {
  if (strstr($comp_value, '#') === FALSE) {
    return;
  }

  $ret_comp_value_arr = explode("#", $comp_value);
  return $ret_comp_value_arr[1];
}

/**
 * Common function to check error exist for part.
 */
function souriau_toolkit_build_backshell_get_error_exist($form, $form_state, $error_components) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $error_exist = NULL;
  $error_part_msg = NULL;
  if (!empty($error_components)) {
    $err_relation_3 = NULL;
    $err_relation_1 = (!empty($error_components[0]->relation_id_1)) ? souriau_toolkit_build_backshell_get_component_value($values[$error_components[0]->relation_id_1]) : NULL;
    $err_relation_2 = (!empty($error_components[0]->relation_id_2)) ? souriau_toolkit_build_backshell_get_component_value($values[$error_components[0]->relation_id_2]) : NULL;
    $err_comp_val = (int) souriau_toolkit_build_backshell_get_component_value($values[$error_components[0]->component_id]);
    $config_val = ($error_components[0]->config_component > 0) ? souriau_toolkit_build_backshell_get_component_value($values[$error_components[0]->config_component]) : NULL;
    $min_length_value = $error_components[0]->min_length_value;
    $min_length_comp_val = ($error_components[0]->length_component > 0) ? souriau_toolkit_build_backshell_get_component_value($values[$error_components[0]->length_component]) : NULL;
    $component_id = $error_components[0]->component_id;
    if ($error_components[0]->relation_id_3 > 0) {
      $err_relation_3 = (int) souriau_toolkit_build_backshell_get_component_value($values[$error_components[0]->relation_id_3]);
      $error_data_exist = souriau_toolkit_build_backshell_get_error_data($component_id, $err_relation_1, $err_relation_2, $err_relation_3, $error_components[0]->error_compare);
    }
    else {
      $err_relation_1 = (is_numeric($err_relation_1)) ? (int) $err_relation_1 : $err_relation_1;
      $err_relation_2 = (is_numeric($err_relation_2)) ? (int) $err_relation_2 : $err_relation_2;
      $error_data_exist = souriau_toolkit_build_backshell_get_error_data($component_id, $err_relation_1, $err_relation_2, $err_relation_3, $error_components[0]->error_compare);
    }
    switch ($error_components[0]->error_compare) {
      case '>':
        $error_exist = (isset($error_data_exist[0]->component_value) && $err_comp_val > (int) $error_data_exist[0]->component_value) ? 1 : NULL;
        break;

      case '<':
        $error_exist = (isset($error_data_exist[0]->component_value) && $err_comp_val < (int) $error_data_exist[0]->component_value) ? 1 : NULL;
        break;

      default:
        $error_exist = (isset($error_data_exist[0]->component_value) && $err_comp_val == (int) $error_data_exist[0]->component_value) ? 1 : NULL;
    }
    if ($error_exist == 1) {
      if ($config_val == souriau_toolkit_build_backshell_get_exceptional_data('CONFIG_S')) {
        if ($min_length_comp_val < $min_length_value) {
          $error_part_msg = t("The part number displayed above is invalid. When a style 2-assembly is required to meet specific application requirements, the minimum order length is @length inches. Use code @min_length or larger for the length designator in the part number selection option to correct the displayed part number shown above.", ['@length' => $min_length_value / 2, '@min_length' => $min_length_value], ['context' => SOURIAU_COMMON_T_OTHER]);
        }
        else {
          $error_part_msg = t("The above selected part number entry size exceeds the connector insert diameter and therefore a type 2 adapter assembly will be supplied. Please refer to the individual drawing for dimensional data requirements.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
        }
      }
      elseif ($config_val == '' &&  $error_components[0]->message_type == 2) {
        $error_part_msg = t("The part number displayed above is invalid. The entry size exceeds the connector insert diameter, please select a smaller entry size in the part number selection option to correct the displayed part number shown above.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
      }
      elseif ($values['product'] > souriau_toolkit_build_backshell_get_exceptional_data('PROD_3')) {
        $error_part_msg = t("For this shell size and cable entry configuration a style 2 will be supplied", [], ['context' => SOURIAU_COMMON_T_OTHER]);
      }
      else {
        $error_part_msg = t("The above selected part number entry size exceeds the connector insert diameter, therefore a type 2 assembly will be supplied. Please refer to the individual drawing for the type 2 dimensional data requirements. (envelope dimensions will not apply please consult factory).", [], ['context' => SOURIAU_COMMON_T_OTHER]);
      }
    }
  }
  return $error_part_msg;
}

/**
 * Function to get Finish component errors.
 */
function souriau_toolkit_build_backshell_finish_part_msg($part_value) {
  $finish_part_msg = NULL;
  if (($part_value == souriau_toolkit_build_backshell_get_exceptional_data('FINISH_A')) || ($part_value == souriau_toolkit_build_backshell_get_exceptional_data('FINISH_AB'))) {
    $finish_part_msg = t("Anodize finishes noted suited for EMI / RFI shielding or grounding applications.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  if (($part_value == souriau_toolkit_build_backshell_get_exceptional_data('FINISH_P'))) {
    $finish_part_msg = t("Passivate(P) finish is applicable to corrosion resistant steel backsheels only. Consult factory for product availability", [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  if (($part_value == souriau_toolkit_build_backshell_get_exceptional_data('FINISH_CS'))) {
    $finish_part_msg = t("For the choosen finish, the barrier sealant stripes are used to isolate the finish materials. Refer to product series application usage.", [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  return $finish_part_msg;
}

/**
 * Function to get Description of part number.
 */
function souriau_toolkit_build_backshell_get_partnumber_desc($form, $form_state, $create_comp_arr) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $part_id = $values['partnumber'];
  $product_id = $values['product'];
  $part_text = $form['wrapper']['partnumber']['#options'][$part_id];
  $part_desc_array = [];
  $k = 0;
  $part_desc_array[$k]['label'] = t("Product Series", [], ['context' => SOURIAU_COMMON_T_OTHER]);
  if ((int) $product_id > (int) souriau_toolkit_build_backshell_get_exceptional_data('PROD_3')) {
    $part_desc_array[$k]['label'] = t("Product", [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  $part_desc_array[$k]['value'] = souriau_toolkit_build_backshell_get_part_desc_content($form, $form_state, $product_id);
  $part_desc_array[$k]['eq'] = '=';
  $part_desc_array[$k]['level'] = 1;
  $part_desc_array[$k]['prefix'] = NULL;
  $part_desc_array[$k]['suffix'] = NULL;
  $k++;
  if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_2')  || $product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_3')) {
    $part_desc_array[$k]['label'] = t("Basic Part Number", [], ['context' => SOURIAU_COMMON_T_OTHER]);
    $part_desc_array[$k]['eq'] = '=';
    if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_2')) {
      $part_desc_array[$k]['value'] = $form['wrapper']['partnumber']['#options'][$part_id];
    }
    else {
      $part_desc_array[$k]['value'] = substr($part_text, 2);
    }
    $part_desc_array[$k]['level'] = 1;
    $part_desc_array[$k]['prefix'] = NULL;
    $part_desc_array[$k]['suffix'] = NULL;
    $k++;
  }
  foreach ($create_comp_arr as $create_key => $create_value) {
    $eq = '=';
    $prefix_description = NULL;
    $suffix_description = NULL;
    if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_1') && ($create_key == 1 || count($create_comp_arr) == 1)) {
      $part_desc_array[$k]['label'] = t("Basic Part Number", [], ['context' => SOURIAU_COMMON_T_OTHER]);
      $part_desc_array[$k]['eq'] = '=';
      if ($part_id == souriau_toolkit_build_backshell_get_exceptional_data('PART_ID_' . $part_id)) {
        $compval = souriau_toolkit_build_backshell_get_exceptional_data('COMP_285');
        $part_desc_array[$k]['value'] = trim(souriau_toolkit_build_backshell_get_component_value($values[$compval]));
      }
      else {
        $part_desc_array[$k]['value'] = $form['wrapper']['partnumber']['#options'][$part_id];
      }
      $part_desc_array[$k]['level'] = 1;
      $part_desc_array[$k]['prefix'] = NULL;
      $part_desc_array[$k]['suffix'] = NULL;
      $k++;
    }
    $comp_pos_value = trim(souriau_toolkit_build_backshell_get_component_value($values[$create_value->component_id]));
    $part_label = souriau_toolkit_build_backshell_part_description_label($create_value->component_id, $comp_pos_value);
    if ($create_value->prefix_description != '') {
      $prefix_description = $create_value->prefix_description . "&nbsp";
    }
    if ($create_value->suffix_description != '') {
      $suffix_description = "&nbsp" . $create_value->suffix_description;
    }
    if (strtolower($create_value->use_for_part_desc) != 'yes') {
      $comp_pos_value = NULL;
      $create_value->component_type = NULL;
      $eq = NULL;
    }
    else {
      $comp_pos_value = souriau_toolkit_build_backshell_get_component_pos_data($part_id, $create_value, $comp_pos_value);
    }

    if (strtolower($create_value->use_for_part_desc) == 'yes' && $create_value->use_disp_text_for_desc == 1) {
      $description = souriau_toolkit_build_backshell_part_component_description($create_value->component_id, $comp_pos_value, 0);
      if (!empty($description)) {
        if ($create_value->component_id == souriau_toolkit_build_backshell_get_exceptional_data('COMP_ID_' . $create_value->component_id)) {
          $create_value->component_type = $description[0]->display_name;
          $comp_pos_value = NULL;
          $eq = NULL;
        }
        elseif ($create_value->use_value_and_text_for_desc == 1) {
          $comp_pos_value = (trim($comp_pos_value) != '') ? $comp_pos_value . " , " . $description[0]->display_name : $description[0]->display_name;
        }
        else {
          $comp_pos_value = $description[0]->display_name;
        }
      }
    }
    $sleeve_component = souriau_toolkit_build_backshell_get_sleeve_component($part_id);

    if (!empty($sleeve_component) && $sleeve_component[0]->entry_component == $create_value->component_id && $create_value->use_for_part_build == 'No') {
      $entry_value = souriau_toolkit_build_backshell_get_component_value($values[$sleeve_component[0]->entry_component]);
      $sleeve_data = souriau_toolkit_build_backshell_get_sleeve_data($part_id, (int) $entry_value);
      $comp_pos_value = '0' . $sleeve_data[0]->sleev_value;
    }
    if (!empty($part_label)) {
      $comp_pos_value = $part_label[0]->component_type;
    }
    $part_desc_array[$k]['label'] = $create_value->component_type;
    $part_desc_array[$k]['eq'] = $eq;
    $part_desc_array[$k]['value'] = $comp_pos_value;
    $part_desc_array[$k]['level'] = $create_value->display_level;
    $part_desc_array[$k]['prefix'] = $prefix_description;
    $part_desc_array[$k]['suffix'] = $suffix_description;
    if (souriau_toolkit_build_backshell_get_exceptional_data(trim(souriau_toolkit_build_backshell_get_component_value($values[$create_value->component_id]))) == $create_value->component_id) {
      unset($part_desc_array[$k - 2]);
      break;
    }
    $k++;
  }
  return souriau_toolkit_build_backshell_get_left_dimensions($form, $form_state, $part_desc_array);
}

/**
 * Function to get Dimensions of part number.
 */
function souriau_toolkit_build_backshell_get_partnumber_dimension($form, $form_state) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $part_id = $values['partnumber'];
  $i = 0;
  $dimension_group_id = 0;
  $dimension_value = [];
  $dimensions_group = souriau_toolkit_build_backshell_get_dimension_group($part_id);
  $dimensions_data = souriau_toolkit_build_backshell_get_dimension_label($part_id);
  foreach ($dimensions_group as $value) {
    // Get description fileds values corresponding to each dimensions group.
    $pos_data = trim(souriau_toolkit_build_backshell_get_component_value($values[$value->component_id]));
    $rel_data = ($value->relation_id != 0) ? trim(souriau_toolkit_build_backshell_get_component_value($values[$value->relation_id])) : NULL;
    $desc_arr[$value->dimension_group_id] = souriau_toolkit_build_backshell_get_dimension_data($part_id, $value->dimension_group_id, $pos_data, $rel_data);
  }

  foreach ($dimensions_data as $row => $col) {
    // Assign SHELL vale and ENTRY values to its labels(content type).
    $dimension_lbl = NULL;
    if ($col->relation_component == 0  || empty(trim($col->relation_component))) {
      $dimension_lbl = $col->component_type;
    }
    elseif ($col->relation_value == souriau_toolkit_build_backshell_get_component_value($values[$col->relation_component])) {
      $dimension_lbl = $col->component_type;
    }
    if ($dimension_lbl != '') {
      if ($col->dimension_group_id != $dimension_group_id) {
        $dimension_group_id = $col->dimension_group_id;
        $i = 0;
      }
      if ($col->is_dimension == 1) {
        $i++;
        $column = "col_" . $i;
        $dimension_value[$row][$col->component_type][0] = (isset($desc_arr[$col->dimension_group_id][0]->$column)) ? $desc_arr[$col->dimension_group_id][0]->$column : NULL;
      }
      else {
        $dimension_value[$row][$dimension_lbl][0] = NULL;
      }
      $dimension_value[$row][$dimension_lbl][0] .= souriau_toolkit_build_backshell_get_dimension_extension($form, $form_state, $part_id, $col->component_type_id);
    }
    if (isset($dimension_value[$row][$dimension_lbl][0])) {
      $dimension_value[$row][$dimension_lbl][1] = $col->is_dimension;
      $dimension_value[$row][$dimension_lbl][2] = $col->display_level;
    }
  }
  $right_box = NULL;
  foreach ($dimension_value as $dimension) {
    $right_box .= '<div>';
    foreach ($dimension as $lbl => $desc) {
      for ($i = 1; $i < $desc[2]; $i++) {
        $right_box .= '&nbsp;&nbsp;&nbsp;';
      }
      $right_box .= $lbl;
      $right_box .= ($desc[1] != 0) ? '=' : '';
      $right_box .= ($desc[0] != "") ? $desc[0] : '';
    }
    $right_box .= '</div>';
  }
  if (!empty($dimension_value)) {
    $right_box .= '<div>' . t("ALL DIMENSIONS ARE IN INCHES", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
  }
  return $right_box;
}

/**
 * Function to get Extended Dimension of part number.
 */
function souriau_toolkit_build_backshell_get_dimension_extension($form, $form_state, $part_id, $component_type_id) {
  $extension = NULL;
  $comp_id = souriau_toolkit_build_backshell_get_exceptional_data('PART_' . $part_id . '_COMP_TYPE_' . $component_type_id);
  if (empty($comp_id)) {
    return;
  }
  $comp_id_value = trim(souriau_toolkit_build_backshell_get_component_value($form_state['values'][$comp_id]));
  $extension = souriau_toolkit_build_backshell_get_exceptional_data('COMP_' . $comp_id . '_' . $comp_id_value);
  return $extension;
}

/**
 * Function to get Page footer.
 */
function souriau_toolkit_build_backshell_get_partnumber_footer($product_id, $part_id) {
  $page_footer = '<div>';
  $notes_array = souriau_toolkit_build_backshell_get_part_noted($part_id);
  if ($product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_1')
      || $product_id == souriau_toolkit_build_backshell_get_exceptional_data('PROD_2')) {
    $page_footer .= '<div>' . t("Tolerance, unless otherwise specified:", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
    if ($part_id = souriau_toolkit_build_backshell_get_exceptional_data('PART_ID_' . $part_id)) {
      $page_footer .= '<div>' . t(".X &#177 .060", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
      $page_footer .= '<div>' . t(".XX &#177 .030", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
      $page_footer .= '<div>' . t(".XXX &#177 .015", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
      $page_footer .= '<div>' . t("ANGLES &#177 5&#176", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
    }
    else {
      $page_footer .= '<div>' . t(".X &#177 .030", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
      $page_footer .= '<div>' . t(".XX &#177 .010", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
      $page_footer .= '<div>' . t(".XXX &#177 .005", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
      $page_footer .= '<div>' . t("ANGLES &#177 2&#176", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
    }
  }
  $print_button = [
    '#type' => 'button',
    '#value' => t('PRINT', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#souriau_settings' => [
      'color' => 'orange',
    ],
    '#prefix' => '<div class="w-btn">',
    '#suffix' => '</div>',
    '#attributes' => [
      'class' => [
        'orange-btn-hover',
      ],
      'id' => 'print_button',
    ],
  ];
  if (!empty($notes_array)) {
    $page_footer .= '<div class="text-left">';
    $page_footer .= '<div>' . t("NOTES:", [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</div>';
    $note_points = theme('item_list', [
      'items' => $notes_array,
      'title' => NULL,
      'type' => 'ol',
      'attributes' => [],
    ]);
    $page_footer .= render($note_points);
    $page_footer .= '</div>';
  }
  $page_footer .= "<br/>" . drupal_render($print_button);
  $page_footer .= '</div>';
  return $page_footer;
}

/**
 * Function to return description label.
 */
function souriau_toolkit_build_backshell_get_part_desc_content($form, $form_state, $product_id) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $part_id = $values['partnumber'];
  $part_text = $form['wrapper']['partnumber']['#options'][$part_id];
  switch ($product_id) {
    case souriau_toolkit_build_backshell_get_exceptional_data('PROD_1'):
      $part_desc_label = substr($form['wrapper']['series']['#options'][$values['series']], 0, 2);
      break;

    case souriau_toolkit_build_backshell_get_exceptional_data('PROD_2'):
      $part_desc_label = $form['wrapper']['series']['#options'][$values['series']];
      break;

    case souriau_toolkit_build_backshell_get_exceptional_data('PROD_3'):
      $part_desc_label = substr($part_text, 0, 2);
      break;

    default:
      $part_desc_label = $part_text;
  }
  return $part_desc_label;
}

/**
 * Function to return values to be displayed in inches.
 */
function souriau_toolkit_build_backshell_get_component_pos_data($part_id, $create_value, $comp_pos_value) {
  $inches = t("Inches", [], ['context' => SOURIAU_COMMON_T_OTHER]);
  if (is_numeric($comp_pos_value) && ($create_value->component_type_id == souriau_toolkit_build_backshell_get_exceptional_data('COMP_TYPE_6')
    || $part_id == souriau_toolkit_build_backshell_get_exceptional_data('COMP_TYPE_' . $create_value->component_type_id))) {
    $comp_pos_value = $comp_pos_value . "(" . $comp_pos_value / 2 . " " . $inches . ")";
  }
  if (is_numeric($comp_pos_value) && $create_value->component_type_id == souriau_toolkit_build_backshell_get_exceptional_data('COMP_TYPE_13')) {
    $comp_pos_value = $comp_pos_value . "(" . $comp_pos_value . " " . $inches . ")";
  }
  return $comp_pos_value;
}

/**
 * Function to handle exceptional cases.
 */
function souriau_toolkit_build_backshell_handle_exceptional_cases($form, $form_state, $prev_comp_id, $prev_comp_value, $part_group_arr, $redirect_value) {
  $values = (!empty($form_state['values'])) ? $form_state['values'] : NULL;
  $commands = [];
  if ($values['product'] == souriau_toolkit_build_backshell_get_exceptional_data('PROD_2') && !empty(souriau_toolkit_build_backshell_get_exceptional_data($prev_comp_value))) {
    // Disable all following drop downs incase of Arinc- j1500.
    $except_case = souriau_toolkit_build_backshell_get_exceptional_data($prev_comp_value);
    foreach (element_children($form['wrapper']['component']) as $value) {
      if ($value > $except_case) {
        $form['wrapper']['component'][$value]['#attributes'] = ['disabled' => TRUE];
        $commands[] = ajax_command_replace('#comp_' . $value . '_container', drupal_render($form['wrapper']['component'][$value]));
      }
    }
    $commands[] = ajax_command_invoke('#btn_container', 'show');
  }
  if ($values['product'] == souriau_toolkit_build_backshell_get_exceptional_data('PROD_4')) {
    // Redirect to Another Partnmber when component 1 is selected.
    // This is the case with AS85049.
    $part_group_arr = souriau_toolkit_build_backshell_part_group_part($prev_comp_id, $prev_comp_value);
    if (!empty($part_group_arr)) {
      $commands[] = [
        'command' => 'changePartNumber',
        'part_id' => $part_group_arr[0]->part_id,
      ];
    }
  }
  if (!empty($part_group_arr) && $values['product'] == souriau_toolkit_build_backshell_get_exceptional_data('PROD_5')) {
    // Redirectiong in case of Protective cover.
    $redirect_series = souriau_toolkit_build_backshell_get_exceptional_data('RET_PROT_COVER');
    $form['wrapper']['series']['#value'] = $redirect_series;
    $partnumber_values = souriau_toolkit_build_backshell_get_partnumber($redirect_series);
    $commands[] = ajax_command_replace('#series_container', drupal_render($form['wrapper']['series']));
    $form['wrapper']['partnumber']['#options'] = $partnumber_values;
    $commands[] = ajax_command_replace('#partnumber_container', drupal_render($form['wrapper']['partnumber']));
    $commands[] = [
      'command' => 'changePartNumber',
      'part_id' => $part_group_arr[0]->part_id,
    ];
  }
  if (!empty($commands)) {
    $commands[] = ajax_command_invoke('#tools-form-result', 'hide');
    $commands[] = ajax_command_souriau_common_jcf('refresh');
  }
  return $commands;
}

/**
 * Function to get left side diemnsions.
 */
function souriau_toolkit_build_backshell_get_left_dimensions($form, $form_state, $part_desc_array) {
  $left_box = NULL;
  foreach ($part_desc_array as $description) {
    $left_box .= '<div>';
    for ($i = 1; $i < $description['level']; $i++) {
      $left_box .= "&nbsp;&nbsp;&nbsp;";
    }
    foreach (['label', 'eq', 'prefix', 'value', 'suffix'] as $parameter) {
      $left_box .= $description[$parameter];
    }
    $left_box .= '</div>';
  }
  return $left_box;
}
