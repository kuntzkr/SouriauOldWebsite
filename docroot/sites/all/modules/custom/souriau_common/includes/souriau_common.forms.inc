<?php

/**
 * @file
 * Souriau Forms.
 */

/**
 * Implements hook_form().
 */
function souriau_common_facets_admin_form($form, &$form_state, $entity = NULL) {
  $facet_settings_variable = 'souriau_common_fasets';
  $facet_settings = variable_get($facet_settings_variable);
  if (!empty($entity->nid)) {
    $facet_settings_variable = "souriau_common_fasets_$entity->nid";
    $facet_settings = variable_get($facet_settings_variable, $facet_settings);
  }
  if (!empty($entity->tid)) {
    $facet_settings_variable = "souriau_common_fasets_term_$entity->tid";
    $facet_settings = variable_get($facet_settings_variable, $facet_settings);
  }
  $weight = 0;

  $form[$facet_settings_variable] = [
    '#theme' => 'souriau_common_table_drag',
    '#tree' => TRUE,
  ];

  foreach (facetapi_get_searcher_info() as $searcher => $searcher_info) {
    if ($searcher_info['instance'] != 'products_search_index') {
      continue;
    }
    foreach (facetapi_get_enabled_facets($searcher) as $facet_name => $facet) {
      $form[$facet_settings_variable][$facet_name] = [
        'label' => [
          '#type' => 'item',
          '#markup' => $facet['label'],
        ],
        'enabled' => [
          '#type' => 'checkbox',
          '#default_value' => isset($facet_settings[$facet_name]['enabled']) ? $facet_settings[$facet_name]['enabled'] : NULL,
        ],
        'weight' => [
          '#type' => 'textfield',
          '#default_value' => isset($facet_settings[$facet_name]['weight']) ? $facet_settings[$facet_name]['weight'] : $weight,
          '#size' => 3,
          '#attributes' => ['class' => ['item-row-weight']],
        ],
        '#weight' => isset($facet_settings[$facet_name]['weight']) ? $facet_settings[$facet_name]['weight'] : $weight,
      ];
      $weight++;
    }
  }

  $form = system_settings_form($form);

  if (!empty($entity->nid) && $entity->is_draft) {
    $form['actions']['publish'] = [
      '#type' => 'submit',
      '#value' => t('Publish configuration'),
      '#submit' => ['souriau_common_published_form_submit'],
    ];
  }

  return $form;
}

/**
 * Implements hook_form().
 */
function souriau_common_dc_facets_admin_form($form, &$form_state, $entity = NULL) {

  $facet_settings_variable = "souriau_common_dc_facets_term_$entity->tid";
  $facet_settings = variable_get($facet_settings_variable);
  $weight = 0;

  $form[$facet_settings_variable] = [
    '#theme' => 'souriau_common_table_drag',
    '#tree' => TRUE,
  ];

  $index_name = 'download_center_index';
  $results = [];
  $filters = souriau_dc_filter_settings();

  // Create Search_API objects.
  list($index, $service) = _souriau_common_get_search_api_objects($index_name);

  // Get filters values.
  $query = new SearchApiQuery($index);
  $facets = [];

  $facets['dc_reference_productrange'] = [
    'field' => 'dc_reference_productrange',
    'limit' => 100,
    'min_count' => 0,
    'missing' => FALSE,
  ];

  $query->setOption('search_api_facets', $facets);
  // SET LIMIT, for getting 'facet values' we can use only 1 item for request.
  $query->range(NULL, 1);
  // No fields.
  $query->fields([]);
  // Filter values.
  $search_result = $service->search($query);

  $field_info = [
    'solr_field' => 'dc_reference_productrange',
    'solr_field_type' => 'view',
    'placeholder' => t('All product range', [], ['context' => SOURIAU_COMMON_T_OTHER]),
  ];

  $dc_result = souriau_dc_get_cached_filter_values($field_info, $search_result['search_api_facets']['dc_reference_productrange']);

  foreach ($dc_result as $facet_id => $facet_label) {
    $form[$facet_settings_variable][$facet_label] = [
      'label' => [
        '#type' => 'item',
        '#markup' => $facet_label,
      ],
      'enabled' => [
        '#type' => 'checkbox',
        '#default_value' => isset($facet_settings[$facet_label]['enabled']) ? $facet_settings[$facet_label]['enabled'] : NULL,
      ],
      'nid' => [
        '#type' => 'hidden',
        '#default_value' => isset($facet_settings[$facet_label]['nid']) ? $facet_settings[$facet_label]['nid'] : $facet_id,
      ],
      'weight' => [
        '#type' => 'textfield',
        '#default_value' => isset($facet_settings[$facet_label]['weight']) ? $facet_settings[$facet_label]['weight'] : $weight,
        '#size' => 3,
        '#attributes' => ['class' => ['item-row-weight']],
      ],
      '#weight' => isset($facet_settings[$facet_label]['weight']) ? $facet_settings[$facet_label]['weight'] : $weight,
    ];
    $weight++;
  }

  $form = system_settings_form($form);

  if (!empty($entity->nid) && $entity->is_draft) {
    $form['actions']['publish'] = [
      '#type' => 'submit',
      '#value' => t('Publish configuration'),
      '#submit' => ['souriau_common_published_form_submit'],
    ];
  }

  return $form;
}

/**
 * Implements hook_form().
 */
