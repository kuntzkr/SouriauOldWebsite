<?php
/**
 * @file
 * Core base functions.
 */

// ================================= Debug functions and utils.

/**
 * Info file parse.
 */
function minid_info_file($filepath) {
  return parse_ini_file($filepath);
}

/**
 * Sampling function.
 */
function minid_sample($entity_type, $bundle, $variant = FALSE) {
  static $samples = [];

  // Load sample if not yet.
  if (!isset($samples[$entity_type][$bundle])) {
    $file = 'samples/' . $entity_type . '__' . $bundle . '.inc';
    if (file_exists($file)) {
      require_once $file;
      if (!isset($sample)) {
        die('sample [' . $file . '] is empty.');
      }
      if (isset($view_modes)) {
        $sample['#view_modes'] = $view_modes;
      }
      $samples[$entity_type][$bundle] = [
        'sample' => $sample,
        'variants' => !empty($variants) ? $variants : [],
      ];
    }
    else {
      die('sample [' . $file . '] not found.');
    }
  }

  if (empty($variant)) {
    return $samples[$entity_type][$bundle]['sample'];
  }
  elseif (isset($samples[$entity_type][$bundle]['variants'][$variant])) {
    return $samples[$entity_type][$bundle]['variants'][$variant] + $samples[$entity_type][$bundle]['sample'];
  }
  else {
    die('sample [' . $file . '] variant [' . $variant . '] not found.');
  }
}

// ================================= Core theme related functions.
/**
 * Image process function.
 */
function minid_image_print($source, $width = FALSE, $height = FALSE) {

  $size = getimagesize($source);
  $_width = $size[0];
  $_height = $size[1];
  $chunks = explode('.', $source);
  $ext = str_replace('jpg', 'jpeg', array_pop($chunks));

  // Normal images.
  if (empty($width) && empty($height)) {
    $content = file_get_contents($source);
    header("Content-type: " . $size['mime']);
    print $content;
    die;
  }
  // Scaled images.
  elseif (empty($height)) {
    $scale = $width / $_width;
    $height = (int) round($_height * $scale);
  }
  elseif (empty($width)) {
    $scale = $height / $_height;
    $width = (int) round($_width * $scale);
  }
  // Scale + crop.
  else {
    $crop = [
      'width' => $width,
      'height' => $height,
    ];

    // Get scales.
    $scale_width = $width / $_width;
    $scale_height = $height / $_height;

    $scale = ($scale_width > $scale_height) ?
      $scale_width :
      $scale_height;

    $crop['x'] = ($_width * $scale - $width) / 2;
    $crop['y'] = ($_height * $scale - $height) / 2;

    $width = (int) round($_width * $scale);
    $height = (int) round($_height * $scale);
  }

  // Resize image to new dimensions.
  $image = (object) [
    'source' => $source,
    'info' => [
      'extension' => $ext,
      'width' => $_width,
      'height' => $_height,
    ],
  ];

  // Resize.
  $res = image_gd_load($image);
  $res = image_gd_resize($image, $width, $height);

  // Crop.
  if (!empty($crop)) {
    image_gd_crop($image, $crop['x'], $crop['y'], $crop['width'], $crop['height']);
  }

  // Output.
  header("Content-type: " . $size['mime']);
  $function = 'image' . $ext;
  if (function_exists($function)) {
    $quality = ($ext == 'png') ? 0 : 100;
    $function($image->resource, NULL, $quality);
  }
  die;
}

/**
 * Text field formatter.
 */
function minid_render_field_t($value, $settings = []) {
  return $value;
}

/**
 * Link field formatter.
 */
function minid_render_field_l($value, $settings = []) {
  list($title, $path) = explode('||', $value);
  return l($title, $path, $settings);
}

/**
 * Reference field formatter.
 */
function minid_render_field_r($value, $settings = []) {
  list($entity_type, $entity_id) = explode('||', $value);
  return entity_view($entity_type, $entity_id, $settings[0]);
}

/**
 * Image field formatter.
 */
