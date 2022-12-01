<?php
/**
 * @file
 * souriau_compare_page_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_compare_page_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'compare_part_numbers';
  $page->task = 'page';
  $page->admin_title = 'Compare Part Numbers';
  $page->admin_description = '';
  $page->path = 'compare-part-numbers';
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
  $handler->name = 'page_compare_part_numbers__panel';
  $handler->task = 'page';
  $handler->subtask = 'compare_part_numbers';
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
      'header' => NULL,
      'content' => array(
        'selector' => 'div.b-compare',
      ),
      'footer' => NULL,
    ),
    'content' => array(
      'style' => 'html',
    ),
  );
  $display->cache = array();
  $display->title = 'Compare part numbers';
  $display->uuid = '59a9f2c1-a757-4544-9800-b0c677c8e873';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-625efc38-1a8e-4fa8-aca3-eb7985859592';
  $pane->panel = 'content';
  $pane->type = 'part_number_list';
  $pane->subtype = 'part_number_list';
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
  $pane->uuid = '625efc38-1a8e-4fa8-aca3-eb7985859592';
  $display->content['new-625efc38-1a8e-4fa8-aca3-eb7985859592'] = $pane;
  $display->panels['content'][0] = 'new-625efc38-1a8e-4fa8-aca3-eb7985859592';
  $pane = new stdClass();
  $pane->pid = 'new-5ad172f3-e1aa-4317-828f-63bcff59f8c6';
  $pane->panel = 'content';
  $pane->type = 'technical_data_comparison';
  $pane->subtype = 'technical_data_comparison';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '5ad172f3-e1aa-4317-828f-63bcff59f8c6';
  $display->content['new-5ad172f3-e1aa-4317-828f-63bcff59f8c6'] = $pane;
  $display->panels['content'][1] = 'new-5ad172f3-e1aa-4317-828f-63bcff59f8c6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['compare_part_numbers'] = $page;

  return $pages;

}
