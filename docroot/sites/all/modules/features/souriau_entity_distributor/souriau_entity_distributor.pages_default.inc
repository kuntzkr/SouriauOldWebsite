<?php

/**
 * @file
 * souriau_entity_distributor.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_entity_distributor_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'where_to_buy';
  $page->task = 'page';
  $page->admin_title = 'Where to buy';
  $page->admin_description = '';
  $page->path = 'our-distributors';
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
  $handler->name = 'page_where_to_buy__panel';
  $handler->task = 'page';
  $handler->subtask = 'where_to_buy';
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
  );
  $display->cache = array();
  $display->title = 'Our distributors';
  $display->uuid = 'a73666b9-b4a4-4ca0-87ba-94bedd88b70a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_where_to_buy__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-61a17028-7231-4362-b0a1-873e0bbcabae';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'distributors';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->uuid = '61a17028-7231-4362-b0a1-873e0bbcabae';
  $display->content['new-61a17028-7231-4362-b0a1-873e0bbcabae'] = $pane;
  $display->panels['content'][0] = 'new-61a17028-7231-4362-b0a1-873e0bbcabae';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-61a17028-7231-4362-b0a1-873e0bbcabae';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['where_to_buy'] = $page;

  return $pages;

}
