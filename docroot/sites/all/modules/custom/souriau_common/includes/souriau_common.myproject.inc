<?php
/**
 * @file
 * My Project menu callbacks and ctools forms.
 */

/**
 * Project Delete AJAX callback.
 */
function souriau_common_popup_project_delete_callback($project_id, $ajax) {
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');
    $form_state = array(
      'ajax' => TRUE,
    );

    $form_state['project_id'] = $project_id;

    // Use ctools to generate ajax instructions for the browser to create
    // a form in a modal popup.
    $commands = ctools_modal_form_wrapper('souriau_common_popup_project_delete_form', $form_state);
    $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['remove-popup']);

    // If the form has been submitted, there may be additional instructions
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
      $commands = $form_state['ajax_commands'];
    }

    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($commands);
    drupal_exit();
  }
  else {
    return drupal_get_form('souriau_common_popup_project_delete_form');
  }
}

/**
 * Confirmation form for project delete.
 */
function souriau_common_popup_project_delete_form($form, $form_state) {
  $form = [];
  $form['content_title'] = [
    '#markup' => t('Delete my project', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#prefix' => '<div class="popup-title"><h2 id="modal-title" class="modal-title">',
    '#suffix' => '</h2></div>',
  ];

  $form['content_text'] = [
    '#markup' => t("You’re about to delete your project. Would you continue?", [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#prefix' => '<div class="b-text"><p>',
    '#suffix' => '</p></div>',
  ];

  $form['actions'] = [
    '#prefix' => '<div class="w-btn wide-btns">',
    '#suffix' => '</div>',
  ];

  $form['actions']['cancel'] = [
    '#type' => 'submit',
    '#value' => t('CANCEL'),
    '#attributes' => ['class' => ['blue-btn', 'btn-cancel']],
    '#submit' => ['souriau_common_popup_project_delete_form_cancel'],
  ];

  $form['actions']['confirm'] = [
    '#type' => 'submit',
    '#value' => t('CONFIRM'),
    '#attributes' => ['class' => ['orange-btn-hover']],
    '#submit' => ['souriau_common_popup_project_delete_form_confirm'],
    '#prefix' => '<div class="w-btn-stretch">',
    '#suffix' => '</div>',
  ];

  return $form;
}

/**
 * Callback form for project delete confirm button.
 */
function souriau_common_popup_project_delete_form_confirm($form, &$form_state) {
  // Delete entity and redirect to my projects.
  entity_delete('project', $form_state['project_id']);
  global $user;
  $redirect_url = format_string('user/@user/projects', ['@user' => $user->uid]);
  $form_state['ajax_commands'][] = ctools_ajax_command_redirect($redirect_url);
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  $form_state['ajax_commands'][] = souriau_common_ajax_set_message('.pane-page-content', t('Project is deleted', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));
}

/**
 * Callback form for project delete cancel button.
 */
function souriau_common_popup_project_delete_form_cancel($form, &$form_state) {
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
}

/**
 * Project Delete AJAX callback.
 */
function souriau_common_popup_project_item_delete_callback($project_id, $item_id, $ajax) {
  if ($ajax) {
    ctools_include('ajax');
    ctools_include('modal');
    $form_state = array(
      'ajax' => TRUE,
    );

    $form_state['project_id'] = $project_id;
    $form_state['item_id'] = $item_id;

    // Use ctools to generate ajax instructions for the browser to create
    // a form in a modal popup.
    $commands = ctools_modal_form_wrapper('souriau_common_popup_item_delete_form', $form_state);
    $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['remove-popup']);

    // If the form has been submitted, there may be additional instructions
    // such as dismissing the modal popup.
    if (!empty($form_state['ajax_commands'])) {
      $commands = $form_state['ajax_commands'];
    }

    // Return the ajax instructions to the browser via ajax_render().
    print ajax_render($commands);
    drupal_exit();
  }
  else {
    return drupal_get_form('souriau_common_popup_item_delete_form');
  }
}

/**
 * Confirmation form for project delete.
 */
function souriau_common_popup_item_delete_form($form, $form_state) {
  $form = [];

  $form['content_title'] = [
    '#markup' => t('Remove this part number from my project', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#prefix' => '<div class="popup-title"><h2 id="modal-title" class="modal-title">',
    '#suffix' => '</h2></div>',
  ];

  $form['content_text'] = [
    '#markup' => t("You’re about to remove this part number from your project. Would you continue?", [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#prefix' => '<div class="b-text"><p>',
    '#suffix' => '</p></div>',
  ];

  $form['actions'] = [
    '#prefix' => '<div class="w-btn wide-btns">',
    '#suffix' => '</div>',
  ];

  $form['actions']['cancel'] = [
    '#type' => 'submit',
    '#value' => t('CANCEL', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#attributes' => ['class' => ['blue-btn', 'btn-cancel']],
    '#submit' => ['souriau_common_popup_project_delete_form_cancel'],
  ];

  $form['actions']['confirm'] = [
    '#type' => 'submit',
    '#value' => t('CONFIRM', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#attributes' => ['class' => ['orange-btn-hover']],
    '#submit' => ['souriau_common_popup_item_delete_form_confirm'],
    '#prefix' => '<div class="w-btn-stretch">',
    '#suffix' => '</div>',
  ];

  return $form;
}

/**
 * Callback form for project delete confirm button.
 */
function souriau_common_popup_item_delete_form_confirm($form, &$form_state) {
  // Delete entity and redirect to my projects.
  $project_id = $form_state['project_id'];
  $item_id = $form_state['item_id'];
  $project = entity_load_single('project', $project_id);
  unset($project->field_part_numbers[LANGUAGE_NONE][$item_id]);
  $project->field_part_numbers[LANGUAGE_NONE] = array_values($project->field_part_numbers[LANGUAGE_NONE]);
  entity_save('project', $project);
  global $user;
  $redirect_url = format_string(
    'user/@user/projects/@pid',
    [
      '@user' => $user->uid,
      '@pid' => $form_state['project_id'],
    ]
  );
  $form_state['ajax_commands'][] = ctools_ajax_command_redirect($redirect_url);
  $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  $form_state['ajax_commands'][] = souriau_common_ajax_set_message('.pane-page-content', t('Part number is removed', [], ['context' => SOURIAU_COMMON_T_COMMERCE]));
}

/**
 * Callback for project edit page.
 */
function souriau_common_project_inline_edit_callback($project_id) {
  $ret = $commands = [];
  $messages_location = '.pane-page-content';
  try {
    $projects = entity_load_single('project', $project_id);
    $projects_wrapper = entity_metadata_wrapper('project', $projects);
    if ($_POST['type'] == 'prj-title-edit') {
      if (strlen($_POST['value']) > 255) {
        $commands[] = souriau_common_ajax_set_message($messages_location, t('The text entered exceeds the maximum length', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'error');
        $ret = [
          '#type' => 'ajax',
          '#commands' => $commands,
        ];
        return $ret;
      }
      else {
        $projects_wrapper->field_project_title = $_POST['value'];
      }
    }
    elseif ($_POST['type'] == 'prj-desc-edit') {
      $projects_wrapper->field_project_description = $_POST['value'];
    }
    elseif ($_POST['type'] == 'prj-partno-notes') {
      foreach ($projects_wrapper->field_part_numbers as $item_id => $partnumber) {
        if ($item_id == $_POST['partno']) {
          $partnumber->field_notes->set($_POST['value']);
          $partnumber->save();
        }
      }
    }
    entity_save('project', $projects);
  }
  catch (Exception $e) {
    watchdog('project inline edit', 'Exception: !exception in editing project info.', array(
      '!exception' => $e->getMessage(),
    ), WATCHDOG_ERROR);
    $commands[] = souriau_common_ajax_set_message($messages_location, t('Unfortunately Project updates weren\'t saved. Please try again later.', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'error');
  }
  $ret = [
    '#type' => 'ajax',
    '#commands' => $commands,
  ];
  return $ret;
}

/**
 * Call back for project create form.
 */
function souirau_common_project_popup_callback($ajax = NULL, $part_number = NULL) {
  if ($ajax !== 'ajax') {
    return drupal_get_form('souriau_common_project_form');
  }

  ctools_include('ajax');
  ctools_include('modal');

  $form_state = array(
    'ajax' => TRUE,
    'part_number' => $part_number,
  );

  // Use ctools to generate ajax instructions for the browser to create
  // a form in a modal popup.
  $commands = ctools_modal_form_wrapper('souriau_common_project_form', $form_state);
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['projects-popup']);

  // If the form has been submitted, there may be additional instructions
  // such as dismissing the modal popup.
  if (!empty($form_state['ajax_commands'])) {
    $commands = $form_state['ajax_commands'];
  }

  // Return the ajax instructions to the browser via ajax_render().
  print ajax_render($commands);
  drupal_exit();
}

/**
 * Project add form builder.
 */
function souriau_common_project_form($form, $form_state) {
  global $user;

  if (!isset($form_state['ajax'])) {
    $projects_link = l('<span aria-hidden="true" class="glyphicon glyphicon-menu-left"></span> '
      . t('BACK TO MY PROJECTS', [], ['context' => SOURIAU_COMMON_T_USER]),
      'user/' . $user->uid . '/projects',
      ['attributes' => ['class' => ['btn-back']], 'html' => TRUE]);

    $form['back_to_project'] = [
      '#markup' => '<div class="b-back-link">
      <div class="container">'
      . $projects_link .
      '</div>
      </div>',
    ];

    $form['wrapper_top'] = [
      '#markup' => '<div class="b-projects">
      <div class="container">
      <div class="b-add-project">',
    ];
  }

  $form['project_title'] = [
    '#markup' => '<div class="popup-title"><h2 id="modal-title" class="modal-title">'
    . t('Create a new project', [], ['context' => SOURIAU_COMMON_T_USER]) .
    '</h2></div>',
  ];

  $form['project_name'] = [
    '#type' => 'textfield',
    '#title' => t('Project name', [], ['context' => SOURIAU_COMMON_T_USER]),
    '#required' => TRUE,
  ];

  $form['project_description'] = [
    '#type' => 'textarea',
    '#attributes' => ['class' => ['form-area']],
    '#title' => t('Project description', [], ['context' => SOURIAU_COMMON_T_USER]),
    '#resizable' => FALSE,
    '#required' => TRUE,
  ];

  $form['cancel'] = [
    '#type' => 'submit',
    '#prefix' => '<div class="form-block form-actions wide-btns">',
    '#attributes' => [
      'class' => ['btn', 'blue-btn', 'btn-cancel'],
      'data-dismiss' => 'modal',
    ],
    '#value' => t('CANCEL', [], ['context' => SOURIAU_COMMON_T_USER]),
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#name' => 'submit',
    '#prefix' => '<div class="w-btn-stretch">',
    '#suffix' => '</div></div>',
    '#attributes' => [
      'class' => ['btn', 'orange-btn-hover', 'gtm_element'],
      'data-gtm-category' => 'Button',
      'data-gtm-action' => 'Create-project',
      'data-gtm-label' => drupal_get_title(),
    ],
    '#value' => t('CONFIRM', [], ['context' => SOURIAU_COMMON_T_USER]),
    '#submit' => ['souriau_common_project_form_submit'],
  ];

  if (!isset($form_state['ajax'])) {
    $form['cancel']['#submit'] = ['souriau_common_project_form_cancel'];
    $form['cancel']['#limit_validation_errors'] = [];
    $form['wrapper_bottom'] = [
      '#markup' => '</div></div></div>',
    ];
  }
  else {
    $form['cancel']['#attributes']['class'] = [
      'btn',
      'blue-btn',
      'btn-cancel',
      'ctools-close-modal',
    ];
  }

  return $form;
}

/**
 * Project add form submit handler.
 */
function souriau_common_project_form_submit(&$form, &$form_state) {
  global $user;
  $values = $form_state['values'];
  // Create an Entity.
  $project = entity_create('project', array('type' => 'project'));

  // Specify the author.
  $project->uid = $user->uid;

  $redirect_url = "user/$user->uid/projects";

  // Create a Entity Wrapper of that new Entity.
  $entity = entity_metadata_wrapper('project', $project);
  $entity->field_project_title = $values['project_name'];
  $entity->field_project_description = $values['project_description'];
  $entity->save();

  if (!empty($form_state['part_number'])) {
    $paragraph = new ParagraphsItemEntity(['field_name' => 'field_part_numbers', 'bundle' => 'project_item']);
    $paragraph->is_new = TRUE;
    $paragraph->setHostEntity('project', $project);
    $paragraph->save();

    $entity_paragraph = entity_metadata_wrapper('paragraphs_item', $paragraph);
    $entity_paragraph->field_part_number = $form_state['part_number'];
    $entity_paragraph->save();
  }
  else {
    $form_state['ajax_commands'][] = ctools_ajax_command_redirect($redirect_url);
  }

  // If not ajax, then redirect user to project page.
  if (!isset($form_state['ajax'])) {
    $form_state['redirect'] = $redirect_url;
  }
  else {
    // Tell the browser to close the modal.
    $form_state['ajax_commands'][] = ctools_modal_command_dismiss();
  }
}

/**
 * Project add form cancel handler.
 */
function souriau_common_project_form_cancel(&$form, &$form_state) {
  global $user;
  $form_state['redirect'] = "user/$user->uid/projects";
}

/**
 * Callback for add to project form.
 */
function souriau_common_popup_add_to_project_callback($part_number, $ajax) {
  if (!$ajax) {
    return drupal_get_form('souriau_common_add_to_project_form');
  }

  ctools_include('ajax');
  ctools_include('modal');

  $form_state = [
    'ajax' => TRUE,
    'part_number' => $part_number,
  ];

  // Use ctools to generate ajax instructions for the browser to create
  // a form in a modal popup.
  $commands = ctools_modal_form_wrapper('souriau_common_add_to_project_form', $form_state);
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['add-to-project-popup']);

  // If the form has been submitted, there may be additional instructions
  // such as dismissing the modal popup.
  if (!empty($form_state['ajax_commands'])) {
    $commands = $form_state['ajax_commands'];
  }

  // Return the ajax instructions to the browser via ajax_render().
  print ajax_render($commands);
  drupal_exit();
}

/**
 * Add to project widget form.
 */
function souriau_common_add_to_project_form($form, $form_state) {
  $part_number = $form_state['part_number'];
  $form = [];
  $form['add_to'] = [
    '#markup' => '<legend>' . t('ADD TO', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</legend>',
  ];

  $user_projects = _souriau_common_get_projects();
  $selected_projects = _souriau_common_get_projects($part_number);

  if (!empty($user_projects)) {
    $form['projects'] = [
      '#type' => 'checkboxes',
      '#options' => _souriau_common_get_projects(),
      '#default_value' => array_keys($selected_projects),
      '#ajax' => array(
        'callback' => 'souriau_common_options_callback',
      ),
    ];
  }
  else {
    $form['projects'] = [
      '#markup' => t('No project available', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    ];
  }

  $form['create_project'] = [
    '#prefix' => '<div class="w-btn text-center">',
    '#suffix' => '</div>',
  ];

  $form['create_project']['link'] = [
    '#type' => 'link',
    '#title' => t('CREATE PROJECT', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    '#href' => url('souriau/ajax/project/create/ajax/' . $part_number, array('absolute' => TRUE)),
    '#options' => [
      'attributes' => [
        'class' => [
          'btn',
          'orange-btn-hover',
          'ctools-use-modal',
          'ctools-modal-souriau-modal-style',
        ],
      ],
    ],
  ];

  return $form;
}

/**
 * Callback for option selection on Add to Project widget.
 */
function souriau_common_options_callback($form, $form_state) {
  $user_projects = _souriau_common_get_projects($form_state['part_number']);
  $user_projects_ids = array_keys($user_projects);
  $new_selected = $form_state['values']['projects'];
  $options_diff = array_diff($new_selected, $user_projects_ids);

  foreach ($options_diff as $key => $project_id) {
    if ($project_id !== 0) {
      $project = entity_load_single('project', $project_id);
      // Add the PartNumber to the project.
      souriau_common_myprojects_add_partnumber($project, $form_state['part_number']);
    }
    else {
      $project = entity_load_single('project', $key);
      // Remove the PartNumber from the project.
      souriau_common_myprojects_remove_partnumber($project, $form_state['part_number']);
    }
  }
}

/**
 * Remove PartNumber from given $project.
 *
 * @param object $project
 *   Project entity.
 * @param int $part_number_nid
 *   NID of PartNumber node.
 */
function souriau_common_myprojects_remove_partnumber($project, $part_number_nid) {
  try {
    if (empty($project->field_part_numbers)) {
      // Nothing to do here.
      return;
    }

    $project_wrapper = entity_metadata_wrapper('project', $project);
    foreach ($project_wrapper->field_part_numbers as $delta => $item) {
      if (empty($item) || empty($item->field_part_number->value())) {
        continue;
      }
      if ($item->field_part_number->value()->nid == $part_number_nid) {
        unset($project_wrapper->field_part_numbers[$delta]);
        break;
      }
    }
    $project_wrapper->save();
  }
  catch (Exception $e) {
    watchdog('souria_common', 'My projects Exception !e', ['!e' => $e->getMessage()], WATCHDOG_WARNING);
  }
}

/**
 * Add PartNumber to given $project.
 *
 * @param object $project
 *   Project entity.
 * @param int $part_number_nid
 *   NID of PartNumber node.
 */
function souriau_common_myprojects_add_partnumber($project, $part_number_nid) {
  try {
    if (empty($project)) {
      // Nothing to do here.
      return;
    }
    $paragraph = new ParagraphsItemEntity([
      'field_name' => 'field_part_numbers',
      'bundle' => 'project_item',
    ]);
    $paragraph->is_new = TRUE;
    $paragraph->setHostEntity('project', $project);
    $paragraph->save();

    $entity_paragraph = entity_metadata_wrapper('paragraphs_item', $paragraph);
    $entity_paragraph->field_part_number = $part_number_nid;
    $entity_paragraph->save();
  }
  catch (Exception $e) {
    watchdog('souria_common', 'My projects Exception !e', ['!e' => $e->getMessage()], WATCHDOG_WARNING);
  }
}

/**
 * Custom function to return project and project ID.
 */
function _souriau_common_get_projects($part_number = NULL) {
  global $user;
  $view_data = views_get_view_result('souriau_query_user_project_list', 'default', $user->uid, $part_number);
  $projects = [];
  foreach ($view_data as $row) {
    $projects[$row->id] = $row->field_data_field_project_title_field_project_title_value;
  }
  return $projects;
}
