<?php
/**
 * @file
 * Function for work with database.
 */

/**
 * DB_Insert.
 *
 * @param array $data
 *   Array with data, like ['field_name' => 'value'].
 *
 * @throws \Exception
 */
function souriau_eco_erp_db_insert($data) {
  if (!isset($data['order_id'])) {
    return;
  }

  db_insert('souriau_eco_erp')
    ->fields($data)
    ->execute();

  return Database::getConnection()->lastInsertId();
}

/**
 * DB Select.
 *
 * @param array $conditions
 *   Condition array like ['field_name' => 'value']
 *   or ['field_name' => [
 *        'value' => ['value'],
 *        'operator' => 'value',
 *      ]].
 * @param mixed $fields
 *   Array of filed for select or NUll.
 * @param int $limit
 *   Select limit.
 *
 * @return mixed
 *   Early return.
 */
function souriau_eco_erp_db_select($conditions = [], $fields = NULL, $limit = 25) {
  $query = db_select('souriau_eco_erp', 'eco');
  if (!empty($fields)) {
    $fields = is_array($fields) ? $fields : [$fields];
    $query->fields('eco', $fields);
  }
  else {
    $query->fields('eco');
  }

  foreach ($conditions as $field => $condition) {
    if (is_array($condition)) {
      $query->condition($field, $condition['value'], $condition['operator']);
    }
    else {
      $query->condition($field, $condition, '=');
    }
  }
  $query->orderBy('goid', 'DESC');
  $query->extend('PagerDefault');
  $query->range(0, $limit);

  $result = $query->execute();
  return $result->fetchAll();
}

/**
 * DB_Update.
 *
 * @param array $data
 *   Array with data, like ['field_name' => 'value'].
 */
function souriau_eco_erp_db_update($data) {
  db_update('souriau_eco_erp')
    ->fields($data)
    ->condition('goid', $data['goid'], '=')
    ->execute();
}
