<?php
/**
 * @file
 * souriau_training_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_training_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_inquiry';
  $page->task = 'page';
  $page->admin_title = 'Training inquiry';
  $page->admin_description = '';
  $page->path = 'training-inquiry';
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
  $handler->name = 'page_training_inquiry__panel';
  $handler->task = 'page';
  $handler->subtask = 'training_inquiry';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Training inquiry',
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
  $display->title = 'Training inquiry';
  $display->uuid = 'cc17deda-4f55-48e0-b95c-66b851e9f1da';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_training_inquiry__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-939b4541-1750-4e4c-9926-ecaa6b331dad';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_training_inquiry';
  $pane->subtype = 'souriau_common_training_inquiry';
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
  $pane->uuid = '939b4541-1750-4e4c-9926-ecaa6b331dad';
  $display->content['new-939b4541-1750-4e4c-9926-ecaa6b331dad'] = $pane;
  $display->panels['content'][0] = 'new-939b4541-1750-4e4c-9926-ecaa6b331dad';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-939b4541-1750-4e4c-9926-ecaa6b331dad';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_inquiry'] = $page;

  return $pages;

}
