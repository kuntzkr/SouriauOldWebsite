<?php
/**
 * @file
 * Functions to work with tools database.
 */

/**
 * Return all the components of a family in component position order.
 *
 * @param string $family_id
 *   Unique ID of family.
 * @param bool $skip_first
 *   Skip first component.
 *
 * @return Object array
 *   Family resultset.
 */
function souriau_toolkit_cross_ref_get_components($family_id, $skip_first = TRUE) {
  db_set_active('ect_tools');
  $comp_query = db_select('xref_component', 'C');
  $comp_query->join('xref_component_type', 'CT', 'CT.component_type_id = C.component_type_id');
  $comp_query->fields('C', [
    'component_id',
    'component_type_id',
    'component_position',
    'component_min_length',
    'component_max_length',
  ]);
  $comp_query->fields('CT', [
    'component_type',
  ]);

  $comp_query->condition('family_id', $family_id)
      ->condition('status', 1);
  if ($skip_first) {
    $comp_query->condition('component_position', 1, '<>');
  }

  $comp_query->orderBy('component_position', 'ASC');

  db_set_active();
  return $comp_query->execute()->fetchAll();
}

/**
 * Check for the value match in the component value table.
 *
 * @param string $value
 *   Search value.
 * @param string $component_id
 *   Unique ID of component.
 *
 * @return Object array
 *   Returns the result set if there is any match.
 */
function souriau_toolkit_cross_ref_component_value_match($value, $component_id = NULL) {
  db_set_active('ect_tools');
  // Remove the leading 0 from the value string.
  $value_search = ltrim($value, '0');

  $comp_val_query = db_select('xref_component_values', 'CV');
  $comp_val_query->join('xref_component', 'C', 'C.component_id = CV.component_id');
  $comp_val_query->join('xref_component_type', 'CT', 'CT.component_type_id = C.component_type_id');

  // If, after removing the 0, the string does'nt becomes '', that means the value was 0.
  if ($value_search != '' && !is_null($component_id)) {
    // Remove the leading 0 from the value column for comparison.
    $comp_val_query->where("TRIM(LEADING '0' FROM REPLACE(value, '-', '')) = :val", [':val' => $value_search]);
  }
  else {
    // The case when the value is 0.
    $comp_val_query->where("REPLACE(CV.value, '-', '') = :val", [':val' => $value]);
  }

  $comp_val_query->fields('CV', [
    'component_id',
    'component_value_id',
    'description',
  ]);

  if (is_null($component_id)) {
    $comp_val_query->join('xref_company', 'CM', 'CM.company_id = C.company_id');
    $comp_val_query->join('xref_family', 'F', 'F.family_id = C.family_id');
    $comp_val_query->fields('F', ['family_id', 'family_name']);
    $comp_val_query->fields('CM', ['company_name']);
    $comp_val_query->condition('C.component_position', 1);
  }
  else {
    $comp_val_query->condition('CV.component_id', $component_id);
  }

  $comp_val_query->fields('CT', [
    'component_type',
  ]);

  $comp_val_query->fields('C', [
    'component_min_length',
    'component_max_length',
  ]);

  $comp_val_query->addField('CV', 'value', 'component_match');
  db_set_active();
  return $comp_val_query->execute()->fetchObject();
}

/**
 * Get the min and max length of all family.
 */
function souriau_toolkit_cross_ref_get_family_lengths() {
  db_set_active('ect_tools');
  $length_query = db_select('xref_component', 'C');
  $length_query->addExpression('min(component_min_length)', 'min_length');
  $length_query->addExpression('max(component_max_length)', 'max_length');
  $length_query->condition('status', 1)
      ->condition('component_position', 1);

  db_set_active();
  return $length_query->execute()->fetchObject();
}

/**
 * Get all the rows that contains the value of the component from the relation.
 *
 * @param string $component_id
 *   Unique ID of component.
 * @param string $value_id
 *   Unique ID of value.
 *
 * @return Object Array
 *   Relation data resultset.
 */
function souriau_toolkit_cross_ref_get_relation_rows($component_id, $value_id) {
  db_set_active('ect_tools');
  $rows_query = db_select('xref_group_relation_rows', 'RR');
  $rows_query->join('xref_group_relation_values', 'RV', 'RV.row_id = RR.row_id');
  $rows_query->join('xref_group_relation', 'GR', 'GR.group_relation_id = RR.group_relation_id');
  $rows_query->join('xref_group_component', 'GC', 'GC.group_id = GR.relation_for_group');
  $rows_query->fields('RR', [
    'row_id',
  ]);
  $rows_query->condition('GC.component_id', $component_id)->condition('RV.value_id', $value_id);

  db_set_active();
  return $rows_query->distinct()->execute()->fetchAll();
}

/**
 * Fetch all the components related to a component in a row.
 *
 * @param string $row_id
 *   Unique ID of row.
 * @param string $component_id
 *   Unique ID of component.
 *
 * @return Object Array
 *   Related components.
 */
function souriau_toolkit_cross_ref_get_related_components($row_id, $component_id) {
  db_set_active('ect_tools');
  $rel_comp_query = db_select('xref_group_relation_values', 'RV');
  $rel_comp_query->join('xref_component_values', 'CV', 'CV.component_value_id = RV.value_id');
  $rel_comp_query->fields('RV');
  $rel_comp_query->fields('CV');
  $rel_comp_query->condition('RV.row_id', $row_id);
  $rel_comp_query->condition('CV.component_id', $component_id, '<>');

  db_set_active();
  return $rel_comp_query->execute()->fetchAll();
}

