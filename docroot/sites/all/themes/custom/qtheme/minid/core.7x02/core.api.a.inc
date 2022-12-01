<?php
/**
 * @file
 * Image processing facility.
 */

// Drupal resources.
require_once minid_path('root', 'includes/ajax.inc');
require_once minid_path('root', 'modules/system/image.gd.inc');

// ================================= Drupal functions analogs.

/**
 * Returns if user is anonymous.
 */
function user_is_anonymous() {
  global $minid_user_is_anonymous;
  return !empty($minid_user_is_anonymous);
}

/**
 * Parses Drupal module and theme .info files.
 */
function drupal_parse_info_file($filename) {
  if (!file_exists($filename)) {
    die('info file [' . $filename . '] not found');
  }
  $data = file_get_contents($filename);
  $info = drupal_parse_info_format($data);
  return $info;
}

/**
 * Parses data in Drupal's .info format.
 */
function drupal_parse_info_format($data) {
  $info = array();

  if (preg_match_all('
    @^\s*                           # Start at the beginning of a line, ignoring leading whitespace
    ((?:
      [^=;\[\]]|                    # Key names cannot contain equal signs, semi-colons or square brackets,
      \[[^\[\]]*\]                  # unless they are balanced and not nested
    )+?)
    \s*=\s*                         # Key/value pairs are separated by equal signs (ignoring white-space)
    (?:
      ("(?:[^"]|(?<=\\\\)")*")|     # Double-quoted string, which may contain slash-escaped quotes/slashes
      (\'(?:[^\']|(?<=\\\\)\')*\')| # Single-quoted string, which may contain slash-escaped quotes/slashes
      ([^\r\n]*?)                   # Non-quoted string
    )\s*$                           # Stop at the next end of a line, ignoring trailing whitespace
    @msx', $data, $matches, PREG_SET_ORDER)) {
    foreach ($matches as $match) {
      // Fetch the key and value string.
      $i = 0;
      foreach (array('key', 'value1', 'value2', 'value3') as $var) {
        $$var = isset($match[++$i]) ? $match[$i] : '';
      }
      $value = stripslashes(substr($value1, 1, -1)) . stripslashes(substr($value2, 1, -1)) . $value3;

      // Parse array syntax.
      $keys = preg_split('/\]?\[/', rtrim($key, ']'));
      $last = array_pop($keys);
      $parent = &$info;

      // Create nested arrays.
      foreach ($keys as $key) {
        if ($key == '') {
          $key = count($parent);
        }
        if (!isset($parent[$key]) || !is_array($parent[$key])) {
          $parent[$key] = array();
        }
        $parent = &$parent[$key];
      }

      // Handle PHP constants.
      if (preg_match('/^\w+$/i', $value) && defined($value)) {
        $value = constant($value);
      }

      // Insert actual value.
      if ($last == '') {
        $last = count($parent);
      }
      $parent[$last] = $value;
    }
  }

  return $info;
}

/**
 * Template render replacement.
 */
function theme_render_template($template_file, $variables) {
  if (!file_exists($template_file)) {
    return '[template <b>' . $template_file . '</b> not found]';
  }
  // Extract the variables to a local namespace
  extract($variables, EXTR_SKIP);

  // Start output buffering
  ob_start();

  // Include the template file
  include $template_file;

  // End buffering and return its contents
  return ob_get_clean();
}

/**
 * Entity view function replacement.
 */
function entity_view($entity_type, $entity_id, $view_mode = 'full') {
  global $theme_name, $theme_registry;

  $ids = explode(':', $entity_id);
  if (empty($ids[1])) {
    $ids[1] = FALSE;
  }

  $theme = $entity_type . '__' . $ids[0] . '__' . $view_mode;
  if (!isset($theme_registry[$theme])) {
    $template = $entity_type . '/' . str_replace('_', '-', $theme);
    $theme_registry[$theme] = array(
      'template' => $template,
    );
  }

  // Prepare variables.
  $sample = minid_sample($entity_type, $ids[0], $ids[1]);
  $variables = array(
    'entity' => (object) $sample,
    'content' => minid_render_sample($sample, $view_mode),
  );

  // Return themed entity.
  return theme($theme, $variables);
}

/**
 * Theme function replacement.
 */
function theme($theme, $variables = array()) {
  global $theme_name;

  // Check for function based theme.
  $function = $theme_name . '_' . $theme;
  if (function_exists($function)) {
    return $function($variables);
  }

  // Check if template hook exists.
  $theme_registry = minid_theme_registry();
  if (empty($theme_registry[$theme])) {
    die('theme [' . $theme . '] not found');
  }
  $hook = $theme_registry[$theme];
  if (!isset($hook['type'])) {
    $hook['type'] = 'theme';
  }

  // Check preprocess function.
  $function = $theme_name . '_preprocess_' . $theme;

  // For layouts preprocess is not required.
  if (!function_exists($function)) {
    die('preprocess [' . $function . '] not found');
  }

  // Check template.
  $template = minid_path('theme', 'templates/' . $hook['template'] . '.tpl.php');

  // Set default keys.
  if (empty($variables['_html'])) {
    $variables['_html'] = array();
  }
  if (empty($variables['_data'])) {
    $variables['_data'] = array();
  }

  // Special preprocess for html template.
  if ($theme == 'html') {
    _preprocess_html($variables);
  }

  // Call preprocess function if exists.
  $function($variables);

  // Special postprocess for html template.
  if ($theme == 'html') {
    _postprocess_html($variables);
  }

  // Render template.
  return theme_render_template($template, $variables);
}

/**
 * Theme image_style().
 */
function qtheme_image($path, $style, $alt = '', $attributes = array()) {
  $source = minid_path('theme', $path);

  // Check if image should be processed.
  $settings = minid_image_style_get($style);
  $process = FALSE;
  if (!empty($settings['width'])) {
    $query['width'] = $settings['width'];
    $process = TRUE;
  }
  if (!empty($settings['height'])) {
    $query['height'] = $settings['height'];
    $process = TRUE;
  }

  // Build URL.
  if ($process) {
    $query['source'] = $source;
    $url = url('image', array('query' => $query));
  }
  else {
    $url = $source;
  }

  // Output result.
  if (!empty($settings['url_only'])) {
    return $url;
  }
  else {
    return '<img src="' . $url . '" />';
  }
}

/**
 * Render function wrapper.
 */
function qtheme_render($content, $key) {
  if (isset($content[$key])) {
    return implode('', $content[$key]);
  }
}

/**
 * Build http query.
 */
function drupal_http_build_query(array $query, $parent = '') {
  $params = array();

  foreach ($query as $key => $value) {
    $key = ($parent ? $parent . '[' . rawurlencode($key) . ']' : rawurlencode($key));

    // Recurse into children.
    if (is_array($value)) {
      $params[] = drupal_http_build_query($value, $key);
    }
    // If a query parameter value is NULL, only append its key.
    elseif (!isset($value)) {
      $params[] = $key;
    }
    else {
      // For better readability of paths in query strings, we decode slashes.
      $params[] = $key . '=' . str_replace('%2F', '/', rawurlencode($value));
    }
  }

  return implode('&', $params);
}

/**
 * url replacement.
 */
function url($path = NULL, array $options = array()) {

  if ($path == '<void>') {
    return 'javascript:void(0)';
  }

  // Merge in defaults.
  $options += array(
    'fragment' => '',
    'query' => array(),
    'absolute' => FALSE,
    'alias' => FALSE,
    'prefix' => ''
  );

  if (isset($options['fragment']) && $options['fragment'] !== '') {
    $options['fragment'] = '#' . $options['fragment'];
  }

  // Append the query.
  $options['query']['q'] = $path;
  $path = basename($_SERVER["SCRIPT_FILENAME"]) . (strpos($path, '?') !== FALSE ? '&' : '?') . drupal_http_build_query($options['query']);

  // Reassemble.
  return $path . $options['fragment'];
}

/**
 * l() replacement.
 */
function l($text, $path, array $options = array()) {

  // Merge in defaults.
  $options += array(
    'attributes' => array(),
    'html' => FALSE,
  );

  // Remove all HTML and PHP tags from a tooltip. For best performance, we act only
  // if a quick strpos() pre-check gave a suspicion (because strip_tags() is expensive).
  if (isset($options['attributes']['title']) && strpos($options['attributes']['title'], '<') !== FALSE) {
    $options['attributes']['title'] = strip_tags($options['attributes']['title']);
  }

  // The result of url() is a plain-text URL. Because we are using it here
  // in an HTML argument context, we need to encode it properly.
  return '<a href="' . check_plain(url($path, $options)) . '"' . drupal_attributes($options['attributes']) . '>' . ($options['html'] ? $text : check_plain($text)) . '</a>';
}

/**
 * Return safe string.
 */
function check_plain($text) {
  return htmlspecialchars($text, ENT_QUOTES, 'UTF-8');
}

/**
 * Build attributes string.
 */
function drupal_attributes(array $attributes = array()) {
  foreach ($attributes as $attribute => &$data) {
    $data = implode(' ', (array) $data);
    $data = $attribute . '="' . check_plain($data) . '"';
  }
  return $attributes ? ' ' . implode(' ', $attributes) : '';
}

/**
 * Add css replacement.
 */
function drupal_add_css($file = NULL, $media = 'all', $options = array()) {
  static $css = array();
  if (empty($css[$media])) {
    $css[$media] = array();
  }

  if (!empty($file)) {
    $file = minid_path('theme', $file);
    if (!isset($css[$media][$file])) {
      if (!file_exists($file)) {
        die('file [' . $file . '] not found.');
      }
      $css[$media][$file] = $options;
    }
  }
  return $css;
}

/**
 * Add js replacement.
 */
function drupal_add_js($file = NULL, $options = array()) {
  global $drupal_js;
  static $js = array(
    'files' => array(),
    'settings' => array(),
  );

  // Process settings.
  if (is_array($file)) {
    $js['settings'] = array_merge_recursive($js['settings'], $file);
    return $js;
  }

  // Transform Drupal js into drupoal path.
  if (isset($drupal_js[$file])) {
    if ($drupal_js[$file] == FALSE) {
      return;
    }
    // 0 => file_path, 1 => array of dependencies.
    $file_options = $drupal_js[$file];
    if (!empty($file_options['requires'])) {
      foreach ($file_options['requires'] as $dependency) {
        drupal_add_js($dependency);
      }
    }
    $file = $file_options['file'];
  }
  elseif (!empty($file)) {
    $file = minid_path('theme', $file);
  }

  // Add js to the list.
  if (!empty($file) && !isset($js['files'][$file])) {
    if (!file_exists($file)) {
      die('file [' . $file . '] not found.');
    }
    $js['files'][$file] = $options;
  }
  return $js;
}

// ========================================= DEVEL module.
/**
 * Saves krumo html using output buffering.
 *
 * @see devel module.
 */
function krumo_ob($object) {
  ob_start();
  krumo($object);
  $output = ob_get_contents();
  ob_end_clean();
  return $output;
}

/**
 * kpr() + die.
 */
function kpr($content, $die = TRUE) {
  krumo($content);
  if ($die) {
    die('Exit reason: kpr().');
  }
}

/**
 * dpm().
 */
function dpm($content, $name = FALSE) {
  $_SESSION['messages'][] = array($content, $name);
}

// ======================================= MINIFY module.
/**
 * Helper function to add tag key and value for further replacement.
 */
function _minify_reserve_place($content) {
  global $placeholders;
  $placeholder = '%' . REPLACEMENT_HASH . count($placeholders) . '%';
  $placeholders[$placeholder] = $content;
  return $placeholder;
}

/**
 * Remove HTML comments (not containing IE conditional comments).
 */
function _minify_html_html_comment($string) {
  return (0 === strpos($string[1], '[') || false !== strpos($string[1], '<!['))
    ? $string[0]
    : '';
}

/**
 * Helper function to add place holder for <iframe> tag.
 */
function _minify_html_iframe_callback($m) {
  $iframe = preg_replace('/^\\s+|\\s+$/m', '', $m[0]);
  return _minify_reserve_place($iframe);
}

/**
 * Helper function to add place holder for <script> tag.
 */
function _minify_html_script_callback($m) {
  $search = array(
    '!/\*.*?\*/!s',     // remove multi-line comment
    '/^\\s+|\\s+$/m',   // trim each line
    '/\n(\s*\n)+/',     // remove multiple empty line
  );
  $replace = array('', "\n", "\n");
  $script = preg_replace($search, $replace, $m[0]);

  return _minify_reserve_place($script);
}

/**
 * Helper function to add place holder for <style> tag.
 */
function _minify_html_style_callback($m) {
  $search = array(
    '!/\*.*?\*/!s',   // remove multiline comment
    '/^\\s+|\\s+$/m'  // trim each line
  );
  $replace = array('');
  $style = preg_replace($search, $replace, $m[0]);
  return _minify_reserve_place($style);
}

/**
 * Helper function to add place holder for <textarea> and <pre> tag.
 */
function _minify_html_callback($m){
  return _minify_reserve_place($m[0]);
}

/**
 * Helper function to minify HTML.
 */
function _minify_html($buffer) {

  /* Replace <textarea> with placeholder */
  $buffer = preg_replace_callback('/\\s*<textarea(\\b[^>]*?>[\\s\\S]*?<\\/textarea>)\\s*/i', '_minify_html_callback', $buffer);

  /* Replace <pre> with placeholder */
  $buffer = preg_replace_callback('/\\s*<pre(\\b[^>]*?>[\\s\\S]*?<\\/pre>)\\s*/i', '_minify_html_callback', $buffer);

  /* Replace <iframe> with placeholder */
  $buffer = preg_replace_callback('/\\s*<iframe(\\b[^>]*?>[\\s\\S]*?<\\/iframe>)\\s*/i', '_minify_html_iframe_callback', $buffer);

  /* Replace <script> with placeholder */
  $buffer = preg_replace_callback('/\\s*<script(\\b[^>]*?>[\\s\\S]*?<\\/script>)\\s*/i', '_minify_html_script_callback', $buffer);

  /* Replace <style> with placeholder */
  $buffer = preg_replace_callback('/\\s*<style(\\b[^>]*?>[\\s\\S]*?<\\/style>)\\s*/i', '_minify_html_style_callback', $buffer);

  /* Remove HTML comment */
  //$buffer = preg_replace_callback('/<!--([\\s\\S]*?)-->/', '_minify_html_html_comment', $buffer);

  $search = array(
    '/\>[^\S ]+/s',                 // remove whitespaces after tags, except space
    '/[^\S ]+\</s',                 // remove whitespaces before tags, except space
    '/(\s)+/s',                     // shorten multiple whitespace sequences
    '/\\s+(<\\/?(?:area|base(?:font)?|blockquote|body'
        .'|caption|center|col(?:group)?|dd|dir|div|dl|dt|fieldset|form'
        .'|frame(?:set)?|h[1-6]|head|hr|html|legend|li|link|map|menu|meta'
        .'|ol|opt(?:group|ion)|p|param|t(?:able|body|head|d|h||r|foot|itle)'
        .'|ul)\\b[^>]*>)/i',        // remove whitespaces around block/undisplayed elements
    '/^\\s+|\\s+$/m',               // trim each line
  );

  $replace = array(
    '>',        // remove whitespaces after tags, except space
    '<',        // remove whitespaces before tags, except space
    '\\1',      // shorten multiple whitespace sequences
    '$1',       // remove whitespaces around block/undisplayed elements
    '',         // trim each line
  );

  $buffer = preg_replace($search, $replace, $buffer);

  /* Find and replace <textarea>, <pre>, <iframe>, <script> and <style> place holders values */
  global $placeholders;
  if (!empty($placeholders)) {
    $buffer = str_replace(array_keys($placeholders), array_values($placeholders), $buffer);
  }

  return $buffer;
}

/*$path = !empty($_GET['path']) ? $_GET['path'] : FALSE;
$width = !empty($_GET['width']) ? $_GET['width'] : FALSE;
$height = !empty($_GET['height']) ? $_GET['height'] : FALSE;
image_start($path, $width, $height);*/