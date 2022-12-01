<?php
/**
 * @file
 * Theme functions for souriau_common.
 */

/**
 * Theming function.
 */
function theme_figure_pic($variables) {
  $element = $variables['element'];
  if (empty($element['#image'])) {
    return '<figure class="pic"></figure>';
  }
  // In case: #image = fid.
  if (!empty($element['#image']) && is_numeric($element['#image'])) {
    $element['#image'] = file_load($element['#image']);
    if (!$element['#image']) {
      return '<figure class="pic"></figure>';
    }
  }
  $souriau_settings = isset($element['#souriau_settings']) ? $element['#souriau_settings'] : [];
  souriau_common_element_figure_pic_prepare($element, $element['#image']);

  $attributes = [];
  if (isset($element['#attributes'])) {
    $attributes = $element['#attributes'];
  }
  if (!empty($element['#style'])) {
    $attributes['src'] = image_style_url($element['#style'], $element['#path']);
  }
  else {
    $attributes['src'] = file_create_url($element['#path']);
  }

  // Set image height for correct working jquery function matchheight.
  if (!empty($souriau_settings['image_type']) && $souriau_settings['image_type'] == 'search_result') {
    $image_info = image_get_info(image_style_path($element['#style'], $element['#path']));
    if (!$image_info) {
      $image_info = image_get_info($element['#path']);
    }

    if ($image_info) {
      image_style_transform_dimensions($element['#style'], $image_info);
    }
    $element['#height'] = $image_info['height'];
  }

  foreach (array('width', 'height', 'alt') as $key) {
    if (isset($element['#' . $key])) {
      $attributes[$key] = $element['#' . $key];
    }
  }
  $output = '<figure class="pic">';
  if (isset($element['#href'])) {
    $output .= l('<img' . drupal_attributes($attributes) . ' />', $element['#href'], ['html' => TRUE]);
  }
  else {
    $output .= '<img' . drupal_attributes($attributes) . ' />';
  }
  $output .= '</figure>';

  return $output;
}

/**
 * Theming function.
 */
function theme_svg_icon($variables) {
  $element = $variables['element'];
  if (isset($element['#attributes'])) {
    $attributes = $element['#attributes'];
  }
  $attributes['class'][] = 'svg-ico';
  $icon = $element['#icon'];
  $wrapper_attr = [
    'class' => ['ico', $icon],
  ];
  $output = '<span' . drupal_attributes($wrapper_attr) . '><!--[if gte IE 9]><!-->';
  $output .= '<svg' . drupal_attributes($attributes) . '><use xlink:href="#' . $icon . '"></use></svg>';
  $output .= '<!--<![endif]--></span>';

  return $output;
}

/**
 * Theming function.
 */
function theme_find_part_number($variables) {
  $search_context = isset($variables['search_context']) ? $variables['search_context'] : [];
  $search_context += ['active_tab' => 'part-number'];
  $icon = [
    '#type' => 'svg_icon',
    '#icon' => 'ico-search',
  ];
  $search_button_text = '<span class="btn-txt">' . t('FIND A PART NUMBER', [], ['context' => SOURIAU_COMMON_T_OTHER]) . '</span>';
  $search_url_parts = ['search'];
  if (isset($search_context['keyword'])) {
    $search_url_parts[] = $search_context['keyword'];
    unset($search_context['keyword']);
  }
  $search_url = implode('/', $search_url_parts);
  $output = l(drupal_render($icon) . $search_button_text, $search_url, [
    'html' => TRUE,
    'attributes' => [
      'class' => ['btn', 'link_search'],
    ],
    'query' => $search_context,
  ]);
  return $output;
}

/**
 * Theme function for souriau_common_table_drag.
 */
function theme_souriau_common_table_drag($vars) {
  $element = $vars['element'];
  drupal_add_tabledrag('sample_table', 'order', 'sibling', 'item-row-weight');

  $header = [
    'label' => t('Attribute'),
    'enabled' => t('Enabled/disabled'),
    'weight' => t('Weight'),
  ];

  $rows = [];
  foreach (element_children($element) as $key) {
    $row = [];
    $row['data'] = [];
    foreach ($header as $fieldname => $title) {
      $row['data'][] = drupal_render($element[$key][$fieldname]);
      $row['class'] = ['draggable'];
    }
    $rows[] = $row;
  }

  return theme('table', [
    'header' => $header,
    'rows' => $rows,
    'attributes' => ['id' => 'sample_table'],
  ]);
}

/**
 * Theme souriau_common_main_menu_form.
 *
 * Copy from theme_menu_overview_form().
 */
function theme_souriau_common_main_menu_form($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('menu-overview', 'match', 'parent', 'menu-plid', 'menu-plid', 'menu-mlid', TRUE, MENU_MAX_DEPTH - 1);
  drupal_add_tabledrag('menu-overview', 'order', 'sibling', 'menu-weight');

  $header = [
    t('Menu link', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    [
      'data' => t('Enabled', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'class' => ['checkbox'],
    ],
    t('Weight', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    [
      'data' => t('Operations', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      'colspan' => '3',
    ],
  ];

  $rows = [];

  // Default $menu_settings_field.
  $menu_settings_field = 'souriau_common_main_menu_form';
  // Found Menu_settings Field.
  $childrens = element_children($form);
  foreach ($childrens as $child) {
    if (!empty($form[$child]['#menu'])) {
      $menu_settings_field = $child;
    }
  }

  foreach (element_children($form[$menu_settings_field]) as $mlid) {
    if (isset($form[$menu_settings_field][$mlid]['hidden'])) {
      $element = &$form[$menu_settings_field][$mlid];
      // Build a list of operations.
      $operations = [];
      foreach (element_children($element['operations']) as $op) {
        $operations[] = ['data' => drupal_render($element['operations'][$op]), 'class' => ['menu-operations']];
      }
      while (count($operations) < 2) {
        $operations[] = '';
      }

      // Add special classes to be used for tabledrag.js.
      $element['plid']['#attributes']['class'] = ['menu-plid'];
      $element['mlid']['#attributes']['class'] = ['menu-mlid'];
      $element['weight']['#attributes']['class'] = ['menu-weight'];

      // Change the parent field to a hidden. This allows any value but hides the field.
      $element['plid']['#type'] = 'hidden';

      $row = [];
      $row[] = theme('indentation', ['size' => $element['#item']['depth'] - 1]) . drupal_render($element['title']);
      $row[] = [
        'data' => drupal_render($element['hidden']),
        'class' => ['checkbox', 'menu-enabled'],
      ];
      $row[] = drupal_render($element['weight']) . drupal_render($element['plid']) . drupal_render($element['mlid']);
      $row = array_merge($row, $operations);

      $row = array_merge(['data' => $row], $element['#attributes']);
      $row['class'][] = 'draggable';
      $rows[] = $row;
    }
  }

  $output = '';
  if (empty($rows)) {
    $rows[] = [
      [
        'data' => t('Menu empty', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
        'colspan' => '7',
      ],
    ];
  }
  $output .= theme('table', [
    'header' => $header,
    'rows' => $rows,
    'attributes' => ['id' => 'menu-overview'],
  ]);
  $output .= drupal_render_children($form);
  return $output;
}
