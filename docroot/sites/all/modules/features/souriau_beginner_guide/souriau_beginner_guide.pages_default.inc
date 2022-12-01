<?php
/**
 * @file
 * souriau_beginner_guide.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_beginner_guide_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'beginner_guidance';
  $page->task = 'page';
  $page->admin_title = 'Beginner guidance';
  $page->admin_description = '';
  $page->path = 'get-started';
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
  $handler->name = 'page_beginner_guidance__panel';
  $handler->task = 'page';
  $handler->subtask = 'beginner_guidance';
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
  $display->title = 'Get Started';
  $display->uuid = '1f92c27d-5f66-45f6-a8c4-8c55d7578c39';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7b85a848-5859-42b2-a9e7-8959227d0000';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_get_started';
  $pane->subtype = 'souriau_common_get_started';
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
  $pane->uuid = '7b85a848-5859-42b2-a9e7-8959227d0000';
  $display->content['new-7b85a848-5859-42b2-a9e7-8959227d0000'] = $pane;
  $display->panels['content'][0] = 'new-7b85a848-5859-42b2-a9e7-8959227d0000';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7b85a848-5859-42b2-a9e7-8959227d0000';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['beginner_guidance'] = $page;

  return $pages;

}
