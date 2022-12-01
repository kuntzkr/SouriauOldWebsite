<?php
/**
 * @file
 * souriau_ct_postcard.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_ct_postcard_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'did_you_know';
  $page->task = 'page';
  $page->admin_title = 'Did you know';
  $page->admin_description = '';
  $page->path = 'did-you-know';
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
  $handler->name = 'page_did_you_know__panel';
  $handler->task = 'page';
  $handler->subtask = 'did_you_know';
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
  $display->title = 'Did you know?';
  $display->uuid = 'deb73d9e-3c0b-4050-84dc-5c677a25d25b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_did_you_know__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4d44c03a-9b98-4a73-bf1a-12897cb7ecc9';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_did_you_know';
  $pane->subtype = 'souriau_common_did_you_know';
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
  $pane->uuid = '4d44c03a-9b98-4a73-bf1a-12897cb7ecc9';
  $display->content['new-4d44c03a-9b98-4a73-bf1a-12897cb7ecc9'] = $pane;
  $display->panels['content'][0] = 'new-4d44c03a-9b98-4a73-bf1a-12897cb7ecc9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['did_you_know'] = $page;

  return $pages;

}
