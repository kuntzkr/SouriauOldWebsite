<?php
/**
 * @file
 * souriau_faq.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_faq_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'souriau_faq';
  $page->task = 'page';
  $page->admin_title = 'Souriau FAQ';
  $page->admin_description = '';
  $page->path = 'faq';
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
  $handler->name = 'page_souriau_faq__panel';
  $handler->task = 'page';
  $handler->subtask = 'souriau_faq';
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
  $display->title = 'FAQ';
  $display->uuid = 'cb245a8e-3e18-4d91-b5da-52799ab7495b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_souriau_faq__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4b1fe092-abdd-44ce-b8c0-367c15491640';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'souriau_query_get_popular_faq';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
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
  $pane->uuid = '4b1fe092-abdd-44ce-b8c0-367c15491640';
  $display->content['new-4b1fe092-abdd-44ce-b8c0-367c15491640'] = $pane;
  $display->panels['content'][0] = 'new-4b1fe092-abdd-44ce-b8c0-367c15491640';
  $pane = new stdClass();
  $pane->pid = 'new-a374ce09-98f5-4074-909e-970f4cdd0cf8';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'souriau_query_get_faq_themes';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a374ce09-98f5-4074-909e-970f4cdd0cf8';
  $display->content['new-a374ce09-98f5-4074-909e-970f4cdd0cf8'] = $pane;
  $display->panels['content'][1] = 'new-a374ce09-98f5-4074-909e-970f4cdd0cf8';
  $pane = new stdClass();
  $pane->pid = 'new-e1469c7d-379d-448e-856e-4d674ef4aac3';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'souriau_query_get_theme_based_faq';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '0',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e1469c7d-379d-448e-856e-4d674ef4aac3';
  $display->content['new-e1469c7d-379d-448e-856e-4d674ef4aac3'] = $pane;
  $display->panels['content'][2] = 'new-e1469c7d-379d-448e-856e-4d674ef4aac3';
  $pane = new stdClass();
  $pane->pid = 'new-b845d0f7-9d53-41d7-bc75-0a6c8eaac2f3';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_faq';
  $pane->subtype = 'souriau_common_faq';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b845d0f7-9d53-41d7-bc75-0a6c8eaac2f3';
  $display->content['new-b845d0f7-9d53-41d7-bc75-0a6c8eaac2f3'] = $pane;
  $display->panels['content'][3] = 'new-b845d0f7-9d53-41d7-bc75-0a6c8eaac2f3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['souriau_faq'] = $page;

  return $pages;

}
