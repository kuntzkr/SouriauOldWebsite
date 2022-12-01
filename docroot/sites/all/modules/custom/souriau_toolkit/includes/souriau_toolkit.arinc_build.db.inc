<?php

/**
 * @file
 * Functions to load database values.
 */

/**
 * Function to return requested component values as per component type passed.
 */
function _souriau_toolkit_arinc_build_get_component_values($component_type, $flag = FALSE, $shell_size = FALSE, $cavity_size = FALSE, $shell_type = FALSE) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);

  if ($component_type == 'arinc plating') {
    $comp_val_query->orderBy('CV.component_value_id', 'DESC');
  }

  if ($component_type == 'CavityA' || $component_type == 'CavityB' || $component_type == 'CavityD' || $component_type == 'CavityE'
     || $component_type == 'CavityC'  || $component_type == 'CavityF') {
    $comp_val_query->condition('CV.addtional_restriction', '%' . db_like($cavity_size) . '%', 'LIKE');
  }

  if ($component_type == 'sealing feature' && $shell_type == 'M') {
    $comp_val_query->condition('CV.restricted_flag', 1);
  }
  elseif ($component_type == 'sealing feature') {
    $comp_val_query->condition('CV.addtional_restriction', 'M', '<>');
  }
  $parameter = ($flag) ? 'description' : 'value';
  $comp_val_query->fields('CV', [
    'component_value_id',
    $parameter,
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchAllKeyed();
}

/**
 * Function to return contact type as per shell type passed.
 */
function _souriau_toolkit_arinc_build_get_contact_type($shell_type_id, $component_type) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_group_relation_values', 'AGRV', 'AGRV.value_id = CV.component_value_id');
  $comp_val_query->join('arinc_group_relation_values', 'AGRV2', 'AGRV2.row_id = AGRV.row_id');
  $comp_val_query->join('arinc_component_values', 'CV2', 'CV2.component_value_id = AGRV2.value_id');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');

  $comp_val_query->condition('CV.component_value_id', $shell_type_id);
  $comp_val_query->condition('AGRV2.value_id', $shell_type_id, '<>');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);

  $comp_val_query->fields('CV2', ['value']);

  db_set_active();
  return $comp_val_query->execute()->fetchObject()->value;
}

/**
 * Function to return mounding releases as per shell type passed.
 */
