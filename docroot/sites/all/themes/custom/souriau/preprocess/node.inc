<?php
/**
 * @file
 * Node preprocess functions.
 */

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__productlanding__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $spacer = '<!--fix inline-block
-->';
  // Title  & Image.
  $_html['title'] = $node_wrapper->title_field->value();
  try {
    $_html['image'] = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->value(),
      '#alt' => 'banner image',
    ];
  }
  catch (Exception $e) {
    watchdog_exception('product_landing_hero_image', $e);
  }
  $_html['image'] = drupal_render($_html['image']);

  // Categories.
  $_html['categories'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_category', 'product_landing_page');

  // General Description.
  $_html['description'] = souriau_common_get_field_value('node', $node, 'field_description');

  // Block interest.
  $urls = variable_get('souriau_common_settings');
  $params = [
    '3dmodel_url' => !empty($urls['block_of_interest_urls']['3dmodel_url']) ? $urls['block_of_interest_urls']['3dmodel_url'] : '',
    'technical_support' => !empty($urls['block_of_interest_urls']['technical_suppport_url']) ? $urls['block_of_interest_urls']['technical_suppport_url'] : '',
  ];
  $_html['block_interest'] = theme('block_interest', ['params' => $params]);

  // Top Products.
  $_html['top_products'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_cross_sell_product_range', 'product_landing_page', [], $spacer);

  // Block Brand.
  $_html['brand'] = _souriau_preprocess_node_productlanding_brand($node_wrapper, $node, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__category__product_landing_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $entity = entity_metadata_wrapper('node', $node)->language($language->language);

  $title = '<div class="title"><h2>' . $entity->title_field->value() . '</h2></div>';
  $title .= '<div class="view-more">' . t('VIEW MORE', array(), array('context' => 'SOURIAU: other')) . '</div>';
  $_html['category'] = l('<div class="text">' . $title . '</div>',
    'node/' . $entity->nid->raw(),
    array(
      'html'  => TRUE,
      'attributes' => array(
        'class' => array('item'),
      ),
    )
  );
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__postcard__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $entity = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['title'] = $entity->title_field->value();

  $_html['description'] = souriau_common_get_field_value('node', $node, 'body');
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrange__product_landing_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Helper Function for build brand block of ProductLanding CT.
 */
function _souriau_preprocess_node_productlanding_brand($wrapper, $node, &$_html) {
  // Process presentation (ECT).
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $wrapper->field_ect_image->raw(),
      '#attributes' => [
        'title' => $wrapper->field_ect_image->file->value()->title,
        'alt' => $wrapper->field_ect_image->file->value()->alt,
      ],
    ];
  }
  catch (Exception $e) {
    watchdog_exception('productlanding_brand_image', $e);
  }
  $_html['presentation_image'] = drupal_render($image);
  $_html['presentation_description'] = souriau_common_get_field_value('node', $node, 'field_ect_description');

  // Process brands.
  foreach (['SOURIAU', 'SUNBANK'] as $brand) {
    $description = souriau_common_get_field_value('node', $node, 'field_' . drupal_strtolower($brand) . '_description');
    $brand_strtolower = drupal_strtolower($brand);
    $_html[$brand_strtolower . '_title'] = t($brand, [], ['context' => SOURIAU_COMMON_T_OTHER]);
    $_html[$brand_strtolower . '_description'] = isset($description) ? $description : '';
  }
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__category__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // General Description.
  $_html['description'] = souriau_common_get_field_value('node', $node, 'field_description');

  // SubCategories.
  $_html['is_grouped'] = FALSE;
  $is_grouped = variable_get('souriau_common_settings');
  $is_grouped = isset($is_grouped['grouping']['is_group']) ? $is_grouped['grouping']['is_group'] : FALSE;
  if ('Connectors' == $node->title_original && $is_grouped) {
    $_html['is_grouped'] = $is_grouped;
    $groups = '';

    // Grouping Nodes.
    $output = _souriau_preprocess_build_grouped_subcategory($node_wrapper, $groups);

    $_html['subcategories'] = theme('category_group', $output);
    $_html['groups'] = theme('item_list', array(
      'items' => $groups,
      'title' => NULL,
      'type' => 'ul',
      'attributes' => [
        'class' => ['nav', 'nav-tabs']
      ]
    ));
  }
  else {
    $_html['subcategories'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_subcategory', 'category_page');
  }

  // Downloads.
  $files = $node_wrapper->field_downloads->value();
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files);

  // Block interest.
  $urls = variable_get('souriau_common_settings');
  $params = [
    '3dmodel_url' => !empty($urls['block_of_interest_urls']['3dmodel_url']) ? $urls['block_of_interest_urls']['3dmodel_url'] : '',
    'technical_support' => !empty($urls['block_of_interest_urls']['technical_suppport_url']) ? $urls['block_of_interest_urls']['technical_suppport_url'] : '',
  ];
  $_html['block_interest'] = theme('block_interest', ['params' => $params]);

  // Block product-items.
  $_html['discover'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_cross_sell_product_range', 'category_page');
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrange__category_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__subcategory__category_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $entity = entity_metadata_wrapper('node', $node)->language($language->language);

  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $entity->field_image->raw(),
      '#attributes' => [
        'title' => $entity->field_image->file->value()->title,
        'alt' => $entity->field_image->file->value()->alt,
      ],
      '#style' => 'product_thumbnails',
    ];
  }
  catch (Exception $e) {
    watchdog_exception('subcategory_image', $e);
  }
  $_html['image'] = drupal_render($image);
  $_html['title'] = $entity->title_field->value();
  $_html['href'] = url('node/' . $entity->nid->raw());
}

/**
 * Helper function for build downloads block.
 */
function _souriau_preprocess_node__category__render_downloads($files, $sku = NULL, $is_sku = FALSE) {
  // Prepare file links.
  $items = [];
  if ($is_sku) {
    $partnumber = souriau_common_load_part_number_by_sku($sku);
    $parent_product_range = souriau_common_get_main_product_range($partnumber);
    if (!empty($parent_product_range)) {
      $catalog_file = field_get_items('node', $parent_product_range, 'field_pn_catalog');
      if (!empty($catalog_file)) {
        $files['Catalog'] = $catalog_file[0];
      }
    }
  }
  if (empty($files)) {
    return;
  }

  foreach ($files as $key => $file) {
    if (isset($file['file']) && is_object($file['file'])) {
      $file = get_object_vars($file['file']);
    }

    if (!$file['published']) {
      continue;
    }

    $icon = [
      '#type' => 'svg_icon',
      '#icon' => 'ico-pdf'
    ];
    $gtm_action = 'Document';
    if ($file['type'] == 'ipaper') {
      $icon['#icon'] = 'ico-ipaper';
      $gtm_action = 'ipaper';
    }
    if ($file['type'] == '3d_model') {
      $icon['#icon'] = 'ico-3dmodel';
      $gtm_action = '3Dpicture';
    }
    $file_values = _souriau_common_get_file_values__download_block($file['fid']);

    $attributes = [
      'target' => '_blank',
      'class' => ['gtm_element'],
      'data-gtm-category' => 'Download',
      'data-gtm-action' => $gtm_action,
      'data-gtm-label' => $file_values['file_title'],
    ];
    $file_name = drupal_basename($file['uri']);
    if ($is_sku) {
      $file_name = drupal_basename(str_replace($file_name, '', $file['uri']));
      if ('Catalog' === $key) {
        $file_name = $key;
      }
      $icon = [
        '#markup' => '<span class="file-download-wrapper">' . $file_name . '</span>',
      ];
      $file_values['file_name'] = '';
      $attributes['data-gtm-label'] = $sku;
    }

    $items[] = l(drupal_render($icon) . $file_values['file_name'], $file_values['file_url'], [
      'html' => TRUE,
      'attributes' => $attributes,
    ]);
  }
  // Render links.
  $output = '';
  if (count($items)) {
    $links = [
      'items' => $items,
      'title' => NULL,
      'type' => 'ul',
      'attributes' => ['class' => ($is_sku) ? 'sku-downloads' : ''],
    ];
    $output = theme('item_list', $links);
  }

  return $output;
}

/**
 * Helper function for build top/complementary product range links.
 */
