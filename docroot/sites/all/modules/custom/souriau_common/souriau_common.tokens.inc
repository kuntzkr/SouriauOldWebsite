<?php
/**
 * @file
 * Souriau Common Tokens.
 */

/**
 * Implements hook_token_info_alter().
 */
function souriau_common_token_info_alter(&$data) {
  $address_field = &$data['tokens']['address-field'];
  $address_field['job-position'] = array(
    'name' => t('Job Position'),
    'description' => t('Job Position.'),
  );
  return $data;
}

/**
 * Implements hook_token_info().
 */
function souriau_common_token_info() {
  $info['tokens']['node']['souriau_alias'] = [
    'name' => t('Generate alias to Node'),
    'description' => t('Generate path Category/Subcategory to CT PartNumber, CT ProductRange and CT Sub-Category for Category Hierarchy'),
  ];
  $info['tokens']['node']['souriau_default_translation_title'] = [
    'name' => t('Get title from default translation of Node'),
    'description' => t('Get title from default translation of Node'),
  ];
  $info['tokens']['node']['souriau_news_landing_link'] = [
    'name' => t('News landing link'),
    'description' => t('Url to news landing node'),
  ];
  $info['tokens']['node']['souriau_products_landing_page'] = [
    'name' => t('Product landing link'),
    'description' => t('Url to news product node'),
  ];
  $info['tokens']['user']['reset_password_timeout'] = [
    'name' => t('Reset Password Timeout'),
    'description' => t('Timeout for one time login link. On password reset'),
  ];
  $info['tokens']['node']['souriau_meta_description'] = [
    'name' => t('Meta Description'),
    'description' => t('Meta tags for site pages'),
  ];
  $info['tokens']['node']['souriau_meta_image'] = [
    'name' => t('Meta Images'),
    'description' => t('Meta tags for site images'),
  ];
  return $info;
}

/**
 * Implements hook_tokens().
 */
function souriau_common_tokens($type, $tokens, array $data = [], array $options = []) {
  $sanitize = !empty($options['sanitize']);

  $replacements = [];

  if ($type == 'node') {
    $replacements += souriau_common_tokens_node($type, $tokens, $data, $options);
  }
  elseif ($type == 'address-field' && !empty($data['address-field'][LANGUAGE_NONE]) && is_array($data['address-field'][LANGUAGE_NONE])) {
    $address = reset($data['address-field'][LANGUAGE_NONE]);
    $replacements[$tokens['job-position']] = $sanitize ? check_plain($address['job_position']) : $address['job_position'];
  }
  elseif ($type == 'user' && isset($tokens['reset_password_timeout'])) {
    $time = variable_get('user_password_reset_timeout');
    $hours = intval($time / 60 / 60);
    $replacements[$tokens['reset_password_timeout']] = $hours;
  }

  return $replacements;
}

/**
 * Helper function for node tokens replace.
 */
function souriau_common_tokens_node($type, $tokens, $data, $options) {
  $node = $data['node'];
  $replacements = [];
  $content_types = [
    'category',
    'subcategory',
    'productrange',
    'applicationdomain',
    'application',
    'capabilitydomain',
    'capability',
  ];

  foreach ($tokens as $name => $original) {
    // Meta tags replacement function call for twitter cards.
    if ($name == 'souriau_meta_description' || $name == 'souriau_meta_image') {
      $replacements[$original] = souriau_common_meta_descrption($name, $node);
    }
    if ($name == 'souriau_alias' && (empty($data['node']) || !in_array($node->type, $content_types))) {
      continue;
    }

    switch ($name) {
      case 'souriau_alias':
        $replacements[$original] = _souriau_common_get_generated_alias($node);
        break;

      case 'souriau_news_landing_link':
        $landing_nid = souriau_common_get_nids('news_landing');
        $replacements[$original] = l(t('News Landing Page', [], ['context' => SOURIAU_COMMON_T_OTHER]), url('node/' . reset($landing_nid)), ['external' => TRUE]);
        break;

      case 'souriau_products_landing_page':
        $landing_nid = souriau_common_get_nids('productlanding');
        $replacements[$original] = l(t('Products Landing Page', [], ['context' => SOURIAU_COMMON_T_OTHER]), url('node/' . reset($landing_nid)), ['external' => TRUE]);
        break;

      case 'souriau_default_translation_title':
        $replacements[$original] = $node->title_original;
        break;

      default:
        break;
    }
  }

  return $replacements;
}

/**
 * Implements hook_tokens_alter().
 */
function souriau_common_tokens_alter(array &$replacements, array $context) {
  $tokens = $context['tokens'];
  $options = $context['options'];
  $type = $context['type'];
  $data = $context['data'];

  $sanitize = !empty($options['sanitize']);

  // If we're generating tokens for an address field, extract the address data
  // from the field value array and generate the necessary replacements.
  if (!($type == 'address-field' && !empty($data['address-field'][LANGUAGE_NONE]) && is_array($data['address-field'][LANGUAGE_NONE]))) {
    return;
  }
  $address = reset($data['address-field'][LANGUAGE_NONE]);

  $simple_replace = [
    'phone-number',
    'phone-number-extension',
    'mobile-number',
    'fax-number',
    'country-code',
    'administrative-area-raw',
    'locality',
    'postal-code',
    'thoroughfare',
    'premise',
    'sub_premise',
    'name-line',
    'first-name',
    'last-name',
  ];

  foreach ($tokens as $name => $original) {
    if (in_array($name, $simple_replace)) {
      $property = str_replace('-', '_', $name);
      $replacements[$original] = $sanitize ? check_plain($address[$property]) : $address[$property];

      continue;
    }

    switch ($name) {
      case 'country':
        $countries = _addressfield_country_options_list();
        if (!isset($countries[$address['country']])) {
          $replacements[$original] = '';
          break;
        }
        $replacements[$original] = $sanitize ? check_plain($countries[$address['country']]) : $countries[$address['country']];
        break;

      case 'organisation':
        $replacements[$original] = $sanitize ? check_plain($address['organisation_name']) : $address['organisation_name'];
        break;

      case 'administrative-area':
        $replacements[$original] = _souriau_common_tokens_administrative_area($address, $sanitize, $data);
        break;

      // See: http://kb.mailchimp.com/article/how-do-i-format-my-list-fields-to-import-them
      case 'format-mailchimp':
        $replacements[$original] = _souriau_common_tokens_format_mailchimp($address, $sanitize);
        break;

      default:
        break;
    }
  }
}