function _souriau_toolkit_arinc_build_get_mount_release_values($component_type, $opted_shell_type = NULL, $connector_selected = NULL) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);
  if ($opted_shell_type == 'M') {
    $comp_val_query->condition('CV.restricted_flag', 1);
  }
  else {
    $comp_val_query->condition('CV.addtional_restriction', 'F');
  }
  // Load only G if sealed connector opted.
  if ($connector_selected == 'sealed') {
    $comp_val_query->condition('CV.restricted_shell', 1);
  }

  $comp_val_query->fields('CV', [
    'component_value_id',
    'description',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchAllKeyed();
}

/**
 * Function to return sealing code if exist.
 */
function _souriau_toolkit_arinc_build_verify_sealing_code($comp_conditional_id, $component_type, $ref_lookup_name) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_components_relation_reference', 'CRR');
  $comp_val_query->join('arinc_relation_master', 'RM', 'RM.relation_lookup_id = CRR.relation_lookup_id');
  $comp_val_query->join('arinc_component_values', 'CV', 'CV.component_value_id = CRR.comp_digit_code_value_id');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');

  $comp_val_query->condition('CRR.conditional_value_ids', $comp_conditional_id);
  $comp_val_query->condition('CT.component_type', $component_type);
  $comp_val_query->condition('RM.relation_lookup_name', $ref_lookup_name);
  $comp_val_query->condition('CRR.status', 1);
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');

  $comp_val_query->fields('CV', [
    'component_value_id',
    'value',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchObject();
}

/**
 * Function to verify mounting release mounding style codes compactibility.
 */
function _souriau_toolkit_arinc_build_get_conditional_ids($opted_mr_code) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_components_relation_reference', 'CRR');

  $comp_val_query->condition('CRR.comp_digit_code_value_id', $opted_mr_code);
  $comp_val_query->condition('CRR.status', 1);

  $comp_val_query->fields('CRR', [
    'conditional_value_ids',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchCol();
}

/**
 * Fucntion to verify signal code for no restrcition case only.
 */
function _souriau_toolkit_arinc_build_verify_norestriction($component_type, $cavity_value) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);
  $comp_val_query->condition('CV.component_value_id', $cavity_value);

  $comp_val_query->fields('CV', [
    'restricted_flag',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchObject();
}

/**
 * Function to get signal and power insert source code.
 */
function _souriau_toolkit_arinc_build_get_cavity_code($conditional_ids, $component_type, $ref_component_type) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_components_relation_reference', 'CRR');
  $comp_val_query->join('arinc_relation_master', 'RM', 'RM.relation_lookup_id = CRR.relation_lookup_id');
  $comp_val_query->join('arinc_component_values', 'CV', 'CV.component_value_id = CRR.comp_digit_code_value_id');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('RM.relation_lookup_name', $ref_component_type);
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);
  $comp_val_query->condition('CRR.conditional_value_ids', $conditional_ids);

  $comp_val_query->fields('CV', [
    'component_value_id',
    'value',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchObject();
}

/**
 * Function to find allowed contacts.
 */
function _souriau_toolkit_arinc_build_find_package($shell_size, $mounting_release, $shell_type, $connector_type, $signal_insert_code, $power_insert_code) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_packaging_rules', 'PR');

  $comp_val_query->condition('PR.cavity_signal_code', $signal_insert_code);
  $comp_val_query->condition('PR.cavity_power_digit', $power_insert_code);
  $comp_val_query->condition('PR.shell_size', $shell_size);
  $comp_val_query->condition('PR.mounting_release', $mounting_release);
  $comp_val_query->condition('PR.shell_type', $shell_type);
  $comp_val_query->condition('PR.connector_type', $connector_type);

  $comp_val_query->fields('PR', [
    'signal_22',
    'power_16',
    'power_20',
    'coax_5',
    'coax_1',
    'quadrax',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchObject();
}

/**
 * Function to return signal packages.
 */
function _souriau_toolkit_arinc_build_get_packages($component_type, $flag = NULL, $parameter = TRUE) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);
  $comp_val_query->condition('CV.restricted_flag', $flag);
  if ($flag === 'NO') {
    $comp_val_query->condition('CV.addtional_restriction', $flag);
  }
  $parameter = ($parameter) ? 'description' : 'value';
  $comp_val_query->fields('CV', [
    'component_value_id',
    $parameter,
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchAllKeyed();
}

/**
 * Function to load contact kinds according to mr and shell size opted.
 */
function _souriau_toolkit_arinc_build_get_contact_kind($component_type, $shell_size_selected, $mounting_release_selected) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);
  $comp_val_query->condition('CV.addtional_restriction', '%' . db_like($mounting_release_selected) . '%', 'LIKE');

  $comp_val_query->fields('CV', [
    'component_value_id',
    'value',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchAllKeyed();
}

/**
 * Function to load contact kind sizes according to mr opted.
 */
function _souriau_toolkit_arinc_build_get_contact_sizes($component_type, $mounting_release_selected) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);

  if ($mounting_release_selected == 'H') {
    $comp_val_query->isNull('CV.addtional_restriction');
    $comp_val_query->condition('CV.restricted_flag', 1);
  }
  if ($mounting_release_selected == 'K') {
    $comp_val_query->condition('CV.restricted_flag', 1);
    $comp_val_query->condition('CV.restricted_shell', 1, '<>');
  }

  $comp_val_query->fields('CV', [
    'component_value_id',
    'value',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchAllKeyed();
}

/**
 * Function to load pkg combinations.
 */
function _souriau_toolkit_arinc_build_find_pkg_codes($pkg_pattern, $component_type) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_components_relation_reference', 'CRR');
  $comp_val_query->join('arinc_relation_master', 'RM', 'CRR.relation_lookup_id = RM.relation_lookup_id');
  $comp_val_query->condition('CRR.conditional_value_ids', $pkg_pattern);
  $comp_val_query->condition('CRR.status', 1);
  $comp_val_query->condition('RM.relation_lookup_name', $component_type);

  $comp_val_query->fields('CRR', [
    'comp_digit_code_value_id',
  ]);

  db_set_active();
  $pkg_obj = $comp_val_query->execute()->fetchObject();
  return (is_object($pkg_obj)) ? $pkg_obj->comp_digit_code_value_id : NULL;
}

/**
 * Function to return requested component value as per component value id.
 */
function _souriau_toolkit_arinc_build_get_component_parameters($component_type, $component_value_id = FALSE) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);
  $comp_val_query->condition('CV.component_value_id', $component_value_id);
  $comp_val_query->fields('CV', [
    'value',
  ]);

  db_set_active();
  $comp_obj = $comp_val_query->execute()->fetchObject();

  return (is_object($comp_obj)) ? $comp_obj->value : NULL;
}

/**
 * Package validation function.
 */
function _souriau_toolkit_arinc_build_package_validation($mr, $ms, $pkg_fl, $pkg_sl) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_package_allowed', 'PA');
  $comp_val_query->condition('shell_size', $ms);
  $comp_val_query->condition('mounting_release', $mr);
  $comp_val_query->condition('pkg_first_letter', $pkg_fl);
  $comp_val_query->condition('pkg_second_letter', $pkg_sl);
  $comp_val_query->fields('PA', [
    'package_index_id',
  ]);

  db_set_active();
  return $comp_val_query->execute()->rowCount();
}