function _souriau_preprocess_build_product_range_links($entity, &$_html) {
  // Image.
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $entity->field_image->raw(),
      '#style' => 'product_thumbnails',
    ];
  }
  catch (Exception $e) {
    watchdog_exception('productrange_image', $e);
  }

  $_html['image'] = drupal_render($image);

  // Title.
  $_html['title'] = $entity->title_field->value();
  $_html['second_level_title'] = $entity->field_second_level_title->value();

  // Description.
  $items = [];
  $key_words = $entity->field_key_words->value();
  foreach ($key_words as $term) {
    $term->name = !empty($term->name) ? $term->name : $term->name_original;
    $items[] = $term->name;
  }

  $_html['description'] = theme('item_list', [
    'items' => $items,
    'title' => NULL,
    'type' => 'ul',
  ]);

  $_html['discover'] = t('DISCOVER', [], ['context' => 'SOURIAU: other']);
  $_html['href'] = url('node/' . $entity->nid->raw());
}

/**
 * Helper function for build grouped subcategories on category page.
 */
function _souriau_preprocess_build_grouped_subcategory($node_wrapper, &$groups) {
  $subcategories = $node_wrapper->field_subcategory->value();
  $output = [];
  $groups['all'] = [
    'class' => ['active'],
    'data' => '<a data-toggle="tab" aria-expanded="true" href="#all">' . t('ALL', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</a>'
  ];
  foreach ($subcategories as $subcategory) {

    // Load group by Term ID.
    $term_id = field_get_items('node', $subcategory, 'field_in_grouping');
    // Fallback if $term_id is empty.
    $term_name = t('ALL', [], ['context' => SOURIAU_COMMON_T_OTHER]);
    if (!empty($term_id)) {
      $term = taxonomy_term_load($term_id[0]['tid']);
      $term_name = !empty($term->name) ? $term->name : $term->name_original;
    }
    $machine_name = souriau_common_get_machine_name($term_name);

    // Collect groups.
    if (!isset($groups[$machine_name])) {
      $groups[$machine_name] = [];
    }

    // Collect nodes.
    $output['groups'][$machine_name][] = [
      '#node' => $subcategory,
      '#node_view' => 'category_page',
      '#group' => $machine_name,
      '#group name' => $term_name,
    ];
    if ('all' != $machine_name) {
      $output['groups']['all'][] = [
        '#node' => $subcategory,
        '#node_view' => 'category_page',
        '#group' => $machine_name,
        '#group name' => $term_name,
      ];
    }
  }

  // Set active on 'All' group.
  $output['groups']['all']['#active'] = 'active in';

  // Adding count of each group.
  foreach ($groups as $group_name => &$group) {
    if ('all' == $group_name) {
      continue;
    }
    $count = count($output['groups'][$group_name]);
    $group['data'] = '<a data-toggle="tab" aria-expanded="true" href="#' . $group_name . '">' . drupal_strtoupper($output['groups'][$group_name][0]['#group name']) . ' (' . $count . ')</a>';
  }

  return $output;
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__subcategory__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // Description.
  $_html['description'] = souriau_common_get_field_value('node', $node, 'field_description');

  // Product Ranges.
  $_html['product_ranges'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_product_range', 'subcategory_page');

  // Downloads.
  $files = $node_wrapper->field_downloads->value();
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files);

  // Block interest.
  $urls = variable_get('souriau_common_settings');
  $params = [
    '3dmodel_url' => !empty($urls['block_of_interest_urls']['3dmodel_url']) ? $urls['block_of_interest_urls']['3dmodel_url'] : '',
    'technical_support' => !empty($urls['block_of_interest_urls']['technical_suppport_url']) ? $urls['block_of_interest_urls']['technical_suppport_url'] : '',
  ];
  $_html['block_interest'] = theme('block_interest', ['params' => $params]);

  // Cross sell products.
  $_html['cross_sell'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_cross_sell_product_range', 'subcategory_page');
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrange__subcategory_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__productrange__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // Key Features.
  $_html['features'] = souriau_common_get_field_value('node', $node, 'field_key_features');

  // Paragraph.
  $paragraphs = $node_wrapper->field_paragraphs->value();
  $_html['paragraphs'] = '';
  foreach ($paragraphs as $paragraph) {
    $_html['paragraphs'] .= theme('paragraph_two_col_title_description', ['entity' => $paragraph]);
  };

  // Downloads.
  $files = $node_wrapper->field_downloads->value();
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files);

  // Promotion block.
  $_html['promotion'] = '';
  $promotion = $node_wrapper->field_tool->value();
  $node_view = souriau_common_build_node_view($promotion, 'product_range_page');
  $_html['promotion'] .= drupal_render($node_view);

  // Application.
  $_html['catchline'] = souriau_common_get_field_value('node', $node, 'field_application_catchline');

  $_html['applications'] = '';
  $application_paragraphs = $node_wrapper->field_paragraph_aplication->value();
  foreach ($application_paragraphs as $paragraph) {
    $catchline = field_get_items('paragraphs_item', $paragraph, 'field_paragraph_catchline');
    $paragraph_title = field_get_items('paragraphs_item', $paragraph, 'field_pr_paragraph_title');
    $paragraph_image = field_get_items('paragraphs_item', $paragraph, 'field_paragraph_image');
    if (empty($paragraph_title)) {
      continue;
    }
    $paragraph_image = [
      '#type' => 'figure_pic',
      '#image' => isset($paragraph_image[0]) ? $paragraph_image[0] : '',
      '#attributes' => [],
    ];
    $paragraph_image = drupal_render($paragraph_image);
    $params = [
      'catchline' => !empty($catchline) ? $catchline[0]['value'] : '',
      'paragraph_image' => $paragraph_image,
      'paragraph_title' => !empty($paragraph_title) ? $paragraph_title[0]['value'] : '',
    ];
    $_html['applications'] .= theme('paragraph_product_range_application', ['params' => $params]);
  }

  // Similar products.
  $_html['similar_products'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_similar_product_ranges', 'product_range_page');

  // Complementary products.
  $_html['complementary'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_complementary_product_rang', 'product_range_page');

  // News.
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);

  // FAQ.
  $_html['faq'] = souriau_common_get_faq_per_productrange($node->nid);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__productrangehub__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  // Key Features.
  $_html['features'] = souriau_common_get_field_value('node', $node, 'field_key_features');

  // Paragraph.
  $paragraphs = $node_wrapper->field_paragraphs->value();
  $_html['paragraphs'] = '';
  foreach ($paragraphs as $paragraph) {
    $_html['paragraphs'] .= theme('paragraph_two_col_title_description', ['entity' => $paragraph]);
  };

  // Downloads.
  $files = $node_wrapper->field_downloads->value();
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files);

  // Promotion block.
  $_html['promotion'] = '';
  $promotion = $node_wrapper->field_tool->value();
  $node_view = souriau_common_build_node_view($promotion, 'product_range_page');
  $_html['promotion'] .= drupal_render($node_view);

  // Application.
  $_html['catchline'] = souriau_common_get_field_value('node', $node, 'field_application_catchline');

  $_html['applications'] = '';
  $application_paragraphs = $node_wrapper->field_paragraph_aplication->value();
  foreach ($application_paragraphs as $paragraph) {
    $catchline = field_get_items('paragraphs_item', $paragraph, 'field_paragraph_catchline');
    $paragraph_title = field_get_items('paragraphs_item', $paragraph, 'field_pr_paragraph_title');
    $paragraph_image = field_get_items('paragraphs_item', $paragraph, 'field_paragraph_image');

    $paragraph_image = [
      '#type' => 'figure_pic',
      '#image' => isset($paragraph_image[0]) ? $paragraph_image[0] : '',
      '#attributes' => [],
    ];
    $paragraph_image = drupal_render($paragraph_image);
    $params = [
      'catchline' => !empty($catchline) ? $catchline[0]['value'] : '',
      'paragraph_image' => $paragraph_image,
      'paragraph_title' => !empty($paragraph_title) ? $paragraph_title[0]['value'] : '',
    ];
    $_html['applications'] .= theme('paragraph_product_range_application', ['params' => $params]);
  }

  // Similar products.
  $_html['similar_products'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_similar_product_ranges', 'product_range_page');

  // Complementary products.
  $_html['complementary'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_complementary_product_rang', 'product_range_page');

  // News.
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__tool__product_range_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $promo_icon = array(
    '#type' => 'svg_icon',
    '#icon' => 'ico-tool',
  );
  $_html['icon'] = drupal_render($promo_icon);
  $_html['promo_link'] = l(t('TRY IT', [], ['context' => 'SOURIAU: other']), 'node/' . $node->nid, [
    'attributes' => [
      'class' => ['view-more', 'gtm_element'],
      'data-gtm-category' => 'Button',
      'data-gtm-action' => $node_wrapper->title_field->value(),
      'data-gtm-label' => $node_wrapper->title_field->value(),
    ],
  ]);
  $_html['promo_text'] = souriau_common_get_field_value('node', $node, 'field_cta_description');
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__application__product_range_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['href'] = url('node/' . $node->nid);
  $_html['title'] = $node_wrapper->title_field->value();
  if (!empty($node->field_catchline[$language->language])) {
    $_html['catchline'] = $node_wrapper->field_catchline->value();
  }
  // Process Image.
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->raw(),
    ];
  }
  catch (Exception $e) {
    watchdog_exception('application_productrange_image', $e);
  }
  $_html['image'] = drupal_render($image);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__productrange__product_range_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__productrangehub__product_range_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Helper Function for prepare html of News Block.
 */
function _souriau_preprocess_node__prepare_html_news_block($node_wrapper, &$_html) {
  global $language;
  $news_terms = $node_wrapper->field_tags->value();
  $tids = [];
  $params = ['souriau_query_get_news', 'default'];

  foreach ($news_terms as $term) {
    $tids[] = $term->tid;
  }
  $news = call_user_func_array('views_get_view_result', array_merge($params, $tids));

  foreach ($news as $item) {
    if ($node_wrapper->nid->value() != $item->nid) {
      $news_node = node_load($item->nid);
      $node_view = souriau_common_build_node_view($news_node, 'product_range_page');
      $_html['news'] .= drupal_render($node_view);
    }
  }
  $souriau_variables = variable_get('souriau_site_settings_variables');
  $link_params = [
    'attributes' => [
      'class' => ['view-more']
    ],
    'external' => TRUE,
  ];

  // News more button.
  $landing_nid = souriau_common_get_nids('news_landing');
  $link = '#';
  if (!empty($landing_nid)) {
    $link = '/node/' . reset($landing_nid);
    $link_params['query'] = ['selected' => implode(',', $tids)];
  }
  $_html['news_more'] = l(t('MORE NEWS', [], ['context' => SOURIAU_COMMON_T_OTHER]), $link, $link_params);
  $link_params['attributes']['class'][] = 'blue-btn';
  $_html['news_more_blue'] = l(t('MORE NEWS', [], ['context' => SOURIAU_COMMON_T_OTHER]), $link, $link_params);
  $catchline = isset($souriau_variables['block_news']['news']) ? $souriau_variables['block_news']['news'] : 'Website Hosting Reviews Free The Best Resource';
  $_html['news_catchline'] = '<p>' . t($catchline, [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</p>';
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__news__product_range_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  _souriau_preprocess_node__news__prepare_html($node_wrapper, $_html);
}

/**
 * Helper function: prepare html for preprocess node News.
 */
function _souriau_preprocess_node__news__prepare_html($node_wrapper, &$_html) {
  $icon = [
    '#type' => 'svg_icon',
    '#icon' => 'ico-tag',
  ];
  $_html['icon'] = drupal_render($icon);

  $_html['href'] = url('node/' . $node_wrapper->nid->raw());
  $_html['title'] = $node_wrapper->title_field->value();
  $_html['date'] = format_date($node_wrapper->created->raw(), 'custom', 'd/m/Y');

  $news_tags = $node_wrapper->field_tags->value();
  $tags = [];
  foreach ($news_tags as $term) {
    $tags[] = drupal_strtoupper($term->name);
  }
  $tags = implode(', ', $tags);

  $_html['tag'] = $tags;
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__application__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $spacer = '<!--fix inline-block
-->';
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // Our Solution.
  $_html['solution'] = souriau_common_get_field_value('node', $node, 'field_our_solution');

  // Paragraph.
  $paragraphs = $node_wrapper->field_paragraphs->value();
  $_html['paragraphs'] = '';
  foreach ($paragraphs as $paragraph) {
    $_html['paragraphs'] .= theme('paragraph_two_col_title_description', ['entity' => $paragraph]);
  };

  // Discover our products.
  $_html['top_products'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_product_range', 'application_page', [], $spacer);

  // Downloads.
  $files = $node_wrapper->field_downloads->value();
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files);

  // Examples.
  $_html['examples'] = '';
  $examples = $node_wrapper->field_example->value();
  foreach ($examples as $example) {
    $_html['examples'] .= theme('paragraph_application_examples', ['entity' => $example]);
  }

  // News.
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__productrange__application_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__productrangehub__application_page(&$variables) {
  souriau_preprocess_node__productrange__application_page($variables);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__applicationdomain__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // Title.
  $_html['title'] = $node_wrapper->title_field->value();

  // Description & Search.
  $_html['description'] = souriau_common_get_field_value('node', $node, 'field_description');

  // Part number search button status.
  $_html['part_number_available'] = $node_wrapper->field_part_number_available->value();

  // Application.
  $applications = $node_wrapper->field_application->value();
  $search_context = souriau_common_get_search_context($node, $node_wrapper);
  $_html['search'] = theme('find_part_number', ['search_context' => $search_context]);
  $_html['applications'] = '';
  foreach ($applications as $application) {
    $node_view = souriau_common_build_node_view($application, 'applicationdomain_page');
    $_html['applications'] .= drupal_render($node_view);
  }

  // News.
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__applicationdomain__application_landing_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  // Process Image.
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->raw(),
    ];
  }
  catch (Exception $e) {
    watchdog_exception('applicationdomain_applicationlanding_image', $e);
  }
  $_html['image'] = drupal_render($image);
  $_html['catchline'] = $node_wrapper->field_catchline->value();
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__applicationlanding__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['application_domains'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_application_domain', 'application_landing_page');
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__application__applicationdomain_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['href'] = url('node/' . $node->nid);
  $_html['title'] = $node_wrapper->title_field->value();
  if (!empty($node->field_catchline[$language->language])) {
    $_html['catchline'] = $node_wrapper->field_catchline->value();
  }
  // Process Image.
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->raw(),
    ];
  }
  catch (Exception $e) {
    watchdog_exception('application_applicationdomain_image', $e);
  }
  $_html['image'] = drupal_render($image);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__news__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $body = field_get_items('node', $node, 'field_body');
  $body = field_view_value('node', $node, 'field_body', $body[0]);
  $_html['body'] = drupal_render($body);

  $kicker = field_get_items('node', $node, 'field_kicker');
  $kicker = field_view_value('node', $node, 'field_kicker', $kicker[0]);
  $_html['kicker'] = drupal_render($kicker);
  $tags = $variables['field_tags'];
  if (!empty($tags)) {
    foreach ($tags as $tag) {
      $term = taxonomy_term_load($tag['tid']);
      $_html['tags'][] = $term->name;
    }
  }
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);
  _souriau_preprocess_node__news__prepare_html($node_wrapper, $_html);
}

/**
 * Helper function to render preview block.
 */
function _suriau_preprocess_node__render_preview_block($node_wrapper, $field, $view_mode, $products = [], $spacer = '') {
  global $language;
  if (!empty($node_wrapper) && !empty($field)) {
    $products = $node_wrapper->$field->value();
  }

  if (empty($products)) {
    return FALSE;
  }

  $output = [];
  foreach ($products as $product) {
    $node_view = souriau_common_build_node_view($product, $view_mode);
    $output[] = trim(drupal_render($node_view));
  }
  $output = array_filter($output);

  $final_output = implode($spacer, $output);
  if (!empty($final_output)) {
    return $final_output;
  }
  return FALSE;
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__capabilitieslanding__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['capability_domains'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_capability_domain', 'capability_landing_page');
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__capabilitydomain__capability_landing_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  // Process Image.
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->raw(),
    ];
  }
  catch (Exception $e) {
    watchdog_exception('capabilitydomain_image', $e);
  }
  $_html['image'] = drupal_render($image);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__capability__capability_landing_page(&$variables) {
  souriau_preprocess_node__capabilitydomain__capability_landing_page($variables);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__capabilitydomain__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // Title.
  $_html['title'] = $node_wrapper->title_field->value();

  // Description & Search.
  $_html['description'] = $node_wrapper->field_description->value();

  // Application.
  $capabilities = $node_wrapper->field_capability->value();
  $_html['capabilities'] = '';
  foreach ($capabilities as $capability) {
    $node_view = souriau_common_build_node_view($capability, 'capabilitydomain_page');
    $_html['capabilities'] .= drupal_render($node_view);
  }

  // News.
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__capability__capabilitydomain_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['href'] = url('node/' . $node->nid);
  $_html['title'] = $node_wrapper->title_field->value();
  if (!empty($node->field_catchline[$language->language])) {
    $_html['catchline'] = $node_wrapper->field_catchline->value();
  }
  // Process Image.
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->raw(),
    ];
  }
  catch (Exception $e) {
    watchdog_exception('capability_image', $e);
  }
  $_html['image'] = drupal_render($image);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__product__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $sku = $node_wrapper->field_sku_products->raw();
  if (empty($sku)) {
    // SKU required.
    return;
  }
  $sku = $node_wrapper->field_sku_products->value();

  if (!$sku->status) {
    return drupal_not_found();
  }
  // Create Part Number content: image/description/stock information.
  _souriau_preprocess_create_description_block_html($sku, $node_wrapper, $_data, $_html);
  $_html['description'] = souriau_common_get_part_number_field_value($node, 'description');

  // Key Features.
  $_html['key_features'] = souriau_common_get_part_number_field_value($node, 'key_features');

  // Downloads.
  $dc_new_layout = variable_get('pn_page_dc_layout', FALSE);
  $files = field_get_items('commerce_product', $sku, 'field_sku_attachments');
  $files = ($files === FALSE) ? [] : $files;
  if ($dc_new_layout) {
    $stp = field_get_items('commerce_product', $sku, 'field_sku_3d_model');
    if (!empty($stp[0])) {
      array_unshift($files, $stp[0]);
    }
  }
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files, $sku->sku, $dc_new_layout);

  // Technical data.
  $entity_view = entity_view('commerce_product', [$sku], 'part_number');
  $_html['tech_data'] = drupal_render($entity_view);

  // Complementary products.
  $groups = '';
  $complementary = $node_wrapper->field_complementary_part_number->value();
  $_html['complementary'] = _souriau_preprocess_product_render_preview_part_numbers($complementary, $groups, '0');
  $_html['compl_groups'] = $groups;

  // Help and advice.
  // Advice description.
  $_html['advices_description'] = souriau_common_get_part_number_field_value($node, 'advices_description');

  // Advice Image.
  $advices_image = souriau_common_get_part_number_field_value($node, 'advices_image');
  $advices_image = [
    '#type' => 'figure_pic',
    '#image' => $advices_image,
  ];
  $_html['advices_image'] = drupal_render($advices_image);

  // Advices.
  $_html['advices'] = [];
  $advices = souriau_common_get_part_number_field_value($node, 'advices');
  foreach ($advices as $advice) {

    $description = field_get_items('advice', $advice, 'field_advice_description');
    $video_id = field_get_items('advice', $advice, 'field_advice_video');
    $image = field_get_items('advice', $advice, 'field_advice_image');
    $image = isset($image[0]) ? array_shift($image) : [];

    // Convert the youtube link to embeded format.
    $video_id = ($video_id) ? $video_id[0]['video_id'] : NULL;
    $advice_image = [
      '#type' => 'figure_pic',
      '#image' => $image,
    ];

    $advice_description = field_view_value('advice', $advice, 'field_advice_description', $description[0]);
    $_html['advices'][] = [
      'title' => !empty($advice->title) ? $advice->title : '',
      'description' => !empty($description) ? drupal_render($advice_description) : '',
      'video_id' => $video_id,
      'image' => $advice_image,
    ];
  }

  // Recommended products.
  $groups = '';
  $recommended = $node_wrapper->field_recommendation->value();
  $_html['recommendation'] = _souriau_preprocess_product_render_preview_part_numbers($recommended, $groups, '1');
  $_html['rec_groups'] = $groups;

  // Comparator data.
  $comparator_data = isset($_COOKIE['Drupal_visitor_part_numbers']) ? explode(',', $_COOKIE['Drupal_visitor_part_numbers']) : [];
  $comparator_data = array_filter($comparator_data);
  $comparator_count = count($comparator_data);
  $_html['comparator_string'] = $comparator_count == 0 ? '' : format_plural($comparator_count, t('1 item added', [], ['context' => SOURIAU_COMMON_T_OTHER]), t('@count items added', [], ['context' => SOURIAU_COMMON_T_OTHER]));
}