function souriau_common_dc_application_admin_form($form, &$form_state, $entity = NULL) {
  $facet_settings_variable = 'souriau_common_dc_applications';
  $facet_settings = variable_get($facet_settings_variable);

  $weight = 0;

  $form[$facet_settings_variable] = [
    '#theme' => 'souriau_common_table_drag',
    '#tree' => TRUE,
  ];

  $query = new EntityFieldQuery();

  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'applicationdomain')
    ->propertyCondition('status', 1);

  $result = $query->execute();

  if (!empty($result['node'])) {
    $nids = array_keys($result['node']);

    foreach ($nids as $nid) {
      $node_wrapper = entity_metadata_wrapper('node', $nid);
      $title = $node_wrapper->title->value();

      $form[$facet_settings_variable][$title] = [
        'label' => [
          '#type' => 'item',
          '#markup' => $title,
        ],
        'enabled' => [
          '#type' => 'checkbox',
          '#default_value' => isset($facet_settings[$title]['enabled']) ? $facet_settings[$title]['enabled'] : NULL,
        ],
        'nid' => [
          '#type' => 'hidden',
          '#default_value' => isset($facet_settings[$title]['nid']) ? $facet_settings[$title]['nid'] : $nid,
        ],
        'weight' => [
          '#type' => 'textfield',
          '#default_value' => isset($facet_settings[$title]['weight']) ? $facet_settings[$title]['weight'] : $weight,
          '#size' => 3,
          '#attributes' => ['class' => ['item-row-weight']],
        ],
        '#weight' => isset($facet_settings[$title]['weight']) ? $facet_settings[$title]['weight'] : $weight,
      ];
      $weight++;
    }
  }

  $form = system_settings_form($form);

  if (!empty($entity->nid) && $entity->is_draft) {
    $form['actions']['publish'] = [
      '#type' => 'submit',
      '#value' => t('Publish configuration'),
      '#submit' => ['souriau_common_published_form_submit'],
    ];
  }

  return $form;
}

/**
 * Category facets publish submit handler.
 */
function souriau_common_published_form_submit($form, &$form_state) {
  if (!isset($form_state['build_info']['args'][0])) {
    return;
  }
  system_settings_form_submit($form, $form_state);
  $draft = $form_state['build_info']['args'][0];

  $_domain = domain_get_domain();
  $global_facet_settings = variable_get('souriau_common_fasets');
  $draft_facet_settings = variable_get("souriau_common_fasets_{$draft->nid}", $global_facet_settings);
  domain_conf_variable_set($_domain['domain_id'], "souriau_common_fasets_{$draft->edition_id}", $draft_facet_settings);
}

/**
 * Implements hook_form().
 */
function souriau_common_sku_attributes_admin_form($form, &$form_state) {
  $sku_attributes = variable_get('souriau_common_sku_attributes');
  $weight = 0;

  $form['souriau_common_sku_attributes'] = [
    '#theme' => 'souriau_common_table_drag',
    '#tree' => TRUE,
  ];

  $field_except = [
    'sku',
    'field_sku_view_in_regions',
    'field_view_exception',
    'field_sku_samples_in_regions',
    'field_samples_exception',
    'field_sku_legacy',
    'field_sku_product_series_code',
    'commerce_price',
    'field_sku_application',
    'field_sku_images',
    'field_sku_attachments',
    'field_sku_3d_model',
    'title_field',
    'field_sku_company',
  ];
  // View mode.
  $view_mode_settings = field_view_mode_settings('commerce_product', 'product');
  foreach (field_info_instances('commerce_product', 'sku') as $field_name => $instance) {
    if (in_array($field_name, $field_except)) {
      continue;
    }

    // Load display.
    $actual_mode = (!empty($view_mode_settings['part_number']['custom_settings']) ? 'part_number' : 'default');
    $display = $instance['display'][$actual_mode];

    if ($display['type'] == 'hidden') {
      continue;
    }

    $form['souriau_common_sku_attributes'][$field_name] = [
      'label' => [
        '#type' => 'item',
        '#markup' => $instance['label'],
      ],
      'enabled' => [
        '#type' => 'checkbox',
        '#default_value' => isset($sku_attributes[$field_name]['enabled']) ? $sku_attributes[$field_name]['enabled'] : 1,
      ],
      'weight' => [
        '#type' => 'textfield',
        '#default_value' => isset($sku_attributes[$field_name]['weight']) ? $sku_attributes[$field_name]['weight'] : $weight,
        '#size' => 3,
        '#attributes' => ['class' => ['item-row-weight']],
      ],
      '#weight' => isset($sku_attributes[$field_name]['weight']) ? $sku_attributes[$field_name]['weight'] : $weight,
    ];
    $weight++;
  }

  return system_settings_form($form);
}

/**
 * Implements hook_form().
 */