/**
 * Function to decide checking required with package first letter.
 */
function _souriau_toolkit_arinc_build_checking_required($component_type) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component', 'C');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);
  $comp_val_query->fields('C', [
    'is_component',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchObject()->is_component;
}

/**
 * Filter allowed mounting style codes.
 */
function _souriau_toolkit_arinc_build_get_mnt_options($shell_size, $shell_type, $shell_category, $conn_class) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_mounting_allowed', 'MA');
  $comp_val_query->condition('MA.status', 1);
  $comp_val_query->condition('MA.shell_size', $shell_size);
  $comp_val_query->condition('MA.shell_type', $shell_type);
  $comp_val_query->condition('MA.shell_category', $shell_category);
  $comp_val_query->condition('MA.connector_class', $conn_class);
  $comp_val_query->fields('MA', [
    'mnt_code_allowed',
  ]);

  db_set_active();
  $mnt_arr = $comp_val_query->execute()->fetchCol();
  return (count($mnt_arr) > 0) ? $mnt_arr : NULL;
}

/**
 * Load mounting style codes as per connector class and shell properties opted.
 */
function _souriau_toolkit_arinc_build_load_mnt_options($component_type, $mnt_val_arr) {
  db_set_active('ect_tools');
  $comp_val_query = db_select('arinc_component_values', 'CV');
  $comp_val_query->join('arinc_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('arinc_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_val_query->join('arinc_family', 'F', 'F.family_id = C.family_id');
  $comp_val_query->condition('C.status', 1);
  $comp_val_query->condition('F.family_name', 'Souriau Arinc 600');
  $comp_val_query->condition('CT.component_type', $component_type);

  $comp_val_query->condition('CV.value', $mnt_val_arr, 'IN');

  $comp_val_query->fields('CV', [
    'component_value_id',
    'description',
  ]);

  db_set_active();
  return $comp_val_query->execute()->fetchAllKeyed();
}
