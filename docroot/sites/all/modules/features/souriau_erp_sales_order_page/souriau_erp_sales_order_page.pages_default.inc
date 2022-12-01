<?php
/**
 * @file
 * souriau_erp_sales_order_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_erp_sales_order_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_orders';
  $page->task = 'page';
  $page->admin_title = 'User orders';
  $page->admin_description = '';
  $page->path = 'user/%user/erp-orders';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'souriau_eco_access_orders',
        'settings' => NULL,
        'context' => array(
          0 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
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
  $handler->name = 'page_user_orders__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_orders';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'User orders',
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
  $display->title = 'My orders';
  $display->uuid = '549e3fe7-49c6-42cb-b049-5e938c4473af';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9c2cf285-e019-40c7-be80-dc58fcc26f27';
  $pane->panel = 'content';
  $pane->type = 'souriau_eco_user_orders';
  $pane->subtype = 'souriau_eco_user_orders';
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
  $pane->uuid = '9c2cf285-e019-40c7-be80-dc58fcc26f27';
  $display->content['new-9c2cf285-e019-40c7-be80-dc58fcc26f27'] = $pane;
  $display->panels['content'][0] = 'new-9c2cf285-e019-40c7-be80-dc58fcc26f27';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_orders'] = $page;

  return $pages;

}
