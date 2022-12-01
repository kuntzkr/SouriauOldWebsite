<?php
/**
 * @file
 * souriau_ct_resource.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_ct_resource_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'training_center';
  $page->task = 'page';
  $page->admin_title = 'Video Tutorials';
  $page->admin_description = '';
  $page->path = 'video-tutorials';
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
  $handler->name = 'page_training_center__panel';
  $handler->task = 'page';
  $handler->subtask = 'training_center';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
    'content' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Video Tutorials';
  $display->uuid = 'a9177cb0-fbac-4b9b-b30a-7ab13cfa6e80';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-165312b1-699d-4db0-9ac9-0d06a0ab3adc';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_training_resource_landing';
  $pane->subtype = 'souriau_common_training_resource_landing';
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
  $pane->uuid = '165312b1-699d-4db0-9ac9-0d06a0ab3adc';
  $display->content['new-165312b1-699d-4db0-9ac9-0d06a0ab3adc'] = $pane;
  $display->panels['content'][0] = 'new-165312b1-699d-4db0-9ac9-0d06a0ab3adc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['training_center'] = $page;

  return $pages;

}
