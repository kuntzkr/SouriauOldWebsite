<?php
/**
 * @file
 * Plugin to provide ERP Order  context.
 */

$plugin = array(
  'title' => t("ERP Order"),
  'description' => t('ERP Order Object'),
  'context' => 'erp_order_panels_context_erp_order_page',
  'keyword' => 'erp_order',
  'context name' => 'erp_order',
  'no ui' => FALSE,
);

/**
 * Context create callback.
 */
function erp_order_panels_context_erp_order_page($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('string');
  $context->plugin = 'string';
  if ($empty) {
    return $context;
  }

  if (!empty($data)) {
    $context->data     = $data;
    $context->title = t('ERP Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
    return $context;
  }
}
