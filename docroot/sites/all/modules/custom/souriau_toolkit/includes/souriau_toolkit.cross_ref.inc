<?php
/**
 * @file
 * Cross reference tool.
 */

module_load_include('inc', 'souriau_toolkit', 'includes/souriau_toolkit.cross_ref.db');

/**
 * Formbuilder for crossref.
 */
function souriau_toolkit_cross_ref_main_form($form, &$form_state) {
  form_load_include($form_state, 'inc', 'souriau_toolkit', 'includes/souriau_toolkit.cross_ref');
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
    '#title' => t('Competitor Part Number', [], ['context' => SOURIAU_COMMON_T_OTHER]),
  ];

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
    '#value' => t('FIND A MATCH', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#souriau_settings' => [
      'color' => 'blue',
    ],
    '#ajax' => [
      'callback' => 'souriau_toolkit_cross_ref_callback',
      'wrapper' => 'tools-form-result',
      'effect' => 'fade',
    ],
    '#attributes' => [
      'class' => [
        'gtm_crossref_element',
      ],
    ],
  ];

  $form['#attached']['js'][] = drupal_get_path("module", "souriau_tools") . "/js/souriau_tools_scroller.js";

  return $form;
}

/**
 * Ajax submit handler for partsearch.
 */
function souriau_toolkit_cross_ref_callback($form, &$form_state) {
  $commands = [];
  $search_result = NULL;
  $part_number = trim($form_state['values']['part_number']);
  if (!empty($part_number)) {
    $search_result = souriau_toolkit_cross_ref_partfinder($part_number);
  }
  $commands[] = ajax_command_replace('#tools-form-result', souriau_tools_result_processor($part_number, $search_result));
  $commands[] = ['command' => 'scroll_to_results'];

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Souriau part finder function.
 *
 * @param string $partnumber
 *   Partnumber to search for.
 *
 * @return string
 *   Matching souriau part or empty.
 */
function souriau_toolkit_cross_ref_partfinder($partnumber) {
  $souriau_partnumber = '';
  // Calls the function to fetch the partnumber components.
  $part_details = souriau_toolkit_cross_ref_part_search(strtoupper(souriau_toolkit_cross_ref_string_cleaner($partnumber)));

  // @Todo specal case for Amphenol, need rework.
  if ($part_details && $part_details[1]->family_name == 'TV' && !isset($part_details[21]) && strtoupper(substr($partnumber, -1)) != 'N') {
    $partnumber .= 'N';
    $part_details = souriau_toolkit_cross_ref_part_search(strtoupper(souriau_toolkit_cross_ref_string_cleaner($partnumber)));
  }

  // If there is a result, then the family, company and component details are displayed.
  if ($part_details && souriau_toolkit_cross_ref_check_relation_status($part_details)) {
    reset($part_details);
    $competitor_company_name = $part_details[key($part_details)]->company_name;

    if (!in_array(strtolower($competitor_company_name), ['souriau', 'sunbank'])) {
      $souriau_components = souriau_toolkit_cross_ref_find_souriau_parts($part_details);
      reset($souriau_components);
      $souriau_family_id = $souriau_components[key($souriau_components)]->family_id;
      $souriau_final_components = souriau_toolkit_cross_ref_check_applications($souriau_family_id, $souriau_components);
      $souriau_partnumber = souriau_toolkit_cross_ref_prepare_souriau_part($souriau_final_components);
    }
  }

  return $souriau_partnumber;
}

/**
 * Helper function to generate souriau partnumber.
 */
function souriau_toolkit_cross_ref_prepare_souriau_part($souriau_components) {
  $souriau_partnumber = '';
  if (!is_bool($souriau_components)) {
    // Build the header and rows from the result.
    foreach ($souriau_components as $souriau_component) {
      if (!is_null($souriau_component->value_match)) {
        $souriau_partnumber .= $souriau_component->value_match;
      }
    }
  }

  return $souriau_partnumber;
}

/**
 * Fetch the family and company.
 *
 * @param string $partnumber
 *   Competitor partnumber.
 *
 * @return string
 *   Matching partnumber.
 */
function souriau_toolkit_cross_ref_part_search($partnumber) {
  // Fetch the family and company details from the part number.
  $part_details = souriau_toolkit_cross_ref_get_family($partnumber);

  // All the component objects will be pushed to this array.
  $final_part = [];

  // If the family is identified then process the rest of the components.
  if ($part_details) {
    // Initialize the part search status to TRUE.
    $part_search_status = TRUE;

    $comp_replace = "/" . strtoupper(str_replace(
      '/',
      '\/',
      souriau_toolkit_cross_ref_string_cleaner($part_details->component_match))
    ) . "/";

    // Remove the first component from the partnumber.
    $new_partnum = preg_replace($comp_replace, '', $partnumber, 1);
    // Push the first component details to the final part array.
    $first_component = $part_details;
    // Loop through all the other components of the family.
    // In the component position order.
    foreach (souriau_toolkit_cross_ref_get_components($part_details->family_id) as $part_component) {
      // Proceed furthere only if the search status is TRUE.
      if ($part_search_status) {
        $part_search = souriau_toolkit_cross_ref_parse_components($part_component, $new_partnum, $part_search_status, $final_part);
        extract($part_search);
      }
      else {
        // If search status is set to false, the loop will exit.
        break;
      }
    }

    // Case when component loop completes and still the partcode exists.
    if ($new_partnum != '' || count($final_part) == 0) {
      $part_search_status = FALSE;
    }
  }
  $part = [$first_component->component_id => $first_component] + $final_part;

  return ($part_search_status) ? $part : $part_search_status;
}

/**
 * Parse through components for searching.
 */
function souriau_toolkit_cross_ref_parse_components($part_component, $new_partnum, $part_search_status, $final_part) {
  $component_value_match = FALSE;

  $comp_min_length = $part_component->component_min_length;
  $comp_max_length = $part_component->component_max_length;
  $component_finder = souriau_toolkit_cross_ref_component_finder($part_component->component_id, $comp_max_length, $comp_min_length, $new_partnum, $component_value_match);
  extract($component_finder);

  // Special eg: when component in db is 07 and user enter 7 only.
  if (!$component_value_match && $part_component->component_min_length == 2 && $new_partnum != '') {
    // Cut the component from the part string based on the min length.
    $component_value = substr($new_partnum, 0, 1);
    // Search for the value match with the min length component.
    $component_value_match = souriau_toolkit_cross_ref_component_value_match(
        $component_value, $part_component->component_id
    );
  }

  // Case if match not found and if the previous match was not the correct component match.
  if (!$component_value_match && $part_component->component_min_length != 0) {
    end($final_part);
    $last_component = key($final_part);

    if ($final_part[$last_component]->component_min_length == 0) {
      $prev_value = ltrim($final_part[$last_component]->component_match, '0');
      $new_partnum = $prev_value . $new_partnum;
      // Cut the component from the part string based on the min length.
      $component_value = substr($new_partnum, 0, $part_component->component_min_length);
      // Search for the value match with the min length component.
      $component_finder = souriau_toolkit_cross_ref_component_finder($part_component->component_id, $comp_max_length, $comp_min_length, $new_partnum, $component_value_match);
      extract($component_finder);

      if ($component_value_match) {
        unset($final_part[$last_component]);
      }
    }
    else {
      // Case if previously found component is not right.
      $prev_value = ltrim($final_part[$last_component]->component_match, '0');
      $new_partnum = $prev_value . $new_partnum;
      $max_length = $final_part[$last_component]->component_max_length;
      $min_length = $final_part[$last_component]->component_min_length;
      // Search for the value match with the min length component.
      $component_finder = souriau_toolkit_cross_ref_component_finder($last_component, $max_length, $min_length, $new_partnum, FALSE);
      extract($component_finder);

      if ($component_value_match) {
        $final_part[$last_component] = $component_value_match;

        $comp_replace = "/" . souriau_toolkit_cross_ref_string_cleaner(strtoupper($component_value)) . "/";
        $new_partnum = preg_replace($comp_replace, '', $new_partnum, 1);

        $component_finder = souriau_toolkit_cross_ref_component_finder($part_component->component_id, $comp_max_length, $comp_min_length, $new_partnum, FALSE);
        extract($component_finder);
      }
    }
  }

  // If there is a match.
  // Or the min length is 0.
  // Ie the case when there is no component present in the partcode.
  if ($component_value_match || $part_component->component_min_length == 0) {

    $comp_replace = "/" . souriau_toolkit_cross_ref_string_cleaner(strtoupper($component_value)) . "/";
    // Store the component details to final part array if min length is not 0.
    if ($part_component->component_min_length != 0) {
      $final_part[$component_value_match->component_id] = $component_value_match;
      // Remove the newly identified component value from the part for next search.
      $new_partnum = preg_replace($comp_replace, '', $new_partnum, 1);
    }
    // If the min length is 0, but the match is found with max length.
    elseif ($component_value_match) {
      // Store the component details to final part array.
      $final_part[$component_value_match->component_id] = $component_value_match;
      // Remove the newly identified component value from the part for next search.
      $new_partnum = preg_replace($comp_replace, '', $new_partnum, 1);
    }
  }
  else {
    // In case if there is no value match, the search status is set to false.
    $part_search_status = FALSE;
  }

  return [
    'part_search_status' => $part_search_status,
    'final_part' => $final_part,
    'new_partnum' => $new_partnum,
  ];
}

/**
 * Find the component value for an ID.
 *
 * @param string $component_id
 *   Unique ID of component.
 * @param string $comp_max_length
 *   Component max length.
 * @param string $comp_min_length
 *   Component min length.
 * @param string $new_partnum
 *   The partnumber to consider.
 * @param array $component_value_match
 *   Current value match.
 *
 * @return array
 *   Matching component value and value match.
 */
function souriau_toolkit_cross_ref_component_finder($component_id, $comp_max_length, $comp_min_length, $new_partnum, $component_value_match) {
  for ($c_length = $comp_max_length; $c_length >= $comp_min_length && $new_partnum != '' && !$component_value_match; $c_length--) {
    // Search for the component in the part string if min length is not 0.
    if ($c_length != 0) {
      // Cut the component from the part string based on the min length.
      $component_value = substr($new_partnum, 0, $c_length);
      // Search for the value match with the min length component.
      $component_value_match = souriau_toolkit_cross_ref_component_value_match(
          $component_value, $component_id
      );
    }
  }

  return [
    'component_value' => $component_value,
    'component_value_match' => $component_value_match,
  ];
}

/**
 * Fetch the family and company details from the partnumber.
 */
function souriau_toolkit_cross_ref_get_family($partnumber) {
  $part_details = FALSE;
  $family_lengths = souriau_toolkit_cross_ref_get_family_lengths();

  for ($i = $family_lengths->max_length; $i >= $family_lengths->min_length && !$part_details; $i--) {
    $new_part = substr($partnumber, 0, $i);
    $part_details = souriau_toolkit_cross_ref_component_value_match($new_part);
  }

  return $part_details;
}

/**
 * Remove all special characters from the partnumber.
 */
function souriau_toolkit_cross_ref_string_cleaner($string) {
  return preg_replace('/[^A-Za-z0-9]/', '', $string);
}

/**
 * Checks the relation status of the components in the provided partnumber.
 */
function souriau_toolkit_cross_ref_check_relation_status($part_components) {
  $relation_status = TRUE;
  reset($part_components);

  // Loop through each components of the partnumber.
  foreach ($part_components as $component) {
    // Check if the component has any relation.
    if (souriau_toolkit_cross_ref_component_has_relation($component->component_id)) {
      $component_search = souriau_toolkit_cross_ref_get_component_search_status($component, $part_components);

      // If any component match fails, mark the relation as false and exit the loop.
      if ($component_search == FALSE) {
        $relation_status = FALSE;
        break;
      }
    }
  }

  return $relation_status;
}

/**
 * Component search status.
 */
function souriau_toolkit_cross_ref_get_component_search_status($component, $part_components) {
  // Get the rows that has the component and value.
  $relation_rows = souriau_toolkit_cross_ref_get_relation_rows($component->component_id, $component->component_value_id);
  $component_search = FALSE;
  foreach ($relation_rows as $relation_row) {
    if (!$component_search) {
      // Fetch all components in that row related to the current component.
      $component_search = souriau_toolkit_cross_ref_cross_component_match_search($relation_row, $component, $part_components);
    }
  }

  return $component_search;
}

/**
 * Check if there us a component match present.
 *
 * @param array $relation_row
 *   The related row.
 * @param array $component
 *   Component details.
 * @param array $part_components
 *   Set of all part components.
 *
 * @return bool
 *   Component search status.
 */
function souriau_toolkit_cross_ref_cross_component_match_search($relation_row, $component, $part_components) {
  foreach (souriau_toolkit_cross_ref_get_related_components($relation_row->row_id, $component->component_id) as $related_comp) {
    // Check if the row value is present in the component.
    if (isset($part_components[$related_comp->component_id])) {
      $component_match = $part_components[$related_comp->component_id]->component_value_id;
      $related_value = $related_comp->value_id;
      // If there is any match, change the status and continue the loop.
      if ($component_match == $related_value) {
        $component_search = TRUE;
      }
      else {
        $component_search = FALSE;
        break;
      }
    }
  }

  return $component_search;
}

/**
 * Main function for building souriau partnumber from a competitor part.
 *
 * @param array $competitor_part
 *   Compoetor part details.
 *
 * @return Object Array
 *   Corresponding souriau parts.
 */
function souriau_toolkit_cross_ref_find_souriau_parts($competitor_part) {
  $souriau_part_status = TRUE;

  $final_souriau_part = [];

  reset($competitor_part);

  $competitor_component_id = $competitor_part[key($competitor_part)]->component_id;
  $competitor_family_id = $competitor_part[key($competitor_part)]->family_id;

  // Get souriau family details.
  $souriau_family = souriau_toolkit_cross_ref_get_souriau_family($competitor_component_id);

  if ($souriau_family) {
    // Fetch all souriau components.
    $souriau_components = souriau_toolkit_cross_ref_get_components($souriau_family->family_id, FALSE);
    $souriau_components[key($souriau_components)]->family_name = $souriau_family->family_name;
    $souriau_components[key($souriau_components)]->company_name = $souriau_family->company_name;
    $souriau_components[key($souriau_components)]->company_id = $souriau_family->company_id;
    $souriau_components[key($souriau_components)]->family_id = $souriau_family->family_id;

    // Loop through each souriau component to find cross.
    foreach ($souriau_components as $key => $sourau_component) {
      $cross_found = FALSE;
      if (!isset($souriau_components[$key]->value_match)) {
        // Loop through each cross rows having the component.
        $cross_rows = souriau_toolkit_cross_ref_get_cross_rows($sourau_component->component_id, $competitor_family_id);
        $cross_search_status = souriau_toolkit_cross_ref_cross_search_status($cross_rows, $cross_found, $souriau_components, $competitor_part);
        extract($cross_search_status);

        // If no match for for any component, then we stop the search.
        if (!$cross_found && $sourau_component->component_min_length != 0) {
          $souriau_part_status = FALSE;
          break;
        }
      }
      $final_souriau_part[$sourau_component->component_id] = $souriau_components[$key];
    }
  }
  else {
    $souriau_part_status = FALSE;
  }
  return ($souriau_part_status) ? $final_souriau_part : $souriau_part_status;
}

/**
 * Get search status.
 */
function souriau_toolkit_cross_ref_cross_search_status($cross_rows, $cross_found, $souriau_components, $competitor_part) {
  foreach ($cross_rows as $cross_row) {
    if (!$cross_found) {
      $row_components = souriau_toolkit_cross_ref_get_cross_components($cross_row->row_id);
      // Find loop through the components in the same row.
      foreach ($row_components as $row_component) {
        // If the component is a souriau component, store the value.
        $is_souriau_component = souriau_toolkit_cross_ref_is_souriau_component($row_component->component_id, $souriau_components);

        if ($is_souriau_component !== FALSE) {
          $souriau_components[$is_souriau_component]->value_match = $row_component->value;
          $souriau_components[$is_souriau_component]->value_description = $row_component->description;
          $souriau_components[$is_souriau_component]->value_id = $row_component->value_id;
        }
        // If the component is not souriau component, and if the value matches the competitor value, then cross found.
        elseif (isset($competitor_part[$row_component->component_id]) && $row_component->value_id == $competitor_part[$row_component->component_id]->component_value_id) {
          // Cross Found.
          $cross_found = TRUE;
        }
        else {
          $cross_found = FALSE;
          break;
        }
      }
    }
    else {
      break;
    }
  }

  return [
    'souriau_components' => $souriau_components,
    'cross_found' => $cross_found
  ];
}

/**
 * Check if a component is souriau component or not.
 *
 * @param string $component_id
 *   Unique ID of component.
 * @param array $souriau_components
 *   Part component details.
 *
 * @return bool
 *    Boolean or the position of comonent in the array.
 */
function souriau_toolkit_cross_ref_is_souriau_component($component_id, $souriau_components) {
  $is_souriau_component = FALSE;
  foreach ($souriau_components as $key => $souriau_component) {
    if ($souriau_component->component_id == $component_id) {
      $is_souriau_component = $key;
      break;
    }
  }

  return $is_souriau_component;
}

/**
 * Check if any components applicability. If not applicable, then remove them.
 *
 * @param string $family_id
 *   Unique ID of family.
 * @param array $part_components
 *   Part component details.
 *
 * @return Object Array
 *   Part components if applications are ok.
 */
function souriau_toolkit_cross_ref_check_applications($family_id, $part_components) {
  // Loop through all the applications in the family.
  foreach (souriau_toolkit_cross_ref_get_applications($family_id) as $application) {
    // Loop through the rows related to the application.
    $is_applicable = souriau_toolkit_cross_ref_check_applicable($application, $part_components);

    // If the component is not applicable, then reset the array element.
    if (!$is_applicable) {
      unset($part_components[$application->component_is_applicable]);
    }
  }

  return $part_components;
}

/**
 * Loop through the rows related to the application.
 */
function souriau_toolkit_cross_ref_check_applicable($application, $part_components) {
  // Set as not applicable by default for each component initially.
  $is_applicable = FALSE;
  foreach (souriau_toolkit_cross_ref_get_application_rows($application->application_id) as $applicaton_rows) {
    // Check if the component is not applicable.
    if (!$is_applicable) {
      // Loop throuh each components.
      foreach (souriau_toolkit_cross_ref_get_application_components($applicaton_rows->row_id) as $component) {

        // Check if the value is same as the application rule, if yes then it is applicable.
        if ($part_components[$component->component_id]->value_id == $component->value_id) {
          $is_applicable = TRUE;
        }
        else {
          $is_applicable = FALSE;
          break;
        }
      }
    }
    else {
      break;
    }
  }

  return $is_applicable;
}