/**
 * Helper function for render products related products.
 *
 * @return string.
 *   HTML
 */
function _souriau_preprocess_product_render_preview_part_numbers($products, &$groups, $delta = '0') {
  $items = [];
  // Get groups with products.
  $products_array = _souriau_preprocess_products_groups($products);

  // Active class.
  $active = 'active in';
  $aria_expanded = ['true'];

  // Create HTML.
  $products_html = '';
  foreach ($products_array as $group_name => $products) {
    $group_name = drupal_strtoupper($group_name);
    $group_name_machine = souriau_common_get_machine_name($group_name) . $delta;
    $products_html .= '<div id="' . $group_name_machine . '" class="tab-pane fade ' . $active . '"><div class="product-items">';
    // Load view mode for products.
    $products_html .= _suriau_preprocess_node__render_preview_block(FALSE, FALSE, 'part_number', $products);
    $products_html .= '</div></div>';

    // Process groups:
    if (count($products_array) == 1 && $group_name == 'ALL') {
      continue;
    }
    $active = '';
    if (empty($items)) {
      // Set attribute for first item of list.
      $items[$group_name]['class'] = ['active'];
    }
    $items[$group_name]['data'] = l(t($group_name, [], ['context' => SOURIAU_COMMON_T_OTHER]) . ' (' . count($products) . ')', '#' . $group_name_machine, [
      'attributes' => [
        'data-toggle' => 'tab',
        'aria-controls' => '#' . $group_name_machine,
        'aria-expanded' => !empty($aria_expanded) ? array_shift($aria_expanded) : 'false',
      ],
      'external' => TRUE,
    ]);
  }
  if (empty($items)) {
    return $products_html;
  }
  $groups = theme('item_list', array(
    'items' => $items,
    'title' => NULL,
    'type' => 'ul',
    'attributes' => [
      'class' => ['nav', 'nav-tabs']
    ]
  ));
  // Return products.
  return $products_html;
}

