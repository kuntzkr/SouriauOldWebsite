<?php

/**
 * @file
 * Draft Moderation forms.
 */

/**
 * Implements hook_form_alter().
 *
 * Alters node_type_form.
 */
function draft_moderation_form_node_type_form_alter(&$form, $form_state) {
  if (isset($form['type'])) {
    // Node type edit form.
    $form['workflow']['draft_moderation'] = array(
      '#type' => 'item',
      '#title' => t('Moderation options', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
    );
    $form['workflow']['draft_moderation']['draft_moderation_node'] = array(
      '#type' => 'radios',
      '#title' => t('Draft moderation', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
      '#default_value' => draft_moderation_supported_type($form['#node_type']->type),
      '#options' => array(
        DRAFT_MODERATION_DISABLED => t('Disabled', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
        DRAFT_MODERATION_ENABLED  => t('Enabled', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
        DRAFT_MODERATION_WORKFLOW => t('Enabled with workflow', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
      ),
    );
    // Register on callback to configure node_type.
    $form['#submit'][] = 'draft_moderation_node_type_submit';
  }
}

/**
 * Callback for `node_type_form`.
 *
 * Adds special fields to the CT.
 */
function draft_moderation_node_type_submit($form, &$form_state) {
  $entity_type = 'node';
  $node_type = $form['#node_type'];
  $bundle_name = !empty($node_type->type) ? $node_type->type : $form_state['values']['type'];

  if (in_array($form_state['values']['draft_moderation_node'], array(DRAFT_MODERATION_ENABLED, DRAFT_MODERATION_WORKFLOW))) {
    // DRAFT_MODERATION_FIELD_REF.
    // Check if our field is not already created.
    if (!field_info_field(DRAFT_MODERATION_FIELD_REF)) {
      $field = array(
        'field_name' => DRAFT_MODERATION_FIELD_REF,
        'type' => 'entityreference',

        'active' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'entity_types' => array(),
        'foreign keys' => array(
          'node' => array(
            'columns' => array(
              'target_id' => 'nid',
            ),
            'table' => 'node',
          ),
        ),
        'indexes' => array(
          'target_id' => array(
            0 => 'target_id',
          ),
        ),
        'locked' => '0',
        'module' => 'entityreference',
        'settings' => array(
          'entity_translation_sync' => FALSE,
          'handler' => 'base',
          'handler_settings' => array(
            'behaviors' => array(
              'views-select-list' => array(
                'status' => 0,
              ),
            ),
            'sort' => array(
              'type' => 'none',
            ),
            'target_bundles' => array(),
          ),
          'target_type' => 'node',
        ),
        'translatable' => '0',
      );
      field_create_field($field);
    }
    if (!field_info_instance($entity_type, DRAFT_MODERATION_FIELD_REF, $bundle_name)) {
      // Create the instance on the bundle.
      $instance = array(
        'field_name' => DRAFT_MODERATION_FIELD_REF,
        'entity_type' => $entity_type,
        'label' => 'Edition',
        'description' => '',
        'bundle' => $bundle_name,
        'deleted' => '0',
        // If you don't set the "required"
        // property then the field wont be required by default.
        'required' => 0,
        'settings' => array(
          'entity_translation_sync' => FALSE,
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'entityreference',
          'settings' => array(
            'match_operator' => 'CONTAINS',
            'path' => '',
            'references_dialog_add' => 0,
            'references_dialog_edit' => 0,
            'references_dialog_edit_translation' => 0,
            'references_dialog_search' => 0,
            'references_dialog_search_view' => '',
            'size' => '60',
          ),
          'type' => 'entityreference_autocomplete',
          'weight' => '34',
        ),
      );
      field_create_instance($instance);
    }

    // DRAFT_MODERATION_FIELD_FLAG.
    // Check if our field is not already created.
    if (!field_info_field(DRAFT_MODERATION_FIELD_FLAG)) {
      $field = array(
        'field_name' => DRAFT_MODERATION_FIELD_FLAG,
        'type' => 'list_boolean',

        'active' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'entity_types' => array(),
        'foreign keys' => array(),
        'indexes' => array(
          'value' => array(
            0 => 'value',
          ),
        ),
        'locked' => '0',
        'module' => 'list',
        'settings' => array(
          'allowed_values' => array(
            0 => '0',
            1 => '1',
          ),
          'allowed_values_function' => '',
          'entity_translation_sync' => FALSE,
        ),
        'translatable' => '0',
      );
      field_create_field($field);
    }
    if (!field_info_instance($entity_type, DRAFT_MODERATION_FIELD_FLAG, $bundle_name)) {
      // Create the instance on the bundle.
      $instance = array(
        'field_name' => DRAFT_MODERATION_FIELD_FLAG,
        'entity_type' => $entity_type,
        'label' => 'Draft',
        'bundle' => $bundle_name,
        'deleted' => '0',
        // If you don't set the "required"
        // property then the field wont be required by default.
        'required' => FALSE,
        'settings' => array(
          'entity_translation_sync' => FALSE,
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'options',
          'settings' => array(
            'display_label' => 1,
          ),
          'type' => 'options_onoff',
          'weight' => '35',
        ),
        'default_value' => array(
          0 => array(
            'value' => 0,
          ),
        ),
      );
      field_create_instance($instance);
    }

    // DRAFT_MODERATION_FIELD_MODIFICATION_TYPE.
    // Check if our field is not already created.
    if (!field_info_field(DRAFT_MODERATION_FIELD_MODIFICATION_TYPE)) {
      $field = array(
        'field_name' => DRAFT_MODERATION_FIELD_MODIFICATION_TYPE,
        'type' => 'list_text',
        'active' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'entity_types' => array(),
        'foreign keys' => array(),
        'indexes' => array(
          'value' => array(
            0 => 'value',
          ),
        ),
        'locked' => '0',
        'module' => 'list',
        'settings' => array(
          'allowed_values' => array(
            'graphic' => 'Graphic changes',
            'content' => 'Content changes',
            'both' => 'Both content and graphic changes',
          ),
          'allowed_values_function' => '',
          'entity_translation_sync' => FALSE,
        ),
        'translatable' => '0',
      );
      field_create_field($field);
    }
    if (!field_info_instance($entity_type, DRAFT_MODERATION_FIELD_MODIFICATION_TYPE, $bundle_name)) {
      // Create the instance on the bundle.
      $instance = array(
        'field_name' => DRAFT_MODERATION_FIELD_MODIFICATION_TYPE,
        'entity_type' => $entity_type,
        'label' => 'Modification Type',
        'bundle' => $bundle_name,
        'deleted' => '0',
        // If you don't set the "required"
        // property then the field wont be required by default.
        'required' => TRUE,
        'settings' => array(
          'entity_translation_sync' => FALSE,
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'options',
          'settings' => array(),
          'type' => 'options_select',
          'weight' => '35',
        ),
        'default_value' => NULL,
      );
      field_create_instance($instance);
    }

    // Check if our field is not already created.
    if (!field_info_field(DRAFT_MODERATION_FIELD_LOG)) {
      $field = array(
        'field_name' => DRAFT_MODERATION_FIELD_LOG,
        'type' => 'text_long',

        'active' => '1',
        'cardinality' => '1',
        'deleted' => '0',
        'entity_types' => array(),
        'foreign keys' => array(
          'format' => array(
            'columns' => array(
              'format' => 'format',
            ),
            'table' => 'filter_format',
          ),
        ),
        'indexes' => array(
          'format' => array(
            0 => 'format',
          ),
        ),
        'locked' => '0',
        'module' => 'text',
        'settings' => array(
          'entity_translation_sync' => FALSE,
        ),
        'translatable' => '1',
      );
      field_create_field($field);
    }
    if (!field_info_instance($entity_type, DRAFT_MODERATION_FIELD_LOG, $bundle_name)) {
      // Create the instance on the bundle.
      $instance = array(
        'field_name' => DRAFT_MODERATION_FIELD_LOG,
        'entity_type' => $entity_type,
        'label' => 'Log',
        'bundle' => $bundle_name,
        'deleted' => '0',
        // If you don't set the "required"
        // property then the field wont be required by default.
        'required' => 0,
        'settings' => array(
          'entity_translation_sync' => FALSE,
          'text_processing' => '0',
          'user_register_form' => FALSE,
        ),
        'widget' => array(
          'active' => 1,
          'module' => 'text',
          'settings' => array(
            'rows' => '5',
          ),
          'type' => 'text_textarea',
          'weight' => '36',
        ),
      );
      field_create_instance($instance);
    }
  }
}

/**
 * Implements hook_form_alter().
 */
function draft_moderation_form_alter(&$form, &$form_state, $form_id) {
  // Ignore all forms except node editing forms.
  if (!isset($form['#node']) || !isset($form['#node']->type) || !($form['#node']->type . '_node_form' == $form_id)) {
    return;
  }

  $node = $form['#node'];
  $moderation_mode = draft_moderation_supported_type($node->type);

  // Ignore all CT with disabled draft_moderation mode.
  if (empty($moderation_mode)) {
    return;
  }

  $form_state['values']['translation'] = array(
    'status' => FALSE,
    'translate' => 0,
  );

  if ($moderation_mode == DRAFT_MODERATION_WORKFLOW) {
    if (isset($form['translation'])) {
      $form['translation']['workflow'] = array(
        '#type' => 'radios',
        '#default_value' => isset($form['translation']['workflow']) ? $form['translation']['workflow']['#default_value'] : DRAFT_MODERATION_WORKFLOW_IN_PROGRESS,
        '#options' => _draft_moderation_workflow_states(),
        '#title' => t('Translation workflow status', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
        '#tree' => TRUE,
      );
    }
    // Set default WORKFLOW STATUS for new content.
    if (empty($node->nid)) {
      if (draft_moderation_user_has_publish_access($moderation_mode, $workflow = 0, $node->type)) {
        // Default Workflow state for new content
        // created by users with "Publish access".
        $form['translation']['workflow']['#value'] = DRAFT_MODERATION_WORKFLOW_VALIDATED;
      }
      else {
        // Default Workflow state for new content
        // created by users with NO "Publish access".
        $form['translation']['workflow']['#value'] = DRAFT_MODERATION_WORKFLOW_IN_PROGRESS;
      }
    }
  }

  if (user_access('edit production editions')) {
    // Normally, this permission should be disabled for evreyone.
    $form[DRAFT_MODERATION_FIELD_REF]['#disabled']  = TRUE;
    $form[DRAFT_MODERATION_FIELD_FLAG]['#disabled'] = TRUE;
  }
  else {
    $form[DRAFT_MODERATION_FIELD_REF]['#access']  = FALSE;
    $form[DRAFT_MODERATION_FIELD_FLAG]['#access'] = FALSE;

    if (isset($form['translation'])) {
      $form['translation']['translate'] = array(
        '#type' => 'value',
        '#value' => 0,
      );
      // @TODO: Check if this required.
      if ($moderation_mode == DRAFT_MODERATION_WORKFLOW && !user_access('bypass workflow states') && !user_access('moderate translations')) {
        $form['translation']['workflow']['#value'] = DRAFT_MODERATION_WORKFLOW_IN_PROGRESS;
      }
    }

    // Hide system elements.
    $form['translation']['#access'] = FALSE;
    $form['options']['#access'] = FALSE;
    $form['revision_information']['#access'] = FALSE;
    $form['author']['#access'] = FALSE;
    $form['actions']['submit']['#weight'] = 1;
    unset($form['actions']['delete_translation']);
  }

  $form['actions']['submit']['#weight'] = 1;

  // Remove unused actions.
  unset($form['actions']['preview_changes']);

  // Allow to Create and Publish Node.
  // Check if user has access to Publish/Unpublish the Draft.
  $label = t('Save and publish', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
  $publish_access = draft_moderation_user_has_publish_access($moderation_mode, $workflow = DRAFT_MODERATION_WORKFLOW_IN_PROGRESS, $node->type);
  if (empty($node->nid) && !empty($publish_access) && $form['actions']['submit']['#access']) {
    $form['actions']['save_and_publish'] = array(
      '#type' => 'submit',
      '#value' => $label,
      '#weight' => 10,
      '#submit' => array('draft_moderation_create_and_publish_submit'),
    );
  }

  // Check if this is Draft node.
  if (empty($node->is_draft)) {
    // If it's not draft then
    // there is nothing else to do here.
    return;
  }

  // // Add a 'View changes' button on the node edit form.
  // if (variable_get('diff_show_preview_changes_node_' . $node->type, TRUE) && !empty($node->nid)) {
  // $form['actions']['preview_changes'] = array(
  // '#type' => 'submit',
  // #value' => t('View changes', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
  // '#weight' => 12,
  // '#submit' => array('draft_moderation_translations_compare'),
  // );
  // }.

  // Apply Moderation form elements.
  _draft_moderation_form_alter($form);
}

/**
 * Helper form builder function for moderation workflow.
 *
 * Apllies moderation form elements.
 *
 * @see draft_moderation_form_alter()
 */
function _draft_moderation_form_alter(&$form) {
  $node = $form['#node'];
  $form['actions']['submit']['#submit'][] = 'draft_moderation_save_submit';

  $moderation_mode = draft_moderation_supported_type($node->type);

  $published_node = node_load($node->edition_id);
  $pub_handler = entity_translation_get_handler('node', $published_node);
  $pub_translations = $pub_handler->getTranslations();

  $handler = entity_translation_get_handler('node', $node);
  $form_langcode = $handler->getFormLanguage();
  $translations = $handler->getTranslations();
  $translation = NULL;
  $workflow = 0;

  if (isset($translations->data[$form_langcode])) {
    $translation = $translations->data[$form_langcode];
    $workflow = $translation['workflow'];

    if ($moderation_mode == DRAFT_MODERATION_WORKFLOW && isset($form['translation'])) {
      $form['translation']['workflow']['#default_value'] = $workflow;
    }
  }

  $label = t('Save and publish', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));

  // Check if user has access to Publish/Unpublish the Draft.
  $publish_access = draft_moderation_user_has_publish_access($moderation_mode, $workflow, $node->type);
  if (!empty($publish_access)) {
    $form['actions']['save_and_publish'] = array(
      '#type' => 'submit',
      '#value' => $label,
      '#weight' => 10,
      '#submit' => array('draft_moderation_save_and_publish_submit'),
    );
    $label = '';
    if ($form_langcode != $translations->original && (!isset($pub_translations->data[$form_langcode]) || $pub_translations->data[$form_langcode]['status'])) {
      $label = t('Unpublish translation', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
    }
    elseif (user_access('unpublish production editions') && $published_node->status) {
      $label = t('Unpublish', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
    }
    if ($label) {
      $form['actions']['unpublish_t10n'] = array(
        '#type' => 'submit',
        '#value' => $label,
        '#weight' => 11,
        '#submit' => array('draft_moderation_unpublish_submit'),
      );
      $form['actions']['save_and_unpublish']['#access'] = FALSE;
    }
  }

  // Dissallow Log message for non-translated.
  if (isset($form[DRAFT_MODERATION_FIELD_LOG])) {
    $form[DRAFT_MODERATION_FIELD_LOG]['#access'] = FALSE;
  }

  if ($translation && $moderation_mode == DRAFT_MODERATION_WORKFLOW) {
    if (isset($form[DRAFT_MODERATION_FIELD_LOG])) {
      $form[DRAFT_MODERATION_FIELD_LOG]['#access'] = TRUE;
    }

    if ($workflow != DRAFT_MODERATION_WORKFLOW_TO_VALIDATE || user_access('bypass workflow states')) {
      $form['actions']['save_and_send'] = array(
        '#type' => 'submit',
        '#value' => t('Save for moderation', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
        '#weight' => 4,
        '#submit' => array('draft_moderation_save_and_send'),
      );
    }
    if ((user_access('save node for tc moderation') && $workflow != DRAFT_MODERATION_WORKFLOW_TO_VALIDATE_TC) || user_access('bypass workflow states')) {
      $form['actions']['save_and_send_to_tc'] = array(
        '#type' => 'submit',
        '#value' => t('Save for TC moderation', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
        '#weight' => 4,
        '#submit' => array('draft_moderation_save_and_send_to_tc_submit'),
      );
    }
    if ((user_access('moderate translations') && $workflow == DRAFT_MODERATION_WORKFLOW_TO_VALIDATE)
        || user_access('bypass workflow states')) {

      if ($workflow != DRAFT_MODERATION_WORKFLOW_VALIDATED) {
        $form['actions']['save_approve'] = array(
          '#type' => 'submit',
          '#value' => t('Save and approve', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
          '#weight' => 6,
          '#submit' => array('draft_moderation_approve_submit'),
        );
      }
      if ($workflow != DRAFT_MODERATION_WORKFLOW_REFUSED) {
        $form['actions']['save_refuse'] = array(
          '#type' => 'submit',
          '#value' => t('Save and refuse', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
          '#weight' => 8,
          '#submit' => array('draft_moderation_refuse_submit'),
        );
      }
      if (isset($form[DRAFT_MODERATION_FIELD_LOG])) {
        unset($form[DRAFT_MODERATION_FIELD_LOG]['#disabled']);
        $form[DRAFT_MODERATION_FIELD_LOG]['#access'] = TRUE;
      }
    }
  }

  // Update Translation from Original.
  if ($form_langcode != $translations->original) {
    $form['actions']['copy_original'] = array(
      '#type' => 'submit',
      '#value' => t('Copy original translation', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
      '#weight' => 12,
      '#submit' => array('draft_moderation_node_form_copy_original_submit'),
      '#limit_validation_errors' => array(),
    );
  }
}

/**
 * Node form submit callback for "Save" btn.
 *
 * Does a little: stay on the same page.
 */
function draft_moderation_save_submit($form, &$form_state) {
  $node = $form['#node'];
  if ($node->created != REQUEST_TIME) {
    $handler = entity_translation_get_handler($entity_type = 'node', $node, TRUE);
    if (!empty($handler)) {
      $langcode = $handler->getFormLanguage();
      $translations = $handler->getTranslations();
      if (empty($translations->data[$langcode])) {
        // It was a request to create translation.
        // Nothing to do here.
        return;
      }
    }

    // Stay on the same page.
    // unset($form_state['redirect']).
  }
}

/**
 * Node form submit callback for "to PUBLISHED".
 *
 * Copies the submitted translation into published edition.
 */
function draft_moderation_save_and_publish_submit($form, &$form_state) {
  $bundle = $form['#node']->type;
  $moderation_mode = draft_moderation_supported_type($bundle);

  if (user_access('bypass workflow states') ||
    ($moderation_mode && (user_access('publish to production edition') || user_access("publish {$bundle} to production edition")))) {

    $langcode = $form_state['entity_translation']['form_langcode'];
    $form_state['values']['status'] = 1;
    $form_state['values']['translation']['status'] = 1;
    $form_state['values']['translation']['translate'] = 0;
    $form_state['values']['translation']['workflow'] = DRAFT_MODERATION_WORKFLOW_VALIDATED;

    node_form_submit($form, $form_state);
    $entity_type = 'node';
    $draft      = entity_load_single($entity_type, $form_state['nid']);
    $production = entity_load_single($entity_type, $draft->edition_id);
    draft_moderation_publish($draft, $production, $langcode);

    $handler = entity_translation_get_handler($entity_type = 'node', $draft, TRUE);
    if (!empty($handler)) {
      $langcode = $handler->getFormLanguage();
      $translations = $handler->getTranslations();
      if (empty($translations->data[$langcode]) || ($translations->data[$langcode]['created'] == REQUEST_TIME)) {
        // It was a request to create translation.
        // Nothing to do here.
        return;
      }
    }
    unset($form_state['redirect']);
  }
}

/**
 * Node form submit callback for "to PUBLISHED".
 *
 * Copies the submitted translation into published edition.
 */
function draft_moderation_create_and_publish_submit($form, &$form_state) {
  $bundle = $form['#node']->type;
  $moderation_mode = draft_moderation_supported_type($bundle);

  if (user_access('bypass workflow states') ||
    ($moderation_mode && (user_access('publish to production edition') || user_access("publish {$bundle} to production edition")))) {

    $form_state['values']['status'] = 1;
    $form_state['values']['translation']['status'] = 1;
    $form_state['values']['translation']['translate'] = 0;
    $form_state['values']['translation']['workflow'] = DRAFT_MODERATION_WORKFLOW_VALIDATED;

    node_form_submit($form, $form_state);
    $entity_type = 'node';
    // @Important: VISE VERSA when creating.
    $production = entity_load_single($entity_type, $form_state['nid']);
    $draft      = entity_load_single($entity_type, $production->edition_id);
    draft_moderation_publish($draft, $production);
  }
}


/**
 * Node form submit callback for "NEW NODE".
 */
function draft_moderation_new_node_submit($form, &$form_state) {
  $nid = $form_state['nid'];
  $node = node_load($nid);
  $form_state['redirect'] = 'node/' . $node->edition_id;
}

/**
 * Node form submit callback for "to VALIDATE".
 */
function draft_moderation_save_and_send($form, &$form_state) {
  $form_state['values']['translation']['status'] = 0;
  $form_state['values']['translation']['workflow'] = DRAFT_MODERATION_WORKFLOW_TO_VALIDATE;
  $form_state['values']['translation']['translate'] = 0;
  node_form_submit($form, $form_state);
  if (!user_access('bypass workflow states') && !user_access('moderate translations')) {
    $form_state['redirect'] = 'admin/dashboard';
    return;
  }
  unset($form_state['redirect']);
}

/**
 * Node form submit callback for "to Validate TC".
 */
function draft_moderation_save_and_send_to_tc_submit($form, $form_state) {
  $form_state['values']['translation']['status'] = 0;
  $form_state['values']['translation']['workflow'] = DRAFT_MODERATION_WORKFLOW_TO_VALIDATE_TC;
  $form_state['values']['translation']['translate'] = 0;
  node_form_submit($form, $form_state);
  if (!user_access('bypass workflow states') && !user_access('moderate translations')) {
    $form_state['redirect'] = 'admin/dashboard';
    return;
  }
  unset($form_state['redirect']);
}

/**
 * Node form submit callback for "to VALIDATED".
 */
function draft_moderation_approve_submit($form, $form_state) {
  $form_state['values']['translation']['status'] = 0;
  $form_state['values']['translation']['workflow'] = DRAFT_MODERATION_WORKFLOW_VALIDATED;
  $form_state['values']['translation']['translate'] = 0;
  node_form_submit($form, $form_state);
  unset($form_state['redirect']);
}

/**
 * Node form submit callback for "to REFUSE".
 */
function draft_moderation_refuse_submit($form, $form_state) {
  $form_state['values']['translation']['status'] = 0;
  // DRAFT_MODERATION_WORKFLOW_REFUSED.
  $form_state['values']['translation']['workflow'] = DRAFT_MODERATION_WORKFLOW_IN_PROGRESS;
  $form_state['values']['translation']['translate'] = 0;
  node_form_submit($form, $form_state);
  unset($form_state['redirect']);
}

/**
 * Node form submit callback for "to UNPUBLISH".
 */
function draft_moderation_unpublish_submit($form, $form_state) {
  if ($handler = entity_translation_entity_form_get_handler($form, $form_state)) {
    $langcode = $handler->getFormLanguage();
    $translations = $handler->getTranslations();
    $source = $translations->original;
    $entity_type = 'node';
    $edition_id = $form_state['values'][DRAFT_MODERATION_FIELD_REF][LANGUAGE_NONE][0]['target_id'];
    $production = entity_load_single($entity_type, $edition_id);
    if ($source == $langcode) {
      $form_state['values']['status'] = 0;
      $form_state['values']['translation']['status'] = 0;
      node_form_submit($form, $form_state);
      if ($production) {
        $production->status = 0;
        $production_wrapper = entity_metadata_wrapper($entity_type, $production);
        $production_wrapper->save();
        drupal_set_message(t('@node_title has been unpublished', array('@node_title' => $production->title), array('context' => DRAFT_MODERATION_T_CONTEXT)), 'warning');
      }
    }
    else {
      $form_state['values']['translation']['status'] = 0;
      node_form_submit($form, $form_state);
      if ($production && ($phandler = entity_translation_get_handler($entity_type, $production))) {
        $ptranslations = $phandler->getTranslations();
        if (isset($ptranslations->data[$langcode]) && $ptranslations->data[$langcode]['status']) {
          $ptranslations->data[$langcode]['status'] = 0;
          $phandler->setTranslation($ptranslations->data[$langcode]);
          $phandler->saveTranslations();
        }

        // Set current form language.
        $handler = entity_translation_get_handler('node', $production);
        $handler->setFormLanguage($langcode);
        node_save($production);
      }
    }
  }
  unset($form_state['redirect']);
}

/**
 * Submit handler for the 'View changes' action.
 *
 * @TODO
 *
 * @see node_form_build_preview()
 */
function draft_moderation_translations_compare($form, &$form_state) {
  module_load_include('inc', 'diff', 'diff.pages');

  // @TODO: compare stranslations instead of revisions.
  $old_node = clone node_load($form_state['values']['nid']);
  $node = node_form_submit_build_node($form, $form_state);

  // Create diff of old node and edited node.
  $rows = _diff_body_rows($old_node, $node);

  $header = _diff_default_header(t('Original'), t('Changes', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)));
  $changes = theme('table__diff__preview', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('class' => 'diff'),
    'colgroups' => _diff_default_cols(),
    'sticky' => FALSE,
  ));

  // Prepend diff to edit form.
  $form_state['node_preview'] = $changes;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit callback for "Copy from original".
 */
function draft_moderation_node_form_copy_original_submit($form, &$form_state) {
  if (!module_exists('entity_translation')) {
    return;
  }

  $handler = entity_translation_entity_form_get_handler($form, $form_state);

  if (empty($handler)) {
    // Invalid translation handler,
    // or translations are disabled.
    return;
  }

  // Retrieve form language.
  $langcode = $handler->getFormLanguage();
  $node = &$form['#node'];

  if (empty($node->nid)) {
    // If new node?
    return;
  }

  // Copy fields original transtation into current language.
  draft_moderation_translations_update_from_original($node, $entity_type = 'node', $langcode);
  // Mark translation as up to date.
  $node->translations->data[$langcode]['translate'] = 0;
  $node->translations->data[$langcode]['language'] = $langcode;
  // Save the translation.
  node_save($node);

  $node_link = l(t('view'), 'node/' . $node->nid);
  $watchdog_args = array('@type' => $node->type, '%title' => $node->title);
  $t_args = array('@type' => node_type_get_name($node), '%title' => $node->title);

  watchdog('content', '@type: updated %title.', $watchdog_args, WATCHDOG_NOTICE, $node_link);
  drupal_set_message(t('@type %title has been updated.', $t_args));

  if ($node->nid) {
    $form_state['values']['nid'] = $node->nid;
    $form_state['nid'] = $node->nid;
    $form_state['redirect'] = 'node/' . $node->nid . '/edit/' . $langcode;
  }
  else {
    // In the unlikely case something went wrong on save, the node will be
    // rebuilt and node form redisplayed the same way as in preview.
    drupal_set_message(t('The post could not be saved.'), 'error');
    $form_state['rebuild'] = TRUE;
  }
  // Clear the page and block caches.
  cache_clear_all();

  unset($form_state['redirect']);
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows copy original translation into selected.
 */
function draft_moderation_form_commerce_product_ui_product_form_alter(&$form, $form_state) {
  $handler = entity_translation_entity_form_get_handler($form, $form_state);
  if (empty($handler)) {
    // Invalid translation handler,
    // or translations are disabled.
    return;
  }

  // Retrieve form language.
  $form_langcode = $handler->getFormLanguage();
  $translations = $handler->getTranslations();

  // FIX for access Translation actions.
  if (user_access('edit any commerce_product entity') || user_access('edit any commerce_product entity of bundle sku')) {
    $form['actions']['#access'] = TRUE;
  }
  // Prevent removing translations.
  if (isset($form['actions']['delete_translation'])) {
    $form['actions']['delete_translation']['#access'] = FALSE;
  }

  // Update Translation from Original.
  if (!empty($form['#entity']->product_id) && ($form_langcode != $translations->original)) {
    $form['actions']['copy_original'] = array(
      '#type' => 'submit',
      '#value' => t('Copy original translation', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
      '#weight' => 12,
      '#submit' => array('draft_moderation_commere_product_copy_original_submit'),
    );
  }
}

/**
 * Submit callback for "Copy from original".
 */
function draft_moderation_commere_product_copy_original_submit($form, &$form_state) {
  if (!module_exists('entity_translation')) {
    return;
  }

  $handler = entity_translation_entity_form_get_handler($form, $form_state);

  if (empty($handler)) {
    // Invalid translation handler,
    // or translations are disabled.
    return;
  }

  // Retrieve form language.
  $langcode = $handler->getFormLanguage();
  $entity = &$form['#entity'];

  if (empty($entity->product_id)) {
    // If new node?
    return;
  }

  // Copy fields original transtation into current language.
  draft_moderation_translations_update_from_original($entity, $entity_type = 'commerce_product', $langcode);
  // Fix Entity-title issue.
  if (isset($entity->title_original)) {
    $entity->title = $entity->title_original;
  }

  // Save the translation.
  entity_save($entity_type = 'commerce_product', $entity);

  $product_link = l(t('view'), 'admin/commerce/products/' . $entity->product_id . '/edit/' . $langcode);
  $watchdog_args = array('@type' => 'Commerce product', '%title' => $entity->sku);
  $t_args = array('@type' => 'Commerce product', '%title' => $entity->sku);

  watchdog('commerce_product', '@type: updated %title.', $watchdog_args, WATCHDOG_NOTICE, $product_link);
  drupal_set_message(t('@type %title has been updated.', $t_args));

  if ($entity->product_id) {
    $form_state['redirect'] = 'admin/commerce/products/' . $entity->product_id . '/edit/' . $langcode;
  }
  else {
    // In the unlikely case something went wrong on save, the node will be
    // rebuilt and node form redisplayed the same way as in preview.
    drupal_set_message(t('The product could not be saved.'), 'error');
    $form_state['rebuild'] = TRUE;
  }
  // Clear the page and block caches.
  cache_clear_all();
}

/**
 * Implements hook_views_bulk_operations_form_alter().
 */
function draft_moderation_views_bulk_operations_form_alter(&$form, $form_state, $vbo) {
  switch ($form_state['step']) {
    case 'views_bulk_operations_confirm_form':
      if (empty($form_state['values']['operation'])) {
        return;
      }

      $entity_type = $vbo->get_entity_type();
      $options = $vbo->get_operation_options($form_state['values']['operation']);
      $operation = views_bulk_operations_get_operation($form_state['values']['operation'], $entity_type, $options);

      $confirmation_msg = t('Are you sure you want to perform %operation on the selected items?', array('%operation' => $operation->label()), array('context' => DRAFT_MODERATION_T_CONTEXT));
      $form['msg_item'] = array(
        '#type' => 'markup',
        '#markup' => $confirmation_msg,
      );
      break;

  }
}

/**
 * Implements hook_form_BASE_FORM_ID_alter() for node_form().
 *
 * @see path_form_element_validate()
 */
function draft_moderation_form_node_form_alter(&$form, &$form_state) {
  $node = $form_state['node'];
  if (draft_moderation_supported_type($node->type) && !isset($node->is_draft) || (isset($node->is_draft) && $node->is_draft)) {
    $form['#after_build'][] = '_draft_moderation_node_form_after_build';
  }

  // Added slider edit option for role home_page_update.
  if ($form['type']['#value'] == 'homepage' && (site_common_user_has_role('product_suggessions_editor') || site_common_user_has_role('home_page_update'))) {
    $field_groups = [];
    $excluded = ['group_moderation'];
    if (site_common_user_has_role('home_page_update')) {
      array_push($excluded, 'group_slider');
      array_push($excluded, 'group_news');
    }

    if (site_common_user_has_role('product_suggessions_editor')) {
      array_push($excluded, 'group_top_products');
    }
    foreach ($form['#fieldgroups'] as $key => $val) {
      if (in_array($key, $excluded)) {
        continue;
      }
      $field_groups[] = $key;
    }

    field_group_hide_field_groups($form, $field_groups);
  }
}

/**
 * After build from callback for node form.
 *
 * @see draft_moderation_form_node_form_alter()
 */
function _draft_moderation_node_form_after_build($form, &$form_state) {
  if (isset($form['path'])) {
    if (!empty($form['path']['alias']['#value'])) {
      $current_alias = $form['path']['alias']['#value'];
      if (0 === strpos($current_alias, 'draft/')) {
        $form['path']['alias']['#value'] = substr($current_alias, strlen('draft/'));
      }
    }
    array_unshift($form['path']['#element_validate'], 'draft_moderation_node_form_path_element_validate');
  }
  return $form;
}

/**
 * Form element validation handler for URL alias form element.
 */
function draft_moderation_node_form_path_element_validate($element, &$form_state, $complete_form) {
  // Trim the submitted value.
  $alias = trim($form_state['values']['path']['alias']);
  if (!empty($alias)) {
    if (0 !== strpos($alias, 'draft/')) {
      $alias = 'draft/' . $alias;
    }
    form_set_value($element['alias'], $alias, $form_state);
  }
}