function souriau_common_main_menu_form($form, &$form_state) {
  global $user;
  $settings = variable_get('souriau_common_main_menu_form', []);
  $settings_sync = variable_get('souriau_common_main_menu_form_sync', []);

  // Load menu.
  $menu = menu_load(SOURIAU_COMMON_VAR_HEADER_MENU);

  // Get default menu form.
  module_load_include('admin.inc', 'menu');
  $form = [];
  $form_state['build_info']['args'] = [$menu];
  $form = menu_overview_form($form, $form_state, $menu);
  unset($form['actions']);

  // Add our modification to form.
  $disabled = [];
  foreach (element_children($form) as $key) {
    $field = &$form[$key];
    $field['operations'] = [];
    if (empty($field['hidden']['#default_value']) || in_array($field['#item']['plid'], $disabled)) {
      $field['hidden']['#default_value'] = FALSE;
      $field['hidden']['#disabled'] = TRUE;
      $field['title']['#markup'] = t('!title (disabled on master level)', ['!title' => $field['#item']['title']], ['context' => SOURIAU_COMMON_T_ADMIN]);
      $disabled[] = $field['#item']['mlid'];
    }
    else {
      // We need to know location ID for this item.
      $locale_location = 'menu:item:' . $field['#item']['mlid'] . ':title';
      $sql_query = db_select('locales_source', 's')
        ->fields('s', ['lid', 'location'])
        ->condition('s.location', $locale_location)
        ->execute();
      $sources = $sql_query->fetchAll();
      if (!empty($sources)) {
        $field['operations']['translate'] = [
          '#type' => 'link',
          '#title' => t('translate', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
          '#href' => 'admin/config/regional/translate/edit/' . $sources[0]->lid,
          '#options' => ['query' => drupal_get_destination()],
        ];
      }
    }
    // Set out custom values.
    if (!in_array($field['#item']['mlid'], $disabled)) {
      if (isset($settings[$key]['hidden'])) {
        $field['hidden']['#default_value'] = $settings[$key]['hidden'];
      }
    }
  }

  $_form['souriau_common_main_menu_form'] = $form;
  $_form['#theme'] = 'souriau_common_main_menu_form';

  // Additional settings.
  $_domain = domain_get_domain();
  $_form['souriau_common_main_menu_form_sync'] = [
    '#prefix' => '<div class="container-inline">',
    '#title' => t('Global Settings (Those settings affect all sites)', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#type' => 'fieldset',
    '#access' => ($_domain['domain_id'] == SOURIAU_COMMON_DOMAIN_CENTRAL),
    '#tree' => TRUE,
    '#weight' => 100,
    '#suffix' => '</div>',
  ];

  // We attach custom submit to validate, to prevent form submission.
  $_form['souriau_common_main_menu_form_sync']['sync_button'] = [
    '#type' => 'button',
    '#value' => t('Sync now', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#validate' => ['souriau_common_main_menu_form__sync_button__submit'],
  ];

  if ($user->uid == 1) {
    $_form['souriau_common_main_menu_form_sync']['sync_auto'] = [
      '#type' => 'checkbox',
      '#title' => t('Sync automtically on structure updates', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      '#default_value' => isset($settings_sync['sync_auto']) ? $settings_sync['sync_auto'] : FALSE,
    ];
  }

  $_form['#submit'][] = 'souriau_common_main_menu_form_submit';
  $_form['#submit'][] = 'menu_cache_clear_all';
  return system_settings_form($_form);
}

/**
 * Submit handler for the menu overview form.
 *
 * This function takes great care in saving parent items first, then items
 * underneath them. Saving items in the incorrect order can break the menu tree.
 *
 * @see menu_overview_form()
 */
function souriau_common_main_menu_form_submit($form, &$form_state) {
  // When dealing with saving menu items, the order in which these items are
  // saved is critical. If a changed child item is saved before its parent,
  // the child item could be saved with an invalid path past its immediate
  // parent. To prevent this, save items in the form in the same order they
  // are sent by $_POST, ensuring parents are saved first, then their children.
  // See http://drupal.org/node/181126#comment-632270

  // Get the $_POST order.
  $order = array_flip(array_keys($form_state['input']['souriau_common_main_menu_form']));
  // Update our original form with the new order.
  $form = array_merge($order, $form['souriau_common_main_menu_form']);

  $updated_items = array();
  $fields = array('weight', 'plid');
  foreach (element_children($form) as $mlid) {
    if (isset($form[$mlid]['#item'])) {
      $element = $form[$mlid];
      // Update any fields that have changed in this menu item.
      foreach ($fields as $field) {
        if ($element[$field]['#value'] != $element[$field]['#default_value']) {
          $element['#item'][$field] = $element[$field]['#value'];
          $updated_items[$mlid] = $element['#item'];
        }
      }
      // Hidden is a special case, the value needs to be reversed.
      if ($element['hidden']['#value'] != $element['hidden']['#default_value']) {
        // Convert to integer rather than boolean due to PDO cast to string.
        $element['#item']['hidden'] = $element['hidden']['#value'] ? 0 : 1;
        $updated_items[$mlid] = $element['#item'];
      }
    }
  }

  // Save all our changed items to the database.
  foreach ($updated_items as $item) {
    $item['customized'] = 1;
    menu_link_save($item);
  }
}

/**
 * Trigger menu sync.
 */
function souriau_common_main_menu_form__sync_button__submit($form, &$form_state) {
  $menu_links = menu_load_links(SOURIAU_COMMON_VAR_HEADER_MENU);
  $parent = views_get_view_result(SOURIAU_COMMON_VIEW_QUERY_GET_MENU_ITEMS, 'parent');
  $errors = [];
  foreach ($parent as $item) {
    module_load_include('inc', 'souriau_common', 'souriau_common.pages');
    $errors[] = souriau_common_rebuild_menu($menu_links, $item);
  }

  if (!empty($errors)) {
    foreach ($errors as $error) {
      drupal_set_message(check_plain($error), 'error');
    }
  }
  else {
    menu_cache_clear_all();
    drupal_set_message(t('Menu synchronized', [], ['context' => SOURIAU_COMMON_T_ADMIN]));
  }
}

/**
 * Config form.
 */
function souriau_common_form_site_settings() {
  $form = [];
  $fildset_conf = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  $form['souriau_common_settings'] = [
    '#tree' => TRUE,
  ];
  $default_value = variable_get('souriau_common_settings');
  $_domain = domain_get_domain();

  // Contact information.
  $contact_default = isset($default_value['information']) ? $default_value['information'] : [];
  $form['souriau_common_settings']['information'] = _souriau_common_form_site_settings_contact_information($contact_default, $fildset_conf);

  $form['souriau_common_settings']['information']['copyrights'][2] = [
    '#type' => 'textfield',
    '#title' => NULL,
    '#default_value' => isset($default_value['information']['copyrights'][2]) ? $default_value['information']['copyrights'][2] : '',
  ];

  // Connectors grouping.
  $form['souriau_common_settings']['grouping'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Grouping', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['souriau_common_settings']['grouping']['is_group'] = [
    '#type' => 'checkbox',
    '#title' => t('Use grouping', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['grouping']['is_group']) ? $default_value['grouping']['is_group'] : '',
    '#description' => t('Enable grouping for Connectors Category', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  // User zone.
  $form['souriau_common_settings']['user_zone'] = [
    '#collapsed' => FALSE,
    '#title' => t('User Zone', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;

  // Default image for my projects.
  $form['souriau_common_settings']['user_zone']['project_default_image'] = [
    '#type' => 'managed_file',
    '#title' => t('Default image for my projects', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['user_zone']['project_default_image']) ? $default_value['user_zone']['project_default_image'] : '',
    '#description' => t('Option for adding a default image to show if there is no project images available', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#upload_location' => 'private://user_zone/project',
  ];

  // Beginner Guidance.
  $form['souriau_common_settings']['beginner_guide'] = [
    '#collapsed' => FALSE,
    '#title' => t('Beginner Guide', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;

  // Default image for beginner guidance.
  $form['souriau_common_settings']['beginner_guide']['beginner_guide_background'] = [
    '#type' => 'managed_file',
    '#title' => t('Default background for beginer guide', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['beginner_guide']['beginner_guide_background']) ? $default_value['beginner_guide']['beginner_guide_background'] : '',
    '#description' => t('Option for adding a default background image to show on beginner guide page', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#upload_location' => 'public://get_started',
  ];

  // Beginner Guidance.
  $form['souriau_common_settings']['download_center'] = [
    '#collapsed' => FALSE,
    '#title' => t('Download Center', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;

  // Default image for download center thumbnail.
  $form['souriau_common_settings']['download_center']['thumbnail_image'] = [
    '#type' => 'managed_file',
    '#title' => t('Default thumbnail for download center', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['download_center']['thumbnail_image']) ? $default_value['download_center']['thumbnail_image'] : '',
    '#description' => t('Option for adding a thumbnail to download center', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#upload_location' => 'public://download_center',
  ];

  // Default contact recipients.
  $contact_default = isset($default_value['contact']) ? $default_value['contact'] : '';
  $form['souriau_common_settings']['contact'] = _souriau_common_form_site_settings_default_recipients($contact_default, $fildset_conf);

  // Paths where Poll button to be shown.
  $form['souriau_common_settings']['poll'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Poll', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];
  $form['souriau_common_settings']['poll']['show_on_paths'] = [
    '#type' => 'textarea',
    '#title' => t('Specific paths to show the poll button', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['poll']['show_on_paths']) ? $default_value['poll']['show_on_paths'] : '',
    '#description' => t('Poll button will be shown on these paths. Enter one path per line. The "*" character is a wildcard. Example paths are node for the node page and node/* for all nodes. To display in all pages leave this field blank.'),
  ];

  $form['souriau_common_webmaster_mail'] = [
    '#type' => 'textfield',
    '#title' => t('Souriau Webmaster Email', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => '',
    '#default_value' => SOURIAU_COMMON_WEBMASTER,
  ];

  // Paths where Poll button to be shown.
  $form['souriau_common_settings']['gtm'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Google tag manager', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['souriau_common_settings']['gtm']['container_id'] = [
    '#type' => 'textfield',
    '#title' => t('GTM Container ID', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('The ID assigned by Google Tag Manager (GTM) for this website container. ', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['gtm']['container_id']) ? $default_value['gtm']['container_id'] : 'GTM-K4Q672',
  ];

  // Paths where Poll button to be shown.
  $form['souriau_common_settings']['newsletter'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Newsletter', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['souriau_common_settings']['newsletter']['link'][$_domain['domain_id']] = [
    '#type' => 'textfield',
    '#title' => t('Newsletter link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Newsletter link to display in the footer iframe(domain sensitive). ', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['newsletter']['link'][$_domain['domain_id']]) ? $default_value['newsletter']['link'][$_domain['domain_id']] : 'https://app.mailjet.com/widget/iframe/41YK/i8A',
  ];

  // OCR Screening process.
  _souriau_common_screening_settings($form, $default_value);
  _souriau_common_domain_settings($form, $default_value);

  // Sample order redirection page.
  $form['souriau_common_settings']['sample_order'] = [
    '#collapsed' => FALSE,
    '#title' => t('Sample Order', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;

  $form['souriau_common_settings']['sample_order']['sample_order_url'] = [
    '#type' => 'textfield',
    '#title' => t('Sample order url.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['sample_order']['sample_order_url']) ? $default_value['sample_order']['sample_order_url'] : '',
    '#description' => t('Redirection url for sample order', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#field_prefix' => url(NULL, ['absolute' => TRUE]) . (variable_get('clean_url', 0) ? '' : '?q='),
  ];
  // Product landing page.
  $form['souriau_common_settings']['block_of_interest_urls'] = [
    '#collapsed' => FALSE,
    '#title' => t('Block Of Interest', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;

  $form['souriau_common_settings']['block_of_interest_urls']['3dmodel_url'] = [
    '#type' => 'textfield',
    '#title' => t('Download Center url.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['block_of_interest_urls']['3dmodel_url']) ? $default_value['block_of_interest_urls']['3dmodel_url'] : '',
    '#description' => t('Url for "you may be interested in Download Center."', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#field_prefix' => url(NULL, ['absolute' => TRUE]) . (variable_get('clean_url', 0) ? '' : '?q='),
  ];
  $form['souriau_common_settings']['block_of_interest_urls']['technical_suppport_url'] = [
    '#type' => 'textfield',
    '#title' => t('Technical suppport url.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['block_of_interest_urls']['technical_suppport_url']) ? $default_value['block_of_interest_urls']['technical_suppport_url'] : '',
    '#description' => t('Url for "you may be interested in technical support" in product landing page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#field_prefix' => url(NULL, ['absolute' => TRUE]) . (variable_get('clean_url', 0) ? '' : '?q='),
  ];

  return system_settings_form($form);
}

/**
 * Helper function for screening config form.
 */
function _souriau_common_screening_settings(&$form, $default_value) {
  $form['souriau_common_settings']['ocr_screening'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('OCR Screening', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['souriau_common_settings']['ocr_screening']['screening_status'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable OCR screening', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['screening_status']) ? $default_value['ocr_screening']['screening_status'] : TRUE,
    '#description' => t('Enable OCR screning service for user registration', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  $form['souriau_common_settings']['ocr_screening']['screening_url'] = [
    '#type' => 'textfield',
    '#title' => t('OCR API URL', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['screening_url']) ? $default_value['ocr_screening']['screening_url'] : 'https://ocrtest.esterline.net/dpss/resultHostedService.ocr',
    '#description' => t('URL to OCR services to send request', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  $form['souriau_common_settings']['ocr_screening']['webservice_key'] = [
    '#type' => 'textfield',
    '#title' => t('API Key', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['webservice_key']) ? $default_value['ocr_screening']['webservice_key'] : '0000001-SAS',
    '#description' => t('OCR services API key', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  $form['souriau_common_settings']['ocr_screening']['tcm_email'] = [
    '#type' => 'textfield',
    '#title' => t('Trade Compliance Manager email', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('You can add multiple email id separated by semicolon', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['tcm_email']) ? $default_value['ocr_screening']['tcm_email'] : '',
  ];

  $form['souriau_common_settings']['ocr_screening']['screening_cc_email'] = [
    '#type' => 'textfield',
    '#title' => t('Screening email cc', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Email id of user to which we must send user list for screening as cc. You can add multiple email id separated by semicolon', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['screening_cc_email']) ? $default_value['ocr_screening']['screening_cc_email'] : '',
  ];

  $form['souriau_common_settings']['ocr_screening']['csr_email'] = [
    '#type' => 'textfield',
    '#title' => t('Customer Service Representative email', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('You can add multiple email id separated by semicolon', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['csr_email']) ? $default_value['ocr_screening']['csr_email'] : '',
  ];

  $form['souriau_common_settings']['ocr_screening']['webservice_username'] = [
    '#type' => 'textfield',
    '#title' => t('Webservice Username', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['webservice_username']) ? $default_value['ocr_screening']['webservice_username'] : 'WebServ1896!SSL',
  ];

  $form['souriau_common_settings']['ocr_screening']['webservice_email'] = [
    '#type' => 'textfield',
    '#title' => t('Webservice email', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['ocr_screening']['webservice_email']) ? $default_value['ocr_screening']['webservice_email'] : 'brian.hall@esterline.com',
  ];
}

/**
 * Helper function for screening config form.
 */
function _souriau_common_domain_settings(&$form, $default_value) {
  $_domain = domain_get_domain();
  $form['souriau_common_settings']['registration_sample_checkout'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Registration & Sample Checkout', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['souriau_common_settings']['registration_sample_checkout']['login_registration_status'][$_domain['domain_id']] = [
    '#type' => 'checkbox',
    '#title' => t('Enable login / create account features', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['registration_sample_checkout']['login_registration_status'][$_domain['domain_id']]) ? $default_value['registration_sample_checkout']['login_registration_status'][$_domain['domain_id']] : TRUE,
  ];

  $form['souriau_common_settings']['registration_sample_checkout']['sample_checkout_status'][$_domain['domain_id']] = [
    '#type' => 'checkbox',
    '#title' => t('Enable sample checkout', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['registration_sample_checkout']['sample_checkout_status'][$_domain['domain_id']]) ? $default_value['registration_sample_checkout']['sample_checkout_status'][$_domain['domain_id']] : TRUE,
  ];
}

/**
 * Element validate for user_password_reset_timeout.
 */
function souriau_common_form_site_settings_timeout_validate(&$element) {
  if (!ctype_digit($element['#value'])) {
    form_set_error($element['#name'], t('field %field_name must contain only int values.', [
      '%field_name' => $element['#title'],
    ]
    )
    );
  }
}

/**
 * Config form.
 */
function souriau_common_form_site_settings_variables() {
  $form = [];
  $fieldset_conf = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  ];

  $form['souriau_site_settings_variables'] = [
    '#tree' => TRUE,
  ];
  $default_value = variable_get('souriau_site_settings_variables');

  $blocks = [
    'block_news' => [
      '#title' => t('News Block', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'news' => [
        '#title' => t('Catchline', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        '#description' => t('Catchline for News Block, that displayed on Product Ranges pages.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      ],
    ],
    'user_zone' => [
      '#title' => t('User zone', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'info' => [
        '#title' => t('Information on page: Create an Account', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        '#description' => t('Text on user registration page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      ],
      'landing_text' => [
        '#title' => t('Text on page: My Account', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        '#description' => t('Text on user registration page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      ],
    ],
    'contact' => [
      '#title' => t('Contact Recipients', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'default_recepient' => [
        '#title' => t('Email ids', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        '#description' => t(
            'Enter the value in the format "country-code|subject|email-id1;email-id2;email-id3". You can add multiple email-ids separated by semicolon',
            [],
            ['context' => SOURIAU_COMMON_T_ADMIN]
        ),
      ],
    ],
    'csr_contact' => [
      '#title' => t('CSR Mail Recipients', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'default_recepient' => [
        '#title' => t('Email ids', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        '#description' => t(
          'Enter the value in the format "country-code|email-id". Please make sure to add a default one like default|user1@example.com',
          [],
          ['context' => SOURIAU_COMMON_T_ADMIN]
        ),
      ],
    ],
    'cookie_alert_message' => [
      '#title' => t('GDPR: EU Cookie Compliance', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'cookie message' => [
        '#title' => t('Cookies Alert Message', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        '#description' => t('Message to show on cookie alert popup.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      ],
    ],
    'did_you_know' => [
      '#title' => t('Did you know: Description', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'description' => [
        '#title' => t('Did you know: Description', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        '#description' => t('Description to show on did you know page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      ],
    ],
  ];

  foreach ($blocks as $block_key => $block) {
    // Set block title.
    $form['souriau_site_settings_variables'][$block_key] = [
      '#title' => $block['#title'],
    ] + $fieldset_conf;
    unset($block['#title']);

    // Set block elements.
    foreach ($block as $element_key => $element) {
      // Check on translations.
      $sources = [];
      if (!empty($default_value[$block_key][$element_key])) {
        $sql_query = db_select('locales_source', 's')
          ->fields('s', ['lid', 'location'])
          ->condition('s.source', $default_value[$block_key][$element_key])
          ->execute();
        $sources = $sql_query->fetchAll();
      }
      // Add link to translations.
      if (!empty($sources)) {
        $form['souriau_site_settings_variables'][$block_key]['translate_' . $element_key] = [
          '#type' => 'link',
          '#title' => t('Translate', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
          '#href' => 'admin/config/regional/translate/edit/' . $sources[0]->lid,
          '#options' => ['query' => drupal_get_destination()],
        ];
      }
      // Add form element.
      $form['souriau_site_settings_variables'][$block_key][$element_key] = [
        '#type' => 'textarea',
        '#title' => $element['#title'],
        '#default_value' => isset($default_value[$block_key][$element_key]) ? $default_value[$block_key][$element_key] : '',
        '#description' => $element['#description'],
      ];
    }
  }

  $site_search = variable_get('site_search');

  $form['site_search'] = [
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('eCatalog/Site Search', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['site_search']['disabled'] = [
    '#type' => 'checkbox',
    '#title' => t('Disable site search(eCatalog) and find partnumber buttons?', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($site_search['disabled']) ? $site_search['disabled'] : FALSE,
  ];

  $form['site_search']['redirect_url'] = [
    '#type' => 'textfield',
    '#title' => t('URL for redirecting', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($site_search['redirect_url']) ? $site_search['redirect_url'] : '',
    '#description' => t('The URL to redirect the user to when they click on search bar or find partnumber buttons.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['alert_banner'] = [
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Alert banner', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $alert_banner = variable_get('alert_banner');

  $form['alert_banner']['show'] = [
    '#type' => 'checkbox',
    '#title' => t('Show the alert banner on site header?', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($alert_banner['show']) ? $alert_banner['show'] : FALSE,
  ];

  $form['alert_banner']['banner_message'] = [
    '#type' => 'text_format',
    '#title' => t('Banner message', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#format' => 'simple',
    '#default_value' => isset($alert_banner['banner_message']['value']) && !empty(trim($alert_banner['banner_message']['value'])) ? $alert_banner['banner_message']['value'] : '',
    '#description' => t('Alert message to be displayed on the banner', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $google_optimize = variable_get('google_optimize');
  $form['google_optimize'] = [
    '#tree' => TRUE,
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Google Optimize', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['google_optimize']['container_id'] = [
    '#type' => 'textfield',
    '#title' => t('Google optimize container ID', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($google_optimize['container_id']) ? $google_optimize['container_id'] : 'GTM-5XK848T',
    '#description' => t('The ID assigned by Google Optimize for this website container. ', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['google_optimize']['snippet'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable google optimize page hiding snippet?', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($google_optimize['snippet']) ? $google_optimize['snippet'] : FALSE,
  ];
  // Parent company logo.
  $form['parent_company_logo'] = [
    '#type' => 'managed_file',
    '#title' => t('EATON Logo', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('parent_company_logo'),
    '#description' => t('Option to add EATON logo, will be displayed in footer section', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#upload_location' => 'public://',
  ];

  $form['watchdog_path'] = [
    '#type' => 'textfield',
    '#title' => t('Watchdog Path', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('watchdog_path'),
    '#description' => t('Drupal watcchdog file full path', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['access_log_path'] = [
    '#type' => 'textfield',
    '#title' => t('Accesslog Path', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('access_log_path'),
    '#description' => t('Apache accesslog file full path', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['user_password_reset_timeout'] = [
    '#type' => 'textfield',
    '#attributes' => array(
      'data-type' => 'number',
    ),
    '#title' => t('Password Reset Timeout', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Set timeout for one time login link in seconds.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => SOURIAU_PASSWORD_RESET_TIMEOUT,
    '#element_validate' => ['souriau_common_form_site_settings_timeout_validate'],
  ];

  $form['ect_site_career_link'] = [
    '#type' => 'textfield',
    '#title' => t('ECT career site link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => SOURIAU_CAREER_LINK,
    '#description' => t('Link to load/show on ECT job oportunities header link.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['souriau_distributors_google_map_link'] = [
    '#type' => 'textfield',
    '#title' => t('Souriau Worldwide distributors google map link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('souriau_distributors_google_map_link', 'https://www.google.com/maps/d/embed?mid=1aZ3noIvG2hbMOtcSHQphI0ZYgrpjr0RB'),
    '#description' => t('Link to show Souriau Worldwide distributors google map page on our distributors page.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['training_inquiry_webform_nid'] = [
    '#type' => 'textfield',
    '#title' => t('Training inquiry webform NID', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('training_inquiry_webform_nid'),
    '#description' => t('Webform NID of training inquiry form.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['website_feedback_recipient'] = [
    '#type' => 'textfield',
    '#title' => t('Website feedback recipient', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('website_feedback_recipient', 'webmaster-ect@souriau.com'),
    '#description' => t('Mail id to which website feedback should be sent.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['training_inquiry_receipient'] = [
    '#type' => 'textfield',
    '#title' => t('Training inquiry receipient', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('training_inquiry_receipient', 'training-admin@souriau.com'),
    '#description' => t('Mail id to which training inquiry should be sent.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  $form['pn_page_dc_layout'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable new layout for download section on PN page?', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('pn_page_dc_layout', FALSE),
  ];

  $form['log_add_to_cart'] = [
    '#type' => 'checkbox',
    '#title' => t('Log \'add to cart\' response from Mouser?', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => variable_get('log_add_to_cart', FALSE),
    '#description' => t('Enable this option to log the \'add the cart\' response we receive from Mouser API', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];

  // Additional elements for define active mailchimp list.
  if (function_exists('souriau_newsletter_conf_form')) {
    $mailchimp_conf = isset($default_value['mailchimp']) ? $default_value['mailchimp'] : [];
    $form['souriau_site_settings_variables']['mailchimp'] = souriau_newsletter_conf_form($mailchimp_conf);
  }

  $form['souriau_site_settings_variables']['distributor_inventory'] = _souriau_common_form_site_settings_distributor_inventory($default_value, $fieldset_conf);

  $form['souriau_site_settings_variables']['mouser-ftp'] = _souriau_common_form_site_settings_mouser_inventory($default_value, $fieldset_conf);

  $job_link_default_message = isset($default_value['job_link']) ? $default_value['job_link'] : 'Dummy content';
  $form['souriau_site_settings_variables']['job_link'] = _souriau_common_form_site_settings_jobclick_message($job_link_default_message, $fieldset_conf);

  // Perform our custom submit before system submit.
  $form['#submit'][] = 'souriau_common_settings_form_submit';

  return system_settings_form($form);
}

/**
 * Custom submit to fix the file_managed error.
 *
 * Link: https://www.drupal.org/project/drupal/issues/1090198#comment-5452202.
 */
function souriau_common_settings_form_submit($form, &$form_state) {
  global $user;
  if (is_numeric($form_state['values']['parent_company_logo'])) {
    // Load the file via file.fid.
    $file = file_load($form_state['values']['parent_company_logo']);
    if ($file) {
      // Change status to permanent.
      $file->status = FILE_STATUS_PERMANENT;
      // Save.
      file_save($file);
      // Save file to variable.
      variable_set('parent_company_logo', $file->fid);
      // Record that the module (in this example, user module) is using the file.
      file_usage_add($file, 'user', 'user', $user->uid);
      // Unset formstate value.
      unset($form_state['values']['parent_company_logo']);
    }
  }
  else {
    // Delete file.
    variable_set('parent_company_logo', '');
  }
}

/**
 * Helper Function for build contact_recipients.
 *
 * @see souriau_common_form_site_settings()
 */
function _souriau_common_form_site_settings_default_recipients($default_value, $fildset_conf) {
  $form = [
    '#title' => t('Where To Buy Settings', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#collapsed' => FALSE,
  ] + $fildset_conf;

  $recipients_groups = [
    'where_to_buy' => t('Empty Result Text', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  foreach ($recipients_groups as $group => $title) {
    $form[$group] = [
      '#title' => $title,
    ] + $fildset_conf;

    $form[$group]['no_result_text'] = [
      '#type' => 'text_format',
      '#title' => t('No Distributor Found Text', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      '#format' => 'full',
      '#default_value' => isset($default_value['contact']['where_to_buy']['no_result_text']['value']) ? $default_value['contact']['where_to_buy']['no_result_text']['value'] : '',
      '#description' => t(
        'Text to be displayed when no distributors found in where to buy',
        [],
        ['context' => SOURIAU_COMMON_T_ADMIN]
      ),
    ];
  }

  return $form;
}

/**
 * Helper function for create contact information block on souriau-site-settings page.
 */
function _souriau_common_form_site_settings_contact_information($contact_defaults, $fildset_conf) {
  $form = [
    '#title' => t('Contact Information', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;

  $blocks = [
    'contact_information' => [
      'title' => t('Contact information', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'description' => t('Contact information, that displayed in footer', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    ],
    'contact_form_description' => [
      'title' => t('Contact form description', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'description' => t('Contact form description, that is displayed in the site-wide contact form', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    ],
  ];

  foreach ($blocks as $block => $value) {
    $form[$block] = [
      '#type' => 'text_format',
      '#title' => $value['title'],
      '#format' => 'full',
      '#default_value' => $contact_defaults[$block]['value'],
      '#description' => $value['description'],
    ];
  }

  // Social icons.
  $social = [
    'facebook' => t('Facebook link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'twitter' => t('Twitter link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'in' => t('In link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'google' => t('Google link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'youtube' => t('Youtube', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];
  $form['social'] = [
    '#title' => t('Social', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;
  foreach ($social as $index => $title) {
    $form['social'][$index] = [
      '#type' => 'textfield',
      '#title' => $title,
      '#default_value' => isset($contact_defaults['social'][$index]) ? $contact_defaults['social'][$index] : '',
    ];
  }
  // Default image for my projects.
  $form['social']['socialshare_default_image'] = [
    '#type' => 'managed_file',
    '#title' => t('Default image for social share', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($contact_defaults['social']['socialshare_default_image']) ? $contact_defaults['social']['socialshare_default_image'] : '',
    '#description' => t('Option for adding a default image in social sharing', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#upload_location' => 'private://social',
  ];

  // Copyrights.
  $form['copyrights'] = [
    '#title' => t('Copyrights', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Copyright, displayed in footer', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ] + $fildset_conf;

  $form['copyrights'][1] = [
    '#type' => 'textfield',
    '#title' => NULL,
    '#default_value' => isset($contact_defaults['copyrights'][1]) ? $contact_defaults['copyrights'][1] : '',
  ];

  $form['copyrights']['separator'] = [
    '#type' => 'textfield',
    '#size' => 1,
    '#default_value' => ' - ',
    '#disabled' => TRUE,
  ];
  return $form;
}

/**
 * Helper Function for job link popup alert message.
 *
 * @see souriau_global_settings()
 */
function _souriau_common_form_site_settings_jobclick_message($default_value, $fildset_conf) {
  $form = [
    '#title' => t('Job Opportunities Settings', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#collapsed' => FALSE,
  ] + $fildset_conf;

  $form['job_click']['job_alert_message'] = [
    '#type' => 'text_format',
    '#title' => t('Job Opportunities popup alert message', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#format' => 'full',
    '#default_value' => !empty(trim($default_value['job_click']['job_alert_message']['value'])) ? $default_value['job_click']['job_alert_message']['value'] : '',
    '#description' => t('Alert message to be displayed on Job Oportunities popup', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];

  return $form;
}

/**
 * Helper Function for distributor inventory data.
 *
 * @see souriau_global_settings()
 */
function _souriau_common_form_site_settings_distributor_inventory($default_value, $fildset_conf) {
  $form = [
    '#title' => t('Distributor - Inventory Data Flow', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#collapsed' => TRUE,
  ] + $fildset_conf;

  $form['ftp'] = [
    '#type' => 'textfield',
    '#title' => t('FTP Host', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => !empty($default_value['distributor_inventory']['ftp']) ? $default_value['distributor_inventory']['ftp'] : 'ftps://ftp.souriau.com',
  ];
  $form['ftp_user'] = [
    '#type' => 'textfield',
    '#title' => t('FTP User', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => !empty($default_value['distributor_inventory']['ftp_user']) ? $default_value['distributor_inventory']['ftp_user'] : 'Souriau',
  ];
  $form['ftp_password'] = [
    '#type' => 'textfield',
    '#title' => t('FTP Password', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => !empty($default_value['distributor_inventory']['ftp_password']) ? $default_value['distributor_inventory']['ftp_password'] : 'Sour!@u20',
  ];
  $form['ftp_port'] = [
    '#type' => 'textfield',
    '#title' => t('FTP Port', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => !empty($default_value['distributor_inventory']['ftp_port']) ? $default_value['distributor_inventory']['ftp_port'] : '990',
  ];
  return $form;
}

/**
 * Helper Function for mouser inventory data.
 *
 * @see souriau_global_settings()
 */
function _souriau_common_form_site_settings_mouser_inventory($default_value, $fildset_conf) {
  $form = [
    '#title' => t('Mouser FTP - Sample Stock Inventory', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#collapsed' => TRUE,
  ] + $fildset_conf;

  $form['server'] = [
    '#type' => 'textfield',
    '#title' => t('Server', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Enter the FTP server URL or IP address', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['mouser-ftp']['server']) ? $default_value['mouser-ftp']['server'] : 'b2bgateway.mouser.com'
  ];

  $form['username'] = [
    '#type' => 'textfield',
    '#title' => t('Username', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Enter the FTP username', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['mouser-ftp']['username']) ? $default_value['mouser-ftp']['username'] : 'souriau'
  ];

  $form['password'] = [
    '#type' => 'textfield',
    '#title' => t('Password', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Enter the FTP password', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['mouser-ftp']['password']) ? $default_value['mouser-ftp']['password'] : 'f9fxr2b6vjlxxahs!'
  ];

  return $form;
}
