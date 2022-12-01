<?php
/**
 * @file
 * External DB Sales Order.
 */

define('SOURIAU_ECO_ERP_ORDER_STATUS_NO_SHIPPED', 0);
define('SOURIAU_ECO_ERP_ORDER_STATUS_SHIPPED', 1);
define('SOURIAU_ECO_ERP_ORDER_ITEMS_PER_PAGE', 12);

/**
 * Load Order Data by Order ID.
 *
 * @param string $order_id
 *   ERP Order ID.
 * @param bool $full
 *   If FALSE Order will be load without order Items.
 */
function souriau_eco_load_user_order_data($order_id, $full = TRUE) {

  db_set_active('sales_order');

  $select = db_select('sales_order', 'so');
  $select->fields('so');
  $select->condition('so_no', $order_id, '=');
  $result = $select->execute();

  if ($result->rowCount() > 0) {
    $order = $result->fetchObject();

    $order->order_items = [];

    if ($full) {
      $order->order_items = souriau_eco_load_order_items($order_id);
    }

    return $order;
  }

  db_set_active();

  return;
}

/**
 * Load Order Items by Order ID.
 */
function souriau_eco_load_order_items($order_id) {

  db_set_active('sales_order');

  $select = db_select('sales_order_line', 'sol');
  $select->fields('sol');
  $select->condition('so_no', $order_id, '=');
  $result = $select->execute();

  $orders = [];
  if ($result->rowCount() > 0) {
    $orders = $result->fetchAll();
  }

  db_set_active();

  return $orders;
}

/**
 * Load Orders by User ERP Code(s).
 */
function souriau_eco_load_user_orders($customer_erp_code, $order_status, $offset = 0, $limit = SOURIAU_ECO_ERP_ORDER_ITEMS_PER_PAGE) {

  $codes = is_array($customer_erp_code) ? $customer_erp_code : [$customer_erp_code];

  if (count($codes) == 0) {
    return;
  }

  db_set_active('sales_order');

  $select = db_select('sales_order', 'so');
  $select->fields('so');
  $select->condition('so.cust_erp_code', $codes, 'IN');
  $select->where("IF(so.`order_status` = 'Fully Shipped', 1, 0) = {$order_status}");
  $select->groupBy('so.so_no');
  $select->orderBy('so.so_last_update_date', 'DESC');
  $select->range($offset, $limit);
  $result = $select->execute();

  $orders = [];
  if ($result->rowCount() > 0) {
    $orders = $result->fetchAll();
  }

  db_set_active();

  return $orders;
}

/**
 * Load Orders by User ERP Code(s).
 */
function souriau_eco_load_user_orders_count($customer_erp_code, $order_status) {

  $codes = is_array($customer_erp_code) ? $customer_erp_code : [$customer_erp_code];

  if (count($codes) == 0) {
    return;
  }

  db_set_active('sales_order');

  $select = db_select('sales_order', 'so');
  $select->addExpression("COUNT(distinct so.`so_no`)", 'count');
  $select->condition('so.cust_erp_code', $codes, 'IN');
  $select->where("IF(so.`order_status` = 'Fully Shipped', 1, 0) = {$order_status}");

  $count = $select->execute()->fetchObject()->count;

  db_set_active();

  return $count;
}

/**
 * Return information about order from external DB.
 *
 * @param array $arg
 *   Array with arguments for query.
 * @param string $database
 *   Key of external DB.
 *
 * @return object|bool
 *   Single order object.
 */
function souriau_eco_load_user_orders_info($arg, $database = 'sales_order') {

  if (!empty($arg['order_id'])) {
    // Return single order with items.
    db_set_active($database);
    $order = souriau_eco_load_user_order_data($arg['order_id']);
    db_set_active();
    return $order;
  }

  return;
}
