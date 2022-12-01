<?php

/**
 * @file
 * souriau_entity_distributor.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_entity_distributor_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dashboard_souriau_distributors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_distributor';
  $view->human_name = 'Dashboard Souriau Distributors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dashboard Souriau Distributors';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    17 => '17',
    18 => '18',
    11 => '11',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'field_distributor_name' => 'field_distributor_name',
    'field_type' => 'field_type',
    'field_distributor_brand' => 'field_distributor_brand',
    'field_url' => 'field_url',
    'field_postal_address_country' => 'field_postal_address_country',
    'field_postal_address_thoroughfare' => 'field_postal_address_thoroughfare',
    'field_postal_address_premise' => 'field_postal_address_thoroughfare',
    'field_postal_address_locality' => 'field_postal_address_locality',
    'field_postal_address_data' => 'field_postal_address_data',
    'field_email' => 'field_email',
    'edit_link' => 'edit_link',
    'delete_link' => 'edit_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_distributor_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_distributor_brand' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_url' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_postal_address_country' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_postal_address_thoroughfare' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&ensp;',
      'empty_column' => 0,
    ),
    'field_postal_address_premise' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_postal_address_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_postal_address_data' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_email' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => '&ensp;',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Distributor: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_distributor';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Distributor: Distributor Code */
  $handler->display->display_options['fields']['field_distributor_code']['id'] = 'field_distributor_code';
  $handler->display->display_options['fields']['field_distributor_code']['table'] = 'field_data_field_distributor_code';
  $handler->display->display_options['fields']['field_distributor_code']['field'] = 'field_distributor_code';
  $handler->display->display_options['fields']['field_distributor_code']['label'] = 'Code';
  /* Field: Distributor: Name */
  $handler->display->display_options['fields']['field_distributor_name']['id'] = 'field_distributor_name';
  $handler->display->display_options['fields']['field_distributor_name']['table'] = 'field_data_field_distributor_name';
  $handler->display->display_options['fields']['field_distributor_name']['field'] = 'field_distributor_name';
  /* Field: Distributor: Type */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  /* Field: Distributor: Brand */
  $handler->display->display_options['fields']['field_distributor_brand']['id'] = 'field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['table'] = 'field_data_field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['field'] = 'field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['delta_offset'] = '0';
  /* Field: Distributor: Website Url */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  /* Field: Field: Postal address - Country */
  $handler->display->display_options['fields']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_postal_address_country']['display_name'] = 1;
  /* Field: Field: Postal address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['id'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['field'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['label'] = 'Address';
  /* Field: Field: Postal address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_postal_address_premise']['id'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_premise']['field'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['label'] = 'Address2';
  /* Field: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['label'] = 'City';
  /* Field: Field: Postal address with phone number */
  $handler->display->display_options['fields']['field_postal_address_data']['id'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_data']['field'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_postal_address_data']['selected_phone_type'] = '1';
  /* Field: Distributor: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  /* Field: Distributor: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_distributor';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Operations';
  /* Field: Distributor: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_distributor';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['text'] = 'delete';
  /* Filter criterion: Distributor: distributor type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_distributor';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'distributor' => 'distributor',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Distributor: Id */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'eck_distributor';
  $handler->display->display_options['filters']['id']['field'] = 'id';
  $handler->display->display_options['filters']['id']['group'] = 1;
  $handler->display->display_options['filters']['id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['id']['expose']['operator_id'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['label'] = 'Id';
  $handler->display->display_options['filters']['id']['expose']['operator'] = 'id_op';
  $handler->display->display_options['filters']['id']['expose']['identifier'] = 'id';
  $handler->display->display_options['filters']['id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Distributor: Distributor Code (field_distributor_code) */
  $handler->display->display_options['filters']['field_distributor_code_value']['id'] = 'field_distributor_code_value';
  $handler->display->display_options['filters']['field_distributor_code_value']['table'] = 'field_data_field_distributor_code';
  $handler->display->display_options['filters']['field_distributor_code_value']['field'] = 'field_distributor_code_value';
  $handler->display->display_options['filters']['field_distributor_code_value']['group'] = 1;
  $handler->display->display_options['filters']['field_distributor_code_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distributor_code_value']['expose']['operator_id'] = 'field_distributor_code_value_op';
  $handler->display->display_options['filters']['field_distributor_code_value']['expose']['label'] = 'Distributor Code';
  $handler->display->display_options['filters']['field_distributor_code_value']['expose']['operator'] = 'field_distributor_code_value_op';
  $handler->display->display_options['filters']['field_distributor_code_value']['expose']['identifier'] = 'field_distributor_code_value';
  $handler->display->display_options['filters']['field_distributor_code_value']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Distributor: Name (field_distributor_name) */
  $handler->display->display_options['filters']['field_distributor_name_value']['id'] = 'field_distributor_name_value';
  $handler->display->display_options['filters']['field_distributor_name_value']['table'] = 'field_data_field_distributor_name';
  $handler->display->display_options['filters']['field_distributor_name_value']['field'] = 'field_distributor_name_value';
  $handler->display->display_options['filters']['field_distributor_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_distributor_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_distributor_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distributor_name_value']['expose']['operator_id'] = 'field_distributor_name_value_op';
  $handler->display->display_options['filters']['field_distributor_name_value']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['field_distributor_name_value']['expose']['operator'] = 'field_distributor_name_value_op';
  $handler->display->display_options['filters']['field_distributor_name_value']['expose']['identifier'] = 'field_distributor_name_value';
  $handler->display->display_options['filters']['field_distributor_name_value']['expose']['remember_roles'] = array(
    2 => '2',
  );
  /* Filter criterion: Distributor: Brand (field_distributor_brand) */
  $handler->display->display_options['filters']['field_distributor_brand_value']['id'] = 'field_distributor_brand_value';
  $handler->display->display_options['filters']['field_distributor_brand_value']['table'] = 'field_data_field_distributor_brand';
  $handler->display->display_options['filters']['field_distributor_brand_value']['field'] = 'field_distributor_brand_value';
  $handler->display->display_options['filters']['field_distributor_brand_value']['group'] = 1;
  $handler->display->display_options['filters']['field_distributor_brand_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distributor_brand_value']['expose']['operator_id'] = 'field_distributor_brand_value_op';
  $handler->display->display_options['filters']['field_distributor_brand_value']['expose']['label'] = 'Brand';
  $handler->display->display_options['filters']['field_distributor_brand_value']['expose']['operator'] = 'field_distributor_brand_value_op';
  $handler->display->display_options['filters']['field_distributor_brand_value']['expose']['identifier'] = 'field_distributor_brand_value';
  $handler->display->display_options['filters']['field_distributor_brand_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
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
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
    46 => 0,
  );
  /* Filter criterion: Field: Postal address - Country */
  $handler->display->display_options['filters']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['filters']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['filters']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['filters']['field_postal_address_country']['group'] = 1;
  $handler->display->display_options['filters']['field_postal_address_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['operator_id'] = 'field_postal_address_country_op';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['operator'] = 'field_postal_address_country_op';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['identifier'] = 'field_postal_address_country';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Distributor: Email (field_email) */
  $handler->display->display_options['filters']['field_email_email']['id'] = 'field_email_email';
  $handler->display->display_options['filters']['field_email_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['filters']['field_email_email']['field'] = 'field_email_email';
  $handler->display->display_options['filters']['field_email_email']['group'] = 1;
  $handler->display->display_options['filters']['field_email_email']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_email_email']['expose']['operator_id'] = 'field_email_email_op';
  $handler->display->display_options['filters']['field_email_email']['expose']['label'] = 'Email';
  $handler->display->display_options['filters']['field_email_email']['expose']['operator'] = 'field_email_email_op';
  $handler->display->display_options['filters']['field_email_email']['expose']['identifier'] = 'field_email_email';
  $handler->display->display_options['filters']['field_email_email']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['path'] = 'admin/dashboard/distributors';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Distributors';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'distributors-list-%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Distributor: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_distributor';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Distributor: Distributor Code */
  $handler->display->display_options['fields']['field_distributor_code']['id'] = 'field_distributor_code';
  $handler->display->display_options['fields']['field_distributor_code']['table'] = 'field_data_field_distributor_code';
  $handler->display->display_options['fields']['field_distributor_code']['field'] = 'field_distributor_code';
  $handler->display->display_options['fields']['field_distributor_code']['label'] = 'Code';
  /* Field: Distributor: Name */
  $handler->display->display_options['fields']['field_distributor_name']['id'] = 'field_distributor_name';
  $handler->display->display_options['fields']['field_distributor_name']['table'] = 'field_data_field_distributor_name';
  $handler->display->display_options['fields']['field_distributor_name']['field'] = 'field_distributor_name';
  /* Field: Distributor: Type */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  /* Field: Distributor: Brand */
  $handler->display->display_options['fields']['field_distributor_brand']['id'] = 'field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['table'] = 'field_data_field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['field'] = 'field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['delta_offset'] = '0';
  /* Field: Distributor: Website Url */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  /* Field: Field: Postal address - Country */
  $handler->display->display_options['fields']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_postal_address_country']['display_name'] = 1;
  /* Field: Field: Postal address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['id'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['field'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['label'] = 'Address';
  /* Field: Field: Postal address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_postal_address_premise']['id'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_premise']['field'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['label'] = 'Address2';
  /* Field: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['label'] = 'City';
  /* Field: Field: Postal address with phone number */
  $handler->display->display_options['fields']['field_postal_address_data']['id'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_data']['field'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_postal_address_data']['selected_phone_type'] = '1';
  /* Field: Distributor: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['path'] = 'admin/dashboard/distributors/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['return_path'] = 'admin/dashboard/distributors';
  $handler->display->display_options['segment_size'] = '10';
  $translatables['dashboard_souriau_distributors'] = array(
    t('Master'),
    t('Dashboard Souriau Distributors'),
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
    t('Id'),
    t('.'),
    t(','),
    t('Code'),
    t('Name'),
    t('Type'),
    t('Brand'),
    t('Website Url'),
    t('Country'),
    t('Address'),
    t('Address2'),
    t('City'),
    t('Phone'),
    t('Email'),
    t('Operations'),
    t('Delete link'),
    t('delete'),
    t('Distributor Code'),
    t('Page'),
    t('Displaying @start - @end of @total'),
    t('Data export'),
  );
  $export['dashboard_souriau_distributors'] = $view;

  $view = new view();
  $view->name = 'distributors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_distributor';
  $view->human_name = 'Distributors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '24';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '.view-content:eq(0)';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_postal_address_thoroughfare' => 'field_postal_address_thoroughfare',
    'field_postal_address_premise' => 'field_postal_address_premise',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No distributors found';
  $handler->display->display_options['empty']['area']['format'] = 'simple';
  /* Field: Distributor: Name */
  $handler->display->display_options['fields']['field_distributor_name']['id'] = 'field_distributor_name';
  $handler->display->display_options['fields']['field_distributor_name']['table'] = 'field_data_field_distributor_name';
  $handler->display->display_options['fields']['field_distributor_name']['field'] = 'field_distributor_name';
  $handler->display->display_options['fields']['field_distributor_name']['label'] = '';
  $handler->display->display_options['fields']['field_distributor_name']['element_label_colon'] = FALSE;
  /* Field: Field: Postal address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['id'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['field'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['element_label_colon'] = FALSE;
  /* Field: Field: Postal address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_postal_address_premise']['id'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_premise']['field'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_premise']['element_label_colon'] = FALSE;
  /* Field: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  /* Field: Field: Postal address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['id'] = 'field_postal_address_administrative_area';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['field'] = 'field_postal_address_administrative_area';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['display_name'] = 1;
  /* Field: Field: Postal address - Country */
  $handler->display->display_options['fields']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_postal_address_country']['display_name'] = 1;
  /* Field: Field: Postal address - Postal code */
  $handler->display->display_options['fields']['field_postal_address_postal_code']['id'] = 'field_postal_address_postal_code';
  $handler->display->display_options['fields']['field_postal_address_postal_code']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_postal_code']['field'] = 'field_postal_address_postal_code';
  $handler->display->display_options['fields']['field_postal_address_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_postal_code']['element_label_colon'] = FALSE;
  /* Field: Field: Postal address with phone number */
  $handler->display->display_options['fields']['field_postal_address_data']['id'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_data']['field'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['label'] = 'Phone n°';
  $handler->display->display_options['fields']['field_postal_address_data']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_postal_address_data']['selected_phone_type'] = '1';
  /* Field: Field: Postal address with phone number */
  $handler->display->display_options['fields']['field_postal_address_data_1']['id'] = 'field_postal_address_data_1';
  $handler->display->display_options['fields']['field_postal_address_data_1']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_data_1']['field'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data_1']['label'] = 'Fax n°';
  $handler->display->display_options['fields']['field_postal_address_data_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_postal_address_data_1']['selected_phone_type'] = '4';
  /* Field: Distributor: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['type'] = 'email_plain';
  /* Field: Distributor: Website Url */
  $handler->display->display_options['fields']['field_url']['id'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['table'] = 'field_data_field_url';
  $handler->display->display_options['fields']['field_url']['field'] = 'field_url';
  $handler->display->display_options['fields']['field_url']['label'] = '';
  $handler->display->display_options['fields']['field_url']['element_label_colon'] = FALSE;
  /* Field: Distributor: Brand */
  $handler->display->display_options['fields']['field_distributor_brand']['id'] = 'field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['table'] = 'field_data_field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['field'] = 'field_distributor_brand';
  $handler->display->display_options['fields']['field_distributor_brand']['label'] = '';
  $handler->display->display_options['fields']['field_distributor_brand']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_distributor_brand']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_distributor_brand']['separator'] = ' ';
  /* Field: Distributor: Type */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['label'] = '';
  $handler->display->display_options['fields']['field_type']['element_label_colon'] = FALSE;
  /* Field: Distributor: Contact Person */
  $handler->display->display_options['fields']['field_contact_person']['id'] = 'field_contact_person';
  $handler->display->display_options['fields']['field_contact_person']['table'] = 'field_data_field_contact_person';
  $handler->display->display_options['fields']['field_contact_person']['field'] = 'field_contact_person';
  $handler->display->display_options['fields']['field_contact_person']['hide_empty'] = TRUE;
  /* Field: Distributor: VAD SERIES */
  $handler->display->display_options['fields']['field_vad_series']['id'] = 'field_vad_series';
  $handler->display->display_options['fields']['field_vad_series']['table'] = 'field_data_field_vad_series';
  $handler->display->display_options['fields']['field_vad_series']['field'] = 'field_vad_series';
  $handler->display->display_options['fields']['field_vad_series']['label'] = '';
  $handler->display->display_options['fields']['field_vad_series']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_vad_series']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Distributor: Name (field_distributor_name) */
  $handler->display->display_options['sorts']['field_distributor_name_value']['id'] = 'field_distributor_name_value';
  $handler->display->display_options['sorts']['field_distributor_name_value']['table'] = 'field_data_field_distributor_name';
  $handler->display->display_options['sorts']['field_distributor_name_value']['field'] = 'field_distributor_name_value';
  /* Filter criterion: Postal address - Country (selective) */
  $handler->display->display_options['filters']['field_postal_address_country_selective']['id'] = 'field_postal_address_country_selective';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['field'] = 'field_postal_address_country_selective';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['ui_name'] = 'Postal address - Country (selective)';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_postal_address_country_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_postal_address_country_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['expose']['label'] = 'MY LOCATION';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['expose']['identifier'] = 'field_postal_address_country_selective';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_postal_address_country_selective']['selective_display_field'] = 'field_postal_address_country';
  $handler->display->display_options['filters']['field_postal_address_country_selective']['selective_items_limit'] = '';
  /* Filter criterion: Type (field_type) (selective) */
  $handler->display->display_options['filters']['field_type_value_selective']['id'] = 'field_type_value_selective';
  $handler->display->display_options['filters']['field_type_value_selective']['table'] = 'field_data_field_type';
  $handler->display->display_options['filters']['field_type_value_selective']['field'] = 'field_type_value_selective';
  $handler->display->display_options['filters']['field_type_value_selective']['ui_name'] = 'Type (field_type) (selective)';
  $handler->display->display_options['filters']['field_type_value_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_type_value_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_type_value_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_type_value_selective']['expose']['label'] = 'TYPE';
  $handler->display->display_options['filters']['field_type_value_selective']['expose']['identifier'] = 'field_type_value_selective';
  $handler->display->display_options['filters']['field_type_value_selective']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_type_value_selective']['selective_display_field'] = 'field_type';
  $handler->display->display_options['filters']['field_type_value_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Brand (field_distributor_brand) (selective) */
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['id'] = 'field_distributor_brand_value_selective';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['table'] = 'field_data_field_distributor_brand';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['field'] = 'field_distributor_brand_value_selective';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['ui_name'] = 'Brand (field_distributor_brand) (selective)';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['expose']['label'] = 'BRAND';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['expose']['identifier'] = 'field_distributor_brand_value_selective';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['selective_display_field'] = 'field_distributor_brand';
  $handler->display->display_options['filters']['field_distributor_brand_value_selective']['selective_items_limit'] = '100';
  $translatables['distributors'] = array(
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
    t('Load more'),
    t('No results'),
    t('No distributors found'),
    t('Postal address - Locality (i.e. City)'),
    t('Phone n°'),
    t('Fax n°'),
    t('Contact Person'),
    t('MY LOCATION'),
    t('TYPE'),
    t('BRAND'),
  );
  $export['distributors'] = $view;

  return $export;
}
