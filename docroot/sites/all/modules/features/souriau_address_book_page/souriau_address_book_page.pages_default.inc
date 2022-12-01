<?php
/**
 * @file
 * souriau_address_book_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_address_book_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'address_book';
  $page->task = 'page';
  $page->admin_title = 'Address Book';
  $page->admin_description = '';
  $page->path = 'user/%user/addresses';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'context_exists',
        'settings' => array(
          'exists' => '1',
        ),
        'context' => 'argument_entity_id:user_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'entity_field_value:user:user:field_allow_usage_of_data',
        'settings' => array(
          'field_allow_usage_of_data' => array(
            'und' => array(
              0 => array(
                'value' => 1,
              ),
            ),
          ),
          'field_allow_usage_of_data_value' => array(
            0 => 1,
          ),
        ),
        'context' => 'argument_entity_id:user_1',
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
  $handler->name = 'page_address_book__panel';
  $handler->task = 'page';
  $handler->subtask = 'address_book';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Address Book',
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
  $display->layout = 'souriau_main';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'My addresses';
  $display->uuid = '9da8f08c-88b1-4972-8c40-eec8ae13bbc1';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-4d044aa1-32c0-4999-a5f8-b0277f8fe803';
  $pane->panel = 'content';
  $pane->type = 'souriau_eco_address_book';
  $pane->subtype = 'souriau_eco_address_book';
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
  $pane->uuid = '4d044aa1-32c0-4999-a5f8-b0277f8fe803';
  $display->content['new-4d044aa1-32c0-4999-a5f8-b0277f8fe803'] = $pane;
  $display->panels['content'][0] = 'new-4d044aa1-32c0-4999-a5f8-b0277f8fe803';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['address_book'] = $page;

  return $pages;

}
