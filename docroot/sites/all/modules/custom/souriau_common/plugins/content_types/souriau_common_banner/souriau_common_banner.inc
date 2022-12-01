<?php

/**
 * @file
 * Breadcrumbs CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU Common: Banner', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'description' => t('SOURIAU Common: Banner', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'content_types' => 'souriau_common_banner',
  'single' => TRUE,
  'render callback' => 'souriau_common_banner_content_type_render',
  'edit form' => 'souriau_common_banner_content_type_edit_form',
  'hook theme' => 'souriau_common_banner_content_type_theme',
  'admin title' => 'souriau_common_banner_content_type_admin_title',
  'category' => t('SOURIAU'),
  'icon' => NULL,
  'render last' => TRUE,
  'required context' => array(
    new ctools_context_optional(t('Node', array(), array('context' => SOURIAU_COMMON_T_ADMIN)), 'node'),
  ),

);

/**
 * Build breadcrumbs for different node types.
 */
function souriau_common_banner_node_breadcrumbs($node) {
  global $language;
  $link = '<front>';
  $breadcrumb = [];
  switch ($node->type) {
    case SOURIAU_COMMON_CAPABILITIES_LANDING_CT:
    case SOURIAU_COMMON_APPLICATION_LANDING_CT:
    case SOURIAU_COMMON_PRODUCT_LANDING_CT:
      // Get Current Item.
      _souriau_common_banner_parent_by_plid($node, $language->language, $current_item, $breadcrumb);
      break;

    case SOURIAU_COMMON_CAPABILITY_DOMAIN_CT:
    case SOURIAU_COMMON_APPLICATION_DOMAIN_CT:
    case SOURIAU_COMMON_CATEGORY_CT:
      // Set Hierarchy breadcrumbs.
      souriau_common_banner_set_breadcrumbs_hierarchy($node, $language, NULL, $breadcrumb);
      break;

    case SOURIAU_COMMON_SUBCATEGORY_CT:
    case SOURIAU_COMMON_APPLICATION_CT:
    case SOURIAU_COMMON_CAPABILITY_CT:
      // Set hierarchy into Breadcrumbs by menu links.
      souriau_common_banner_set_breadcrumbs_hierarchy($node, $language, NULL, $breadcrumb);
      break;

    case SOURIAU_COMMON_PRODUCT_RANGE_HUB_CT:
    case SOURIAU_COMMON_PRODUCT_RANGE_CT:
      // Set Current element.
      $title = souriau_common_get_field_value('node', $node, 'title_field');
      array_unshift($breadcrumb, souriau_common_microdata_tag($title));

      // Set General Breadcrumbs.
      souriau_common_banner_set_breadcrumbs_hierarchy($node, $language, NULL, $breadcrumb);
      break;

    case SOURIAU_COMMON_NEWS_LANDING_CT:
      array_unshift($breadcrumb, souriau_common_microdata_tag(t('News', [], ['context' => SOURIAU_COMMON_T_OTHER])));
      break;

    case SOURIAU_COMMON_NEWS_CT:
      _souriau_common_banner_parent_by_plid($node, $language->language, $current_item, $breadcrumb);
      $landing_nid = souriau_common_get_nids('news_landing');
      if (!empty($landing_nid)) {
        $link = 'node/' . $landing_nid[0];
      }
      array_unshift($breadcrumb, souriau_common_microdata_link(t('News', [], ['context' => SOURIAU_COMMON_T_OTHER]), $link));
      break;

    case SOURIAU_COMMON_PART_NUMBER_CT:
      // Set title.
      array_unshift($breadcrumb, souriau_common_microdata_tag($node->title));

      // Set static link to search page.
      array_unshift($breadcrumb, souriau_common_microdata_link(t('Search', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'search', ['query' => ['active_tab' => 'part-number']]));
      break;

    case SOURIAU_COMMON_TOOL_CT:
      $title = souriau_common_get_field_value('node', $node, 'title_field');
      array_unshift($breadcrumb, souriau_common_microdata_tag($title));
      $landing_nid = souriau_common_get_nids('toolkitlanding');
      if (!empty($landing_nid)) {
        $link = 'node/' . $landing_nid[0];
      }
      array_unshift($breadcrumb, souriau_common_microdata_link(t('Toolbox', [], ['context' => SOURIAU_COMMON_T_OTHER]), $link));
      break;

    case SOURIAU_COMMON_GENERIC_LANDING:
    case SOURIAU_COMMON_TOOLKIT_LANDING:
      $title = souriau_common_get_field_value('node', $node, 'title_field');
      array_unshift($breadcrumb, souriau_common_microdata_tag($title));
      break;

    case SOURIAU_COMMON_RESOURCE_CT:
      $title = souriau_common_get_field_value('node', $node, 'title_field');
      array_unshift($breadcrumb, souriau_common_microdata_tag($title));
      array_unshift($breadcrumb, souriau_common_microdata_link(t('VIDEO TUTORIALS', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'video-tutorials'));
      break;

    case SOURIAU_COMMON_CMS_PAGE:
      $cms_title = souriau_common_get_field_value('node', $node, 'title_field');
      array_unshift($breadcrumb, souriau_common_microdata_tag($cms_title));
      $referrer_url = $_SERVER['HTTP_REFERER'];
      $path = preg_replace('/\//', '', parse_url($referrer_url, PHP_URL_PATH), 1);
      if (!empty($language->prefix) && preg_match('/^' . $language->prefix . '/', $path) > 0) {
        $path = preg_replace('/^' . $language->prefix . '\//', '', $path);
      }
      $org_path = drupal_lookup_path("source", $path);
      $generic_node = menu_get_object("node", 1, $org_path);
      if ($generic_node->type == SOURIAU_COMMON_GENERIC_LANDING) {
        $generic_title = field_get_items('node', $generic_node, 'title_field', $language->language);
        $generic_title = $generic_title[0]['value'];
        $generic_link = 'node/' . $generic_node->nid;
        array_unshift($breadcrumb, souriau_common_microdata_link($generic_title, $generic_link));
      }
      break;

    default:
      break;

  }

  // Add Home link.
  array_unshift($breadcrumb, souriau_common_microdata_link(t('Home', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'));
  return $breadcrumb;
}

/**
 * Helper function for set category hierarchy into breadcrumbs.
 */
function souriau_common_banner_set_breadcrumbs_hierarchy($node, $language, $current_item, &$breadcrumb) {
  // Origin node type.
  $origin_type = $node->type;

  if ($origin_type == SOURIAU_COMMON_PART_NUMBER_CT) {
    $product_range = souriau_common_banner_set_breadcrumbs_parent_product_range($node, $language, $breadcrumb);
  }

  if ($origin_type == SOURIAU_COMMON_PRODUCT_RANGE_CT || !empty($product_range)) {
    $product_range = !empty($product_range) ? $product_range : $node;
    $node = _souriau_common_get_parent_node($product_range->nid, 'subcategory', 'field_product_range');
    if (empty($node)) {
      return;
    }
  }
  elseif ($origin_type == SOURIAU_COMMON_PRODUCT_RANGE_HUB_CT || !empty($product_range)) {
    $product_range = !empty($product_range) ? $product_range : $node;
    $node = _souriau_common_get_parent_node($product_range->nid, 'subcategory', 'field_product_range');
    if (empty($node)) {
      return;
    }
  }

  // Set Subcategory.
  _souriau_common_banner_parent_by_plid($node, $language->language, $current_item, $breadcrumb);
  if (!empty($current_item)) {
    // Set parent Category/Application Domain/Capability Domain.
    _souriau_common_banner_parent_by_plid($node, $language->language, $current_item, $breadcrumb);

    // Next level is required for Application, Subcategory, Capability, Product Range HUB and Product Range CT.
    if (!empty($current_item) && in_array($origin_type, [
      SOURIAU_COMMON_CAPABILITY_CT,
      SOURIAU_COMMON_APPLICATION_CT,
      SOURIAU_COMMON_SUBCATEGORY_CT,
      SOURIAU_COMMON_PRODUCT_RANGE_CT,
      SOURIAU_COMMON_PRODUCT_RANGE_HUB_CT,
    ])) {
      _souriau_common_banner_parent_by_plid($node, $language->language, $current_item, $breadcrumb);
    }

    if (in_array($origin_type, [
      SOURIAU_COMMON_CAPABILITY_DOMAIN_CT,
      SOURIAU_COMMON_APPLICATION_DOMAIN_CT,
      SOURIAU_COMMON_CATEGORY_CT,
      SOURIAU_COMMON_PART_NUMBER_CT,
    ])) {
      // Enough for links of level 2.
      // Part Number don't need Product Landing in breadcrumbs.
      return;
    }
  }
}

/**
 * Add to breadcrumbs Product Range.
 *
 * @return object
 *   Product Range node.
 */
function souriau_common_banner_set_breadcrumbs_parent_product_range($node, $language, &$breadcrumb) {
  $parent_product_range = souriau_common_get_main_product_range($node);
  if (empty($parent_product_range)) {
    return FALSE;
  }
  $pr_wrapper = entity_metadata_wrapper('node', $parent_product_range)->language($language->language);
  $link = l($pr_wrapper->title_field->value(), url('node/' . $parent_product_range->nid, ['external' => TRUE]));
  array_unshift($breadcrumb, $link);

  return $parent_product_range;
}

/**
 * Implements hook_content_type_render().
 */
function souriau_common_banner_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user, $language;
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $breadcrumbs = array();
  $context_node = $context[0];
  // B_white - extra class to Breadcrumbs and Share links.
  $b_white = NULL;
  $data['_html']['is_banner'] = FALSE;
  $data['_html']['node_type'] = NULL;

  // Process breadcrumbs for node.
  if (!empty($context_node->data)) {
    $node = $context_node->data;
    $breadcrumb = souriau_common_banner_node_breadcrumbs($node);

    // Add extra links into breadcrumbs.
    _souriau_common_breadcrumbs_extra_links($node, $breadcrumbs, $user);

    // Check, if need an extra class.
    $white_breadcrumbs = [
      'application',
      'applicationlanding',
      'applicationdomain',
      'capability',
      'capabilitydomain',
      'capabilitieslanding'
    ];
    if (in_array($node->type, $white_breadcrumbs)) {
      $b_white = 'b-white';
    }
  }

  // Fallback to default breadcrumb.
  if (!isset($breadcrumb)) {
    $breadcrumb = drupal_get_breadcrumb();
  }
  $breadcrumbs['breadcrumb'] = $breadcrumb;
  $data['_html']['breadcrumb'] = souriau_common_breadcrumbs($breadcrumbs, $b_white);

  $data['_html']['share'] = souriau_common_get_share_buttons($b_white);

  // Process banner.
  $ct_with_banner = [
    'category',
    'subcategory',
    'productrange',
    'productrangehub',
    'application',
    'applicationdomain',
    'applicationlanding',
    'capabilitydomain',
    'capabilitieslanding',
    'capability',
    'cms_page',
    'productlanding',
  ];
  if (isset($node) && in_array($node->type, $ct_with_banner)) {
    $banner_type = 'category-banner';
    $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
    $data['_html']['is_banner'] = TRUE;
    $ct_without_partnumber = [
      'applicationdomain',
      'applicationlanding',
      'capabilitydomain',
      'capabilitieslanding',
    ];

    if (!in_array($node->type, $ct_without_partnumber)) {
      $data['_html']['part_number_available'] = FALSE;
      $data['_html']['title'] = $node_wrapper->title_field->value();
      if (isset($node_wrapper->field_part_number_available)) {
        $data['_html']['part_number_available'] = $node_wrapper->field_part_number_available->value();
        $search_context = souriau_common_get_search_context($node, $node_wrapper);
        $data['_html']['search'] = theme('find_part_number', ['search_context' => $search_context]);
      }
    }
    else {
      $data['_html']['application_banner'] = TRUE;
      $banner_type = 'landing-app-banner';
    }
    try {
      $banner_image = [
        '#type' => 'figure_pic',
        '#image' => $node_wrapper->field_image->raw(),
      ];
    }
    catch (Exception $e) {
      watchdog_exception('banner_image', $e);
    }

    // Process Download block. (on Product Range CT).
    $capabilities_bundles = [
      'capability',
      'capabilitydomain',
      'capabilitieslanding',
    ];
    if ('productrange' == $node->type || 'productrangehub' == $node->type) {
      $data['_html']['node_type'] = $node->type;
      $banner_type = 'product-banner';
      $data['_html']['second_level_title'] = $node_wrapper->field_second_level_title->value();
    }
    elseif ('application' == $node->type) {
      $banner_type = 'application-banner';
    }
    elseif (in_array($node->type, $capabilities_bundles)) {
      $banner_type = 'landing-cap-banner';
    }
    elseif ('productlanding' == $node->type) {
      $data['_html']['node_type'] = 'productlanding';
      $banner_type = 'product-banner';
    }

    $data['_html']['b_type'] = $banner_type;
    $data['_html']['image'] = drupal_render($banner_image);
  }

  $block->content = theme('block_banner', $data);
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_banner_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Admin title callback.
 */
function souriau_common_banner_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: Banner', array(), array('context' => SOURIAU_COMMON_T_ADMIN));
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_banner_content_type_theme(&$theme, $plugin) {
  $theme['block_banner'] = array(
    'path' => $plugin['path'],
    'template' => 'souriau-common-banner',
    'variables' => array('params' => array()),
  );
}

/**
 * Return node path of pub.node.
 */
function _souriau_common_banner_get_node_path($node) {
  $node_path = 'node/' . $node->nid;
  if ($node->is_draft) {
    $prod_node = node_load($node->field_edition[LANGUAGE_NONE][0]['target_id']);
    $node_path = 'node/' . $prod_node->nid;
  }
  return $node_path;
}

/**
 * Helper function for adding additional links to breadcrumbs.
 */
function _souriau_common_breadcrumbs_extra_links($node, &$breadcrumbs, $user) {
  if (isset($node->is_draft) && ($node->is_draft == FALSE)) {
    $draft_node = node_load($node->edition_id);
  }
  else {
    $draft_node = $node;
  }

  if (node_access('update', $draft_node, $user) === TRUE) {
    $breadcrumbs['admin_link'] = l(t('[Edit node]', array(), array('context' => SOURIAU_COMMON_T_OTHER)), 'node/' . $draft_node->nid . '/edit', array(
      'attributes' => array(
        'class' => array('admin-link'),
      ),
    ));

    // Add link to view submissions for webforms.
    if (in_array($node->type, array('webform'))) {
      $breadcrumbs['webform_admin_link'] = l(t('[View results]', array(), array('context' => SOURIAU_COMMON_T_OTHER)), 'node/' . $node->nid . '/webform-results', array(
        'attributes' => array(
          'class' => array('admin-link'),
        ),
      ));
    }
  }

}

/**
 * Helper function for build banner.
 */
function _souriau_common_banner_build_search_form() {
  $icon = [
    '#type' => 'svg_icon',
    '#icon' => 'ico-search',
  ];
  $form = [
    '#type' => 'form',
    '#action' => 'search',
  ];
  $form['submit_wrapper'] = [
    '#type' => 'container',
    '#attributes' => [
      'class' => ['w-btn'],
    ],
  ];
  $elements = [
    'icon' => $icon,
    'span' => [
      '#attributes' => [
        'class' => ['btn-txt'],
      ],
      '#value' => t('search', array(), array('context' => SOURIAU_COMMON_T_OTHER)),
    ],
  ];
  $form['submit_wrapper']['submit'] = [
    '#type' => 'button',
    '#attributes' => [
      'class' => ['btn', 'btn_search'],
    ],
    '#souriau_settings' => [
      '#elements' => $elements,
    ],
  ];
  $form['search'] = [
    '#type' => 'textfield',
    '#attributes' => [
      'placeholder' => 'FIND A PART NUMBER',
      'class' => ['form-text'],
    ],
  ];
  return drupal_render($form);
}

/**
 * Helper function for build breadcrumbs.
 */
function _souriau_common_banner_parent_by_plid($node, $langcode, &$current_item, &$breadcrumb) {
  if (empty($current_item)) {
    $node_path = _souriau_common_banner_get_node_path($node);
    $current_item = menu_link_get_preferred($node_path, SOURIAU_COMMON_VAR_HEADER_MENU);

    if (!empty($current_item) && !empty($breadcrumb)) {
      array_unshift($breadcrumb, souriau_common_microdata_link(souriau_common_microdata_tag(_i18n_menu_link_title($current_item)), $node_path));
    }
    elseif (!empty($current_item)) {
      $breadcrumb_item_value = _i18n_menu_link_title($current_item);
      array_unshift($breadcrumb, souriau_common_microdata_tag($breadcrumb_item_value));
    }
    elseif (empty($current_item) && !empty($breadcrumb)) {
      $node_wrapper = entity_metadata_wrapper('node', $node)->language($langcode);
      array_unshift($breadcrumb, souriau_common_microdata_link(souriau_common_microdata_tag($node_wrapper->title_field->value()), $node_path));
    }
    else {
      $node_wrapper = entity_metadata_wrapper('node', $node)->language($langcode);
      array_unshift($breadcrumb, souriau_common_microdata_tag($node_wrapper->title_field->value()));
    }
    return;
  }

  if (!empty($current_item['plid'])) {
    $parent_item = menu_link_load($current_item['plid']);
    $parent_item_value = _i18n_menu_link_title($parent_item);
    array_unshift($breadcrumb, souriau_common_microdata_link(souriau_common_microdata_tag($parent_item_value), $parent_item['link_path']));
  }
  else {
    $node_wrapper = entity_metadata_wrapper('node', $node)->language($langcode);
    array_unshift($breadcrumb, souriau_common_microdata_tag($node_wrapper->title_field->value()));
  }
  if (!empty($parent_item)) {
    $current_item = $parent_item;
  }
}

/**
 * Helper function for build downloads block in the banner.
 */
function _souriau_common_banner_render_downloads_block($files, $columns = FALSE) {
  $options = ['html' => TRUE];
  $items = [];
  foreach ($files as $file) {
    if (!$file['published']) {
      continue;
    }

    $icon = [
      '#type' => 'svg_icon',
      '#icon' => 'ico-pdf',
    ];

    $file_values = _souriau_common_get_file_values__download_block($file['fid']);

    if ($file['type'] == 'ipaper') {
      $icon['#icon'] = 'ico-ipaper';
      $options += [
        'external' => TRUE,
        'attributes' => [
          'target' => '_blank',
        ],
      ];
    }

    if (count($items) >= 5) {
      $items[] = [
        'data' => l(drupal_render($icon) . $file_values['file_title'], $file_values['file_url'], $options),
        'class' => ['hide-link'],
      ];
    }
    else {
      $items[] = [
        'data' => l(drupal_render($icon) . $file_values['file_title'], $file_values['file_url'], $options),
      ];
    }
  }

  // Link More.
  $more = [
    'data' => l(t('+ MORE', [], ['context' => SOURIAU_COMMON_T_OTHER]), '#', [
      'attributes' => [
        'class' => ['more-visible'],
        'data-block' => ['block-links'],
      ],
      'external' => TRUE,
    ]),
  ];

  if ($columns) {
    $columns = [];
    // Set links in 2 columns.
    foreach ($items as $key => $item) {
      $column = fmod($key, 2);
      $columns[$column][] = $item;
    }
    // Add link more in 2nd column.
    if (count($items) > 5) {
      $columns[1][] = $more;
    }

    $output = '';
    foreach ($columns as $column) {
      $links = array(
        'items' => $column,
        'title' => NULL,
        'type' => 'ul',
      );
      $output .= '<div class="column">';
      $output .= theme('item_list', $links);
      $output .= '</div>';
    }
  }
  else {
    // Add link more in the end.
    if (count($items) > 5) {
      $items[] = $more;
    }
    $links = array(
      'items' => $items,
      'title' => NULL,
      'type' => 'ul',
    );

    $output = theme('item_list', $links);
  }
  return $output;
}
