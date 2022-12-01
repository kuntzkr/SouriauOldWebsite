<?php
/**
 * @file
 * Implements views hooks.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class draft_moderation_views_handler_field_status extends views_handler_field_boolean {
  function construct() {
    parent::construct();
  }

  function render($values) {
    $value = $this->get_value($values);
    if (isset($values->node_status)) {
      $value = $values->node_status && $this->get_value($values);
    }

    if (!empty($this->options['not'])) {
      $value = !$value;
    }

    if (isset($this->formats[$this->options['type']])) {
      return $value ? $this->formats[$this->options['type']][0] : $this->formats[$this->options['type']][1];
    }
    else {
      return $value ? $this->formats['yes-no'][0] : $this->formats['yes-no'][1];
    }
  }
}
