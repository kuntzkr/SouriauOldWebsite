<?php
/**
 * @file
 * souriau_my_projects.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_my_projects_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'project_page';
  $page->task = 'page';
  $page->admin_title = 'Project Page';
  $page->admin_description = 'Individual Project Page';
  $page->path = 'user/%user/projects/%project';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'souriau_common_project_access',
        'settings' => NULL,
        'context' => array(
          0 => 'argument_entity_id:project_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
    'project' => array(
      'id' => 1,
      'identifier' => 'Project: ID',
      'name' => 'entity_id:project',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_project_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'project_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Project page',
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
  $display->title = '%project:field-project-title';
  $display->uuid = '01f169d7-0d3a-4878-8eec-123578af9ae5';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-07934543-5c40-4760-9383-96d0a5b37786';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_project';
  $pane->subtype = 'souriau_common_project';
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
  $pane->uuid = '07934543-5c40-4760-9383-96d0a5b37786';
  $display->content['new-07934543-5c40-4760-9383-96d0a5b37786'] = $pane;
  $display->panels['content'][0] = 'new-07934543-5c40-4760-9383-96d0a5b37786';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['project_page'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'projects';
  $page->task = 'page';
  $page->admin_title = 'Projects';
  $page->admin_description = '';
  $page->path = 'user/%user/projects';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'souriau_common_project_list_access',
        'settings' => NULL,
        'context' => array(
          0 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array(
    'user' => array(
      'id' => 1,
      'identifier' => 'User: ID',
      'name' => 'entity_id:user',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_projects__panel';
  $handler->task = 'page';
  $handler->subtask = 'projects';
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
  $display->title = 'My projects';
  $display->uuid = '5fb28cf1-0e48-47ea-982b-00c1e7963fbd';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-bc2fac09-bf95-468c-91ae-cdc3e8855964';
  $pane->panel = 'content';
  $pane->type = 'views';
  $pane->subtype = 'userzone_my_projects';
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
  $pane->uuid = 'bc2fac09-bf95-468c-91ae-cdc3e8855964';
  $display->content['new-bc2fac09-bf95-468c-91ae-cdc3e8855964'] = $pane;
  $display->panels['content'][0] = 'new-bc2fac09-bf95-468c-91ae-cdc3e8855964';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-bc2fac09-bf95-468c-91ae-cdc3e8855964';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['projects'] = $page;

  return $pages;

}
