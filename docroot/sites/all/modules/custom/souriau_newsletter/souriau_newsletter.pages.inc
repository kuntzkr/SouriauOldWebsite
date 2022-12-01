<?php
/**
 * @file
 * Souriau Newsletter.inc.
 */

/**
 * Newsletter Ajax form callback.
 */
function souriau_newsletter_form_callback() {
  global $user;
  $commands = [];
  $double_optin = FALSE;
  $messages_location = '.subscribe-messages';

  // Simple spam protection.
  if (!empty($_POST['field_interests'])) {
    $commands[] = ajax_command_html('#anonymous-subscriber-form', theme('souriau_newsletter_newsletter_form'));
    return ['#type' => 'ajax', '#commands' => $commands];
  }

  // Collect data.
  $data = array(
    'field_email' => !empty($_POST['field_email_field']) ? filter_xss($_POST['field_email_field']) : '',
    'groups' => !empty($_POST['groups']) ? array_filter($_POST['groups']) : [],
    'is_popup' => !empty($_POST['field_is_popup']) ? TRUE : FALSE,
  );

  // Check Email.
  if (empty($data['field_email']) || !valid_email_address($data['field_email'])) {
    $msg = t('Incorrect email', [], ['context' => SOURIAU_COMMON_T_OTHER]);
    $commands[] = souriau_common_ajax_set_message($messages_location, $msg, 'error');
    $form = theme('souriau_newsletter_newsletter_form', [
      'error' => TRUE,
      'email' => $data['field_email'],
      'error_msg' => $msg,
    ]);
    $commands[] = ajax_command_html("#anonymous-subscriber-form", $form);
    $commands[] = ctools_modal_command_dismiss();
    return ['#type' => 'ajax', '#commands' => $commands];
  }

  // Get default mail list.
  $list = souriau_newsletter_get_mailchimp_list();

  // Check if already subscribed.
  $info = mailchimp_get_memberinfo($list->id, $data['field_email']);
  if (isset($info->status) && $info->status == 'subscribed') {
    // Set message.
    if (!user_is_anonymous() && $user->mail == $data['field_email']) {
      $status = 'warning';
      $acc_edit = l(t('Edit Account', [], ['context' => SOURIAU_COMMON_T_USER]), "user/$user->uid/edit-profile");
      $msg = t('You have been already subscribed. You can manage subscription from your account edit page.', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '<br/> (' . $acc_edit . ')';
    }
    else {
      $msg = t('Email already subscribed.', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      $status = 'error';
    }
    $commands[] = souriau_common_ajax_set_message($messages_location, $msg, $status);

    // Update newsletter form.
    $form = theme('souriau_newsletter_newsletter_form', [
      'error' => TRUE,
      'email' => $data['field_email'],
      'error_msg' => $msg,
    ]);
    $commands[] = ajax_command_html('#anonymous-subscriber-form', $form);
    $commands[] = ctools_modal_command_dismiss();
    return ['#type' => 'ajax', '#commands' => $commands];
  }
  elseif (isset($info->status) && $info->status == 'unsubscribed') {
    $double_optin = TRUE;
  }

  // Check if no groups selected.
  if (empty($data['groups'])) {
    if ($data['is_popup']) {
      // Update popup form with error message.
      $popup_form = theme('souriau_newsletter_popup_groups', [
        'email' => $data['field_email'],
        'error' => t('Select please at least one preference.', [], ['context' => SOURIAU_COMMON_T_OTHER]),
        'list' => $list,
      ]);
      $commands[] = ajax_command_html("#newsletter-groups", $popup_form);
    }
    else {
      // Show popup form with groups.
      $output = theme('souriau_newsletter_popup_groups', [
        'email' => $data['field_email'],
        'error' => FALSE,
        'list' => $list,
      ]);
      $commands[] = ctools_modal_command_display('', $output);
      $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['ctools-modal-example-style']);
    }
    // Update newsletter form.
    $form = theme('souriau_newsletter_newsletter_form', [
      'email' => $data['field_email'],
    ]);
    $commands[] = ajax_command_html("#anonymous-subscriber-form", $form);
    return ['#type' => 'ajax', '#commands' => $commands];
  }

  // Add personal data.
  $user_wrapper = NULL;
  $personal_data = NULL;
  $data += souriau_newsletter_add_personal_information($user, $user_wrapper, $personal_data, $data);

  // Prepare groups for request.
  $groups = $list->intgroups;
  $grouping = souriau_newsletter_pages_prepare_groups($groups, $data['groups']);

  // Prepare request.
  $merge_vars = array(
    'EMAIL' => $data['field_email'],
    'FNAME' => $data['field_first_name'],
    'LNAME' => $data['field_last_name'],
    'CIVILITY' => $data['field_civility'],
  );

  // Send request.
  if (mailchimp_subscribe($list->id, $data['field_email'], $merge_vars, $grouping, $double_optin)) {

    // Update checkbox 'Subscribe to Newsletter'.
    if ($user->mail == $data['field_email'] && empty($user_wrapper->field_subscribe_newsletter)) {
      $user_wrapper->field_subscribe_newsletter->set(1);
      $user_wrapper->save();
    }

    // Set confirmation message.
    $msg = t('Congratulations. You have successfully subscribed', [], ['context' => SOURIAU_COMMON_T_OTHER]);
    $commands[] = souriau_common_ajax_set_message($messages_location, $msg);
    $status = theme('newsletter_congratulation');
  }
  else {
    // Set error.
    $msg = t('Something went wrong during subscribing, please try again later.', [], ['context' => SOURIAU_COMMON_T_OTHER]);
    $commands[] = souriau_common_ajax_set_message($messages_location, $msg, 'error');
    $status = theme('souriau_newsletter_newsletter_form');
  }

  $commands[] = ajax_command_html('#anonymous-subscriber-form', $status);
  $commands[] = ctools_modal_command_dismiss();
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Helper function for collect personal data.
 */
function souriau_newsletter_add_personal_information(&$user, &$user_wrapper, &$personal_data, $data) {
  if (user_is_anonymous() || $user->mail != $data['field_email']) {
    return [
      'field_civility' => '',
      'field_first_name' => 'Anonymous',
      'field_last_name' => '',
    ];
  }

  $user = user_load($user->uid);
  $user_wrapper = entity_metadata_wrapper('user', $user);
  $personal_data = $user_wrapper->field_postal_address->value();
  $civility = array(
    'mr' => t('Mr.'),
    'ms' => t('Ms.'),
  );
  return [
    'field_civility' => isset($civility[$personal_data['civility']]) ? $civility[$personal_data['civility']] : '',
    'field_first_name' => $user_wrapper->field_first_name->value(),
    'field_last_name' => $user_wrapper->field_last_name->value(),
  ];
}

/**
 * Helper function for build group array.
 *
 * @param array $groups
 *   Intgroup of mailchimp list.
 * @param array $selected
 *   Array with intrested subjects.
 *
 * @return array
 *   Array GROUPINGS for http request.
 */
function souriau_newsletter_pages_prepare_groups($groups, $selected) {
  $grouping = [];
  foreach ($groups as $key => $group) {
    foreach ($group->interests as $interest) {
      if (is_array($selected)) {
        $selected = array_filter($selected);
        if (in_array($interest->id, $selected)) {
          $grouping[$key][$interest->id] = TRUE;
          continue;
        }
        $grouping[$key][$interest->id] = 0;
      }
      elseif ($selected == $interest->id) {
        $grouping[$key][$interest->id] = TRUE;
      }
    }
  }
  return $grouping;
}
