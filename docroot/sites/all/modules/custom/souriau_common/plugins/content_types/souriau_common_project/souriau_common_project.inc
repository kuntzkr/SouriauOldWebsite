<?php
/**
 * @file
 * Implements project CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU Common: project', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: project', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'single' => TRUE,
  'render callback' => 'souriau_common_project_content_type_render',
  'edit form' => 'souriau_common_project_content_type_edit_form',
  'hook theme' => 'souriau_common_project_content_type_theme',
  'admin title' => 'souriau_common_project_content_type_admin_title',
  'category' => t('SOURIAU'),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
];

/**
 * Implements hook_content_type_render().
 */
function souriau_common_project_content_type_render() {
  $block = new stdClass();
  $block->title = NULL;
  $project_id = arg(3);
  $block->content = theme(
    'block_project',
    ['_html' => _souriau_common_project_details($project_id)]
  );
  return $block;
}

/**
 * Admin title callback.
 */
function souriau_common_project_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: project', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_project_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_project_content_type_theme(&$theme, $plugin) {
  $theme['block_project'] = [
    'path' => $plugin['path'],
    'template' => 'souriau-common-project',
    'variables' => [
      '_html' => NULL,
    ],
  ];
}

/**
 * Custom function to generate data required for individual project page.
 *
 * @param int $project_id
 *   Project ID.
 *
 * @return array
 *   HTML array to passed over template
 */
function _souriau_common_project_details($project_id) {
  global $user, $language;

  $project_entity = entity_load_single('project', $project_id);
  $project_wrapper = entity_metadata_wrapper($project_entity->type, $project_entity)->language($language->language);

  $_html = [];
  $_html['id'] = $project_id;
  $_html['title'] = check_plain($project_wrapper->field_project_title->value());
  $_html['description'] = check_plain($project_wrapper->field_project_description->value());
  $_html['data-ajax-url'] = url(format_string(
    'souriau/ajax/user/!uid/projects/!project/inline-edit',
    ['!project' => (int) $project_id, '!uid' => (int) $user->uid]
  ));
  $_html['csv-link'] = url(format_string(
    '/user/projects/!project/csv',
    ['!project' => (int) $project_id]
  ));
  $_html['myprojects-link'] = url(format_string(
    '/user/!uid/projects',
    ['!uid' => (int) $user->uid]
  ));
  $_html['part-numbers'] = [];

  // Default image in case image is not found.
  $product_image_default = souriau_common_project_lineitem_default_image();
  // Scans for individual items added in the project.
  $_html['lineitems'] = [];
  $_domain = domain_get_domain();
  $domain_countries = [];
  $domain_countries = domain_conf_variable_get($_domain['domain_id'], 'geo_countries');
  foreach ($project_wrapper->field_part_numbers as $item_id => $line_item) {
    $exception_country_codes = (!empty($line_item->field_part_number->field_sku_products) && !empty($line_item->field_part_number->field_sku_products->field_view_exception->value()))
      ? $line_item->field_part_number->field_sku_products->field_view_exception->value() : [];
    if (is_array($domain_countries) && !empty(array_intersect($exception_country_codes, $domain_countries))) {
      continue;
    }
    $line_item_data = souriau_common_project_line_item_data($line_item, $product_image_default);
    if (empty($line_item_data)) {
      continue;
    }

    $line_item_data['partno'] = $item_id;
    $line_item_data['item-delete-link'] = [
      'url' => url('user/projects/' . $project_id . '/delete/' . $item_id . '/nojs'),
      'classes' => 'ctools-use-modal ctools-modal-souriau-modal-style remove-link',
    ];

    $_html['lineitems'][] = $line_item_data;
  }
  $_html['delete-link'] = l(
    t('DELETE PROJECT', [], ['context' => SOURIAU_COMMON_T_OTHER]),
    format_string('user/projects/!pid/delete/nojs', ['!pid' => $project_id]),
    [
      'attributes' => [
        'class' => [
          'ctools-use-modal', 'ctools-modal-souriau-modal-style',
          'btn', 'blue-btn',
        ],
      ],
    ]
  );
  return $_html;
}

/**
 * Retrieve Line Item's data for given $line_item.
 *
 * @param object $line_item
 *   LineItem of a Project entity.
 * @param array $product_image_default
 *   Default image to display if there is no image in SKU.
 *
 * @return array|mixed
 *   Assosiative array with LineItem's info.
 */
