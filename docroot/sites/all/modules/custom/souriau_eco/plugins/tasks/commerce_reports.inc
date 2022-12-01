<?php

/**
 * @file
 * Handle the 'commerce_reports' override task.
 *
 * This plugin overrides admin/commerce/reports
 * and reroutes it to the page manager, where
 * a list of tasks can be used to service this request based upon criteria
 * supplied by access plugins.
 */

/**
 * Implements hook_page_manager_task_tasks().
 *
 * See api-task.html for
 * more information.
 */
function souriau_eco_commerce_reports_page_manager_tasks() {
  return array(
    // This is a 'page' task and will fall under the page admin UI.
    'title' => t('Commerce Reports Template'),
    'description' => t('When enabled, this overrides the default Drupal
    behavior for displaying Commerce Reports Dashboard.'),
    'task type' => 'page',
    'admin title' => t('Commerce Reports Template'),
    'admin description' => t('When enabled, this overrides the default Drupal behavior for displaying Commerce Reports Dashboard.'),
    'admin path' => 'admin/commerce/reports',
    // Callback to override standard commerce reports dashboard:
    'hook menu alter' => 'souriau_eco_commerce_reports_menu_alter',
    // Allow this to be enabled or disabled.
    'disabled' => variable_get('souriau_eco_commerce_reports_disabled', FALSE),
    'enable callback' => 'souriau_eco_commerce_reports_enable',
  );
}

/**
 * Menu alter defined by souriau_eco_commerce_page_manager_tasks().
 *
 * Alter the commerce form so that view comes to us rather than the
 * normal process.
 */
function souriau_eco_commerce_reports_menu_alter(&$items, $task) {
  if (variable_get('souriau_eco_commerce_reports_disabled', FALSE)) {
    return;
  }

  if (!empty($items['admin/commerce/reports/dashboard']) || variable_get('page_manager_override_anyway', FALSE)) {
    $items['admin/commerce/reports']['page callback'] = 'souriau_eco_commerce_reports_page';
    $items['admin/commerce/reports/dashboard']['file path'] = $task['path'];
    $items['admin/commerce/reports/dashboard']['file'] = $task['file'];
  }
  if (!empty($items['admin/commerce/reports']) || variable_get('page_manager_override_anyway', FALSE)) {
    $items['admin/commerce/reports']['page callback'] = 'souriau_eco_commerce_reports_page';
    $items['admin/commerce/reports']['file path'] = $task['path'];
    $items['admin/commerce/reports']['file'] = $task['file'];
  }
  else {
    // Automatically disable this task if it cannot be enabled.
    variable_set('souriau_eco_commerce_reports_disabled', TRUE);
    if (!empty($GLOBALS['souriau_eco_enabling_commerce_reports'])) {
      drupal_set_message(t('Page manager module is unable to enable checkout/%commerce_order because some other module already has overridden with %callback.', array('%callback' => $items['checkout/%commerce_order']['page callback'])), 'error');
    }
  }
}

/**
 * Page callback for Commerce Reports.
 *
 * In this function we are going to call the page arguments and put it in
 * context so we can access it all the time.
 * We build our form with the page args that are send with the page callback.
 */
function souriau_eco_commerce_reports_page() {
  drupal_add_js(drupal_get_path('module', 'commerce_reports') . '/theme/js/dashboard.js', 'file');
  drupal_add_css(drupal_get_path('module', 'commerce_reports') . '/theme/css/commerce_reports_dashboard.css');

  // Load my task plugin:
  $task = page_manager_get_task('commerce_reports');

  // Load the account into a context.
  ctools_include('context');
  ctools_include('context-task-handler');
  $contexts = ctools_context_handler_get_task_contexts($task, '', array());

  $output = ctools_context_handler_render($task, '', $contexts, array());

  if ($output != FALSE) {
    return $output;
  }
}

/**
 * Callback to enable/disable the page from the UI.
 */
function souriau_eco_commerce_reports_enable($cache, $status) {
  variable_set('souriau_eco_commerce_reports_disabled', $status);
  // Set a global flag so that the menu routine knows it needs
  // to set a message if enabling cannot be done.
  if (!$status) {
    $GLOBALS['souriau_eco_enabling_commerce_reports'] = TRUE;
  }
}
