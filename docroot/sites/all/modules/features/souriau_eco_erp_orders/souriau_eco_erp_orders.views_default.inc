<?php

/**
 * @file
 * souriau_eco_erp_orders.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_eco_erp_orders_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_eco_erp_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'Souriau Eco ERP Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'souriau_eco_erp_dashboard';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['id'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['field'] = 'commerce_customer_shipping_profile_id';
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  /* Field: Commerce order: Edit ERP */
  $handler->display->display_options['fields']['souriau_erp_link']['id'] = 'souriau_erp_link';
  $handler->display->display_options['fields']['souriau_erp_link']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['souriau_erp_link']['field'] = 'souriau_erp_link';
  $handler->display->display_options['fields']['souriau_erp_link']['label'] = 'ERP';
  /* Field: Commerce Order: Link */
  $handler->display->display_options['fields']['view_order']['id'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['view_order']['field'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['label'] = 'view';
  $handler->display->display_options['fields']['view_order']['text'] = 'view';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['label'] = 'Edit';
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'cart' => 'cart',
    'checkout_checkout' => 'checkout_checkout',
    'checkout_shipping' => 'checkout_shipping',
    'checkout_review' => 'checkout_review',
    'checkout_payment' => 'checkout_payment',
    'checkout_complete' => 'checkout_complete',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Order number */
  $handler->display->display_options['filters']['order_number']['id'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['order_number']['field'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['group'] = 1;
  $handler->display->display_options['filters']['order_number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_number']['expose']['operator_id'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['label'] = 'Order number';
  $handler->display->display_options['filters']['order_number']['expose']['operator'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['identifier'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Commerce Order: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['id'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['field'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Ordered Date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Field: Postal address - Company */
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['id'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['field'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['label'] = 'Company';
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['group_type'] = 'sum';
  $handler->display->display_options['fields']['quantity']['label'] = 'Total Quantity';
  $handler->display->display_options['fields']['quantity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Commerce Customer profile: Address - Pays */
  $handler->display->display_options['fields']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_country']['label'] = 'Shipment Country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['display_name'] = 1;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['label'] = 'Edit';
  /* Field: Commerce order: Edit ERP */
  $handler->display->display_options['fields']['souriau_erp_link']['id'] = 'souriau_erp_link';
  $handler->display->display_options['fields']['souriau_erp_link']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['souriau_erp_link']['field'] = 'souriau_erp_link';
  $handler->display->display_options['fields']['souriau_erp_link']['label'] = 'ERP';
  /* Field: Commerce Order: Link */
  $handler->display->display_options['fields']['view_order']['id'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['view_order']['field'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['label'] = 'view';
  $handler->display->display_options['fields']['view_order']['text'] = 'view';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Customer profile: Address - Pays */
  $handler->display->display_options['filters']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['filters']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['filters']['commerce_customer_address_country']['value'] = array(
    'CA' => 'CA',
    'CN' => 'CN',
    'MX' => 'MX',
    'US' => 'US',
  );
  $handler->display->display_options['filters']['commerce_customer_address_country']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'cart' => 'cart',
    'checkout_checkout' => 'checkout_checkout',
    'checkout_shipping' => 'checkout_shipping',
    'checkout_review' => 'checkout_review',
    'checkout_payment' => 'checkout_payment',
    'checkout_complete' => 'checkout_complete',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Order number */
  $handler->display->display_options['filters']['order_number']['id'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['order_number']['field'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['group'] = 1;
  $handler->display->display_options['filters']['order_number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_number']['expose']['operator_id'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['label'] = 'Order number';
  $handler->display->display_options['filters']['order_number']['expose']['operator'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['identifier'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Commerce Order: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Ordered Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  $handler->display->display_options['path'] = 'admin/dashboard/ecommerce/orders';
  $handler->display->display_options['menu']['title'] = 'Orders';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Sample Manager Dashboard */
  $handler = $view->new_display('page', 'Sample Manager Dashboard', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mouser Orders';
  $handler->display->display_options['display_description'] = 'This dashboard used by pn sample approval or cancellation by role sample managers';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'souriau_eco_erp_mouser_orders';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['id'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['field'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  /* Field: Commerce Order: Mouser Order Number */
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['id'] = 'field_commerce_mouser_orderno';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['table'] = 'field_data_field_commerce_mouser_orderno';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['field'] = 'field_commerce_mouser_orderno';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['label'] = 'Mouser Order';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: Field: Postal address - Company */
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['id'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['field'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['label'] = 'Company';
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  /* Field: Commerce Order: Mouser status */
  $handler->display->display_options['fields']['field_commerce_mouser_status']['id'] = 'field_commerce_mouser_status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['table'] = 'field_data_field_commerce_mouser_status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['field'] = 'field_commerce_mouser_status';
  /* Field: Commerce order: Edit ERP */
  $handler->display->display_options['fields']['souriau_erp_link']['id'] = 'souriau_erp_link';
  $handler->display->display_options['fields']['souriau_erp_link']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['souriau_erp_link']['field'] = 'souriau_erp_link';
  $handler->display->display_options['fields']['souriau_erp_link']['label'] = 'ERP';
  /* Field: Commerce Order: Link */
  $handler->display->display_options['fields']['view_order']['id'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['view_order']['field'] = 'view_order';
  $handler->display->display_options['fields']['view_order']['label'] = 'view';
  $handler->display->display_options['fields']['view_order']['text'] = 'view';
  /* Field: Commerce Order: Edit link */
  $handler->display->display_options['fields']['edit_order']['id'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['edit_order']['field'] = 'edit_order';
  $handler->display->display_options['fields']['edit_order']['label'] = 'Edit';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Approve';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'admin/commerce/orders/[order_number]/approve';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = 'Cancel';
  $handler->display->display_options['fields']['nothing_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['path'] = '/admin/commerce/orders/[order_number]/cancel';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Action';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[nothing_1] | [nothing_2]';
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'admin/commerce/orders/[order_number]/approve';
  $handler->display->display_options['fields']['nothing']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Customer profile: Address - Pays */
  $handler->display->display_options['filters']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['filters']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['filters']['commerce_customer_address_country']['value'] = array(
    'CA' => 'CA',
    'MX' => 'MX',
    'US' => 'US',
  );
  $handler->display->display_options['filters']['commerce_customer_address_country']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'cart' => 'cart',
    'checkout_checkout' => 'checkout_checkout',
    'checkout_shipping' => 'checkout_shipping',
    'checkout_review' => 'checkout_review',
    'checkout_payment' => 'checkout_payment',
    'checkout_complete' => 'checkout_complete',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Order number */
  $handler->display->display_options['filters']['order_number']['id'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['order_number']['field'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['group'] = 1;
  $handler->display->display_options['filters']['order_number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_number']['expose']['operator_id'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['label'] = 'Order number';
  $handler->display->display_options['filters']['order_number']['expose']['operator'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['identifier'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Commerce Order: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Commerce Order: Mouser status (field_commerce_mouser_status) */
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['id'] = 'field_commerce_mouser_status_value';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['table'] = 'field_data_field_commerce_mouser_status';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['field'] = 'field_commerce_mouser_status_value';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['value'] = 'waiting for approval';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/dashboard/ecommerce/mouser-orders';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Mouser Orders';
  $handler->display->display_options['menu']['description'] = 'All USA orders for sample managers';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Cron Job Orders */
  $handler = $view->new_display('page', 'Cron Job Orders', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Mouser Orders';
  $handler->display->display_options['display_description'] = 'Thisview for filtering orders to cron job';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Commerce Order */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_commerce_order';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  /* Field: Commerce Order: Mouser Order Number */
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['id'] = 'field_commerce_mouser_orderno';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['table'] = 'field_data_field_commerce_mouser_orderno';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['field'] = 'field_commerce_mouser_orderno';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['label'] = 'Mouser Order';
  $handler->display->display_options['fields']['field_commerce_mouser_orderno']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  /* Field: Commerce Order: Mouser status */
  $handler->display->display_options['fields']['field_commerce_mouser_status']['id'] = 'field_commerce_mouser_status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['table'] = 'field_data_field_commerce_mouser_status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['field'] = 'field_commerce_mouser_status';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = array(
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  /* Filter criterion: Commerce Order: Mouser status (field_commerce_mouser_status) */
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['id'] = 'field_commerce_mouser_status_value';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['table'] = 'field_data_field_commerce_mouser_status';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['field'] = 'field_commerce_mouser_status_value';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['value'] = 'shipped';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
  );
  /* Filter criterion: Commerce Order: Mouser status (field_commerce_mouser_status) */
  $handler->display->display_options['filters']['field_commerce_mouser_status_value_1']['id'] = 'field_commerce_mouser_status_value_1';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value_1']['table'] = 'field_data_field_commerce_mouser_status';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value_1']['field'] = 'field_commerce_mouser_status_value';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value_1']['operator'] = '!=';
  $handler->display->display_options['filters']['field_commerce_mouser_status_value_1']['value'] = 'waiting for approval';
  $handler->display->display_options['path'] = 'admin/dashboard/ecommerce/mouser-orders';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Mouser Orders';
  $handler->display->display_options['menu']['description'] = 'All USA orders for sample managers';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Commerce Order: Owner */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  /* Relationship: Commerce Order: Referenced customer profile */
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['id'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['table'] = 'field_data_commerce_customer_shipping';
  $handler->display->display_options['relationships']['commerce_customer_shipping_profile_id']['field'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order number */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'Order Number';
  $handler->display->display_options['fields']['order_number']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Ordered Date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated Date';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Field: Field: Postal address - Company */
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['id'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['field'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['label'] = 'Company';
  /* Field: Commerce Order: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['group_type'] = 'sum';
  $handler->display->display_options['fields']['quantity']['label'] = 'Total Quantity';
  $handler->display->display_options['fields']['quantity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Field: Commerce Customer profile: Address - Pays */
  $handler->display->display_options['fields']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_country']['label'] = 'Shipment Country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['display_name'] = 1;
  /* Field: Commerce Order: Order status */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['label'] = 'Order Status';
  $handler->display->display_options['fields']['status_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Customer profile: Address - Pays */
  $handler->display->display_options['filters']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['filters']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['filters']['commerce_customer_address_country']['relationship'] = 'commerce_customer_shipping_profile_id';
  $handler->display->display_options['filters']['commerce_customer_address_country']['value'] = array(
    'CA' => 'CA',
    'CN' => 'CN',
    'MX' => 'MX',
    'US' => 'US',
  );
  $handler->display->display_options['filters']['commerce_customer_address_country']['group'] = 1;
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'canceled' => 'canceled',
    'cart' => 'cart',
    'checkout_checkout' => 'checkout_checkout',
    'checkout_shipping' => 'checkout_shipping',
    'checkout_review' => 'checkout_review',
    'checkout_payment' => 'checkout_payment',
    'checkout_complete' => 'checkout_complete',
    'pending' => 'pending',
    'processing' => 'processing',
    'completed' => 'completed',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Filter criterion: Commerce Order: Order number */
  $handler->display->display_options['filters']['order_number']['id'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['order_number']['field'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['group'] = 1;
  $handler->display->display_options['filters']['order_number']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_number']['expose']['operator_id'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['label'] = 'Order number';
  $handler->display->display_options['filters']['order_number']['expose']['operator'] = 'order_number_op';
  $handler->display->display_options['filters']['order_number']['expose']['identifier'] = 'order_number';
  $handler->display->display_options['filters']['order_number']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Commerce Order: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    6 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Date: Date (commerce_order) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Select Order created Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'commerce_order.created' => 'commerce_order.created',
  );
  $handler->display->display_options['path'] = 'admin/dashboard/orders/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'page_1' => 0,
    'page_3' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/dashboard/ecommerce/orders';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['souriau_eco_erp_orders'] = array(
    t('Master'),
    t('Orders'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Order owner'),
    t('Customer profile referenced by commerce_customer_shipping'),
    t('Commerce Order'),
    t('- Choose an operation -'),
    t('Order number'),
    t('Updated date'),
    t('Name'),
    t('E-mail'),
    t('Order status'),
    t('ERP'),
    t('view'),
    t('Edit'),
    t('Page'),
    t('Line items referenced by commerce_line_items'),
    t('Ordered Date'),
    t('Company'),
    t('Total Quantity'),
    t('.'),
    t(','),
    t('Shipment Country'),
    t('Sample Manager Dashboard'),
    t('Mouser Orders'),
    t('This dashboard used by pn sample approval or cancellation by role sample managers'),
    t('Mouser Order'),
    t('First name'),
    t('Last name'),
    t('Mouser status'),
    t('Custom text'),
    t('Approve'),
    t('Cancel'),
    t('Action'),
    t('[nothing_1] | [nothing_2]'),
    t('Cron Job Orders'),
    t('Thisview for filtering orders to cron job'),
    t('Data export'),
    t('Order Number'),
    t('Updated Date'),
    t('Order Status'),
    t('Select Order created Date'),
  );
  $export['souriau_eco_erp_orders'] = $view;

  $view = new view();
  $view->name = 'user_sample_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'User Sample Orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User Sample Orders';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Commerce Order: Empty text */
  $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_order';
  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['label'] = 'Empty text';
  $handler->display->display_options['empty']['empty_text']['empty'] = TRUE;
  $handler->display->display_options['empty']['empty_text']['add_path'] = 'search';
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Order Date';
  $handler->display->display_options['fields']['created']['date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Commerce Order: Line items */
  $handler->display->display_options['fields']['commerce_line_items']['id'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['field'] = 'commerce_line_items';
  $handler->display->display_options['fields']['commerce_line_items']['label'] = 'Cart Items';
  $handler->display->display_options['fields']['commerce_line_items']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_line_items']['settings'] = array(
    'view' => 'commerce_line_item_table|default',
  );
  $handler->display->display_options['fields']['commerce_line_items']['delta_offset'] = '0';
  /* Field: Commerce Order: Shipment Tracking Link */
  $handler->display->display_options['fields']['field_commerce_shipping_link']['id'] = 'field_commerce_shipping_link';
  $handler->display->display_options['fields']['field_commerce_shipping_link']['table'] = 'field_data_field_commerce_shipping_link';
  $handler->display->display_options['fields']['field_commerce_shipping_link']['field'] = 'field_commerce_shipping_link';
  $handler->display->display_options['fields']['field_commerce_shipping_link']['label'] = 'Track Order';
  $handler->display->display_options['fields']['field_commerce_shipping_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_shipping_link']['alter']['text'] = 'Track Order';
  $handler->display->display_options['fields']['field_commerce_shipping_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_shipping_link']['alter']['path'] = '[field_commerce_shipping_link] ';
  $handler->display->display_options['fields']['field_commerce_shipping_link']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_commerce_shipping_link']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Shipped Date */
  $handler->display->display_options['fields']['field_commerce_shipped_date']['id'] = 'field_commerce_shipped_date';
  $handler->display->display_options['fields']['field_commerce_shipped_date']['table'] = 'field_data_field_commerce_shipped_date';
  $handler->display->display_options['fields']['field_commerce_shipped_date']['field'] = 'field_commerce_shipped_date';
  $handler->display->display_options['fields']['field_commerce_shipped_date']['settings'] = array(
    'format_type' => 'long',
    'custom_date_format' => '',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'samples_order' => 'samples_order',
  );

  /* Display: User Sample Orders */
  $handler = $view->new_display('page', 'User Sample Orders', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Users sample orders listing';
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ ';
  $handler->display->display_options['pager']['options']['tags']['next'] = ' ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = ' »';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_id' => 'order_id',
    'created' => 'created',
    'commerce_line_items' => 'commerce_line_items',
    'field_commerce_shipping_link' => 'field_commerce_shipping_link',
    'field_commerce_shipped_date' => 'field_commerce_shipped_date',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'order_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_line_items' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_shipping_link' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_commerce_shipped_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['element_label_colon'] = FALSE;
  /* Field: Commerce Order: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Ordered Date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm-d-Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Commerce Order: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm-d-Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Commerce Order: Shipped Date */
  $handler->display->display_options['fields']['field_commerce_shipped_date']['id'] = 'field_commerce_shipped_date';
  $handler->display->display_options['fields']['field_commerce_shipped_date']['table'] = 'field_data_field_commerce_shipped_date';
  $handler->display->display_options['fields']['field_commerce_shipped_date']['field'] = 'field_commerce_shipped_date';
  $handler->display->display_options['fields']['field_commerce_shipped_date']['settings'] = array(
    'format_type' => 'custom',
    'custom_date_format' => 'm-d-Y',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Commerce Order: Mouser status */
  $handler->display->display_options['fields']['field_commerce_mouser_status']['id'] = 'field_commerce_mouser_status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['table'] = 'field_data_field_commerce_mouser_status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['field'] = 'field_commerce_mouser_status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['label'] = 'Order status';
  $handler->display->display_options['fields']['field_commerce_mouser_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Commerce Order: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Created date';
  $handler->display->display_options['sorts']['created']['granularity'] = 'minute';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Commerce Order: Order type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'samples_order' => 'samples_order',
  );
  /* Filter criterion: Commerce Order: Order status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['operator'] = 'not in';
  $handler->display->display_options['filters']['status']['value'] = array(
    'cart' => 'cart',
    'checkout_checkout' => 'checkout_checkout',
    'checkout_shipping' => 'checkout_shipping',
    'checkout_review' => 'checkout_review',
    'checkout_payment' => 'checkout_payment',
    'checkout_complete' => 'checkout_complete',
  );
  $handler->display->display_options['path'] = 'user_sample_orders';
  $handler->display->display_options['menu']['title'] = 'Sample Orders';
  $handler->display->display_options['menu']['description'] = 'Users Sample orders history listing';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['user_sample_orders'] = array(
    t('Master'),
    t('User Sample Orders'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Empty text'),
    t('Order ID'),
    t('Order Date'),
    t('Cart Items'),
    t('Track Order'),
    t('Shipped Date'),
    t('All'),
    t('Users sample orders listing'),
    t('«'),
    t('‹ '),
    t(' ›'),
    t(' »'),
    t('Ordered Date'),
    t('Updated date'),
    t('Order status'),
    t('Created date'),
  );
  $export['user_sample_orders'] = $view;

  $view = new view();
  $view->name = 'user_sample_orders_details';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'user_sample_orders_details';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_id' => 'order_id',
    'commerce_line_items' => 'commerce_line_items',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'order_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_line_items' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Commerce Order: Referenced line items */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = 'Line Number';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Commerce Line item: Product */
  $handler->display->display_options['fields']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_product']['type'] = 'commerce_product_reference_sku_plain';
  $handler->display->display_options['fields']['commerce_product']['settings'] = array(
    'show_quantity' => 0,
    'default_quantity' => '1',
    'combine' => 1,
    'show_single_product_attributes' => 0,
    'line_item_type' => 'product',
  );
  /* Field: Commerce Line Item: Quantity */
  $handler->display->display_options['fields']['quantity']['id'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['table'] = 'commerce_line_item';
  $handler->display->display_options['fields']['quantity']['field'] = 'quantity';
  $handler->display->display_options['fields']['quantity']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['quantity']['precision'] = '0';
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Commerce Order: Order number */
  $handler->display->display_options['arguments']['order_number']['id'] = 'order_number';
  $handler->display->display_options['arguments']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_number']['field'] = 'order_number';
  $handler->display->display_options['arguments']['order_number']['default_action'] = 'default';
  $handler->display->display_options['arguments']['order_number']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['order_number']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['order_number']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_number']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_number']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['order_number']['limit'] = '0';
  $translatables['user_sample_orders_details'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Line items referenced by commerce_line_items'),
    t('Line Number'),
    t('Product'),
    t('Quantity'),
    t('.'),
    t(','),
    t('All'),
  );
  $export['user_sample_orders_details'] = $view;

  return $export;
}
