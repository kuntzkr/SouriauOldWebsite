<?php
/**
 * @file
 * Module login and api.
 */

/**
 * Get current variant.
 */
function qtools_varnish_get_variant($name, $default_value = '') {
  $variant = &drupal_static(__FUNCTION__, array());
  if (empty($variant)) {
    $source = !empty($_COOKIE['QTEVARIANT'])
      ? $_COOKIE['QTEVARIANT']
      : '';

    $items = explode('|', $source);
    foreach ($items as $item) {
      list($key, $value) = explode('=', trim($item));
      $variant[$key] = $value;
    }
  }

  return !empty($variant[$name])
    ? $variant[$name]
    : $default_value;
}

/**
 * Get user bin.
 */
function qtools_varnish_get_user_bin($account, $tag_values = FALSE) {

  $bin = array();

  // If user should bypass varnish we must set per user bin.
  if (user_access(QTOOLS_VARNISH_PERM_BYPASS_VARNISH, $account)) {
    $bin[] = 'u' . $account->uid;
  }
  // Bin for anonym user is empty.
  elseif ($account->uid > 0) {
    // Set user roles as default bin.
    $roles = array_filter(array_keys($account->roles));
    foreach ($roles as $role) {
      $bin[] = 'ur' . $role;
    }
  }

  // Allow Other modules to alter bin.
  drupal_alter('qtools_varnish_user_cache_bin', $bin, $account);
  sort($bin);

  return $tag_values
    ? $bin
    : implode('_', $bin);
}

/**
 * Gather esi providers.
 */
function qtools_varnish_esi_handler($esi_type = NULL) {
  $handlers = &drupal_static(__FUNCTION__, array());

  // Return from static cache.
  if (empty($handlers)) {
    // Gather handlers list.
    $handlers = module_invoke_all('qtools_varnish_esi_handlers');
  }

  if (!empty($esi_type)) {
    $result = !empty($handlers[$esi_type]) ? $handlers[$esi_type] : NULL;
  }
  else {
    $result = $handlers;
  }
  return $result;
}

/**
 * Helper function that create userblock markup and check if it can be used.
 */
function qtools_varnish_create_user_block($selector, $attributes = array()) {
  global $user;

  $block = FALSE;

  // User blocks are only available to users.
  if (!empty($user->uid) && qtools_varnish_enabled()) {
    // Parse selector.
    list($tag, $id, $class) = qtools_api__selector_parse($selector);
    if (empty($tag)) {
      $tag = 'div';
    }

    // Update attributes.
    $attributes += array(
      'id' => $id,
      'class' => implode(' ', $class),
      'style' => 'display:none;',
    );
    $block = '<'. $tag . ' ' . drupal_attributes(array_filter($attributes)) . '></' . $tag . '>';
  }
  return $block;
}

/**
 * Helper function that create esi markup and check if it can be used.
 */
function qtools_varnish_create_esi_block($module, $block_id, $cachemode = DRUPAL_CACHE_PER_USER, $esi_args = array(), $maxwait = 5000) {

  // ESI blocks are only available when Varnish enabled.
  if (qtools_varnish_enabled()) {
    $esi_type = QTOOLS_VARNISH_ESI_TYPE_BLOCK;
    $esi_id = $module . '-' . $block_id;
    $block = qtools_varnish_wrap(qtools_varnish_esi_tag($esi_type, $esi_id, $cachemode, $esi_args, $maxwait));
  }
  else {
    $block = FALSE;
  }
  return $block;
}


/**
 * Check if this server can handle Varnish.
 */
