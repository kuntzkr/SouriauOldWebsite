<?php
/**
 * @file
 * souriau_download_center.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_download_center_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'download_center';
  $page->task = 'page';
  $page->admin_title = 'Download center';
  $page->admin_description = '';
  $page->path = 'download-center';
  $page->access = array(
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
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
  $handler->name = 'page_download_center__panel';
  $handler->task = 'page';
  $handler->subtask = 'download_center';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Download center',
    'no_blocks' => 1,
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
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Download Center';
  $display->uuid = '5d00c8f8-e585-49ea-8258-57cb0a456572';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_download_center__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-6030577b-1a60-40d7-86f3-fd9fd27fe6fc';
  $pane->panel = 'content';
  $pane->type = 'souriau_dc_search';
  $pane->subtype = 'souriau_dc_search';
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
  $pane->uuid = '6030577b-1a60-40d7-86f3-fd9fd27fe6fc';
  $display->content['new-6030577b-1a60-40d7-86f3-fd9fd27fe6fc'] = $pane;
  $display->panels['content'][0] = 'new-6030577b-1a60-40d7-86f3-fd9fd27fe6fc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['download_center'] = $page;

  return $pages;

}