/**
 * Check if the component has any relation with other components.
 *
 * @param string $component_id
 *   Unique ID of component.
 *
 * @return Int Row count
 *   Number of relations of a component.
 */
function souriau_toolkit_cross_ref_component_has_relation($component_id) {
  db_set_active('ect_tools');
  $result = db_select('xref_group_component', 'GC');
  $result->join('xref_group_relation', 'GR', 'GC.group_id = GR.relation_for_group');
  $result->fields('GC');
  $result->condition('component_id', $component_id);

  db_set_active();
  return $result->execute()->rowCount();
}

/**
 * Get souriay family details for a competitor family.
 *
 * @param string $competitor_component_id
 *   Unique ID of component.
 *
 * @return Object Array
 *   Family details.
 */
function souriau_toolkit_cross_ref_get_souriau_family($competitor_component_id) {
  db_set_active('ect_tools');
  $result = db_select('xref_group_cross', 'G');
  $result->join('xref_group_component', 'GC', 'GC.group_id = G.based_on_group');
  $result->join('xref_group_component', 'SG', 'SG.group_id = G.cross_for_group');
  $result->join('xref_component', 'C', 'C.component_id = SG.component_id');
  $result->join('xref_family', 'F', 'C.family_id = F.family_id');
  $result->join('xref_company', 'CM', 'CM.company_id = F.company_id');
  $result->fields('C', ['family_id']);
  $result->fields('F', ['family_name']);
  $result->fields('CM', ['company_name', 'company_id']);
  $result->condition('GC.component_id', $competitor_component_id);

  db_set_active();
  return $result->execute()->fetchObject();
}

/**
 * Get all the rows that contains the value of the component from the cross.
 *
 * @param string $component_id
 *   Unique ID of component.
 * @param string $competitor_family_id
 *   Unique ID of family.
 *
 * @return Object Array
 *   Cross details.
 */
function souriau_toolkit_cross_ref_get_cross_rows($component_id, $competitor_family_id) {
  db_set_active('ect_tools');
  $rows_query = db_select('xref_group_cross_rows', 'RR');
  $rows_query->join('xref_group_cross', 'GR', 'GR.group_cross_id = RR.group_cross_id');
  $rows_query->join('xref_group_component', 'GC', 'GC.group_id = GR.cross_for_group');
  $rows_query->join('xref_group', 'GCOM', 'GCOM.group_id = GR.based_on_group');
  $rows_query->join('xref_group_cross_values', 'RV', 'RV.row_id = RR.row_id');
  $rows_query->addExpression('count(RR.row_id)', 'row_cnt');
  $rows_query->fields('RR', [
    'row_id',
  ]);
  $rows_query->condition('GC.component_id', $component_id);
  $rows_query->condition('GCOM.family_id', $competitor_family_id);
  $rows_query->orderBy('row_cnt', 'DESC');
  $rows_query->groupBy('RV.row_id');

  db_set_active();
  return $rows_query->distinct()->execute()->fetchAll();
}

/**
 * Fetch all the components cross to a component in a row.
 *
 * @param string $row_id
 *   Row id of relations.
 *
 * @return Object Array
 *   Cross component results.
 */
function souriau_toolkit_cross_ref_get_cross_components($row_id) {
  db_set_active('ect_tools');
  $rel_comp_query = db_select('xref_group_cross_values', 'RV');
  $rel_comp_query->join('xref_component_values', 'CV', 'CV.component_value_id = RV.value_id');
  $rel_comp_query->fields('RV');
  $rel_comp_query->fields('CV');
  $rel_comp_query->condition('RV.row_id', $row_id);

  db_set_active();
  return $rel_comp_query->execute()->fetchAll();
}

/**
 * Fetch the applications related to a family.
 *
 * @param string $family_id
 *   Unique ID of family.
 *
 * @return Object Array
 *   Component application details.
 */
function souriau_toolkit_cross_ref_get_applications($family_id) {
  db_set_active('ect_tools');
  $appl_query = db_select('xref_group_applicable', 'GA');
  $appl_query->join('xref_component', 'C', 'C.component_id = GA.component_is_applicable');
  $appl_query->fields('GA');
  $appl_query->condition('C.family_id', $family_id);

  db_set_active();
  return $appl_query->execute()->fetchAll();
}

/**
 * Fetch the rows related to the applications.
 *
 * @param string $application_id
 *   Unique ID of application.
 *
 * @return Object Array
 *   Component application details.
 */
function souriau_toolkit_cross_ref_get_application_rows($application_id) {
  db_set_active('ect_tools');
  $appl_row_query = db_select('xref_group_applicable_rows', 'R');
  $appl_row_query->fields('R');
  $appl_row_query->condition('R.application_id', $application_id);

  db_set_active();
  return $appl_row_query->execute()->fetchAll();
}

/**
 * Fetch the components on a row related to the application.
 *
 * @param string $row_id
 *   Unique ID of application rows.
 *
 * @return Object Array
 *   Component applications details.
 */
function souriau_toolkit_cross_ref_get_application_components($row_id) {
  db_set_active('ect_tools');
  $appl_value_query = db_select('xref_group_applicable_values', 'RV');
  $appl_value_query->join('xref_component_values', 'CV', 'CV.component_value_id = RV.value_id');
  $appl_value_query->fields('RV');
  $appl_value_query->fields('CV');
  $appl_value_query->condition('RV.row_id', $row_id);

  db_set_active();
  return $appl_value_query->execute()->fetchAll();
}
