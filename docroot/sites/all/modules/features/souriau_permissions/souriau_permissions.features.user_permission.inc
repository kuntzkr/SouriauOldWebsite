<?php

/**
 * @file
 * souriau_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function souriau_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access Dashboard'.
  $permissions['access Dashboard'] = array(
    'name' => 'access Dashboard',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'customer_service' => 'customer_service',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'news_tags_manager' => 'news_tags_manager',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'sample_manager' => 'sample_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'souriau_common',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'customer_service' => 'customer_service',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'news_tags_manager' => 'news_tags_manager',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'sample_manager' => 'sample_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'customer_service' => 'customer_service',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'news_tags_manager' => 'news_tags_manager',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'sample_manager' => 'sample_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access checkout'.
  $permissions['access checkout'] = array(
    'name' => 'access checkout',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'access commerce_product clone'.
  $permissions['access commerce_product clone'] = array(
    'name' => 'access commerce_product clone',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'souriau_common',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'access domain settings form'.
  $permissions['access domain settings form'] = array(
    'name' => 'access domain settings form',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain_settings',
  );

  // Exported permission: 'access environment indicator'.
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'customer_service' => 'customer_service',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'sample_manager' => 'sample_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access inactive domains'.
  $permissions['access inactive domains'] = array(
    'name' => 'access inactive domains',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'access media browser'.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'media',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'customer_service' => 'customer_service',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer checkout'.
  $permissions['administer checkout'] = array(
    'name' => 'administer checkout',
    'roles' => array(),
    'module' => 'commerce_checkout',
  );

  // Exported permission: 'administer commerce_customer_profile entities'.
  $permissions['administer commerce_customer_profile entities'] = array(
    'name' => 'administer commerce_customer_profile entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'administer commerce_order entities'.
  $permissions['administer commerce_order entities'] = array(
    'name' => 'administer commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'customer_service' => 'customer_service',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'administer commerce_product entities'.
  $permissions['administer commerce_product entities'] = array(
    'name' => 'administer commerce_product entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer customer profile types'.
  $permissions['administer customer profile types'] = array(
    'name' => 'administer customer profile types',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'administer domains'.
  $permissions['administer domains'] = array(
    'name' => 'administer domains',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'administer elysia_cron'.
  $permissions['administer elysia_cron'] = array(
    'name' => 'administer elysia_cron',
    'roles' => array(),
    'module' => 'elysia_cron',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer file types'.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer files'.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(),
    'module' => 'file_entity',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer mail templates'.
  $permissions['administer mail templates'] = array(
    'name' => 'administer mail templates',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'mail_edit',
  );

  // Exported permission: 'administer mailchimp'.
  $permissions['administer mailchimp'] = array(
    'name' => 'administer mailchimp',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mailchimp',
  );

  // Exported permission: 'administer media browser'.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menus per domain'.
  $permissions['administer menus per domain'] = array(
    'name' => 'administer menus per domain',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'domain_menu_access',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer souriau main_menu'.
  $permissions['administer souriau main_menu'] = array(
    'name' => 'administer souriau main_menu',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'souriau_common',
  );

  // Exported permission: 'administer souriau site settings'.
  $permissions['administer souriau site settings'] = array(
    'name' => 'administer souriau site settings',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'souriau_common',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'customer_service' => 'customer_service',
    ),
    'module' => 'user',
  );

  // Exported permission: 'assign domain editors'.
  $permissions['assign domain editors'] = array(
    'name' => 'assign domain editors',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'bypass file access'.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass workflow states'.
  $permissions['bypass workflow states'] = array(
    'name' => 'bypass workflow states',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'bypass_access_order_history'.
  $permissions['bypass_access_order_history'] = array(
    'name' => 'bypass_access_order_history',
    'roles' => array(
      'administrator' => 'administrator',
      'customer_service' => 'customer_service',
    ),
    'module' => 'souriau_eco',
  );

  // Exported permission: 'bypass_myprojects_access'.
  $permissions['bypass_myprojects_access'] = array(
    'name' => 'bypass_myprojects_access',
    'roles' => array(),
    'module' => 'souriau_common',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear souriau_master_file_product_importer feeds'.
  $permissions['clear souriau_master_file_product_importer feeds'] = array(
    'name' => 'clear souriau_master_file_product_importer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear souriau_master_file_sku_importer feeds'.
  $permissions['clear souriau_master_file_sku_importer feeds'] = array(
    'name' => 'clear souriau_master_file_sku_importer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clone node'.
  $permissions['clone node'] = array(
    'name' => 'clone node',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'clone',
  );

  // Exported permission: 'clone own nodes'.
  $permissions['clone own nodes'] = array(
    'name' => 'clone own nodes',
    'roles' => array(),
    'module' => 'clone',
  );

  // Exported permission: 'configure order settings'.
  $permissions['configure order settings'] = array(
    'name' => 'configure order settings',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create application content'.
  $permissions['create application content'] = array(
    'name' => 'create application content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create application content on assigned domains'.
  $permissions['create application content on assigned domains'] = array(
    'name' => 'create application content on assigned domains',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create applicationdomain content'.
  $permissions['create applicationdomain content'] = array(
    'name' => 'create applicationdomain content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create applicationdomain content on assigned domains'.
  $permissions['create applicationdomain content on assigned domains'] = array(
    'name' => 'create applicationdomain content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create applicationlanding content'.
  $permissions['create applicationlanding content'] = array(
    'name' => 'create applicationlanding content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create applicationlanding content on assigned domains'.
  $permissions['create applicationlanding content on assigned domains'] = array(
    'name' => 'create applicationlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create capabilitieslanding content'.
  $permissions['create capabilitieslanding content'] = array(
    'name' => 'create capabilitieslanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create capabilitieslanding content on assigned domains'.
  $permissions['create capabilitieslanding content on assigned domains'] = array(
    'name' => 'create capabilitieslanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create capability content'.
  $permissions['create capability content'] = array(
    'name' => 'create capability content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create capability content on assigned domains'.
  $permissions['create capability content on assigned domains'] = array(
    'name' => 'create capability content on assigned domains',
    'roles' => array(
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create capabilitydomain content'.
  $permissions['create capabilitydomain content'] = array(
    'name' => 'create capabilitydomain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create capabilitydomain content on assigned domains'.
  $permissions['create capabilitydomain content on assigned domains'] = array(
    'name' => 'create capabilitydomain content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create category content'.
  $permissions['create category content'] = array(
    'name' => 'create category content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create category content on assigned domains'.
  $permissions['create category content on assigned domains'] = array(
    'name' => 'create category content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create cms_page content on assigned domains'.
  $permissions['create cms_page content on assigned domains'] = array(
    'name' => 'create cms_page content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create commerce_customer_profile entities'.
  $permissions['create commerce_customer_profile entities'] = array(
    'name' => 'create commerce_customer_profile entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_customer_profile entities of bundle billing'.
  $permissions['create commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'create commerce_customer_profile entities of bundle billing',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_customer_profile entities of bundle shipping'.
  $permissions['create commerce_customer_profile entities of bundle shipping'] = array(
    'name' => 'create commerce_customer_profile entities of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'create commerce_order entities'.
  $permissions['create commerce_order entities'] = array(
    'name' => 'create commerce_order entities',
    'roles' => array(
      'administrator' => 'administrator',
      'customer_service' => 'customer_service',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle commerce_order'.
  $permissions['create commerce_order entities of bundle commerce_order'] = array(
    'name' => 'create commerce_order entities of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_order entities of bundle samples_order'.
  $permissions['create commerce_order entities of bundle samples_order'] = array(
    'name' => 'create commerce_order entities of bundle samples_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'create commerce_product entities'.
  $permissions['create commerce_product entities'] = array(
    'name' => 'create commerce_product entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create commerce_product entities of bundle sku'.
  $permissions['create commerce_product entities of bundle sku'] = array(
    'name' => 'create commerce_product entities of bundle sku',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'create faq content'.
  $permissions['create faq content'] = array(
    'name' => 'create faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create faq content on assigned domains'.
  $permissions['create faq content on assigned domains'] = array(
    'name' => 'create faq content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create files'.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'create genericlanding content on assigned domains'.
  $permissions['create genericlanding content on assigned domains'] = array(
    'name' => 'create genericlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create homepage content'.
  $permissions['create homepage content'] = array(
    'name' => 'create homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create homepage content on assigned domains'.
  $permissions['create homepage content on assigned domains'] = array(
    'name' => 'create homepage content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'create news content'.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create news content on assigned domains'.
  $permissions['create news content on assigned domains'] = array(
    'name' => 'create news content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create news_landing content on assigned domains'.
  $permissions['create news_landing content on assigned domains'] = array(
    'name' => 'create news_landing content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create product content'.
  $permissions['create product content'] = array(
    'name' => 'create product content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create product content on assigned domains'.
  $permissions['create product content on assigned domains'] = array(
    'name' => 'create product content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create productlanding content'.
  $permissions['create productlanding content'] = array(
    'name' => 'create productlanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create productlanding content on assigned domains'.
  $permissions['create productlanding content on assigned domains'] = array(
    'name' => 'create productlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create productrange content'.
  $permissions['create productrange content'] = array(
    'name' => 'create productrange content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create productrange content on assigned domains'.
  $permissions['create productrange content on assigned domains'] = array(
    'name' => 'create productrange content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'product_contributor' => 'product_contributor',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create productrangehub content on assigned domains'.
  $permissions['create productrangehub content on assigned domains'] = array(
    'name' => 'create productrangehub content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create resource content on assigned domains'.
  $permissions['create resource content on assigned domains'] = array(
    'name' => 'create resource content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create subcategory content'.
  $permissions['create subcategory content'] = array(
    'name' => 'create subcategory content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create subcategory content on assigned domains'.
  $permissions['create subcategory content on assigned domains'] = array(
    'name' => 'create subcategory content on assigned domains',
    'roles' => array(
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create tool content'.
  $permissions['create tool content'] = array(
    'name' => 'create tool content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create tool content on assigned domains'.
  $permissions['create tool content on assigned domains'] = array(
    'name' => 'create tool content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create toolkitlanding content on assigned domains'.
  $permissions['create toolkitlanding content on assigned domains'] = array(
    'name' => 'create toolkitlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create webform content on assigned domains'.
  $permissions['create webform content on assigned domains'] = array(
    'name' => 'create webform content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any 3d_model files'.
  $permissions['delete any 3d_model files'] = array(
    'name' => 'delete any 3d_model files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any application content'.
  $permissions['delete any application content'] = array(
    'name' => 'delete any application content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any applicationdomain content'.
  $permissions['delete any applicationdomain content'] = array(
    'name' => 'delete any applicationdomain content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any applicationlanding content'.
  $permissions['delete any applicationlanding content'] = array(
    'name' => 'delete any applicationlanding content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any audio files'.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any capabilitieslanding content'.
  $permissions['delete any capabilitieslanding content'] = array(
    'name' => 'delete any capabilitieslanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any capability content'.
  $permissions['delete any capability content'] = array(
    'name' => 'delete any capability content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any capabilitydomain content'.
  $permissions['delete any capabilitydomain content'] = array(
    'name' => 'delete any capabilitydomain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any category content'.
  $permissions['delete any category content'] = array(
    'name' => 'delete any category content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any document files'.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any faq content'.
  $permissions['delete any faq content'] = array(
    'name' => 'delete any faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any homepage content'.
  $permissions['delete any homepage content'] = array(
    'name' => 'delete any homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any image files'.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any ipaper files'.
  $permissions['delete any ipaper files'] = array(
    'name' => 'delete any ipaper files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any news content'.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any product content'.
  $permissions['delete any product content'] = array(
    'name' => 'delete any product content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any productlanding content'.
  $permissions['delete any productlanding content'] = array(
    'name' => 'delete any productlanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any productrange content'.
  $permissions['delete any productrange content'] = array(
    'name' => 'delete any productrange content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any subcategory content'.
  $permissions['delete any subcategory content'] = array(
    'name' => 'delete any subcategory content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tool content'.
  $permissions['delete any tool content'] = array(
    'name' => 'delete any tool content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any video files'.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete application content on assigned domains'.
  $permissions['delete application content on assigned domains'] = array(
    'name' => 'delete application content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete applicationdomain content on assigned domains'.
  $permissions['delete applicationdomain content on assigned domains'] = array(
    'name' => 'delete applicationdomain content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete applicationlanding content on assigned domains'.
  $permissions['delete applicationlanding content on assigned domains'] = array(
    'name' => 'delete applicationlanding content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete capabilitieslanding content on assigned domains'.
  $permissions['delete capabilitieslanding content on assigned domains'] = array(
    'name' => 'delete capabilitieslanding content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete capability content on assigned domains'.
  $permissions['delete capability content on assigned domains'] = array(
    'name' => 'delete capability content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete capabilitydomain content on assigned domains'.
  $permissions['delete capabilitydomain content on assigned domains'] = array(
    'name' => 'delete capabilitydomain content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete category content on assigned domains'.
  $permissions['delete category content on assigned domains'] = array(
    'name' => 'delete category content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete domain content'.
  $permissions['delete domain content'] = array(
    'name' => 'delete domain content',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete faq content on assigned domains'.
  $permissions['delete faq content on assigned domains'] = array(
    'name' => 'delete faq content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete homepage content on assigned domains'.
  $permissions['delete homepage content on assigned domains'] = array(
    'name' => 'delete homepage content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete news content on assigned domains'.
  $permissions['delete news content on assigned domains'] = array(
    'name' => 'delete news content on assigned domains',
    'roles' => array(
      'delete_data' => 'delete_data',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'delete own 3d_model files'.
  $permissions['delete own 3d_model files'] = array(
    'name' => 'delete own 3d_model files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own application content'.
  $permissions['delete own application content'] = array(
    'name' => 'delete own application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own applicationdomain content'.
  $permissions['delete own applicationdomain content'] = array(
    'name' => 'delete own applicationdomain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own applicationlanding content'.
  $permissions['delete own applicationlanding content'] = array(
    'name' => 'delete own applicationlanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own audio files'.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own capabilitieslanding content'.
  $permissions['delete own capabilitieslanding content'] = array(
    'name' => 'delete own capabilitieslanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own capability content'.
  $permissions['delete own capability content'] = array(
    'name' => 'delete own capability content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own capabilitydomain content'.
  $permissions['delete own capabilitydomain content'] = array(
    'name' => 'delete own capabilitydomain content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own category content'.
  $permissions['delete own category content'] = array(
    'name' => 'delete own category content',
    'roles' => array(
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own document files'.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own faq content'.
  $permissions['delete own faq content'] = array(
    'name' => 'delete own faq content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own homepage content'.
  $permissions['delete own homepage content'] = array(
    'name' => 'delete own homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own image files'.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own ipaper files'.
  $permissions['delete own ipaper files'] = array(
    'name' => 'delete own ipaper files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own news content'.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own product content'.
  $permissions['delete own product content'] = array(
    'name' => 'delete own product content',
    'roles' => array(
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own productlanding content'.
  $permissions['delete own productlanding content'] = array(
    'name' => 'delete own productlanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own productrange content'.
  $permissions['delete own productrange content'] = array(
    'name' => 'delete own productrange content',
    'roles' => array(
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own subcategory content'.
  $permissions['delete own subcategory content'] = array(
    'name' => 'delete own subcategory content',
    'roles' => array(
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tool content'.
  $permissions['delete own tool content'] = array(
    'name' => 'delete own tool content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own video files'.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'delete product content on assigned domains'.
  $permissions['delete product content on assigned domains'] = array(
    'name' => 'delete product content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete productlanding content on assigned domains'.
  $permissions['delete productlanding content on assigned domains'] = array(
    'name' => 'delete productlanding content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete productrange content on assigned domains'.
  $permissions['delete productrange content on assigned domains'] = array(
    'name' => 'delete productrange content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_manager' => 'resource_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete subcategory content on assigned domains'.
  $permissions['delete subcategory content on assigned domains'] = array(
    'name' => 'delete subcategory content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete tool content on assigned domains'.
  $permissions['delete tool content on assigned domains'] = array(
    'name' => 'delete tool content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'delete webform content on assigned domains'.
  $permissions['delete webform content on assigned domains'] = array(
    'name' => 'delete webform content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'distributors settings'.
  $permissions['distributors settings'] = array(
    'name' => 'distributors settings',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'souriau_distributor',
  );

  // Exported permission: 'download any 3d_model files'.
  $permissions['download any 3d_model files'] = array(
    'name' => 'download any 3d_model files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any audio files'.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any document files'.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any image files'.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any ipaper files'.
  $permissions['download any ipaper files'] = array(
    'name' => 'download any ipaper files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download any video files'.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own 3d_model files'.
  $permissions['download own 3d_model files'] = array(
    'name' => 'download own 3d_model files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own audio files'.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own document files'.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own image files'.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own ipaper files'.
  $permissions['download own ipaper files'] = array(
    'name' => 'download own ipaper files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'download own video files'.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'eck add advice advice entities'.
  $permissions['eck add advice advice entities'] = array(
    'name' => 'eck add advice advice entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add advice bundles'.
  $permissions['eck add advice bundles'] = array(
    'name' => 'eck add advice bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add bundles'.
  $permissions['eck add bundles'] = array(
    'name' => 'eck add bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add distributor bundles'.
  $permissions['eck add distributor bundles'] = array(
    'name' => 'eck add distributor bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add distributor distributor entities'.
  $permissions['eck add distributor distributor entities'] = array(
    'name' => 'eck add distributor distributor entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entities'.
  $permissions['eck add entities'] = array(
    'name' => 'eck add entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entity types'.
  $permissions['eck add entity types'] = array(
    'name' => 'eck add entity types',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add project bundles'.
  $permissions['eck add project bundles'] = array(
    'name' => 'eck add project bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add project project entities'.
  $permissions['eck add project project entities'] = array(
    'name' => 'eck add project project entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer advice advice entities'.
  $permissions['eck administer advice advice entities'] = array(
    'name' => 'eck administer advice advice entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer advice bundles'.
  $permissions['eck administer advice bundles'] = array(
    'name' => 'eck administer advice bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer bundles'.
  $permissions['eck administer bundles'] = array(
    'name' => 'eck administer bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer distributor bundles'.
  $permissions['eck administer distributor bundles'] = array(
    'name' => 'eck administer distributor bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer distributor distributor entities'.
  $permissions['eck administer distributor distributor entities'] = array(
    'name' => 'eck administer distributor distributor entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entities'.
  $permissions['eck administer entities'] = array(
    'name' => 'eck administer entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entity types'.
  $permissions['eck administer entity types'] = array(
    'name' => 'eck administer entity types',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer project bundles'.
  $permissions['eck administer project bundles'] = array(
    'name' => 'eck administer project bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer project project entities'.
  $permissions['eck administer project project entities'] = array(
    'name' => 'eck administer project project entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete advice advice entities'.
  $permissions['eck delete advice advice entities'] = array(
    'name' => 'eck delete advice advice entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete advice bundles'.
  $permissions['eck delete advice bundles'] = array(
    'name' => 'eck delete advice bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete bundles'.
  $permissions['eck delete bundles'] = array(
    'name' => 'eck delete bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete distributor bundles'.
  $permissions['eck delete distributor bundles'] = array(
    'name' => 'eck delete distributor bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete distributor distributor entities'.
  $permissions['eck delete distributor distributor entities'] = array(
    'name' => 'eck delete distributor distributor entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entities'.
  $permissions['eck delete entities'] = array(
    'name' => 'eck delete entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entity types'.
  $permissions['eck delete entity types'] = array(
    'name' => 'eck delete entity types',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete project bundles'.
  $permissions['eck delete project bundles'] = array(
    'name' => 'eck delete project bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete project project entities'.
  $permissions['eck delete project project entities'] = array(
    'name' => 'eck delete project project entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit advice advice entities'.
  $permissions['eck edit advice advice entities'] = array(
    'name' => 'eck edit advice advice entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit advice bundles'.
  $permissions['eck edit advice bundles'] = array(
    'name' => 'eck edit advice bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit bundles'.
  $permissions['eck edit bundles'] = array(
    'name' => 'eck edit bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit distributor bundles'.
  $permissions['eck edit distributor bundles'] = array(
    'name' => 'eck edit distributor bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit distributor distributor entities'.
  $permissions['eck edit distributor distributor entities'] = array(
    'name' => 'eck edit distributor distributor entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entities'.
  $permissions['eck edit entities'] = array(
    'name' => 'eck edit entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entity types'.
  $permissions['eck edit entity types'] = array(
    'name' => 'eck edit entity types',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit project bundles'.
  $permissions['eck edit project bundles'] = array(
    'name' => 'eck edit project bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit project project entities'.
  $permissions['eck edit project project entities'] = array(
    'name' => 'eck edit project project entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list advice advice entities'.
  $permissions['eck list advice advice entities'] = array(
    'name' => 'eck list advice advice entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list advice bundles'.
  $permissions['eck list advice bundles'] = array(
    'name' => 'eck list advice bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list bundles'.
  $permissions['eck list bundles'] = array(
    'name' => 'eck list bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list distributor bundles'.
  $permissions['eck list distributor bundles'] = array(
    'name' => 'eck list distributor bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list distributor distributor entities'.
  $permissions['eck list distributor distributor entities'] = array(
    'name' => 'eck list distributor distributor entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entities'.
  $permissions['eck list entities'] = array(
    'name' => 'eck list entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entity types'.
  $permissions['eck list entity types'] = array(
    'name' => 'eck list entity types',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list project bundles'.
  $permissions['eck list project bundles'] = array(
    'name' => 'eck list project bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list project project entities'.
  $permissions['eck list project project entities'] = array(
    'name' => 'eck list project project entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view advice advice entities'.
  $permissions['eck view advice advice entities'] = array(
    'name' => 'eck view advice advice entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view advice bundles'.
  $permissions['eck view advice bundles'] = array(
    'name' => 'eck view advice bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view distributor bundles'.
  $permissions['eck view distributor bundles'] = array(
    'name' => 'eck view distributor bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view distributor distributor entities'.
  $permissions['eck view distributor distributor entities'] = array(
    'name' => 'eck view distributor distributor entities',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view entities'.
  $permissions['eck view entities'] = array(
    'name' => 'eck view entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view project bundles'.
  $permissions['eck view project bundles'] = array(
    'name' => 'eck view project bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view project project entities'.
  $permissions['eck view project project entities'] = array(
    'name' => 'eck view project project entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'edit all meta fields'.
  $permissions['edit all meta fields'] = array(
    'name' => 'edit all meta fields',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'souriau_common',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any 3d_model files'.
  $permissions['edit any 3d_model files'] = array(
    'name' => 'edit any 3d_model files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any application content'.
  $permissions['edit any application content'] = array(
    'name' => 'edit any application content',
    'roles' => array(
      'administrator' => 'administrator',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any applicationdomain content'.
  $permissions['edit any applicationdomain content'] = array(
    'name' => 'edit any applicationdomain content',
    'roles' => array(
      'administrator' => 'administrator',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any applicationlanding content'.
  $permissions['edit any applicationlanding content'] = array(
    'name' => 'edit any applicationlanding content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any audio files'.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any capabilitieslanding content'.
  $permissions['edit any capabilitieslanding content'] = array(
    'name' => 'edit any capabilitieslanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any capability content'.
  $permissions['edit any capability content'] = array(
    'name' => 'edit any capability content',
    'roles' => array(
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any capabilitydomain content'.
  $permissions['edit any capabilitydomain content'] = array(
    'name' => 'edit any capabilitydomain content',
    'roles' => array(
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any category content'.
  $permissions['edit any category content'] = array(
    'name' => 'edit any category content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any commerce_customer_profile entity'.
  $permissions['edit any commerce_customer_profile entity'] = array(
    'name' => 'edit any commerce_customer_profile entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_customer_profile entity of bundle billing'.
  $permissions['edit any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle billing',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_customer_profile entity of bundle shipping'.
  $permissions['edit any commerce_customer_profile entity of bundle shipping'] = array(
    'name' => 'edit any commerce_customer_profile entity of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit any commerce_order entity'.
  $permissions['edit any commerce_order entity'] = array(
    'name' => 'edit any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'customer_service' => 'customer_service',
      'sample_manager' => 'sample_manager',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle commerce_order'.
  $permissions['edit any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'edit any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_order entity of bundle samples_order'.
  $permissions['edit any commerce_order entity of bundle samples_order'] = array(
    'name' => 'edit any commerce_order entity of bundle samples_order',
    'roles' => array(
      'administrator' => 'administrator',
      'sample_manager' => 'sample_manager',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit any commerce_product entity'.
  $permissions['edit any commerce_product entity'] = array(
    'name' => 'edit any commerce_product entity',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any commerce_product entity of bundle sku'.
  $permissions['edit any commerce_product entity of bundle sku'] = array(
    'name' => 'edit any commerce_product entity of bundle sku',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit any document files'.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any faq content'.
  $permissions['edit any faq content'] = array(
    'name' => 'edit any faq content',
    'roles' => array(
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any homepage content'.
  $permissions['edit any homepage content'] = array(
    'name' => 'edit any homepage content',
    'roles' => array(
      'home_page_update' => 'home_page_update',
      'product_suggessions_editor' => 'product_suggessions_editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any image files'.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any ipaper files'.
  $permissions['edit any ipaper files'] = array(
    'name' => 'edit any ipaper files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any news content'.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any product content'.
  $permissions['edit any product content'] = array(
    'name' => 'edit any product content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any productlanding content'.
  $permissions['edit any productlanding content'] = array(
    'name' => 'edit any productlanding content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any productrange content'.
  $permissions['edit any productrange content'] = array(
    'name' => 'edit any productrange content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any subcategory content'.
  $permissions['edit any subcategory content'] = array(
    'name' => 'edit any subcategory content',
    'roles' => array(
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tool content'.
  $permissions['edit any tool content'] = array(
    'name' => 'edit any tool content',
    'roles' => array(
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video files'.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit domain content'.
  $permissions['edit domain content'] = array(
    'name' => 'edit domain content',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'edit meta tag: description'.
  $permissions['edit meta tag: description'] = array(
    'name' => 'edit meta tag: description',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'edit node original values'.
  $permissions['edit node original values'] = array(
    'name' => 'edit node original values',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'edit node translation shared fields'.
  $permissions['edit node translation shared fields'] = array(
    'name' => 'edit node translation shared fields',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'edit original values'.
  $permissions['edit original values'] = array(
    'name' => 'edit original values',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'edit own 3d_model files'.
  $permissions['edit own 3d_model files'] = array(
    'name' => 'edit own 3d_model files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own application content'.
  $permissions['edit own application content'] = array(
    'name' => 'edit own application content',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'global_contributor' => 'global_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own applicationdomain content'.
  $permissions['edit own applicationdomain content'] = array(
    'name' => 'edit own applicationdomain content',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'global_contributor' => 'global_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own applicationlanding content'.
  $permissions['edit own applicationlanding content'] = array(
    'name' => 'edit own applicationlanding content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own audio files'.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own capabilitieslanding content'.
  $permissions['edit own capabilitieslanding content'] = array(
    'name' => 'edit own capabilitieslanding content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own capability content'.
  $permissions['edit own capability content'] = array(
    'name' => 'edit own capability content',
    'roles' => array(
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own capabilitydomain content'.
  $permissions['edit own capabilitydomain content'] = array(
    'name' => 'edit own capabilitydomain content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own category content'.
  $permissions['edit own category content'] = array(
    'name' => 'edit own category content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'resource_contributor' => 'resource_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own commerce_customer_profile entities'.
  $permissions['edit own commerce_customer_profile entities'] = array(
    'name' => 'edit own commerce_customer_profile entities',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_customer_profile entities of bundle billing'.
  $permissions['edit own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle billing',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_customer_profile entities of bundle shipping'.
  $permissions['edit own commerce_customer_profile entities of bundle shipping'] = array(
    'name' => 'edit own commerce_customer_profile entities of bundle shipping',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'edit own commerce_order entities'.
  $permissions['edit own commerce_order entities'] = array(
    'name' => 'edit own commerce_order entities',
    'roles' => array(
      'sample_manager' => 'sample_manager',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle commerce_order'.
  $permissions['edit own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'edit own commerce_order entities of bundle commerce_order',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_order entities of bundle samples_order'.
  $permissions['edit own commerce_order entities of bundle samples_order'] = array(
    'name' => 'edit own commerce_order entities of bundle samples_order',
    'roles' => array(
      'sample_manager' => 'sample_manager',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'edit own commerce_product entities'.
  $permissions['edit own commerce_product entities'] = array(
    'name' => 'edit own commerce_product entities',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own commerce_product entities of bundle sku'.
  $permissions['edit own commerce_product entities of bundle sku'] = array(
    'name' => 'edit own commerce_product entities of bundle sku',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'edit own document files'.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own faq content'.
  $permissions['edit own faq content'] = array(
    'name' => 'edit own faq content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own homepage content'.
  $permissions['edit own homepage content'] = array(
    'name' => 'edit own homepage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own image files'.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own ipaper files'.
  $permissions['edit own ipaper files'] = array(
    'name' => 'edit own ipaper files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own news content'.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own product content'.
  $permissions['edit own product content'] = array(
    'name' => 'edit own product content',
    'roles' => array(
      'resource_contributor' => 'resource_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own productlanding content'.
  $permissions['edit own productlanding content'] = array(
    'name' => 'edit own productlanding content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own productrange content'.
  $permissions['edit own productrange content'] = array(
    'name' => 'edit own productrange content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own subcategory content'.
  $permissions['edit own subcategory content'] = array(
    'name' => 'edit own subcategory content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'resource_contributor' => 'resource_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tool content'.
  $permissions['edit own tool content'] = array(
    'name' => 'edit own tool content',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video files'.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(),
    'module' => 'webform',
  );

  // Exported permission: 'edit production editions'.
  $permissions['edit production editions'] = array(
    'name' => 'edit production editions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'edit taxonomy_term original values'.
  $permissions['edit taxonomy_term original values'] = array(
    'name' => 'edit taxonomy_term original values',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'edit taxonomy_term translation shared fields'.
  $permissions['edit taxonomy_term translation shared fields'] = array(
    'name' => 'edit taxonomy_term translation shared fields',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'edit translation shared fields'.
  $permissions['edit translation shared fields'] = array(
    'name' => 'edit translation shared fields',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'edit user roles'.
  $permissions['edit user roles'] = array(
    'name' => 'edit user roles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backoffice_extras',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'execute auto_entitylabel_entity_update_action'.
  $permissions['execute auto_entitylabel_entity_update_action'] = array(
    'name' => 'execute auto_entitylabel_entity_update_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute clone_action_clone'.
  $permissions['execute clone_action_clone'] = array(
    'name' => 'execute clone_action_clone',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute draft_moderation_copy_original_to_translation_action'.
  $permissions['execute draft_moderation_copy_original_to_translation_action'] = array(
    'name' => 'execute draft_moderation_copy_original_to_translation_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute draft_moderation_publish_action'.
  $permissions['execute draft_moderation_publish_action'] = array(
    'name' => 'execute draft_moderation_publish_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute draft_moderation_unpublish_action'.
  $permissions['execute draft_moderation_unpublish_action'] = array(
    'name' => 'execute draft_moderation_unpublish_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute file_admin_publish_action'.
  $permissions['execute file_admin_publish_action'] = array(
    'name' => 'execute file_admin_publish_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute file_admin_unpublish_action'.
  $permissions['execute file_admin_unpublish_action'] = array(
    'name' => 'execute file_admin_unpublish_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute mailchimp_lists_add_to_segment_action'.
  $permissions['execute mailchimp_lists_add_to_segment_action'] = array(
    'name' => 'execute mailchimp_lists_add_to_segment_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_assign_owner_action'.
  $permissions['execute node_assign_owner_action'] = array(
    'name' => 'execute node_assign_owner_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_sticky_action'.
  $permissions['execute node_make_sticky_action'] = array(
    'name' => 'execute node_make_sticky_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_make_unsticky_action'.
  $permissions['execute node_make_unsticky_action'] = array(
    'name' => 'execute node_make_unsticky_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_promote_action'.
  $permissions['execute node_promote_action'] = array(
    'name' => 'execute node_promote_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_publish_action'.
  $permissions['execute node_publish_action'] = array(
    'name' => 'execute node_publish_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_save_action'.
  $permissions['execute node_save_action'] = array(
    'name' => 'execute node_save_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpromote_action'.
  $permissions['execute node_unpromote_action'] = array(
    'name' => 'execute node_unpromote_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_action'.
  $permissions['execute node_unpublish_action'] = array(
    'name' => 'execute node_unpublish_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute node_unpublish_by_keyword_action'.
  $permissions['execute node_unpublish_by_keyword_action'] = array(
    'name' => 'execute node_unpublish_by_keyword_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_file_update_action'.
  $permissions['execute pathauto_file_update_action'] = array(
    'name' => 'execute pathauto_file_update_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_node_update_action'.
  $permissions['execute pathauto_node_update_action'] = array(
    'name' => 'execute pathauto_node_update_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_taxonomy_term_update_action'.
  $permissions['execute pathauto_taxonomy_term_update_action'] = array(
    'name' => 'execute pathauto_taxonomy_term_update_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute pathauto_user_update_action'.
  $permissions['execute pathauto_user_update_action'] = array(
    'name' => 'execute pathauto_user_update_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute souriau_common_commerce_product_clone'.
  $permissions['execute souriau_common_commerce_product_clone'] = array(
    'name' => 'execute souriau_common_commerce_product_clone',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_block_ip_action'.
  $permissions['execute system_block_ip_action'] = array(
    'name' => 'execute system_block_ip_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_goto_action'.
  $permissions['execute system_goto_action'] = array(
    'name' => 'execute system_goto_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_message_action'.
  $permissions['execute system_message_action'] = array(
    'name' => 'execute system_message_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute system_send_email_action'.
  $permissions['execute system_send_email_action'] = array(
    'name' => 'execute system_send_email_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute user_block_user_action'.
  $permissions['execute user_block_user_action'] = array(
    'name' => 'execute user_block_user_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_archive_action'.
  $permissions['execute views_bulk_operations_archive_action'] = array(
    'name' => 'execute views_bulk_operations_archive_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_argument_selector_action'.
  $permissions['execute views_bulk_operations_argument_selector_action'] = array(
    'name' => 'execute views_bulk_operations_argument_selector_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_item'.
  $permissions['execute views_bulk_operations_delete_item'] = array(
    'name' => 'execute views_bulk_operations_delete_item',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'news_tags_manager' => 'news_tags_manager',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_delete_revision'.
  $permissions['execute views_bulk_operations_delete_revision'] = array(
    'name' => 'execute views_bulk_operations_delete_revision',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_modify_action'.
  $permissions['execute views_bulk_operations_modify_action'] = array(
    'name' => 'execute views_bulk_operations_modify_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_script_action'.
  $permissions['execute views_bulk_operations_script_action'] = array(
    'name' => 'execute views_bulk_operations_script_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_cancel_action'.
  $permissions['execute views_bulk_operations_user_cancel_action'] = array(
    'name' => 'execute views_bulk_operations_user_cancel_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'execute views_bulk_operations_user_roles_action'.
  $permissions['execute views_bulk_operations_user_roles_action'] = array(
    'name' => 'execute views_bulk_operations_user_roles_action',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'actions_permissions',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'import souriau_master_file_product_importer feeds'.
  $permissions['import souriau_master_file_product_importer feeds'] = array(
    'name' => 'import souriau_master_file_product_importer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import souriau_master_file_sku_importer feeds'.
  $permissions['import souriau_master_file_sku_importer feeds'] = array(
    'name' => 'import souriau_master_file_sku_importer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'manage advice properties'.
  $permissions['manage advice properties'] = array(
    'name' => 'manage advice properties',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'manage distributor properties'.
  $permissions['manage distributor properties'] = array(
    'name' => 'manage distributor properties',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'manage project properties'.
  $permissions['manage project properties'] = array(
    'name' => 'manage project properties',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'master-file management'.
  $permissions['master-file management'] = array(
    'name' => 'master-file management',
    'roles' => array(
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'souriau_master_file_import',
  );

  // Exported permission: 'moderate translations'.
  $permissions['moderate translations'] = array(
    'name' => 'moderate translations',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish application to production edition'.
  $permissions['publish application to production edition'] = array(
    'name' => 'publish application to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish applicationdomain to production edition'.
  $permissions['publish applicationdomain to production edition'] = array(
    'name' => 'publish applicationdomain to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish applicationlanding to production edition'.
  $permissions['publish applicationlanding to production edition'] = array(
    'name' => 'publish applicationlanding to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish capabilitieslanding to production edition'.
  $permissions['publish capabilitieslanding to production edition'] = array(
    'name' => 'publish capabilitieslanding to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish capability to production edition'.
  $permissions['publish capability to production edition'] = array(
    'name' => 'publish capability to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish capabilitydomain to production edition'.
  $permissions['publish capabilitydomain to production edition'] = array(
    'name' => 'publish capabilitydomain to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish category to production edition'.
  $permissions['publish category to production edition'] = array(
    'name' => 'publish category to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish faq to production edition'.
  $permissions['publish faq to production edition'] = array(
    'name' => 'publish faq to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish files'.
  $permissions['publish files'] = array(
    'name' => 'publish files',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_admin',
  );

  // Exported permission: 'publish from assigned domain'.
  $permissions['publish from assigned domain'] = array(
    'name' => 'publish from assigned domain',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'publish from default domain'.
  $permissions['publish from default domain'] = array(
    'name' => 'publish from default domain',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'publish homepage to production edition'.
  $permissions['publish homepage to production edition'] = array(
    'name' => 'publish homepage to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish news to production edition'.
  $permissions['publish news to production edition'] = array(
    'name' => 'publish news to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish productlanding to production edition'.
  $permissions['publish productlanding to production edition'] = array(
    'name' => 'publish productlanding to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish productrange to production edition'.
  $permissions['publish productrange to production edition'] = array(
    'name' => 'publish productrange to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish subcategory to production edition'.
  $permissions['publish subcategory to production edition'] = array(
    'name' => 'publish subcategory to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish to any assigned domain'.
  $permissions['publish to any assigned domain'] = array(
    'name' => 'publish to any assigned domain',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'publish to production edition'.
  $permissions['publish to production edition'] = array(
    'name' => 'publish to production edition',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_publisher' => 'global_publisher',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'publish tool to production edition'.
  $permissions['publish tool to production edition'] = array(
    'name' => 'publish tool to production edition',
    'roles' => array(
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'resource_manager' => 'resource_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'save node for tc moderation'.
  $permissions['save node for tc moderation'] = array(
    'name' => 'save node for tc moderation',
    'roles' => array(
      'administrator' => 'administrator',
      'global_publisher' => 'global_publisher',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'set domain access'.
  $permissions['set domain access'] = array(
    'name' => 'set domain access',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'show vote results'.
  $permissions['show vote results'] = array(
    'name' => 'show vote results',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'advpoll',
  );

  // Exported permission: 'souriau_eco_erp_mouser_orders'.
  $permissions['souriau_eco_erp_mouser_orders'] = array(
    'name' => 'souriau_eco_erp_mouser_orders',
    'roles' => array(
      'sample_manager' => 'sample_manager',
    ),
    'module' => 'souriau_eco_erp',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate to any language'.
  $permissions['translate to any language'] = array(
    'name' => 'translate to any language',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'domain_locale',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unlock souriau_master_file_product_importer feeds'.
  $permissions['unlock souriau_master_file_product_importer feeds'] = array(
    'name' => 'unlock souriau_master_file_product_importer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock souriau_master_file_sku_importer feeds'.
  $permissions['unlock souriau_master_file_sku_importer feeds'] = array(
    'name' => 'unlock souriau_master_file_sku_importer feeds',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unpublish production editions'.
  $permissions['unpublish production editions'] = array(
    'name' => 'unpublish production editions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'update application content on assigned domains'.
  $permissions['update application content on assigned domains'] = array(
    'name' => 'update application content on assigned domains',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update applicationdomain content on assigned domains'.
  $permissions['update applicationdomain content on assigned domains'] = array(
    'name' => 'update applicationdomain content on assigned domains',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update applicationlanding content on assigned domains'.
  $permissions['update applicationlanding content on assigned domains'] = array(
    'name' => 'update applicationlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update capabilitieslanding content on assigned domains'.
  $permissions['update capabilitieslanding content on assigned domains'] = array(
    'name' => 'update capabilitieslanding content on assigned domains',
    'roles' => array(
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update capability content on assigned domains'.
  $permissions['update capability content on assigned domains'] = array(
    'name' => 'update capability content on assigned domains',
    'roles' => array(
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update capabilitydomain content on assigned domains'.
  $permissions['update capabilitydomain content on assigned domains'] = array(
    'name' => 'update capabilitydomain content on assigned domains',
    'roles' => array(
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update category content on assigned domains'.
  $permissions['update category content on assigned domains'] = array(
    'name' => 'update category content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update cms_page content on assigned domains'.
  $permissions['update cms_page content on assigned domains'] = array(
    'name' => 'update cms_page content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update faq content on assigned domains'.
  $permissions['update faq content on assigned domains'] = array(
    'name' => 'update faq content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update genericlanding content on assigned domains'.
  $permissions['update genericlanding content on assigned domains'] = array(
    'name' => 'update genericlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update homepage content on assigned domains'.
  $permissions['update homepage content on assigned domains'] = array(
    'name' => 'update homepage content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update news content on assigned domains'.
  $permissions['update news content on assigned domains'] = array(
    'name' => 'update news content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update news_landing content on assigned domains'.
  $permissions['update news_landing content on assigned domains'] = array(
    'name' => 'update news_landing content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update product content on assigned domains'.
  $permissions['update product content on assigned domains'] = array(
    'name' => 'update product content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'update productlanding content on assigned domains'.
  $permissions['update productlanding content on assigned domains'] = array(
    'name' => 'update productlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update productrange content on assigned domains'.
  $permissions['update productrange content on assigned domains'] = array(
    'name' => 'update productrange content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'product_contributor' => 'product_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update productrangehub content on assigned domains'.
  $permissions['update productrangehub content on assigned domains'] = array(
    'name' => 'update productrangehub content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
      'product_contributor' => 'product_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update resource content on assigned domains'.
  $permissions['update resource content on assigned domains'] = array(
    'name' => 'update resource content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update subcategory content on assigned domains'.
  $permissions['update subcategory content on assigned domains'] = array(
    'name' => 'update subcategory content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update tool content on assigned domains'.
  $permissions['update tool content on assigned domains'] = array(
    'name' => 'update tool content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update toolkitlanding content on assigned domains'.
  $permissions['update toolkitlanding content on assigned domains'] = array(
    'name' => 'update toolkitlanding content on assigned domains',
    'roles' => array(
      'global_contributor' => 'global_contributor',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'update webform content on assigned domains'.
  $permissions['update webform content on assigned domains'] = array(
    'name' => 'update webform content on assigned domains',
    'roles' => array(),
    'module' => 'domain',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(),
    'module' => 'page_manager',
  );

  // Exported permission: 'view any commerce_customer_profile entity'.
  $permissions['view any commerce_customer_profile entity'] = array(
    'name' => 'view any commerce_customer_profile entity',
    'roles' => array(
      'administrator' => 'administrator',
      'sample_manager' => 'sample_manager',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_customer_profile entity of bundle billing'.
  $permissions['view any commerce_customer_profile entity of bundle billing'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle billing',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_customer_profile entity of bundle shipping'.
  $permissions['view any commerce_customer_profile entity of bundle shipping'] = array(
    'name' => 'view any commerce_customer_profile entity of bundle shipping',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view any commerce_order entity'.
  $permissions['view any commerce_order entity'] = array(
    'name' => 'view any commerce_order entity',
    'roles' => array(
      'administrator' => 'administrator',
      'customer_service' => 'customer_service',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle commerce_order'.
  $permissions['view any commerce_order entity of bundle commerce_order'] = array(
    'name' => 'view any commerce_order entity of bundle commerce_order',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_order entity of bundle samples_order'.
  $permissions['view any commerce_order entity of bundle samples_order'] = array(
    'name' => 'view any commerce_order entity of bundle samples_order',
    'roles' => array(
      'administrator' => 'administrator',
      'sample_manager' => 'sample_manager',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view any commerce_product entity'.
  $permissions['view any commerce_product entity'] = array(
    'name' => 'view any commerce_product entity',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any commerce_product entity of bundle sku'.
  $permissions['view any commerce_product entity of bundle sku'] = array(
    'name' => 'view any commerce_product entity of bundle sku',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view any unpublished files'.
  $permissions['view any unpublished files'] = array(
    'name' => 'view any unpublished files',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_admin',
  );

  // Exported permission: 'view draft editions'.
  $permissions['view draft editions'] = array(
    'name' => 'view draft editions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'view files'.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'client' => 'client',
      'customer_service' => 'customer_service',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own commerce_customer_profile entities'.
  $permissions['view own commerce_customer_profile entities'] = array(
    'name' => 'view own commerce_customer_profile entities',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_customer_profile entities of bundle billing'.
  $permissions['view own commerce_customer_profile entities of bundle billing'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle billing',
    'roles' => array(),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_customer_profile entities of bundle shipping'.
  $permissions['view own commerce_customer_profile entities of bundle shipping'] = array(
    'name' => 'view own commerce_customer_profile entities of bundle shipping',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_customer',
  );

  // Exported permission: 'view own commerce_order entities'.
  $permissions['view own commerce_order entities'] = array(
    'name' => 'view own commerce_order entities',
    'roles' => array(),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle commerce_order'.
  $permissions['view own commerce_order entities of bundle commerce_order'] = array(
    'name' => 'view own commerce_order entities of bundle commerce_order',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_order entities of bundle samples_order'.
  $permissions['view own commerce_order entities of bundle samples_order'] = array(
    'name' => 'view own commerce_order entities of bundle samples_order',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'commerce_order',
  );

  // Exported permission: 'view own commerce_product entities'.
  $permissions['view own commerce_product entities'] = array(
    'name' => 'view own commerce_product entities',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own commerce_product entities of bundle sku'.
  $permissions['view own commerce_product entities of bundle sku'] = array(
    'name' => 'view own commerce_product entities of bundle sku',
    'roles' => array(),
    'module' => 'commerce_product',
  );

  // Exported permission: 'view own files'.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own private files'.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view own unpublished files'.
  $permissions['view own unpublished files'] = array(
    'name' => 'view own unpublished files',
    'roles' => array(
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'product_contributor' => 'product_contributor',
    ),
    'module' => 'file_admin',
  );

  // Exported permission: 'view private files'.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'customer_service' => 'customer_service',
      'global_contributor' => 'global_contributor',
      'news_tags_manager' => 'news_tags_manager',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'sample_manager' => 'sample_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view unpublished domain content'.
  $permissions['view unpublished domain content'] = array(
    'name' => 'view unpublished domain content',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'domain',
  );

  // Exported permission: 'view unpublished production editions'.
  $permissions['view unpublished production editions'] = array(
    'name' => 'view unpublished production editions',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'application_contributor' => 'application_contributor',
      'capability_contributor' => 'capability_contributor',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'draft_moderation',
  );

  // Exported permission: 'vote on polls'.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      'Webmaster' => 'Webmaster',
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'application_contributor' => 'application_contributor',
      'authenticated user' => 'authenticated user',
      'capability_contributor' => 'capability_contributor',
      'client' => 'client',
      'customer_service' => 'customer_service',
      'global_contributor' => 'global_contributor',
      'global_publisher' => 'global_publisher',
      'product_contributor' => 'product_contributor',
      'resource_contributor' => 'resource_contributor',
      'resource_manager' => 'resource_manager',
      'trade_compliance' => 'trade_compliance',
      'сatalog_manager' => 'сatalog_manager',
    ),
    'module' => 'advpoll',
  );

  return $permissions;
}
