<?php
/**
 * @file
 * souriau_search_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_search_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search';
  $page->task = 'page';
  $page->admin_title = 'Search';
  $page->admin_description = '';
  $page->path = 'search/!keyword';
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
  $page->arguments = array(
    'keyword' => array(
      'id' => 1,
      'identifier' => 'search_keyword',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search__panel_context_f6c3c522-0d63-4fb2-8eab-d20ce0561c57';
  $handler->task = 'page';
  $handler->subtask = 'search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
  $display->title = 'Search %keyword:html_safe';
  $display->uuid = '94f41a6a-6c34-4c15-85a2-70ae10c7602b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_search__panel_context_f6c3c522-0d63-4fb2-8eab-d20ce0561c57';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8f6553a1-d17a-4017-864a-e0393825517c';
  $pane->panel = 'content';
  $pane->type = 'views_panes';
  $pane->subtype = 'search-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'items_per_page' => '10',
    'offset' => '0',
    'path' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8f6553a1-d17a-4017-864a-e0393825517c';
  $display->content['new-8f6553a1-d17a-4017-864a-e0393825517c'] = $pane;
  $display->panels['content'][0] = 'new-8f6553a1-d17a-4017-864a-e0393825517c';
  $pane = new stdClass();
  $pane->pid = 'new-c58eba40-57d5-4b1a-aab4-982a8d4dd7bf';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_facets';
  $pane->subtype = 'souriau_common_facets';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c58eba40-57d5-4b1a-aab4-982a8d4dd7bf';
  $display->content['new-c58eba40-57d5-4b1a-aab4-982a8d4dd7bf'] = $pane;
  $display->panels['content'][1] = 'new-c58eba40-57d5-4b1a-aab4-982a8d4dd7bf';
  $pane = new stdClass();
  $pane->pid = 'new-68f7b5d0-cb62-45cf-8d78-d04f3aa40929';
  $pane->panel = 'content';
  $pane->type = 'souriau_search_results';
  $pane->subtype = 'souriau_search_results';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '68f7b5d0-cb62-45cf-8d78-d04f3aa40929';
  $display->content['new-68f7b5d0-cb62-45cf-8d78-d04f3aa40929'] = $pane;
  $display->panels['content'][2] = 'new-68f7b5d0-cb62-45cf-8d78-d04f3aa40929';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search'] = $page;

  return $pages;

}
