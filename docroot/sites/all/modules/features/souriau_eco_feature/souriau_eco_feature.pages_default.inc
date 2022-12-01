<?php
/**
 * @file
 * souriau_eco_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function souriau_eco_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'cart__http_response_836076e7-fa8c-4e29-ae73-bdc34cb018c4';
  $handler->task = 'cart';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'HTTP response code',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => 'checkout',
    'name' => '',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $export['cart__http_response_836076e7-fa8c-4e29-ae73-bdc34cb018c4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'commerce__panel_context_16c33e82-a103-4ca7-9bc3-49744b386f1f';
  $handler->task = 'commerce';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Checkout cart',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'souriau_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7a24e23f-dfc0-4444-8dde-7719f21d0293';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5aa2f631-80c4-46a1-9110-c990b8240895';
  $pane->panel = 'content';
  $pane->type = 'checkout_steps';
  $pane->subtype = 'checkout_steps';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5aa2f631-80c4-46a1-9110-c990b8240895';
  $display->content['new-5aa2f631-80c4-46a1-9110-c990b8240895'] = $pane;
  $display->panels['content'][0] = 'new-5aa2f631-80c4-46a1-9110-c990b8240895';
  $pane = new stdClass();
  $pane->pid = 'new-e79a3291-612e-4a43-866e-bff63d47c286';
  $pane->panel = 'content';
  $pane->type = 'checkout_form';
  $pane->subtype = 'checkout_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e79a3291-612e-4a43-866e-bff63d47c286';
  $display->content['new-e79a3291-612e-4a43-866e-bff63d47c286'] = $pane;
  $display->panels['content'][1] = 'new-e79a3291-612e-4a43-866e-bff63d47c286';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['commerce__panel_context_16c33e82-a103-4ca7-9bc3-49744b386f1f'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'commerce__panel_context_8a6ab32d-4563-4c36-bc91-75e474c3c44b';
  $handler->task = 'commerce';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Samples Cart',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'context_exists',
          'settings' => array(
            'exists' => '0',
          ),
          'context' => 'argument_commerce_checkout_page_2',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'souriau_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'e8c1ca2a-eb9e-4f4b-882a-5e20dcb7b85a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2e8db7ab-795b-41b2-8153-4a5a2dbb3902';
  $pane->panel = 'content';
  $pane->type = 'checkout_steps';
  $pane->subtype = 'checkout_steps';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2e8db7ab-795b-41b2-8153-4a5a2dbb3902';
  $display->content['new-2e8db7ab-795b-41b2-8153-4a5a2dbb3902'] = $pane;
  $display->panels['content'][0] = 'new-2e8db7ab-795b-41b2-8153-4a5a2dbb3902';
  $pane = new stdClass();
  $pane->pid = 'new-2e59dfae-1eea-4810-8a2f-05fd91244f26';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'commerce_cart_form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '0',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'samples_cart',
    'context' => array(
      0 => 'argument_entity_id:commerce_order_1.order-id',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2e59dfae-1eea-4810-8a2f-05fd91244f26';
  $display->content['new-2e59dfae-1eea-4810-8a2f-05fd91244f26'] = $pane;
  $display->panels['content'][1] = 'new-2e59dfae-1eea-4810-8a2f-05fd91244f26';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['commerce__panel_context_8a6ab32d-4563-4c36-bc91-75e474c3c44b'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_eco_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_sample_order';
  $page->task = 'page';
  $page->admin_title = 'User sample order';
  $page->admin_description = '';
  $page->path = 'user/%user/sample-orders';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user_sample_order__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_sample_order';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Sample order history',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'souriau_main';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Sample Orders';
  $display->uuid = 'd120f44e-6c05-4beb-a4a7-be58338a16b5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fe09113c-ea3d-4e0e-bdef-bbef735374c1';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'user_sample_orders';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page',
    'context' => array(
      0 => 'argument_entity_id:user_1.uid',
    ),
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fe09113c-ea3d-4e0e-bdef-bbef735374c1';
  $display->content['new-fe09113c-ea3d-4e0e-bdef-bbef735374c1'] = $pane;
  $display->panels['content'][0] = 'new-fe09113c-ea3d-4e0e-bdef-bbef735374c1';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fe09113c-ea3d-4e0e-bdef-bbef735374c1';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_sample_order'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_sample_order_details';
  $page->task = 'page';
  $page->admin_title = 'User sample order details';
  $page->admin_description = '';
  $page->path = 'user/%user/sample-orders/%commerce_order';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
    'commerce_order' => array(
      'id' => 1,
      'identifier' => 'Commerce Order: ID',
      'name' => 'entity_id:commerce_order',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_user_sample_order_details__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_sample_order_details';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Sample order details',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'souriau_main';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Sample Order %commerce_order:order-id';
  $display->uuid = '7c62e810-0b93-4447-b25d-f5d8025e1399';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ea601bbd-9e34-4cba-ab1f-30a53ff82c81';
  $pane->panel = 'content';
  $pane->type = 'souriau_eco_sample_order_details';
  $pane->subtype = 'souriau_eco_sample_order_details';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ea601bbd-9e34-4cba-ab1f-30a53ff82c81';
  $display->content['new-ea601bbd-9e34-4cba-ab1f-30a53ff82c81'] = $pane;
  $display->panels['content'][0] = 'new-ea601bbd-9e34-4cba-ab1f-30a53ff82c81';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_sample_order_details'] = $page;

  return $pages;

}
