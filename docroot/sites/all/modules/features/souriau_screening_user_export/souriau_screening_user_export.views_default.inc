<?php
/**
 * @file
 * souriau_screening_user_export.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_screening_user_export_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_screening_users_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Souriau Screening Users List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Souriau Screening Users List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '$PARTNER';
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'N';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'SIN';
  /* Field: Field: Postal address - Company */
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['id'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['field'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['label'] = 'SIN';
  /* Field: Address 1 */
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['id'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['field'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['ui_name'] = 'Address 1';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['label'] = 'U';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['element_label_colon'] = FALSE;
  /* Field: Address 2 */
  $handler->display->display_options['fields']['field_postal_address_premise']['id'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_premise']['field'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['ui_name'] = 'Address 2';
  $handler->display->display_options['fields']['field_postal_address_premise']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_premise']['element_label_colon'] = FALSE;
  /* Field: Address 3 */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Address 3';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_locality']['element_label_colon'] = FALSE;
  /* Field: Field: Postal address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_postal_address_administrative_area_1']['id'] = 'field_postal_address_administrative_area_1';
  $handler->display->display_options['fields']['field_postal_address_administrative_area_1']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_administrative_area_1']['field'] = 'field_postal_address_administrative_area';
  $handler->display->display_options['fields']['field_postal_address_administrative_area_1']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_administrative_area_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_postal_address_administrative_area_1']['display_name'] = 0;
  /* Field: Field: Postal address - Administrative area (i.e. State / Province) */
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['id'] = 'field_postal_address_administrative_area';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['field'] = 'field_postal_address_administrative_area';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_postal_address_administrative_area']['display_name'] = 1;
  /* Field: Field: Postal address - Country */
  $handler->display->display_options['fields']['field_postal_address_country_1']['id'] = 'field_postal_address_country_1';
  $handler->display->display_options['fields']['field_postal_address_country_1']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_country_1']['field'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country_1']['label'] = '';
  $handler->display->display_options['fields']['field_postal_address_country_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_postal_address_country_1']['display_name'] = 0;
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
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Date: Date (users) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'users';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now -1 day';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'users.created' => 'users.created',
  );

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'screening_list');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 0;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['path'] = 'admin/users/screening/csv';
  $translatables['souriau_screening_users_list'] = array(
    t('Master'),
    t('Souriau Screening Users List'),
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
    t('$PARTNER'),
    t('N'),
    t('SIN'),
    t('U'),
    t('Data export'),
  );
  $export['souriau_screening_users_list'] = $view;

  return $export;
}
