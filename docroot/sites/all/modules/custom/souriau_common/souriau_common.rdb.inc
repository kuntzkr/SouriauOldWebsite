<?php
/**
 * @file
 * Functions to work with ReferenceDB.
 */

/**
 * Fetch all $sql results from specified RDB.
 *
 * @param string $db
 *   Name of DB to select from.
 * @param string $sql
 *   SQL query.
 * @param mixed $keys
 *   Defines result structure.
 *   If not given returns array of objects.
 * @param array $args
 *   Array of arguments to $sql query.
 * @param array $options
 *   An array of options to control how the query operates.
 */
function souriau_common_rdb_fetch_all($db, $sql, $keys = NULL, array $args = array(), array $options = array()) {
  try {
    db_set_active($db);

    $query = db_query($sql, $args, $options);
    if (empty($keys)) {
      // Retrieve all records into an indexed array of stdClass objects.
      return $query->fetchAll();
    }
    elseif (is_string($keys)) {
      // If string is given then retrieve all records as stdObjects
      // into an associative array keyed by the field in the result.
      return $query->fetchAllAssoc($keys);
    }
    if (is_array($keys)) {
      // Also good to note that you can specify which two fields to use
      // by specifying the column numbers for each field.
      return $query->fetchAllKeyed($keys[0], $keys[1]);
    }
  }
  catch (Exception $e) {
    // Log exception.
    watchdog('ea_common:rdb', 'Exception: !exception in !function on !sql.', array(
      '!exception' => $e->getMessage(),
      '!function' => __FUNCTION__,
      '!sql' => $sql,
    ), WATCHDOG_ERROR);
  }
  finally {
    // Restore DB.
    db_set_active();
  }

  // Return result anyway.
  return NULL;
}

/**
 * Fetch filed value $sql results from specified RDB.
 *
 * @param string $db
 *   Name of DB to select from.
 * @param string $sql
 *   SQL query.
 * @param array $args
 *   Array of arguments to $sql query.
 * @param array $options
 *   An array of options to control how the query operates.
 */
function souriau_common_rdb_fetch_field($db, $sql, array $args = array(), array $options = array()) {
  try {
    db_set_active($db);
    $query = db_query($sql, $args, $options);
    return $query->fetchField();
  }
  catch (Exception $e) {
    // Log exception.
    watchdog('souriau_common:rdb', 'Exception: !exception in !function on !sql.', array(
      '!exception' => $e->getMessage(),
      'function' => __FUNCTION__,
      '!sql' => $sql,
    ), WATCHDOG_ERROR);
  }
  finally {
    // Restore DB.
    db_set_active();
  }

  // Return result anyway.
  return NULL;
}

/**
 * Return boolean value, available on stock or not.
 */
function souriau_common_rdb_get_part_number_stock_status($pn, $is_sample = FALSE, $is_mouser = FALSE) {
  if (empty($pn)) {
    // Nothing to do here.
    return FALSE;
  }

  // If sample request, use table Samples.
  $table = 'stock';
  if ($is_sample) {
    $table = 'samples';
  }
  if ($is_mouser) {
    $table = 'mouser_stock';
  }

  // Need to set settings about external DB into settings.php.
  // Need to set table name.
  $db = 'stock_management';
  $select = db_select($table, 's')
    ->fields('s')
    ->condition('part_number', $pn, '=')
    ->condition('quantity', 0, '>');
  if ($table == 'stock') {
    $current_domain = domain_get_domain();
    $domain_country = domain_conf_variable_get($current_domain['domain_id'], 'geo_countries');
    if (!isset($domain_country['none'])) {
      $domain_country = array_values($domain_country);
      $all_countries = country_get_list();
      $country_name = drupal_strtoupper($all_countries[$domain_country[0]]);
      $select->addExpression("CASE WHEN country LIKE '%{$country_name}%' THEN 1 ELSE 2 END", 'order_col');
      $select->orderBy('order_col', 'ASC');
    }
  }
  $sql = $select->__toString();
  $arg = $select->getArguments();
  $result = souriau_common_rdb_fetch_all($db, $sql, NULL, $arg);

  // Check result.
  if ($result) {
    return $result;
  }
  return FALSE;
}
