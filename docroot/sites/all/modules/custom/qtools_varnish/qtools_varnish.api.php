<?php
/**
 * @file
 * Module API.
 * // TODO: add API.
 */

/**
 * Implements hook_qtools_varnish_user_cache_bin_alter().
 *
 * Alter user cache bin, allow have different caches per
 * user role/domain, language or any other condition.
 */
function mymodule_qtools_varnish_user_cache_bin_alter(&$cookie_inf, $account) {
}

/**
 * Implements hook_qtools_varnish_userblocks().
 *
 * Return list of user blocks to be displayed on current page.
 */
function mymodule_qtools_varnish_userblocks() {

}
