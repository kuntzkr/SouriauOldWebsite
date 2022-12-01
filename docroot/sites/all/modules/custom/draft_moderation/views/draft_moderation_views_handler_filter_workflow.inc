<?php

/**
 * @file
 * Interface between draft_moderation.module and views.module.
 */

/**
 * Filter for translation workflow status
 */
class draft_moderation_views_handler_filter_workflow extends views_handler_filter_in_operator  {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Workflow status', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
      $states = _draft_moderation_workflow_states();
      $states = array_map('check_plain', $states);
      $this->value_options = $states;
    }
  }
}
