<?php
/**
 * @file
 * Interface between domain_views.module and views.module.
 *
 * @ingroup domain_views
 */

/**
 * Field handler to provide simple renderer that allows linking to a workflow.
 *
 * @ingroup domain_views
 */
class draft_moderation_views_handler_field_workflow extends views_handler_field {

  function render($values) {
    $state = $values->{$this->field_alias};
    return check_plain(_draft_moderation_workflow_states($state));
  }
}
