<?php
/**
 * @file
 * souriau_search_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function souriau_search_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function souriau_search_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function souriau_search_feature_default_search_api_index() {
  $items = array();
  $items['products_search_index'] = entity_import('search_api_index', '{
    "name" : "Products search index",
    "machine_name" : "products_search_index",
    "description" : null,
    "server" : "solr",
    "item_type" : "search_api_et_node",
    "options" : {
      "datasource" : { "bundles" : [
          "application",
          "capability",
          "news",
          "product",
          "productrange",
          "productrangehub",
          "category",
          "subcategory"
        ]
      },
      "index_directly" : 0,
      "cron_limit" : "50",
      "search_api_et" : {
        "include" : "incomplete",
        "restrict undefined" : 0,
        "fallback language" : ""
      },
      "fields" : {
        "avaliable_translations" : { "type" : "list\\u003Cstring\\u003E" },
        "field_search_keywords:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_sku_products" : { "type" : "integer", "entity_type" : "commerce_product" },
        "field_sku_products:category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_sku_products:domains" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_sku_products:field_sku_active_part_technology" : { "type" : "string" },
        "field_sku_products:field_sku_alternate_search_key" : {
          "type" : "list\\u003Ctext\\u003E",
          "real_type" : "list\\u003Cedge_n2_kw_text\\u003E"
        },
        "field_sku_products:field_sku_application" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_sku_products:field_sku_backshell_angle" : { "type" : "string" },
        "field_sku_products:field_sku_backshell_type" : { "type" : "string" },
        "field_sku_products:field_sku_body" : { "type" : "string" },
        "field_sku_products:field_sku_breaking_capability" : { "type" : "boolean" },
        "field_sku_products:field_sku_cable_diam_max_inch" : { "type" : "decimal" },
        "field_sku_products:field_sku_cable_diam_max_mm" : { "type" : "decimal" },
        "field_sku_products:field_sku_cable_diam_min_inch" : { "type" : "decimal" },
        "field_sku_products:field_sku_cable_diam_min_mm" : { "type" : "decimal" },
        "field_sku_products:field_sku_cable_diameter" : { "type" : "string" },
        "field_sku_products:field_sku_cable_ending" : { "type" : "string" },
        "field_sku_products:field_sku_cable_length_m" : { "type" : "integer" },
        "field_sku_products:field_sku_cable_type" : { "type" : "string" },
        "field_sku_products:field_sku_color_stripes_marking" : { "type" : "boolean" },
        "field_sku_products:field_sku_connector_accessory_op" : { "type" : "string" },
        "field_sku_products:field_sku_connector_side_1" : { "type" : "string" },
        "field_sku_products:field_sku_connector_side_2" : { "type" : "string" },
        "field_sku_products:field_sku_connector_type" : { "type" : "string" },
        "field_sku_products:field_sku_contact_compatibilitie" : { "type" : "list\\u003Cstring\\u003E" },
        "field_sku_products:field_sku_contact_delivery" : { "type" : "string" },
        "field_sku_products:field_sku_contact_gender" : { "type" : "string" },
        "field_sku_products:field_sku_contact_packaging" : { "type" : "string" },
        "field_sku_products:field_sku_contact_plating" : { "type" : "string" },
        "field_sku_products:field_sku_contact_size_awg" : { "type" : "integer" },
        "field_sku_products:field_sku_contact_size_mm" : { "type" : "decimal" },
        "field_sku_products:field_sku_contact_standard" : { "type" : "string" },
        "field_sku_products:field_sku_contact_type" : { "type" : "string" },
        "field_sku_products:field_sku_core_section_mm2" : { "type" : "string" },
        "field_sku_products:field_sku_coupling" : { "type" : "string" },
        "field_sku_products:field_sku_current_a" : { "type" : "decimal" },
        "field_sku_products:field_sku_current_breaking_capac" : { "type" : "string" },
        "field_sku_products:field_sku_current_iec" : { "type" : "decimal" },
        "field_sku_products:field_sku_current_ul" : { "type" : "decimal" },
        "field_sku_products:field_sku_description_sealing_le" : { "type" : "string" },
        "field_sku_products:field_sku_ending_1" : { "type" : "string" },
        "field_sku_products:field_sku_ending_2" : { "type" : "string" },
        "field_sku_products:field_sku_environmental" : { "type" : "list\\u003Cstring\\u003E" },
        "field_sku_products:field_sku_fiber_optic_contact_te" : { "type" : "string" },
        "field_sku_products:field_sku_first_mate_last_break_" : { "type" : "string" },
        "field_sku_products:field_sku_function" : { "type" : "list\\u003Cstring\\u003E" },
        "field_sku_products:field_sku_gender_side_1" : { "type" : "string" },
        "field_sku_products:field_sku_gender_side_2" : { "type" : "string" },
        "field_sku_products:field_sku_halogen_free" : { "type" : "boolean" },
        "field_sku_products:field_sku_insulation_grip" : { "type" : "boolean" },
        "field_sku_products:field_sku_last_mate_first_break_" : { "type" : "string" },
        "field_sku_products:field_sku_layout" : { "type" : "string" },
        "field_sku_products:field_sku_layout_1" : { "type" : "string" },
        "field_sku_products:field_sku_layout_2" : { "type" : "string" },
        "field_sku_products:field_sku_manufacturing_process" : { "type" : "string" },
        "field_sku_products:field_sku_mating_connector" : { "type" : "list\\u003Cstring\\u003E" },
        "field_sku_products:field_sku_mating_cycles" : { "type" : "integer" },
        "field_sku_products:field_sku_module" : { "type" : "string" },
        "field_sku_products:field_sku_number_cavity_13mm" : { "type" : "integer" },
        "field_sku_products:field_sku_number_of_contacts" : { "type" : "integer" },
        "field_sku_products:field_sku_pcb_diameter_mm" : { "type" : "string" },
        "field_sku_products:field_sku_pcb_length" : { "type" : "string" },
        "field_sku_products:field_sku_pcb_tail_angle" : { "type" : "integer" },
        "field_sku_products:field_sku_plating" : { "type" : "string" },
        "field_sku_products:field_sku_plug_type" : { "type" : "string" },
        "field_sku_products:field_sku_receptacle_mount_type" : { "type" : "string" },
        "field_sku_products:field_sku_salt_spray" : { "type" : "integer" },
        "field_sku_products:field_sku_sealing_level" : { "type" : "integer" },
        "field_sku_products:field_sku_shell_continuity_mohm" : { "type" : "decimal" },
        "field_sku_products:field_sku_shell_material" : { "type" : "string" },
        "field_sku_products:field_sku_shell_size" : { "type" : "string" },
        "field_sku_products:field_sku_shielding" : { "type" : "boolean" },
        "field_sku_products:field_sku_size_contact" : { "type" : "string" },
        "field_sku_products:field_sku_standard" : { "type" : "list\\u003Cstring\\u003E" },
        "field_sku_products:field_sku_subtype_component" : { "type" : "string" },
        "field_sku_products:field_sku_temp_max_c" : { "type" : "integer" },
        "field_sku_products:field_sku_temp_max_f" : { "type" : "integer" },
        "field_sku_products:field_sku_temp_min_c" : { "type" : "integer" },
        "field_sku_products:field_sku_temp_min_f" : { "type" : "integer" },
        "field_sku_products:field_sku_type_component" : { "type" : "string" },
        "field_sku_products:field_sku_voltage_iec_v" : { "type" : "integer" },
        "field_sku_products:field_sku_voltage_ul_v" : { "type" : "integer" },
        "field_sku_products:field_sku_vrms" : { "type" : "integer" },
        "field_sku_products:field_sku_wire_acceptance_maxi_a" : { "type" : "decimal" },
        "field_sku_products:field_sku_wire_acceptance_maxi_m" : { "type" : "decimal" },
        "field_sku_products:field_sku_wire_acceptance_mini_a" : { "type" : "decimal" },
        "field_sku_products:field_sku_wire_acceptance_mini_m" : { "type" : "decimal" },
        "field_sku_products:field_sku_wire_awg" : { "type" : "integer" },
        "field_sku_products:field_sku_with_ground_cavity" : { "type" : "integer" },
        "field_sku_products:partial_sku" : { "type" : "text", "boost" : "5.0", "real_type" : "edge_n2_kw_text" },
        "field_sku_products:product_series" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_sku_products:sku_string" : { "type" : "string" },
        "field_sku_products:subcategory" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_sku_products:title_field" : { "type" : "text" },
        "field_sticky" : { "type" : "boolean" },
        "nid" : { "type" : "integer" },
        "partial_title" : { "type" : "text", "boost" : "8.0", "real_type" : "edge_n2_kw_text" },
        "product_series_text" : { "type" : "list\\u003Ctext\\u003E" },
        "product_series_weight" : { "type" : "integer" },
        "search_api_et_id" : { "type" : "string" },
        "search_api_language" : { "type" : "string" },
        "search_title" : { "type" : "text" },
        "title_field_string" : { "type" : "string" },
        "type" : { "type" : "string" },
        "type_weight" : { "type" : "integer" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : {
            "lang_field" : "title_field",
            "languages" : {
              "und" : "und",
              "en-en" : "en-en",
              "en-gb" : "en-gb",
              "en-us" : "en-us",
              "en-ca" : "en-ca",
              "fr-ca" : "fr-ca",
              "fr-fr" : "fr-fr",
              "es-sp" : "es-sp",
              "ch-ch" : "ch-ch",
              "jp-jp" : "jp-jp",
              "en" : "en",
              "en-int" : "en-int",
              "it" : "it",
              "na" : "na"
            }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "souriau_common_alter_language_control" : { "status" : 1, "weight" : "0", "settings" : [] },
        "souriau_common_exclude_unpublish_sku" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : {
            "fields" : [],
            "spaces" : "\\\\\\\\n|\\\\\\\\r|\\\\\\\\t|[[:^alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_case_ignore" : { "status" : 1, "weight" : "-49", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "field_code_p" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "field_code_p" : true } }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "field_code_p" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}