function souriau_common_project_line_item_data($line_item, $product_image_default) {
  global $user, $language;

  try {
    if (empty($line_item) || empty($line_item->field_part_number->value())) {
      // Data is incomplete.
      return NULL;
    }

    // Series can be sometimes empty.
    $series = '';
    $pn_description = '';
    $parent_product_range = souriau_common_get_main_product_range($line_item->field_part_number->value());
    if (!empty($parent_product_range)) {
      $pr_wrapper = entity_metadata_wrapper('node', $parent_product_range)->language($language->language);
      $product_series = $pr_wrapper->field_product_series->value();
      $series = souriau_common_get_product_series_name($product_series);
      $pn_description = $pr_wrapper->field_pn_description->value()['safe_value'];
    }

    $product_image = $product_image_default;
    if (!empty($line_item->field_part_number->field_sku_products) && !empty($line_item->field_part_number->field_sku_products->field_sku_images->value())) {
      $sku_image_fid = $line_item->field_part_number->field_sku_products->field_sku_images[0]->value();
      $sku_image = file_load($sku_image_fid['fid']);
      $product_image = [
        'url' => file_create_url($sku_image->uri),
        'alt' => $sku_image->alt,
      ];
    }

    return [
      'url' => url('node/' . $line_item->field_part_number->nid->value()),
      'part-number' => [
        'title' => !empty($line_item->field_part_number->title->value()) ? $line_item->field_part_number->title->value() : '',
        'sku' => (!empty($line_item->field_part_number->field_sku_products) && !empty($line_item->field_part_number->field_sku_products->sku->value()))
        ? $line_item->field_part_number->field_sku_products->sku->value() : '',
        'sku-brand' => (!empty($line_item->field_part_number->field_sku_products) && !empty($line_item->field_part_number->field_sku_products->field_sku_company->value()))
        ? $line_item->field_part_number->field_sku_products->field_sku_company->value() : '',
        'sku-series' => $series,
        'sku-image' => $product_image,
        'description' => $pn_description,
      ],
      'notes' => check_plain($line_item->field_notes->value()),
    ];
  }
  catch (Exception $e) {
    watchdog('souriau_common', 'Exception: !exception in !function.', [
      '!exception' => $e->getMessage(),
      '!function' => __FUNCTION__,
    ], WATCHDOG_WARNING);
    return NULL;
  }
}

/**
 * Default image for PartNumber in Project.
 */
function souriau_common_project_lineitem_default_image() {
  $souriau_settings = variable_get('souriau_common_settings');
  if (empty($souriau_settings['user_zone']['project_default_image'])) {
    // Nothing to do here.
    return [];
  }
  $default_fid = $souriau_settings['user_zone']['project_default_image'];
  $default_file = file_load($default_fid);

  if (empty($default_file->uri)) {
    // Nothing to do here.
    return [];
  }

  return [
    'url' => file_create_url($default_file->uri),
    'alt' => 'PartNumber in Project',
  ];
}

/**
 * Implements hook_views_pre_render().
 */
function souriau_common_views_pre_render(&$view) {
  global $language;
  if ($view->name == 'userzone_my_projects') {
    $_domain = domain_get_domain();
    $domain_countries = [];
    $domain_countries = domain_conf_variable_get($_domain['domain_id'], 'geo_countries');
    foreach ($view->result as $value) {
      $project_id = $value->id;
      $part_number_count = $value->paragraphs_item_field_data_field_part_numbers_item_id;
      // Get project by project id.
      $project_entity = entity_load_single('project', $project_id);
      $project_wrapper = entity_metadata_wrapper($project_entity->type, $project_entity)->language($language->language);
      // Unset the partnumber count if domain is mentioned in view exception field of sku.
      foreach ($project_wrapper->field_part_numbers as $line_item) {
        $exception_country_codes = (!empty($line_item->field_part_number->field_sku_products) && !empty($line_item->field_part_number->field_sku_products->field_view_exception->value()))
          ? $line_item->field_part_number->field_sku_products->field_view_exception->value() : [];
        if (!empty($part_number_count) && $part_number_count > 0 && is_array($domain_countries) && !empty(array_intersect($exception_country_codes, $domain_countries))) {
          $part_number_count = $part_number_count - 1;
        }
      }
      $value->paragraphs_item_field_data_field_part_numbers_item_id = $part_number_count;
    }
  }
}
