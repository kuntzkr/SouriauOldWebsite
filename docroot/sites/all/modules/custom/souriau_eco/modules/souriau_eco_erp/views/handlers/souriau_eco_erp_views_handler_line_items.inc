<?php
/**
 * @file
 * Views plugin for translation link.
 */

/**
 * Field handler to present a link to the node.
 *
 * @ingroup views_field_handlers
 */
class souriau_eco_erp_views_handler_line_items extends views_handler_field {
  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();

    $this->additional_fields['order_id'] = 'order_id';
  }

  /**
   * {@inheritdoc}
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   */
  public function access() {
    return TRUE;
  }

  /**
   * Render.
   */
  public function render($values) {
    return $this->renderLineItem($values);
  }

  /**
   * Render Link.
   */
  private function renderLineItem($values) {
    $order_id = $this->get_value($values, 'order_id');
    if (!($this->access())) {
      return;
    }
    if (empty($order_id)) {
      return;
    }
    try {
      $wrapper = entity_metadata_wrapper('commerce_order', $order_id);
      $line_item_display_title = '';
      foreach ($wrapper->commerce_line_items as $line_item_wrapper) {
        if (!in_array($line_item_wrapper->type->value(), commerce_product_line_item_types())) {
          continue;
        }
        $line_item_quantity = !empty($line_item_wrapper->quantity->value()) ? $line_item_wrapper->quantity->value() : 0;
        $title = !empty($line_item_wrapper->commerce_product->title->value()) ?
          $line_item_wrapper->commerce_product->title->value()
          . '(' . $line_item_wrapper->line_item_label->value() . ')'
          : '(' . $line_item_wrapper->line_item_label->value() . ')';
        $display_title = $title . ' - ' . $line_item_quantity;
        $line_item_display_title .= !empty($line_item_display_title) ? ' | ' . $display_title : $display_title;
      }
      $text = $line_item_display_title;
      return $text;
    }
    catch (Exception $e) {
      watchdog('souriau_eco', 'Exception %message in !function.', [
        '%message' => $e->getMessage(),
        '!function' => __FUNCTION__,
      ], WATCHDOG_WARNING);
    }
  }

}