/**
 * Helper function for replacement format-mailchimp token.
 */
function _souriau_common_tokens_format_mailchimp($address, $sanitize) {
  $components = array();

  $address_components = [
    'thoroughfare',
    'premise',
    'locality',
    'administrative_area',
    'postal_code',
    'country'
  ];
  foreach ($address_components as $component) {
    if (!empty($address[$component])) {
      $components[] = $address[$component];
    }
  }

  $format_mailchimp = implode('  ', $components);
  return $sanitize ? check_plain($format_mailchimp) : $format_mailchimp;
}

/**
 * Helper function for replacement administrative-area token.
 */
function _souriau_common_tokens_administrative_area($address, $sanitize, $data) {
  // If we received format handlers in the data array, generate the form
  // for the address field to see if the administrative area should be
  // expanded from an abbreviation to a related name.
  $administrative_area = $address['administrative_area'];

  if (!empty($data['format_handlers'])) {
    $form = addressfield_generate($address, $data['format_handlers'], array('mode' => 'form'));

    if (!empty($form['locality_block']['administrative_area']['#options'][$administrative_area])) {
      $administrative_area = $form['locality_block']['administrative_area']['#options'][$administrative_area];
    }
  }

  return $sanitize ? check_plain($administrative_area) : $administrative_area;
}

/**
 * Helper function for node meta tags tokens replace.
 */
function souriau_common_meta_descrption($name, $node) {
  global $language;
  $alter = [
    'max_length' => 160,
    'ellipsis' => FALSE,
    'word_boundary' => TRUE,
    'html' => TRUE,
  ];
  switch ($node->type) {
    case 'homepage':
      $description_field = 'field_ect_description';
      $image_field = 'field_ect_image';
      break;

    case 'news':
      $description_field = 'field_body';
      $image_field = 'field_image';
      break;

    case 'capabilitieslanding':
    case 'capabilitydomain':
    case 'applicationdomain':
    case 'applicationlanding':
    case 'category':
    case 'subcategory':
    case 'genericlanding':
    case 'news_landing':
    case 'toolkitlanding':
    case 'tool':
    case 'productlanding':
      $description_field = 'field_description';
      $image_field = 'field_image';
      break;

    case 'application':
      $description_field = 'field_our_solution';
      $image_field = 'field_image';
      break;

    case 'product':
      if ($name == 'souriau_meta_description') {
        return views_trim_text($alter, souriau_common_get_part_number_field_value($node, 'description'));
      }
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $sku = $node_wrapper->field_sku_products->raw();
      if (empty($sku)) {
        // SKU required.
        return;
      }
      $sku = $node_wrapper->field_sku_products->value();
      // Build image url.
      $images = field_get_items('commerce_product', $sku, 'field_sku_images');
      $image = isset($images[0]) ? array_shift($images) : [];
      return !empty($image['fid']) ?
      image_style_url('part_number_image', $image['file']->uri) : souriau_common_check_meta_image('', $node);

    case 'resource':
      $description_field = 'field_description';
      $image_field = 'field_resource_image';
      break;

    case 'cms_page':
    case 'toolkit':
      $description_field = 'field_paragraphs';
      $image_field = 'field_image';
      break;

    case 'productrange':
    case 'productrangehub':
      if ($name == 'souriau_meta_image') {
        return souriau_common_check_meta_image('field_image', $node);
      }
      $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
      $paragraphs = $node_wrapper->field_paragraphs->value();
      if (empty($paragraphs)) {
        return;
      }
      $description = field_get_items('paragraphs_item', $paragraphs[0], 'field_paragraph_description');
      $meta_description = field_view_value('paragraphs_item', $paragraphs[0], 'field_paragraph_description', $description[0]);
      return !empty($meta_description['#markup']) ? views_trim_text($alter, $meta_description['#markup']) : '';

    case 'capability':
      $description_field = 'field_our_solution';
      $image_field = 'field_image';
      break;

    default:
      return;
  }

  return ($name == 'souriau_meta_description') ?
  views_trim_text($alter, souriau_common_get_field_value('node', $node, $description_field, $language->language)) : souriau_common_check_meta_image($image_field, $node);
}

/**
 * Check node image exist or return social account default image.
 */
function souriau_common_check_meta_image($image_field, $node) {
  global $language, $theme;
  $image_field_src = souriau_common_get_field_value('node', $node, $image_field, $language->language);
  if (!empty($image_field_src)) {
    return $image_field_src;
  }

  $souriau_settings = variable_get('souriau_common_settings');
  $default_fid = $souriau_settings['information']['social']['socialshare_default_image'];
  if (!empty($default_fid)) {
    $default_file = file_load($default_fid);
    return file_create_url($default_file->uri);
  }
  // Return site logo if no default image defined.
  $logo_path = theme_get_setting('logo', $theme);
  return file_create_url($logo_path);
}
