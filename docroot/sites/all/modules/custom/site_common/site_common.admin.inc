<?php
/**
 * @file
 * Admin forms.
 */

/**
 * Settings form builder.
 */
function site_common_admin_settings_form() {
  $form = array();

  // Root element to store settings.
  $form['site_common_settings'] = array(
    '#tree' => TRUE,
  );

  // Get list os image styles (extracting mobile styles).
  $list = image_styles();
  foreach ($list as $name => $style) {
    if (strpos($name, '__m') == strlen($name) - 3) {
      continue;
    }
    $mobile_style = $name . '__m';
    $label = empty($list[$mobile_style])
      ? $style['label']
      : $style['label'] . ' [M]';
    $options[$name] = $label;
  }

  // Lazy Load images settings.
  $form['site_common_settings']['lazy_load'] = array(
    '#title' => t('Images Lazy Load', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'fieldset',
    '#description' => t('You may want to override %behavior behavior in your theme.', array(
      '%behavior' => 'Drupal.behaviors.site_common_lazy_load',
    ), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['site_common_settings']['lazy_load']['enabled'] = array(
    '#title' => t('Enable images lazy load', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'checkbox',
    '#description' => t('If disabled, settings below will have no effect.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => _site_common_settings('lazy_load', 'enabled'),
  );
  $form['site_common_settings']['lazy_load']['threshold'] = array(
    '#title' => t('Mobile treshold', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'textfield',
    '#description' => t('This is max width in which mobile images will be loaded (if available).', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => _site_common_settings('lazy_load', 'threshold', SITE_COMMON_VAR_DEFAULT_MOBILE_THRESHOLD),
    '#element_validate' => array('element_validate_integer'),
    '#required' => TRUE,
  );
  $form['site_common_settings']['lazy_load']['image_styles'] = array(
    '#title' => t('Image styles', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#description' => t('If style have mobile version it wil be displayed as [M].', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#options' => $options,
    '#default_value' => _site_common_settings('lazy_load', 'image_styles', array()),
  );
  $form['site_common_settings']['lazy_load']['placeholder_styles'] = array(
    '#title' => t('Placeholder styles', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'select',
    '#multiple' => TRUE,
    '#description' => t('Specify which styles should have blank placeholder instead of empty src (this prevents page from jumping on image load, but increase page size).', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#options' => $options,
    '#default_value' => _site_common_settings('lazy_load', 'placeholder_styles', array()),
  );

  // JQuery Mobile images settings.
  $form['site_common_settings']['jquery_mobile'] = array(
    '#title' => t('jQuery Mobile', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'fieldset',
    '#description' => t('jQuery Mobile intergarion', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['site_common_settings']['jquery_mobile']['enabled'] = array(
    '#title' => t('Enable jQM integration', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'checkbox',
    '#description' => t('This will add script to front page that will fix behaviors for jQuery Mobile sites.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => _site_common_settings('jquery_mobile', 'enabled'),
  );
  $form['site_common_settings']['jquery_mobile']['debug'] = array(
    '#title' => t('Enable console messages', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'checkbox',
    '#description' => t('This will log most important messages to the console.log().', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => _site_common_settings('jquery_mobile', 'debug'),
  );
  $form['site_common_settings']['jquery_mobile']['themes'] = array(
    '#title' => t('Supported themes', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'select',
    '#options' => qtools_api__array_extract(list_themes(), 'name'),
    '#multiple' => TRUE,
    '#description' => t('This will add script to front page that will fix behaviors for jQuery Mobile sites.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => _site_common_settings('jquery_mobile', 'themes'),
  );
  $form['site_common_settings']['jquery_mobile']['exclude_url'] = array(
    '#title' => t('jQM excluded url pattern', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'textfield',
    '#description' => t('Enter RegEx to exclude admin (or other pages) from being served through jQM.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => _site_common_settings('jquery_mobile', 'exclude_url', SITE_COMMON_VAR_JQM_EXCLUDE),
  );
  $form['site_common_settings']['jquery_mobile']['exclude_form'] = array(
    '#title' => t('jQM excluded form ids', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#type' => 'textarea',
    '#description' => t('Enter list of form ids, that should not be served through jQM.', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
    '#default_value' => _site_common_settings('jquery_mobile', 'exclude_form'),
  );

  return system_settings_form($form);
}
