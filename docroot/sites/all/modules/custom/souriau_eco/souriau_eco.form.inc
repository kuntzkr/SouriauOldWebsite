<?php

/**
 * @file
 * Souriau Ecommerce forms.
 */

/**
 * Prepare for 'commerce_addressbook_customer_profile'. Del unnecessary fields.
 */
function _souriau_eco_form_commerce_addressbook_customer_profile_form_prepare(&$form) {
  $form['field_address_name']['#weight'] = 99;

  $customer_address_field = &$form['commerce_customer_address'][$form['commerce_customer_address']['#language']][0];
  $address_name = &$form['field_address_name'][$form['field_address_name']['#language']][0];

  $name_block = &$customer_address_field['name_block'];
  $phone_block = &$customer_address_field['phone_block'];
  $country_block = &$customer_address_field['country'];
  $street_block = &$customer_address_field['street_block'];
  $locality_block = &$customer_address_field['locality_block'];
  $civility = &$customer_address_field['civility'];
  $organisation_block = &$customer_address_field['organisation_block'];
  $customer_address_field['country']['#title'] = t('Location', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  $customer_address_field['#title'] = t('CREATE A NEW ADDRESS', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);

  $name_block['civility']['#access'] = FALSE;
  $name_block['#access'] = TRUE;
  $civility['#access'] = FALSE;

  $key = is_array($name_block['#attributes']['class'])
  ? array_search('addressfield-container-inline', $name_block['#attributes']['class']) : FALSE;
  if ($key !== FALSE) {
    unset($name_block['#attributes']['class'][$key]);
  }

  $phone_block['phone_number']['#attributes']['class'] = [];
  $phone_block['mobile_number']['#attributes']['class'] = [];

  if (isset($street_block['premise']['#title_display'])) {
    unset($street_block['premise']['#title_display']);
  }

  $locality_block['postal_code']['#title'] = t('Zip Code', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  $locality_block['locality']['#title'] = t('City', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);

  $street_block['thoroughfare']['#title'] = t('Address', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  $street_block['premise']['#title'] = t('Address', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);

  $phone_block['mobile_number']['#title'] = t('Mobile Phone', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  $phone_block['phone_number']['phone_number']['#title'] = t('Phone', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);

  $address_name['value']['#title'] = t('Name of this address', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);

  $_locality_block = [];

  foreach ($locality_block as $name => $element) {
    if ($name{0} != '#' && $element['#access'] == TRUE) {
      $_locality_block[] = $name;
    }
  }

  if (count($_locality_block) == 2) {
    list($left_element, $right_element) = $_locality_block;

    $locality_block['#attributes']['class'][] = 'form-row';
    $locality_block[$left_element]['#souriau_settings']['wrapper-align'] = 'left';
    $locality_block[$right_element]['#souriau_settings']['wrapper-align'] = 'right';
  }

  $name_block['#weight'] = 1;
  $street_block['#weight'] = 2;
  $locality_block['#weight'] = 4;
  $country_block['#weight'] = 3;
  $organisation_block['#weight'] = 5;
  $phone_block['#weight'] = 6;

  $form['#submit'] = [];

  $form['actions'] = [
    '#type' => 'actions',
    '#souriau_settings' => [
      'text_align' => 'center',
      'align' => 'center',
    ],

    'submit' => [
      '#type' => 'submit',
      '#value' => t('ADD THIS ADDRESS', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
      '#attributes' => [
        'class' => ['use-ajax-submit', 'btn', 'blue-btn', 'close-btn'],
      ],
      '#ajax' => [
        'callback' => 'souriau_eco_address_save_callback',
      ],
    ],
  ];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function souriau_eco_form_commerce_addressbook_customer_profile_form_alter(&$form, &$form_state, $form_id) {
  _souriau_eco_form_commerce_addressbook_customer_profile_form_prepare($form);
}

/**
 * Implements hook_addressfield_standard_widget_refresh_alter().
 */
function souriau_eco_addressfield_standard_widget_refresh_alter(&$commands, $form, $form_state) {
  _souriau_eco_form_commerce_addressbook_customer_profile_form_prepare($form);
}

/**
 * Generate confirmation form.
 */
function souriau_eco_address_delete_confirm_form($form, &$form_state) {
  $form = [];

  $form['title'] = [
    '#markup' => t('Delete this things ?', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  ];

  $form['description'] = [
    '#markup' => t('You are about to cancel this product to your cart would you continue?', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  ];

  $form['buttons'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['w-btn wide-btns'],
    ],

    'cancel' => [
      '#type' => 'link',
      '#title' => t('CANCEL'),
      '#href' => '',
      '#attributes' => [
        'class' => [
          'ctools-close-modal',
          'btn',
          'blue-btn',
          'btn-cancel',
        ],
      ],
    ],

    'stretch' => [
      '#type' => 'container',
      '#attributes' => [
        'class' => [
          'w-btn-stretch',
        ],
      ],

      'confirm' => [
        '#type' => 'submit',
        '#value' => t('CONFIRM'),
        '#attributes' => [
          'class' => [
            'btn',
            'orange-btn-hover',
          ],
        ],
        '#ajax' => [
          'callback' => 'souriau_eco_address_delete_submit_callback',
        ],
      ],
    ],
  ];

  return $form;
}

/**
 * Create or update address.
 *
 * @param array $form
 *   Form.
 * @param array $form_state
 *   Form state.
 *
 * @return array
 *   Ajax commands.
 */
function souriau_eco_address_save_callback(array $form, array &$form_state) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  global $user;

  $commands = [];

  module_load_include('inc', 'commerce_addressbook', 'includes/commerce_addressbook.user');

  $errors = form_get_errors();

  if ($errors) {
    $commands[] = ajax_command_html('#js-commerce-addressbook-customer-profile-form', drupal_render($form));
    return ['#type' => 'ajax', '#commands' => $commands];
  }

  $profile = &$form_state['customer_profile'];

  $is_new = is_null($profile->profile_id);

  // Save default parameters back into the $profile object.
  $profile->status = $form_state['values']['status'];

  // Set the profile's owner uid based on the supplied name.
  if (!empty($form_state['values']['name']) && $account = user_load_by_name($form_state['values']['name'])) {
    $profile->uid = $account->uid;
  }
  else {
    $profile->uid = 0;
  }

  // Notify field widgets.
  field_attach_submit('commerce_customer_profile', $profile, $form, $form_state);

  // Save the profile.
  commerce_customer_profile_save($profile);

  $commands[] = ajax_command_html(
    '#js-commerce-addressbook-addresses',
    commerce_embed_view('souriau_commerce_addressbook', 'default', [$user->uid, 'shipping'])
  );

  $commands[] = souriau_eco_reset_address_form();

  $modal_style = [
    'CToolsModal' => [
      'modalTheme' => 'souriau_common_popup',
    ],
  ];

  $commands[] = ajax_command_settings($modal_style, TRUE);

  if ($is_new) {
    $commands[] = ctools_modal_command_display(
      '', t('Your address has been added', [], ['context' => SOURIAU_COMMON_T_COMMERCE])
    );
  }
  else {
    $commands[] = ctools_modal_command_display(
      '', t('Your address has been updated', [], ['context' => SOURIAU_COMMON_T_COMMERCE])
    );
  }

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function souriau_eco_form_views_form_commerce_cart_form_default_alter(&$form, &$form_state, $form_id) {
  if (isset($form['edit_quantity'])) {
    foreach ($form['edit_quantity'] as $key => $value) {
      if (is_numeric($key) && drupal_substr($key, 0, 1) != '#' && is_array($value)) {
        $line_item = commerce_line_item_load($form['edit_quantity'][$key]['#line_item_id']);
        $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
        $sku = $line_item_wrapper->commerce_product->sku->value();
        $max_count = souriau_eco_get_product_max_quantity($sku);
        $form['edit_quantity'][$key]['#attributes'] += [
          'min' => 0,
          // Fallback to make counter widget works as expected.
          // @todo need validate.
          'max' => $max_count == 0 ? $form['edit_quantity'][$key]['#default_value'] : $max_count,
          'step' => 1,
        ];
      }
    }
    foreach ($form['edit_delete'] as $key => $value) {
      if (is_numeric($key) && drupal_substr($key, 0, 1) != '#' && is_array($value)) {
        $icon = [
          '#type' => 'svg_icon',
          '#icon' => 'ico-remove',
        ];
        $form['edit_delete'][$key] = [
          '#type' => 'link',
          '#title' => drupal_render($icon),
          '#href' => 'souriau/ajax/cart/nojs/' . $form['edit_delete'][$key]['#line_item_id'] . '/' . $form_state['order']->order_number . '/delete',
          '#options' => ['html' => TRUE],
          '#attributes' => [
            'class' => [
              'ctools-use-modal',
              'ctools-modal-souriau-modal-style',
              'remove-link',
            ],
          ],
        ];
      }
    }

    unset($form['actions']['submit']);
    $form['actions']['#attributes']['class'][] = 'text-right';
    $form['actions']['checkout']['#value'] = t('PROCEED TO CHECKOUT', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
    $form['actions']['checkout']['#souriau_settings'] = [
      'hover_color' => 'orange',
    ];
    $form['actions']['checkout']['#submit'][] = 'souriau_eco_line_item_views_form_submit';
    $form['actions']['checkout']['#validate'][] = 'souriau_eco_line_item_views_form_submit_validate';
    $form['actions']['checkout']['#ajax'] = [
      'callback' => 'souriau_eco_line_item_views_form_submit_callback',
      'event' => 'click',
    ];
  }
}

/**
 * Submit handler used to redirect to the next checkout page.
 */
function souriau_eco_line_item_views_form_submit($form, &$form_state) {
  $order_status = commerce_order_status_load($form_state['order']->status);
  $page = commerce_checkout_page_load($order_status['checkout_page']);
  $form_state['order'] = commerce_order_status_update($form_state['order'], 'checkout_' . $page['next_page'], FALSE, NULL);

  commerce_order_save($form_state['order']);
  $form_state['redirect'] = 'checkout/' . $form_state['order']->order_id . '/' . $page['next_page'];
}

/**
 * Validate handler used to prevent redirect to the next checkout page.
 */
function souriau_eco_line_item_views_form_submit_validate($form, &$form_state) {
  global $user;
  $period = variable_get('souriau_eco_part_number_sample_order_delay', 100);
  foreach ($form_state['values']['edit_quantity'] as $key => $value) {
    if (!isset($form['edit_quantity'][$key]['#line_item_id'])) {
      $contact_link = l(t('contact support.', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'contact');
      $message = t('Sample for this part number can\'t be processed, please ', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
      $name = implode('][', ['edit_quantity', $key]);
      form_set_error($name, $message . $contact_link);
    }
    $line_item = commerce_line_item_load($form['edit_quantity'][$key]['#line_item_id']);
    $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
    $sku = $line_item_wrapper->commerce_product->sku->value();
    // Get maximum allowed quantity and stock level of the sku.
    $max_qty = $pn_stock = NULL;
    $pn_quantities = souriau_eco_get_product_max_quantity_and_stock($sku);
    $max_qty = $pn_quantities['max_qty'];
    $pn_stock = $pn_quantities['stock_level'];
    $ordered_qty = $form_state['values']['edit_quantity'][$key];
    // Get already ordered qty.
    $product_sku = commerce_product_load_by_sku($sku);
    $previously_ordered_qty = souriau_eco_sku_sample_previously_ordered_count($product_sku, $period, $user->uid);
    $total_ordered_qty = $ordered_qty + $previously_ordered_qty;

    if ($previously_ordered_qty > 0 && $total_ordered_qty > $max_qty) {
      $name = implode('][', ['edit_quantity', $key]);
      $error_message = format_plural((int) $max_qty,
        'Allowed max quantity for %sku is %maxqty product.
        You have already ordered %previousqty product.
        Remaining number of products you can order for %sku is %remainingqty',
        'Allowed max quantity for %sku is %maxqty products.
        You have already ordered %previousqty product.
        Remaining number of products you can order for %sku is %remainingqty',
        [
          '%maxqty' => $max_qty,
          '%sku' => $sku,
          '%previousqty' => $previously_ordered_qty,
          '%remainingqty' => $max_qty - $previously_ordered_qty,
        ],
        ['context' => SOURIAU_COMMON_T_COMMERCE]
      );
      form_set_error($name, $error_message);
    }
    elseif ($ordered_qty > $max_qty) {
      $name = implode('][', ['edit_quantity', $key]);
      $error_message = format_plural((int) $max_qty,
        'You cannot order more than %maxqty product for %sku',
        'You cannot order more than %maxqty products for %sku',
        ['%maxqty' => $max_qty, '%sku' => $sku],
        ['context' => SOURIAU_COMMON_T_COMMERCE]
      );
      form_set_error($name, $error_message);
    }
    elseif ($ordered_qty > $pn_stock) {
      $name = implode('][', ['edit_quantity', $key]);
      form_set_error($name, t("The quantity requested for part number %sku is not available. There's, currently, only %stock in stock", ['%sku' => $sku, '%stock' => $pn_stock], ['context' => SOURIAU_COMMON_T_COMMERCE]));
    }
  }

}

/**
 * Helper function for getting max quantity of an sku.
 */
function souriau_eco_get_product_max_quantity($sku) {
  $pn_quantities = souriau_eco_get_product_max_quantity_and_stock($sku);
  return ($pn_quantities['stock_level'] >= $pn_quantities['max_qty']) ? $pn_quantities['max_qty'] : $pn_quantities['stock_level'];
}

/**
 * Helper function for getting max quantity and stock level of an sku.
 */
function souriau_eco_get_product_max_quantity_and_stock($sku) {
  $part_number = souriau_common_load_part_number_by_sku($sku);
  $main_product_range = souriau_common_get_main_product_range($part_number);
  $max_quantity = _souriau_common_get_category_field_from_product_range($main_product_range, 'field_sample_max_quantity');
  $max_quantity = is_array($max_quantity) ? reset($max_quantity) : 0;
  $max_quantity = (int) $max_quantity;
  module_load_include('inc', 'souriau_common', 'souriau_common.rdb');
  $stock_level = souriau_eco_erp_get_samples_stock($sku);
  $pn_quantities = [
    'max_qty' => $max_quantity,
    'stock_level' => (int) $stock_level,
  ];
  return $pn_quantities;
}

/**
 * Ajax callback used to redirect to the next checkout page.
 */
function souriau_eco_line_item_views_form_submit_callback($form, &$form_state) {
  ctools_include('ajax');
  ctools_add_js('ajax-responder');
  $commands = [];
  foreach ($form['edit_quantity'] as $key => $value) {
    if (form_get_error($form['edit_quantity'][$key])) {
      $commands[] = ctools_ajax_command_reload();
      return ['#type' => 'ajax', '#commands' => $commands];
    }
  }
  $commands[] = ctools_ajax_command_redirect($form_state['redirect']);
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Souriau ecommerce config form.
 *
 * Callback for admin/souriau-site-settings/souriau-ecommerce.
 */
function souriau_eco_form_site_settings_souriau_ecommerce($form, &$form_state) {
  $form = [];

  $form['souriau_site_settings_souriau_ecommerce'] = [
    '#tree' => TRUE,
  ];
  $default_value = variable_get('souriau_site_settings_souriau_ecommerce');
  if (empty($form_state['users_count']) && isset($default_value['orders']['notify']['users'])) {
    $form_state['users_count'] = count($default_value['orders']['notify']['users']);
  }
  elseif (empty($form_state['users_count'])) {
    $form_state['users_count'] = 1;
  }

  // ERP settings block.
  $erp_default = isset($default_value['erp']) ? $default_value['erp'] : FALSE;
  $form['souriau_site_settings_souriau_ecommerce']['erp'] = _souriau_eco_form_site_settings_souriau_ecommerce_erp_settings($erp_default);

  // Stock System block.
  $stock_default = isset($default_value['stock']) ? $default_value['stock'] : FALSE;
  $form['souriau_site_settings_souriau_ecommerce']['stock'] = _souriau_eco_form_site_settings_souriau_ecommerce_stock_settings($stock_default);

  // Block notify system.
  $form['souriau_site_settings_souriau_ecommerce']['orders'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Orders Notify System', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];
  $form['souriau_site_settings_souriau_ecommerce']['orders']['system'] = [
    '#type' => 'checkbox',
    '#title' => t('Notify ERP system', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#default_value' => isset($default_value['orders']['system']) ? $default_value['orders']['system'] : 0,
    '#description' => t('If checked, samples order request will be sent to mouser.', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  // Block Orders.
  $form['souriau_site_settings_souriau_ecommerce']['orders']['notify'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Users', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['souriau_site_settings_souriau_ecommerce']['orders']['notify']['description'] = [
    '#type' => 'markup',
    '#markup' => t('Users, that will be notified, when request has failed with unexpected error.',
      [],
      ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  for ($i = 1; $i <= $form_state['users_count']; $i++) {
    $form['souriau_site_settings_souriau_ecommerce']['orders']['notify']['users'][$i] = [
      '#type' => 'textfield',
      '#title' => NULL,
      '#default_value' => isset($default_value['orders']['notify']['users'][$i]) ? $default_value['orders']['notify']['users'][$i] : '',
      '#autocomplete_path' => 'user/autocomplete',
      '#element_validate' => ['souriau_eco_form_site_settings_souriau_ecommerce_user_validation'],
      '#weight' => -1,
      '#delta' => 0,
    ];
  }
  $form['souriau_site_settings_souriau_ecommerce']['orders']['notify']['add_item'] = [
    '#type' => 'submit',
    '#value' => t('Add one more user', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#submit' => array('souriau_eco_form_site_settings_souriau_ecommerce_add_item'),
  ];

  if ($form_state['users_count'] > 1) {
    $form['souriau_site_settings_souriau_ecommerce']['orders']['notify']['remove_item'] = array(
      '#type' => 'submit',
      '#value' => t('Remove latest name'),
      '#submit' => array('souriau_eco_form_site_settings_souriau_ecommerce_remove_item'),
      // Since we are removing a name, don't validate until later.
      '#limit_validation_errors' => array(),
    );
  }
  $form['delay_time_wrapper'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Order a free sample delay time', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['delay_time_wrapper']['souriau_eco_part_number_sample_order_delay_input'] = [
    '#type' => 'textfield',
    '#element_validate' => ['souriau_eco_form_delay_time_validate'],
    '#title' => t('Order a free sample delay time', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Set up delay time in next format: %days %hours:%minutes:%seconds. for ex: 74 0:0:0, it is mean that delay time is 74 days.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('souriau_eco_part_number_sample_order_delay_input', '0 0:1:40'),
  ];
  $form['delay_time_wrapper']['delay_time_information'] = [
    '#type' => 'markup',
    '#markup' => t('Current value: %value (seconds)', ['%value' => variable_get('souriau_eco_part_number_sample_order_delay', 100)], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  if (!module_exists('souriau_eco_erp')) {
    drupal_set_message(t('Module "Souriau ECommerce ERP" disabled', [], ['context' => SOURIAU_COMMON_T_ADMIN]), 'warning');
  }

  return system_settings_form($form);
}

/**
 * Element validate for souriau_eco_part_number_sample_order_delay_input. Delay time.
 *
 * @see souriau_eco_form_site_settings_souriau_ecommerce
 */
function souriau_eco_form_delay_time_validate(&$element) {
  if (empty($element['#value'])) {
    drupal_set_message(t('Field %field_name is empty. Delay time sets to default: 100 seconds', [
      '%field_name' => $element['#title'],
    ], ['context' => SOURIAU_COMMON_T_ADMIN]), 'warning');
    variable_set('souriau_eco_part_number_sample_order_delay', 100);
    return;
  }

  // If numeric value, perceive variable as in seconds.
  if (is_numeric($element['#value'])) {
    // Set machine readable variable in seconds.
    variable_set('souriau_eco_part_number_sample_order_delay', $element['#value']);
    return;
  }

  // Error counter.
  $errors = 0;

  // If string. Checking for correct format: "%days %h:%m:%s".
  $values = explode(' ', $element['#value']);
  $days = array_shift($values);

  // Only numeric values pass.
  if (!is_numeric($days)) {
    $errors++;
  }

  if (!empty($values) && !is_array($values[0])) {
    $values = explode(':', $values[0]);
    foreach ($values as &$value) {
      // Only numeric values pass.
      if (!is_numeric($value)) {
        $errors++;
      }
    }
    // Check on count elements: hours, minutes, seconds.
    if (count($values) == 3) {
      list($hours, $minutes, $second) = $values;
    }
    else {
      $errors++;
    }
  }
  else {
    $errors++;
  }

  if (!empty($errors)) {
    form_set_error($element['#name'], t('Incorrect format of field %field_name. Please input numeric format in seconds, or in the next format: "%days %h:%m:%s"', [
      '%field_name' => $element['#title'],
    ], ['context' => SOURIAU_COMMON_T_ADMIN]));
    return;
  }

  // Set machine readable variable in seconds.
  $total_sec = ($days * 86400) + ($hours * 3600) + ($minutes * 60) + $second;
  variable_set('souriau_eco_part_number_sample_order_delay', $total_sec);
}

/**
 * Callback for add item.
 */
function souriau_eco_form_site_settings_souriau_ecommerce_add_item($form, &$form_state) {
  $form_state['users_count']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Callback for remove item.
 */
function souriau_eco_form_site_settings_souriau_ecommerce_remove_item($form, &$form_state) {
  if ($form_state['users_count'] > 1) {
    $form_state['users_count']--;
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Element Validate.
 *
 * @param array $element
 *   Form element.
 */
function souriau_eco_form_site_settings_souriau_ecommerce_user_validation(array &$element) {
  $user = user_load_by_name($element['#value']);
  if (empty($user)) {
    form_set_error($element['#id'], t('User %user not found, try another name', ['%user' => $element['#value']], ['contex' => SOURIAU_COMMON_T_ADMIN]));
  }
}

/**
 * Helper function for FORM.
 *
 * @see souriau_eco_form_site_settings_souriau_ecommerce()
 */
function _souriau_eco_form_site_settings_souriau_ecommerce_stock_settings($default_value) {
  $form = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Stock System', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['system'] = [
    '#type' => 'radios',
    '#title' => t('Select system for getting information about samples stock', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#options' => [
      'worldwide_stock' => t('Worldwide', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'mouser_stock' => t('Mouser', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    ],
    '#default_value' => isset($default_value['system']) ? $default_value['system'] : 'worldwide_stock',
    '#description' => t('In case Worldwide, we get information from external DB: souriau_stock.samples', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  $form['shipping_accepted_countries'] = [
    '#type' => 'textfield',
    '#title' => t('Shipping Accepted Countries', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['shipping_accepted_countries']) ? $default_value['shipping_accepted_countries'] : 'CA|MX|US',
    '#description' => t('List of country codes that allows mouser shipping. Enter the country codes separated by "|"', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];
  $form['ecia'] = [
    '#title' => t('ECIA', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  $form['ecia']['company_id'] = [
    '#type' => 'textfield',
    '#title' => t('Company ID', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Enter the company id which is specified in ECIA portal', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ecia']['company_id']) ? $default_value['ecia']['company_id'] : 'Souriau'
  ];

  $form['ecia']['api_key'] = [
    '#type' => 'textfield',
    '#title' => t('API Key', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Enter the API key which is specified in ECIA portal', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ecia']['api_key']) ? $default_value['ecia']['api_key'] : '55fb3df6-8dd0-4252-b54f-2f37adcabd02',
  ];

  $form['ecia']['api_search_url'] = [
    '#type' => 'textfield',
    '#title' => t('API Search URL', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Enter the search api URL', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ecia']['api_search_url']) ? $default_value['ecia']['api_search_url'] : 'https://inventory.api.eciaauthorized.com/api/Search/Query',
  ];

  $form['ecia']['manufacturers'] = [
    '#type' => 'textfield',
    '#title' => t('Manufacturers', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Enter the manufacturers seperated by | character in case of more than one', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ecia']['manufacturers']) ? $default_value['ecia']['manufacturers'] : 'souriau|sunbank',
  ];

  // For billing address.
  $form['billing'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Billing Address for US/CA/MX orders', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];
  $form['billing']['first_name'] = [
    '#type' => 'textfield',
    '#title' => t('First Name', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['first_name']) ? $default_value['billing']['first_name'] : '',
    '#required' => TRUE
  ];
  $form['billing']['last_name'] = [
    '#type' => 'textfield',
    '#title' => t('Last Name', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['last_name']) ? $default_value['billing']['last_name'] : '',
    '#required' => TRUE
  ];
  $form['billing']['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['title']) ? $default_value['billing']['title'] : '-',
    '#required' => TRUE
  ];
  $form['billing']['adress_line1'] = [
    '#type' => 'textfield',
    '#title' => t('Address Line 1', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['adress_line1']) ? $default_value['billing']['adress_line1'] : '',
    '#required' => TRUE
  ];
  $form['billing']['adress_line2'] = [
    '#type' => 'textfield',
    '#title' => t('Address Line 2', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['adress_line2']) ? $default_value['billing']['adress_line2'] : '',
  ];
  $form['billing']['city'] = [
    '#type' => 'textfield',
    '#title' => t('City', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['city']) ? $default_value['billing']['city'] : '',
    '#required' => TRUE
  ];
  $form['billing']['country_code'] = [
    '#type' => 'textfield',
    '#title' => t('Country Code', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['country_code']) ? $default_value['billing']['country_code'] : '',
    '#required' => TRUE
  ];
  $form['billing']['region_code'] = [
    '#type' => 'textfield',
    '#title' => t('Region Code', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['region_code']) ? $default_value['billing']['region_code'] : '-',
    '#required' => TRUE
  ];
  $form['billing']['postal_code'] = [
    '#type' => 'textfield',
    '#title' => t('Postal Code', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['postal_code']) ? $default_value['billing']['postal_code'] : '',
    '#required' => TRUE
  ];
  $form['billing']['company'] = [
    '#type' => 'textfield',
    '#title' => t('Company Name', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['company']) ? $default_value['billing']['company'] : '',
    '#required' => TRUE
  ];
  $form['billing']['email_address'] = [
    '#type' => 'textfield',
    '#title' => t('Email Address', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['email_address']) ? $default_value['billing']['email_address'] : 'souriau-customer@souriau.com',
    '#required' => TRUE
  ];
  $form['billing']['phone'] = [
    '#type' => 'textfield',
    '#title' => t('Phone', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#default_value' => isset($default_value['billing']['phone']) ? $default_value['billing']['phone'] : '',
    '#required' => TRUE
  ];

  return $form;
}

/**
 * Helper function for FORM.
 *
 * @see souriau_eco_form_site_settings_souriau_ecommerce()
 */
function _souriau_eco_form_site_settings_souriau_ecommerce_erp_settings($default_value) {
  $form = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('ERP settings', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['client_token'] = [
    '#type' => 'textfield',
    '#title' => t('Client Token', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#default_value' => isset($default_value['client_token']) ? $default_value['client_token'] : '57FE074A-7A07-4B28-892F-D7B6278A19B2',
    '#description' => t('Client Identifier', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  $form['mouser_url'] = [
    '#type' => 'textfield',
    '#title' => t('Mouser API URL', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#disabled' => !module_exists('souriau_eco_erp'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#default_value' => isset($default_value['mouser_url']) ? $default_value['mouser_url'] : 'https://tpltest.services.mouser.com',
    '#description' => t('URL to mouser services to send request', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  return $form;
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function souriau_eco_form_commerce_checkout_form_shipping_alter(&$form, &$form_state, $form_id) {
  global $user;
  $form_state['storage'] = [];

  module_load_include('inc', 'commerce_addressbook', 'includes/commerce_addressbook.user');

  $form_state['build_info']['files']['souriau_eco'] = [
    'module' => 'souriau_eco',
    'name' => 'souriau_eco.pages',
    'type' => 'inc',
  ];

  $form_state['build_info']['files']['commerce_customer'] = [
    'module' => 'commerce_customer',
    'name' => 'includes/commerce_customer_profile.forms',
    'type' => 'inc',
  ];

  $form_state['build_info']['files']['commerce_checkout_pages'] = [
    'module' => 'commerce_checkout',
    'name' => 'includes/commerce_checkout.pages',
    'type' => 'inc',
  ];

  $customer_profile = commerce_customer_profile_new('shipping', $user->uid);

  $default_profile_id = commerce_addressbook_get_default_profile_id($user->uid, 'shipping');
  if (_souriau_eco_check_profile_status($default_profile_id) == FALSE) {
    $default_profile_id = NULL;
  }
  $customer_profile_shipping = &$form['customer_profile_shipping'];
  if (isset($customer_profile_shipping['addressbook_entries']) && !empty($default_profile_id)) {
    foreach ($customer_profile_shipping['addressbook_entries']['#value'] as $profile_id => $profile) {
      if (_souriau_eco_check_profile_status($profile_id) == FALSE) {
        unset($customer_profile_shipping['addressbook_entries']['#value'][$profile_id]);
        continue;
      }
      $profile_wrapper = entity_metadata_wrapper('commerce_customer_profile', $profile);
      $customer_profile_shipping['addressbook']['#options'][$profile->profile_id] = [
        '#title' => $profile_wrapper->label(),
        '#entity' => $profile,
      ];
      $customer_profile_shipping['addressbook']['#theme'] = 'souriau_eco_checkout_form_address';
    }
    $customer_profile_shipping['addressbook']['#default_value'] = $default_profile_id;
    $customer_profile = $customer_profile_shipping['addressbook']['#options'][$default_profile_id]['#entity'];
  }
  else {
    $customer_profile_shipping['addressbook']['#default_value'] = 'none';
  }
  $customer_profile_shipping['addressbook']['#type'] = 'radios';
  $customer_profile_shipping['addressbook']['#process'] = ['souriau_eco_commerce_checkout_process_radios'];
  $customer_profile_shipping['addressbook']['#theme_wrappers'][] = ['souriau_eco_checkout_form_list_address'];
  unset($customer_profile_shipping['addressbook']['#description']);
  $customer_profile_shipping['addressbook']['#title_display'] = 'invisible';
  $customer_profile_shipping['addressbook']['#options']['none'] = t('Or create a new address', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);

  $customer_profile_shipping['addressbook']['#ajax']['callback'] = 'souriau_eco_checkout_form_shipping_edit_callback';
  $customer_profile_shipping['addressbook']['#ajax']['wrapper'] = 'customer-profile-shipping-ajax-wrapper';

  $_title = '';

  if (isset($form_state['triggering_element']) && $form_state['triggering_element']['#name'] == 'customer_profile_shipping[addressbook]') {

    foreach (['input', 'values'] as $k) {
      $_fields = [
        'commerce_customer_address',
        'field_address_name',
        'customer_profile',
      ];
      foreach ($_fields as $f) {
        unset($form_state[$k]['customer_profile_shipping'][$f]);
      }
    }

    unset(
      $customer_profile_shipping['commerce_customer_address'],
      $customer_profile_shipping['field_address_name']
    );
  }

  if ($form_state['input']) {
    $addressbook = $form_state['input']['customer_profile_shipping']['addressbook'];

    if ($addressbook != 'none') {
      $_title = t('Edit address', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
      $customer_profile = $customer_profile_shipping['addressbook']['#options'][$addressbook]['#entity'];
    }
    else {
      $customer_profile = commerce_customer_profile_new('shipping', $user->uid);
    }
  }
  field_attach_form('commerce_customer_profile', $customer_profile, $customer_profile_shipping, $form_state);

  _souriau_eco_form_commerce_addressbook_customer_profile_form_prepare($customer_profile_shipping);

  $form_state['customer_profile'] = $customer_profile;

  $_lang = $customer_profile_shipping['commerce_customer_address']['#language'];
  $customer_profile_shipping['commerce_customer_address'][$_lang][0]['#title'] = $_title;

  unset($customer_profile_shipping['actions']);

  $form['buttons']['#type'] = 'actions';
  $form['buttons']['#souriau_settings'] = [
    'align' => 'center',
    'text_align' => 'center',
  ];

  $form['buttons']['continue']['#value'] = t('CONFIRM ORDER', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  $form['buttons']['continue']['#attributes'] = [
    'class' => ['a-right'],
  ];

  array_unshift($form['buttons']['continue']['#validate'], 'souriau_eco_commerce_checkout_form_validate');

  $form['buttons']['continue']['#submit'][] = 'souriau_eco_commerce_checkout_form_submit';

  $form['buttons']['continue']['#souriau_settings'] = [
    'hover_color' => 'orange',
  ];

  $form['buttons']['back']['#value'] = t('BACK TO CART', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  $form['buttons']['back']['#attributes'] = [
    'class' => ['btn', 'blue-btn'],
  ];
  unset($form['buttons']['back']['#prefix']);

  return $form;
}

/**
 * Helper Function for FORM. Remove unnecessary fields from form_state.
 *
 * @param array $form_state
 *   Form state.
 *
 * @see souriau_eco_form_commerce_checkout_form_shipping_alter()
 */
function _souriau_eco_form_commerce_checkout_form_shipping_alter_remove_fields(array &$form_state) {
  foreach (['input', 'values'] as $k) {
    foreach (['commerce_customer_address', 'field_address_name'] as $field) {
      if (isset($form_state[$k][$field])) {
        unset($form_state[$k][$field]);
      }
    }
  }
}

/**
 * Expands a radios element into individual radio elements.
 */
function souriau_eco_commerce_checkout_process_radios($element) {
  if (count($element['#options']) > 0) {
    $weight = 0;
    $i = 0;
    foreach ($element['#options'] as $key => $choice) {
      // Maintain order of options as defined in #options, in case the element
      // defines custom option sub-elements, but does not define all option
      // sub-elements.
      $weight += 0.001;
      $i++;

      $element += array($key => array());
      // Generate the parents as the autogenerator does, so we will have a
      // unique id for each radio button.
      $parents_for_id = array_merge($element['#parents'], array($key));
      $element[$key] += array(
        '#type' => 'radio',
        '#title' => is_array($choice) ? $choice['#title'] : $choice,
        // The key is sanitized in drupal_attributes() during output from the
        // theme function.
        '#return_value' => $key,
        // Use default or FALSE. A value of FALSE means that the radio button is
        // not 'checked'.
        '#default_value' => isset($element['#default_value']) ? $element['#default_value'] : FALSE,
        '#attributes' => $element['#attributes'],
        '#parents' => $element['#parents'],
        '#id' => drupal_html_id('edit-' . implode('-', $parents_for_id)),
        '#ajax' => isset($element['#ajax']) ? $element['#ajax'] : NULL,
        '#weight' => $weight,
        '#zebra' => ($i % 2) ? 'odd' : 'even',
        '#align' => ($i % 2) ? 'left' : 'right',
        '#theme_wrappers' => ['form_element', 'souriau_eco_checkout_form_list_address_item'],
      );
      if ($key != 'none') {
        $element[$key]['#title_display'] = 'screen_reader';
      }
      $element[$key]['#attributes']['class'][] = 'select-address-input';

      if (isset($choice['#entity'])) {
        $profile_wrapper = entity_metadata_wrapper('commerce_customer_profile', $choice['#entity']);
        $element[$key]['#entity'] = $choice['#entity'];
        $element[$key]['#info'] = [
          'title' => $profile_wrapper->field_address_name->value(),
          'name_line' => $profile_wrapper->commerce_customer_address->name_line->value(),
          'thoroughfare' => $profile_wrapper->commerce_customer_address->thoroughfare->value(),
          'premise' => $profile_wrapper->commerce_customer_address->premise->value(),
          'locality' => $profile_wrapper->commerce_customer_address->locality->value(),
          'country' => $profile_wrapper->commerce_customer_address->country->value(),
          'phone_number' => $profile_wrapper->commerce_customer_address->phone_number->value(),
          'mobile_number' => $profile_wrapper->commerce_customer_address->mobile_number->value(),
        ];
      }
    }
  }

  return $element;
}

/**
 * Validation callback for checkout shipping form.
 */
function souriau_eco_checkout_form_shipping_save_validate($form, &$form_state) {
  if (!empty($form_state['customer_profile'])) {
    $customer_profile = $form_state['customer_profile'];

    if (!empty($form_state['values']['name']) && !user_load_by_name($form_state['values']['name'])) {
      form_set_error('name', t('The username %name does not exist.', array('%name' => $form_state['values']['name'])));
    }

    field_attach_form_validate('commerce_customer_profile', $customer_profile, $form, $form_state);
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 */
function souriau_eco_form_views_form_souriau_minicart_default_alter(&$form, &$form_state, $form_id) {
  unset($form['actions']);
  if (isset($form['edit_delete'])) {
    foreach ($form['edit_delete'] as $key => $value) {
      if (is_numeric($key) && drupal_substr($key, 0, 1) != '#' && is_array($value)) {
        $icon = [
          '#type' => 'svg_icon',
          '#icon' => 'ico-remove',
        ];
        $form['edit_delete'][$key] = [
          '#type' => 'link',
          '#title' => drupal_render($icon),
          '#href' => 'souriau/ajax/mini-cart/nojs/' . $form['edit_delete'][$key]['#line_item_id'] . '/' . $form_state['order']->order_number . '/delete',
          '#options' => ['html' => TRUE],
          '#attributes' => [
            'class' => [
              'ctools-use-modal',
              'ctools-modal-souriau-modal-style',
              'remove-link',
            ],
          ],
        ];
      }
    }
  }
}

/**
 * Implements hook_form_alter().
 */
function souriau_eco_form_alter(&$form, &$form_state, $form_id) {
  if (strpos($form_id, 'commerce_checkout_form') === 0) {
    $errors = isset($form_state['storage']['errors']) ? $form_state['storage']['errors'] : [];
    if ($errors) {
      foreach ($errors as $error) {
        drupal_set_message($error, 'error');
      }

      $checkout_page = $form_state['checkout_page'];
      $checkout_panes = commerce_checkout_panes([
        'enabled' => TRUE,
        'page' => $checkout_page['page_id'],
      ]);

      foreach ($checkout_panes as $pane_id => $checkout_pane) {
        if (isset($form[$pane_id]) && isset($form[$pane_id][$pane_id . '_messages'])) {
          hide($form[$pane_id][$pane_id . '_messages']);
        }
      }
    }
  }
}

/**
 * Checks the status of customer profile.
 */
function _souriau_eco_check_profile_status($profile_id = NULL) {
  $query = db_select('commerce_customer_profile', 'ccp')
    ->fields('ccp', array('profile_id'))
    ->condition('profile_id', $profile_id)
    ->condition('status', 1)
    ->execute();
  $record = $query->fetchObject();

  return ($record) ? TRUE : FALSE;
}
