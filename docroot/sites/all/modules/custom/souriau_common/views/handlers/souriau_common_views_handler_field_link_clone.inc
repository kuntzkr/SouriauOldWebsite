<?php
/**
 * @file
 * Views field handler for Node_Clone module.
 */

/**
 * Field handler to present a clone node link.
 *
 * Added additional check on node type.
 *
 * @see views_handler_field_node_link_clone.
 */
class souriau_common_views_handler_field_link_clone extends views_handler_field_node_link_clone {

  /**
   * Renders the link.
   */
  public function render_link($node, $values) {

    if ('product' != $node->type) {
      return;
    }

    return parent::render_link($node, $values);
  }

}
