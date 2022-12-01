<?php
/**
 * @file
 * souriau_dashboard.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function souriau_dashboard_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'dashboard_all';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dashboard Souriau All';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    12 => '12',
    13 => '13',
    7 => '7',
    21 => '21',
    26 => '26',
    14 => '14',
    5 => '5',
    4 => '4',
    8 => '8',
    11 => '11',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'title_1' => 'title_1',
    'title_field_1' => 'title_field_1',
    'title_field' => 'title_field',
    'name' => 'name',
    'name_1' => 'name_1',
    'type' => 'type',
    'status_1' => 'status_1',
    'workflow' => 'workflow',
    'status' => 'status',
    'field_modification_type' => 'field_modification_type',
    'created' => 'created',
    'changed' => 'changed',
    'language' => 'language',
    'language_link' => 'language_link',
    'view_translation' => 'view_translation',
    'edit_translation' => 'edit_translation',
    'clone_node' => 'clone_node',
    'publish_translation' => 'publish_translation',
    'unpublish_translation' => 'unpublish_translation',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'workflow' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_modification_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_translation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_translation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publish_translation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'unpublish_translation' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Draft node */
  $handler->display->display_options['relationships']['field_edition_target_id']['id'] = 'field_edition_target_id';
  $handler->display->display_options['relationships']['field_edition_target_id']['table'] = 'field_data_field_edition';
  $handler->display->display_options['relationships']['field_edition_target_id']['field'] = 'field_edition_target_id';
  $handler->display->display_options['relationships']['field_edition_target_id']['ui_name'] = 'Draft node';
  $handler->display->display_options['relationships']['field_edition_target_id']['label'] = 'Draft node';
  /* Relationship: Content: Entity translation: translations */
  $handler->display->display_options['relationships']['entity_translations']['id'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['table'] = 'node';
  $handler->display->display_options['relationships']['entity_translations']['field'] = 'entity_translations';
  $handler->display->display_options['relationships']['entity_translations']['relationship'] = 'field_edition_target_id';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['relationship'] = 'field_edition_target_id';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_draft_value']['group'] = 1;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
    'und' => 'und',
    'en-en' => 'en-en',
    'en-gb' => 'en-gb',
    'en-us' => 'en-us',
    'en-ca' => 'en-ca',
    'fr-ca' => 'fr-ca',
    'fr-fr' => 'fr-fr',
    'es-sp' => 'es-sp',
    'ch-ch' => 'ch-ch',
    'jp-jp' => 'jp-jp',
    'en' => 'en',
    'en-int' => 'en-int',
    'it' => 'it',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
    'applicationdomain' => 'applicationdomain',
    'applicationlanding' => 'applicationlanding',
    'capabilitieslanding' => 'capabilitieslanding',
    'capability' => 'capability',
    'capabilitydomain' => 'capabilitydomain',
    'category' => 'category',
    'faq' => 'faq',
    'homepage' => 'homepage',
    'news' => 'news',
    'product' => 'product',
    'productlanding' => 'productlanding',
    'productrange' => 'productrange',
    'subcategory' => 'subcategory',
    'tool' => 'tool',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow_1']['id'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow_1']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow_1']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow_1']['value'] = array(
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['filters']['workflow_1']['group'] = 1;
  $handler->display->display_options['filters']['workflow_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['operator_id'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['label'] = 'Moderation status';
  $handler->display->display_options['filters']['workflow_1']['expose']['operator'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['identifier'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['workflow_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Entity translation: Translation status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['status']['value'] = '0';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Translation Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Field: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow']['id'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow']['value'] = array(
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['filters']['workflow']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'advpoll' => 'advpoll',
  );

  /* Display: All Content */
  $handler = $view->new_display('page', 'All Content', 'all_content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Content';
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    12 => '12',
    13 => '13',
    7 => '7',
    21 => '21',
    26 => '26',
    14 => '14',
    5 => '5',
    4 => '4',
    16 => '16',
    8 => '8',
    11 => '11',
    3 => '3',
  );
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::draft_moderation_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::draft_moderation_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title (origin)';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Title (origin)';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
  $handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_1']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field_1']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field_1']['empty'] = '[title_1]';
  $handler->display->display_options['fields']['title_field_1']['link_to_entity'] = 0;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[title_field_1]';
  $handler->display->display_options['fields']['title_field']['empty'] = '[title_field_1]';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['name_1']['label'] = 'Contributor';
  $handler->display->display_options['fields']['name_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'node';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['label'] = '';
  $handler->display->display_options['fields']['status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['status_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status_1']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status_1']['not'] = 0;
  /* Field: Entity translation: Workflow status */
  $handler->display->display_options['fields']['workflow']['id'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['workflow']['field'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['workflow']['label'] = 'Moderation status';
  /* Field: Entity translation: Translation status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['status']['label'] = 'Translation Status';
  $handler->display->display_options['fields']['status']['empty'] = '[status_1]';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Modification Type */
  $handler->display->display_options['fields']['field_modification_type']['id'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['table'] = 'field_data_field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['field'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['relationship'] = 'field_edition_target_id';
  /* Field: Content: Log */
  $handler->display->display_options['fields']['field_log']['id'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['table'] = 'field_data_field_log';
  $handler->display->display_options['fields']['field_log']['field'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['field_log']['label'] = 'Modification Description';
  $handler->display->display_options['fields']['field_log']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_log']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Entity translation: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'j-n-Y ';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Entity translation: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Entity translation: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['relationship'] = 'entity_translations';
  /* Field: Entity translation: Link with translation language */
  $handler->display->display_options['fields']['language_link']['id'] = 'language_link';
  $handler->display->display_options['fields']['language_link']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['language_link']['field'] = 'language_link';
  $handler->display->display_options['fields']['language_link']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['language_link']['label'] = 'View published';
  $handler->display->display_options['fields']['language_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['language_link']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['language_link']['text'] = 'view published';
  /* Field: Entity translation: Link to translation */
  $handler->display->display_options['fields']['view_translation']['id'] = 'view_translation';
  $handler->display->display_options['fields']['view_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['view_translation']['field'] = 'view_translation';
  $handler->display->display_options['fields']['view_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['view_translation']['label'] = 'draft';
  $handler->display->display_options['fields']['view_translation']['text'] = 'view draft';
  /* Field: Entity translation: Edit link */
  $handler->display->display_options['fields']['edit_translation']['id'] = 'edit_translation';
  $handler->display->display_options['fields']['edit_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['edit_translation']['field'] = 'edit_translation';
  $handler->display->display_options['fields']['edit_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['edit_translation']['label'] = 'Edit';
  /* Field: Content: Clone link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['label'] = 'Clone';
  /* Field: Entity translation: Publish link */
  $handler->display->display_options['fields']['publish_translation']['id'] = 'publish_translation';
  $handler->display->display_options['fields']['publish_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['publish_translation']['field'] = 'publish_translation';
  $handler->display->display_options['fields']['publish_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['publish_translation']['label'] = 'Publish';
  /* Field: Entity translation: Unpublish link */
  $handler->display->display_options['fields']['unpublish_translation']['id'] = 'unpublish_translation';
  $handler->display->display_options['fields']['unpublish_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['unpublish_translation']['field'] = 'unpublish_translation';
  $handler->display->display_options['fields']['unpublish_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['unpublish_translation']['label'] = 'Unpublish';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_draft_value']['group'] = 1;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
    'und' => 'und',
    'en-en' => 'en-en',
    'en-gb' => 'en-gb',
    'en-us' => 'en-us',
    'en-ca' => 'en-ca',
    'fr-ca' => 'fr-ca',
    'fr-fr' => 'fr-fr',
    'es-sp' => 'es-sp',
    'ch-ch' => 'ch-ch',
    'jp-jp' => 'jp-jp',
    'en' => 'en',
    'en-int' => 'en-int',
    'it' => 'it',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advpoll' => 'advpoll',
    'application' => 'application',
    'applicationdomain' => 'applicationdomain',
    'applicationlanding' => 'applicationlanding',
    'capabilitieslanding' => 'capabilitieslanding',
    'capability' => 'capability',
    'capabilitydomain' => 'capabilitydomain',
    'category' => 'category',
    'cms_page' => 'cms_page',
    'faq' => 'faq',
    'genericlanding' => 'genericlanding',
    'homepage' => 'homepage',
    'news' => 'news',
    'news_landing' => 'news_landing',
    'postcard' => 'postcard',
    'productlanding' => 'productlanding',
    'productrange' => 'productrange',
    'productrangehub' => 'productrangehub',
    'resource' => 'resource',
    'subcategory' => 'subcategory',
    'tool' => 'tool',
    'toolkitlanding' => 'toolkitlanding',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
    22 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow_1']['id'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow_1']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow_1']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow_1']['value'] = array(
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['filters']['workflow_1']['group'] = 1;
  $handler->display->display_options['filters']['workflow_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['operator_id'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['label'] = 'Moderation status';
  $handler->display->display_options['filters']['workflow_1']['expose']['operator'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['identifier'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['workflow_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Entity translation: Translation status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Translation Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Field: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow']['id'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow']['value'] = array(
    'all' => 'all',
    1 => '1',
    2 => '2',
    4 => '4',
    0 => '0',
  );
  $handler->display->display_options['filters']['workflow']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/dashboard/all';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: My Content */
  $handler = $view->new_display('page', 'My Content', 'my_content');
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::draft_moderation_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::draft_moderation_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_node_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Title (origin)';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
  $handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_1']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field_1']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field_1']['empty'] = '[title]';
  $handler->display->display_options['fields']['title_field_1']['link_to_entity'] = 0;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '[title_field_1]';
  $handler->display->display_options['fields']['title_field']['empty'] = '[title_field_1]';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['name_1']['label'] = 'Contributor';
  $handler->display->display_options['fields']['name_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'node';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_1']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status_1']['not'] = 0;
  /* Field: Entity translation: Workflow status */
  $handler->display->display_options['fields']['workflow']['id'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['workflow']['field'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['workflow']['label'] = 'Moderation status';
  /* Field: Entity translation: Translation status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['status']['label'] = 'Translation Status';
  $handler->display->display_options['fields']['status']['empty'] = '[status_1]';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Modification Type */
  $handler->display->display_options['fields']['field_modification_type']['id'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['table'] = 'field_data_field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['field'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['relationship'] = 'field_edition_target_id';
  /* Field: Content: Log */
  $handler->display->display_options['fields']['field_log']['id'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['table'] = 'field_data_field_log';
  $handler->display->display_options['fields']['field_log']['field'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['field_log']['label'] = 'Modification Description';
  $handler->display->display_options['fields']['field_log']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_log']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Entity translation: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'j-n-Y ';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Entity translation: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Entity translation: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['relationship'] = 'entity_translations';
  /* Field: Entity translation: Link with translation language */
  $handler->display->display_options['fields']['language_link']['id'] = 'language_link';
  $handler->display->display_options['fields']['language_link']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['language_link']['field'] = 'language_link';
  $handler->display->display_options['fields']['language_link']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['language_link']['label'] = 'View published';
  $handler->display->display_options['fields']['language_link']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['language_link']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['language_link']['text'] = 'view published';
  /* Field: Entity translation: Link to translation */
  $handler->display->display_options['fields']['view_translation']['id'] = 'view_translation';
  $handler->display->display_options['fields']['view_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['view_translation']['field'] = 'view_translation';
  $handler->display->display_options['fields']['view_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['view_translation']['label'] = 'draft';
  $handler->display->display_options['fields']['view_translation']['text'] = 'view draft';
  /* Field: Entity translation: Edit link */
  $handler->display->display_options['fields']['edit_translation']['id'] = 'edit_translation';
  $handler->display->display_options['fields']['edit_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['edit_translation']['field'] = 'edit_translation';
  $handler->display->display_options['fields']['edit_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['edit_translation']['label'] = 'Edit';
  /* Field: Content: Clone link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['label'] = 'Clone';
  /* Field: Entity translation: Publish link */
  $handler->display->display_options['fields']['publish_translation']['id'] = 'publish_translation';
  $handler->display->display_options['fields']['publish_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['publish_translation']['field'] = 'publish_translation';
  $handler->display->display_options['fields']['publish_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['publish_translation']['label'] = 'Publish';
  /* Field: Entity translation: Unpublish link */
  $handler->display->display_options['fields']['unpublish_translation']['id'] = 'unpublish_translation';
  $handler->display->display_options['fields']['unpublish_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['unpublish_translation']['field'] = 'unpublish_translation';
  $handler->display->display_options['fields']['unpublish_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['unpublish_translation']['label'] = 'Unpublish';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_draft_value']['group'] = 1;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
    'und' => 'und',
    'en-en' => 'en-en',
    'en-gb' => 'en-gb',
    'en-us' => 'en-us',
    'en-ca' => 'en-ca',
    'fr-ca' => 'fr-ca',
    'fr-fr' => 'fr-fr',
    'es-sp' => 'es-sp',
    'ch-ch' => 'ch-ch',
    'jp-jp' => 'jp-jp',
    'en' => 'en',
    'en-int' => 'en-int',
    'it' => 'it',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
    'applicationdomain' => 'applicationdomain',
    'applicationlanding' => 'applicationlanding',
    'capabilitieslanding' => 'capabilitieslanding',
    'capability' => 'capability',
    'capabilitydomain' => 'capabilitydomain',
    'category' => 'category',
    'cms_page' => 'cms_page',
    'faq' => 'faq',
    'genericlanding' => 'genericlanding',
    'homepage' => 'homepage',
    'news' => 'news',
    'news_landing' => 'news_landing',
    'productlanding' => 'productlanding',
    'productrange' => 'productrange',
    'productrangehub' => 'productrangehub',
    'resource' => 'resource',
    'subcategory' => 'subcategory',
    'tool' => 'tool',
    'toolkitlanding' => 'toolkitlanding',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow']['id'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow']['value'] = array(
    1 => '1',
    2 => '2',
    4 => '4',
    0 => '0',
  );
  $handler->display->display_options['filters']['workflow']['group'] = 1;
  $handler->display->display_options['filters']['workflow']['exposed'] = TRUE;
  $handler->display->display_options['filters']['workflow']['expose']['operator_id'] = 'workflow_op';
  $handler->display->display_options['filters']['workflow']['expose']['label'] = 'Workflow status';
  $handler->display->display_options['filters']['workflow']['expose']['operator'] = 'workflow_op';
  $handler->display->display_options['filters']['workflow']['expose']['identifier'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['workflow']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['workflow']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Entity translation: Translation status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Translation Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Field: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/dashboard/my-content';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Content';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: To Validation */
  $handler = $view->new_display('page', 'To Validation', 'for_validation');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'To Validation';
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Title (origin)';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
  $handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_1']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field_1']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title_field_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field_1']['empty'] = '[title]';
  $handler->display->display_options['fields']['title_field_1']['link_to_entity'] = 0;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title_field']['empty'] = '[title_field_1]';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name_1']['label'] = 'Contributor';
  $handler->display->display_options['fields']['name_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['name_1']['empty_zero'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['alter']['make_link'] = TRUE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status_1']['id'] = 'status_1';
  $handler->display->display_options['fields']['status_1']['table'] = 'node';
  $handler->display->display_options['fields']['status_1']['field'] = 'status';
  $handler->display->display_options['fields']['status_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['status_1']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status_1']['not'] = 0;
  /* Field: Entity translation: Workflow status */
  $handler->display->display_options['fields']['workflow']['id'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['workflow']['field'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['workflow']['label'] = 'Moderation status';
  /* Field: Entity translation: Translation status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['status']['label'] = 'Translation Status';
  $handler->display->display_options['fields']['status']['empty'] = '[status_1]';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Modification Type */
  $handler->display->display_options['fields']['field_modification_type']['id'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['table'] = 'field_data_field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['field'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['relationship'] = 'field_edition_target_id';
  /* Field: Content: Log */
  $handler->display->display_options['fields']['field_log']['id'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['table'] = 'field_data_field_log';
  $handler->display->display_options['fields']['field_log']['field'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['field_log']['label'] = 'Modification Description';
  $handler->display->display_options['fields']['field_log']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_log']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Entity translation: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'j-n-Y ';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Entity translation: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Entity translation: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['relationship'] = 'entity_translations';
  /* Field: Entity translation: Link to translation */
  $handler->display->display_options['fields']['view_translation']['id'] = 'view_translation';
  $handler->display->display_options['fields']['view_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['view_translation']['field'] = 'view_translation';
  $handler->display->display_options['fields']['view_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['view_translation']['label'] = 'draft';
  $handler->display->display_options['fields']['view_translation']['text'] = 'view draft';
  /* Field: Entity translation: Edit link */
  $handler->display->display_options['fields']['edit_translation']['id'] = 'edit_translation';
  $handler->display->display_options['fields']['edit_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['edit_translation']['field'] = 'edit_translation';
  $handler->display->display_options['fields']['edit_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['edit_translation']['label'] = 'Edit';
  /* Field: Content: Clone link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['label'] = 'Clone';
  /* Field: Entity translation: Publish link */
  $handler->display->display_options['fields']['publish_translation']['id'] = 'publish_translation';
  $handler->display->display_options['fields']['publish_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['publish_translation']['field'] = 'publish_translation';
  $handler->display->display_options['fields']['publish_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['publish_translation']['label'] = 'Publish';
  /* Field: Entity translation: Unpublish link */
  $handler->display->display_options['fields']['unpublish_translation']['id'] = 'unpublish_translation';
  $handler->display->display_options['fields']['unpublish_translation']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['unpublish_translation']['field'] = 'unpublish_translation';
  $handler->display->display_options['fields']['unpublish_translation']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['unpublish_translation']['label'] = 'Unpublish';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_draft_value']['group'] = 1;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
    'und' => 'und',
    'en-en' => 'en-en',
    'en-gb' => 'en-gb',
    'en-us' => 'en-us',
    'en-ca' => 'en-ca',
    'fr-ca' => 'fr-ca',
    'fr-fr' => 'fr-fr',
    'es-sp' => 'es-sp',
    'ch-ch' => 'ch-ch',
    'jp-jp' => 'jp-jp',
    'en' => 'en',
    'en-int' => 'en-int',
    'it' => 'it',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
    'applicationdomain' => 'applicationdomain',
    'applicationlanding' => 'applicationlanding',
    'capabilitieslanding' => 'capabilitieslanding',
    'capability' => 'capability',
    'capabilitydomain' => 'capabilitydomain',
    'category' => 'category',
    'cms_page' => 'cms_page',
    'faq' => 'faq',
    'genericlanding' => 'genericlanding',
    'homepage' => 'homepage',
    'news' => 'news',
    'news_landing' => 'news_landing',
    'productlanding' => 'productlanding',
    'productrange' => 'productrange',
    'productrangehub' => 'productrangehub',
    'resource' => 'resource',
    'subcategory' => 'subcategory',
    'tool' => 'tool',
    'toolkitlanding' => 'toolkitlanding',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow_1']['id'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow_1']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow_1']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow_1']['value'] = array(
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['filters']['workflow_1']['group'] = 1;
  $handler->display->display_options['filters']['workflow_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['operator_id'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['label'] = 'Moderation status';
  $handler->display->display_options['filters']['workflow_1']['expose']['operator'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['identifier'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['workflow_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Entity translation: Translation status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Translation Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Field: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow']['id'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow']['value'] = array(
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['filters']['workflow']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/dashboard/for-validation';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'To Validation';
  $handler->display->display_options['menu']['weight'] = '-50';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'Node ID';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title (origin)';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Title (origin)';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field_1']['id'] = 'title_field_1';
  $handler->display->display_options['fields']['title_field_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field_1']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field_1']['link_to_entity'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['name_1']['label'] = 'Contributor';
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Entity translation: Workflow status */
  $handler->display->display_options['fields']['workflow']['id'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['workflow']['field'] = 'workflow';
  $handler->display->display_options['fields']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['workflow']['label'] = 'Moderation status';
  /* Field: Entity translation: Translation status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Modification Type */
  $handler->display->display_options['fields']['field_modification_type']['id'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['table'] = 'field_data_field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['field'] = 'field_modification_type';
  $handler->display->display_options['fields']['field_modification_type']['relationship'] = 'field_edition_target_id';
  /* Field: Content: Log */
  $handler->display->display_options['fields']['field_log']['id'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['table'] = 'field_data_field_log';
  $handler->display->display_options['fields']['field_log']['field'] = 'field_log';
  $handler->display->display_options['fields']['field_log']['relationship'] = 'field_edition_target_id';
  $handler->display->display_options['fields']['field_log']['label'] = 'Modification Description';
  $handler->display->display_options['fields']['field_log']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_log']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Entity translation: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Entity translation: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'entity_translations';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Entity translation: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'entity_translation';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Draft (field_draft) */
  $handler->display->display_options['filters']['field_draft_value']['id'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['table'] = 'field_data_field_draft';
  $handler->display->display_options['filters']['field_draft_value']['field'] = 'field_draft_value';
  $handler->display->display_options['filters']['field_draft_value']['operator'] = 'and';
  $handler->display->display_options['filters']['field_draft_value']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_draft_value']['group'] = 1;
  /* Filter criterion: Entity translation: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
    'und' => 'und',
    'en-en' => 'en-en',
    'en-gb' => 'en-gb',
    'en-us' => 'en-us',
    'en-ca' => 'en-ca',
    'fr-ca' => 'fr-ca',
    'fr-fr' => 'fr-fr',
    'es-sp' => 'es-sp',
    'ch-ch' => 'ch-ch',
    'jp-jp' => 'jp-jp',
    'en' => 'en',
    'en-int' => 'en-int',
    'it' => 'it',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'application' => 'application',
    'applicationdomain' => 'applicationdomain',
    'applicationlanding' => 'applicationlanding',
    'capabilitieslanding' => 'capabilitieslanding',
    'capability' => 'capability',
    'capabilitydomain' => 'capabilitydomain',
    'category' => 'category',
    'faq' => 'faq',
    'homepage' => 'homepage',
    'news' => 'news',
    'product' => 'product',
    'productlanding' => 'productlanding',
    'productrange' => 'productrange',
    'subcategory' => 'subcategory',
    'tool' => 'tool',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow_1']['id'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow_1']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow_1']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow_1']['value'] = array(
    2 => '2',
    4 => '4',
  );
  $handler->display->display_options['filters']['workflow_1']['group'] = 1;
  $handler->display->display_options['filters']['workflow_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['operator_id'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['label'] = 'Moderation status';
  $handler->display->display_options['filters']['workflow_1']['expose']['operator'] = 'workflow_1_op';
  $handler->display->display_options['filters']['workflow_1']['expose']['identifier'] = 'workflow_1';
  $handler->display->display_options['filters']['workflow_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['workflow_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['workflow_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Entity translation: Translation status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Translation Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
    36 => 0,
    41 => 0,
  );
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: Field: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Title';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: Entity translation: Workflow status */
  $handler->display->display_options['filters']['workflow']['id'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['table'] = 'entity_translation';
  $handler->display->display_options['filters']['workflow']['field'] = 'workflow';
  $handler->display->display_options['filters']['workflow']['relationship'] = 'entity_translations';
  $handler->display->display_options['filters']['workflow']['value'] = array(
    'all' => 'all',
    1 => '1',
    2 => '2',
    4 => '4',
    0 => '0',
  );
  $handler->display->display_options['filters']['workflow']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/dashboard/all/export';
  $handler->display->display_options['displays'] = array(
    'all_content' => 'all_content',
    'default' => 0,
    'my_content' => 0,
    'for_validation' => 0,
  );
  $handler->display->display_options['return_path'] = 'admin/dashboard/all';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['dashboard_all'] = array(
    t('Master'),
    t('My Content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Draft node'),
    t('Translations'),
    t('author'),
    t('revision user'),
    t('Nid'),
    t('Author'),
    t('Language'),
    t('Type'),
    t('Moderation status'),
    t('Published'),
    t('Translation Published'),
    t('Title'),
    t('All Content'),
    t('Displaying @start - @end of @total'),
    t('Content'),
    t('- Choose an operation -'),
    t('Title (origin)'),
    t('[title_1]'),
    t('[title_field_1]'),
    t('Contributor'),
    t('Translation Status'),
    t('[status_1]'),
    t('Modification Type'),
    t('Modification Description'),
    t('Created'),
    t('Updated'),
    t('View published'),
    t('view published'),
    t('draft'),
    t('view draft'),
    t('Edit'),
    t('Clone'),
    t('Publish'),
    t('Unpublish'),
    t('Delete'),
    t('[title]'),
    t('Workflow status'),
    t('To Validation'),
    t('Data export'),
    t('Node ID'),
    t('Translation status'),
  );
  $export['dashboard_all'] = $view;

  $view = new view();
  $view->name = 'dashboard_product_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Dashboard Product List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Products List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    11 => '11',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_code_p' => 'field_code_p',
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'title' => 'title',
    'sku' => 'sku',
    'field_product_series' => 'field_product_series',
    'status' => 'status',
    'changed' => 'changed',
    'view_node' => 'view_node',
    'edit_node' => 'edit_node',
    'sku_1' => 'edit_node',
    'publish_button' => 'publish_button',
    'clone_node' => 'clone_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_code_p' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sku' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_product_series' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => ' | ',
      'empty_column' => 0,
    ),
    'sku_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'publish_button' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clone_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  /* Relationship: Content: Referenced products */
  $handler->display->display_options['relationships']['field_sku_products_product_id']['id'] = 'field_sku_products_product_id';
  $handler->display->display_options['relationships']['field_sku_products_product_id']['table'] = 'field_data_field_sku_products';
  $handler->display->display_options['relationships']['field_sku_products_product_id']['field'] = 'field_sku_products_product_id';
  $handler->display->display_options['relationships']['field_sku_products_product_id']['label'] = 'SKU';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_parent_product_range_target_id']['id'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['relationships']['field_parent_product_range_target_id']['table'] = 'field_data_field_parent_product_range';
  $handler->display->display_options['relationships']['field_parent_product_range_target_id']['field'] = 'field_parent_product_range_target_id';
  /* Field: Content: Product Code */
  $handler->display->display_options['fields']['field_code_p']['id'] = 'field_code_p';
  $handler->display->display_options['fields']['field_code_p']['table'] = 'field_data_field_code_p';
  $handler->display->display_options['fields']['field_code_p']['field'] = 'field_code_p';
  $handler->display->display_options['fields']['field_code_p']['exclude'] = TRUE;
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'field_sku_products_product_id';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Content: Product Series */
  $handler->display->display_options['fields']['field_product_series']['id'] = 'field_product_series';
  $handler->display->display_options['fields']['field_product_series']['table'] = 'field_data_field_product_series';
  $handler->display->display_options['fields']['field_product_series']['field'] = 'field_product_series';
  $handler->display->display_options['fields']['field_product_series']['relationship'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['fields']['field_product_series']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_product_series']['group_column'] = 'entity_id';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'souriau_date_short_with_time';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = 'View';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = 'Part Number';
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku_1']['id'] = 'sku_1';
  $handler->display->display_options['fields']['sku_1']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku_1']['field'] = 'sku';
  $handler->display->display_options['fields']['sku_1']['relationship'] = 'field_sku_products_product_id';
  $handler->display->display_options['fields']['sku_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['sku_1']['alter']['text'] = 'SKU';
  $handler->display->display_options['fields']['sku_1']['link_to_product'] = 1;
  /* Field: Content: Publish button */
  $handler->display->display_options['fields']['publish_button']['id'] = 'publish_button';
  $handler->display->display_options['fields']['publish_button']['table'] = 'node';
  $handler->display->display_options['fields']['publish_button']['field'] = 'publish_button';
  $handler->display->display_options['fields']['publish_button']['label'] = 'Publish';
  $handler->display->display_options['fields']['publish_button']['element_default_classes'] = FALSE;
  /* Field: Content: Clone link */
  $handler->display->display_options['fields']['clone_node']['id'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['table'] = 'node';
  $handler->display->display_options['fields']['clone_node']['field'] = 'clone_node';
  $handler->display->display_options['fields']['clone_node']['label'] = 'Clone';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Title or SKU';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_code_p' => 'field_code_p',
    'title' => 'title',
    'sku' => 'sku',
  );
  /* Filter criterion: Content: Product Series (field_product_series) */
  $handler->display->display_options['filters']['field_product_series_tid']['id'] = 'field_product_series_tid';
  $handler->display->display_options['filters']['field_product_series_tid']['table'] = 'field_data_field_product_series';
  $handler->display->display_options['filters']['field_product_series_tid']['field'] = 'field_product_series_tid';
  $handler->display->display_options['filters']['field_product_series_tid']['relationship'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['filters']['field_product_series_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_product_series_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['operator_id'] = 'field_product_series_tid_op';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['label'] = 'Product Series';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['operator'] = 'field_product_series_tid_op';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['identifier'] = 'field_product_series_tid';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_product_series_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_product_series_tid']['vocabulary'] = 'product_series';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Updated Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.changed' => 'node.changed',
  );

  /* Display: Products List */
  $handler = $view->new_display('page', 'Products List', 'products');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['group'] = 1;
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    10 => 0,
    8 => 0,
    7 => 0,
    5 => 0,
    6 => 0,
    9 => 0,
    4 => 0,
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Title or SKU';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_code_p' => 'field_code_p',
    'title' => 'title',
    'sku' => 'sku',
  );
  /* Filter criterion: Content: Product Series (field_product_series) */
  $handler->display->display_options['filters']['field_product_series_tid']['id'] = 'field_product_series_tid';
  $handler->display->display_options['filters']['field_product_series_tid']['table'] = 'field_data_field_product_series';
  $handler->display->display_options['filters']['field_product_series_tid']['field'] = 'field_product_series_tid';
  $handler->display->display_options['filters']['field_product_series_tid']['relationship'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['filters']['field_product_series_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_product_series_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['operator_id'] = 'field_product_series_tid_op';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['label'] = 'Product Series';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['operator'] = 'field_product_series_tid_op';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['identifier'] = 'field_product_series_tid';
  $handler->display->display_options['filters']['field_product_series_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_product_series_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_product_series_tid']['vocabulary'] = 'product_series';
  /* Filter criterion: Published (selective) */
  $handler->display->display_options['filters']['status_selective']['id'] = 'status_selective';
  $handler->display->display_options['filters']['status_selective']['table'] = 'node';
  $handler->display->display_options['filters']['status_selective']['field'] = 'status_selective';
  $handler->display->display_options['filters']['status_selective']['ui_name'] = 'Published (selective)';
  $handler->display->display_options['filters']['status_selective']['group'] = 1;
  $handler->display->display_options['filters']['status_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_selective']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status_selective']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['status_selective']['expose']['identifier'] = 'status_selective';
  $handler->display->display_options['filters']['status_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['status_selective']['selective_display_field'] = 'status';
  $handler->display->display_options['filters']['status_selective']['selective_items_limit'] = '100';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Updated Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.changed' => 'node.changed',
  );
  $handler->display->display_options['path'] = 'admin/dashboard/products';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Products List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'field_sku_products_product_id';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Content: Product Series */
  $handler->display->display_options['fields']['field_product_series']['id'] = 'field_product_series';
  $handler->display->display_options['fields']['field_product_series']['table'] = 'field_data_field_product_series';
  $handler->display->display_options['fields']['field_product_series']['field'] = 'field_product_series';
  $handler->display->display_options['fields']['field_product_series']['relationship'] = 'field_parent_product_range_target_id';
  $handler->display->display_options['fields']['field_product_series']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_product_series']['group_column'] = 'entity_id';
  $handler->display->display_options['path'] = 'admin/dashboard/products/csv';
  $handler->display->display_options['displays'] = array(
    'products' => 'products',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/dashboard/products';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['dashboard_product_list'] = array(
    t('Master'),
    t('Products List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('SKU'),
    t('Content entity referenced from field_parent_product_range'),
    t('Product Code'),
    t('Content'),
    t('- Choose an operation -'),
    t('Nid'),
    t('Title'),
    t('Product Series'),
    t('Published'),
    t('Updated date'),
    t('View'),
    t('Edit'),
    t('Part Number'),
    t('Publish'),
    t('Clone'),
    t('Delete'),
    t('Title or SKU'),
    t('Updated Date'),
    t('Data export'),
  );
  $export['dashboard_product_list'] = $view;

  $view = new view();
  $view->name = 'dashboard_projects';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_project';
  $view->human_name = 'Dashboard Projects';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Projects List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    11 => '11',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'id' => 'id',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'mail' => 'mail',
    'field_project_title' => 'field_project_title',
    'created' => 'created',
    'view_link' => 'view_link',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_project_title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Project: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_project';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Project: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_project';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = 'Project title';
  /* Field: Project: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_project';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Project: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_project';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'View';
  $handler->display->display_options['fields']['view_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_link']['alter']['text'] = '<a href="/user/[uid]/projects/[id]">View</a>';
  /* Sort criterion: Project: Id */
  $handler->display->display_options['sorts']['id']['id'] = 'id';
  $handler->display->display_options['sorts']['id']['table'] = 'eck_project';
  $handler->display->display_options['sorts']['id']['field'] = 'id';
  $handler->display->display_options['sorts']['id']['order'] = 'DESC';
  /* Filter criterion: Project: project type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_project';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'project' => 'project',
  );
  /* Filter criterion: User: First name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_first_name_value']['group_info']['label'] = 'First name (field_first_name)';
  $handler->display->display_options['filters']['field_first_name_value']['group_info']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_first_name_value']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: User: Last name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'uid';
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['relationship'] = 'uid';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );

  /* Display: Projects List */
  $handler = $view->new_display('page', 'Projects List', 'projects');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Project: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_project';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = 'Project title';
  /* Field: Project: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_project';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Project: Link */
  $handler->display->display_options['fields']['view_link']['id'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['table'] = 'eck_project';
  $handler->display->display_options['fields']['view_link']['field'] = 'view_link';
  $handler->display->display_options['fields']['view_link']['label'] = 'View';
  $handler->display->display_options['fields']['view_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_link']['alter']['text'] = '<a href="/user/[uid]/projects/[id]">View</a>';
  $handler->display->display_options['path'] = 'admin/dashboard/projects';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Projects List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Projects Export */
  $handler = $view->new_display('views_data_export', 'Projects Export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'projects-list-%timestamp-full .csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 0;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 1;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Project: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_project';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Project: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_project';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Field: Project: Title */
  $handler->display->display_options['fields']['field_project_title']['id'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['table'] = 'field_data_field_project_title';
  $handler->display->display_options['fields']['field_project_title']['field'] = 'field_project_title';
  $handler->display->display_options['fields']['field_project_title']['label'] = 'Project title';
  /* Field: Project: Project Part Number SKU */
  $handler->display->display_options['fields']['project_part_number_sku']['id'] = 'project_part_number_sku';
  $handler->display->display_options['fields']['project_part_number_sku']['table'] = 'project';
  $handler->display->display_options['fields']['project_part_number_sku']['field'] = 'project_part_number_sku';
  $handler->display->display_options['fields']['project_part_number_sku']['label'] = 'Part Number';
  /* Field: Project: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_project';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D m/d/Y - H:i';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['path'] = 'admin/dashboard/projects/export';
  $handler->display->display_options['displays'] = array(
    'projects' => 'projects',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'admin/dashboard/projects';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['dashboard_projects'] = array(
    t('Master'),
    t('Projects List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('User'),
    t('Id'),
    t('.'),
    t(','),
    t('First name'),
    t('Last name'),
    t('E-mail'),
    t('Project title'),
    t('Created'),
    t('View'),
    t('<a href="/user/[uid]/projects/[id]">View</a>'),
    t('First name (field_first_name)'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Projects Export'),
    t('Part Number'),
  );
  $export['dashboard_projects'] = $view;

  $view = new view();
  $view->name = 'dashboard_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Dashboard - Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dashboard - Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'uid' => 'uid',
    'created' => 'created',
    'access' => 'access',
    'field_ect_customer_number' => 'field_ect_customer_number',
    'name' => 'name',
    'field_postal_address_last_name' => 'field_postal_address_last_name',
    'field_postal_address_first_name' => 'field_postal_address_first_name',
    'rid' => 'rid',
    'mail' => 'mail',
    'field_order_history_access_st' => 'field_order_history_access_st',
    'status' => 'status',
    'field_subscribe_newsletter' => 'field_subscribe_newsletter',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'access' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ect_customer_number' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_postal_address_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_postal_address_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_order_history_access_st' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_subscribe_newsletter' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_user';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_user_cancel_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'rules_component::rules_unblock_selected_users' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::pathauto_user_update_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Login';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Field: Postal address - Company */
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['id'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['field'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['label'] = 'Company';
  /* Field: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['label'] = 'City';
  /* Field: Field: Postal address - Country */
  $handler->display->display_options['fields']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_postal_address_country']['display_name'] = 1;
  /* Field: User: Access status */
  $handler->display->display_options['fields']['field_order_history_access_st']['id'] = 'field_order_history_access_st';
  $handler->display->display_options['fields']['field_order_history_access_st']['table'] = 'field_data_field_order_history_access_st';
  $handler->display->display_options['fields']['field_order_history_access_st']['field'] = 'field_order_history_access_st';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Subscribe to Newsletter */
  $handler->display->display_options['fields']['field_subscribe_newsletter']['id'] = 'field_subscribe_newsletter';
  $handler->display->display_options['fields']['field_subscribe_newsletter']['table'] = 'field_data_field_subscribe_newsletter';
  $handler->display->display_options['fields']['field_subscribe_newsletter']['field'] = 'field_subscribe_newsletter';
  $handler->display->display_options['fields']['field_subscribe_newsletter']['label'] = 'Newsletter';
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    10 => '10',
    11 => '11',
    14 => '14',
    12 => '12',
    13 => '13',
    8 => '8',
    3 => '3',
    5 => '5',
    4 => '4',
    7 => '7',
    9 => '9',
    16 => '16',
    21 => '21',
    26 => '26',
    31 => '31',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
  );
  $handler->display->display_options['filters']['rid']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: Access status (field_order_history_access_st) */
  $handler->display->display_options['filters']['field_order_history_access_st_value']['id'] = 'field_order_history_access_st_value';
  $handler->display->display_options['filters']['field_order_history_access_st_value']['table'] = 'field_data_field_order_history_access_st';
  $handler->display->display_options['filters']['field_order_history_access_st_value']['field'] = 'field_order_history_access_st_value';
  $handler->display->display_options['filters']['field_order_history_access_st_value']['value'] = array(
    'all' => 'all',
    'none' => 'none',
    'pending' => 'pending',
    'approved' => 'approved',
    'denied' => 'denied',
  );
  $handler->display->display_options['filters']['field_order_history_access_st_value']['group'] = 1;
  $handler->display->display_options['filters']['field_order_history_access_st_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_order_history_access_st_value']['expose']['operator_id'] = 'field_order_history_access_st_value_op';
  $handler->display->display_options['filters']['field_order_history_access_st_value']['expose']['label'] = 'Access status';
  $handler->display->display_options['filters']['field_order_history_access_st_value']['expose']['operator'] = 'field_order_history_access_st_value_op';
  $handler->display->display_options['filters']['field_order_history_access_st_value']['expose']['identifier'] = 'field_order_history_access_st_value';
  $handler->display->display_options['filters']['field_order_history_access_st_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_order_history_access_st_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_order_history_access_st_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['group'] = 1;
  $handler->display->display_options['filters']['uid_raw']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid_raw']['expose']['operator_id'] = 'uid_raw_op';
  $handler->display->display_options['filters']['uid_raw']['expose']['label'] = 'UID';
  $handler->display->display_options['filters']['uid_raw']['expose']['operator'] = 'uid_raw_op';
  $handler->display->display_options['filters']['uid_raw']['expose']['identifier'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: First name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'First name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  /* Filter criterion: User: Last name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'Last name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    15 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['group'] = 1;
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'users';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = 'All';
  $handler->display->display_options['filters']['status_1']['group'] = 1;
  $handler->display->display_options['filters']['status_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status_1']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status_1']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status_1']['expose']['operator'] = 'status_1_op';
  $handler->display->display_options['filters']['status_1']['expose']['identifier'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  /* Filter criterion: User: Subscribe to Newsletter (field_subscribe_newsletter) */
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['id'] = 'field_subscribe_newsletter_value';
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['table'] = 'field_data_field_subscribe_newsletter';
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['field'] = 'field_subscribe_newsletter_value';
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['value'] = array(
    'all' => 'all',
    0 => '0',
    1 => '1',
  );
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['group'] = 1;
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['expose']['operator_id'] = 'field_subscribe_newsletter_value_op';
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['expose']['label'] = 'Newsletter';
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['expose']['operator'] = 'field_subscribe_newsletter_value_op';
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['expose']['identifier'] = 'field_subscribe_newsletter_value';
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['field_subscribe_newsletter_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw_1']['id'] = 'uid_raw_1';
  $handler->display->display_options['filters']['uid_raw_1']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw_1']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw_1']['operator'] = '!=';
  $handler->display->display_options['filters']['uid_raw_1']['value']['value'] = '0';
  $handler->display->display_options['filters']['uid_raw_1']['group'] = 1;
  /* Filter criterion: Date: Date (users) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'users';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Created Date';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    6 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    16 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['group_info']['label'] = 'Date (users)';
  $handler->display->display_options['filters']['date_filter']['group_info']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['date_filter']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'users.created' => 'users.created',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/dashboard/users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Users';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['newline_token'] = '1';
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Addressbook: Profile ID */
  $handler->display->display_options['relationships']['profile_id']['id'] = 'profile_id';
  $handler->display->display_options['relationships']['profile_id']['table'] = 'commerce_addressbook_defaults';
  $handler->display->display_options['relationships']['profile_id']['field'] = 'profile_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  $handler->display->display_options['fields']['access']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Login';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Field: Postal address - Company */
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['id'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['field'] = 'field_postal_address_organisation_name';
  $handler->display->display_options['fields']['field_postal_address_organisation_name']['label'] = 'Company';
  /* Field: Field: Postal address - Locality (i.e. City) */
  $handler->display->display_options['fields']['field_postal_address_locality']['id'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_locality']['field'] = 'field_postal_address_locality';
  $handler->display->display_options['fields']['field_postal_address_locality']['label'] = 'City';
  /* Field: Field: Postal address - Country */
  $handler->display->display_options['fields']['field_postal_address_country']['id'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['table'] = 'field_data_field_postal_address';
  $handler->display->display_options['fields']['field_postal_address_country']['field'] = 'field_postal_address_country';
  $handler->display->display_options['fields']['field_postal_address_country']['label'] = 'Country';
  $handler->display->display_options['fields']['field_postal_address_country']['display_name'] = 1;
  /* Field: User: Access status */
  $handler->display->display_options['fields']['field_order_history_access_st']['id'] = 'field_order_history_access_st';
  $handler->display->display_options['fields']['field_order_history_access_st']['table'] = 'field_data_field_order_history_access_st';
  $handler->display->display_options['fields']['field_order_history_access_st']['field'] = 'field_order_history_access_st';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Subscribe to Newsletter */
  $handler->display->display_options['fields']['field_subscribe_newsletter']['id'] = 'field_subscribe_newsletter';
  $handler->display->display_options['fields']['field_subscribe_newsletter']['table'] = 'field_data_field_subscribe_newsletter';
  $handler->display->display_options['fields']['field_subscribe_newsletter']['field'] = 'field_subscribe_newsletter';
  $handler->display->display_options['fields']['field_subscribe_newsletter']['label'] = 'Newsletter';
  /* Field: Commerce Customer profile: Address - Full name */
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['id'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['field'] = 'commerce_customer_address_name_line';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['relationship'] = 'profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['alter']['text'] = '[commerce_customer_address_name_line],';
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_name_line']['hide_empty'] = TRUE;
  /* Field: Commerce Customer profile: Address - Postal code */
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['id'] = 'commerce_customer_address_postal_code';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['field'] = 'commerce_customer_address_postal_code';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['relationship'] = 'profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['alter']['text'] = '[commerce_customer_address_postal_code],';
  $handler->display->display_options['fields']['commerce_customer_address_postal_code']['element_label_colon'] = FALSE;
  /* Field: Commerce Customer profile: Address - Locality (i.e. City) */
  $handler->display->display_options['fields']['commerce_customer_address_locality']['id'] = 'commerce_customer_address_locality';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['field'] = 'commerce_customer_address_locality';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['relationship'] = 'profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_locality']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_locality']['alter']['text'] = '[commerce_customer_address_locality],';
  $handler->display->display_options['fields']['commerce_customer_address_locality']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_locality']['hide_empty'] = TRUE;
  /* Field: Commerce Customer profile: Address - Thoroughfare (i.e. Street address) */
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['id'] = 'commerce_customer_address_thoroughfare';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['field'] = 'commerce_customer_address_thoroughfare';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['relationship'] = 'profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['alter']['text'] = '[commerce_customer_address_thoroughfare],';
  $handler->display->display_options['fields']['commerce_customer_address_thoroughfare']['element_label_colon'] = FALSE;
  /* Field: Commerce Customer profile: Address - Country */
  $handler->display->display_options['fields']['commerce_customer_address_country']['id'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['table'] = 'field_data_commerce_customer_address';
  $handler->display->display_options['fields']['commerce_customer_address_country']['field'] = 'commerce_customer_address_country';
  $handler->display->display_options['fields']['commerce_customer_address_country']['relationship'] = 'profile_id';
  $handler->display->display_options['fields']['commerce_customer_address_country']['label'] = '';
  $handler->display->display_options['fields']['commerce_customer_address_country']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['alter']['text'] = '[commerce_customer_address_country].';
  $handler->display->display_options['fields']['commerce_customer_address_country']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_customer_address_country']['display_name'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Shipping info';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[commerce_customer_address_name_line][commerce_customer_address_postal_code][commerce_customer_address_locality][commerce_customer_address_thoroughfare][commerce_customer_address_country]';
  $handler->display->display_options['path'] = 'admin/dashboard/users/csv';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['dashboard_users'] = array(
    t('Master'),
    t('Dashboard - Users'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('User'),
    t('- Choose an operation -'),
    t('Uid'),
    t('Created'),
    t('Last access'),
    t('Login'),
    t('Roles'),
    t('E-mail'),
    t('Company'),
    t('City'),
    t('Country'),
    t('Access status'),
    t('Active'),
    t('Newsletter'),
    t('Edit'),
    t('UID'),
    t('First name'),
    t('Last name'),
    t('Created Date'),
    t('Date (users)'),
    t('Page'),
    t('Data export'),
    t('Profile'),
    t('[commerce_customer_address_name_line],'),
    t('[commerce_customer_address_postal_code],'),
    t('[commerce_customer_address_locality],'),
    t('[commerce_customer_address_thoroughfare],'),
    t('[commerce_customer_address_country].'),
    t('Shipping info'),
    t('[commerce_customer_address_name_line][commerce_customer_address_postal_code][commerce_customer_address_locality][commerce_customer_address_thoroughfare][commerce_customer_address_country]'),
  );
  $export['dashboard_users'] = $view;

  $view = new view();
  $view->name = 'news_tags';
  $view->description = 'List all terms used by newses';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'News Tags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'News Tags';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    51 => '51',
    11 => '11',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['label'] = 'Results Summary';
  /* Relationship: Taxonomy term: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Field: Bulk operations: Taxonomy term */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_taxonomy_term';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = 'Select Taxonomy term';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: COUNT(Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid']['label'] = 'Usage Count';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tags' => 'tags',
  );
  /* Filter criterion: COUNT(Content: Nid) */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['relationship'] = 'nid';
  $handler->display->display_options['filters']['nid']['group_type'] = 'count';
  $handler->display->display_options['filters']['nid']['operator'] = '>=';
  $handler->display->display_options['filters']['nid']['value']['value'] = '0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/dashboard/news-tags';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'News Tags';
  $handler->display->display_options['menu']['description'] = 'List all tags used by news pages';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['news_tags'] = array(
    t('Master'),
    t('News Tags'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Results Summary'),
    t('Displaying @start - @end of @total'),
    t('node'),
    t('Select Taxonomy term'),
    t('- Choose an operation -'),
    t('Name'),
    t('Usage Count'),
    t('Page'),
  );
  $export['news_tags'] = $view;

  $view = new view();
  $view->name = 'part_numbers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_product';
  $view->human_name = 'Dashboard Souriau Part Numbers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Part Numbers(SKU) List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    11 => '11',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'product_id' => 'product_id',
    'sku' => 'sku',
    'field_sku_view_in_regions' => 'field_sku_view_in_regions',
    'field_view_exception' => 'field_sku_view_in_regions',
    'field_sku_samples_in_regions' => 'field_sku_samples_in_regions',
    'field_samples_exception' => 'field_sku_samples_in_regions',
    'field_sku_company' => 'field_sku_company',
    'status' => 'status',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = 'product_id';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'product_id' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'sku' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sku_view_in_regions' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', except: ',
      'empty_column' => 0,
    ),
    'field_view_exception' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sku_samples_in_regions' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => ', except: ',
      'empty_column' => 0,
    ),
    'field_samples_exception' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_sku_company' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations' => array(
      'align' => '',
      'separator' => ' ',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Commerce Product */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_commerce_product';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
  );
  /* Field: Commerce Product: Product ID */
  $handler->display->display_options['fields']['product_id']['id'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['product_id']['field'] = 'product_id';
  $handler->display->display_options['fields']['product_id']['label'] = 'ID';
  $handler->display->display_options['fields']['product_id']['link_to_product'] = 0;
  /* Field: Commerce Product: SKU */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Field: Commerce Product: View all */
  $handler->display->display_options['fields']['field_sku_view_in_regions']['id'] = 'field_sku_view_in_regions';
  $handler->display->display_options['fields']['field_sku_view_in_regions']['table'] = 'field_data_field_sku_view_in_regions';
  $handler->display->display_options['fields']['field_sku_view_in_regions']['field'] = 'field_sku_view_in_regions';
  $handler->display->display_options['fields']['field_sku_view_in_regions']['label'] = 'View All';
  $handler->display->display_options['fields']['field_sku_view_in_regions']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sku_view_in_regions']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['field_sku_view_in_regions']['empty'] = 'No';
  $handler->display->display_options['fields']['field_sku_view_in_regions']['empty_zero'] = TRUE;
  /* Field: Commerce Product: View exception */
  $handler->display->display_options['fields']['field_view_exception']['id'] = 'field_view_exception';
  $handler->display->display_options['fields']['field_view_exception']['table'] = 'field_data_field_view_exception';
  $handler->display->display_options['fields']['field_view_exception']['field'] = 'field_view_exception';
  $handler->display->display_options['fields']['field_view_exception']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_view_exception']['type'] = 'text_plain';
  $handler->display->display_options['fields']['field_view_exception']['delta_offset'] = '0';
  /* Field: Commerce Product: Samples all */
  $handler->display->display_options['fields']['field_sku_samples_in_regions']['id'] = 'field_sku_samples_in_regions';
  $handler->display->display_options['fields']['field_sku_samples_in_regions']['table'] = 'field_data_field_sku_samples_in_regions';
  $handler->display->display_options['fields']['field_sku_samples_in_regions']['field'] = 'field_sku_samples_in_regions';
  $handler->display->display_options['fields']['field_sku_samples_in_regions']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_sku_samples_in_regions']['alter']['text'] = 'Yes';
  $handler->display->display_options['fields']['field_sku_samples_in_regions']['empty'] = 'No';
  $handler->display->display_options['fields']['field_sku_samples_in_regions']['empty_zero'] = TRUE;
  /* Field: Commerce Product: Samples exception */
  $handler->display->display_options['fields']['field_samples_exception']['id'] = 'field_samples_exception';
  $handler->display->display_options['fields']['field_samples_exception']['table'] = 'field_data_field_samples_exception';
  $handler->display->display_options['fields']['field_samples_exception']['field'] = 'field_samples_exception';
  $handler->display->display_options['fields']['field_samples_exception']['delta_offset'] = '0';
  /* Field: Commerce Product: Brand */
  $handler->display->display_options['fields']['field_sku_company']['id'] = 'field_sku_company';
  $handler->display->display_options['fields']['field_sku_company']['table'] = 'field_data_field_sku_company';
  $handler->display->display_options['fields']['field_sku_company']['field'] = 'field_sku_company';
  $handler->display->display_options['fields']['field_sku_company']['label'] = 'Company';
  /* Field: Commerce Product: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'active-disabled';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Commerce Product: Operations links */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Operations';
  $handler->display->display_options['fields']['operations']['add_destination'] = 1;
  /* Filter criterion: Commerce Product: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'sku' => 'sku',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Commerce Product: Product ID */
  $handler->display->display_options['filters']['product_id']['id'] = 'product_id';
  $handler->display->display_options['filters']['product_id']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['product_id']['field'] = 'product_id';
  $handler->display->display_options['filters']['product_id']['group'] = 1;
  $handler->display->display_options['filters']['product_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['product_id']['expose']['operator_id'] = 'product_id_op';
  $handler->display->display_options['filters']['product_id']['expose']['label'] = 'Product ID';
  $handler->display->display_options['filters']['product_id']['expose']['operator'] = 'product_id_op';
  $handler->display->display_options['filters']['product_id']['expose']['identifier'] = 'product_id';
  $handler->display->display_options['filters']['product_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Commerce Product: SKU */
  $handler->display->display_options['filters']['sku']['id'] = 'sku';
  $handler->display->display_options['filters']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['filters']['sku']['field'] = 'sku';
  $handler->display->display_options['filters']['sku']['group'] = 1;
  $handler->display->display_options['filters']['sku']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sku']['expose']['operator_id'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['label'] = 'SKU';
  $handler->display->display_options['filters']['sku']['expose']['operator'] = 'sku_op';
  $handler->display->display_options['filters']['sku']['expose']['identifier'] = 'sku';
  $handler->display->display_options['filters']['sku']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );
  /* Filter criterion: Commerce Product: Brand (field_sku_company) */
  $handler->display->display_options['filters']['field_sku_company_value']['id'] = 'field_sku_company_value';
  $handler->display->display_options['filters']['field_sku_company_value']['table'] = 'field_data_field_sku_company';
  $handler->display->display_options['filters']['field_sku_company_value']['field'] = 'field_sku_company_value';
  $handler->display->display_options['filters']['field_sku_company_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_sku_company_value']['group'] = 1;
  $handler->display->display_options['filters']['field_sku_company_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_sku_company_value']['expose']['operator_id'] = 'field_sku_company_value_op';
  $handler->display->display_options['filters']['field_sku_company_value']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_sku_company_value']['expose']['operator'] = 'field_sku_company_value_op';
  $handler->display->display_options['filters']['field_sku_company_value']['expose']['identifier'] = 'field_sku_company_value';
  $handler->display->display_options['filters']['field_sku_company_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'sku_list');
  $handler->display->display_options['path'] = 'admin/dashboard/sku';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'SKU list';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['part_numbers'] = array(
    t('Master'),
    t('Part Numbers(SKU) List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Commerce Product'),
    t('- Choose an operation -'),
    t('ID'),
    t('SKU'),
    t('View All'),
    t('Yes'),
    t('No'),
    t('View exception'),
    t('Samples all'),
    t('Samples exception'),
    t('Company'),
    t('Status'),
    t('Operations'),
    t('Product ID'),
    t('Page'),
  );
  $export['part_numbers'] = $view;

  $view = new view();
  $view->name = 'souriau_dashboard_files';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'souriau_dashboard_files';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Dashboard files';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any unpublished files';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'fid' => 'fid',
    'filename' => 'filename',
    'type' => 'type',
    'filesize' => 'filesize',
    'timestamp' => 'timestamp',
    'usage' => 'usage',
    'published' => 'published',
    'edit' => 'edit',
    'delete' => 'delete',
  );
  $handler->display->display_options['style_options']['default'] = 'timestamp';
  $handler->display->display_options['style_options']['info'] = array(
    'fid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filename' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'filesize' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'usage' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'published' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Footer: Global: Result summary */
  $handler->display->display_options['footer']['result']['id'] = 'result';
  $handler->display->display_options['footer']['result']['table'] = 'views';
  $handler->display->display_options['footer']['result']['field'] = 'result';
  $handler->display->display_options['footer']['result']['label'] = 'Results Summary';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No Files found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: File: User who uploaded */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'file_managed';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::file_admin_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::file_admin_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'file_managed';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: File: Usage link */
  $handler->display->display_options['fields']['usage']['id'] = 'usage';
  $handler->display->display_options['fields']['usage']['table'] = 'file_managed';
  $handler->display->display_options['fields']['usage']['field'] = 'usage';
  $handler->display->display_options['fields']['usage']['label'] = 'Used in';
  /* Field: File: Published */
  $handler->display->display_options['fields']['published']['id'] = 'published';
  $handler->display->display_options['fields']['published']['table'] = 'file_managed';
  $handler->display->display_options['fields']['published']['field'] = 'published';
  $handler->display->display_options['fields']['published']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['published']['not'] = 0;
  /* Field: File: Edit link */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'file_managed';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['label'] = 'Edit';
  /* Field: File: Delete link */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'file_managed';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = 'Delete';
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    '3d_model' => '3d_model',
    'audio' => 'audio',
    'document' => 'document',
    'video' => 'video',
    'ipaper' => 'ipaper',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: File: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'file_managed';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = 'All';
  $handler->display->display_options['filters']['published']['group'] = 1;
  $handler->display->display_options['filters']['published']['exposed'] = TRUE;
  $handler->display->display_options['filters']['published']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['published']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['published']['expose']['operator'] = 'published_op';
  $handler->display->display_options['filters']['published']['expose']['identifier'] = 'published';
  $handler->display->display_options['filters']['published']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: File: Path */
  $handler->display->display_options['filters']['uri']['id'] = 'uri';
  $handler->display->display_options['filters']['uri']['table'] = 'file_managed';
  $handler->display->display_options['filters']['uri']['field'] = 'uri';
  $handler->display->display_options['filters']['uri']['operator'] = 'not';
  $handler->display->display_options['filters']['uri']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uri']['expose']['operator_id'] = 'uri_op';
  $handler->display->display_options['filters']['uri']['expose']['label'] = 'Path';
  $handler->display->display_options['filters']['uri']['expose']['description'] = 'Choose "does not contain" and use "multimedia" in path to view download center files';
  $handler->display->display_options['filters']['uri']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['uri']['expose']['operator'] = 'uri_op';
  $handler->display->display_options['filters']['uri']['expose']['identifier'] = 'uri';
  $handler->display->display_options['filters']['uri']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    11 => 0,
    14 => 0,
    12 => 0,
    13 => 0,
    8 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    9 => 0,
    16 => 0,
    21 => 0,
    26 => 0,
    31 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any unpublished files';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::file_admin_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::file_admin_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'file_managed';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['machine_name'] = 0;
  /* Field: File: Document type */
  $handler->display->display_options['fields']['field_document_type']['id'] = 'field_document_type';
  $handler->display->display_options['fields']['field_document_type']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['fields']['field_document_type']['field'] = 'field_document_type';
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: File: Usage link */
  $handler->display->display_options['fields']['usage']['id'] = 'usage';
  $handler->display->display_options['fields']['usage']['table'] = 'file_managed';
  $handler->display->display_options['fields']['usage']['field'] = 'usage';
  $handler->display->display_options['fields']['usage']['label'] = 'Used in';
  /* Field: File: Published */
  $handler->display->display_options['fields']['published']['id'] = 'published';
  $handler->display->display_options['fields']['published']['table'] = 'file_managed';
  $handler->display->display_options['fields']['published']['field'] = 'published';
  $handler->display->display_options['fields']['published']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['published']['not'] = 0;
  /* Field: File: Edit link */
  $handler->display->display_options['fields']['edit']['id'] = 'edit';
  $handler->display->display_options['fields']['edit']['table'] = 'file_managed';
  $handler->display->display_options['fields']['edit']['field'] = 'edit';
  $handler->display->display_options['fields']['edit']['label'] = 'Edit';
  /* Field: File: Delete link */
  $handler->display->display_options['fields']['delete']['id'] = 'delete';
  $handler->display->display_options['fields']['delete']['table'] = 'file_managed';
  $handler->display->display_options['fields']['delete']['field'] = 'delete';
  $handler->display->display_options['fields']['delete']['label'] = 'Delete';
  $handler->display->display_options['path'] = 'admin/dashboard/files';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Files';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Site Images */
  $handler = $view->new_display('page', 'Site Images', 'site_images');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Site images';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Bulk operations: File */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_file';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'log' => 0,
      ),
    ),
    'action::file_admin_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::file_admin_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: File: File ID */
  $handler->display->display_options['fields']['fid']['id'] = 'fid';
  $handler->display->display_options['fields']['fid']['table'] = 'file_managed';
  $handler->display->display_options['fields']['fid']['field'] = 'fid';
  $handler->display->display_options['fields']['fid']['label'] = '';
  $handler->display->display_options['fields']['fid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['fid']['element_label_colon'] = FALSE;
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['link_to_file'] = TRUE;
  /* Field: File: Size */
  $handler->display->display_options['fields']['filesize']['id'] = 'filesize';
  $handler->display->display_options['fields']['filesize']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filesize']['field'] = 'filesize';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Resolution';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[uri]';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  /* Field: File: Upload date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: File: Usage link */
  $handler->display->display_options['fields']['usage']['id'] = 'usage';
  $handler->display->display_options['fields']['usage']['table'] = 'file_managed';
  $handler->display->display_options['fields']['usage']['field'] = 'usage';
  $handler->display->display_options['fields']['usage']['label'] = 'Used in';
  /* Field: File: Published */
  $handler->display->display_options['fields']['published']['id'] = 'published';
  $handler->display->display_options['fields']['published']['table'] = 'file_managed';
  $handler->display->display_options['fields']['published']['field'] = 'published';
  $handler->display->display_options['fields']['published']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['published']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: File: Published */
  $handler->display->display_options['filters']['published']['id'] = 'published';
  $handler->display->display_options['filters']['published']['table'] = 'file_managed';
  $handler->display->display_options['filters']['published']['field'] = 'published';
  $handler->display->display_options['filters']['published']['value'] = 'All';
  $handler->display->display_options['filters']['published']['group'] = 1;
  $handler->display->display_options['filters']['published']['exposed'] = TRUE;
  $handler->display->display_options['filters']['published']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['published']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['published']['expose']['operator'] = 'published_op';
  $handler->display->display_options['filters']['published']['expose']['identifier'] = 'published';
  $handler->display->display_options['filters']['published']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    10 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: File: Mime type */
  $handler->display->display_options['filters']['filemime']['id'] = 'filemime';
  $handler->display->display_options['filters']['filemime']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filemime']['field'] = 'filemime';
  $handler->display->display_options['filters']['filemime']['operator'] = 'starts';
  $handler->display->display_options['filters']['filemime']['value'] = 'image/';
  /* Filter criterion: File: Path */
  $handler->display->display_options['filters']['uri']['id'] = 'uri';
  $handler->display->display_options['filters']['uri']['table'] = 'file_managed';
  $handler->display->display_options['filters']['uri']['field'] = 'uri';
  $handler->display->display_options['filters']['uri']['operator'] = 'not';
  $handler->display->display_options['filters']['uri']['value'] = '/webform/';
  $handler->display->display_options['path'] = 'admin/dashboard/site-images';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Site Images';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-admin-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['souriau_dashboard_files'] = array(
    t('Master'),
    t('Dashboard files'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Results Summary'),
    t('Displaying @start - @end of @total'),
    t('No Files found.'),
    t('User who uploaded'),
    t('File'),
    t('- Choose an operation -'),
    t('Name'),
    t('Type'),
    t('Size'),
    t('Author'),
    t('Upload date'),
    t('Used in'),
    t('Published'),
    t('Edit'),
    t('Delete'),
    t('Path'),
    t('Choose "does not contain" and use "multimedia" in path to view download center files'),
    t('Page'),
    t('Document type'),
    t('Site Images'),
    t('Site images'),
    t('Resolution'),
    t('[uri]'),
  );
  $export['souriau_dashboard_files'] = $view;

  $view = new view();
  $view->name = 'souriau_poll';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Souriau Poll';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Souriau Poll';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    10 => '10',
    11 => '11',
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = 'Delete';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Results';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'View poll result';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/advpoll/results';
  $handler->display->display_options['fields']['nothing']['alter']['alt'] = 'view poll result';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Votes';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'View all votes';
  $handler->display->display_options['fields']['nothing_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['path'] = 'node/[nid]/advpoll/votes';
  $handler->display->display_options['fields']['nothing_1']['alter']['alt'] = 'view poll votes';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'advpoll' => 'advpoll',
  );

  /* Display: Poll */
  $handler = $view->new_display('page', 'Poll', 'page');
  $handler->display->display_options['path'] = 'admin/dashboard/souriau-poll';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Poll';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['souriau_poll'] = array(
    t('Master'),
    t('Souriau Poll'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Nid'),
    t('Title'),
    t('Edit'),
    t('Delete'),
    t('Results'),
    t('View poll result'),
    t('view poll result'),
    t('Votes'),
    t('View all votes'),
    t('view poll votes'),
    t('Poll'),
  );
  $export['souriau_poll'] = $view;

  return $export;
}
