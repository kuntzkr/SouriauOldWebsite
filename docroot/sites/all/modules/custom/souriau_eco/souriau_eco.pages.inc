<?php
/**
 * @file
 * Souriau Ecommerce pages.
 */

/**
 * Callback for form cancel.
 */
function souriau_eco_address_cancel_callback() {
  $commands = [];
  $commands[] = ajax_command_html('#js-commerce-addressbook-customer-profile-form', '');
  $commands[] = ajax_command_invoke('#js-create-new-address', 'removeClass', ['hide-btn']);

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Callback for delete address.
 */
function souriau_eco_address_delete_confirm_callback($commerce_customer_profile) {
  ctools_include('modal');
  ctools_modal_add_js();

  $form_state = [
    'ajax' => TRUE,
    'commerce_customer_profile' => $commerce_customer_profile,
  ];

  $commands = ctools_modal_form_wrapper('souriau_eco_address_delete_confirm_form', $form_state);
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['remove-popup']);
  $commands[] = ajax_command_invoke('#modal-content', 'removeClass');

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Ajax callback for delete user address.
 */
function souriau_eco_address_delete_submit_callback($form, $form_state) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  global $user;

  $commerce_customer_profile = $form_state['commerce_customer_profile'];

  $commands = [];
  $update_address_status = _souriau_eco_delete_address($commerce_customer_profile);
  if ($update_address_status) {
    $commands[] = ajax_command_html(
      '#js-commerce-addressbook-addresses',
      commerce_embed_view('souriau_commerce_addressbook', 'default', [$user->uid, 'shipping'])
    );

    $commands[] = ctools_modal_command_display(
      '', t("Your shipping address has been deleted", [], ['context' => SOURIAU_COMMON_T_COMMERCE])
      );
  }
  else {
    $commands[] = ctools_modal_command_display(
      '', t("Address can't be deleted!", [], ['context' => SOURIAU_COMMON_T_COMMERCE])
    );
  }

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Call form using ajax.
 *
 * @return array
 *   Ajax commands.
 */
function souriau_eco_address_edit_form_callback($commerce_customer_profile = FALSE) {
  ctools_include('ajax');
  ctools_include('modal');
  ctools_modal_add_js();

  global  $user;

  $commands = [];

  module_load_include('inc', 'commerce_addressbook', 'includes/commerce_addressbook.user');

  if ($commerce_customer_profile) {
    // Form for edit existing address.
    $form = commerce_addressbook_profile_options_edit($user, $commerce_customer_profile);
    $customer_address_field = &$form['commerce_customer_address'][$form['commerce_customer_address']['#language']][0];
    $customer_address_field['#title'] = t('EDIT ADDRESS', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
    $form['actions']['submit']['#value'] = t('UPDATE THIS ADDRESS', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  }
  else {
    // Empty form for creation new address.
    $form = commerce_addressbook_profile_create($user, 'shipping');
  }

  $commands[] = ajax_command_html('#js-commerce-addressbook-customer-profile-form', "<div>" . drupal_render($form) . "</div>");
  $commands[] = ajax_command_invoke('#js-create-new-address', 'addClass', ['hide-btn']);

  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Load address fields into checkout shipping form.
 */
function souriau_eco_checkout_form_shipping_edit_callback(&$form, &$form_state) {
  $pane_id = $form_state['triggering_element']['#parents'][0];
  $pane = $form[$pane_id];

  $pane['addressbook']['#access'] = FALSE;

  $commands = array();
  $commands[] = ajax_command_replace(NULL, drupal_render($pane));
  unset($form_state['storage']);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Callback for save default customer profile.
 */
function souriau_eco_commerce_checkout_form_submit($form, &$form_state) {
  commerce_addressbook_set_default_profile($form_state['customer_profile']);
}

/**
 * Pre-validate handler for the continue button of the checkout form.
 */
function souriau_eco_commerce_checkout_form_validate($form, &$form_state) {
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $ecommerce_stock_system = isset($site_commerce_settings['stock']['system']) ? $site_commerce_settings['stock']['system'] : 'worldwide_stock';
  if ($ecommerce_stock_system == "mouser_stock") {
    $shipping_accepted_countries = $site_commerce_settings['stock']['shipping_accepted_countries'];
    $mouser_countries = !empty($shipping_accepted_countries)
      ? explode('|', $shipping_accepted_countries) : ['CA', 'MX', 'US', 'CN'];
    $shipping_country = $form_state['values']['customer_profile_shipping']['commerce_customer_address'][LANGUAGE_NONE][0]['country'];
    if (!in_array($shipping_country, $mouser_countries)) {
      form_set_error('customer_profile_shipping][commerce_customer_address][' . LANGUAGE_NONE . '][0][country', t("Product can only be sent to @country countries.",
        ['@country' => implode(',', $mouser_countries)], ['context' => SOURIAU_COMMON_T_COMMERCE]));
      return;
    }
  }
  $form_state['values']['customer_profile_shipping']['customer_profile'] = $form_state['customer_profile'];
}

/**
 * Sample add callback.
 */
function souriau_eco_sample_add_callback($sku, $ajax = NULL) {
  $commands = [];
  $messages_location = '.pane-page-content';
  if (user_is_anonymous()) {
    $commands[] = souriau_common_ajax_set_message(
      $messages_location,
      t('To order a free sample, please !login or !register',
        [
          '!login' => l(t('login'), 'user/login'),
          '!register' => l(t('create a new account'), 'user/register'),
        ], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'error');
    return array('#type' => 'ajax', '#commands' => $commands);
  }
  global $user;

  try {
    $cart = commerce_cart_order_load($user->uid);
    if (empty($cart)) {
      $cart = commerce_cart_order_new($user->uid, 'samples_order');
    }
  }
  catch (Exception $e) {
    watchdog('souriau_eco', 'Exception %message in !function.', [
      '%message' => $e->getMessage(),
      '!function' => __FUNCTION__,
    ], WATCHDOG_WARNING);
  }
  // User can't request more the one free sample.
  if (souriau_eco_is_sku_in_order($sku, $cart)) {
    $commands[] = souriau_common_ajax_set_message($messages_location, t('This free sample already in cart', [], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'error');
    return array('#type' => 'ajax', '#commands' => $commands);
  }

  $period = variable_get('souriau_eco_part_number_sample_order_delay', 100);
  $pn_quantities = souriau_eco_get_product_max_quantity_and_stock($sku->sku);
  $pn_quantities['max_qty'] = 100;
  if (!site_common_user_has_role('sample_manager') && souriau_eco_sku_sample_previously_ordered_count($sku, $period, $user->uid) >= $pn_quantities['max_qty']) {
    $commands[] = souriau_common_ajax_set_message($messages_location, t('You already ordered this part number', [], ['context' => SOURIAU_COMMON_T_COMMERCE]), 'error');
    return array('#type' => 'ajax', '#commands' => $commands);
  }

  if (souriau_eco_get_product_max_quantity($sku->sku) <= 0) {
    $contact_link = l(t('contact us.', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'contact');
    $message = t('Sorry, this sample is out of stock. If you need further assistance, please', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
    $commands[] = souriau_common_ajax_set_message($messages_location, $message . ' ' . $contact_link, 'error');
    return array('#type' => 'ajax', '#commands' => $commands);
  }
  try {
    $quantity = 1;
    $line_item = commerce_product_line_item_new($sku, $quantity);
    $line_item_is_added = commerce_cart_product_add($user->uid, $line_item);
  }
  catch (Exception $e) {
    watchdog('souriau_eco', 'Exception %message in !function.', [
      '%message' => $e->getMessage(),
      '!function' => __FUNCTION__,
    ], WATCHDOG_WARNING);
  }

  if (empty($line_item_is_added)) {
    $contact_link = l(t('contact support.', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'contact');
    $message = t('Sample for this part number can\'t be added into Cart, please ', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
    $commands[] = souriau_common_ajax_set_message($messages_location, $message . ' ' . $contact_link, 'error');
    return array('#type' => 'ajax', '#commands' => $commands);
  }

  $commands[] = souriau_common_ajax_set_message($messages_location, t('Free sample has been added to cart successfully', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));

  // Updating the cart count.
  module_load_include('inc', 'souriau_common', 'includes/souriau_common.minicart');
  $cart_content = souriau_common_minicart_header_build_cart();
  $cart_data = $cart_content['link_path'];
  $commands[] = ajax_command_replace('#header-cart-count', $cart_data);
  // Updating minicart contents.
  $minicart_cart_content = souriau_common_header_build_popup_cart();
  $commands[] = ajax_command_replace('.w-popup-cart', $minicart_cart_content);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Check access.
 *
 * Check access Current User for this Address.
 * And check authorized user ID and user ID in request.
 * Unsubscribe link in newsletter form on edit user page menu callback.
 */
function souriau_eco_confirm_detete_callback($js = NULL, $line_item = NULL, $order = NULL) {
  $form_state = [
    'triggered_link' => [
      'element' => 'delete',
      'form_id' => 'souriau_eco_line_item',
    ],
    'line_item' => $line_item,
    'order' => $order,
  ];

  $confirm_options = [
    'question' => t('Delete this things ?', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'description' => t('You are about to cancel this product to your cart would you continue?', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'yes' => t('Confirm', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'no' => t('Cancel', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'name' => t('Confirm', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  ];

  return souriau_common_confirm_callback($form_state, $confirm_options);
}

/**
 * Minicart line-item delete callback function.
 */
function souriau_eco_minicart_confirm_delete_callback($js = NULL, $line_item = NULL, $order = NULL) {
  $commands = [];
  $messages_location = '.pane-page-content';
  $commands[] = souriau_common_ajax_set_message($messages_location, t('Free sample has been removed from cart successfully', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));

  $commands[] = ctools_modal_command_dismiss();

  $form_state = [
    'triggered_link' => [
      'element' => 'delete',
      'form_id' => 'souriau_eco_line_item',
    ],
    'line_item' => $line_item,
    'order' => $order,
    'ajax_commands' => $commands,
    'extra_id' => 'souriau_eco_minicart_delete',
  ];

  $confirm_options = [
    'question' => t('Delete this things ?', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'description' => t('You are about to cancel this product to your cart would you continue?', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'yes' => t('Confirm', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'no' => t('Cancel', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'name' => t('Confirm', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  ];

  return souriau_common_confirm_callback($form_state, $confirm_options);
}

/**
 * Ajax callback for minicart load.
 */
function souriau_eco_minicart_load() {
  $commands = [];
  // Updating the cart count.
  module_load_include('inc', 'souriau_common', 'includes/souriau_common.minicart');
  $cart_content = souriau_common_minicart_header_build_cart();
  $cart_data = $cart_content['link_path'];
  $commands[] = ajax_command_replace('#header-cart-count', $cart_data);
  // Updating minicart contents.
  $minicart_cart_content = souriau_common_header_build_popup_cart();
  $commands[] = ajax_command_replace('.w-popup-cart', $minicart_cart_content);

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Change status of commerce_customer_profile and delete default profile id.
 *
 * @see commerce_addressbook_commerce_customer_profile_delete
 * in commerce_addressbook.module.
 */
function _souriau_eco_delete_address($profile) {
  $address_update = db_update('commerce_customer_profile')
    ->fields(['status' => '0'])
    ->condition('profile_id', $profile->profile_id)
    ->execute();
  $default_profile = commerce_addressbook_get_default_profile_id($profile->uid, $profile->type);
  if ($default_profile == $profile->profile_id) {
    db_delete('commerce_addressbook_defaults')
      ->condition('profile_id', $profile->profile_id)
      ->execute();

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'commerce_customer_profile')
      ->propertyCondition('status', 1)
      ->propertyCondition('uid', $profile->uid)
      ->propertyCondition('type', $profile->type)
      ->propertyOrderBy('profile_id', 'DESC')
      ->range(0, 1);
    $results = $query->execute();
    if (!empty($results['commerce_customer_profile'])) {
      commerce_addressbook_set_default_profile(commerce_customer_profile_load(key($results['commerce_customer_profile'])));
    }
  }
  return $address_update;
}
