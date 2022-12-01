<?php
/**
 * @file
 * souriau_download_center.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_download_center_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function souriau_download_center_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function souriau_download_center_default_search_api_index() {
  $items = array();
  $items['download_center_index'] = entity_import('search_api_index', '{
    "name" : "Download center index",
    "machine_name" : "download_center_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "file",
    "options" : {
      "datasource" : { "bundles" : [ "3d_model", "document", "ipaper" ] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "dc_dtype_weight" : { "type" : "integer" },
        "dc_reference_application" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "dc_reference_capability" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "dc_reference_productrange" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "dc_title" : { "type" : "text", "real_type" : "edge_n2_kw_text" },
        "dc_weight" : { "type" : "integer" },
        "field_brand" : { "type" : "list\\u003Cstring\\u003E" },
        "field_document_language" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "name" : { "type" : "text", "real_type" : "edge_n2_kw_text" },
        "reference_fields" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "timestamp" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "teaser" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "souriau_common_alter_language_control" : { "status" : 0, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "name" : true, "dc_title" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "name" : true, "dc_title" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "name" : true, "dc_title" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "name" : true, "dc_title" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : { "name" : true, "dc_title" : true },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
