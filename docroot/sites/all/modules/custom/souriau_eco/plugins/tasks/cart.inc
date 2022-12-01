<?php

/**
 * @file
 * Handle the 'cart' override task.
 *
 * This plugin overrides commerce/% and reroutes it to the page manager, where
 * a list of tasks can be used to service this request based upon criteria
 * supplied by access plugins.
 */

/**
 * Implements hook_page_manager_task_tasks().
 *
 * See api-task.html for
 * more information.
 */
function souriau_eco_cart_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI.
    'task type' => 'page',
    'title' => t('Commerce Cart Template'),
    'admin title' => t('Commerce Cart Template'),
    'admin description' => t('When enabled, this overrides the default Drupal
    behavior for displaying commerce cart form.'),
    'admin path' => 'cart',
    // Callback to add items to the page manager task administration form:
    'hook menu' => 'souriau_eco_cart_menu',
    'hook menu alter' => 'souriau_eco_cart_menu_alter',
    // This is a task that uses 'context' handlers and must implement these
    // to give the
    // handler data it needs.
    'handler type' => 'context',
    // Allow this to be enabled or disabled.
    'disabled' => variable_get('souriau_eco_cart_disabled', FALSE),
    'enable callback' => 'souriau_eco_cart_enable',
  );
}

/**
 * Menu alter defined by souriau_eco_cart_page_manager_tasks().
 *
 * Alter the commerce form so that view comes to us rather than the
 * normal process.
 */
function souriau_eco_cart_menu_alter(&$items, $task) {
  if (variable_get('souriau_eco_cart_disabled', FALSE)) {
    return;
  }

  if (!empty($items['cart']) || variable_get('page_manager_override_anyway', FALSE)) {
    $items['cart']['page callback'] = 'souriau_eco_cart_page';
    $items['cart']['file path'] = $task['path'];
    $items['cart']['file'] = $task['file'];
  }
  else {
    // Automatically disable this task if it cannot be enabled.
    variable_set('souriau_eco_cart_disabled', TRUE);
    if (!empty($GLOBALS['souriau_eco_enabling_cart'])) {
      drupal_set_message(t('Page manager module is unable to enable checkout/%commerce_order because some other module already has overridden with %callback.', array('%callback' => $items['checkout/%commerce_order']['page callback'])), 'error');
    }
  }
}

/**
 * Page callback for Checkout.
 *
 * In this function we are going to call the page arguments and put it in
 * context so we can access it all the time.
 * We build our form with the page args that are send with the page callback.
 */
function souriau_eco_cart_page() {
  module_load_include('inc', 'commerce_cart', 'includes/commerce_cart.pages');

  // Load my task plugin:
  $task = page_manager_get_task('cart');

  // Load the account into a context.
  ctools_include('context');
  ctools_include('context-task-handler');
  $contexts = ctools_context_handler_get_task_contexts($task, '', array());

  $output = ctools_context_handler_render($task, '', $contexts, array());

  if ($output != FALSE) {
    return $output;
  }

  // Otherwise, fallback to default view.
  return commerce_cart_view();
}

/**
 * Callback to enable/disable the page from the UI.
 */
function souriau_eco_cart_enable($cache, $status) {
  variable_set('souriau_eco_cart_disabled', $status);
  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['souriau_eco_enabling_cart'] = TRUE;
  }
}