function qtools_varnish_enabled($ignore_post = FALSE, &$disabled_reason = FALSE) {
  global $theme, $is_https;
  $varnish_enabled = &drupal_static('qtools_varnish_enabled', NULL);
  if ($varnish_enabled !== NULL) {
    return $varnish_enabled;
  }

  // Disabled by default.
  $varnish_enabled = FALSE;
  $disabled_reason = QTOOLS_VARNISH_DISABLED_OTHER;

  // Enable Varnish if header present and not POST.
  if ($ignore_post || empty($_POST)) {
    if (!empty($_SERVER[QTOOLS_VARNISH_HEADER_ENABLED])) {

      // Check for https.
      if (_qtools_varnish_settings('available', 'https') || !$is_https) {

        // Do nothing if in admin theme.
        $admin_theme = variable_get('admin_theme', 0);
        if (_qtools_varnish_settings('available', 'admin_theme') || ($admin_theme != $theme)) {

          // From now Varnish enabled by default.
          $varnish_enabled = TRUE;
          $disabled_reason = FALSE;

          // Disable if current user may bypass varnish.
          if (user_access(QTOOLS_VARNISH_PERM_BYPASS_VARNISH)) {
            $varnish_enabled = FALSE;
            $disabled_reason = QTOOLS_VARNISH_DISABLED_BYPASS;
          }

          // Disable if varnish disabled for specific domain name.
          if ($varnish_enabled) {
            $config = explode(PHP_EOL, _qtools_varnish_settings('available', 'exclide', ''));
            foreach ($config as $line) {
              $rule = explode('|', trim($line));
              if (($rule[0] == '*') || ($_SERVER['SERVER_NAME'] == $rule[0])) {
                if (($rule[1] == '*') || strpos($_SERVER['REQUEST_URI'], $rule[1]) === 0) {
                  $varnish_enabled = FALSE;
                  $disabled_reason = QTOOLS_VARNISH_DISABLED_EXCLUDE;
                  break;
                }
              }
            }
          }
        }
        else {
          $disabled_reason = QTOOLS_VARNISH_DISABLED_ADMINTHEME;
        }
      }
      else {
        $disabled_reason = QTOOLS_VARNISH_DISABLED_HTTPS;
      }
    }
    else {
      $disabled_reason = QTOOLS_VARNISH_DISABLED_NOHEADER;
    }
  }
  else {
    $disabled_reason = QTOOLS_VARNISH_DISABLED_POST;
  }
  return $varnish_enabled;
}

/**
 * Get tags array from given text.
 */
function qtools_varnish_parse_tags($text) {
  $tags = explode(',', $text);
  foreach ($tags as &$tag) {
    $tag = explode(QTOOLS_TAG_EQUAL_SIGN, trim($tag));
    if (empty($tag[1])) {
      $tag[1] = '';
    }
    $tag = qtools_api__cache_tag($tag[0], $tag[1]);
  }
  return $tags;
}

/**
 * Get deflate KEY.
 */
function qtools_varnish_get_def_key($reset = FALSE) {
  $key = variable_get(__FUNCTION__, -1);
  if ($key == -1 || $reset) {
    $key = time();
    variable_set(__FUNCTION__, $key);
  }
  return $key;
}

/**
 * Generate ESI tag.
 */
function qtools_varnish_esi_tag($esi_type, $esi_id, $cachemode = DRUPAL_CACHE_PER_USER, $esi_args = array(), $maxwait = 5000) {

  // Disallow ESI tags on ESI requests to prevent loop.
  // TODO: we need to do this only on error pages?
  if (strpos($_SERVER['REQUEST_URI'], '/qtools_varnish/esi/') !== FALSE) {
    $tag = '<div style="display:none" class="qtools_varnish_esi_loop"></div>';
    return $tag;
  }

  // Generate ESI path.
  $path = 'qtools_varnish/esi/' . $esi_type . '/' . $esi_id;

  // Add signature.
  $signature = qtools_varnish_get_signature($esi_type, $esi_id, $cachemode, $esi_args);

  // Build query.
  $query['cachemode'] = $cachemode;
  if (!empty($esi_args)) {
    $query['a'] = $esi_args;
  }
  $url = url($path . '/' . $signature, array('query' => $query));

  // Build tag.
  $tag = "<!--esi\n" . '<esi:include src="' . $url  . '" maxwait="' . $maxwait . '"/>' . "\n-->";
  return $tag;
}
