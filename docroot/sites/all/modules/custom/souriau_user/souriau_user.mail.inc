<?php
/**
 * @file
 * Mail hooks.
 */

/**
 * Implements hook_mailkeys().
 */
function souriau_user_mailkeys() {
  return [
    'password_changed' => t('Send Notify message for user on password change.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'approve_ect_access' => t('Send Notify message for admins on ECT request.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'request_ect_access' => t('Send info message to user on ECT request.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'approve_ect_approve' => t('Send Notify message for users on ECT request approval.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'approve_ect_deny' => t('Send Notify message for users on ECT request denial.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'ocr_screening_csr' => t('Send Notify customer service representative message on new user after registration screening.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'ocr_screening_rejected' => t('Send Notify Trade compliance manager message on non approved users after registration screening.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'ocr_user_rejected' => t('Send Notify the user message on non approved after registration screening.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'ocr_new_user_list' => t('Send Notify Trade compliance manager with the list of new users.', [], ['context' => SOURIAU_COMMON_T_USER]),
    'user_deleted' => t('Send Notify user about account deletion.', [], ['context' => SOURIAU_COMMON_T_USER]),
  ];
}

/**
 * Implements hook_mail_edit_text().
 */
function souriau_user_mail_edit_text($key, $language) {
  $text = [];
  // Implement default value.
  $text['subject'] = _souriau_common_mail_text($key . '_subject', $language);
  $text['body'] = _souriau_common_mail_text($key . '_body', $language);
  return $text;
}

/**
 * Implements hook_mail().
 */
function souriau_user_mail($key, &$message, $params) {
  $language = isset($message['language']) ? $message['language'] : NULL;
  $message['subject'] = _souriau_common_mail_text($key . '_subject', $language, $params);
  $message['body'] = _souriau_common_mail_text($key . '_body', $language, $params);

  // Add attachment when available.
  if (isset($params['attachment'])) {
    $message['params']['attachments'][] = $params['attachment'];
  }

  // Add CC when available.
  if (isset($params['cc'])) {
    $message['headers']['CC'] = $params['cc'];
  }
}

/**
 * Implements hook_form_alter().
 */
function souriau_user_form_mail_edit_template_form_alter(&$form, &$form_state, $form_id) {
  // Mail template forms.
  $forms = [
    'souriau_user_password_changed',
    'souriau_user_approve_ect_access',
    'souriau_user_approve_ect_approve',
    'souriau_user_approve_ect_deny',
    'souriau_user_request_ect_access',
  ];
  // Add commerce-order into token tree.
  if (in_array($form['id']['#value'], $forms)) {
    $form['mail']['token_tree']['#token_types'] = ['user'];
  }
}

/**
 * Mail subject for password_changed mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_password_changed_subject() {
  return 'Your password has been successfully changed';
}

/**
 * Mail body for password_changed mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_password_changed_body() {
  return 'Hello [user:field-first-name] [user:field-last-name],

Your password has been successfully changed.

Thank you!
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for password_changed mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_approve_ect_access_subject() {
  return 'New request for order status access from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for password_changed mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_approve_ect_access_body() {
  return 'Hello,

You received a new request for an order status access for:

ECT customer ID: [user:field-ect-customer-id-requested]
First name: [user:field_first_name]
Last name: [user:field_last_name]
Company: [user:field_postal_address:organisation]
Job position: [user:field_postal_address:job-position]
Email address: [user:mail]
Phone number: [user:field_postal_address:phone-number]
Mobile phone: [user:field_postal_address:mobile-number]
Country: [user:field_postal_address:country]

Please login here <a href="[site:url]user/[user:uid]/edit"></a> to validate the request.';
}

/**
 * Mail subject for request_ect_access.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_request_ect_access_subject() {
  return 'Your request for order status access from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for request_ect_access.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_request_ect_access_body() {
  return 'Hello,

Thank you for your request.
Your data have been successfully uploaded in our system.

Please allow 72 hours for your registration to become active.ai

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for approve_ect_approve.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_approve_ect_approve_subject() {
  return 'Your order status access activated from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for approve_ect_approve.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_approve_ect_approve_body() {
  return 'Hello,

We are pleased to confirm your registration to the order status section.

Through this functionality, you can review your past and current orders with SOURIAU - SUNBANK Connection Technologies | SOURIAU – SUNBANK.

Start your exploration by logging in with your email address and your password.

Login <a href="[site:login-url]">here</a>!

We look forward to providing you with reliable products and excellent customer service.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for approve_ect_deny.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_approve_ect_deny_subject() {
  return 'Your order status access from SOURIAU - SUNBANK Connection Technologies';
}

/**
 * Mail body for approve_ect_deny.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_approve_ect_deny_body() {
  return 'Hello,

Thank you for your request.
We were not able to upload your data in our system.

Please contact your customer service representative for more information.

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for ocr_screening_csr.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_screening_csr_subject() {
  return 'ECT new user alert';
}

/**
 * Mail body for ocr_screening_csr.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_screening_csr_body() {
  return 'ECT new user created after screening.';
}

/**
 * Mail subject for ocr_screening_rejected.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_screening_rejected_subject() {
  return 'ECT OCR screening user not activated';
}

/**
 * Mail body for ocr_screening_rejected.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_screening_rejected_body() {
  return 'New user not activated as a result of OCR screening.';
}

/**
 * Mail subject for ocr_user_rejected.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_user_rejected_subject() {
  return 'ECT OCR screening user account not activated';
}

/**
 * Mail body for ocr_user_rejected.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_user_rejected_body() {
  return 'Your account is not activated as a result of OCR screening.';
}

/**
 * Mail subject for ocr_new_user_list.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_new_user_list_subject() {
  return 'ECT OCR screening new user list - csv';
}

/**
 * Mail body for ocr_new_user_list.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_ocr_new_user_list_body() {
  return 'Please find the attached new users list from today.';
}

/**
 * Mail subject for user delete mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_user_deleted_subject() {
  return 'Your account has been deleted';
}

/**
 * Mail body for user delete mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_user_mail_user_deleted_body() {
  return 'Hello [user:field-first-name] [user:field-last-name],

Your esterline-connection-technologies account has been deleted.

Thank you!
The SOURIAU - SUNBANK Connection Technologies Team';
}
