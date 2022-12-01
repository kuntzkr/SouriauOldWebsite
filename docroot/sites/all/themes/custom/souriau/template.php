<?php

/**
 * @file
 * Souriau theme template.php.
 */

require_once 'preprocess/elements.inc';

/**
 * Implements hook_css_alter().
 */
function souriau_css_alter(&$css) {
  $exclude = array(
    'misc/ui/jquery.ui.autocomplete.css' => FALSE,
    'misc/ui/jquery.ui.menu.css' => FALSE,
    'misc/ui/jquery.ui.core.css' => FALSE,
    'misc/ui/jquery.ui.theme.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}

/**
 * Copy core function, without div wrapper.
 */
function souriau_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];
  $wrapper = isset($variables['wrapper']) ? $variables['wrapper'] : FALSE;
  $output = '';

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array(
          'items' => $children,
          'title' => NULL,
          'type' => $type,
          'attributes' => $attributes,
        ));
      }
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }

  // Special Wrapper for breadcrumbs.
  if ($wrapper && is_array($wrapper)) {
    foreach ($wrapper as $tag => $value) {
      $attributes = !empty($value['attributes']) ? $value['attributes'] : '';
      $output = '<' . $tag . drupal_attributes($attributes) . '>' . $output . '</' . $tag . ">\n";
    }
  }

  return $output;
}

/**
 * Implements theme_preprocess_hook().
 *
 * Preprocess for theme('category_group').
 */
function souriau_preprocess_category_group(&$variables) {
  $_html = [];
  // Process groups.
  $_html['groups'] = '';
  foreach ($variables['groups'] as $group_name => $group) {
    $active = empty($group['#active']) ? '' : $group['#active'];
    unset($group['#active']);
    $_html['groups'] .= '<div id="' . $group_name . '" class="tab-pane fade ' . $active . '"><div class="container"><section class="b-sub-categories"><div class="items">';
    foreach ($group as $item) {
      $node_view = souriau_common_build_node_view($item['#node'], $item['#node_view']);
      $_html['groups'] .= drupal_render($node_view);
    }
    $_html['groups'] .= '</div></section></div></div>';
  }

  $variables['_html'] = $_html;
}

/**
 * Implements theme_preprocess_hook().
 *
 * Preprocess for theme('paragraph_two_col_title_description').
 */
function souriau_preprocess_paragraph_two_col_title_description(&$variables) {
  $_html = [];
  $entity = $variables['entity'];
  $title = field_get_items('paragraphs_item', $entity, 'field_paragraph_title');
  $title = field_view_value('paragraphs_item', $entity, 'field_paragraph_description', $title[0]);
  $description = field_get_items('paragraphs_item', $entity, 'field_paragraph_description');
  $description = field_view_value('paragraphs_item', $entity, 'field_paragraph_description', $description[0]);

  $_html['title'] = drupal_render($title);
  $_html['anchor'] = str_replace(' ', '-', $_html['title']);
  $_html['description'] = drupal_render($description);

  $variables['_html'] = $_html;
}

/**
 * Implements theme_preprocess_hook().
 *
 * Preprocess for theme('paragraph_application_examples').
 */
function souriau_preprocess_paragraph_application_examples(&$variables) {
  $_html = [];
  $entity = $variables['entity'];
  $image = field_get_items('paragraphs_item', $entity, 'field_image');
  $image = isset($image[0]) ? array_shift($image) : [];
  $description = field_get_items('paragraphs_item', $entity, 'field_paragraph_description');
  $description = field_view_value('paragraphs_item', $entity, 'field_paragraph_description', $description[0]);
  $image = [
    '#type' => 'figure_pic',
    '#image' => $image,
    '#style' => 'medium',
    '#attributes' => [],
  ];
  $_html['image'] = drupal_render($image);
  $_html['description'] = drupal_render($description);
  $variables['_html'] = $_html;
}

/**
 * Implements hook_preprocess_views_view_fields().
 */
