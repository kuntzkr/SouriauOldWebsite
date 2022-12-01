<?php
/**
 * @file
 * souriau_common.pages.inc
 *
 * Contain menu callbacks.
 */

/**
 * Custom callback for cloning sku.
 */
function souriau_common_pages_sku_clone($sku) {

  drupal_set_title(t('Cloning sku: !sku', array('!sku' => $sku->sku)));

  $sku = souriau_common_pages_prepare_commerce_product($sku);

  $form_state['build_info']['args'][] = $sku;
  module_load_include('inc', 'commerce_product', 'includes/commerce_product.forms');

  return drupal_build_form('commerce_product_ui_product_form', $form_state);
}

/**
 * Prepare SKU for clone.
 */
function souriau_common_pages_prepare_commerce_product($product) {
  global $user;

  $product->clone_from_id = $product->product_id;
  $product->sku = NULL;
  $product->product_id = NULL;
  $product->revision_id = NULL;
  $product->revision_uid = NULL;
  $product->created = NULL;
  $product->changed = NULL;
  $product->uid = $user->uid;
  $product->revision_timestamp = NULL;

  return $product;
}

/**
 * Callback of Dashboard page, that redirect to view with all CTs.
 */
function souriau_common_pages_default_dashboard() {
  if ($view = views_get_view('dashboard_all')) {
    drupal_goto($view->display['all_content']->display_options['path']);
  }
  else {
    drupal_goto('admin/content');
  }
}

/**
 * Implements hook_search_api_solr_autocomplete_suggestions_alter().
 */
function souriau_common_autocomplete_callback($server_name, $index_name, $fields) {
  global $language;
  $groups = array(
    'productrange',
    'productrangehub',
    'application',
    'capability',
    'product',
    'category',
    'subcategory',
    'news',
  );
  $sort = [
    'type_weight' => 'ASC',
    'field_sticky' => 'DESC',
    'title_field_string' => 'ASC'
  ];
  $term = $_GET['term'];
  $domain = domain_get_domain();
  $server = search_api_server_load($server_name);
  $index = search_api_index_load($index_name);
  $service_info = search_api_get_service_info($server->class);
  $srv = new $service_info['class']($server);
  $query = new SearchApiQuery($index);
  $query->setOption('parse mode', 'terms');
  $query->keys($term);
  $query->fields(explode(',', $fields));
  $query->range(0, 5);
  // Added default sorting to match the all search results.
  foreach ($sort as $sort_field => $sort_order) {
    $query->sort($sort_field, $sort_order);
  }
  // Set language filter.
  $filter = $query->createFilter('OR');
  foreach ($groups as $group) {
    $sub_filter = $query->createFilter('AND');
    $sub_filter->condition('type', $group);
    if ($group != 'product') {
      $sub_filter->condition('search_api_language', $language->language);
    }
    else {
      // Filter by Domain, only for Products.
      $sub_filter->condition('field_sku_products:domains', $domain['domain_id']);
    }
    $filter->filter($sub_filter);
  }
  $query->filter($filter);
  $search_result = $srv->search($query);

  if (empty($search_result['results'])) {
    return;
  }

  $output = array();
  $extracted_ids = souriau_common_search_api_extract_entity_ids($search_result['results'], $index);
  $entities = entity_load($extracted_ids['entity_type'], $extracted_ids['ids']);
  $entity_view_array = entity_view('node', $entities, 'search_autocomplete');
  foreach (element_children($entity_view_array['node']) as $nid) {
    $output['_' . $nid] = array(
      'node' => render($entity_view_array['node'][$nid]),
    );
  }

  drupal_json_output($output);
  drupal_exit();
}

/**
 * Create menu links from category structure.
 *
 * TODO: if nodes will have custom path this has to be incorporated here.
 */
function souriau_common_rebuild_menu($menu_links, $item) {
  $first = menu_link_get_preferred('node/' . $item->nid);
  if ($first['menu_name'] != SOURIAU_COMMON_VAR_HEADER_MENU) {

    $link_title = array(
      'capabilitieslanding' => 'Capabilities',
      'applicationlanding' => 'Applications',
      'productlanding' => 'Products',
    );
    $link_path = 'node/' . $item->nid;

    $first = array(
      'link_title' => $link_title[$item->node_type],
      'link_path'  => $link_path,
      'menu_name'  => SOURIAU_COMMON_VAR_HEADER_MENU,
      'plid' => 0,
      'weight'     => 0,
      'customized' => TRUE,
    );

    menu_link_save($first);
  }
  return _souriau_common_rebuild_menu($menu_links, $first, $item->node_type);
}


/**
 * Helper function for create menu links(2nd lvl, 3rd lvl).
 *
 * TODO: if nodes will have custom path this has to be incorporated here.
 */
