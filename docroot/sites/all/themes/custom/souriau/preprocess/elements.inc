<?php

/**
 * @file
 * Form elements theming.
 */

/**
 * Implements theme_select.
 */
function souriau_select($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'size'));
  _form_set_class($element, array('form-select'));

  if (isset($element['#extra_attributes'])) {
    return '<select' . drupal_attributes($element['#attributes']) . '>' . souriau_select_options($element) . '</select>';
  }
  return '<select' . drupal_attributes($element['#attributes']) . '>' . form_select_options($element) . '</select>';
}

/**
 * Overridden core theme_form_element.
 */
function souriau_form_element($variables) {
  $element = &$variables['element'];

  $exclude_wrapper = [
    'edit-field-postal-address-country-selective',
    'edit-field-type-value-selective',
    'edit-field-postal-address-administrative-area-selective',
    'edit-field-distributor-brand-value-selective',
    'edit-dc-keyword',
    'edit-results',
  ];
  if (($element['#array_parents'][0] != 'types' && isset($element['#ajax']) && $element['#ajax']['callback'] == 'souriau_dc_search_callback') || (isset($element['#id']) && in_array($element['#id'], $exclude_wrapper))) {
    // Do not wrap elements for distributor page exposed filters.
    return $element['#children'];
  }

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
    if (isset($element['#webform_component'])) {
      $attributes['class'][] = 'webform-prefill-exclude';
    }
  }

  // Assigning the form-text-field class to required elements.
  $textfield_types = ['search_autocomplete', 'webform_email'];
  if (!empty($element['#type']) && in_array($element['#type'], $textfield_types)) {
    $attributes['class'][] = 'form-type-textfield';
  }

  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(
      ' ' => '-',
      '_' => '-',
      '[' => '-',
      ']' => '',
    ));
  }
  // We require isset check because views forms try to render VBO checkbox
  // on placeholder replacement.
  $error = isset($element['#parents']) ? form_get_error($element) : NULL;
  if ($error !== NULL && !empty($element['#validated'])) {
    $attributes['class'][] = 'error';
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }

  if (isset($element['#souriau_settings'])) {
    if (isset($element['#souriau_settings']['wrapper-align'])) {
      $attributes['class'][] = 'a-' . $element['#souriau_settings']['wrapper-align'];
    }
  }

  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'screen_reader':
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      $output .= ' ' . theme('form_element_label', $variables) . "\n";

      break;

  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  // Set error message.
  if ($error !== NULL && $element['#name'] !== 'pass' && $element['#name'] !== 'login_pass[pass]' && !in_array($element['#type'], ['radio', 'checkbox'])) {
    $output .= '<div class="error-msg">' . t($error, [], ['context' => 'SOURIAU: other']) . '</div>';
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * Overridden core theme_form_element_label.
 */
function souriau_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();

  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }

  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';

  $title = filter_xss_admin($element['#title']);

  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $title_class = preg_replace('/\s*/', '', $title);
    $title_class = strtolower($title_class);
    $attributes['class'] = ['option', $title_class];
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }

  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }

  $title = $t('!title !required', array('!title' => $title, '!required' => $required));
  if ($element['#title_display'] == 'screen_reader') {
    $title = '<span class="screen-reader-text">' . $title . '</span>';
  }
  // The leading whitespace helps visually separate fields from inline labels.
  return ' <label' . drupal_attributes($attributes) . '>' . $title . "</label>\n";
}

/**
 * Overridden core theme_textfield.
 */
