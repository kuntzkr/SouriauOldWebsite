<?php

/**
 * @file
 * A specific handler for CH.
 */

$plugin = array(
  'title' => t('Souriau add-on: Job Position'),
  'format callback' => 'souriau_common_format_address_jobposition_generate',
  'type' => 'jobposition',
  'weight' => 100,
);

/**
 * Format callback.
 *
 * @see CALLBACK_addressfield_format_callback()
 */
function souriau_common_format_address_jobposition_generate(&$format, $address, $context = array()) {
  if ($context['mode'] == 'form') {

    $format['organisation_block']['job_position'] = array(
      '#title' => t('Job Position'),
      '#type' => 'textfield',
      '#maxlength' => 255,
      '#attributes' => array(
        'class' => array('jop-position'),
      ),
      '#default_value' => isset($address['job_position']) ? $address['job_position'] : '',
    );
  }
  else {
    // Add our own render callback for the format view.
    $format['organisation_block']['job_position'] = array(
      '#type' => 'addressfield_container',
      '#title' => t('Civility', array(), array('context' => SOURIAU_COMMON_T_COMMERCE)),
      '#weight' => 10,
      '#tag' => 'div',
      '#attributes' => array('class' => array('job-position')),
      'job_position' => array(
        '#children' => check_plain($address['job_position']),
      ),
    );
  }
}
