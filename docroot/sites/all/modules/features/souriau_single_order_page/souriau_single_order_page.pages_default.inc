<?php
/**
 * @file
 * souriau_single_order_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_single_order_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'single_order';
  $page->task = 'page';
  $page->admin_title = 'Single order';
  $page->admin_description = '';
  $page->path = 'user/%user/erp-orders/%erp-order';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'souriau_eco_access_single_order',
        'settings' => NULL,
        'context' => array(
          0 => 'argument_erp_order_1',
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
    'erp-order' => array(
      'id' => 1,
      'identifier' => 'ERP Order',
      'name' => 'erp_order',
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
  $handler->name = 'page_single_order__panel';
  $handler->task = 'page';
  $handler->subtask = 'single_order';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Single Order',
    'no_blocks' => 1,
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
  $display->layout = 'souriau_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Order %erp-order:html_safe';
  $display->uuid = 'a16c7412-c77e-436c-a0a4-2c5c7b25cef2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7d30c4b5-9800-477e-af54-3b70b61a0215';
  $pane->panel = 'content';
  $pane->type = 'souriau_eco_user_single_order';
  $pane->subtype = 'souriau_eco_user_single_order';
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
  $pane->uuid = '7d30c4b5-9800-477e-af54-3b70b61a0215';
  $display->content['new-7d30c4b5-9800-477e-af54-3b70b61a0215'] = $pane;
  $display->panels['content'][0] = 'new-7d30c4b5-9800-477e-af54-3b70b61a0215';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['single_order'] = $page;

  return $pages;

}
