<?php
/**
 * @file
 * Function for addressfield module. Used when addrassfield_phone module non exist.
 */

/**
 * Returns an array of the field names of any addressfields.
 */
function _souriau_common_addressfield_types() {
  if (!isset($addressfields)) {
    static $addressfields;
    $result = db_query("SELECT field_name FROM {field_config} WHERE type = 'addressfield'");
    $addressfields = array();
    foreach ($result as $row) {
      $addressfields[] = $row->field_name;
    }
  }
  return $addressfields;
}
