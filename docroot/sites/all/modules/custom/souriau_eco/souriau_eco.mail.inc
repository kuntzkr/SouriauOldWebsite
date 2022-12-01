<?php

/**
 * @file
 * Mail hooks.
 */

/**
 * Implements hook_mailkeys().
 */
function souriau_eco_mailkeys() {
  return [
    'checkout_waiting_sample_notify_csr' => t('Send Notify message for admins on successful sample order and to approve.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_processing_started_sample_notify_csr' => t('Send Notify message for admins after approval and processing started.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_shipment_started_sample_notify_csr' => t('Send Notify message to admin on sample shipment started .', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_completed_errors' => t('Send Notify message for admins on appears Errors.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_completed_cancelation' => t('Send message to user on Sample order request cancellation.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_waiting_sample_notify_user' => t('Send Notify message to users on sample order receival.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_processing_started_sample_notify' => t('Send Notify message to users on sample order processing start time.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_shipment_started_sample_notify' => t('Send Notify message to users on sample order shipment start time.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
    'checkout_completed_sample_notify_row_usr' => t('Send Notify message for EU and ROW users on successful sample order.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]),
  ];
}

/**
 * Implements hook_mail_edit_text().
 */
function souriau_eco_mail_edit_text($key, $language) {
  $text = [];
  // Implement default value.
  $text['subject'] = _souriau_common_mail_text($key . '_subject', $language);
  $text['body'] = _souriau_common_mail_text($key . '_body', $language);
  return $text;
}

/**
 * Implements hook_mail().
 */
function souriau_eco_mail($key, &$message, $params) {
  $language = isset($message['language']) ? $message['language'] : NULL;
  $message['subject'] = _souriau_common_mail_text($key . '_subject', $language, $params);
  $message['body'] = _souriau_common_mail_text($key . '_body', $language, $params);
}

/**
 * Implements hook_form_alter().
 */
function souriau_eco_form_mail_edit_template_form_alter(&$form, &$form_state, $form_id) {
  // Mail template forms.
  $forms = [
    'souriau_eco_checkout_completed_sample_notify',
    'souriau_eco_checkout_completed_errors',
  ];
  // Add commerce-order into token tree.
  if (in_array($form['id']['#value'], $forms)) {
    $form['mail']['token_tree']['#token_types'] = ['commerce-order'];
  }

  // Mail template forms.
  $forms = [
    'souriau_common_training_confirmation_mail',
    'souriau_common_training_notification_mail',
    'souriau_common_contact_notification_mail',
  ];
  if (in_array($form['id']['#value'], $forms)) {
    $form['mail']['token_tree']['#token_types'][] = 'submission';
  }
}

/**
 * Mail subject for checkout_completed_cancelation mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_completed_cancelation_subject() {
  return 'Your samples order #[commerce-order:order-id] from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for checkout_completed_cancelation mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_completed_cancelation_body() {
  return 'Hello [user:field-first-name] [user:field-last-name],

Oops…We were not able to proceed to your sample order.

Reason for cancellation : [commerce-order:field_commerce_cancel_desc]

Please accept our sincere apologies for the inconvenience you may have experienced.

Feel free to contact the customer service team <a href="[site:url]/contact">[site:url]/contact</a> for further help with samples.

Thank you.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for checkout_completed_errors mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_completed_errors_subject() {
  return 'Error, while sending request';
}

/**
 * Mail body for checkout_completed_errors mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_completed_errors_body() {
  return 'Error, while sending request, Please check it.
order_id: [commerce-order:order-id]
order_uid: [commerce-order:uid];

link: <a href="admin/commerce/orders/[commerce-order:order-id]/erp">link</a>';
}

/**
 * Mail subject for checkout_waiting_sample_notify mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_waiting_sample_notify_user_subject() {
  return 'Your order #[commerce-order:order-id] received from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for for checkout_waiting_sample_notify mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_waiting_sample_notify_user_body() {
  return 'Hello,

This email confirms your order received. Once your order processing started, you will receive a notification e-mail.

You can find the status of your current order at:
<a href="[commerce-order:field_commerce_shipping_provider]/user/login">Login</a> and click here <a href="[commerce-order:field_commerce_shipping_provider]/user/[commerce-order:uid]/sample-orders/[commerce-order:order-id]" target="_blank">Order Status</a>

If you have any questions about your order, please email us at <a href="mailto:USPAS-AMERICASSales@Eaton.com">USPAS-AMERICASSales@Eaton.com</a> or call us at 717-718-8810

Order No : #[commerce-order:order-id]

[commerce-order:lite-line-orders]

DELIVERY ADDRESS
[commerce-order:commerce_customer_shipping]

Thank you.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for checkout_processing_started_sample_notify mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_processing_started_sample_notify_subject() {
  return 'Your order #[commerce-order:order-id] processing started from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for checkout_processing_started_sample_notify mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_processing_started_sample_notify_body() {
  return 'Hello,

This email confirms your order processing started. Once your order has shipped, you will receive a shipping confirmation e-mail.

You can find the status of your current order at :
<a href="[commerce-order:field_commerce_shipping_provider]/user/login">Login</a> and click here <a href="[commerce-order:field_commerce_shipping_provider]/user/[commerce-order:uid]/sample-orders/[commerce-order:order-id]" target="_blank">Order Status</a>

If you have any questions about your order, please email us at <a href="mailto:USPAS-AMERICASSales@Eaton.com">USPAS-AMERICASSales@Eaton.com</a> or call us at 717-718-8810

Order No : #[commerce-order:order-id]

[commerce-order:lite-line-orders]

DELIVERY ADDRESS
[commerce-order:commerce_customer_shipping]

Thank you.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for checkout_shipment_started_sample_notify mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_shipment_started_sample_notify_subject() {
  return 'Your order #[commerce-order:order-id] is shipped from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for checkout_shipment_started_sample_notify mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_shipment_started_sample_notify_body() {
  return 'Hello,

Your order from SOURIAU - SUNBANK Connection Technologies is being processed by our warehouse and will be shipped on [commerce-order:field-commerce-shipped-date:custom:jS F Y]. 
You can track your order on the website using their <a href="[commerce-order:field_commerce_shipping_link]" target="_blank">online tracking service</a>.

Please note that it may take up to 24 hours for tracking information to become available online.
Please include your ECT order reference number #[commerce-order:order-id], as well as your name and email address on all correspondence regarding this order.

If you have any questions about your order, please email us at <a href="mailto:USPAS-AMERICASSales@Eaton.com">USPAS-AMERICASSales@Eaton.com</a> or call us at 717-718-8810.

Order No : #[commerce-order:order-id]

Cart Summary

[commerce-order:lite-line-orders]

DELIVERY ADDRESS
[commerce-order:commerce_customer_shipping]

Thank you.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for checkout_waiting_sample_notify_csr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_waiting_sample_notify_csr_subject() {
  return 'Order received #[commerce-order:order-id] from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for checkout_waiting_sample_notify_csr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_waiting_sample_notify_csr_body() {
  return 'Hello,

You received a new sample order from SOURIAU - SUNBANK Connection Technologies.

Order No : #[commerce-order:order-id]

[commerce-order:lite-line-orders]

DELIVERY ADDRESS
[commerce-order:commerce_customer_shipping]

Login here to confirm / refuse the order <a href="[site:url]/admin/dashboard/ecommerce/mouser-orders">Manage Order</a>.

Thank you.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for checkout_processing_started_sample_notify_csr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_processing_started_sample_notify_csr_subject() {
  return 'Your order #[commerce-order:order-id] processing started from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for checkout_processing_started_sample_notify_csr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_processing_started_sample_notify_csr_body() {
  return 'Hello,

This email confirms your order processing started. Once your order has shipped, you will receive a shipping confirmation e-mail.
If you have any questions about your order, please email us at <a href="mailto:USPAS-AMERICASSales@Eaton.com">USPAS-AMERICASSales@Eaton.com</a> or call us at 717-718-8810

Order No : #[commerce-order:order-id]

[commerce-order:lite-line-orders]

DELIVERY ADDRESS
[commerce-order:commerce_customer_shipping]

Thank you.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for checkout_shipment_started_sample_notify_csr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_shipment_started_sample_notify_csr_subject() {
  return 'Your order #[commerce-order:order-id] is shipped from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for checkout_shipment_started_sample_notify_csr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_shipment_started_sample_notify_csr_body() {
  return 'Hello,

Your order from SOURIAU - SUNBANK Connection Technologies is being processed by our warehouse and will be shipped on [commerce-order:field-commerce-shipped-date:custom:jS F Y]. 
You can track your order on the website using their <a href="[commerce-order:field_commerce_shipping_link]" target="_blank">online tracking service</a>.

Please note, it may take up to 24 hours for tracking information to become available online.
Please include your ECT order reference number #[commerce-order:order-id], as well as your name and email address on all correspondense regarding this order.

If you have any questions about your order, please email us at <a href="mailto:USPAS-AMERICASSales@Eaton.com">USPAS-AMERICASSales@Eaton.com</a> or call us at 717-718-8810

Order No : #[commerce-order:order-id]

Cart Summary :

[commerce-order:lite-line-orders]

DELIVERY ADDRESS
[commerce-order:commerce_customer_shipping]

Thank you.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for checkout_completed_sample_notify_row_usr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_completed_sample_notify_row_usr_subject() {
  return 'Order Confirmation : Sample Order #[commerce-order:order-id] from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for checkout_completed_sample_notify_row_usr mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_eco_mail_checkout_completed_sample_notify_row_usr_body() {
  return 'Thanks for your order #[commerce-order:order-number] at [site:name].


  If this is your first order with us, you will receive a separate e-mail with login instructions.
  
  You can find the status of your current order at:

  <a href="[commerce-order:field_commerce_shipping_provider]/user/login">Login</a> and click here <a href="[commerce-order:field_commerce_shipping_provider]/user/[commerce-order:uid]/sample-orders/[commerce-order:order-id]" target="_blank">Order Status</a>
  
  Please contact us if you have any questions about your order
  
  Cart Summary :

  [commerce-order:lite-line-orders]
  
  Email
  <a href="mailto:[commerce-order:mail]">[commerce-order:mail]</a>
  

  DELIVERY ADDRESS
[commerce-order:commerce_customer_shipping]
  
  Thank you.

  Best regards,
  The SOURIAU - SUNBANK Connection Technologies Team';
}
