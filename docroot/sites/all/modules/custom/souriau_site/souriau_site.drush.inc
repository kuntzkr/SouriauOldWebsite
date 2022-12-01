<?php
/**
 * @file
 * souriau_site.drush.inc
 */

/*******************************************************************************
 * DRUSH SUPPORT
 ******************************************************************************/

/**
 * Implements hook_drush_command().
 */
function souriau_site_drush_command() {
  $items = array();

  $items['souriau-env'] = array(
    'description' => "Run reconfiguration of all domains and variables according to enviroment configs in settings.php",
    'callback'    => 'drush_souriau_site_enviroment_reconfigure_wrapper',
    'arguments' => array(),
    'examples' => array(
      'drush souriau-env' => 'Reconfigures the website after migrating DB from other server.',
    ),
    // 'aliases' => array('souriau-env'),
    // 'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );
  $items['delete-all-pn'] = array(
    'description' => "Delete all part_numbers and SKUs",
    'callback'    => 'drush_souriau_site_delete_pn',
    'arguments' => array(),
    'examples' => array(
      'drush delete-pn-and-sku' => 'delete PN & SKU',
    ),
  );

  return $items;
}

/**
 * Reconfigure enviroment.
 */
function drush_souriau_site_enviroment_reconfigure_wrapper() {
  $env = variable_get('enviroment', FALSE);
  if (empty($env) || empty($env['main_domain'])) {
    print "Stopped. `env` is not configured. At lease env[`main_domain`] has to be set.";
    return;
  }
  print 'Configuration to apply: ' . print_r($env, TRUE) . PHP_EOL;

  print 'Checking search servers' . PHP_EOL;
  if (!isset($_ENV['AH_SITE_ENVIRONMENT'])) {
    // Load all indexes.
    $indexes = search_api_index_load_multiple(FALSE);
    foreach ($indexes as $index) {
      $server = search_api_server_load($index->server);
      if (empty($server) || $server->class == 'acquia_search_service') {
        if ($index->update(['read_only' => 1])) {
          print $index->name . ': read_only mode was turned ON' . PHP_EOL;
          continue;
        }
        print $index->name . ': problem during updating index.' . PHP_EOL;
      }
    }
  }
  print 'Search configuration - done' . PHP_EOL;

  // 1. Change domains.
  $all_domains = domain_domains();
  foreach ($all_domains as $domain) {
    $basic_subdomain = $domain['subdomain'];
    $domain_array = explode('.', $domain['subdomain']);
    $domain_prefix = array_shift($domain_array);
    $domain['subdomain'] = $domain_prefix . '.' . rtrim($env['main_domain'], '/');
    $domain['path'] = rtrim($domain['scheme'] . '://' . $domain_prefix . '.' . $env['main_domain'], '/') . '/';

    // Update Aliases.
    if (!empty($domain['aliases']) && is_array($domain['aliases'])) {
      foreach ($domain['aliases'] as &$alias) {
        $alias['pattern'] = str_replace($basic_subdomain, $domain['subdomain'], $alias['pattern']);
        db_update('domain_alias')
          ->condition('alias_id', $alias['alias_id'])
          ->fields(array(
            'pattern' => $alias['pattern'],
            'redirect' => intval($alias['redirect']),
          ))
          ->execute();
      }
    }

    // Update secure setting.
    if (module_exists('securepages') && module_exists('domain')) {
      if ($domain['domain_id'] == '1') {
        domain_conf_variable_set($domain['domain_id'], 'securepages_basepath_ssl', 'https://' . rtrim($env['main_domain'], '/'));
      }
      else {
        domain_conf_variable_set($domain['domain_id'], 'securepages_basepath_ssl', 'https://' . rtrim($domain['subdomain'], '/'));
      }
      domain_conf_variable_set($domain['domain_id'], 'securepages_basepath', $domain['path']);
    }

    domain_save($domain);
  }
  print 'Domain configurations are updated.' . PHP_EOL;

  // Reset static domain caches.
  drupal_static_reset('domain_lookup_domains');
  drupal_static_reset('domain_lookup_result');

  // 2. Change superadmin user credentials.
  if (!empty($env['admin_login']) && !empty($env['admin_pwd'])) {
    $admin = user_load(1);
    $credentials = array(
      'name' => $env['admin_login'],
      'pass' => $env['admin_pwd'],
    );
    user_save($admin, $credentials);
    print 'Admin Credentials are updated.' . PHP_EOL;
  }

  return "Done";
}


/**
 * Index items.
 *
 * @param array $bundles
 *   The array of bundles to delete: ['node' => 'article', 'commerce_product' => 'sku'].
 * @param int $batch_size
 *   Number of items to index per batch.
 */
function drush_souriau_site_delete_pn($bundles = ['node' => 'product'], $batch_size = 500) {

  // TODO for other CT.
  foreach ($bundles as $type => $bundle) {
    $q = new EntityFieldQuery();
    $q->entityCondition('entity_type', $type)
      ->entityCondition('bundle', $bundle)
      ->addMetaData('account', user_load(1));
    $limit = $q->count()->execute();
    if (empty($limit)) {
      continue;
    }

    drush_log(dt("for deletion: !limit of !bundle with step !batch_size", array(
      '!bundle' => $type . ':' . $bundle,
      '!limit' => $limit,
      '!batch_size' => $batch_size
    )), 'ok');

    // Set the batch.
    $batch = array(
      'title' => dt('Deleting items'),
      'operations' => array(
        array(
          '_souriau_site_batch_delete_content_callback',
          array($type, $bundle, $batch_size, $limit)
        ),
      ),
      'progress_message' => dt('Deleted about @percentage% .'),
      'finished' => '_souriau_site_batch_deleting_finished',
      'file' => drupal_get_path('module', 'souriau_site') . '/souriau_site.module',
    );
    batch_set($batch);
  }
  // Start process batch.
  drush_backend_batch_process();
}
