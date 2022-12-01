<?php
/**
 * @file
 * souriau_403_404.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_403_404_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = '403_access_denied';
  $page->task = 'page';
  $page->admin_title = '403 Access Denied';
  $page->admin_description = '';
  $page->path = 'page_403';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_403_access_denied__panel';
  $handler->task = 'page';
  $handler->subtask = '403_access_denied';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => '403 Access Denied',
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
  $display->layout = 'souriau_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Access Denied';
  $display->uuid = '84fa464e-ce26-4c2c-bf5f-dcc1bc0854b6';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a442f20a-5f85-4fda-9861-1cf6b56e8d8d';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_403';
  $pane->subtype = 'souriau_common_403';
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
  $pane->uuid = 'a442f20a-5f85-4fda-9861-1cf6b56e8d8d';
  $display->content['new-a442f20a-5f85-4fda-9861-1cf6b56e8d8d'] = $pane;
  $display->panels['content'][0] = 'new-a442f20a-5f85-4fda-9861-1cf6b56e8d8d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['403_access_denied'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = '404_page_not_found';
  $page->task = 'page';
  $page->admin_title = '404 Page not found';
  $page->admin_description = '';
  $page->path = 'page_404';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_404_page_not_found__panel';
  $handler->task = 'page';
  $handler->subtask = '404_page_not_found';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => '404 Page not found',
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
  $display->layout = 'souriau_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Page not found';
  $display->uuid = '4707352e-1aee-4080-b99b-d01231406f61';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-86ce09c1-5a4d-4729-a92b-f1abcbd3cc5c';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_404';
  $pane->subtype = 'souriau_common_404';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
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
  $pane->uuid = '86ce09c1-5a4d-4729-a92b-f1abcbd3cc5c';
  $display->content['new-86ce09c1-5a4d-4729-a92b-f1abcbd3cc5c'] = $pane;
  $display->panels['content'][0] = 'new-86ce09c1-5a4d-4729-a92b-f1abcbd3cc5c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['404_page_not_found'] = $page;

  return $pages;

}