function souriau_textfield($variables) {
  $element = $variables['element'];
  $type = isset($element['#datatype']) ? $element['#datatype'] : 'text';
  $element['#attributes']['type'] = $type;
  element_set_attributes($element, array(
    'id',
    'name',
    'value',
    'size',
    'maxlength',
  ));
  if ($type != 'number') {
    _souriau_form_set_class($element, array('form-text'));
  }

  $extra = '';
  if ($element['#autocomplete_path'] && !empty($element['#autocomplete_input'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';

    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#autocomplete_input']['#id'];
    $attributes['value'] = $element['#autocomplete_input']['#url_value'];
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }

  $output = '<input' . drupal_attributes($element['#attributes']) . ' />';

  return $output . $extra;
}

/**
 * Overridden core theme_checkbox.
 */
function souriau_checkbox($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'checkbox';
  element_set_attributes($element, [
    0 => 'id',
    1 => 'name',
    '#return_value' => 'value',
  ]);

  // Unchecked checkbox has #value of integer 0.
  if (!empty($element['#checked']) || (isset($element['#default_value']) && ($element['#return_value'] == $element['#default_value']))) {
    $element['#attributes']['checked'] = TRUE;
  }
  if (isset($element['#title'])) {
    _souriau_form_set_class($element, [
      'form-checkbox',
      'check-' . drupal_html_class($element['#title']),
    ]);
  }

  if ($element['#array_parents'][0] != 'types' && $element['#ajax']['callback'] == 'souriau_dc_search_callback') {
    return '<li><label><input' . drupal_attributes($element['#attributes']) . ' /><span><i class="fa fa-plus"></i>' . $element['#title'] . '</span></label></li>';
  }
  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Overridden core theme_textarea.
 */
function souriau_textarea($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id', 'name', 'cols', 'rows'));
  _souriau_form_set_class($element, array('form-textarea'));

  $wrapper_attributes = array(
    'class' => array('form-textarea-wrapper'),
  );

  // Add resizable behavior.
  if (!empty($element['#resizable'])) {
    drupal_add_library('system', 'drupal.textarea');
    $wrapper_attributes['class'][] = 'resizable';
  }

  $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
  $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
  $output .= '</div>';
  return $output;
}

/**
 * Overridden core theme_password.
 */
function souriau_password($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'password';
  element_set_attributes($element, array('id', 'name', 'size', 'maxlength'));
  _souriau_form_set_class($element, array('form-text'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Overridden core theme_button.
 */
function souriau_button($variables) {
  $element = $variables['element'];

  if (!isset($element['#button_type'])) {
    $element['#button_type'] = isset($element['#souriau_settings']['b_type']) ? $element['#souriau_settings']['b_type'] : 'submit';
  }
  $element['#attributes']['type'] = isset($element['#souriau_settings']['b_type']) ? $element['#souriau_settings']['b_type'] : 'submit';

  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'btn';
  if (isset($element['#souriau_settings']['color'])) {
    $element['#attributes']['class'][] = $element['#souriau_settings']['color'] . '-btn';
  }
  if (isset($element['#souriau_settings']['hover_color'])) {
    $element['#attributes']['class'][] = $element['#souriau_settings']['hover_color'] . '-btn-hover';
  }
  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#ea']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }

  $output = '<button' . drupal_attributes($element['#attributes']) . '>';

  // Set elements after <button> tag.
  if (!empty($element['#souriau_settings']['#elements'])) {
    $output .= _souriau_souriau_settings_elements_render($element['#souriau_settings']['#elements']);
  }

  if (isset($element['#value'])) {
    $output .= $element['#value'];
  }
  $output .= '</button>';

  if (isset($element['#souriau_settings']['link']) && $element['#souriau_settings']['b_type'] == 'button') {
    $output = l($output, $element['#souriau_settings']['link'], [
      'html' => TRUE,
    ]);
  }
  return $output;
}

/**
 * Overridden core theme_container.
 *
 * Remove form-wrapper class.
 *
 * @recheck_implementation.
 */
function souriau_container($variables) {
  $element = $variables['element'];
  if (isset($element['#type']) && $element['#type'] == 'actions') {
    return souriau_actions($variables);
  }
  // Ensure #attributes is set.
  $element += array('#attributes' => array());

  // Special handling for form elements.
  if (isset($element['#array_parents'])) {
    // Assign an html ID.
    if (!isset($element['#attributes']['id'])) {
      $element['#attributes']['id'] = $element['#id'];
    }
  }
  return '<div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';
}

/**
 * Overridden core theme_actions.
 */
function souriau_actions($variables) {
  $element = $variables['element'];
  _souriau_form_set_class($element, ['form-block']);
  if (isset($element['#souriau_settings']['text_align'])) {
    _souriau_form_set_class($element, ['text-' . $element['#souriau_settings']['text_align']]);
  }
  if (isset($element['#souriau_settings']['align'])) {
    $wrapper_attributes = [
      'class' => ['align-btn-' . $element['#souriau_settings']['align']],
    ];
    $element['#children'] = '<div' . drupal_attributes($wrapper_attributes) . '>' . $element['#children'] . '</div>';
  }
  return '<div' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</div>';

}

/**
 * Render select options.
 *
 * Added extra_attributes to options.
 */
function souriau_select_options($element, $choices = NULL) {
  if (!isset($choices)) {
    $choices = $element['#options'];
  }
  // array_key_exists() accommodates the rare event where $element['#value'] is NULL.
  // isset() fails in this situation.
  $value_valid = isset($element['#value']) || array_key_exists('#value', $element);
  $value_is_array = $value_valid && is_array($element['#value']);
  $options = '';
  foreach ($choices as $key => $choice) {
    if (is_array($choice)) {
      $options .= '<optgroup label="' . check_plain($key) . '">';
      $options .= souriau_select_options($element, $choice);
      $options .= '</optgroup>';
    }
    elseif (is_object($choice)) {
      $options .= souriau_select_options($element, $choice->option);
    }
    else {
      $key = (string) $key;
      if ($value_valid && (!$value_is_array && (string) $element['#value'] === $key || ($value_is_array && in_array($key, $element['#value'])))) {
        $selected = ' selected="selected"';
      }
      else {
        $selected = '';
      }

      $options .= '<option value="' . check_plain($key) . '"' . drupal_attributes($element['#extra_attributes'][$key]) . $selected . '>' . check_plain($choice) . '</option>';
    }
  }
  return $options;
}

/**
 * Sets a form element's class attribute.
 */
function _souriau_form_set_class(&$element, $class = array()) {
  if (!empty($class)) {
    if (!isset($element['#attributes']['class'])) {
      $element['#attributes']['class'] = array();
    }
    $element['#attributes']['class'] = array_merge($element['#attributes']['class'], $class);
  }
  // This function is invoked from form element theme functions, but the
  // rendered form element may not necessarily have been processed by
  // form_builder().
  if (!empty($element['#required'])) {
    $element['#attributes']['class'][] = 'required';
  }
}

/**
 * Helper function for render elements inside button tag.
 */
function _souriau_souriau_settings_elements_render($elements) {
  $output = '';
  foreach ($elements as $tag => $item) {
    $rendered_item = drupal_render($item);
    if (!empty($rendered_item)) {
      $output = $rendered_item;
    }
    else {
      $output = '<' . $tag . drupal_attributes($elements[$tag]['#attributes']) . '>';
      $output .= isset($elements[$tag]['#value']) ? $elements[$tag]['#value'] : '';
      $output .= '</' . $tag . '>';
    };
  }
  return $output;
}

/**
 * Implements theme_fieldset.
 */
function souriau_fieldset($variables) {
  $element = $variables['element'];
  element_set_attributes($element, array('id'));

  $element['#attributes'] = isset($element['#attributes']) ? $element['#attributes'] : [];

  $output = '<fieldset' . drupal_attributes($element['#attributes']) . '>';
  if (!empty($element['#title'])) {
    // Always wrap fieldset legends in a SPAN for CSS positioning.
    $output .= '<legend>' . $element['#title'] . '</legend>';
  }
  $class = isset($element['#souriau_settings']['content_wrapper_class']) ?
    implode(' ', $element['#souriau_settings']['content_wrapper_class']) :
    'fieldset-wrapper';
  $output .= '<div class="' . $class . '">';

  if (!empty($element['#description'])) {
    $output .= '<div class="fieldset-description">' . $element['#description'] . '</div>';
  }
  $output .= $element['#children'];
  if (isset($element['#value'])) {
    $output .= $element['#value'];
  }
  $output .= '</div>';
  $output .= "</fieldset>\n";
  return $output;
}

/**
 * Implements theme_form.
 */
function souriau_form($variables) {
  $element = $variables['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }
  // Anonymous DIV to satisfy XHTML compliance.
  return '<div class="b-form"><form' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</form></div>';
}

/**
 * Implements theme_link.
 */
function souriau_link($variables) {
  // Merge in defaults.
  $variables['options'] += [
    'attributes' => [],
    'html' => FALSE,
  ];

  return '<a href="' . check_plain(url($variables['path'], $variables['options'])) . '"' . drupal_attributes($variables['options']['attributes']) . '>' . ($variables['options']['html'] ? $variables['text'] : check_plain($variables['text'])) . '</a>';
}

/**
 * Implements theme_links.
 */
function souriau_links($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';
  $souriau_setting = '';

  if (count($links) > 0) {
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      if (isset($link['souriau_settings'])) {
        $souriau_setting = $link['souriau_settings'];
        unset($link['souriau_settings']);
      }

      $class = array($key);

      // Add first, last and active classes to the list of links to help out
      // themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
        && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for
        // adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }
      if (!empty($souriau_setting)) {
        $output .= theme('header_menu_level_2', [
          'links' => $souriau_setting['sub_2'],
          'parent' => $link,
        ]);
      }

      $i++;
      $souriau_setting = '';
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Overrides the theme_webform_element.
 */
function souriau_webform_element($variables) {
  return souriau_form_element($variables);
}

/**
 * Overrides the theme_webform_email.
 */
function souriau_webform_email($variables) {
  $element = $variables['element'];

  // This IF statement is mostly in place to allow our tests to set type="text"
  // because SimpleTest does not support type="email".
  if (!isset($element['#attributes']['type'])) {
    $element['#attributes']['type'] = 'email';
  }

  // Convert properties to attributes on the element if set.
  foreach (['id', 'name', 'value', 'size'] as $property) {
    if (isset($element['#' . $property]) && $element['#' . $property] !== '') {
      $element['#attributes'][$property] = $element['#' . $property];
    }
  }
  _souriau_form_set_class($element, array('form-text', 'form-email'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

/**
 * Overrides theme_file_widget_multiple.
 */
function souriau_file_widget_multiple($variables) {
  $element = $variables['element'];

  // Get our list of widgets in order (needed when the form comes back after
  // preview or failed validation).
  $widgets = array();
  foreach (element_children($element) as $key) {
    $widgets[] = &$element[$key];
  }

  $output = '';
  foreach ($widgets as $key => &$widget) {
    // Delay rendering of the buttons, so that they can be rendered later in the
    // "operations" column.
    $operations_elements = array();
    foreach (element_children($widget) as $sub_key) {
      if (isset($widget[$sub_key]['#type']) && $widget[$sub_key]['#type'] == 'submit') {
        if ($sub_key == 'remove_button' || $sub_key == 'upload_button') {
          $widget[$sub_key]['#souriau_settings'] = [
            'hover_color' => 'orange',
          ];
        }

        hide($widget[$sub_key]);
        $operations_elements[] = &$widget[$sub_key];
      }
    }

    // Delay rendering of the "Display" option and the weight selector, so that
    // each can be rendered later in its own column.
    if ($element['#display_field']) {
      hide($widget['display']);
    }
    hide($widget['_weight']);

    // Render everything else together in a column, without the normal wrappers.
    $widget['#theme_wrappers'] = array();
    $information = drupal_render($widget);

    // Render the previously hidden elements, using render() instead of
    // drupal_render(), to undo the earlier hide().
    $operations = '';
    foreach ($operations_elements as $operation_element) {
      $operations .= render($operation_element);
    }

    // Arrange the row with all of the rendered columns.
    $output .= "<div class='item'>";
    $output .= $information . $operations;
    $output .= "</div>";
  }

  $output .= drupal_render_children($element);
  return $output;
}