function minid_render_field_i($value, $settings = []) {
  $source = minid_path('theme', $value);

  // Check if image should be processed.
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
    $url = url('image', ['query' => $query]);
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
 * Render entity content according to view mode.
 */
function minid_render_sample($sample, $view_mode = 'full') {
  if (!isset($sample['#view_modes'][$view_mode])) {
    die('view_mode [' . $view_mode . '] not defined.');
  }

  $content = [];
  $fields = $sample['#view_modes'][$view_mode];
  foreach ($fields as $field_name => $formatter) {
    if (!isset($sample[$field_name])) {
      die('field [' . $field_name . '] not found.');
    }
    else {
      $type = $formatter[0];
      $settings = !empty($formatter[1]) ?
        $formatter[1] :
        [];
      $function = 'minid_render_field_' . $type;
      if (!function_exists($function)) {
        die('formatter [' . $type . '] not supported.');
      }
      $values = is_array($sample[$field_name]) ?
        $sample[$field_name] :
        [$sample[$field_name]];
      foreach ($values as $delta => $value) {
        $content[$field_name][$delta] = !empty($value) ?
          $function($value, $settings) :
          '';
      }
    }
  }

  return $content;
}

/**
 * Return menu registry.
 */
function minid_menu_registry() {
  $menu_registry = $GLOBALS['menu_registry'];
  return $menu_registry + [
    'image' => [
      'type' => MINID_MENU_CALLBACK,
      'page callback' => 'minid_menu_image_callback'
    ],
  ];
}

/**
 * Return theme registry.
 */
function minid_theme_registry() {
  $theme_registry = $GLOBALS['theme_registry'];
  return $theme_registry + [
    'html' => ['template' => 'html'],
  ];
}

/**
 * Returns image style.
 */
function minid_image_style_get($name) {
  $image_styles = $GLOBALS['image_styles'];
  if (!isset($image_styles[$name])) {
    die('no image_style [' . $name . '] found');
  }
  return $image_styles[$name];
}

/**
 * Return theme layout.
 */
function minid_theme_layout_get($name) {
  $layouts = $GLOBALS['layouts'];
  if (empty($layouts[$name])) {
    die('no layout found for [' . $name . ']');
  }
  return $layouts[$name];
}

/**
 * Theme given panel's layout.
 */
function minid_render_layout($name, $panel_content = []) {
  $layout = minid_theme_layout_get($name);

  // Build template name.
  $template = minid_path('theme', 'templates/' . $layout['template'] . '.tpl.php');

  // Build layout content by rendering all blocks.
  $content = [];
  foreach ($layout['regions'] as $region) {
    $content[$region] = [];

    // Get content.
    if (!empty($panel_content[$region])) {
      $blocks = $panel_content[$region];
    }
    elseif (!empty($layout['content']) && !empty($layout['content'][$region])) {
      $blocks = $layout['content'][$region];
    }
    else {
      $blocks = [];
    }
    foreach ($blocks as $block_variables) {
      $block_type = array_shift($block_variables);
      if ($block_type == MINID_BLOCK_PAGE_CONTENT) {
        $content[$region][] = minid_menu_result();
      }
      elseif ($block_type == MINID_BLOCK_ENTITY_VIEW) {
        $content[$region][] = call_user_func_array('entity_view', $block_variables);
      }
      else {
        // Default block is simple theme.
        $content[$region][] = theme($block_type, $block_variables);
      }
    }
  }

  // Merge result into plain html.
  $variables = [
    'content' => [],
  ];
  foreach ($content as $region => $items) {
    $variables['content'][$region] = implode(PHP_EOL, $items);
  }

  // Render layout template.
  $html = theme_render_template($template, $variables);
  return $html;
}

/**
 * Dev's preprocess html.
 */
function _preprocess_html(&$variables) {
  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  $router_item = minid_menu_router_item();

  // Theme wrapper.
  $variables['page'] = minid_render_layout($router_item['wrapper']);

  // Add template variable.
  $variables['page_top'] = '';
  $variables['page_bottom'] = '';
  $variables['language'] = (object) [
    'language' => 'en',
    'dir' => 'ltr',
  ];

  // Add all js from theme info file.
  $info = drupal_parse_info_file(minid_path('theme', 'nes.info'));
  if (!empty($info['scripts'])) {
    foreach ($info['scripts'] as $script_file) {
      if (strpos($script_file, 'html/') === 0) {
        drupal_add_js($script_file);
      }
    }
  }

  // Add all css.
  if (!empty($info['stylesheets']['all'])) {
    foreach ($info['stylesheets']['all'] as $css_file) {
      if (strpos($css_file, 'html/') === 0) {
        drupal_add_css($css_file);
      }
    }
  }
}

/**
 * Dev's postprocess html.
 */
function _postprocess_html(&$variables) {
  $menu_registry = minid_menu_registry();

  $_html = &$variables['_html'];
  $_data = &$variables['_data'];

  // Add template variable.
  $variables['page_top'] = '';
  $variables['page_bottom'] = '';
  $variables['language'] = (object) [
    'language' => 'en',
    'dir' => 'ltr',
  ];

  // Add js settings.
  $ajax_path = [];
  foreach ($menu_registry as $path => $router_item) {
    if ($router_item['type'] == MINID_MENU_AJAX) {
      $ajax_path[$path] = '?q=' . $path;
    }
  }
  drupal_add_js(['minid' => ['ajax_path' => $ajax_path]]);

  // Build styles.
  $variables['styles'] = '';
  foreach (drupal_add_css() as $media => $list) {
    $variables['styles'] .= PHP_EOL . '<style media="' . $media . '">';
    foreach ($list as $file => $options) {
      $variables['styles'] .= PHP_EOL . '@import url("' . $file . '");';
    }
    $variables['styles'] .= PHP_EOL . '</style>';
  }
  $variables['styles'] .= PHP_EOL;

  // Build scripts.
  $variables['scripts'] = '';
  $js = drupal_add_js();
  foreach ($js['files'] as $file => $options) {
    $variables['scripts'] .= PHP_EOL . '<script src="' . $file . '"></script>';
  }
  $variables['scripts'] .= PHP_EOL;

  // Build settings.
  $settings = json_encode($js['settings']);
  $variables['scripts'] .= '<script>jQuery.extend(Drupal.settings, ' . $settings . ');</script>' . PHP_EOL;

  // Check if have messages to print.
  $messages = '';
  if (!empty($_SESSION['messages'])) {
    foreach ($_SESSION['messages'] as $message) {
      $messages .= krumo_ob($message[0]);
    }
  }
  if (!empty($messages)) {
    $variables['page_top'] = $messages;
  }
}

// ===================================== Core menu routing functions.

/**
 * Image callback.
 *
 * This function output result directly to the browser.
 */
function minid_menu_image_callback() {
  $source = !empty($_GET['source']) ? $_GET['source'] : FALSE;
  $width = !empty($_GET['width']) ? $_GET['width'] : FALSE;
  $height = !empty($_GET['height']) ? $_GET['height'] : FALSE;
  minid_image_print($source, $width, $height);
}


/**
 * Panel page callback.
 */
function minid_menu_panel_callback() {
  $router_item = minid_menu_router_item();
  $html = minid_render_layout($router_item['layout'], $router_item['content']);
  return $html;
}

/**
 * Get router item.
 */
function minid_menu_router_item() {
  $menu_registry = minid_menu_registry();
  static $router_item = FALSE;

  // Static cache.
  if (!empty($router_item)) {
    return $router_item;
  }

  // Check that menu exists.
  $q = !empty($_GET['q']) ?
    $_GET['q'] :
    'home';
  $path = $q;
  $chunks = explode('/', $path);
  $args = [];
  $router_item = FALSE;
  while (!empty($path)) {
    if (!empty($menu_registry[$path])) {
      $router_item = $menu_registry[$path];
      // We found a match.
      break;
    }
    array_unshift($args, array_pop($chunks));
    $path = implode('/', $chunks);
  }

  // Check if menu entry exists.
  if (empty($router_item)) {
    die('menu entry [' . $q . '] not found.');
  }
  else {
    $router_item['page arguments'] = $args;
  }

  // Validate router type.
  $valid = FALSE;

  // Panel pages.
  if ($router_item['type'] == MINID_MENU_PANEL) {
    if (empty($router_item['wrapper'])) {
      die('panel wrapper not set for [' . $path . '].');
    }
    if (empty($router_item['layout'])) {
      die('panel layout not set for [' . $path . '].');
    }
    $router_item['theme'] = minid_theme_layout_get($router_item['layout']);
    $router_item['page callback'] = 'minid_menu_panel_callback';
    $valid = TRUE;
  }
  // Ajax pages.
  elseif ($router_item['type'] == MINID_MENU_AJAX) {
    $function = 'menu_' . $router_item['type'] . '_' . str_replace('/', '_', $path);
    if (!function_exists($function)) {
      die('menu callback [' . $function . '] not found.');
    }
    $router_item['page callback'] = $function;
    $valid = TRUE;
  }
  // Callback pages.
  elseif ($router_item['type'] == MINID_MENU_CALLBACK) {
    if (!function_exists($router_item['page callback'])) {
      die('menu callback [' . $function . '] not found.');
    }
  }
  else {
    die('unsupported page type [' . $router_item['type'] . ']');
  }

  return $router_item;
}

/**
 * Saves return menu result.
 */
function minid_menu_result() {
  static $menu_result = FALSE;

  // Static cache.
  if (!empty($menu_result)) {
    return $menu_result;
  }

  $router_item = minid_menu_router_item();
  if (!empty($router_item['page callback'])) {
    $menu_result = call_user_func_array($router_item['page callback'], $router_item['page arguments']);
  }
  else {
    $menu_result = [];
  }
  return $menu_result;
}

/**
 * Entry point for page processing.
 */
function minid_start() {

  // Get router item.
  $router_item = minid_menu_router_item();

  // Process callback.
  switch ($router_item['type']) {
    case MINID_MENU_CALLBACK:
      // Execute menu handler.
      $menu_result = minid_menu_result();
      die('callback type pages should not get here.');

    case MINID_MENU_PANEL:
      // Add normal page resources.
      drupal_add_js('jquery');
      drupal_add_js('jquery.once');
      drupal_add_js('drupal');
      drupal_add_js('qtools.base');
      drupal_add_js('core.jquerysign');

      // Execute menu handler.
      $menu_result = minid_menu_result();

      // Theme html.
      $output = _minify_html(theme('html', [
        'router_item' => $router_item,
        'menu_result' => $menu_result,
      ]));
      break;

    case MINID_MENU_AJAX:
      // Add validation header.
      header('X-Drupal-Ajax-Token: 1');
      // Get resulted commands and pass them as response.
      $menu_result = minid_menu_result();
      $output = json_encode($menu_result);
      break;
  }

  print $output;
}
