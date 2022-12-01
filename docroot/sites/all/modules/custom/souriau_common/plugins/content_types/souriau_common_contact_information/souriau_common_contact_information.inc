<?php
/**
 * @file
 * Domain specific facets block.
 */

$plugin = [
  'title' => t('SOURIAU Common: Contact Page Contact Information Block', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: Contact Page Contact Information Block', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'single' => TRUE,
  'render callback' => 'souriau_common_contact_info_block_render',
  'defaults' => [],
  'edit form' => 'souriau_common_contact_info_block_edit_form',
  'hook theme' => 'souriau_common_contact_info_block_theme',
  'category' => [t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_ADMIN])],
  'icon' => NULL,
  'all contexts' => TRUE,
];

/**
 * Implementation of edit form builder.
 */
function souriau_common_contact_info_block_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Plugin render callback.
 */
function souriau_common_contact_info_block_render($subtype, $conf, $args, $context) {
  $block = new stdClass();
  $block->title = NULL;
  $default_country = '';
  $domain = domain_get_domain();
  if ($domain['domain_id'] != SOURIAU_COMMON_CENTRAL_DOMAIN_ID) {
    $default_country = domain_conf_variable_get($domain['domain_id'], 'geo_countries');
  }
  $rendered_array = [
    '#theme' => 'contact_info',
    '#form' => drupal_get_form('souriau_common_contact_country_selector_form', $default_country),
    '#address_list' => souriau_common_address_block($default_country),
  ];
  $block->content = drupal_render($rendered_array);
  return $block;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_contact_info_block_theme(&$theme, $plugin) {
  $theme['contact_info'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-contact-information',
    'variables' => [
      'form' => NULL,
      'address_list' => NULL,
    ],
  ];
}

/**
 * Country selector form.
 */
function souriau_common_contact_country_selector_form($form, &$form_state, $default_country = NULL) {
  $form = [];
  form_load_include($form_state, 'inc', 'souriau_common', 'plugins/content_types/souriau_common_contact_information/souriau_common_contact_information');
  $country_list = [
      '0' => t('Select your location', [], ['context' => SOURIAU_COMMON_T_OTHER])
    ]
    + country_get_list();
  $form['country'] = [
    '#type' => 'select',
    '#options' => $country_list,
    '#default_value' => (isset($default_country) ? $default_country : 0),
    '#ajax' => [
      'event' => 'selectCountry',
      'callback' => 'souriau_common_get_contact_by_country',
    ],
    '#attributes' => [
      'aria-multiselectable' => 'false',
      'class' => ['default'],
    ],
  ];
  return $form;
}

/**
 * Ajax callback.
 *
 * Get the contact details based on country-id.
 */
function souriau_common_get_contact_by_country($form, &$form_state, $country = NULL) {
  $country_code = $form_state['values']['country'];
  $output = souriau_common_address_block($country_code);
  $commands = [];
  $commands[] = ajax_command_html('#contact_address_list', $output);
  $commands[] = ajax_command_souriau_common_jcf('refresh');
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Returns the address block.
 */
function souriau_common_address_block($country_code) {
  $country_list = country_get_list();
  $entities = souriau_common_query_get_contacts_by_country($country_code);
  $data = [];
  if (!empty($entities)) {
    foreach ($entities as $entity) {
      $contact = souriau_common_get_contact_details($entity, $country_list);
      if (empty($contact)) {
        continue;
      }
      $data['address'][$contact['id']] = $contact;
    }
  }
  $output = theme('contact_page_address_block', ['_html' => $data]);
  return $output;
}
/**
 * Get the Contact entity based on country-id.
 */
function souriau_common_query_get_contacts_by_country($country_code) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'contact')
    ->entityCondition('bundle', 'contact')
    ->fieldCondition('field_postal_address', 'country', $country_code, '=');
  $result = $query->execute();
  if (empty($result)) {
    return FALSE;
  }
  $entities_ids = [];
  foreach ($result['contact'] as $value) {
    $entities_ids[] = $value->id;
  }
  $entities = entity_load('contact', $entities_ids);
  return $entities;
}

/**
 * Contact details.
 */
function souriau_common_get_contact_details($entity, $country_list) {
  try {
    $entity_wrapper = entity_metadata_wrapper('contact', $entity);
    if (empty($entity_wrapper) || empty($entity_wrapper->id->value())) {
      // Data is incomplete.
      return NULL;
    }
    $data = [
      'id' => $entity_wrapper->id->value(),
      'name' => $entity_wrapper->title->value(),
      'address1' => $entity_wrapper->field_postal_address->thoroughfare->value(),
      'address2' => $entity_wrapper->field_postal_address->premise->value(),
      'city' => $entity_wrapper->field_postal_address->locality->value(),
      'country' => $entity_wrapper->field_postal_address->country->value() ? $country_list[$entity_wrapper->field_postal_address->country->value()] : '',
      'phone_no' => $entity_wrapper->field_postal_address->phone_number->value(),
      'fax_no' => $entity_wrapper->field_postal_address->fax_number->value(),
      'postal_code' => $entity_wrapper->field_postal_address->postal_code->value(),
      'email' => $entity_wrapper->field_postal_address->value()['email'],
    ];
    return $data;
  }
  catch (Exception $e) {
    watchdog('souriau_common', 'Exception: !exception in !function.', [
      '!exception' => $e->getMessage(),
      '!function' => __FUNCTION__,
    ], WATCHDOG_WARNING);
    return NULL;
  }
}
