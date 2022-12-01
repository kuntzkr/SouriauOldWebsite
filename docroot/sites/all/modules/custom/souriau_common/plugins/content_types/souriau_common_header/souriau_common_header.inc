<?php

/**
 * @file
 * Header CCT.
 */

/**
 * Implements hook_ctools_content_types().
 */
$plugin = [
  'title' => t('SOURIAU Common: Header', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'description' => t('SOURIAU Common: Header', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'content_types' => 'souriau_common_header',
  'single' => TRUE,
  'render callback' => 'souriau_common_header_content_type_render',
  'edit form' => 'souriau_common_header_content_type_edit_form',
  'admin title' => 'souriau_common_header_content_type_admin_title',
  'hook theme' => 'souriau_common_header_content_type_theme',
  'category' => t('SOURIAU', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  'icon' => NULL,
  'all contexts' => TRUE,
  'no title override' => TRUE,
];

/**
 * Implements hook_content_type_render().
 */
function souriau_common_header_content_type_render($subtype, $conf, $panel_args, $context) {
  global $user;
  global $theme;
  global $language;

  $block = new stdClass();
  $block->title = NULL;
  $data = [];
  $data['user'] = $user;
  $query_string = variable_get('css_js_query_string', '0');
  $theme_path = drupal_get_path('theme', 'souriau');

  // Build logo Container.
  $site_name = variable_get('site_name', 'SOURIAU - SUNBANK Connection Technologies');
  $logo_img = theme('image', [
    'path' => theme_get_setting('logo', $theme),
    'attributes' => [],
    'alt' => $site_name,
  ]);
  $domain = domain_get_domain();
  $logo_link = $domain['path'] . $language->language;
  $data['_html']['logo'] = l($logo_img, $logo_link, [
    'attributes' => ['class' => 'logo'],
    'html' => TRUE,
  ]);

  // Search.
  // On search page always visible.
  $data['_html']['search_class'] = '';
  if (arg(0) == 'search') {
    $data['_html']['search_class'] = ' b-always-visible';
  }
  $data['_html']['search_form'] = _souriau_common_header_buld_search_form();

  // Cart.
  module_load_include('inc', 'souriau_common', 'includes/souriau_common.minicart');
  // Initializing the cart count.
  $cart_content = souriau_common_minicart_header_build_cart(FALSE);
  $cart = $cart_content['cart'];
  $data['_html']['cart'] = $cart_content['link_path'];
  $data['_html']['minicart_url'] = url('souriau/ajax/mini-cart');
  // Poll link.
  $data['_html']['poll_link'] = _souriau_common_header_build_poll_url();

  // Build main menu.
  $data['_html']['menu'] = _souriau_common_header_build_main_menu($conf);

  // Add additional links.
  $items[] = l($cart['title'], $cart['link_path']);

  if (!user_is_anonymous()) {
    $items[] = l(t('My orders', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/' . $user->uid . '/erp-orders');
    $items[] = l(t('Projects', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/' . $user->uid . '/projects');
    $items[] = l(t('Address book', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/' . $user->uid . '/addresses');
    $items[] = l(t('My account', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/space');
    $items[] = l(t('Sample orders', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/' . $user->uid . '/sample-orders');
    $items[] = l(t('Delete account', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/' . $user->uid . '/delete-account');
    $items[] = l(t('Logout', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/logout');
  }
  else {
    $items[] = l(t('Log in', [], ['context' => SOURIAU_COMMON_T_HEADER]), 'user/login');
  }

  $links = [
    'items' => $items,
    'title' => NULL,
    'type' => 'ul',
  ];

  $data['_html']['alert_banner'] = variable_get('alert_banner');

  $data['_html']['additional_links'] = theme('item_list', $links);

  // Personal links.
  $data['_html']['user_menu'] = _souriau_common_header_build_user_menu($user, $data);

  // Sample order & Where to buy links.
  $data['_html']['b_links'] = _souriau_common_header_sample_where_buy();

  // Select Language.
  $data['_html']['country'] = '<h3>' . t('COUNTRY:', [], ['context' => SOURIAU_COMMON_T_HEADER]) . '</h3>';
  $data['_html']['country'] .= souriau_common_footer_country_selector_form();

  // Custom Styles.
  $data['svg_icons_set'] = '
    <!-- icons set -->
      <!--[if gte IE 9]><!-->
        <div id="site-svg-target"></div>
        <script type="text/javascript" src="/' . $theme_path . '/html/js/svg/svg.js?' . $query_string . '"></script>
      <!--<![endif]-->
    <!-- /icons set -->';

  $block->content = theme('block_header', $data);
  return $block;
}

/**
 * Implements hook_content_type_edit_form().
 */
function souriau_common_header_content_type_edit_form($form, &$form_state) {

  $conf = $form_state['conf'];
  $form['conf'] = [
    '#type' => 'fieldset',
    '#title' => t('Configuration', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#tree' => TRUE,
  ];

  $menu_list = menu_get_menus();

  // Header menu select.
  $form['conf']['header_menu'] = [
    '#type' => 'select',
    '#title' => t('Menu for site header', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#description' => t('Specify menu that will be rendered in site header.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#options' => $menu_list,
    '#required' => TRUE,
    '#default_value' => !empty($conf['header_menu']) ? $conf['header_menu'] : '',
  ];

  return $form;
}

/**
 * Implements hook_edit_form_submit().
 */
function souriau_common_header_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf'] = $form_state['values']['conf'];
}

/**
 * Admin title callback.
 */
function souriau_common_header_content_type_admin_title($subtype, $conf, $context) {
  return t('SOURIAU Common: Header', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
}

/**
 * Implements hook_content_type_theme().
 */
function souriau_common_header_content_type_theme(&$theme, $plugin) {
  $theme['block_header'] = [
    'path'      => $plugin['path'],
    'template'  => 'souriau-common-header',
    'variables' => ['params' => []],
  ];
}

/**
 * Helper function for build search form.
 */
function _souriau_common_header_buld_search_form() {
  // Get quantity of result.
  $placeholder = t('Looking for a product?', [], ['context' => SOURIAU_COMMON_T_HEADER]);
  $filters = souriau_search_get_preprocess();
  if (!empty($filters['keyword'])) {
    $results = souriau_search_apply_filter_helper([], ['keyword' => $filters['keyword']], FALSE);

    $keyword = urldecode($filters['keyword']);

    if (empty($results['count']['all'])) {
      $placeholder = t("No result found for @keyword", ['@keyword' => $keyword], ['context' => SOURIAU_COMMON_T_HEADER]);
    }
    else {
      $placeholder = t("@total result(s) found for @keyword", ['@total' => $results['count']['all'], '@keyword' => $keyword], ['context' => SOURIAU_COMMON_T_HEADER]);
    }
  }
  $search_form = drupal_get_form('souriau_common_search_form');

  // Set placeholder.
  $search_form['search']['search_key']['#attributes']['placeholder'] = $placeholder;
  $search_form['search']['search_key']['#attributes']['class'][] = 'autocomplete';

  // Insert arrow into button.
  $search_form['actions']['#weight'] = -10;
  $search_form['actions']['submit']['#type'] = 'button';
  $search_form['actions']['submit']['#souriau_settings']['#elements'] = [
    'ico' => [
      '#type' => 'svg_icon',
      '#icon' => 'ico-arrow-right',
    ],
  ];

  return drupal_render($search_form);
}

/**
 * Helper function for build main_menu.
 */
function _souriau_common_header_build_main_menu($conf) {
  global $is_https, $base_url;
  $menu = menu_tree_all_data($conf['header_menu']);
  $menu_settings = variable_get('souriau_common_main_menu_form', []);
  $links = [
    'home-link hidden-lg' => [
      'title' => t('Home', [], ['context' => SOURIAU_COMMON_T_HEADER]),
      'href' => '<front>',
    ],
  ];
  $souriau_settings = [];
  foreach ($menu as $key => $item) {
    if (_souriau_common_header_build_main_menu_is_enabled($item, $menu_settings)) {
      $attributes = [];
      if (!empty($item['below'])) {
        $souriau_settings = ['sub_2' => _souriau_common_header_build_main_menu_sub_2($item['below'], $menu_settings)];
        $block_id = [
          'Products' => 'products-pannel',
          'Capabilities' => 'capabilities-pannel',
          'Applications' => 'application-pannel',
        ];
        $attributes = isset($block_id[$item['link']['link_title']]) ? ['aria-controls' => $block_id[$item['link']['link_title']]] : [];
      }
      $links[$key] = [
        'title' => $item['link']['title'],
        'href' => ($is_https && module_exists('domain_alias')) ? $base_url . url($item['link']['link_path']) : $item['link']['link_path'],
        'attributes' => $attributes,
      ];
      if (!empty($souriau_settings['sub_2'])) {
        $links[$key]['souriau_settings'] = $souriau_settings;
      }
      $souriau_settings = '';
    }
  }
  return theme('links', ['links' => $links]);
}

/**
 * Preparing site menu sub links.
 *
 * @param array $links
 *   Array submenu items.
 * @param array $settings
 *   Array with site menu settings per domain.
 *
 * @return array
 *   Array with html links <a>....</a>.
 */
function _souriau_common_header_build_main_menu_sub_2(array $links, array $settings) {
  global $is_https, $base_url;
  $sub_links = [];
  foreach ($links as $link) {
    if (_souriau_common_header_build_main_menu_is_enabled($link, $settings)) {
      $sub_links[] = l(
        $link['link']['title'],
        ($is_https && module_exists('domain_alias')) ? $base_url . url($link['link']['link_path']) : $link['link']['link_path']
      );
    }
  }
  return $sub_links;
}

/**
 * Simple check on 'is menu item enabled/available'.
 *
 * @param array $link
 *   Menu item.
 * @param array $settings
 *   Main menu setting per domain.
 *
 * @return bool
 *   TRUE/FALSE.
 */
function _souriau_common_header_build_main_menu_is_enabled(array $link, array $settings) {
  return ((!isset($settings['mlid:' . $link['link']['mlid']])
      || !empty($settings['mlid:' . $link['link']['mlid']]['hidden']))
    && (!$link['link']['hidden'] || !$link['link']['access']));
}

/**
 * Helper function for build user menu.
 */
function _souriau_common_header_build_user_menu($user, &$data) {
  global $is_https, $base_url, $language;
  $options = [
    'html'  => TRUE,
    'attributes' => [
      'class' => ['account-link'],
    ],
  ];

  // Do not show login menu if login/registraton is disabled in BO.
  if (souriau_common_is_userzone_available() == FALSE) {
    $data['_html']['user_menu_fist'] = NULL;
    return;
  }

  $links = [];
  $anonymous_links = ['user/login'];
  // Links from user_menu, that will not be processed.
  $except_links = ['user/register', 'user/password'];

  $icon = [
    '#type' => 'svg_icon',
    '#icon' => 'ico-account',
  ];

  if (user_is_anonymous()) {
    $data['_html']['user_menu_fist'] = l(
      drupal_render($icon) . t('Log in', [], ['context' => SOURIAU_COMMON_T_USER]),
      (!$is_https && module_exists('domain_alias')) ? $base_url . url('user/login') : 'user/login',
      $options
    );
    return;
  }

  $menu = menu_load_links('user-menu');
  foreach ($menu as $key => $item) {
    if ($item['link_path'] == 'user') {
      $data['_html']['user_menu_fist'] = l(
        drupal_render($icon) . _i18n_menu_link_title($item, $language->language),
        (!$is_https && module_exists('domain_alias')) ? $base_url . url('user/space') : 'user/space',
        $options
      );

      continue;
    }

    // Add links from user_menu into header.
    if (!in_array($item['link_path'], $anonymous_links) && !in_array($item['link_path'], $except_links)) {
      $links[] = [
        'title' => _i18n_menu_link_title($item, $language->language),
        'href' => $item['link_path'],
      ];
    }
  }

  // Add user links.
  $user_links = [
    'delete-account' => t('Delete account', [], ['context' => SOURIAU_COMMON_T_HEADER]),
    'edit-profile' => t('Edit account', [], ['context' => SOURIAU_COMMON_T_HEADER]),
    'sample-orders' => t('Sample orders', [], ['context' => SOURIAU_COMMON_T_HEADER]),
    'addresses' => t('Address book', [], ['context' => SOURIAU_COMMON_T_HEADER]),
    'projects' => t('Projects', [], ['context' => SOURIAU_COMMON_T_HEADER]),
    'erp-orders' => t('My orders', [], ['context' => SOURIAU_COMMON_T_HEADER]),
    // Temporary hidden according to #178794.
    // 'dashboard' => t('Dashboard', [], ['context' => SOURIAU_COMMON_T_HEADER]),.
  ];
  foreach ($user_links as $pathkey => $title) {
    $path = 'user/' . $user->uid . '/' . $pathkey;
    // Check path.
    $item = menu_get_item($path);
    if ($item && $item['access']) {
      array_unshift($links, [
        'title' => $title,
        'href' => (!$is_https && module_exists('domain_alias')) ? $base_url . url($path) : $path
      ]);
    }
  }
  return theme('links', ['links' => $links]);
}

/**
 * Helper function for build header b-links.
 */
function _souriau_common_header_sample_where_buy() {
  global $is_https, $base_url;
  $items = [
    'Job opportunities' => 'souriau_common/nojs',
    'Our distributors' => 'our-distributors',
  ];
  foreach ($items as $key => &$link) {
    $attributes = [
      'class' => ['gtm_element'],
      'data-gtm-category' => 'button',
      'data-gtm-action' => ($key === 'Job opportunities') ? $link : preg_replace('@[^a-z0-9_]+@', '-', drupal_strtolower($key)),
      'data-gtm-label' => $key,
    ];
    $href = ($is_https && module_exists('domain_alias')) ? $base_url . url('/' . preg_replace('@[^a-z0-9_]+@', '-', drupal_strtolower($link))) : '/' . preg_replace('@[^a-z0-9_]+@', '-', drupal_strtolower($link));
    if ($key === 'Job opportunities') {
      $href = $link;
      $attributes['class'][] = 'ctools-use-modal';
      $attributes['class'][] = 'ctools-modal-souriau-modal-style';
    }
    $options['attributes'] = $attributes;
    $link = [
      l(
        t(drupal_strtoupper($key), [], ['context' => SOURIAU_COMMON_T_HEADER]), $href, $options
      ),
    ];
  }
  $links = [
    'items' => $items,
    'title' => NULL,
    'type' => 'ul',
  ];
  return theme('item_list', $links);
}

/**
 * Function for getting the latest poll url.
 */
function _souriau_common_header_build_poll_url() {
  // Check if there is an active poll.
  $view_data = views_get_view_result('souriau_query_get_latest_poll', 'default');

  if (empty($view_data)) {
    return;
  }
  // Get the paths to show the poll button.
  $souraiu_variables = variable_get('souriau_common_settings');
  $paths_to_show = isset($souraiu_variables['poll']['show_on_paths']) ? $souraiu_variables['poll']['show_on_paths'] : '';
  if (!empty($paths_to_show)) {
    $path = drupal_strtolower(drupal_get_path_alias($_GET['q']));
    $page_match = drupal_match_path($path, $paths_to_show);

    // If the page matches to any of the listed paths to ignore, then return.
    if (!$page_match) {
      return;
    }
  }
  return ctools_modal_text_button(
    t('Participate to our exclusive survey', [], ['context' => SOURIAU_COMMON_T_USER]),
    'souriau/ajax/poll/nojs',
    '',
    'ctools-modal-souriau-modal-style b-poll'
  );
}
