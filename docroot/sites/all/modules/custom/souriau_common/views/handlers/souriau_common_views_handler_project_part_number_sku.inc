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
class souriau_common_views_handler_project_part_number_sku extends views_handler_field {
  /**
   * {@inheritdoc}
   */
  public function construct() {
    parent::construct();

    $this->additional_fields['id']  = 'id';
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
    return $this->renderProjectSku($values);
  }

  /**
   * Render Link.
   */
  private function renderProjectSku($values) {
    global $language;
    $project_id = $this->get_value($values, 'id');
    if (!($this->access())) {
      return '';
    }
    if (empty($project_id)) {
      return '';
    }
    try {
      $project_entity = entity_load_single('project', $project_id);
      $project_wrapper = entity_metadata_wrapper($project_entity->type, $project_entity)->language($language->language);
      $project_sku = '';
      foreach ($project_wrapper->field_part_numbers as $project_line_item) {
        $sku = $project_line_item->field_part_number->field_sku_products->sku->value();
        $project_sku .= !empty($project_sku) ? ' | ' . $sku : $sku;
      }
      $text = $project_sku;
      return $text;
    }
    catch (Exception $e) {
      watchdog('souriau_common', 'Exception %message in !function.', [
        '%message' => $e->getMessage(),
        '!function' => __FUNCTION__,
      ], WATCHDOG_WARNING);
    }
  }

}
