<?php
/**
 * @file
 * souriau_entity_contact.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_entity_contact_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'souriau_dashboard_contacts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_contact';
  $view->human_name = 'Souriau Dashboard Contacts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'eck administer contact contact entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'id' => 'id',
    'title' => 'title',
    'changed' => 'changed',
    'field_postal_address_country' => 'field_postal_address_country',
    'field_postal_address_postal_code' => 'field_postal_address_postal_code',
    'field_postal_address_locality' => 'field_postal_address_locality',
    'field_postal_address_thoroughfare' => 'field_postal_address_thoroughfare',
    'field_postal_address_premise' => 'field_postal_address_thoroughfare',
    'field_postal_address_data' => 'field_postal_address_data',
    'field_postal_address_data_1' => 'field_postal_address_data_1',
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
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
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
    'field_postal_address_postal_code' => array(
      'sortable' => 1,
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
    'field_postal_address_thoroughfare' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '<br />',
      'empty_column' => 0,
    ),
    'field_postal_address_premise' => array(
      'sortable' => 0,
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
    'field_postal_address_data_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_link' => array(
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
    'delete_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Contact: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_contact';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: Contact: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_contact';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Contact: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'eck_contact';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Field: Postal address - Country */
  $handler->display->display_options['fields']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_postal_address_country']['display_name'] = 1;
  /* Field: Field: Postal address - Postal code */
  $handler->display->display_options['fields']['field_postal_address_postal_code']['id'] = 'field_postal_address_postal_code';
  $handler->display->display_options['fields']['field_postal_address_postal_code']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_postal_code']['field'] = 'field_postal_address_postal_code';
  $handler->display->display_options['fields']['field_postal_address_postal_code']['label'] = 'Postal code';
  /* Field: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['label'] = 'City';
  /* Field: Field: Postal address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['id'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['field'] = 'field_postal_address_thoroughfare';
  $handler->display->display_options['fields']['field_postal_address_thoroughfare']['label'] = 'Address';
  /* Field: Field: Postal address - Premise (i.e. Apartment / Suite number) */
  $handler->display->display_options['fields']['field_postal_address_premise']['id'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_premise']['field'] = 'field_postal_address_premise';
  $handler->display->display_options['fields']['field_postal_address_premise']['label'] = 'Address line 2';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Email';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[id]';
  /* Field: Field: Postal address with phone number */
  $handler->display->display_options['fields']['field_postal_address_data']['id'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_data']['field'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_postal_address_data']['selected_phone_type'] = '1';
  /* Field: Field: Postal address with phone number */
  $handler->display->display_options['fields']['field_postal_address_data_1']['id'] = 'field_postal_address_data_1';
  $handler->display->display_options['fields']['field_postal_address_data_1']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_data_1']['field'] = 'field_postal_address_data';
  $handler->display->display_options['fields']['field_postal_address_data_1']['label'] = 'FAX';
  $handler->display->display_options['fields']['field_postal_address_data_1']['selected_phone_type'] = '4';
  /* Field: Contact: Edit link */
  $handler->display->display_options['fields']['edit_link']['id'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['table'] = 'eck_contact';
  $handler->display->display_options['fields']['edit_link']['field'] = 'edit_link';
  $handler->display->display_options['fields']['edit_link']['label'] = 'Operations';
  /* Field: Contact: Delete link */
  $handler->display->display_options['fields']['delete_link']['id'] = 'delete_link';
  $handler->display->display_options['fields']['delete_link']['table'] = 'eck_contact';
  $handler->display->display_options['fields']['delete_link']['field'] = 'delete_link';
  /* Sort criterion: Contact: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_contact';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Contact: Id */
  $handler->display->display_options['filters']['id']['id'] = 'id';
  $handler->display->display_options['filters']['id']['table'] = 'eck_contact';
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
  );
  /* Filter criterion: Contact: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_contact';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Field: Postal address - Country */
  $handler->display->display_options['filters']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['filters']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['filters']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['filters']['field_postal_address_country']['value'] = array(
    'AF' => 'AF',
    'AX' => 'AX',
    'AL' => 'AL',
    'DZ' => 'DZ',
    'AS' => 'AS',
    'AD' => 'AD',
    'AO' => 'AO',
    'AI' => 'AI',
    'AQ' => 'AQ',
    'AG' => 'AG',
    'AR' => 'AR',
    'AM' => 'AM',
    'AW' => 'AW',
    'AU' => 'AU',
    'AT' => 'AT',
    'AZ' => 'AZ',
    'BS' => 'BS',
    'BH' => 'BH',
    'BD' => 'BD',
    'BB' => 'BB',
    'BY' => 'BY',
    'BE' => 'BE',
    'BZ' => 'BZ',
    'BJ' => 'BJ',
    'BM' => 'BM',
    'BT' => 'BT',
    'BO' => 'BO',
    'BA' => 'BA',
    'BW' => 'BW',
    'BV' => 'BV',
    'BR' => 'BR',
    'IO' => 'IO',
    'VG' => 'VG',
    'BN' => 'BN',
    'BG' => 'BG',
    'BF' => 'BF',
    'BI' => 'BI',
    'KH' => 'KH',
    'CM' => 'CM',
    'CA' => 'CA',
    'CV' => 'CV',
    'BQ' => 'BQ',
    'KY' => 'KY',
    'CF' => 'CF',
    'TD' => 'TD',
    'CL' => 'CL',
    'CN' => 'CN',
    'CX' => 'CX',
    'CC' => 'CC',
    'CO' => 'CO',
    'KM' => 'KM',
    'CG' => 'CG',
    'CD' => 'CD',
    'CK' => 'CK',
    'CR' => 'CR',
    'HR' => 'HR',
    'CU' => 'CU',
    'CW' => 'CW',
    'CY' => 'CY',
    'CZ' => 'CZ',
    'DK' => 'DK',
    'DJ' => 'DJ',
    'DM' => 'DM',
    'DO' => 'DO',
    'EC' => 'EC',
    'EG' => 'EG',
    'SV' => 'SV',
    'GQ' => 'GQ',
    'ER' => 'ER',
    'EE' => 'EE',
    'ET' => 'ET',
    'FK' => 'FK',
    'FO' => 'FO',
    'FJ' => 'FJ',
    'FI' => 'FI',
    'FR' => 'FR',
    'GF' => 'GF',
    'PF' => 'PF',
    'TF' => 'TF',
    'GA' => 'GA',
    'GM' => 'GM',
    'GE' => 'GE',
    'DE' => 'DE',
    'GH' => 'GH',
    'GI' => 'GI',
    'GR' => 'GR',
    'GL' => 'GL',
    'GD' => 'GD',
    'GP' => 'GP',
    'GU' => 'GU',
    'GT' => 'GT',
    'GG' => 'GG',
    'GN' => 'GN',
    'GW' => 'GW',
    'GY' => 'GY',
    'HT' => 'HT',
    'HM' => 'HM',
    'HN' => 'HN',
    'HK' => 'HK',
    'HU' => 'HU',
    'IS' => 'IS',
    'IN' => 'IN',
    'ID' => 'ID',
    'IR' => 'IR',
    'IQ' => 'IQ',
    'IE' => 'IE',
    'IM' => 'IM',
    'IL' => 'IL',
    'IT' => 'IT',
    'CI' => 'CI',
    'JM' => 'JM',
    'JP' => 'JP',
    'JE' => 'JE',
    'JO' => 'JO',
    'KZ' => 'KZ',
    'KE' => 'KE',
    'KI' => 'KI',
    'KW' => 'KW',
    'KG' => 'KG',
    'LA' => 'LA',
    'LV' => 'LV',
    'LB' => 'LB',
    'LS' => 'LS',
    'LR' => 'LR',
    'LY' => 'LY',
    'LI' => 'LI',
    'LT' => 'LT',
    'LU' => 'LU',
    'MO' => 'MO',
    'MK' => 'MK',
    'MG' => 'MG',
    'MW' => 'MW',
    'MY' => 'MY',
    'MV' => 'MV',
    'ML' => 'ML',
    'MT' => 'MT',
    'MH' => 'MH',
    'MQ' => 'MQ',
    'MR' => 'MR',
    'MU' => 'MU',
    'YT' => 'YT',
    'MX' => 'MX',
    'FM' => 'FM',
    'MD' => 'MD',
    'MC' => 'MC',
    'MN' => 'MN',
    'ME' => 'ME',
    'MS' => 'MS',
    'MA' => 'MA',
    'MZ' => 'MZ',
    'MM' => 'MM',
    'NA' => 'NA',
    'NR' => 'NR',
    'NP' => 'NP',
    'NL' => 'NL',
    'AN' => 'AN',
    'NC' => 'NC',
    'NZ' => 'NZ',
    'NI' => 'NI',
    'NE' => 'NE',
    'NG' => 'NG',
    'NU' => 'NU',
    'NF' => 'NF',
    'MP' => 'MP',
    'KP' => 'KP',
    'NO' => 'NO',
    'OM' => 'OM',
    'PK' => 'PK',
    'PW' => 'PW',
    'PS' => 'PS',
    'PA' => 'PA',
    'PG' => 'PG',
    'PY' => 'PY',
    'PE' => 'PE',
    'PH' => 'PH',
    'PN' => 'PN',
    'PL' => 'PL',
    'PT' => 'PT',
    'PR' => 'PR',
    'QA' => 'QA',
    'RE' => 'RE',
    'RO' => 'RO',
    'RU' => 'RU',
    'RW' => 'RW',
    'BL' => 'BL',
    'SH' => 'SH',
    'KN' => 'KN',
    'LC' => 'LC',
    'MF' => 'MF',
    'PM' => 'PM',
    'VC' => 'VC',
    'WS' => 'WS',
    'SM' => 'SM',
    'ST' => 'ST',
    'SA' => 'SA',
    'SN' => 'SN',
    'RS' => 'RS',
    'SC' => 'SC',
    'SL' => 'SL',
    'SG' => 'SG',
    'SX' => 'SX',
    'SK' => 'SK',
    'SI' => 'SI',
    'SB' => 'SB',
    'SO' => 'SO',
    'ZA' => 'ZA',
    'GS' => 'GS',
    'KR' => 'KR',
    'SS' => 'SS',
    'ES' => 'ES',
    'LK' => 'LK',
    'SD' => 'SD',
    'SR' => 'SR',
    'SJ' => 'SJ',
    'SZ' => 'SZ',
    'SE' => 'SE',
    'CH' => 'CH',
    'SY' => 'SY',
    'TW' => 'TW',
    'TJ' => 'TJ',
    'TZ' => 'TZ',
    'TH' => 'TH',
    'TL' => 'TL',
    'TG' => 'TG',
    'TK' => 'TK',
    'TO' => 'TO',
    'TT' => 'TT',
    'TN' => 'TN',
    'TR' => 'TR',
    'TM' => 'TM',
    'TC' => 'TC',
    'TV' => 'TV',
    'VI' => 'VI',
    'UG' => 'UG',
    'UA' => 'UA',
    'AE' => 'AE',
    'GB' => 'GB',
    'US' => 'US',
    'UM' => 'UM',
    'UY' => 'UY',
    'UZ' => 'UZ',
    'VU' => 'VU',
    'VA' => 'VA',
    'VE' => 'VE',
    'VN' => 'VN',
    'WF' => 'WF',
    'EH' => 'EH',
    'YE' => 'YE',
    'ZM' => 'ZM',
    'ZW' => 'ZW',
  );
  $handler->display->display_options['filters']['field_postal_address_country']['group'] = 1;
  $handler->display->display_options['filters']['field_postal_address_country']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['operator_id'] = 'field_postal_address_country_op';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['label'] = 'Country';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['operator'] = 'field_postal_address_country_op';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['identifier'] = 'field_postal_address_country';
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_postal_address_country']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['filters']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['filters']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['filters']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  $handler->display->display_options['filters']['field_postal_address_locality']['group'] = 1;
  $handler->display->display_options['filters']['field_postal_address_locality']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_postal_address_locality']['expose']['operator_id'] = 'field_postal_address_locality_op';
  $handler->display->display_options['filters']['field_postal_address_locality']['expose']['label'] = 'City';
  $handler->display->display_options['filters']['field_postal_address_locality']['expose']['operator'] = 'field_postal_address_locality_op';
  $handler->display->display_options['filters']['field_postal_address_locality']['expose']['identifier'] = 'field_postal_address_locality';
  $handler->display->display_options['filters']['field_postal_address_locality']['expose']['remember_roles'] = array(
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
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/dashboard/contacts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Contacts';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['souriau_dashboard_contacts'] = array(
    t('Master'),
    t('Contacts'),
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
    t('Title'),
    t('Changed'),
    t('Country'),
    t('Postal code'),
    t('City'),
    t('Address'),
    t('Address line 2'),
    t('Email'),
    t('[id]'),
    t('Phone'),
    t('FAX'),
    t('Operations'),
    t('Delete link'),
    t('Page'),
  );
  $export['souriau_dashboard_contacts'] = $view;

  return $export;
}