function souriau_preprocess_views_view_fields(&$variables) {
  switch ($variables['view']->name) {
    case 'userzone_my_projects':
      $_html = &$variables['_html'];

      $souriau_settings = variable_get('souriau_common_settings');
      $fid = (isset($souriau_settings['user_zone'])) ? $souriau_settings['user_zone']['project_default_image'] : NULL;

      if ($variables['fields']['nid']->content) {
        $node = node_load($variables['fields']['nid']->content);

        $product = commerce_product_load($node->field_sku_products['und'][0]['product_id']);

        if ($product->field_sku_images) {
          $fid = $product->field_sku_images['und'][0]['fid'];
        }
      }

      // Process Image.
      $image = [
        '#type' => 'figure_pic',
        '#image' => $fid,
        '#attributes' => [],
      ];
      $_html['image'] = drupal_render($image);
      break;

    case 'souriau_query_training_center':
      $_html = &$variables['_html'];
      $image = [
        '#type' => 'figure_pic',
        '#image' => $variables['fields']['fid']->content,
        '#attributes' => [],
      ];
      $_html['image'] = drupal_render($image);
      break;

    case 'souriau_query_postcards':
      $_html = &$variables['_html'];
      $image = [
        '#type' => 'figure_pic',
        '#image' => $variables['fields']['fid']->content,
        '#attributes' => ['class' => 'tint'],
      ];
      $_html['image'] = drupal_render($image);
      $_html['body'] = $variables['fields']['field_popup_text']->content;
      $nid = $variables['fields']['nid']->content;
      $_html['share_url'] = url('node/' . $nid, ['absolute' => TRUE]);
      break;

    default:
      break;
  }
}

/**
 * Implements hook_preprocess_views_view_unformatted().
 */
