<?php
/**
 * @file
 * Souriau common mail.
 */

/**
 * Implements hook_mailkeys.
 */
function souriau_common_mailkeys() {
  return [
    'training_confirmation_mail' => t('Sends confirmation on training submission', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'training_notification_mail' => t('Sends notification on training submission', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'contact_confirmation_mail' => t('Sends confirmation on contact submission', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'contact_notification_mail' => t('Sends notification on contact submission', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'training_inquiry_notification_mail' => t('Sends notification on training inquiry submission', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'website_feedback_mail' => t('Sends notification on website feedback submission', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'project_remind' => t('Sends notification on User’s project has been updated since 14 days', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];
}

/**
 * Implements hook_mail().
 */
function souriau_common_mail($key, &$message, $params) {
  $language = isset($message['language']) ? $message['language'] : NULL;
  // Implement default value.
  $message['subject'] = _souriau_common_mail_text($key . '_subject', $language, $params);
  if ($key == 'website_feedback_mail') {
    $message['body'] = t(_souriau_common_mail_website_feedback_mail_body(), $params, ['langcode' => $langcode]);
  }
  else {
    $message['body'] = _souriau_common_mail_text($key . '_body', $language, $params);
  }
}

/**
 * Implements hook_mail_edit_text().
 */
function souriau_common_mail_edit_text($key, $language) {
  $text = [];
  // Implement default value.
  $text['subject'] = _souriau_common_mail_text($key . '_subject', $language);
  $text['body'] = _souriau_common_mail_text($key . '_body', $language);
  return $text;
}

/**
 * Mail Subject for website_feedback_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_website_feedback_mail_subject() {
  return 'New website feedback';
}

/**
 * Mail body for website_feedback_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_website_feedback_mail_body() {
  return 'Hello,

  We have received the following feedback:
  Name: @name
  Email: @email
  Feedback: @feedback

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail Subject for training_confirmation_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_training_confirmation_mail_subject() {
  return 'Your webinar registration';
}

/**
 * Mail body for training_confirmation_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_training_confirmation_mail_body() {
  return 'Hello [submission:values:first_name],

Thank you for your registration to the live webinar [current-page:title].
We will see you on [resource:date:date] at [resource:date:hours]!

In the meantime feel free to browse our latest news [node:souriau_news_landing_link], check out our <a href="[site:url]/faq">FAQ</a>  or look over our products offer [node:souriau_products_landing_page].

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for training_notification_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_training_notification_mail_subject() {
  return 'New webinar registration for [current-page:title]';
}

/**
 * Mail body for training_notification_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_training_notification_mail_body() {
  return 'Hello training_manager_name,

You have received a new registration for the live webinar [current-page:title].

See below applicant’s details:
First name: [submission:values:first_name]
Last name: [submission:values:last_name]
Email address: [submission:values:email]
Phone number: [submission:values:phone_number]
Country: [submission:values:country]
ZIP code: [submission:values:postal_code]
Company: [submission:values:company]
Job position: [submission:values:job_position]

Thank you!
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for training_inquiry_notification_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_training_inquiry_notification_mail_subject() {
  return 'New training inquiry';
}

/**
 * Mail body for training_inquiry_notification_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_training_inquiry_notification_mail_body() {
  return 'You have received a training inquiry:

See below applicant’s details:
First name: [submission:values:name]
Email address: [submission:values:email_address]
Company: [submission:values:company]
Training type: [submission:values:training_type]
Comments: [submission:values:comments]

Thank you!
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for contact_confirmation_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_contact_confirmation_mail_subject() {
  return 'Thank you for your message!';
}

/**
 * Mail body for contact_confirmation_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_contact_confirmation_mail_body() {
  return 'Hello,

We have received the below message from you:

[submission:values:message]

We will contact you shortly, in the meantime feel free to browse our latest news [node:souriau_news_landing_link], check out our <a href="[site:url]/faq">FAQ</a>  or look over our products offer [node:souriau_products_landing_page].

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for contact_notification_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_contact_notification_mail_subject() {
  return 'New request from SOURIAU - SUNBANK Connection Technologies - [submission:values:first_name] [submission:values:last_name]';
}

/**
 * Mail body for contact_notification_mail mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_contact_notification_mail_body() {
  return 'Hello,

You have received a new request from the SOURIAU - SUNBANK Connection Technologies website:

Message:
 [submission:values:message]

Please find below the sender’s contact details:

First Name: [submission:values:first_name]
Last Name: [submission:values:last_name]
Email-id: [submission:values:e_mail]
Phone Number: [submission:values:phone_number]
Country: [submission:values:country]
Zip Code: [submission:values:zip_code]
Company: [submission:values:company]
Job Position: [submission:values:job_position]
Company Address: [submission:values:company_address]

Attachments:
[submission:values:attachments]

Thank you!
The SOURIAU - SUNBANK Connection Technologies Team';
}

/**
 * Mail subject for project_remind mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_project_remind_subject() {
  return 'Need help with your project?';
}

/**
 * Mail body for project_remind mail.
 *
 * @see _souriau_common_mail_text()
 */
function _souriau_common_mail_project_remind_body() {
  return 'Hello [first name],

You have recently created a project with your online account, thank you!

Need product assistance? Please contact our product support team [contact_page_link]

Need website assistance? Please contact our webmaster [contact_page_link]

Best regards,
The SOURIAU - SUNBANK Connection Technologies Team';
}
