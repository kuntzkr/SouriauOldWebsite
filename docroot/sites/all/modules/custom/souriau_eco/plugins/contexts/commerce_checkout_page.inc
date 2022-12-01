<?php
/**
 * @file
 * Plugin to provide a checkout page  context.
 */

$plugin = array(
  'title' => t("Commerce checkout page"),
  'description' => t('A commerce checkout page object.'),
  'context' => 'commerce_checkout_panels_context_create_commerce_checkout_page',
  'keyword' => 'commerce_checkout_page',
  'context name' => 'commerce_checkout_page',
  'no ui' => TRUE,
);

/**
 * Context create callback.
 *
 * It's important to remember that $conf is optional here, because contexts
 * are not always created from the UI.
 */
function commerce_checkout_panels_context_create_commerce_checkout_page($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('string');
  $context->plugin = 'string';
  if ($empty) {
    return $context;
  }

  // Allow context to be created from the UI config.
  if ($conf) {
    $page_id = is_array($data) && isset($data['page_id'])
      ? $data['page_id']
      : (is_object($data) ? $data->page_id : 0);

    if (is_array($data) || !empty($reload)) {
      $data = commerce_checkout_page_load($page_id);
    }
  }

  if (!empty($data)) {
    $context->data     = $data['page_id'];
    $context->title    = $data['title'];
    $context->argument = $data;

    return $context;
  }
}
