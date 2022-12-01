<?php

/**
 * @file
 * souriau_eco_erp.pages.inc
 */

/**
 * Default callback for Ecommerce menu link.
 */
function souriau_eco_erp_pages_default_callback() {
  drupal_goto('admin/dashboard/ecommerce/orders');
}

/**
 * Fallback for Dashboard Ecommerce > Orders page.
 */
function souriau_eco_erp_pages_orders_callback() {
  return 'View missed';
}

/**
 * Another dprint_r().
 *
 * Not restricted access.
 */
function souriau_eco_erp_pages_dprint_r($input, $return = FALSE, $name = NULL, $function = 'print_r', $check = TRUE) {
  if ($name) {
    $name .= ' => ';
  }
  if ($function == 'drupal_var_export') {
    $output = drupal_var_export($input);
  }
  else {
    ob_start();
    $function($input);
    $output = ob_get_clean();
  }

  if ($check) {
    $output = check_plain($output);
  }
  if ($input && count($input, COUNT_RECURSIVE) > DEVEL_MIN_TEXTAREA) {
    // Don't use fapi here because sometimes fapi will not be loaded.
    $printed_value = "<textarea rows=30 style=\"width: 100%;\">\n" . $name . $output . '</textarea>';
  }
  else {
    $printed_value = '<pre>' . $name . $output . '</pre>';
  }

  if ($return) {
    return $printed_value;
  }
  else {
    print $printed_value;
  }
}
