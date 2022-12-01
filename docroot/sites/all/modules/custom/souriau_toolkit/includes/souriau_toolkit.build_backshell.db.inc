<?php

/**
 * @file
 * Functions to work with tools database.
 */

/**
 * Return all products from bkshell_product.
 */
function souriau_toolkit_build_backshell_get_product() {
  db_set_active('ect_tools');
  $prod_query = db_select('bkshell_product', 'P');
  $prod_query->fields('P', [
    'product_id',
    'product_name',
  ]);
  db_set_active();
  return $prod_query->execute()->fetchAllKeyed();
}

/**
 * Return all Series from bkshell_series for the selected product_id.
 */
function souriau_toolkit_build_backshell_get_series($product_id) {
  db_set_active('ect_tools');
  $series_query = db_select('bkshell_series', 'S');
  $series_query->fields('S', [
    'series_id',
    'series_name',
  ]);
  $series_query->condition('product_id', $product_id);
  db_set_active();
  return $series_query->execute()->fetchAllKeyed();
}

/**
 * Return all Series from bkshell_partnumber for the selected series_id.
 */
function souriau_toolkit_build_backshell_get_partnumber($series_id) {
  db_set_active('ect_tools');
  $part_query = db_select('bkshell_partnumber', 'R');
  $part_query->fields('R', [
    'part_id',
    'part_name',
  ]);
  $part_query->condition('series_id', $series_id);
  db_set_active();
  return $part_query->execute()->fetchAllKeyed();
}

/**
 * Return all components from bkshell_component for the selected partnumber.
 */
