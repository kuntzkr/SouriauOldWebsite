<?php
/**
 * @file
 * Containt hooks and field API logic.
 */

/**
 * Common base widgets.
 */
function site_common_field_widget_info() {
  $info['site_common_select'] = array(
    'label' => t('Site Common Select'),
    'description' => t('Attach selects to text and int based fields'),
    'field types' => array('number_integer', 'text_long', 'text'),
    'settings' => array(
      'options' => '0|Default',
      'source' => NULL,
    ),
    'weight' => 10,
  );
  return $info;
}

/**
 * Widget settings form.
 */
function site_common_field_widget_settings_form($field, $instance) {
  $widget = $instance['widget'];
  $settings = $widget['settings'];
  $sources = module_invoke_all('site_common_field_widget_select_options');
  array_unshift($sources, t('-- None --'));

  if ($widget['type'] == 'site_common_select') {
    $form['options'] = array(
      '#type' => 'textarea',
      '#title' => t('Available options'),
      '#default_value' => $settings['options'],
      '#required' => TRUE,
    );
    $form['source'] = array(
      '#type' => 'select',
      '#title' => t('Available Sources'),
      '#options' => $sources,
      '#default_value' => $settings['source'],
    );
  }
  return $form;
}

/**
 * Helper function to get options for select.
 */
function _site_common_field_widget_select_options($settings, $instance) {
  if (!empty($settings['source']) && function_exists($settings['source'])) {
    $options = $settings['source']($instance);
  }
  else {
    $lines = explode(PHP_EOL, $settings['options']);
    $options = array();
    foreach (array_filter($lines) as $line) {
      list($key, $caption) = explode('|', trim($line));
      $options[$key] = t($caption);
    }
  }
  return $options;
}

/**
 * Widget form.
 */
function site_common_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $value = isset($items[$delta]['value']) ? $items[$delta]['value'] : '';
  $settings = $instance['widget']['settings'];

  switch ($instance['widget']['type']) {
    case 'site_common_select':
      $element += array(
        '#type' => 'select',
        '#options' => _site_common_field_widget_select_options($settings, $instance),
        '#default_value' => $value,
      );
      break;
  }
  return array('value' => $element);
}

/**
 * Helper function to get image style for formatter.
 */
function _site_common_field_formatter_image_field_default_preset($instance, $view_mode, $settings = array()) {
  if ($view_mode == 'default') {
    $view_mode = 'full';
  }
  if (!empty($settings['bundle'])) {
    $style = implode('__', array_filter(array(
      $instance['entity_type'],
      $instance['bundle'],
      $instance['field_name'],
      $view_mode,
    )));
  }
  else {
    $style = implode('__', array_filter(array(
      $instance['entity_type'],
      $instance['field_name'],
      $view_mode,
    )));
  }
  return $style;
}

/**
 * Implements hook_field_formatter_info().
 */
