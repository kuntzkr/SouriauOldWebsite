<?php
/**
 * @file
 * souriau_page_node_view.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function souriau_page_node_view_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__capability-landing';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Common',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'capability-landing',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'advpoll' => 'advpoll',
              'application' => 'application',
              'applicationdomain' => 'applicationdomain',
              'applicationlanding' => 'applicationlanding',
              'capabilitieslanding' => 'capabilitieslanding',
              'capability' => 'capability',
              'capabilitydomain' => 'capabilitydomain',
              'category' => 'category',
              'cms_page' => 'cms_page',
              'genericlanding' => 'genericlanding',
              'news' => 'news',
              'news_landing' => 'news_landing',
              'postcard' => 'postcard',
              'product' => 'product',
              'productlanding' => 'productlanding',
              'productrange' => 'productrange',
              'productrangehub' => 'productrangehub',
              'resource' => 'resource',
              'subcategory' => 'subcategory',
              'tool' => 'tool',
              'toolkitlanding' => 'toolkitlanding',
              'homepage' => 'homepage',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'souriau_one_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '206502c6-a680-42e5-a081-31dc63843ce1';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__capability-landing';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-64229257-8f45-4f90-bbee-3c1fb4c09a58';
  $pane->panel = 'content';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '64229257-8f45-4f90-bbee-3c1fb4c09a58';
  $display->content['new-64229257-8f45-4f90-bbee-3c1fb4c09a58'] = $pane;
  $display->panels['content'][0] = 'new-64229257-8f45-4f90-bbee-3c1fb4c09a58';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__capability-landing'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__http_response_fc9b6e16-90c3-4d3f-b749-c2727d8a35d3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Page not  found',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '404',
    'destination' => '',
    'name' => '',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'faq' => 'faq',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $export['node_view__http_response_fc9b6e16-90c3-4d3f-b749-c2727d8a35d3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__panel_context_898b6882-9692-4563-9ca6-cfb800501990';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Contact Form',
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
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'webform' => 'webform',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:webform:field_webform_type',
          'settings' => array(
            'field_webform_type' => array(
              'und' => array(
                0 => array(
                  'value' => 'contact_webform',
                ),
              ),
            ),
            'field_webform_type_value' => array(
              0 => 'contact_webform',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'souriau_contact_two_col';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'content' => NULL,
      'top_left' => NULL,
      'top_right' => NULL,
    ),
  );
  $display->cache = array(
    'method' => '0',
    'settings' => array(),
  );
  $display->title = 'Contact';
  $display->uuid = 'd5861249-d807-4a1c-8868-9f7c45cd28c5';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__panel_context_898b6882-9692-4563-9ca6-cfb800501990';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-68232725-7f43-4b42-a952-61787ab794aa';
  $pane->panel = 'content';
  $pane->type = 'entity_view';
  $pane->subtype = 'node';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_mode' => 'full',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '68232725-7f43-4b42-a952-61787ab794aa';
  $display->content['new-68232725-7f43-4b42-a952-61787ab794aa'] = $pane;
  $display->panels['content'][0] = 'new-68232725-7f43-4b42-a952-61787ab794aa';
  $pane = new stdClass();
  $pane->pid = 'new-48c2e66c-dcd2-4916-9f09-35a4fec7bfe4';
  $pane->panel = 'top_left';
  $pane->type = 'souriau_common_where_to_buy';
  $pane->subtype = 'souriau_common_where_to_buy';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '48c2e66c-dcd2-4916-9f09-35a4fec7bfe4';
  $display->content['new-48c2e66c-dcd2-4916-9f09-35a4fec7bfe4'] = $pane;
  $display->panels['top_left'][0] = 'new-48c2e66c-dcd2-4916-9f09-35a4fec7bfe4';
  $pane = new stdClass();
  $pane->pid = 'new-0acf8e75-481d-43d8-baf8-8d08b6557d76';
  $pane->panel = 'top_right';
  $pane->type = 'souriau_common_contact_information';
  $pane->subtype = 'souriau_common_contact_information';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '0acf8e75-481d-43d8-baf8-8d08b6557d76';
  $display->content['new-0acf8e75-481d-43d8-baf8-8d08b6557d76'] = $pane;
  $display->panels['top_right'][0] = 'new-0acf8e75-481d-43d8-baf8-8d08b6557d76';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-48c2e66c-dcd2-4916-9f09-35a4fec7bfe4';
  $handler->conf['display'] = $display;
  $export['node_view__panel_context_898b6882-9692-4563-9ca6-cfb800501990'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template__panel_context_b1fa20ae-395a-4176-8558-541626ddfe9a';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'DEFAULT',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
  $display->title = '';
  $display->uuid = '257e4d2c-0059-4046-a3cf-38b3a4939fe1';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'site_template__panel_context_b1fa20ae-395a-4176-8558-541626ddfe9a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b14a37f9-9b9a-4555-a77c-f8bf253a64c8';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_banner';
  $pane->subtype = 'souriau_common_banner';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'user
search
search/*
page_404
page_403
user/*
checkout/*
get-started
contact
our-distributors
faq
training-center
compare-part-numbers
video-tutorials
did-you-know
training-inquiry',
        ),
        'context' => 'argument_string_1',
        'not' => TRUE,
      ),
      1 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'homepage' => 'homepage',
          ),
        ),
        'context' => 'node',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array(
    'context' => array(
      0 => 'node',
    ),
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
  $pane->uuid = 'b14a37f9-9b9a-4555-a77c-f8bf253a64c8';
  $display->content['new-b14a37f9-9b9a-4555-a77c-f8bf253a64c8'] = $pane;
  $display->panels['content'][0] = 'new-b14a37f9-9b9a-4555-a77c-f8bf253a64c8';
  $pane = new stdClass();
  $pane->pid = 'new-e5a4ecc8-1d9b-491e-8b4b-df4c9c8ee9c2';
  $pane->panel = 'content';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'user
user/*
cart
checkout/*
content/contact
contact
training-inquiry',
        ),
        'context' => 'argument_string_1',
        'not' => FALSE,
      ),
      1 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'resource' => 'resource',
            'tool' => 'tool',
          ),
        ),
        'context' => 'node',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e5a4ecc8-1d9b-491e-8b4b-df4c9c8ee9c2';
  $display->content['new-e5a4ecc8-1d9b-491e-8b4b-df4c9c8ee9c2'] = $pane;
  $display->panels['content'][1] = 'new-e5a4ecc8-1d9b-491e-8b4b-df4c9c8ee9c2';
  $pane = new stdClass();
  $pane->pid = 'new-aa4757ea-9fb4-430b-aac8-1cfe11f156a7';
  $pane->panel = 'content';
  $pane->type = 'page_content';
  $pane->subtype = 'page_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_page_content_1',
    'override_title' => 1,
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
  $pane->uuid = 'aa4757ea-9fb4-430b-aac8-1cfe11f156a7';
  $display->content['new-aa4757ea-9fb4-430b-aac8-1cfe11f156a7'] = $pane;
  $display->panels['content'][2] = 'new-aa4757ea-9fb4-430b-aac8-1cfe11f156a7';
  $pane = new stdClass();
  $pane->pid = 'new-ba9c394e-c235-4004-b905-f922012ddb82';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_newsletter';
  $pane->subtype = 'souriau_common_newsletter';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'user/*
page_404
page_403
checkout/*
get-started',
        ),
        'context' => 'argument_string_1',
        'not' => TRUE,
      ),
    ),
  );
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ba9c394e-c235-4004-b905-f922012ddb82';
  $display->content['new-ba9c394e-c235-4004-b905-f922012ddb82'] = $pane;
  $display->panels['content'][3] = 'new-ba9c394e-c235-4004-b905-f922012ddb82';
  $pane = new stdClass();
  $pane->pid = 'new-fc33c3fa-4b68-460d-98d2-9aa64a2b7e50';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_slogan';
  $pane->subtype = 'souriau_common_slogan';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'advpoll' => 'advpoll',
          ),
        ),
        'context' => 'node',
        'not' => TRUE,
      ),
      1 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'user/*
page_404
page_403
checkout/*
get-started',
        ),
        'context' => 'argument_string_1',
        'not' => TRUE,
      ),
    ),
  );
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'fc33c3fa-4b68-460d-98d2-9aa64a2b7e50';
  $display->content['new-fc33c3fa-4b68-460d-98d2-9aa64a2b7e50'] = $pane;
  $display->panels['content'][4] = 'new-fc33c3fa-4b68-460d-98d2-9aa64a2b7e50';
  $pane = new stdClass();
  $pane->pid = 'new-eee56594-3985-4272-a791-6fc0c5ff05e9';
  $pane->panel = 'footer';
  $pane->type = 'souriau_common_footer';
  $pane->subtype = 'souriau_common_footer';
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
  $pane->uuid = 'eee56594-3985-4272-a791-6fc0c5ff05e9';
  $display->content['new-eee56594-3985-4272-a791-6fc0c5ff05e9'] = $pane;
  $display->panels['footer'][0] = 'new-eee56594-3985-4272-a791-6fc0c5ff05e9';
  $pane = new stdClass();
  $pane->pid = 'new-013c4ed8-5b8c-4448-818c-62b1da7fdc59';
  $pane->panel = 'header';
  $pane->type = 'souriau_common_header';
  $pane->subtype = 'souriau_common_header';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'header_menu' => 'main-menu',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '013c4ed8-5b8c-4448-818c-62b1da7fdc59';
  $display->content['new-013c4ed8-5b8c-4448-818c-62b1da7fdc59'] = $pane;
  $display->panels['header'][0] = 'new-013c4ed8-5b8c-4448-818c-62b1da7fdc59';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-013c4ed8-5b8c-4448-818c-62b1da7fdc59';
  $handler->conf['display'] = $display;
  $export['site_template__panel_context_b1fa20ae-395a-4176-8558-541626ddfe9a'] = $handler;

  return $export;
}
