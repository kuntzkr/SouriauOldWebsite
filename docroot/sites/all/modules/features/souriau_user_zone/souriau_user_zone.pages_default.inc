<?php
/**
 * @file
 * souriau_user_zone.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function souriau_user_zone_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user__panel_context_39003b08-04d5-4f72-b478-27cb5be254c0';
  $handler->task = 'user';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
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
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Edit my account';
  $display->uuid = 'c10bd2e2-daec-43fa-942e-e8e2391f95b7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-defea85d-1386-42e3-9037-ff169894f68c';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 1,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'defea85d-1386-42e3-9037-ff169894f68c';
  $display->content['new-defea85d-1386-42e3-9037-ff169894f68c'] = $pane;
  $display->panels['content'][0] = 'new-defea85d-1386-42e3-9037-ff169894f68c';
  $pane = new stdClass();
  $pane->pid = 'new-35c099fb-1264-47d2-9971-dafdc2f0649a';
  $pane->panel = 'content';
  $pane->type = 'souriau_user_user_edit';
  $pane->subtype = 'souriau_user_user_edit';
  $pane->shown = TRUE;
  $pane->access = array(
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
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '35c099fb-1264-47d2-9971-dafdc2f0649a';
  $display->content['new-35c099fb-1264-47d2-9971-dafdc2f0649a'] = $pane;
  $display->panels['content'][1] = 'new-35c099fb-1264-47d2-9971-dafdc2f0649a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-defea85d-1386-42e3-9037-ff169894f68c';
  $handler->conf['display'] = $display;
  $export['user__panel_context_39003b08-04d5-4f72-b478-27cb5be254c0'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_login__panel_context_de23200d-dec7-4d7e-9bd0-86db0582d16f';
  $handler->task = 'user_login';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
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
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Please sign in';
  $display->uuid = 'c10bd2e2-daec-43fa-942e-e8e2391f95b7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-defea85d-1386-42e3-9037-ff169894f68c';
  $pane->panel = 'content';
  $pane->type = 'block';
  $pane->subtype = 'user-login';
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
  $pane->uuid = 'defea85d-1386-42e3-9037-ff169894f68c';
  $display->content['new-defea85d-1386-42e3-9037-ff169894f68c'] = $pane;
  $display->panels['content'][0] = 'new-defea85d-1386-42e3-9037-ff169894f68c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-defea85d-1386-42e3-9037-ff169894f68c';
  $handler->conf['display'] = $display;
  $export['user_login__panel_context_de23200d-dec7-4d7e-9bd0-86db0582d16f'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_password__panel_context_2a132431-3509-46c5-88db-95fe7a6d0bd7';
  $handler->task = 'user_password';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
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
      'content' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'I forgot my password';
  $display->uuid = 'c10bd2e2-daec-43fa-942e-e8e2391f95b7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ea07c777-32c1-42c1-9fc5-4ce5c7b26b25';
  $pane->panel = 'content';
  $pane->type = 'souriau_user_user_pass';
  $pane->subtype = 'souriau_user_user_pass';
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
  $pane->uuid = 'ea07c777-32c1-42c1-9fc5-4ce5c7b26b25';
  $display->content['new-ea07c777-32c1-42c1-9fc5-4ce5c7b26b25'] = $pane;
  $display->panels['content'][0] = 'new-ea07c777-32c1-42c1-9fc5-4ce5c7b26b25';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_password__panel_context_2a132431-3509-46c5-88db-95fe7a6d0bd7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_register__panel_context_4d4dc603-9078-4d22-887b-451be199b156';
  $handler->task = 'user_register';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
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
      'plugins' => array(),
    ),
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
  $display->title = 'Sign up';
  $display->uuid = 'c10bd2e2-daec-43fa-942e-e8e2391f95b7';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-053d4996-060e-44e9-9b8d-bc71c31a560d';
  $pane->panel = 'content';
  $pane->type = 'souriau_user_user_register';
  $pane->subtype = 'souriau_user_user_register';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
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
  $pane->uuid = '053d4996-060e-44e9-9b8d-bc71c31a560d';
  $display->content['new-053d4996-060e-44e9-9b8d-bc71c31a560d'] = $pane;
  $display->panels['content'][0] = 'new-053d4996-060e-44e9-9b8d-bc71c31a560d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_register__panel_context_4d4dc603-9078-4d22-887b-451be199b156'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__panel_context_8fdf4836-78ee-47be-947c-e5922651376a';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'User Edit',
    'no_blocks' => 1,
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
      'header' => NULL,
      'content' => NULL,
      'footer' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0a8a28f4-49d4-4cc3-829e-3db2fa87ed8a';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c10123a3-69ca-4999-b0f0-152255c45908';
  $pane->panel = 'content';
  $pane->type = 'souriau_common_user_edit';
  $pane->subtype = 'souriau_common_user_edit';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = 'c10123a3-69ca-4999-b0f0-152255c45908';
  $display->content['new-c10123a3-69ca-4999-b0f0-152255c45908'] = $pane;
  $display->panels['content'][0] = 'new-c10123a3-69ca-4999-b0f0-152255c45908';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c10123a3-69ca-4999-b0f0-152255c45908';
  $handler->conf['display'] = $display;
  $export['user_view__panel_context_8fdf4836-78ee-47be-947c-e5922651376a'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view__permanent_redirect';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'http_response';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Permanent redirect',
    'contexts' => array(),
    'relationships' => array(),
    'code' => '301',
    'destination' => '/user/space',
    'name' => 'permanent_redirect',
  );
  $export['user_view__permanent_redirect'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function souriau_user_zone_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_delete';
  $page->task = 'page';
  $page->admin_title = 'User delete';
  $page->admin_description = 'Delete own user account';
  $page->path = 'user/%user/delete-account';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'compare_users',
        'settings' => array(
          'equality' => '1',
        ),
        'context' => array(
          0 => 'logged-in-user',
          1 => 'argument_entity_id:user_1',
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
  $handler->name = 'page_user_delete__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_delete';
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
  $display->title = 'Delete my account';
  $display->uuid = '3d299eb7-695d-4991-9bcd-fc44c9abb412';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ef546c31-f678-42cd-8270-a297c004657b';
  $pane->panel = 'content';
  $pane->type = 'souriau_user_delete';
  $pane->subtype = 'souriau_user_delete';
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
  $pane->uuid = 'ef546c31-f678-42cd-8270-a297c004657b';
  $display->content['new-ef546c31-f678-42cd-8270-a297c004657b'] = $pane;
  $display->panels['content'][0] = 'new-ef546c31-f678-42cd-8270-a297c004657b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_delete'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'user_edit_page';
  $page->task = 'page';
  $page->admin_title = 'User edit page';
  $page->admin_description = '';
  $page->path = 'user/%user/edit-profile';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'souriau_user_user_edit_page_access',
        'settings' => NULL,
        'context' => array(
          0 => 'argument_entity_id:user_1',
        ),
        'not' => FALSE,
      ),
    ),
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
  $handler->name = 'page_user_edit_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'user_edit_page';
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
    'access' => array(
      'logic' => 'and',
    ),
    'panels_everywhere_site_template' => 'site_template__user-login',
  );
  $display = new panels_display();
  $display->layout = 'souriau_one_col';
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
  $display->title = 'Edit my account';
  $display->uuid = '6e8e11d5-6128-4db5-aaa5-a3b7dc4935c2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a938f59f-608b-44de-9bd0-1be062570988';
  $pane->panel = 'content';
  $pane->type = 'souriau_user_user_edit';
  $pane->subtype = 'souriau_user_user_edit';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'argument_entity_id:user_1',
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
  $pane->uuid = 'a938f59f-608b-44de-9bd0-1be062570988';
  $display->content['new-a938f59f-608b-44de-9bd0-1be062570988'] = $pane;
  $display->panels['content'][0] = 'new-a938f59f-608b-44de-9bd0-1be062570988';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['user_edit_page'] = $page;

  return $pages;

}