function site_common_field_formatter_info() {
  $formatters = array(
    // Image field.
    'site_common_image_field_default' => array(
      'label' => t('Site Common Image', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'field types' => array('image'),
      'settings' => array(
        'image_style' => '',
        'image_link' => '',
        'preset' => '',
        'view_mode' => '',
        'nosize' => TRUE,
        'alter' => FALSE,
        'bundle' => FALSE,
        'url_only' => FALSE,
        'deltas' => '',
      ),
    ),
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function site_common_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];

  $element = array();

  // Settings form for Site common Image formatter.
  if ($display['type'] == 'site_common_image_field_default') {
    $element['deltas'] = array(
      '#title' => t('Deltas', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#description' => t('Deltas to render. Leave blank to render all.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#type' => 'textfield',
      '#size' => 20,
      '#default_value' => $settings['deltas'],
      '#element_validate' => array('element_validate_integer'),
    );

    // Check if we should link image to content.
    $link_types = array(
      'content' => t('Content', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'file' => t('File', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    );
    $element['image_link'] = array(
      '#title' => t('Link image to', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#type' => 'select',
      '#default_value' => $settings['image_link'],
      '#empty_option' => t('Nothing', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#options' => $link_types,
    );

    // Preset value cannot be changed.
    $element['preset'] = array(
      '#type' => 'value',
      '#value' => _site_common_field_formatter_image_field_default_preset($instance, $view_mode),
    );

    // Save view mode.
    $element['view_mode'] = array(
      '#type' => 'value',
      '#value' => $view_mode,
    );

    // Controll size properties strip.
    $element['bundle'] = array(
      '#title' => t('Bundle specific size', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#description' => t('This bundle will have its own preset.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#type' => 'checkbox',
      '#size' => 20,
      '#default_value' => $settings['bundle'],
    );

    // Controll size properties strip.
    $element['nosize'] = array(
      '#title' => t('Remove size', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#description' => t('Remove size properties from resulting image (experimantal).', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#type' => 'checkbox',
      '#size' => 20,
      '#default_value' => $settings['nosize'],
    );

    // If checked, image will be alterable by modules.
    $element['alter'] = array(
      '#title' => t('Alterable', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#description' => t('Allow modules to alter this image.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#type' => 'checkbox',
      '#size' => 20,
      '#default_value' => $settings['alter'],
    );

    // If checked, image will be alterable by modules.
    $element['url_only'] = array(
      '#title' => t('URL only', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#description' => t('Print image as URL for future processing.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      '#type' => 'checkbox',
      '#size' => 20,
      '#default_value' => $settings['url_only'],
    );

  }
  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function site_common_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $summary = array();

  // Settings form for Site common Image formatter.
  if ($display['type'] == 'site_common_image_field_default') {

    // Get preset.
    $preset = $settings['preset'];
    if (!empty($preset)) {
      $preset = _site_common_field_formatter_image_field_default_preset($instance, $view_mode, $settings);
    }

    // Check if this style created.
    $styles = image_styles();
    if (empty($styles[$preset])) {
      $missing = t('(missing)', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
    }
    else {
      $missing = '';
    }

    if (empty($preset)) {
      $summary[] = t('Please open and save settings form.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
    }
    else {
      $summary[] = t('Image style: [!preset] !missing', array('!preset' => $preset, '!missing' => $missing), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
      $summary[] = !empty($settings['deltas']) ?
        t('Deltas: @keys', array('@keys' => $settings['deltas']), array('context' => SITE_COMMON_TCONTEXT_ADMIN)) :
        t('All deltas will be rendered.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
      if (!empty($settings['url_only'])) {
        $summary[] = t('Image will be printed as URL.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
      }
      elseif (!empty($settings['nosize'])) {
        $summary[] = t('Size properties will be stripped from resilting image.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN));
      }
    }
  }
  return implode('<br />', $summary);
}

/**
 * Implements hook_field_formatter_view().
 */
function site_common_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();
  $settings = $display['settings'];

  // Site common image formatter.
  if ($display['type'] == 'site_common_image_field_default') {

    // Calculate deltas.
    $length = 0;
    $deltas = isset($settings['deltas']) ? $settings['deltas'] : NULL;

    // Calculate deltas.
    if (is_numeric($deltas)) {
      // If less than zero then this is number of items to render.
      if ($deltas < 0) {
        $length = -$deltas;
        $deltas = array_keys($items);
      }
      else {
        // If positive -this is direct delta.
        $deltas = array($deltas);
      }
    }
    elseif (empty($deltas)) {
      // If not numeric print all.
      $deltas = array_keys($items);
    }

    // Generate extra context.
    $extra_context = array(
      'entity_type' => $entity_type,
      'entity' => $entity,
      'field' => $field,
      'langcode' => $langcode,
      'display' => $display,
    );

    // Allow modules to alter images if they supports this.
    if ($settings['alter']) {
      drupal_alter('site_common_image_field_default', $items, $deltas, $instance, $extra_context);
    }

    // Render required deltas.
    $rendered_count = 0;
    foreach ($deltas as $key) {

      // Exit if we reached required element count.
      if (!empty($length) && ($rendered_count >= $length)) {
        break;
      }
      $rendered_count++;

      // Get item.
      $item = $items[$key];

      // Fix for empty items.
      if (empty($item['uri'])) {
        $item['uri'] = 'public://image_not_found.png';
      }

      // Pass nosize further,
      // this will be processed by site_common_image_style().
      if (!empty($settings['nosize'])) {
        $item['attributes']['nosize'] = TRUE;
      }

      // Build Path.
      $path = '';
      if ($settings['image_link'] == 'content') {
        $path = entity_uri($entity_type, $entity);
      }
      elseif ($settings['image_link'] == 'file') {
        $path = array(
          'path' => file_create_url($item['uri']),
          'options' => array(),
        );
      }

      // Build element content.
      $preset = empty($settings['view_mode']) ?
        $settings['preset'] :
        _site_common_field_formatter_image_field_default_preset($instance, $settings['view_mode'], $settings);

      // Print img tag.
      if (empty($settings['url_only'])) {
        $element[$key] = array(
          '#theme' => 'image_formatter',
          '#item' => $item,
          '#image_style' => $preset,
          '#path' => $path,
        );
      }
      else {
        // Only print url to image.
        $element[$key] = array(
          '#type' => 'markup',
          '#markup' => image_style_url($preset, $item['uri']),
        );
      }
    }
  }

  return $element;
}
