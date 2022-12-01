<?php
/**
 * Default argument plugin to extract a current language.
 *
 * This plugin actually has no options so it odes not need to do a great deal.
 */
class souriau_common_views_handler_argument_current_language extends views_plugin_argument_default {
  function get_argument() {
    global $language;

    return $language->language;
  }
}
