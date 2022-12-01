<?php

/**
 * @file
 * A specific handler for CH.
 */

$plugin = array(
  'title' => t('Souriau add-on: Email'),
  'format callback' => 'souriau_common_format_address_email_generate',
  'type' => 'email',
  'weight' => 100,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function souriau_common_format_address_email_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {
    $format['email'] = array(
      '#title' => t('Email'),
      '#type' => 'textfield',
      '#maxlength' => 255,
      '#attributes' => array(
        'class' => array('email'),
      ),
      '#default_value' => isset($address['email']) ? $address['email'] : '',
    );
  }
  else {
    // Add our own render callback for the format view.
    $format['email'] = array(
      '#type' => 'addressfield_container',
      '#title' => t('Email', array(), array('context' => SOURIAU_COMMON_T_COMMERCE)),
      '#weight' => 10,
      '#tag' => 'div',
      '#attributes' => array('class' => array('email')),
      'email' => array(
        '#children' => check_plain($address['email']),
      ),
    );
  }
}
