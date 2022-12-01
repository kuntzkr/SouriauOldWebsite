<?php
/**
 * @file
 * souriau_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'front';
  $page->task = 'page';
  $page->admin_title = 'Front';
  $page->admin_description = '';
  $page->path = 'frontpage';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_front__panel';
  $handler->task = 'page';
  $handler->subtask = 'front';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'souriau_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'above' => NULL,
      'header' => NULL,
      'left' => NULL,
      'content' => NULL,
      'right' => NULL,
      'footer' => NULL,
      'below' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dbc9265f-04a2-483e-a2d4-69ba9105308c';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_front__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-26260fec-1de8-4097-a9e9-f005e6905942';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_search';
  $pane->subtype = 'souriau_common_search';
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
  $pane->uuid = '26260fec-1de8-4097-a9e9-f005e6905942';
  $display->content['new-26260fec-1de8-4097-a9e9-f005e6905942'] = $pane;
  $display->panels['content'][0] = 'new-26260fec-1de8-4097-a9e9-f005e6905942';
  $pane = new stdClass();
  $pane->pid = 'new-e02282bc-8f54-4fa2-a4b8-f2059fb046f2';
  $pane->panel = 'content';
  $pane->type = 'content';
  $pane->subtype = 'content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'bundle' => 'home',
    'view_mode' => 'full',
    'context' => array(
      0 => 'empty',
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
  $pane->uuid = 'e02282bc-8f54-4fa2-a4b8-f2059fb046f2';
  $display->content['new-e02282bc-8f54-4fa2-a4b8-f2059fb046f2'] = $pane;
  $display->panels['content'][1] = 'new-e02282bc-8f54-4fa2-a4b8-f2059fb046f2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e02282bc-8f54-4fa2-a4b8-f2059fb046f2';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['front'] = $page;

  return $pages;

}
