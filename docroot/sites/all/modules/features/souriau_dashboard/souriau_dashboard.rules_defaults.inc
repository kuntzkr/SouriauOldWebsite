<?php
/**
 * @file
 * souriau_dashboard.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function souriau_dashboard_default_rules_configuration() {
  $items = array();
  $items['rules_unblock_selected_users'] = entity_import('rules_config', '{ "rules_unblock_selected_users" : {
      "LABEL" : "Unblock selected users",
      "PLUGIN" : "action set",
      "OWNER" : "rules",
      "TAGS" : [ "user" ],
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : { "user" : { "label" : "User", "type" : "user" } },
      "ACTION SET" : [ { "user_unblock" : { "account" : [ "user" ] } } ]
    }
  }');
  return $items;
}
