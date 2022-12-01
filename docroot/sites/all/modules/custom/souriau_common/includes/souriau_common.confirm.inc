<?php
/**
 * @file
 * User zone functionality.
 */

/**
 * Generate confirmation modal popup.
 *
 * @param array $form_state
 *   Form_state array for form need to be confirmed.
 * @param array $confirm_options
 *   Confirmation options keys are the same as for confirm_form().
 *
 * @return array
 *   Ajax commends array.
 */
function souriau_common_confirm_callback(&$form_state, $confirm_options) {
  $excluded_forms = ['souriau_eco_line_item'];
  $form_id = $form_state['triggered_link']['form_id'];
  if (!in_array($form_id, $excluded_forms) && !empty($form_state['ajax_commands'])) {
    return ['#type' => 'ajax', '#commands' => $form_state['ajax_commands']];
  }
  ctools_include('modal');
  ctools_modal_add_js();

  $confirm_form_state = [
    'ajax' => TRUE,
    'title' => $confirm_options['question'],
    'parent_form_state' => $form_state,
    'confirm_options' => $confirm_options,
  ];
  $commands = ctools_modal_form_wrapper('souriau_common_confirm_form', $confirm_form_state);
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Modal submit callback.
 *
 * Used for call parent form submit.
 */
function souriau_common_confirm_submit_callback(&$form, &$form_state) {
  ctools_include('ajax');
  ctools_include('modal');

  $commands = [];

  if (isset($form_state['parent_form_state']['build_info']['form_id'])) {
    $form_state = $form_state['parent_form_state'];
    drupal_form_submit($form_state['parent_form_state']['build_info']['form_id'], $form_state);
  }
  elseif (isset($form_state['parent_form_state']['triggered_link']['form_id'])) {
    $parts = [
      $form_state['parent_form_state']['triggered_link']['form_id'],
      $form_state['parent_form_state']['triggered_link']['element'],
      'submit',
    ];
    $function = implode('_', $parts);
    if (is_callable($function)) {
      // Use fake form and parent form_state for proper emulation submit call.
      $fake_form = [];
      $form_state['parent_form_state']['programmed'] = TRUE;
      $function($fake_form, $form_state['parent_form_state']);
    }
  }
  if (isset($form_state['parent_form_state']['ajax_commands'])) {
    return ['#type' => 'ajax', '#commands' => $form_state['parent_form_state']['ajax_commands']];
  }

  $commands[] = ctools_modal_command_dismiss();
  $commands[] = ctools_ajax_command_reload();
  return ['#type' => 'ajax', '#commands' => $commands];
}

/**
 * Generates a form array for a confirmation form.
 */
function souriau_common_confirm_form($form, &$form_state) {
  $confirm_options = $form_state['confirm_options'];
  $confirm_options_defaults = [
    'description' => t('This action cannot be undone.'),
    'question' => t('Do you confirm this action?'),
    'no' => t('Cancel'),
    'yes' => t('Confirm'),
    'name' => 'confirm',
    'path' => '',
  ];
  $confirm_options += $confirm_options_defaults;

  // Prepare cancel link.
  if (isset($_GET['destination'])) {
    $options = drupal_parse_url(urldecode($_GET['destination']));
  }
  elseif (is_array($confirm_options['path'])) {
    $options = $confirm_options['path'];
  }
  else {
    $options = ['path' => $confirm_options['path']];
  }
  $options['external'] = TRUE;

  drupal_set_title($confirm_options['question'], PASS_THROUGH);

  $form['#attributes']['class'][] = 'confirmation';
  $form['question'] = [
    '#markup' => '<div class="popup-title"><h2 id="myModalLabel">' . $confirm_options['question'] . '</h2></div>',
  ];
  if (!empty($confirm_options['description'])) {
    $form['description'] = [
      '#markup' => '<div class="b-text">' . $confirm_options['description'] . '</div>',
    ];
  }
  $form[$confirm_options['name']] = ['#type' => 'hidden', '#value' => 1];

  $form['actions'] = [
    '#type' => 'actions',
    '#souriau_settings' => [
      'text_align' => 'center',
    ],
  ];
  $form['actions']['cancel'] = [
    '#type' => 'link',
    '#title' => $confirm_options['no'],
    '#href' => '',
    '#options' => $options,
    '#attributes' => [
      'class' => [
        'ctools-close-modal',
        'btn',
        'blue-btn',
        'btn-cancel',
      ],
    ],
  ];

  $form['actions']['submit'] = [
    '#type' => 'submit',
    '#value' => $confirm_options['yes'],
    '#souriau_settings' => [
      'hover_color' => 'orange',
    ],
    '#ajax' => [
      'callback' => 'souriau_common_confirm_submit_callback',
      'event' => 'click',
    ],
  ];

  // By default, render the form using theme_confirm_form().
  if (!isset($form['#theme'])) {
    $form['#theme'] = 'confirm_form';
  }
  return $form;
}
