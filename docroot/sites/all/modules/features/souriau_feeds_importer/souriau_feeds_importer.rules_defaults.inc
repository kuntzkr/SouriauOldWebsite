<?php

/**
 * @file
 * souriau_feeds_importer.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function souriau_feeds_importer_default_rules_configuration() {
  $items = array();
  $items['rules_product_price_rule'] = entity_import('rules_config', '{ "rules_product_price_rule" : {
      "LABEL" : "commerce product price setup",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "entity" ],
      "ON" : { "commerce_product_update" : [], "commerce_product_insert" : [] },
      "DO" : [
        { "data_set" : { "data" : [ "commerce-product:commerce-price:amount" ], "value" : "0" } }
      ]
    }
  }');
  return $items;
}
