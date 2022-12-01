<?php
/**
 * @file
 * souriau_search_feature.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function souriau_search_feature_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_parent_product_range';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_parent_product_range';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_parent_product_range'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:category';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:category';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_shell_material_term';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_shell_material_term';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(
      'search_api_views:search_souriau:page' => 'search_api_views:search_souriau:page',
    ),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_shell_material_term'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_connector_type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_connector_type';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_connector_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_current_iec';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_current_iec';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_current_iec'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_current_ul';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_current_ul';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_current_ul'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_description_sealing_le';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_description_sealing_le';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_description_sealing_le'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_first_mate_last_break_';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_first_mate_last_break_';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_first_mate_last_break_'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_last_mate_first_break_';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_last_mate_first_break_';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_last_mate_first_break_'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_plating';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_plating';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_plating'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_shell_material';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_shell_material';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_shell_material'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index::field_sku_products:field_sku_type_component';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = '';
  $facet->facet = 'field_sku_products:field_sku_type_component';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '50',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@products_search_index::field_sku_products:field_sku_type_component'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:avaliable_translations';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'avaliable_translations';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:avaliable_translations'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_code_p';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_code_p';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_code_p'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_parent_product_range';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_parent_product_range';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_parent_product_range'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_parent_product_range:field_code_p';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_parent_product_range:field_code_p';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_parent_product_range:field_code_p'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_parent_product_range:field_subcategory';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_parent_product_range:field_subcategory';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_parent_product_range:field_subcategory'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_parent_product_range:title_field';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_parent_product_range:title_field';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_parent_product_range:title_field'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_product_range';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_product_range';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_product_range'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_product_series';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_product_series';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_product_series'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:category';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:category';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_radios',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:category'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_connector_type_term';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_connector_type_term';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:field_connector_type_term'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_plating_term';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_plating_term';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:field_plating_term'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_shell_material_term';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_shell_material_term';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_shell_material_term'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_active_part_technology';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_active_part_technology';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_active_part_technology'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_application';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_application';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_application'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_backshell_angle';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_backshell_angle';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_backshell_angle'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_backshell_type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_backshell_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_backshell_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_body';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_body';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_body'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_breaking_capability';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_breaking_capability';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_boolean',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_breaking_capability'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_max_inch';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_diam_max_inch';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_max_inch'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_max_mm';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_diam_max_mm';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_max_mm'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_min_inch';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_diam_min_inch';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_min_inch'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_min_mm';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_diam_min_mm';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_diam_min_mm'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_diameter';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_diameter';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_diameter'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_ending';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_ending';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_ending'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_length_m';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_length_m';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_length_m'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_cable_type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_cable_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_cable_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_color_stripes_marking';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_color_stripes_marking';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_boolean',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_color_stripes_marking'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_connector_accessory_op';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_connector_accessory_op';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_connector_accessory_op'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_connector_side_1';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_connector_side_1';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_connector_side_1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_connector_side_2';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_connector_side_2';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_connector_side_2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_connector_type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_connector_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_connector_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_compatibilitie';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_compatibilitie';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_compatibilitie'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_delivery';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_delivery';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_delivery'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_gender';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_gender';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_gender'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_packaging';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_packaging';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_packaging'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_plating';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_plating';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_plating'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_size_awg';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_size_awg';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_size_awg'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_size_mm';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_size_mm';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_size_mm'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_standard';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_standard';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_standard'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_contact_type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_contact_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_contact_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_core_section_mm2';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_core_section_mm2';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_core_section_mm2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_coupling';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_coupling';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_coupling'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_current_a';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_current_a';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_current_a'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_current_breaking_capac';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_current_breaking_capac';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_current_breaking_capac'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_current_iec';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_current_iec';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_current_iec'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_current_ul';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_current_ul';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_current_ul'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_description_sealing_le';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_description_sealing_le';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_description_sealing_le'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_ending_1';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_ending_1';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_ending_1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_ending_2';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_ending_2';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_ending_2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_environmental';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_environmental';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_environmental'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_fiber_optic_contact_te';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_fiber_optic_contact_te';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_fiber_optic_contact_te'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_first_mate_last_break_';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_first_mate_last_break_';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_first_mate_last_break_'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_function';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_function';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_function'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_gender_side_1';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_gender_side_1';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_gender_side_1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_gender_side_2';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_gender_side_2';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_gender_side_2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_halogen_free';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_halogen_free';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_boolean',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_halogen_free'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_insulation_grip';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_insulation_grip';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_boolean',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_insulation_grip'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_last_mate_first_break_';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_last_mate_first_break_';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_last_mate_first_break_'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_layout';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_layout';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_layout'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_layout_1';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_layout_1';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_layout_1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_layout_2';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_layout_2';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_layout_2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_manufacturing_process';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_manufacturing_process';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_manufacturing_process'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_mating_connector';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_mating_connector';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_mating_connector'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_mating_cycles';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_mating_cycles';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_mating_cycles'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_module';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_module';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_module'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_number_cavity_13mm';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_number_cavity_13mm';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_number_cavity_13mm'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_number_of_contacts';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_number_of_contacts';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_number_of_contacts'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_pcb_diameter_mm';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_pcb_diameter_mm';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_pcb_diameter_mm'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_pcb_length';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_pcb_length';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_pcb_length'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_pcb_tail_angle';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_pcb_tail_angle';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_pcb_tail_angle'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_pitch';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_pitch';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_pitch'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_plating';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_plating';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_plating'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_plug_type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_plug_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_plug_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_receptacle_mount_type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_receptacle_mount_type';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_receptacle_mount_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_salt_spray';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_salt_spray';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_salt_spray'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_sealing_level';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_sealing_level';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_sealing_level'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_shell_continuity_mohm';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_shell_continuity_mohm';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_shell_continuity_mohm'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_shell_material';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_shell_material';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_shell_material'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_shell_size';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_shell_size';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_shell_size'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_shielding';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_shielding';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_boolean',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_shielding'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_size_contact';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_size_contact';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_size_contact'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_standard';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_standard';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_standard'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_subtype_component';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_subtype_component';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_subtype_component'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_temp_max_c';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_temp_max_c';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_temp_max_c'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_temp_max_f';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_temp_max_f';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_temp_max_f'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_temp_min_c';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_temp_min_c';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_temp_min_c'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_temp_min_f';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_temp_min_f';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_temp_min_f'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_type_component';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_type_component';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_type_component'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_voltage_iec_v';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_voltage_iec_v';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_voltage_iec_v'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_voltage_ul_v';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_voltage_ul_v';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_voltage_ul_v'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_vrms';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_vrms';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_vrms'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_maxi_a';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_wire_acceptance_maxi_a';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_maxi_a'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_maxi_m';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_wire_acceptance_maxi_m';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_maxi_m'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_mini_a';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_wire_acceptance_mini_a';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_mini_a'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_mini_m';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_wire_acceptance_mini_m';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_number_compare',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_wire_acceptance_mini_m'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_wire_awg';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_wire_awg';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_wire_awg'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:field_sku_with_ground_cavity';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:field_sku_with_ground_cavity';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:field_sku_with_ground_cavity'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:product_series';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:product_series';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:product_series'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:sku';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:sku';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:sku'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:sku_string';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:sku_string';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:sku_string'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:subcategory';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:subcategory';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_radios',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:field_sku_products:subcategory'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sku_products:title_field';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sku_products:title_field';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sku_products:title_field'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_sticky';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_sticky';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_sticky'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_subcategory';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_subcategory';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_subcategory'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:field_test_field';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'field_test_field';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:field_test_field'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:language';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'language';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:language'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:nid';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'nid';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:nid'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:search_api_et_id';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'search_api_et_id';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:search_api_et_id'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:search_api_language';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'search_api_language';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:search_api_language'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:status';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'status';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:status'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:title_field';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'title_field';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:title_field'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:title_field_string';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'title_field_string';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:title_field_string'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:type';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'type';
  $facet->enabled = FALSE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'souriau_common_dropdown_list',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '20',
    'nofollow' => 1,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'simple',
    ),
  );
  $export['search_api@products_search_index:block:type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@products_search_index:block:type_weight';
  $facet->searcher = 'search_api@products_search_index';
  $facet->realm = 'block';
  $facet->facet = 'type_weight';
  $facet->enabled = TRUE;
  $facet->hash = '0';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
    ),
    'sort_weight' => array(
      'active' => -50,
      'count' => -49,
      'display' => -48,
    ),
    'sort_order' => array(
      'active' => 3,
      'count' => 3,
      'display' => 4,
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => 20,
    'nofollow' => 1,
    'show_expanded' => 0,
  );
  $export['search_api@products_search_index:block:type_weight'] = $facet;

  return $export;
}
