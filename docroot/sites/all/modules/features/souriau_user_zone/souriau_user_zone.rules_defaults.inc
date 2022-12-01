<?php
/**
 * @file
 * souriau_user_zone.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function souriau_user_zone_default_rules_configuration() {
  $items = array();
  $items['rules_redirect_user_logins'] = entity_import('rules_config', '{ "rules_redirect_user_logins" : {
      "LABEL" : "Redirect user logins",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_login" : [] },
      "IF" : [
        { "NOT text_matches" : { "text" : [ "site:current-page:path" ], "match" : "user\\/reset" } }
      ],
      "DO" : [ { "redirect" : { "url" : "\\u003Cfront\\u003E" } } ]
    }
  }');
  return $items;
}