/**
 * Helper function for create product groups.
 */
function _souriau_preprocess_products_groups($products) {
  $products_array = [];
  foreach ($products as $product) {
    // Get Part Number by code_p (sku).
    $product = souriau_common_load_part_number_by_sku($product->sku);
    if (empty($product)) {
      continue;
    }

    $titles = ['all' => 'all'];
    $parent_pr = souriau_common_get_main_product_range($product);
    if ($parent_pr) {
      $titles += _souriau_common_get_category_field_from_product_range($parent_pr);
    }

    foreach ($titles as $title) {
      $products_array[$title][$product->nid] = $product;
    }
  }
  return $products_array;
}

/**
 * Helper function for create description block of Part Number node.
 */
function _souriau_preprocess_create_description_block_html($sku, $node_wrapper, &$_data, &$_html) {
  global $language;
  // Title.
  $_html['title'] = $node_wrapper->title->value();

  // Label New.
  $_data['sticky'] = $node_wrapper->field_sticky->value() ? TRUE : FALSE;

  // Part Number.
  $_html['pn'] = $sku->sku;

  // Build image data.
  $images = field_get_items('commerce_product', $sku, 'field_sku_images');
  $image = isset($images[0]) ? array_shift($images) : [];
  $_data['image'] = '';
  $_data['image'] = [
    '#type' => 'figure_pic',
    '#image' => $image,
    '#style' => 'part_number_image',
  ];

  // 3d model link.
  $model = field_get_items('commerce_product', $sku, 'field_sku_3d_model');
  $_html['model'] = '';
  if (!empty($model) && !variable_get('pn_page_dc_layout', FALSE)) {
    $model = array_shift($model);
    $model = isset($model['file']) ? $model['file'] : file_load($model['fid']);
    $icon = ['#type' => 'svg_icon', '#icon' => 'ico-download'];
    $_html['model'] = l(drupal_render($icon) . t('DOWNLOAD 3D PICTURE', [], ['context' => SOURIAU_COMMON_T_OTHER]), file_create_url($model->uri), [
      'html'  => TRUE,
      'attributes' => [
        'class' => ['download-link', 'gtm_element'],
        'target' => '_blank',
        'data-gtm-category' => 'Download',
        'data-gtm-action' => '3Dpicture',
        'data-gtm-label' => $sku->sku,
      ]
    ]);
  }

  // Stock information.
  $b_link = _souriau_preprocess_create_description_block_stock_information($sku, $node_wrapper, $_data, $_html);
  $_html['where_to_buy'] = !empty($_data['legacy']) ? '<div class="w-link">' . $b_link . '</div>' : $b_link;

  // Brand. Product Series.
  $brand = field_get_items('commerce_product', $sku, 'field_sku_company');
  $brand = field_view_value('commerce_product', $sku, 'field_sku_company', $brand[0]);
  $brand = drupal_render($brand);
  $products_series = !empty($brand) ? [$brand] : [];
  $ranges = $node_wrapper->field_parent_product_range->value();
  // Get series only from main product range.
  if (!empty($ranges) && isset($ranges[0]->field_product_series)) {
    $range_wrapper = entity_metadata_wrapper('node', $ranges[0])->language($language->language);
    $product_series = $range_wrapper->field_product_series->value();
    // Get series name.
    $display_product_series_title = souriau_common_get_product_series_name($product_series);
    if (!empty($display_product_series_title)) {
      $products_series[] = '<span>' . $display_product_series_title . '</span>';
    }
  }
  $_html['series'] = !empty($products_series) ? implode(' / ', $products_series) : FALSE;

  // Links: add to project, order a free sample.
  $_html['b_links'] = '';
  $_html['b_links'] .= _souriau_compare_link($node_wrapper);
  $_html['b_links'] .= _souriau_add_to_project_link($node_wrapper);
  $_html['b_links'] .= _souriau_request_free_sample_link($sku, $node_wrapper);
}

