<?php
/**
 * @file
 * souriau_my_account_landing_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_my_account_landing_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'souriau_my_account_landing';
  $page->task = 'page';
  $page->admin_title = 'Souriau My account Landing';
  $page->admin_description = '';
  $page->path = 'user/space';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_souriau_my_account_landing__panel';
  $handler->task = 'page';
  $handler->subtask = 'souriau_my_account_landing';
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
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
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
  $display->title = 'My account';
  $display->uuid = 'b1af69f4-dbe1-4015-8022-02d3ff603533';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-68ac2f1e-e756-454f-889b-bb6d039613b3';
  $pane->panel = 'content';
  $pane->type = 'souriau_user_landing';
  $pane->subtype = 'souriau_user_landing';
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
  $pane->uuid = '68ac2f1e-e756-454f-889b-bb6d039613b3';
  $display->content['new-68ac2f1e-e756-454f-889b-bb6d039613b3'] = $pane;
  $display->panels['content'][0] = 'new-68ac2f1e-e756-454f-889b-bb6d039613b3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['souriau_my_account_landing'] = $page;

  return $pages;

}