function souriau_preprocess_views_view_unformatted(&$variables) {
  if ($variables['view']->name == 'souriau_query_get_popular_faq') {
    $_html = &$variables['_html'];
    $breadcrumbs = [
      souriau_common_microdata_link(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'),
      souriau_common_microdata_tag(t('FAQ', [], ['context' => SOURIAU_COMMON_T_OTHER]))
    ];

    $_html['breadcrumbs'] = souriau_common_breadcrumbs(['breadcrumb' => $breadcrumbs]);
  }
}

/**
 * Implements hook_preprocess_views_view().
 */
function souriau_preprocess_views_view(&$variables) {
  $_html = &$variables['_html'];

  $view = $variables['view'];
  $view_name = $view->name;
  $view_display_id = $view->current_display;

  if ($view_name == 'distributors') {
    $breadcrumbs = [
      souriau_common_microdata_link(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'),
      souriau_common_microdata_tag(t('OUR DISTRIBUTORS', [], ['context' => SOURIAU_COMMON_T_OTHER]))
    ];

    $_html['breadcrumbs'] = souriau_common_breadcrumbs(['breadcrumb' => $breadcrumbs]);
    // Modify empty message.
    $souraiu_variables = variable_get('souriau_common_settings');
    $_html['empty_distributors'] = !empty($souraiu_variables['contact']['where_to_buy']['no_result_text']['value']) ?
    $souraiu_variables['contact']['where_to_buy']['no_result_text']['value'] : '';
    $_html['souriau_distributors_google_map_link'] = variable_get('souriau_distributors_google_map_link', '');

    /* @var $pager views_plugin_pager
     */
    $pager = $view->query->pager;

    $items_per_page = $pager->get_items_per_page();
    $total_items = $pager->get_total_items();
    $total_pages = ceil($total_items / $items_per_page);
    souriau_site_seo_generate_html_head_rel_links($total_pages, 1);
  }

  if ($view_name == 'souriau_news' && $view_display_id == 'news_list') {
    /* @var $pager views_plugin_pager
     */
    $pager = $view->query->pager;

    $items_per_page = $pager->get_items_per_page();
    $total_items = $pager->get_total_items();
    $total_pages = ceil($total_items / $items_per_page);
    souriau_site_seo_generate_html_head_rel_links($total_pages);

    $_html['is_hidden'] = $view->query->offset >= $view->total_rows;
    $_html['current_page'] = $pager->get_current_page();
    $_html['load_more_url'] = url('souriau/ajax/landing-news/load-more');
    $_html['next_page_link'] = souriau_site_seo_generate_next_page_link($total_pages);
  }

  if ($view_name == 'souriau_query_training_center' && $view_display_id == 'training_center_resources_full') {
    /* @var $pager views_plugin_pager
     */
    $pager = $view->query->pager;

    $items_per_page = $pager->get_items_per_page();
    $total_items = $pager->get_total_items();
    $total_pages = ceil($total_items / $items_per_page);
    souriau_site_seo_generate_html_head_rel_links($total_pages, 1);
  }
}

/**
 * Implements theme_preprocess_hook().
 */
function souriau_preprocess_item_list(&$variables) {
  if (isset($variables['attributes']['class']) && in_array('pager', $variables['attributes']['class'])) {
    $variables['wrapper'] = [
      'div' => [
        'attributes' => [
          'class' => ['pagination', 'text-center'],
        ],
      ],
    ];
  }
}

/**
 * Implements theme_preprocess_hook().
 *
 * Preprocess for theme('header_menu_level_2').
 */
function souriau_preprocess_header_menu_level_2(&$variables) {
  $links = $variables['links'];
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];
  $link = $variables['parent'];
  $_data['block_id'] = isset($link['attributes']['aria-controls']) ? $link['attributes']['aria-controls'] : '';
  $_data['icon'] = ['#type' => 'svg_icon', '#icon' => 'ico-breadcrumb-arrow-white'];
  $_html['parent_title'] = $link['title'];
  $count_colums = count($links) < 7 ? ceil(count($links) / 3) : 3;
  $item_per_colum = count($links) > 9 ? ceil(count($links) / 3) : 3;
  $_html['links'] = '';
  for ($c = 1; $c <= $count_colums; $c++) {
    $column = [];
    for ($i = 1; $i <= $item_per_colum; $i++) {
      $column[] = array_shift($links);
    }
    $_html['links'] .= theme('item_list', [
      'items' => $column,
      'title' => NULL,
      'type' => 'ul',
    ]);
  }
}

/**
 * Preprocess main-template.
 */
function souriau_preprocess_mimemail_message(&$variables) {
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $_data['email_images'] = drupal_get_path('theme', 'souriau') . '/html/email/images/';
  $souriau_settings = variable_get('souriau_common_settings');
  $_data['social_links'] = $souriau_settings['information']['social'];
}

/**
 * Preprocess webform_form.
 */
function souriau_preprocess_form(&$variables) {
  $contact_form_id = "webform_client_form_" . SOURIAU_WEBFORM_CONTACTFORM_NID;
  if (isset($variables['form']) && $variables['form']['#form_id'] == $contact_form_id) {
    $variables['theme_hook_suggestions'][] = "form__webform_contact_form";
  }
}

/**
 * Preprocess for views_loadmore pager.
 */
function souriau_preprocess_views_load_more_pager(&$variables) {
  global $pager_page_array, $pager_total;
  $element = $variables['element'];
  $_html = &$variables['_html'];
  $current_page = $pager_page_array[$element] + 1;
  $_html['is_last_page'] = ($current_page == $pager_total[$element]);
  $query = [];
  foreach ($variables['parameters'] as $paramerer => $value) {
    $query[$paramerer] = $value;
  }
  $query['page'] = $pager_page_array[$element] . ',' . $current_page;

  if (isset($query['field_resource_type_tid']) && $query['field_resource_type_tid'] == 'All') {
    unset($query['field_resource_type_tid']);
  }
  $_html['url'] = url('video-tutorials', ['query' => $query]);
  if (current_path() == 'our-distributors') {
    $_html['url'] = url('our-distributors', ['query' => $query]);
  }
  elseif (current_path() == 'where-to-buy') {
    if (isset($query['field_postal_address_country_selective']) && $query['field_postal_address_country_selective'] == 'All') {
      unset($query['field_postal_address_country_selective']);
    }
    if (isset($query['field_postal_address_administrative_area_selective']) && $query['field_postal_address_administrative_area_selective'] == 'All') {
      unset($query['field_postal_address_administrative_area_selective']);
    }
    if (isset($query['field_type_value_selective']) && $query['field_type_value_selective'] == 'All') {
      unset($query['field_type_value_selective']);
    }
    if (isset($query['field_distributor_brand_value_selective']) && $query['field_distributor_brand_value_selective'] == 'All') {
      unset($query['field_distributor_brand_value_selective']);
    }
    $_html['url'] = url('where-to-buy', ['query' => $query]);
  }
  if ($variables['theme_hook_original'] === 'views_load_more_pager__faq_per_product_range__block_1') {
    $query['page'] = $current_page;
    $_html['url'] = url(current_path(), ['query' => $query]);
  }
}

/**
 * Implements theme_preprocess_hook().
 *
 * Preprocess for theme('homepage_slider').
 */
function souriau_preprocess_homepage_slider(&$variables) {
  $_html = &$variables['_html'];
  $entity = $variables['entity'];
  $image = field_get_items('paragraphs_item', $entity, 'field_slide_image');
  $image = [
    '#type' => 'figure_pic',
    '#image' => isset($image[0]) ? $image[0] : '',
    '#attributes' => [],
  ];
  $_html['image'] = drupal_render($image);
  $_html['title'] = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_title');
  $_html['description'] = nl2br(souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_description'));
  $_html['pager_title'] = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_pager_title');
  // Fallback for pager title.
  if (empty($_html['pager_title'])) {
    $_html['pager_title'] = $_html['title'];
  }
  $_html['cta_text'] = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_cta_text');
  $_html['cta_bg'] = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_cta_bg_color');
  $_html['cta_color'] = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_cta_font_color');
  $slide_bg = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_bg_color');
  $slide_color = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_font_color');
  $_html['slide_bg'] = 'background: ' . $slide_bg . ';';
  $_html['slide_color'] = 'color: ' . $slide_color . ';';
  $slide_cta_bg = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_cta_bg_color');
  $slide_cta_color = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_cta_font_color');
  $cta_target = souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_cta_target');
  $_html['link'] = l($_html['cta_text'], souriau_common_get_field_value('paragraphs_item', $entity, 'field_slide_cta_link'), [
    'attributes' => [
      'class' => 'btn orange-btn-hover gtm_element',
      'target' => (!empty($cta_target)) ? '_blank' : '_self',
      'onmouseover' => 'this.setAttribute("style", "color: ' . $slide_cta_bg . '; border-color: ' . $slide_cta_bg . '; background: transparent")',
      'onmouseout' => 'this.setAttribute("style", "background: ' . $slide_cta_bg . '; color: ' . $slide_cta_color . '; border-color: transparent")',
      'style' => 'background: ' . $slide_cta_bg . '; color: ' . $slide_cta_color . ';',
      'data-gtm-category' => 'slider',
      'data-gtm-action' => 'news',
      'data-gtm-label' => $_html['title'],
    ]
  ]);
}

/**
 * Implements theme_preprocess_hook().
 *
 * Preprocess for theme('homepage_promotion_messages').
 */
function souriau_preprocess_homepage_promotion_messages(&$variables) {
  $_html = &$variables['_html'];
  $entity = $variables['entity'];
  $image = field_get_items('paragraphs_item', $entity, 'field_promotion_image');
  $image = [
    '#type' => 'figure_pic',
    '#image' => isset($image[0]) ? $image[0] : '',
    '#attributes' => [],
  ];
  $link = souriau_common_get_field_value('paragraphs_item', $entity, 'field_promotion_link');
  $promotion_message = drupal_strtoupper(souriau_common_get_field_value('paragraphs_item', $entity, 'field_promotion_message'));
  $_html['image'] = (!empty($link)) ? '<a href="' . $link . '">' . drupal_render($image) . '</a>' : drupal_render($image);
  $_html['message'] = (!empty($link)) ? '<a href="' . $link . '">' . $promotion_message . '</a>' : $promotion_message;
}

/**
 * Implements theme_preprocess_hook().
 *
 * Preprocess for theme('homepage_promotion_messages').
 */
function souriau_preprocess_generic_links(&$variables) {
  $_html = &$variables['_html'];
  $link = $variables['link'];
  $_html['link_bg'] = '';
  $_html['link'] = '';

  $title = !empty($link['title']) ? $link['title'] : '';
  $title = truncate_utf8($title, 28, FALSE, TRUE, 1);
  $title = [
    '#type' => 'container',
    '#attributes' => [
      'class' => 'v-align',
    ],
    'title' => [
      '#type' => 'markup',
      '#markup' => $title,
      '#prefix' => '<h4>',
      '#suffix' => '</h4>',
    ],
  ];

  $_html['link'] = l(drupal_render($title), $link['url'], [
    'attributes' => [
      'class' => 'b-blue-box',
    ],
    'html' => TRUE,
  ]);
}

/**
 * Implements hook_preprocess_html().
 *
 * Preprocess for handling gtm parameters.
 */
function souriau_preprocess_html(&$vars) {
  // Security scanners ask that we set has_js to 'secure' and 'httponly'.
  if (isset($_COOKIE['has_js']) && $_COOKIE['has_js']) {
    setcookie('has_js', 1, NULL, '/', NULL, TRUE, TRUE);
  }

  $vars['gtm'] = souriau_common_gtm_tags();
  $vars['google_optimize'] = souriau_common_google_optimize_code();
}

/**
 * Implements hook_html_head_alter().
 *
 * For removing certain metatags for certain pages.
 */
function souriau_html_head_alter(&$head_elements) {
  $unset_canonical_tag_pages = ['newsroom', 'download-center', 'where-to-buy'];
  if (in_array(drupal_get_path_alias(), $unset_canonical_tag_pages)) {
    foreach ($head_elements as $key => $data) {
      if (isset($data['#name']) && $data['#name'] == 'canonical') {
        unset($head_elements[$key]);
      }
    }
  }
}