/**
 * Helper function for get stock information.
 */
function _souriau_preprocess_create_description_block_stock_information($sku, $node_wrapper, &$_data, &$_html) {
  ctools_include('modal');
  ctools_include('ajax');
  // Get distributor managing system.
  $souriau_setting = variable_get('souriau_distributor_settings', []);
  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $ecommerce_stock_system = isset($site_commerce_settings['stock']['system']) ? $site_commerce_settings['stock']['system'] : 'worldwide_stock';
  // 0 - worldwide.
  // 1 - tipity.
  $distributor_system = isset($souriau_setting['manage']['setting']) ? $souriau_setting['manage']['setting'] : FALSE;
  $_data['d_system'] = $distributor_system;

  // Where to buy button.
  $w_btn_text = t('WHERE TO BUY', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  $w_btn_class = 'btn orange-btn-hover';

  // Discontinued product value.
  $_data['legacy'] = $node_wrapper->field_legacy_data->value();

  // Get available product at stock.
  module_load_include('inc', 'souriau_common', 'souriau_common.rdb');
  $_data['stock'] = souriau_common_rdb_get_part_number_stock_status($sku->sku, TRUE, 'mouser_stock' == $ecommerce_stock_system);

  // IN STOCK or DISCONTINUED (default: out of stock).
  $_html['available'] = '';
  $_html['stock_label'] = t('Sample unavailable', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  if ($_data['stock'] && !$_data['legacy'] && souriau_common_sample_is_availible_in_domain($sku)) {
    $_html['available'] = 'available';
    $_html['stock_label'] = t('Sample available', [], ['context' => SOURIAU_COMMON_T_OTHER]);
    ctools_include('modal');
    ctools_include('ajax');
    // Return were-to-buy worldwide Button.
    return ctools_modal_text_button($w_btn_text, 'souriau/ajax/distributors/' . $sku->sku . '/nojs', '', 'ctools-modal-souriau-modal-style ' . $w_btn_class);
  }
  elseif ($_data['legacy']) {
    $_html['stock_label'] = t('DISCONTINUED PRODUCT', [], ['context' => SOURIAU_COMMON_T_OTHER]);

    // Get replacement product.
    $replacement_sku = $node_wrapper->field_pn_replacement->value();
    if (empty($replacement_sku)) {
      // Remove button.
      return FALSE;
    }
    $replacement_product = souriau_common_load_part_number_by_sku($replacement_sku->sku);

    // Replace button with link replacement product.
    $w_btn_class = ['link-more', 'gtm_element'];
    $w_btn_text = t('VIEW REPLACEMENT PRODUCT', [], ['context' => SOURIAU_COMMON_T_OTHER]);
    $w_btn_href = url('/node/' . $replacement_product->nid);
    $w_btn_icon = '<span class="glyphicon glyphicon-menu-right" aria-hidden="true"></span>';
    // Return replaced link.
    return l($w_btn_icon . $w_btn_text, $w_btn_href, [
      'html' => TRUE,
      'attributes' => [
        'class' => $w_btn_class,
      ],
      'data-gtm-category' => 'Button',
      'data-gtm-action' => 'Remplacement-product',
      'data-gtm-label' => $replacement_sku->sku,
      'external' => TRUE,
    ]);
  }
  // Any way return button, to display default distributors.
  return ctools_modal_text_button($w_btn_text, 'souriau/ajax/distributors/' . $sku->sku . '/nojs', '', 'ctools-modal-souriau-modal-style ' . $w_btn_class);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__product__part_number(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['pn'] = '';
  $_html['series'] = '';
  $sku = $node_wrapper->field_sku_products->raw();
  if (empty($sku)) {
    return;
  }
  $sku = $node_wrapper->field_sku_products->value();
  _souriau_preprocess_build_part_number_preview_block($node_wrapper, $sku, $_html);
}

/**
 * Helper function for build top/complementary product range links.
 */
function _souriau_preprocess_build_part_number_preview_block($entity, $sku, &$_html, $souriau_setting = []) {
  global $language;
  // Image.
  $images = field_get_items('commerce_product', $sku, 'field_sku_images');
  $image = !empty($images) ? array_shift($images) : [];
  $image = [
    '#souriau_settings' => $souriau_setting,
    '#type' => 'figure_pic',
    '#image' => $image,
    '#style' => 'complementary_product_thumb',
  ];
  if (!empty($souriau_setting['create_link'])) {
    $image['#href'] = 'node/' . $entity->nid->raw();
  }
  $_html['image'] = drupal_render($image);

  // Title.
  $_html['title'] = $entity->title->value();

  // Part Number.
  $_html['pn'] = $sku->sku;

  // Product series.
  $ranges = $entity->field_parent_product_range->value();
  $_html['series'] = '';
  if (empty($ranges)) {
    return;
  }
  if (isset($ranges[0]->field_product_series)) {
    $range_wrapper = entity_metadata_wrapper('node', $ranges[0])->language($language->language);
    $product_series = $range_wrapper->field_product_series->value();
    $_html['series'] = souriau_common_get_product_series_name($product_series);
  }
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__capability__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $spacer = '<!--fix inline-block
-->';
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // Our Solution.
  $_html['solution'] = souriau_common_get_field_value('node', $node, 'field_our_solution');

  // Paragraph.
  $paragraphs = $node_wrapper->field_paragraphs->value();
  $_html['paragraphs'] = '';
  foreach ($paragraphs as $paragraph) {
    $_html['paragraphs'] .= theme('paragraph_two_col_title_description', ['entity' => $paragraph]);
  };

  // Discover our products.
  $_html['top_products'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_product_range', 'application_page', [], $spacer);

  // Downloads.
  $files = $node_wrapper->field_downloads->value();
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files);

  // News.
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__tool__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  // Title  & Image.
  $_data['title'] = $node_wrapper->title_field->value();
  try {
    $_data['image'] = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->value(),
    ];
  }
  catch (Exception $e) {
    watchdog_exception('tool_full_image', $e);
  }
  $_data['image'] = drupal_render($_html['image']);

  // Description.
  $_data['description'] = souriau_common_get_field_value('node', $node, 'field_description');

  // Legal info.
  $_data['legal_information'] = souriau_common_get_field_value('node', $node, 'field_legal_information');

  // Form.
  if (module_exists('souriau_tools')) {
    module_load_include('inc', 'souriau_tools', 'souriau_tools.forms');
    // Tool code.
    $code = $node_wrapper->field_tool_code->value();
    $variables['form'] = souriau_tools_integration_form_caller($node, $code);
  }
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__product__tool_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['image'] = '';
  $_html['title'] = '';
  $_html['pn'] = '';
  $_html['series'] = '';
  $sku = $node_wrapper->field_sku_products->raw();
  if (empty($sku)) {
    return;
  }
  $sku = $node_wrapper->field_sku_products->value();
  _souriau_preprocess_build_part_number_preview_block($node_wrapper, $sku, $_html, ['create_link' => TRUE]);

  // Where to buy.
  ctools_include('modal');
  ctools_include('ajax');
  $icon = ['#type' => 'svg_icon', '#icon' => 'ico-location'];
  $w_btn_text = t('WHERE TO BUY', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  $where_to_buy_url = 'souriau/ajax/distributors/' . $sku->sku . '/nojs';
  $where_to_buy = ctools_modal_text_button(
    drupal_render($icon) . $w_btn_text,
    $where_to_buy_url,
    '',
    'where-to-buy-link ctools-modal-souriau-modal-style ctools-use-modal'
  );
  // Add to project link.
  $add_to_project = _souriau_add_to_project_link($node_wrapper);
  // Free sample.
  $free_sample = _souriau_request_free_sample_link($sku, $node_wrapper);

  $_html['b_links'] = $add_to_project . $free_sample . $where_to_buy;
}

/**
 * Link Add to project.
 *
 * @param object $node_wrapper
 *   Product entity metadata wrapper.
 *
 * @return string
 *   Link.
 */
function _souriau_add_to_project_link($node_wrapper) {
  // Add to project.
  $icon = ['#type' => 'svg_icon', '#icon' => 'ico-project'];
  $add_to_project_url = url(format_string(
    'souriau/ajax/projects/add/@nid/nojs', ['@nid' => $node_wrapper->nid->value()]
  ));
  return (user_is_logged_in()) ? l(
    drupal_render($icon) . '<span class="text">' . t('ADD TO PROJECT', [], ['context' => SOURIAU_COMMON_T_OTHER]), $add_to_project_url, [
      'html' => TRUE,
      'attributes' => [
        'class' => [
          'link',
          'add-to-project-link',
          'ctools-use-modal',
          'ctools-modal-souriau-modal-style',
          'gtm_element',
        ],
        'data-gtm-category' => 'Button',
        'data-gtm-action' => 'Add-to-project',
        'data-gtm-label' => $node_wrapper->getIdentifier(),
      ],
      'external' => TRUE,
    ]
  ) . '</span>' : '';
}

/**
 * Link Add to project.
 *
 * @param object $node_wrapper
 *   Product entity metadata wrapper.
 *
 * @return string
 *   Link.
 */
function _souriau_compare_link($node_wrapper) {
  $sku = $node_wrapper->field_sku_products->value();
  $icon_compare = ['#type' => 'svg_icon', '#icon' => 'ico-compare'];
  $icon_check = ['#type' => 'svg_icon', '#icon' => 'ico-check'];
  $link_options = [
    'html' => TRUE,
    'fragment' => ' ',
    'attributes' => [
      'data-part-number' => $node_wrapper->getIdentifier(),
      'class' => [
        'link',
        'compare-link',
        'gtm_element',
      ],
      'data-gtm-category' => 'Button',
      'data-gtm-action' => 'Compare',
      'data-gtm-label' => $sku->sku,
    ],
    'external' => TRUE,
  ];
  $part_numbers = souriau_compare_load_part_numbers();
  if (in_array($node_wrapper->getIdentifier(), $part_numbers)) {
    $link_options['attributes']['class'][] = 'active';
  }

  $compare_link = l(
    drupal_render($icon_compare) . drupal_render($icon_check) . '<span class="text">' . t('COMPARE', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</span>', '', $link_options
  );

  return '<div class="b-compare-btn hidden-xs">' . $compare_link . '</div>';
}
/**
 * Link Order a Free Sample .
 *
 * @param object $sku
 *   SKU.
 * @param object $node_wrapper
 *   Product entity metadata wrapper.
 *
 * @return string
 *   Link for order free sample.
 */
function _souriau_request_free_sample_link($sku, $node_wrapper) {
  if (souriau_common_sample_checkout_status() && !$node_wrapper->field_legacy_data->value() && souriau_common_sample_is_availible_in_domain($sku)) {
    $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
    $ecommerce_stock_system = isset($site_commerce_settings['stock']['system']) ? $site_commerce_settings['stock']['system'] : 'worldwide_stock';

    // Check in local mouser DB if the sample is available.
    if ('mouser_stock' == $ecommerce_stock_system && empty(souriau_eco_erp_get_samples_stock_from_external_db($sku->sku, TRUE))) {
      return '';
    }

    $icon = ['#type' => 'svg_icon', '#icon' => 'ico-cart'];
    $sku = $node_wrapper->field_sku_products->value();
    return l(drupal_render($icon) . '<span class="text">' . t('ORDER A FREE SAMPLE', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'souriau/ajax/order/' . $sku->product_id . '/nojs/sample/add', [
      'html' => TRUE,
      'attributes' => [
        'class' => ['link', 'add-to-cart-link', 'use-ajax', 'gtm_element'],
        'data-gtm-category' => 'Button',
        'data-gtm-action' => 'Order-free-sample',
        'data-gtm-label' => $sku->sku,
      ],
    ]) . '</span>';
  }
  return '';
}

/**
 * Link Where to buy.
 *
 * @param object $sku
 *   SKU.
 *
 * @return string
 *   Link for where to buy.
 */
function _souriau_request_where_to_buy_link($sku, $btn_text = '') {
  if (empty($btn_text)) {
    $btn_text = t('WHERE TO BUY', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  ctools_include('modal');
  ctools_include('ajax');
  $icon = ['#type' => 'svg_icon', '#icon' => 'ico-location'];
  $where_to_buy_url = 'souriau/ajax/distributors/' . $sku->sku . '/nojs';
  return ctools_modal_text_button(
    drupal_render($icon) . '<span data-gtm-label="' . $sku->sku . '" data-gtm-action="where-to-buy" data-gtm-category="Button" class="text gtm_element">' . $btn_text . '</span>',
    $where_to_buy_url,
    '',
    'link where-to-buy-link ctools-modal-souriau-modal-style ctools-use-modal'
  );
}

/**
 * Preprocess for news_landing view mode full.
 */
function souriau_preprocess_node__news_landing__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['title'] = $node_wrapper->title_field->value();
  $_html['description'] = $node_wrapper->field_description->value();

  $tags = empty($_GET['selected']) ? 'all' : $_GET['selected'];

  $_html['most_recent'] = views_embed_view('souriau_news', 'news_most_recent', $tags);
  $_html['news_list'] = views_embed_view('souriau_news', 'news_list', $tags);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__NODE_VIEW().
 */
function souriau_preprocess_node__news__news_landing_pane_teaser(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = &$variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['image'] = '';
  $images = field_get_items('node', $node, 'field_image');
  $image = isset($images[0]) ? array_shift($images) : [];
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $image,
      '#style' => 'news_preview_image',
    ];
  }
  catch (Exception $e) {
    watchdog_exception('news_landing_image', $e);
  }
  $_html['image'] = drupal_render($image);

  $_html['tags'] = [];
  foreach ($node_wrapper->field_tags->value() as $field_tag) {
    $_html['tags'][] = $field_tag->name;
  }

  $body = souriau_common_get_field_value('node', $node, 'field_body');
  $body = strip_tags($body, '<p><h4><h3><h2><h1><b><strong><ol><ul><li><em><u><sub><sup>');
  $body = preg_replace('/\s+/', ' ', str_replace('&nbsp;', ' ', $body));
  $truncated_body = truncate_utf8($body, 200, TRUE, TRUE);
  /* using php tidy library for auto closing html tags. */
  $tidy = new Tidy();
  $_html['description'] = $tidy->repairString($truncated_body, [
    'output-xml' => TRUE,
    'input-xml' => TRUE
  ], 'utf8');
  $_html['title'] = $node_wrapper->title_field->value();
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__resource__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $spacer = '<!--fix inline-block
-->';

  $_html['resource'] = _souriau_get_resource_details($node_wrapper, $node);

  $i = 1;
  $_html['related_resources'] = [];
  foreach ($node_wrapper->field_related_resource->value() as $related_resource) {
    $node_wrapper_related = entity_metadata_wrapper('node', $related_resource)->language($language->language);
    $_html['related_resources'][] = _souriau_get_resource_details($node_wrapper_related, $related_resource);
    if ($i++ == 3) {
      break;
    }
  }

  // Registration form.
  $_html['registration_form'] = NULL;
  $registration_form = $node_wrapper->field_registration_webform->value();
  $webform_settings = (isset($registration_form->nid)) ? _webform_scheduler_webform_scheduler_settings($registration_form->nid) : 0;

  $date_status = (($webform_settings['begin'] == 0 || REQUEST_TIME >= $webform_settings['begin']) && ($webform_settings['end'] == 0 || REQUEST_TIME <= $webform_settings['end']));
  if (!empty($registration_form) && $date_status) {
    $node = node_load($registration_form->nid);
    $webform = drupal_get_form('webform_client_form_' . $registration_form->nid, $node);
    $webform['actions']['submit']['#souriau_settings'] = [
      'hover_color' => 'orange',
    ];

    $webform['actions']['#attributes']['class'] = ['text-center', 'form-actions'];
    $webform['actions']['submit']['#value'] = t('SEND MY MESSAGE', [], ['context' => SOURIAU_COMMON_T_OTHER]);

    $_html['registration_form'] = $webform;
  }

  // Discover our products.
  $_html['top_products'] = _suriau_preprocess_node__render_preview_block(NULL, NULL, 'application_page', array_slice($node_wrapper->field_product_range->value(), 0, 4), $spacer);
}

/**
 * Helper function to fetch resource details for rendering.
 *
 * @param object $node_wrapper
 *   Node wrapper object.
 *
 * @return array
 *   Resource details.
 */
function _souriau_get_resource_details($node_wrapper, $node) {
  $resource = [];
  $resource['nid'] = $node_wrapper->getIdentifier();
  $resource['title'] = $node_wrapper->title_field->value();
  $resource['video'] = $node_wrapper->field_video->value();
  $resource['is_private'] = $node_wrapper->field_resource_private->value();
  $resource['body'] = souriau_common_get_field_value('node', $node, 'field_description');
  $resource_type = $node_wrapper->field_resource_type->value();
  $resource['resource_type'] = !empty($resource_type) ? $resource_type->name : NULL;
  $resource['date'] = format_date($node_wrapper->created->value(), 'custom', 'm/d/Y');

  $resource['tags'] = [];
  foreach ($node_wrapper->field_resource_category->value() as $field_tag) {
    $resource['tags'][] = $field_tag->name;
  }

  $resource['image'] = '';
  $image = field_get_items('node', $node, 'field_resource_image');
  $image = isset($image[0]) ? array_shift($image) : [];
  $image = [
    '#type' => 'figure_pic',
    '#image' => $image,
  ];
  $resource['image'] = drupal_render($image);

  return $resource;
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__product__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $sku = $node_wrapper->field_sku_products->raw();
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['pn'] = '';
  $_html['series'] = '';
  $_html['brand'] = '';
  $_html['links'] = '';
  $_html['divider'] = '';
  $_html['comporator'] = '';
  if (empty($sku)) {
    return;
  }
  $sku = $node_wrapper->field_sku_products->value();
  _souriau_preprocess_build_part_number_preview_block($node_wrapper, $sku, $_html, ['image_type' => 'search_result']);
  $_html['links'] .= _souriau_compare_link($node_wrapper);
  $_html['links'] .= _souriau_add_to_project_link($node_wrapper);
  $_html['links'] .= _souriau_request_free_sample_link($sku, $node_wrapper);
  $_html['links'] .= _souriau_request_where_to_buy_link($sku);

  $brand = field_get_items('commerce_product', $sku, 'field_sku_company');
  $brand = field_view_value('commerce_product', $sku, 'field_sku_company', $brand[0]);
  $_html['brand'] = drupal_render($brand);
  if (!empty($_html['brand']) && !empty($_html['series'])) {
    $_html['divider'] = ' / ';
  }

  $comparator_data = isset($_COOKIE['Drupal_visitor_part_numbers']) ? explode(',', $_COOKIE['Drupal_visitor_part_numbers']) : [];
  $comparator_data = array_filter($comparator_data);
  if (in_array($node->nid, $comparator_data)) {
    $_html['comporator'] = 'active';
  }

  $site_commerce_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $ecommerce_stock_system = isset($site_commerce_settings['stock']['system']) ? $site_commerce_settings['stock']['system'] : 'worldwide_stock';

  $_data['legacy'] = $node_wrapper->field_legacy_data->value();

  // Get available product at stock.
  module_load_include('inc', 'souriau_common', 'souriau_common.rdb');
  $_data['stock'] = souriau_common_rdb_get_part_number_stock_status($sku->sku, TRUE, 'mouser_stock' == $ecommerce_stock_system);

  $_html['available'] = '';
  if (_souriau_request_free_sample_link($sku, $node_wrapper) != '') {
    $_html['stock_label'] = t('Sample unavailable', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  if ($_data['stock'] && !$_data['legacy'] && souriau_common_sample_is_availible_in_domain($sku)) {
    $_html['available'] = 'available';
    $_html['stock_label'] = t('Sample available', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrange__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrangehub__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__application__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 *
 * @deprecated
 * Was updated search index. This Content not indexed anymore
 */
function souriau_preprocess_node__applicationdomain__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 *
 * @deprecated
 * Was updated search index. This Content not indexed anymore
 */
function souriau_preprocess_node__category__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 *
 * @deprecated
 * Was updated search index. This Content not indexed anymore
 */
function souriau_preprocess_node__subcategory__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__news__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__capability__search_result(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $_html['image'] = '';
  $_html['title'] = '';
  $_html['content_type'] = '';
  $_html['body'] = '';
  _souriau_preprocess_build_regular_search_result($node_wrapper, $_html);
}

/**
 * Regular search result data getter.
 *
 * Used for all content types except product.
 *
 * @param object $node_wrapper
 *   Node wrapper.
 * @param array $_html
 *   Target data storage.
 */
function _souriau_preprocess_build_regular_search_result($node_wrapper, &$_html) {
  $types = node_type_get_types();
  $_html['content_type'] = $types[$node_wrapper->getBundle()]->name;

  // Title.
  $_html['title'] = $node_wrapper->title_field->value();
  $_html['body'] = truncate_utf8($node_wrapper->body->value(), 200, TRUE, TRUE);
  $image_allowed_types = [
    'product',
    'productrange',
    'productrangehub',
  ];

  if (!in_array($node_wrapper->getBundle(), $image_allowed_types)) {
    $_html['image'] = '<figure class="pic"></figure>';
    return;
  }

  // Image.
  $images = field_get_items('node', $node_wrapper->raw(), 'field_image');
  $image = isset($images[0]) ? array_shift($images) : [];
  $image = [
    '#souriau_settings' => ['image_type' => 'search_result'],
    '#type' => 'figure_pic',
    '#image' => $image,
    '#style' => 'search_page_preview',
    '#href' => 'node/' . $node_wrapper->getIdentifier(),
  ];
  $_html['image'] = drupal_render($image);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__product__search_autocomplete(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $sku = $node_wrapper->field_sku_products->raw();
  if (empty($sku)) {
    return;
  }
  $sku = $node_wrapper->field_sku_products->value();
  $_html['sku'] = $sku->sku;
  $_html['title'] = $node_wrapper->title->value();

  // Brand. Product Series.
  $brand = field_get_items('commerce_product', $sku, 'field_sku_company');
  $brand = field_view_value('commerce_product', $sku, 'field_sku_company', $brand[0]);
  $brand = drupal_render($brand);
  $products_series = !empty($brand) ? [$brand] : [];
  $ranges = $node_wrapper->field_parent_product_range->value();
  // Get series only from main product range.
  if (!empty($ranges) && isset($ranges[0]->field_product_series)) {
    $range_wrapper = entity_metadata_wrapper('node', $ranges[0])->language($language->language);
    $product_series = $range_wrapper->field_product_series->value();
    $product_series_title = souriau_common_get_product_series_name($product_series);
    if (!empty($product_series_title)) {
      $products_series[] = '<span>' . $product_series_title . '</span>';
    }
  }
  $_html['series'] = !empty($products_series) ? implode(' / ', $products_series) : FALSE;
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__news__search_autocomplete(&$variables) {
  $node = $variables['node'];
  $variables['_html'] = _souriau_preprocess_node_search_autocomplete($node);

}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__application__search_autocomplete(&$variables) {
  $node = $variables['node'];
  $variables['_html'] = _souriau_preprocess_node_search_autocomplete($node);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__capability__search_autocomplete(&$variables) {
  $node = $variables['node'];
  $variables['_html'] = _souriau_preprocess_node_search_autocomplete($node);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__category__search_autocomplete(&$variables) {
  $node = $variables['node'];
  $variables['_html'] = _souriau_preprocess_node_search_autocomplete($node);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__subcategory__search_autocomplete(&$variables) {
  $node = $variables['node'];
  $variables['_html'] = _souriau_preprocess_node_search_autocomplete($node);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__productrange__search_autocomplete(&$variables) {
  $node = $variables['node'];
  $variables['_html'] = _souriau_preprocess_node_search_autocomplete($node);
}

/**
 * Implements hook_preprocess_node__TYPE__VIEW_MODE.
 */
function souriau_preprocess_node__productrangehub__search_autocomplete(&$variables) {
  $node = $variables['node'];
  $variables['_html'] = _souriau_preprocess_node_search_autocomplete($node);
}

/**
 * Helper function for search_autocomplete view mode.
 */
function _souriau_preprocess_node_search_autocomplete($node) {
  global $language;
  $html = [];
  $wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $html['title'] = $wrapper->title_field->value();
  if (isset($node->field_product_series)) {
    $series = $wrapper->field_product_series->value();
    $html['series'] = souriau_common_get_product_series_name($series);
  }

  return $html;
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrangehub__category_page(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrangehub__subcategory_page(&$variables) {
  souriau_preprocess_node__productrangehub__category_page($variables);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrangehub__product_landing_page(&$variables) {
  souriau_preprocess_node__productrangehub__category_page($variables);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE().
 */
function souriau_preprocess_node__homepage__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $spacer = '<!--fix inline-block
-->';
  // Top Products.
  $_html['top_products'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_products', 'homepage', [], $spacer);

  // Slider.
  $slides = $node_wrapper->field_slides->value();
  $_html['slider'] = '';
  foreach ($slides as $slide) {
    $_html['slider'] .= theme('homepage_slider', ['entity' => $slide]);
  };

  // Promo messages.
  $messages = $node_wrapper->field_promotion_messages->value();
  $links = [];
  foreach ($messages as $message) {
    $links[] = theme('homepage_promotion_messages', ['entity' => $message]);
  };
  $_html['messages'] = theme('item_list', array(
    'items' => $links,
    'title' => NULL,
    'type' => 'ul',
    'attributes' => [],
  ));

  // Beginner guide banner.
  $_html['banner_title'] = $node_wrapper->field_banner_title->value();
  $_html['banner_description'] = $node_wrapper->field_banner_description->value();
  $cta_title = $node_wrapper->field_cta_title->value();
  if (empty($cta_title)) {
    $cta_title = t('GET STARTED', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  $_html['guide_link'] = l($cta_title, 'get-started', ['attributes' => ['class' => 'view-more']]);

  // News.
  $news = $node_wrapper->field_news->value();
  if (empty($news)) {
    // Fetch latest published news.
    $news = views_get_view_result('souriau_query_get_latest_news');
  }
  $_html['news'] = '';
  foreach ($news as $item) {
    if (!isset($item->type)) {
      $item = node_load($item->nid);
    }
    $node_view = souriau_common_build_node_view($item, 'homepage');
    $_html['news'] .= drupal_render($node_view);
  };

  // Tools.
  $tools = $node_wrapper->field_promoted_tools->value();
  $_html['tools'] = '';
  foreach ($tools as $tool) {
    $node_view = souriau_common_build_node_view($tool, 'homepage');
    $_html['tools'] .= drupal_render($node_view);
  };

  // Presentation.
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_ect_image->raw(),
      '#attributes' => [
        'title' => $node_wrapper->field_ect_image->file->value()->title,
        'alt' => $node_wrapper->field_ect_image->file->value()->alt,
      ],
    ];
  }
  catch (Exception $e) {
    watchdog_exception('presentation_image', $e);
  }
  $_html['eck_image'] = drupal_render($image);
  $_html['eck_description'] = souriau_common_get_field_value('node', $node, 'field_ect_description');
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrangehub__homepage(&$variables) {
  souriau_preprocess_node__productrangehub__category_page($variables);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__productrange__homepage(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  _souriau_preprocess_build_product_range_links($node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__news__homepage(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $image = field_get_items('node', $node, 'field_image');
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => isset($image[0]) ? $image[0] : '',
      '#style' => 'news_and_events_image',
    ];
  }
  catch (Exception $e) {
    watchdog_exception('news_homepage_image', $e);
  }
  $_html['image'] = drupal_render($image);
  $_html['date'] = format_date($node_wrapper->created->value(), 'custom', 'm/d/Y');;
  $_html['title'] = $node_wrapper->title_field->value();
  $cta_text = $node_wrapper->field_cta_button_text->value();
  if (empty($cta_text)) {
    $cta_text = t('Read more', [], ['context' => SOURIAU_COMMON_T_OTHER]);
  }
  $_html['more'] = l(
    drupal_strtoupper($cta_text),
    'node/' . $node->nid, [
      'attributes' => [
        'class' => ['btn orange-btn-hover', 'gtm_element'],
        'data-gtm-category' => 'Button',
        'data-gtm-action' => 'Event',
        'data-gtm-label' => $_html['title'],
      ],
    ]
  );
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__tool__homepage(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  souriau_preprocess_node_tool_preview_box($node, $node_wrapper, $_html);
}

/**
 * Helper function. Get Values for preview of tool.
 */
function souriau_preprocess_node_tool_preview_box($node, $node_wrapper, &$_html) {
  try {
    $image = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->raw(),
      '#style' => 'medium',
    ];
  }
  catch (Exception $e) {
    watchdog_exception('tool_previewbox_image', $e);
  }
  $_html['image'] = drupal_render($image);
  $_html['catchline'] = $node_wrapper->field_catchline->value();
  $title = $node_wrapper->title_field->value();
  $_html['title'] = truncate_utf8($title, 28, FALSE, TRUE, 1);
  $_html['tool_link'] = url('node/' . $node->nid);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__toolkitlanding__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['description'] = souriau_common_get_field_value('node', $node, 'field_description');
  $_html['title'] = $node_wrapper->title_field->value();

  // Tools.
  $tools = $node_wrapper->field_tools->value();
  $_html['tools'] = '';

  if (empty($tools)) {
    return;
  }

  foreach ($tools as $tool) {
    $node_view = souriau_common_build_node_view($tool, 'toolkitlanding');
    $_html['tools'] .= drupal_render($node_view);
  };
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__tool__toolkitlanding(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  souriau_preprocess_node_tool_preview_box($node, $node_wrapper, $_html);
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__genericlanding__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);

  $_html['description'] = souriau_common_get_field_value('node', $node, 'field_description');
  $_html['title'] = $node_wrapper->title_field->value();

  // Tools.
  $_html['links'] = '';
  $links = $node_wrapper->field_generic_link->value();

  if (empty($links)) {
    return;
  }

  // links.
  foreach ($links as $link) {
    $_html['links'] .= theme('generic_links', ['link' => $link]);
  };
}

/**
 * Implements hook_preprocess_node__NODE_TYPE__VIEW_MODE().
 */
function souriau_preprocess_node__cms_page__full(&$variables) {
  global $language;
  $_html = &$variables['_html'];
  $node = $variables['node'];
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
  $spacer = '<!--fix inline-block
-->';

  // Title  & Image.
  $_html['title'] = $node_wrapper->title_field->value();
  try {
    $_html['image'] = [
      '#type' => 'figure_pic',
      '#image' => $node_wrapper->field_image->value(),
      '#alt' => 'banner image',
    ];
  }
  catch (Exception $e) {
    watchdog_exception('cms_page_image', $e);
  }
  $_html['image'] = drupal_render($_html['image']);

  // Paragraph.
  $paragraphs = $node_wrapper->field_paragraphs->value();
  $_html['paragraphs'] = '';
  foreach ($paragraphs as $paragraph) {
    $_html['paragraphs'] .= theme('paragraph_two_col_title_description', ['entity' => $paragraph]);
  };

  // Discover our products.
  $_html['top_products'] = _suriau_preprocess_node__render_preview_block($node_wrapper, 'field_cross_sell_product_range', 'application_page', [], $spacer);

  // Downloads.
  $files = $node_wrapper->field_downloads->value();
  $_html['downloads'] = _souriau_preprocess_node__category__render_downloads($files);

  // News.
  $_html['news'] = '';
  _souriau_preprocess_node__prepare_html_news_block($node_wrapper, $_html);
}