function souriau_toolkit_build_backshell_get_component($part_id) {
  db_set_active('ect_tools');
  $comp_query = db_select('bkshell_component', 'C');
  $comp_query->join('bkshell_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_query->fields('C');
  $comp_query->fields('CT', [
    'component_type',
  ]);
  $comp_query->condition('part_id', $part_id);
  db_set_active();
  return $comp_query->execute()->fetchAll();
}

/**
 * Return first components values from bkshell_component_values.
 */
function souriau_toolkit_build_backshell_get_first_compvalue($part_id, $component_id, $component_pos) {
  db_set_active('ect_tools');
  $comp_value_query = db_select('bkshell_component_value', 'CV');
  $comp_value_query->join('bkshell_component', 'C', 'C.component_id = CV.component_id');
  $comp_value_query->fields('CV', [
    'component_value_id',
    'value',
    'display_name',
  ]);
  $comp_value_query->condition('C.component_position', $component_pos);
  $comp_value_query->condition('C.part_id', $part_id);
  $comp_value_query->condition('CV.component_id', $component_id);
  $comp_value_query->orderBy('display_name', 'ASC');
  db_set_active();
  return $comp_value_query->execute()->fetchAll();
}

/**
 * Return each component values from bkshell_component_values.
 */
function souriau_toolkit_build_backshell_next_component_value($component_id, $search_val, $relation1, $relation2 = NULL, $search_val2 = NULL) {
  db_set_active('ect_tools');
  if ($relation2 > 0) {
    $next_comp_value_query = db_select('bkshell_component_value', 'CV');
    $next_comp_value_query->join('bkshell_component_group', 'G', 'G.group_id = CV.group_id');
    $next_comp_value_query->join('bkshell_component_group_value', 'GV1', 'GV1.group_id = G.group_id');
    $next_comp_value_query->join('bkshell_component_group_value', 'GV2', 'GV2.group_id = CV.group_id_2');
    $next_comp_value_query->fields('CV', [
      'component_value_id',
      'value',
      'display_name',
    ]);
    $next_comp_value_query->condition('GV1.group_value', $search_val);
    $next_comp_value_query->condition('CV.component_id', $component_id);
    $next_comp_value_query->condition('GV2.group_value', $search_val2);
  }
  elseif ($relation1 > 0) {
    $next_comp_value_query = db_select('bkshell_component_value', 'CV');
    $next_comp_value_query->join('bkshell_component_group', 'G', 'G.group_id = CV.group_id');
    $next_comp_value_query->join('bkshell_component_group_value', 'GV', 'GV.group_id = G.group_id');
    $next_comp_value_query->fields('CV', [
      'component_value_id',
      'value',
      'display_name',
    ]);
    $next_comp_value_query->condition('GV.group_value', $search_val);
    $next_comp_value_query->condition('CV.component_id', $component_id);
  }
  else {
    $next_comp_value_query = db_select('bkshell_component_value', 'CV');
    $next_comp_value_query->fields('CV', [
      'component_value_id',
      'value',
      'display_name',
    ]);
    $next_comp_value_query->condition('CV.component_id', $component_id);
  }
  $next_comp_value_query->orderBy('display_name', 'ASC');
  db_set_active();
  return $next_comp_value_query->execute()->fetchAll();
}

/**
 * Return components from bkshell_component_values to be reset.
 */
function souriau_toolkit_build_backshell_components_reset($part_id, $component_id) {
  db_set_active('ect_tools');
  $comp_reset_query = db_select('bkshell_component', 'C');
  $comp_reset_query->fields('C');
  $comp_reset_query->fields('C', [
    'component_id',
    'component_position',
  ]);
  $comp_reset_query->condition('part_id', $part_id);
  $comp_reset_query->condition('relation_component', $component_id);
  db_set_active();
  return $comp_reset_query->execute()->fetchAll();
}

/**
 * Return component id from bkshell_component_values to be listed.
 */
function souriau_toolkit_build_backshell_next_component($part_id, $component_id) {
  db_set_active('ect_tools');
  $comp_next_comp = db_select('bkshell_component', 'C');
  $comp_next_comp->fields('C', [
    'component_id',
    'component_position',
    'relation',
    'relation_component',
    'selected_value',
  ]);
  $comp_next_comp->condition('part_id', $part_id);
  $comp_next_comp->condition('component_id', $component_id, '>');
  $comp_next_comp->condition('show_list', '1');
  $comp_next_comp->range(0, 1);
  db_set_active();
  return $comp_next_comp->execute()->fetchAll();
}

/**
 * Return part_id from bkshell_component_values.
 */
function souriau_toolkit_build_backshell_part_group_part($component_id, $component_val) {
  db_set_active('ect_tools');
  $part_group_query = db_select('bkshell_component', 'C');
  $part_group_query->join('bkshell_part_group', 'PG', 'PG.part_group_id = C.part_group_id');
  $part_group_query->join('bkshell_part_group_value', 'PV', 'PV.part_group_id = PG.part_group_id');
  $part_group_query->fields('PV', [
    'part_id',
  ]);
  $part_group_query->condition('C.component_id', $component_id);
  $part_group_query->condition('PV.part_group_value', $component_val);
  db_set_active();
  return $part_group_query->execute()->fetchAll();
}

/**
 * Return component list from bkshell_part_build for part number creation.
 */
function souriau_toolkit_build_backshell_get_create_part_components($part_id) {
  db_set_active('ect_tools');
  $create_part_query = db_select('bkshell_part_build', 'PC');
  $create_part_query->join('bkshell_component_type', 'CT', 'CT.component_type_id = PC.component_type_id');
  $create_part_query->fields('PC');
  $create_part_query->fields('CT', [
    'component_type',
  ]);
  $create_part_query->condition('PC.part_id', $part_id);
  $create_part_query->orderBy('PC.position', 'ASC');
  db_set_active();
  return $create_part_query->execute()->fetchAll();
}

/**
 * Return exceptional id from bkshell_exceptions.
 */
function souriau_toolkit_build_backshell_get_exceptions_data($name) {
  db_set_active('ect_tools');
  $except_data_query = db_select('bkshell_exceptions', 'E');
  $except_data_query->fields('E', [
    'reference_id',
  ]);
  $except_data_query->condition('E.component_name', $name);
  db_set_active();
  return $except_data_query->execute()->fetchAll();
}

/**
 * Return error for part id from bkshell_error.
 */
function souriau_toolkit_build_backshell_get_error($part_id) {
  db_set_active('ect_tools');
  $error_part_query = db_select('bkshell_error', 'ER');
  $error_part_query->fields('ER');
  $error_part_query->condition('ER.part_id', $part_id);
  db_set_active();
  return $error_part_query->execute()->fetchAll();
}

/**
 * Return error data from bkshell_error_values.
 */
function souriau_toolkit_build_backshell_get_error_data($component_id, $relation1, $relation2, $relation3, $compare) {
  db_set_active('ect_tools');
  if ($relation2 == '') {
    $error_data_query = db_select('bkshell_error_values', 'EV');
    $error_data_query->fields('EV', [
      'component_value',
    ]);
    $error_data_query->condition('EV.component_id', $component_id);
    $error_data_query->condition('EV.relation_value', $relation1);
  }
  elseif ($relation3 == '') {
    $error_data_query = db_select('bkshell_error_values', 'EV');
    $error_data_query->join('bkshell_error_group', 'EG', 'EG.error_group_id = EV.error_group_id');
    $error_data_query->fields('EV', [
      'component_value',
    ]);
    $error_data_query->condition('EV.component_id', $component_id);
    $error_data_query->condition('EV.relation_value', $relation2);
    $error_data_query->condition('EG.component_id', $component_id);
    $error_data_query->condition('EG.relation_value', $relation1);
  }
  else {
    $error_data_query = db_select('bkshell_error_values', 'EV');
    $error_data_query->join('bkshell_error_group', 'EG', 'EG.error_group_id = EV.error_group_id_2');
    $error_data_query->join('bkshell_error_group', 'EC', 'EC.error_group_id = EV.error_group_id');
    $error_data_query->fields('EV', [
      'component_value',
    ]);
    $error_data_query->condition('EV.component_id', $component_id);
    $error_data_query->condition('EV.relation_value', $relation3);
    $error_data_query->condition('EG.relation_value', $relation2);
    $error_data_query->condition('EC.relation_value', $relation1);
  }
  db_set_active();
  return $error_data_query->execute()->fetchAll();
}

/**
 * Return Part number descriptions.
 */
function souriau_toolkit_build_backshell_part_component_description($component_id, $value, $relation) {
  db_set_active('ect_tools');
  if ($relation > 0) {
    $comp_desc_query = db_select('bkshell_component_value', 'CV');
    $comp_desc_query->join('bkshell_component_group', 'CG', 'CG.group_id = CV.group_id');
    $comp_desc_query->join('bkshell_component_group_value', 'CGV', 'CGV.group_id = CG.group_id');
    $comp_desc_query->fields('CV', [
      'display_name',
    ]);
    $comp_desc_query->condition('CV.component_id', $component_id);
    $comp_desc_query->condition('CV.value', $value);
    $comp_desc_query->condition('CGV.group_value', $value);
    $comp_desc_query->condition('CGV.component_id', $component_id);
  }
  else {
    $comp_desc_query = db_select('bkshell_component_value', 'CV');
    $comp_desc_query->fields('CV', [
      'display_name',
    ]);
    $comp_desc_query->condition('CV.component_id', $component_id);
    $comp_desc_query->condition('CV.value', $value);
  }
  db_set_active();
  return $comp_desc_query->execute()->fetchAll();
}

/**
 * Return labels Part number descriptions.
 */
function souriau_toolkit_build_backshell_part_description_label($component_id, $component_value) {
  db_set_active('ect_tools');
  $desc_label_query = db_select('bkshell_part_build_label', 'PB');
  $desc_label_query->join('bkshell_component_type', 'CT', 'CT.component_type_id = PB.component_type_id');
  $desc_label_query->fields('CT', [
    'component_type',
  ]);
  $desc_label_query->condition('PB.component_id', $component_id);
  $desc_label_query->condition('PB.component_value', $component_value);
  db_set_active();
  return $desc_label_query->execute()->fetchAll();
}

/**
 * Return Dimension Group.
 */
function souriau_toolkit_build_backshell_get_dimension_group($part_id) {
  db_set_active('ect_tools');
  $dim_droup_query = db_select('bkshell_dimension_group', 'DG');
  $dim_droup_query->fields('DG');
  $dim_droup_query->condition('DG.part_id', $part_id);
  db_set_active();
  return $dim_droup_query->execute()->fetchAll();
}

/**
 * Return Dimension Data.
 */
function souriau_toolkit_build_backshell_get_dimension_label($part_id) {
  db_set_active('ect_tools');
  $dim_label_query = db_select('bkshell_dimension_group', 'DG');
  $dim_label_query->join('bkshell_dimensions', 'D', 'D.dimension_group_id = DG.dimension_group_id');
  $dim_label_query->join('bkshell_component_type', 'CT', 'CT.component_type_id = D.component_type_id');
  $dim_label_query->fields('D');
  $dim_label_query->fields('CT', [
    'component_type',
  ]);
  $dim_label_query->condition('DG.part_id', $part_id);
  db_set_active();
  return $dim_label_query->execute()->fetchAll();
}

/**
 * Return Dimension Data.
 */
function souriau_toolkit_build_backshell_get_dimension_data($part_id, $group_id, $pos_val, $rel_data) {
  db_set_active('ect_tools');
  if ($rel_data != NULL) {
    $dim_data_query = db_select('bkshell_dimension_group', 'DG');
    $dim_data_query->join('bkshell_dimensions_value', 'DV', 'DV.dimension_group_id = DG.dimension_group_id');
    $dim_data_query->join('bkshell_component_group', 'CG', 'CG.group_id = DV.group_id');
    $dim_data_query->join('bkshell_component_group_value', 'CGV', 'CGV.group_id = CG.group_id');
    $dim_data_query->fields('DV');
    $dim_data_query->condition('DG.part_id', $part_id);
    $dim_data_query->condition('DV.dimension_value', $pos_val);
    $dim_data_query->condition('DV.dimension_group_id', $group_id);
    $dim_data_query->condition('CGV.group_value', $rel_data);
  }
  else {
    $dim_data_query = db_select('bkshell_dimension_group', 'DG');
    $dim_data_query->join('bkshell_dimensions_value', 'DV', 'DV.dimension_group_id = DG.dimension_group_id');
    $dim_data_query->fields('DV');
    $dim_data_query->condition('DG.part_id', $part_id);
    $dim_data_query->condition('DV.dimension_value', $pos_val);
    $dim_data_query->condition('DV.dimension_group_id', $group_id);
  }
  db_set_active();
  return $dim_data_query->execute()->fetchAll();
}

/**
 * Return Dimension Data.
 */
function souriau_toolkit_build_backshell_get_part_noted($part_id) {
  db_set_active('ect_tools');
  $part_note_query = db_select('bkshell_part_notes', 'PN');
  $part_note_query->fields('PN', [
    'part_notes_id',
    'notes',
  ]);
  $part_note_query->condition('PN.part_id', $part_id);
  db_set_active();
  return $part_note_query->execute()->fetchAllKeyed();
}

/**
 * Return Sleeve component.
 */
function souriau_toolkit_build_backshell_get_sleeve_component($part_id) {
  db_set_active('ect_tools');
  $sleeve_comp_query = db_select('bkshell_sleeve_group', 'SG');
  $sleeve_comp_query->fields('SG');
  $sleeve_comp_query->condition('SG.part_id', $part_id);
  db_set_active();
  return $sleeve_comp_query->execute()->fetchAll();
}

/**
 * Return Sleeve data.
 */
function souriau_toolkit_build_backshell_get_sleeve_data($part_id, $entry_value) {
  db_set_active('ect_tools');
  $sleeve_data_query = db_select('bkshell_sleeve_value', 'SGV');
  $sleeve_data_query->fields('SGV', [
    'sleev_value',
  ]);
  $sleeve_data_query->condition('SGV.part_id', $part_id);
  $sleeve_data_query->condition('SGV.sleeve_entry_value', $entry_value);
  db_set_active();
  return $sleeve_data_query->execute()->fetchAll();
}
