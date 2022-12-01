<?php

/**
 * @file
 * Definition of the 'html' panel style.
 */

// Plugin definition
$plugin = array(
  'title' => t('Site Common: HTML Style'),
  'description' => t('Display the pane or region with wrapped in HTML.'),
  'render region' => 'site_common_html_style_render_region',
  'settings form' => 'site_common_html_style_settings_form',
  'weight' => -5,
);

/**
 * Settings form builder.
 */
function site_common_html_style_settings_form($conf) {
  $form['selector'] = array(
    '#title' => t('CSS wrapper selector', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'textfield',
    '#default_value' => !empty($conf['selector']) ? $conf['selector'] : '',
  );
  return $form;
}

/**
 * Render callback.
 */
function theme_site_common_html_style_render_region($vars) {
  $conf = $vars['settings'];
  $tags = site_common_parse_selector($conf['selector']);

  $value = '[value]';
  foreach (array_reverse($tags) as $tag) {
    $tag['#value'] = $value;
    $value = theme('html_tag', array('element' => $tag));
  }

  $html = implode($vars['panes']);
  $html = str_replace('[value]', $html, $value);
  return $html;
}
