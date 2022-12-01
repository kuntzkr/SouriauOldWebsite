<?php

/**
 * @file
 * Header CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = array(
  'title' => t('SOURIAU Common: Footer', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'description' => t('SOURIAU Common: Footer', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'content_types' => 'souriau_common_footer',
  'single' => TRUE,
  'render callback' => 'souriau_common_footer_content_type_render',
  'edit form' => 'souriau_common_footer_content_type_edit_form',
  'admin title' => 'souriau_common_footer_content_type_admin_title',
  'hook theme' => 'souriau_common_footer_content_type_theme',
  'category' => t('SOURIAU', array(), array('context' => SOURIAU_COMMON_T_ADMIN)),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
);

/**
 * Implements hook_content_type_render().
 */
function souriau_common_footer_content_type_render($subtype, $conf, $panel_args, $context) {
  global $language, $theme;
  $_domain = domain_get_domain();
  $block = new stdClass();
  $block->title = NULL;
  $data = array();
  $souriau_settings = variable_get('souriau_common_settings');

  $default_fid = variable_get('parent_company_logo');
  $data['_html']['parent_logo_img'] = '';
  if ($default_fid) {
    $default_file = file_load($default_fid);

    // Build footer logo.
    $data['_html']['parent_logo_img'] = theme('image', [
      'path' => file_create_url($default_file->uri),
      'attributes' => [],
      'alt' => 'EATON',
    ]);
  }

  // Build footer-links.
  $data['_html']['footer_links'] = _souriau_common_footer_build_footer_links($language);

  // Contact Information.
  // Loading data from backend variable admin UI.
  $data['_html']['contact_information'] = i18n_variable_get('contact_information', $language->language);

  // Social Networks.
  $data['_html']['social'] = _souriau_common_footer_build_social_networks($souriau_settings);

  // Newsletter widget Country setup.
  $newsletter_link = $souriau_settings['newsletter']['link'];
  $data['_html']['newsletter_widget_url'] = isset($newsletter_link[$_domain['domain_id']]) ? $newsletter_link[$_domain['domain_id']] : 'https://app.mailjet.com/widget/iframe/41YK/i8A';

  // Select Language.
  $data['_html']['country'] = '<h3>' . t('COUNTRY:', array(), array('context' => SOURIAU_COMMON_T_FOOTER)) . '</h3>';
  $data['_html']['country'] .= souriau_common_footer_country_selector_form();

  // Footer menu.
  $data['_html']['footer_menu'] = _souriau_common_footer_build_footer_menu($language);

  // Copyrights.
  if (!empty($souriau_settings['information']['copyrights'])) {
    $data['_html']['copyright'] = '<p>' . $souriau_settings['information']['copyrights'][1];
    if (!empty($souriau_settings['information']['copyrights'][1]) && !empty($souriau_settings['information']['copyrights'][2])) {
      $data['_html']['copyright'] .= ' <span class="separator mobile-hide">-</span> ';
    }
    $data['_html']['copyright'] .= '<span class="rights-text">' . $souriau_settings['information']['copyrights'][2] . '</span></p>';
  }
  else {
    $data['_html']['copyright'] = '<p>'
      . t('Copyright &copy; 2016 SOURIAU', array(), array('context' => SOURIAU_COMMON_T_FOOTER))
      . ' <span class="separator mobile-hide">-</span><span class="rights-text"> '
      . t('All Rights Reserved', array(), array('context' => SOURIAU_COMMON_T_FOOTER)) . '</span></p>';
  }

  $block->content = theme('block_footer', $data);
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_footer_content_type_edit_form($form, &$form_state) {
  return $form;
}

/**
 * Admin title callback.
 */
function souriau_common_footer_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: footer', array(), array('context' => SOURIAU_COMMON_T_ADMIN));
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_footer_content_type_theme(&$theme, $plugin) {
  $theme['block_footer'] = array(
    'path'      => $plugin['path'],
    'template'  => 'souriau-common-footer',
    'variables' => array('params' => array()),
  );
}

/**
 * Country selector in footer.
 */
function souriau_common_footer_country_selector_form() {
  global $language, $user;
  $domain = domain_get_domain();
  $lang_list = _domain_locale_get_domains_languages();
  $attributes = [];
  $central_roles = [
    'administrator',
    'Webmaster',
    'product_contributor',
    'application_contributor',
    'capability_contributor',
    'global_contributor',
    'global_publisher',
  ];

  // Prepare Languages.
  $roles = user_roles();
  $en_en = $lang_list[SOURIAU_COMMON_CENTRAL_DOMAIN_ID][SOURIAU_COMMON_VAR_DEFAULT_LNG];
  unset($lang_list[SOURIAU_COMMON_CENTRAL_DOMAIN_ID]);
  foreach ($central_roles as $role) {
    if ($user->uid == 1 || user_has_role(array_search($role, $roles))) {
      $lang_list[SOURIAU_COMMON_CENTRAL_DOMAIN_ID] = [SOURIAU_COMMON_VAR_DEFAULT_LNG => $en_en];
      break;
    }
  }

  // Build options for select.
  $domain_languages = [];
  foreach ($lang_list as $domain_id => $languages) {
    $domain_details = domain_lookup($domain_id);
    if ($domain_details['valid'] == 0) {
      unset($lang_list[$domain_id]);
      continue;
    }
    $display_domain = domain_conf_variable_get($domain_id, 'backoffice_extras_display_domain');
    if ($display_domain == 1) {
      unset($lang_list[$domain_id]);
      continue;
    }
    $domain_languages[$domain_id] = [
      'languages' => $languages,
      'domain' => $domain_details,
      'weight' => $domain_details['weight'],
    ];
  }
  uasort($domain_languages, 'drupal_sort_weight');
  $options = _souriau_common_footer_country_selector_prepare_options($domain_languages, $attributes, $language, $domain);
  $links = [
    'items' => $options['options'],
    'title' => NULL,
    'type' => 'ul',
    'attributes' => ['class' => ['lang-dropdown', 'country-selector']]
  ];
  $output = '<div class="lang-select">';
  $output .= '<span class="lang-label">' . (empty($options['domain-name']) ? '' : $options['domain-name']) . '</span>';
  $output .= theme('item_list', $links);
  $output .= '</div>';

  return $output;
}

/**
 * Helper function for build footer links.
 */
function _souriau_common_footer_build_footer_links($language) {
  $output = '';
  $footer_links = menu_load_links('menu-footer-links');
  $items = [];
  $container_position = 'left';
  foreach ($footer_links as $item) {
    if (!empty($item['hidden'])) {
      continue;
    }
    $items[$container_position][] = l(_i18n_menu_link_title($item, $language->language), $item['link_path']);
    $container_position = ($container_position == 'left') ? 'right' : 'left';
  }

  if (!empty($items['left'])) {
    $links = [
      'items' => $items['left'],
      'title' => NULL,
      'type' => 'ul',
    ];

    $output .= '<div class="sub-col">';
    $output .= theme('item_list', $links);
    $output .= '</div>';
  }

  if (!empty($items['right'])) {
    $links = [
      'items' => $items['right'],
      'title' => NULL,
      'type' => 'ul',
    ];

    $output .= '<div class="sub-col">';
    $output .= theme('item_list', $links);
    $output .= '</div>';
  }
  return $output;
}

/**
 * Helper function for build social networks links.
 */
function _souriau_common_footer_build_social_networks($souriau_settings) {
  $social = isset($souriau_settings['information']['social']) ? $souriau_settings['information']['social'] : array();
  $items = array();
  foreach ($social as $name => $link) {
    if (empty($link) || $name == 'socialshare_default_image') {
      continue;
    }
    if ($name == 'youtube') {
      $icons = '<span class="ico ico-' . $name . '"></span>';
    }
    else {
      $icons = '
        <span class="ico ico-' . $name . '">
          <!--[if gte IE 9]><!-->
            <svg class="svg-ico"><use xlink:href="#ico-' . $name . '"></use></svg>
          <!--<![endif]-->
        </span>';
    }
    $items[] = l($icons, $link, array('html' => TRUE));
  }
  if (empty($items)) {
    return;
  }
  $links = [
    'items' => $items,
    'title' => NULL,
    'type' => 'ul',
  ];
  $output = '<h3>' . t('FOLLOW US:', [], ['context' => SOURIAU_COMMON_T_FOOTER]) . '</h3>';
  $output .= theme('item_list', $links);

  return $output;
}

/**
 * Helper function for build footer menu links.
 */
function _souriau_common_footer_build_footer_menu($language) {
  $items = array();
  $footer_menu = menu_load_links('menu-footer-menu');
  foreach ($footer_menu as $item) {
    if (!empty($item['hidden'])) {
      continue;
    }
    $items[] = l(_i18n_menu_link_title($item, $language->language), $item['link_path']);
  }
  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();
  $feedback_button = ctools_modal_text_button(
    t('Website Feedback', [], ['context' => SOURIAU_COMMON_T_USER]),
    'souriau/ajax/website/feedback/nojs',
    '',
    'ctools-modal-souriau-modal-style'
  );
  array_unshift($items, $feedback_button);

  $links = array(
    'items' => $items,
    'title' => NULL,
    'type' => 'ul',
  );

  return theme('item_list', $links);
}

/**
 * Helper function for prepare Options of country selector.
 */
function _souriau_common_footer_country_selector_prepare_options($domain_languages, &$attributes, $language, $current_domain) {
  $dest = drupal_get_destination();
  $country_list = country_get_list();
  $options = [];
  $domain_prefixes_into_iso = [
    'usa' => 'us',
    'uk' => 'gb',
    'central' => 'Central',
    'www' => 'International',
  ];

  foreach ($domain_languages as $domain_id => $domain_details) {
    $domain = $domain_details['domain'];
    $domain_countries = domain_conf_variable_get($domain_id, 'geo_countries');
    // Take the first assigned country from the domaiin.
    $country_attr = reset($domain_countries);
    // Load domain name.
    $domain_display_name = domain_conf_variable_get($domain_id, 'backoffice_extras_display_name');
    $exploded_subdomain = explode('.', $domain['subdomain']);
    $domain_prefix = array_shift($exploded_subdomain);
    // Fallback for ISO code of domain.
    $domain_prefix = isset($domain_prefixes_into_iso[$domain_prefix]) ? $domain_prefixes_into_iso[$domain_prefix] : $domain_prefix;
    $domain_prefix = drupal_strtoupper($domain_prefix);
    foreach ($domain_details['languages'] as $langcode => $details) {
      $prefix = explode('-', $langcode);
      $display_langcode = array_shift($prefix);
      // Used only on central.
      $country_iso_from_lancode = !empty($prefix) ? '(' . drupal_strtoupper(array_shift($prefix)) . ')' : '';
      $display_name = !empty($domain_display_name) ? $domain_display_name : (isset($country_list[$domain_prefix]) ? $country_list[$domain_prefix] : $domain_prefix);

      if (count($domain_details['languages']) > 1) {
        $display_name = ($current_domain['domain_id'] == SOURIAU_COMMON_DOMAIN_CENTRAL) ? $display_name . $country_iso_from_lancode : $display_name;
        $display_name = implode(' - ', [$display_name, $display_langcode]);
      }
      $key = implode(':', [$domain_id, $langcode]);
      $data_selected = $data_link = $data_lang = $data_iso = NULL;

      if ($key == $current_domain['domain_id'] . ':' . $language->language) {
        $attributes[$key] = [];
        $data_selected = 'selected';
        $output['domain-name'] = drupal_strtoupper($display_name);
      }
      $path_base = $domain['path'] . $langcode;
      $data_link = (drupal_is_front_page()) ? $path_base : $path_base . '/' . drupal_get_path_alias($dest['destination']);
      $data_lang = $langcode;
      if (!empty($country_attr)) {
        $data_iso = $country_attr;
      }
      $options[$key]['data'] = l($display_name, NULL, [
        'attributes' => [
          'data-link' => $data_link,
          'data-lang' => $data_lang,
          'data-iso' => $data_iso,
          'data-selected' => $data_selected,
        ]
      ]);
    }
  }
  $output['options'] = $options;
  return $output;
}
