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
class souriau_eco_erp_views_handler_erp_link extends views_handler_field {

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
    return user_access('souriau_eco_erp_dashboard_send_request');
  }

  /**
   * Render.
   */
  public function render($values) {
    return $this->renderLink($values);
  }

  /**
   * Render Link.
   */
  private function renderLink($values) {
    $order_id = $this->get_value($values, 'order_id');
    $text = !empty($this->options['text']) ? $this->options['text'] : t('ERP');
    if ($this->access()) {
      $this->options['alter']['path'] = "admin/commerce/orders/{$order_id}/erp";
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['query'] = drupal_get_destination();
      return $text;
    }
  }

}