function _souriau_common_rebuild_menu($menu_links, $first, $parent_type) {

  // Sanity check.
  if (empty($menu_links)) {
    return t('Could not rebuild section menu (menu [%menu] not found).', array(
      '%menu' => SOURIAU_COMMON_VAR_HEADER_MENU,
    ), array('context' => SOURIAU_COMMON_T_ADMIN));
  }

  // Get available content types for build links.
  $display = array(
    'capabilitieslanding' => 'capabilities',
    'applicationlanding' => 'applications',
    'productlanding' => 'products',
  );
  $data = views_get_view_result(SOURIAU_COMMON_VIEW_QUERY_GET_MENU_ITEMS, $display[$parent_type]);

  // Remap links by link_path.
  $links = array();
  foreach ($menu_links as $tmp) {
    $links[$tmp['link_path']] = $tmp;
  }

  // Iterate through categories and build/update menu items.
  $processed = array();
  $reference_field = array(
    'capabilitieslanding' => 'node_field_data_field_capability',
    'applicationlanding' => 'node_field_data_field_application',
    'productlanding' => 'node_field_data_field_subcategory',
  );
  foreach ($data as $item) {

    if (!in_array($item->nid, $processed) || !in_array($item->{$reference_field[$parent_type] . '_nid'}, $processed)) {
      $processed[] = $item->nid;

      // Process l2 links.
      _souriau_common_process_l2_links($item, $links, $first);

      // Process l3 links.
      _souriau_common_process_l3_links($item, $links, $reference_field[$parent_type], $processed);
    }
  }
}

/**
 * Helper function for build l2 links.
 */
function _souriau_common_process_l2_links($item, &$links, $first) {
  // Use tile_field for link title.
  $node = node_load($item->nid);
  $title_field = field_get_items('node', $node, 'title_field', SOURIAU_COMMON_VAR_DEFAULT_LNG);
  $link_path = 'node/' . $item->nid;

  $weight = empty($item->field_field_weight[0]['raw']['value']) ? 0 : $item->field_field_weight[0]['raw']['value'];
  $new_link = array(
    'link_title' => !empty($title_field[0]['value']) ? $title_field[0]['value'] : $item->node_title,
    'link_path'  => $link_path,
    'menu_name'  => SOURIAU_COMMON_VAR_HEADER_MENU,
    'plid' => $first['mlid'],
    'weight'     => $weight,
    'customized' => TRUE,
  );

  // Update existing link if match.
  if (!empty($links[$link_path])) {
    $new_link += $links[$link_path];
  }
  menu_link_save($new_link);
  $links[$link_path] = $new_link;
}

/**
 * Helper function for build l3 links.
 */
function _souriau_common_process_l3_links($item, &$links, $reference_field, &$processed) {

  if (!empty($item->{$reference_field . '_nid'}) && !in_array($item->{$reference_field . '_nid'}, $processed)) {
    $processed[] = $item->{$reference_field . '_nid'};

    $parent_path = 'node/' . $item->nid;
    $link_path = 'node/' . $item->{$reference_field . '_nid'};

    // Use tile_field for link title.
    $node = node_load($item->{$reference_field . '_nid'}, NULL, TRUE);
    $title_field = field_get_items('node', $node, 'title_field', SOURIAU_COMMON_VAR_DEFAULT_LNG);

    $weight = empty($item->{$reference_field . '_delta'}) ? 0 : $item->{$reference_field . '_delta'};
    $new_link = array(
      'link_title' => !empty($title_field[0]['value']) ? $title_field[0]['value'] : $item->node_{$reference_field . '_title'},
      'link_path'  => $link_path,
      'menu_name'  => SOURIAU_COMMON_VAR_HEADER_MENU,
      'plid'       => $links[$parent_path]['mlid'],
      'weight'     => $weight,
      'customized' => TRUE,
    );

    // Update existing link if match.
    if (!empty($links[$link_path])) {
      $new_link += $links[$link_path];
    }
    menu_link_save($new_link);
    $links[$link_path] = $new_link;
  }
}

/**
 * Auto create level2 webform links on dashboard for view submissions.
 */
function _souriau_common_pages_webform_insert($node) {
  $menu_links = menu_load_links('menu-admin-menu');
  foreach ($menu_links as $item) {
    if ($item['link_path'] != 'admin/dashboard/webforms') {
      continue;
    }
    $title_field = field_get_items('node', $node, 'title_field', SOURIAU_COMMON_VAR_DEFAULT_LNG);
    $weight = empty($item->field_field_weight[0]['raw']['value']) ? 0 : $item->field_field_weight[0]['raw']['value'];
    $link_path = 'node/' . $node->nid . '/webform-results';
    $new_link = array(
      'link_title' => !empty($title_field[0]['value']) ? $title_field[0]['value'] : $node->title,
      'link_path'  => $link_path,
      'menu_name'  => 'menu-admin-menu',
      'plid'       => $item['mlid'],
      'weight'     => $weight,
      'customized' => TRUE,
    );
    menu_link_save($new_link);
  }
}
