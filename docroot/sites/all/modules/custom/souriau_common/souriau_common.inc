<?php

/**
 * @file
 * Souriau_common.inc Common functions.
 */

/**
 * Get nid of PartNumber by given $sku.
 *
 * @param string $sku
 *   SKU of commerce_product.
 */
function souriau_common_get_part_number_nid($sku) {
  $result = views_get_view_result(SOURIAU_COMMON_VQ_PARTNUMBER_BY_SKU, 'default', $sku);
  return isset($result[0]->nid) ? $result[0]->nid : NULL;
}

/**
 * Load PartNumber node by given $sku.
 *
 * @param string $sku
 *   SKU of commerce_product.
 */
function souriau_common_load_part_number_by_sku($sku) {
  $nid = souriau_common_get_part_number_nid($sku);
  return node_load($nid);
}

/**
 * Is Product Node available in the specified domain.
 *
 * @param object $node
 *   Node of Type Product.
 * @param int $domain_id
 *   DomainID to check in. If not set then current domain is used.
 *
 * @return bool
 *   TRUE in access allowed FALSE otherwise.
 */
function souriau_common_product_is_availible_in_domain($node, $domain_id = NULL) {
  if (empty($node->field_sku_products)) {
    // The product is incomplete.
    return FALSE;
  }

  // If Domain_id is not set then check in the current domain.
  if (empty($domain_id)) {
    $domain = domain_get_domain();
    $domain_id = $domain['domain_id'];
  }

  $node_wrapper = entity_metadata_wrapper('node', $node);
  $sku = $node_wrapper->field_sku_products->value();

  return souriau_common_sku_is_available_in_domain($sku, $domain_id);
}

/**
 * Is Product Node available in the specified domain.
 *
 * @param object $sku
 *   Commerce Product of Type SKU.
 * @param int $domain_id
 *   DomainID to check in. If not set then current domain is used.
 *
 * @return bool
 *   TRUE in access allowed FALSE otherwise.
 */
function souriau_common_sku_is_available_in_domain($sku, $domain_id) {
  if (empty($sku->type) || ('sku' != $sku->type)) {
    // Product is not available.
    return FALSE;
  }

  $sku_wrapper = entity_metadata_wrapper('commerce_product', $sku);

  $current_countries = domain_conf_variable_get($domain_id, 'geo_countries');
  $view_all = $sku_wrapper->field_sku_view_in_regions->raw();
  $exception_countries = $sku_wrapper->field_view_exception->value();
  $exception_check = array_intersect($current_countries, $exception_countries);

  return (
    ($view_all == TRUE && count($exception_check) == 0) ||
    ($view_all == FALSE && count($exception_check) != 0)
  );
}

/**
 * Is Product Node available in domain.
 *
 * @param object $sku
 *   Commerce product.
 *
 * @return bool
 *   TRUE in access allowed FALSE otherwise.
 */
function souriau_common_sample_is_availible_in_domain($sku) {
  $domain = domain_get_domain();
  $current_countries = domain_conf_variable_get($domain['domain_id'], 'geo_countries');

  $wrapper = entity_metadata_wrapper('commerce_product', $sku);
  $sample_all = $wrapper->field_sku_samples_in_regions->value();
  $exception_countries = $wrapper->field_samples_exception->value();
  $exception_check = array_intersect($current_countries, $exception_countries);

  return (
    ($sample_all == TRUE && count($exception_check) == 0) ||
    ($sample_all == FALSE && count($exception_check) == count($current_countries))
  );
}

/**
 * Helper function to check if sample order can be enabled based on BO settings.
 */
function souriau_common_sample_checkout_status() {
  $domain = domain_get_domain();
  $souriau_settings = variable_get('souriau_common_settings');
  return isset($souriau_settings['registration_sample_checkout']['sample_checkout_status'][$domain['domain_id']]) ? $souriau_settings['registration_sample_checkout']['sample_checkout_status'][$domain['domain_id']] : TRUE;
}

/**
 * Callback for element validation.
 */
function _souriau_common_element_code_p_validate(&$element) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $element['#bundle'])
    ->fieldCondition($element['#field_name'], 'value', $element['#value'])
    ->fieldOrderBy($element['#field_name'], 'value', 'ASC')
    ->addMetaData('account', user_load(1));

  // Exclude current node if edit.
  if (!empty($element['#entity']->nid)) {
    $entities_to_exclude = array($element['#entity']->nid);
    if (!empty($element['#entity']->edition_id)) {
      $entities_to_exclude[] = $element['#entity']->edition_id;
    }
    $query->propertyCondition('nid', $entities_to_exclude, 'NOT IN');
  }
  $entities = $query->execute();
  if (count($entities) > 0) {
    form_set_error($element['#field_name'], t('Value of field %field_name is already in use.', array(
      '%field_name' => $element['#title'],
    )));
  }
}

/**
 * Return parent nid in Souriau Catalog hierarchy.
 */
function _souriau_common_get_parent_node($nid, $parent_type, $field_name) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $parent_type)
    ->propertyCondition('status', 1)
    ->fieldCondition($field_name, 'target_id', $nid)
    // We want to fetch just one parent.
    ->range(0, 1);
  $entities = $query->execute();

  if (!empty($entities)) {
    $node = reset($entities['node']);
    return node_load($node->nid);
  }

  return FALSE;
}

/**
 * Return non-transliterated title of the node.
 *
 * Used for building the URL.
 */
function _souriau_common_get_title($node) {
  $title = $node->title_original;
  $title = transliteration_get($title);
  $title = drupal_strtolower($title);
  $title = preg_replace('@[^a-z0-9_]+@', '-', $title);
  return $title;
}

/**
 * Update alias of pub & draft node.
 */
function _souriau_common_update_node_alias($node, $language) {
  if (!is_object($node) || $node->is_draft) {
    return;
  }
  pathauto_node_update_alias($node, 'update', array($language));
  $node_wrapper = entity_metadata_wrapper('node', $node)->language($language);
  $draft_nid = !empty($node_wrapper->field_edition->raw())
    ? $node_wrapper->field_edition->raw()
    : $node->field_edition[LANGUAGE_NONE][0]['target_id'];
  if (!empty($draft_nid)) {
    $draft_node = node_load($draft_nid);
    pathauto_node_update_alias($draft_node, 'update', array($language));
  }
}

/**
 * Return title of parent node.
 *
 * Used only for CT subcategory, productrange, product.
 * Node CT Validation in @see souriau_common_tokens().
 */
function _souriau_common_get_generated_alias($node) {
  $path = [];
  $nid = $node->nid;
  if ($node->is_draft) {
    $nid = field_get_items('node', $node, 'field_edition');
    $nid = isset($nid[0]['target_id']) ? $nid[0]['target_id'] : $nid = $node->nid;
  }

  $allowed_types = [
    SOURIAU_COMMON_PRODUCT_RANGE_CT,
    SOURIAU_COMMON_SUBCATEGORY_CT,
    SOURIAU_COMMON_CATEGORY_CT,
    SOURIAU_COMMON_APPLICATION_CT,
    SOURIAU_COMMON_APPLICATION_DOMAIN_CT,
    SOURIAU_COMMON_CAPABILITY_CT,
    SOURIAU_COMMON_CAPABILITY_DOMAIN_CT,
  ];

  if (in_array($node->type, $allowed_types)) {
    $path = _souriau_common_get_generated_alias_get_path($node->type, $nid);
  }

  ksort($path);
  $result = implode('/', $path);
  return $result;
}

/**
 * Hierarchy mapping.
 */
function _souriau_common_hierarchy_mapping() {
  return [
    SOURIAU_COMMON_PRODUCT_RANGE_CT => [
      'field_product_range' => SOURIAU_COMMON_SUBCATEGORY_CT,
      'field_subcategory' => SOURIAU_COMMON_CATEGORY_CT,
      'field_category' => SOURIAU_COMMON_PRODUCT_LANDING_CT,
    ],
    SOURIAU_COMMON_APPLICATION_CT => [
      'field_application' => SOURIAU_COMMON_APPLICATION_DOMAIN_CT,
      'field_application_domain' => SOURIAU_COMMON_APPLICATION_LANDING_CT,
    ],
    SOURIAU_COMMON_CAPABILITY_CT => [
      'field_capability' => SOURIAU_COMMON_CAPABILITY_DOMAIN_CT,
      'field_capability_domain' => SOURIAU_COMMON_CAPABILITIES_LANDING_CT,
    ],
  ];
}

/**
 * Helper function for return path.
 *
 * @param string $type
 *   Node type.
 * @param int $nid
 *   Node id to witch we generate alias.
 *
 * @return array
 *   Array with path elements
 */
function _souriau_common_get_generated_alias_get_path($type, $nid) {
  $path = [];
  $hierarchy = [];
  $mapping = _souriau_common_hierarchy_mapping();
  foreach ($mapping as $ct_type => $types) {
    if ($ct_type == $type) {
      $hierarchy = $types;
    }
    elseif (in_array($type, $types)) {
      foreach ($types as $key => $item) {
        unset($types[$key]);
        if ($item == $type) {
          $hierarchy = $types;
          continue;
        }
      }
    }
  }

  foreach ($hierarchy as $field_name => $ct_type) {
    // Parent subcategory.
    if (!($title = _souriau_common_get_generated_alias_parent_node_title($nid, $ct_type, $field_name))) {
      return $path;
    }
    array_unshift($path, $title);
  }
  return $path;
}

/**
 * Helper function for return parent node_title.
 */
function _souriau_common_get_generated_alias_parent_node_title(&$nid, $parent_type, $field_name) {
  $parent_node = _souriau_common_get_parent_node($nid, $parent_type, $field_name);
  if (!empty($parent_node)) {
    // Up nid.
    $nid = $parent_node->nid;
    return _souriau_common_get_title($parent_node);
  }
  return FALSE;
}

/**
 * Check if current domain central.
 */
function souriau_common_is_central() {
  $central = FALSE;
  $domain = domain_get_domain();
  if (!empty($domain) && (1 == $domain['domain_id'])) {
    $central = TRUE;
  }

  return $central;
}

/**
 * Debug function genereates Full call stack.
 */
function souriau_common_generate_calltrace() {
  $e = new Exception();
  $trace = explode("\n", $e->getTraceAsString());
  // Reverse array to make steps line up chronologically.
  $trace = array_reverse($trace);
  // Remove {main}.
  array_shift($trace);
  // Remove call to this method.
  array_pop($trace);
  $length = count($trace);
  $result = array();

  for ($i = 0; $i < $length; $i++) {
    // Replace '#someNum' with '$i)', set the right ordering.
    $result[] = ($i + 1) . ')' . substr($trace[$i], strpos($trace[$i], ' '));
  }

  dd(implode("\n\t", $result), 'generateCallTrace');
  dpm($result, __FUNCTION__);
}

/**
 * Return Machine readable name.
 */
function souriau_common_get_machine_name($str) {
  $str = transliteration_get($str);
  $str = drupal_strtolower($str);
  $str = preg_replace('@[^a-z0-9_]+@', '_', $str);
  return $str;
}

/**
 * Custom function for loading Node by field: field_code_p.
 *
 * @deprecated
 *   use souriau_common_load_part_number_by_sku()
 */
function _souriau_common_get_part_number_node_by_field_code_p($value) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'product')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_code_p', 'value', $value, '=')
    ->range(0, 1);
  $result = $query->execute();

  if (empty($result)) {
    return FALSE;
  }
  $product = array_shift($result['node']);
  $node = node_load($product->nid);

  return $node;
}

/**
 * Main product range getter.
 *
 * @param object $part_number
 *   Part number node.
 *
 * @return mixed
 *   Main product range node of FALSE.
 */
function souriau_common_get_main_product_range($part_number) {
  global $language;

  if (empty($part_number->nid) || empty($part_number->field_parent_product_range)) {
    // Nothing to do here.
    return FALSE;
  }

  $product_ranges_by_part_number = &drupal_static(__FUNCTION__);

  if (isset($product_ranges_by_part_number[$part_number->nid])) {
    return $product_ranges_by_part_number[$part_number->nid];
  }

  $node_wrapper = entity_metadata_wrapper('node', $part_number)->language($language->language);
  $product_ranges_by_part_number[$part_number->nid] = $node_wrapper->field_parent_product_range[0]->value();
  return $product_ranges_by_part_number[$part_number->nid];
}

/**
 * Helper Function for getting subcategories ids from several product ranges.
 *
 * @param mixed $product_ranges
 *   Node or nid.
 *
 * @return array
 *   array with categories ids, or empty array.
 */
function souriau_common_get_subcategories_by_product_ranges($product_ranges) {
  $subcategories = [];
  if (is_object($product_ranges)) {
    return souriau_common_get_subcategories_by_product_range($product_ranges->nid);
  }

  if (is_array($product_ranges)) {
    foreach ($product_ranges as $product_range) {
      $pr_nid = is_object($product_range) ? $product_range->nid : $product_range;
      if (!is_numeric($pr_nid)) {
        continue;
      }
      $subcategories += souriau_common_get_subcategories_by_product_range($pr_nid);
    }
  }
  return $subcategories;
}

/**
 * Helper Function for getting subcategories ids from product range.
 *
 * @param mixed $product_range
 *   Node or nid.
 *
 * @return array
 *   array with categories ids, or empty array.
 */
function souriau_common_get_subcategories_by_product_range($product_range) {
  if (is_object($product_range)) {
    $product_range = $product_range->nid;
  }

  if (!is_numeric($product_range)) {
    return [];
  }
  $subcategories = &drupal_static(__FUNCTION__);
  if (isset($subcategories[$product_range])) {
    return $subcategories[$product_range];
  }
  $result = views_get_view_result('get_subcategory_from_productrange', 'default', $product_range);
  $subcategories[$product_range] = [];
  foreach ($result as $subcategory) {
    $subcategories[$product_range][$subcategory->nid] = $subcategory->nid;
  }
  return $subcategories[$product_range];
}

/**
 * Helper function for getting category title from product range.
 *
 * @param object|array $product_range
 *   Product range.
 * @param string $field
 *   Category field.
 *
 * @return array|mixed
 *   Field value.
 */
function _souriau_common_get_category_field_from_product_range($product_range, $field = 'title_field') {
  global $language;

  if (empty($product_range->nid)) {
    // Invalid data given.
    // Nothing to do here.
    return NULL;
  }
  $result = [];
  $product_range_data = &drupal_static(__FUNCTION__);

  if (!isset($product_range_data[$product_range->nid])) {
    $product_range_data[$product_range->nid] = souriau_common_get_categories_for_product_ranges($product_range);
  }

  $categories = $product_range_data[$product_range->nid];
  foreach ($categories as $category_nid) {
    $category = node_load($category_nid);
    if (empty($category->nid)) {
      continue;
    }
    $category_wrapper = entity_metadata_wrapper('node', $category)->language($language->language);
    $result[] = $category_wrapper->{$field}->value();
  }

  return $result;
}

/**
 * Find Categories for given $product_range.
 *
 * @param mixed $product_ranges
 *   ProductRange node.
 *
 * @return array
 *   NIDs of Category nodes.
 */
function souriau_common_get_categories_for_product_ranges($product_ranges) {
  $result = [];

  if (empty($product_ranges)) {
    // Nothing to do here.
    return [];
  }

  if (is_object($product_ranges)) {
    return souriau_common_get_categories_for_product_range($product_ranges);
  }

  // For multiple ranges.
  if (is_array($product_ranges)) {
    foreach ($product_ranges as $product_range) {
      $result += souriau_common_get_categories_for_product_range($product_range);
    }
  }
  return $result;
}

/**
 * Find Categories for given $product_range.
 *
 * @param object $product_range
 *   ProductRange node.
 *
 * @return array
 *   NIDs of Category nodes.
 */
function souriau_common_get_categories_for_product_range($product_range) {
  $result = [];

  if (empty($product_range)) {
    // Nothing to do here.
    return [];
  }

  $subcategories = views_get_view_result('get_subcategory_from_productrange', 'default', $product_range->nid);
  foreach ($subcategories as $subcategory) {
    $categories = views_get_view_result('get_catogory_from_subcategory', 'default', $subcategory->nid);
    foreach ($categories as $category) {
      $result[$category->nid] = $category->nid;
    }
  }
  return $result;
}

/**
 * Helper function for return values for PN fields.
 *
 * @param object $node
 *   Node object Part Number|Product Range.
 * @param string $field
 *   Name of field.
 * @param array $non_textarea_fields
 *   Array with names of non-text fields.
 *
 * @return string|array|bool
 *   Value of field.
 */
function _souriau_common_return_pn_values($node, $field, array $non_textarea_fields) {
  global $language;
  $prefix = [
    'productrange' => 'field_pn_',
    'productrangehub' => 'field_pn_',
  ];

  // Get value of non textarea fields. returns Array.
  if (in_array($field, $non_textarea_fields)) {
    $node_wrapper = entity_metadata_wrapper('node', $node)->language($language->language);
    if (isset($node->{$prefix[$node->type] . $field})) {
      return $node_wrapper->{$prefix[$node->type] . $field}->value();
    }
  }

  // Get value of textarea fields. return HTML.
  if (isset($node->{$prefix[$node->type] . $field})) {
    return souriau_common_get_field_value('node', $node, $prefix[$node->type] . $field);
  }
}

/**
 * Helper function for return default values of PN from product range.
 *
 * @param object $part_number
 *   Node object Part Number.
 * @param string $field
 *   Name of field.
 * @param array $non_textarea_fields
 *   Array with names of non-text fields.
 *
 * @return string|array|bool
 *   Value of field.
 */
function _souriau_common_get_default_pn_values($part_number, $field, array $non_textarea_fields) {
  $product_range = souriau_common_get_main_product_range($part_number);
  return empty($product_range) ? FALSE : _souriau_common_return_pn_values($product_range, $field, $non_textarea_fields);
}

/**
 * Helper function for return values of PN field.
 *
 * @param object $part_number
 *   Node object Part Number.
 * @param string $field
 *   Name of field.
 *
 * @return string|array|bool
 *   Value of field.
 */
function souriau_common_get_part_number_field_value($part_number, $field) {
  $non_textarea_fields = ['advices', 'advices_image'];
  // Get default value.
  $value = _souriau_common_get_default_pn_values($part_number, $field, $non_textarea_fields);
  // On FALSE:  will return empty array for non-textarea.
  if (in_array($field, $non_textarea_fields)) {
    return !empty($value) ? $value : [];
  }
  return $value;
}

/**
 * Helper function to generate form elements for a list's interest groups.
 *
 * @return array
 *   A collection of form elements, one per interest group.
 */
function souriau_common_interest_groups_form_elements($mc_list, array $default_values = [], $email = NULL) {
  $return = [];
  $info = mailchimp_get_memberinfo($mc_list->id, $email);

  // Grab the default values for this member.
  if (!empty($info) && isset($info->status) && 'subscribed' == $info->status) {
    $default_values = souriau_common_interest_groups_get_default_values($mc_list, $email);
  }

  foreach ($mc_list->intgroups as $group) {
    // Extract the field options:
    $options = [];
    foreach ($group->interests as $option) {
      $options[$option->id] = $option->name;
    }

    $return[$group->id] = [
      '#type' => 'checkboxes',
      '#title' => $group->title,
      '#options' => $options,
      '#default_value' => $default_values,
      '#attributes' => ['class' => ['mailchimp-newsletter-interests-' . $mc_list->id]],
    ];
  }
  return $return;
}

/**
 * Get Mailchimp interests for given Mailchimp list and email.
 *
 * @param array $mc_list
 *   Mailchimp List.
 * @param string $email
 *   Email.
 *
 * @return array
 *   Default values array.
 */
function souriau_common_interest_groups_get_default_values(array $mc_list, $email) {
  $default_values = [];

  if (empty($email)) {
    // There is nothing to do here.
    return [];
  }
  $memberinfo = mailchimp_get_memberinfo($mc_list->id, $email);
  if (!isset($memberinfo->interests)) {
    // There is nothing to do here.
    return [];
  }

  foreach ($memberinfo->interests as $interest_id => $status) {
    if ($status) {
      $default_values[] = $interest_id;
    }
  }
  return $default_values;
}

/**
 * Tipity/ECIA service caller.
 *
 * @param string $part_number
 *   Part number.
 *
 * @return array
 *   Service results.
 */
function souriau_common_tipity_service($part_number) {
  $site_settings = variable_get('souriau_site_settings_souriau_ecommerce');
  $site_ecia_settings = $site_settings['stock'];
  $ret = [];

  $url = isset($site_ecia_settings['ecia']['api_search_url']) ? $site_ecia_settings['ecia']['api_search_url'] : 'https://inventory.api.eciaauthorized.com/api/Search/Query';
  $api_key = isset($site_ecia_settings['ecia']['api_key']) ? $site_ecia_settings['ecia']['api_key'] : '55fb3df6-8dd0-4252-b54f-2f37adcabd02';
  $company_id = isset($site_ecia_settings['ecia']['company_id']) ? $site_ecia_settings['ecia']['company_id'] : 'Souriau';
  $manufacturers = isset($site_ecia_settings['ecia']['manufacturers']) ? $site_ecia_settings['ecia']['manufacturers'] : 'souriau|sunbank';

  foreach (explode('|', $manufacturers) as $mf_name) {
    $mf_data[] = ['Name' => $mf_name];
  }
  $queries = [
    'SearchToken' => $part_number,
    'Manufacturers' => $mf_data
  ];

  $data = [
    'CompanyID' => $company_id,
    'APIKey' => $api_key,
    'Queries' => [$queries],
    'InStockOnly' => TRUE,
    'ExactMatch' => TRUE,
    'UserAgent' => $_SERVER['HTTP_USER_AGENT'],
    'SourceIP' => ip_address(),
  ];

  $options = [
    'headers' => ['Content-Type' => 'application/json', 'Accept' => 'application/json'],
    'method' => 'POST',
    'data' => json_encode($data),
    'context' => stream_context_create(['ssl' => ['verify_peer' => FALSE, 'verify_peer_name' => FALSE]]),
  ];
  try {
    $response = drupal_http_request($url, $options);
    if ('200' != $response->code) {
      $status_message = !empty($response->status_message) ? '<br />' . $response->status_message : '';
      $error = t('Error while trying to get list of distributors, please try again later', [], ['context' => SOURIAU_COMMON_T_OTHER]) . $status_message;
      throw new Exception($error);
    }
    $response_data = json_decode($response->data);
    $distributors = $response_data->PartResults[0]->Distributors;
    $ret = souriau_common_parsing_tipity_response($distributors);
  }
  catch (Exception $e) {
    return $ret;
  }
  return $ret;
}

/**
 * Helper Function for parsing tipity/ecia response.
 *
 * @param object $response
 *   Response from drupal_http_request().
 *
 * @return array
 *   Parsed service data.
 */
function souriau_common_parsing_tipity_response($response) {
  $distributors = [];
  foreach ($response as $distributor) {
    $buy_link = NULL;
    foreach ($distributor->DistributorResults[0]->Links as $link) {
      if ($link->Type == 'Buy') {
        $buy_link = $link->Url;
        break;
      }
    }
    if (!empty($buy_link)) {
      $distributors[] = [
        'name' => $distributor->Name,
        'quantity' => $distributor->DistributorResults[0]->Stock->QuantityOnHand,
        'pn_link' => $buy_link,
        'part_number' => $distributor->DistributorResults[0]->PartNumber,
      ];
    }
  }

  return $distributors;
}

/**
 * Theme ajax message helper.
 *
 * @param string $messages_location
 *   Message location css selector.
 * @param string $message
 *   Message @see drupal_set_message().
 * @param string $type
 *   Message type @see drupal_set_message().
 *
 * @return array
 *   Ajax command
 */
function souriau_common_ajax_set_message($messages_location, $message, $type = 'status') {
  // Clearup status messages.
  $msgs = theme('status_messages');
  drupal_set_message($message, $type);
  return ajax_command_before($messages_location, '<div><div class="panel-pane pane-page-messages">' . theme('status_messages') . '</div></div>');
}

/**
 * Helper function for generating share button.
 *
 * @param bool $b_white
 *   Render button in white or black color.
 *
 * @return array
 *   Render array with share button.
 */
function souriau_common_get_share_buttons($b_white = FALSE) {
  // Process share buttons.
  $share_icon = [
    '#type' => 'svg_icon',
    '#icon' => 'ico-share',
  ];
  $share_icon = drupal_render($share_icon);
  $share = [
    '#type' => 'container',
    '#attributes' => ['class' => ['b-share']],
  ];

  if ($b_white) {
    $share['#attributes']['class'][] = 'b-white';
  }

  $share['link'] = [
    '#type' => 'markup',
    '#markup' => l($share_icon . t('SHARE', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'javascript:void(0)', [
      'external' => TRUE,
      'attributes' => ['class' => ['share-link', 'a2a_dd']],
      'html' => TRUE,
    ]),
  ];

  return drupal_render($share);
}

/**
 * Unpacks a downloaded archive file.
 *
 * @param string $file
 *   The filename of the archive you wish to extract.
 * @param string $directory
 *   The directory you wish to extract the archive into.
 *
 * @return Archiver
 *   The Archiver object used to extract the archive.
 *
 * @throws Exception
 */
function souriau_common_archive_extract($file, $directory) {
  $archiver = archiver_get_archiver($file);
  if (!$archiver) {
    throw new Exception(t('Cannot extract %file, not a valid archive.', ['%file' => $file]));
  }

  $archiver->extract($directory);
  return $archiver;
}

/**
 * Implements search_api_solr_query_alter().
 */
function souriau_common_search_api_solr_query_alter($call_args, $query) {
  $index = $query->getIndex();
  if ($index->machine_name == 'products_search_index') {
    // Required
    // This is only one "normal" method to get nid from
    // search index. Search API does not allow adding specific fields
    // into solr fl parameter.
    $call_args['params']['fl'] .= ',is_nid';
  }
}

/**
 * Creates a Drupal Ajax 'jсf' command.
 *
 * This method integrate jcf library vith Drupal.ajax .
 *
 * This command is implemented by Drupal.ajax.prototype.commands.jcf()
 * defined in sites/all/themes/custom/souriau/js/souriau_main.js.
 *
 * @param string $method
 *   Jcf library method.
 * @param string $selector
 *   Jcf context selector or ajax.element if NULL.
 *
 * @return array
 *   An array suitable for use with the ajax_render() function.
 *
 * @see sites/all/themes/custom/souriau/js/souriau_main.js
 */
function ajax_command_souriau_common_jcf($method, $selector = NULL) {
  return [
    'command' => 'jcf',
    'method' => $method,
    'selector' => $selector,
  ];
}

/**
 * Search API ID to entity ID convertor.
 *
 * @param array $result
 *   Search API result.
 * @param \SearchApiIndex $index
 *   Search API index.
 *
 * @return array
 *   Extracted entity ids and entity type.
 */
function souriau_common_search_api_extract_entity_ids(array $result, \SearchApiIndex $index) {
  $ret = [
    'ids' => [],
    'entity_type' => '',
  ];

  $controller = search_api_get_datasource_controller($index->item_type);
  $ret['entity_type'] = $index->getEntityType() ? $index->getEntityType() : $index->item_type;
  foreach ($result as $row_index => $row) {
    if ($controller instanceof SearchApiEtDatasourceController) {
      if (SearchApiEtHelper::isValidItemId($row['id'])) {
        $entity_id = SearchApiEtHelper::splitItemId($row['id'], SearchApiEtHelper::ITEM_ID_ENTITY_ID);
        $ret['ids'][] = (int) $entity_id;
      }
    }
    else {
      $ret['ids'][] = $row['id'];
    }
  }
  return $ret;
}

/**
 * Helper function for adding microdata tags.
 */
function souriau_common_microdata_tag($text) {
  return '<span itemprop="name">' . $text . '</span>';
}

/**
 * Helper function for adding microdata link.
 */
function souriau_common_microdata_link($text, $path, $options = []) {
  $options += ['attributes' => ['itemprop' => 'item'], 'html' => TRUE];
  return l(
    souriau_common_microdata_tag($text),
    $path,
    $options
  );
}

/**
 * Helper function for adding microdata position.
 */
function souriau_common_microdata_position($position) {
  return '<meta itemprop="position" content="' . $position . '" />';
}

/**
 * Helper function for adding microdata details to breadcrumb.
 */
function souriau_common_add_microdata_list($breadcrumb) {
  $breadcrumb_new = [];
  foreach ($breadcrumb as $key => $crumb) {
    if (isset($crumb['data']) && strstr($crumb['data'], 'admin-link')) {
      $breadcrumb_new[] = [
        'data' => !empty($crumb['data']) ? $crumb['data'] : $crumb,
        'class' => !empty($crumb['class']) ? $crumb['class'] : [],
      ];
      continue;
    }

    $position_meta = souriau_common_microdata_position($key + 1);

    $breadcrumb_new[] = [
      'data' => !empty($crumb['data']) ? $crumb['data'] . $position_meta : $crumb . $position_meta,
      'class' => !empty($crumb['class']) ? $crumb['class'] : [],
      'itemprop' => 'itemListElement',
      'itemscope' => NULL,
      'itemtype' => 'http://schema.org/ListItem',
    ];
  }

  return $breadcrumb_new;
}

/**
 * Helper function for build breadcrumbs.
 */
function souriau_common_breadcrumbs($variables, $b_white = NULL) {
  $breadcrumb = $variables['breadcrumb'];

  $br_class = ['breadcrumb'];
  if (!empty($b_white)) {
    $br_class[] = $b_white;
  }

  if (!empty($breadcrumb)) {
    $current = array_pop($breadcrumb);
    array_push($breadcrumb, array(
      'data' => $current,
      'class' => array('without-link'),
    ));
    if (isset($variables['admin_link'])) {
      array_push($breadcrumb, array(
        'data' => $variables['admin_link'],
        'class' => array('without-link'),
      ));
    }
    if (isset($variables['webform_admin_link'])) {
      array_push($breadcrumb, array(
        'data' => $variables['webform_admin_link'],
        'class' => array('without-link'),
      ));
    }
    $attributes['class'] = $br_class;
    $output = theme('item_list', [
      'items' => souriau_common_add_microdata_list($breadcrumb),
      'title' => NULL,
      'type' => 'ul',
      'attributes' => [
        'itemtype' => 'http://schema.org/BreadcrumbList',
        'itemscope' => NULL,
      ],
      'wrapper' => [
        'div' => [
          'attributes' => $attributes,
        ],
      ],
    ]);

    return $output;
  }
}

/**
 * Prepare Figure pic element.
 *
 * @param array $element
 *   Element for render. theme_figure_pic().
 * @param array|int|object $file
 *   Image file or image fid.
 */
function souriau_common_element_figure_pic_prepare(array &$element, $file) {
  if (is_array($file)) {
    $file = (object) $file;
  }

  if (isset($file->file) && is_object($file->file)) {
    $file = $file->file;
  }

  if (empty($file->uri) && !empty($file->fid)) {
    $file = file_load($file->fid);
  }

  if (!empty($file->uri)) {
    $element['#path'] = $file->uri;
  }

  if (!empty($file->alt)) {
    $element['#alt'] = $file->alt;
  }

  if (!empty($file->title)) {
    $element['#attributes']['title'] = $file->title;
  }
}

/**
 * Return value of field.
 */
function souriau_common_get_field_value($entity_type, $entity, $field, $langcode = NULL) {
  $value = field_get_items($entity_type, $entity, $field, $langcode);
  if (empty($value)) {
    // Fallback via wrapper.
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    if (!empty($langcode)) {
      $wrapper->language($langcode);
    }
    $value = isset($wrapper->{$field}) ? $wrapper->{$field}->value() : NULL;
    if (!empty($value)) {
      return $value;
    }
    // If still no value.
    return FALSE;
  }
  $value = array_shift($value);

  // If this is colorpicker element, just return hexadecimal value.
  if (isset($value['jquery_colorpicker'])) {
    return '#' . $value['jquery_colorpicker'];
  }

  $value = field_view_value($entity_type, $entity, $field, $value, [], $langcode);
  return drupal_render($value);
}

/**
 * Return display name of taxomony term.
 */
function souriau_common_get_taxonomy_name($entity, $language = NULL) {
  $wrapper = entity_metadata_wrapper('taxonomy_term', $entity);
  if (!empty($language)) {
    $wrapper->language($language->language);
  }
  $field = isset($wrapper->field_display_name) ? 'field_display_name' : (isset($wrapper->name_field) ? 'name_field' : 'name');
  $value = $wrapper->{$field}->value();
  if (empty($value)) {
    $value = $entity->name;
  }

  return $value;
}

/**
 * Return nids of published nodes.
 *
 * @param string $type
 *   Node type.
 * @param string|bool $field
 *   Field name.
 * @param string|bool $field_value
 *   Field value.
 * @param int $published
 *   Node status.
 *
 * @return array
 *   Nids array.
 */
function souriau_common_get_nids($type, $field = FALSE, $field_value = FALSE, $published = 1) {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', $type)
    ->fieldCondition('field_draft', 'value', FALSE);
  // Node status.
  if ($published == 1) {
    $query->propertyCondition('status', $published);
  }
  // Field value.
  if ($field !== FALSE && $field_value !== FALSE) {
    if (!is_array($field_value)) {
      $field_value = [$field_value];
    }
    $query->fieldCondition($field, 'value', $field_value, 'IN');
  }
  $entities = $query->execute();

  if (!empty($entities)) {
    $nodes = reset($entities);
    $nids = [];
    foreach ($nodes as $node) {
      $nids[] = $node->nid;
    }
    return $nids;
  }

  return [];
}

/**
 * Check user access on view node translation.
 */
function souriau_common_access_view_translation($entity, $language) {
  return ((isset($entity->translations->data[$language]) && !empty($entity->translations->data[$language]['status']))
    || (user_access('translate any entity') || user_access("translate $entity->type entities")));
}

/**
 * Custom node_view.
 */
function souriau_common_build_node_view($node, $view_mode = 'full', $langcode = NULL) {
  if (empty($node)) {
    return '';
  }

  if (!isset($langcode)) {
    $langcode = $GLOBALS['language_content']->language;
  }

  // Check user access on view node translation.
  if ($node->type != 'product'  && !souriau_common_access_view_translation($node, $langcode)) {
    return '';
  }

  return node_view($node, $view_mode, $langcode);
}

/**
 * Helper function for get values.
 */
function _souriau_common_get_file_values__download_block($file) {
  global $language;
  $file = is_numeric($file) ? file_load($file) : $file;
  if (!is_object($file)) {
    return;
  }

  $wrapper = entity_metadata_wrapper('file', $file);

  $info = [];
  $info['fid'] = $file->fid;
  $info['file_title'] = $wrapper->language($language->language)->title_field->value();
  if (empty($info['file_title'])) {
    $info['file_title'] = $file->filename;
  }
  $info['file_name'] = $file->filename;
  $info['file_language'] = $wrapper->field_document_language->label();
  $info['file_type'] = $wrapper->field_document_type->label();
  $info['file_size'] = $file->type == 'ipaper' ? '' : format_size($file->filesize);
  switch ($file->filemime) {
    case 'application/pdf':
      $info['file_mimetype'] = t('PDF', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      break;

    case 'souriau/iPaper':
      $info['file_mimetype'] = t('FLIPBOOK', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      break;

    default:
      $info['file_mimetype'] = t('OTHER', [], ['context' => SOURIAU_COMMON_T_OTHER]);
      break;
  }
  $info['file_mimetype_class'] = $file->filemime == 'application/pdf' ? 'ico-pdf' : 'ico-file';
  if ($file->type == '3d_model') {
    $info['file_mimetype_class'] = 'ico-3dmodel';
  }
  elseif ($file->type == 'ipaper') {
    $info['file_mimetype_class'] = 'ico-ipaper';
  }
  $info['file_url'] = $file->type == 'ipaper' ? souriau_common_get_field_value('file', $file, 'field_ipaper_link') : file_create_url($file->uri);
  $file_info = array_filter([
    $info['file_type'],
    $info['file_language'],
    $info['file_size'],
    $info['file_mimetype'],
  ]);
  $info['file_info'] = implode(' - ', $file_info);

  $souriau_settings = variable_get('souriau_common_settings');
  $fid = (isset($souriau_settings['download_center'])) ? $souriau_settings['download_center']['thumbnail_image'] : '';
  $image = [
    '#type' => 'figure_pic',
    '#image' => ($file->type != 'ipaper' && $file->type != '3d_model') ?
    (['uri' => substr($info['file_url'], 0, -4) . '.jpg']) : $fid,
    '#attributes' => [],
  ];
  $info['image'] = drupal_render($image);

  return $info;
}

/**
 * Creates a Drupal Ajax 'caclIndent' command.
 *
 * This method allow auto calc pedding in  filter form on Drupal.ajax .
 *
 * This command is implemented by Drupal.ajax.prototype.commands.calc_indent()
 * defined in sites/all/themes/custom/souriau/js/souriau_main.js.
 *
 * @param string $selector
 *   caclIndent context selector or ajax.element if NULL.
 *
 * @return array
 *   An array suitable for use with the ajax_render() function.
 *
 * @see sites/all/themes/custom/souriau/js/souriau_main.js
 */
function ajax_command_souriau_common_calc_indent($selector = NULL) {
  return [
    'command' => 'calc_indent',
    'selector' => $selector,
  ];
}

/**
 * Product ranges getter.
 *
 * @param object $part_number
 *   Part number node.
 *
 * @return mixed
 *   Product range nodes array of FALSE.
 */
function souriau_common_get_product_ranges($part_number) {
  global $language;

  if (empty($part_number->nid) || empty($part_number->field_parent_product_range)) {
    // Nothing to do here.
    return FALSE;
  }

  $product_ranges_by_part_number = &drupal_static(__FUNCTION__);

  if (isset($product_ranges_by_part_number[$part_number->nid])) {
    return $product_ranges_by_part_number[$part_number->nid];
  }

  $node_wrapper = entity_metadata_wrapper('node', $part_number)->language($language->language);
  $product_ranges_by_part_number[$part_number->nid] = [];
  foreach ($node_wrapper->field_parent_product_range->getIterator() as $product_range_wrapper) {
    $product_ranges_by_part_number[$part_number->nid][] = $product_range_wrapper->value();
  }
  return $product_ranges_by_part_number[$part_number->nid];
}

/**
 * Product series getter.
 *
 * @param mixed $product_range
 *   Product range node.
 *
 * @return mixed
 *   Product series term of FALSE.
 */
function souriau_common_get_product_series($product_range) {
  global $language;

  if (empty($product_range->nid) || empty($product_range->field_product_series)) {
    // Nothing to do here.
    return FALSE;
  }

  $product_series_by_product_range = &drupal_static(__FUNCTION__);

  if (isset($product_series_by_product_range[$product_range->nid])) {
    return $product_series_by_product_range[$product_range->nid];
  }
  $node_wrapper = entity_metadata_wrapper('node', $product_range)->language($language->language);
  $product_series_by_product_range[$product_range->nid] = $node_wrapper->field_product_series->value();
  return $product_series_by_product_range[$product_range->nid];
}

/**
 * Returns a mail string for a variable name.
 *
 * Used by user_mail() and the settings forms to retrieve strings.
 */
function _souriau_common_mail_text($key, $language = NULL, $variables = array(), $replace = TRUE) {
  if (!empty($language) && !is_object($language)) {
    $language = domain_locale_language_load($language);
  }

  $langcode = !empty($language) ? $language->language : LANGUAGE_NONE;

  $text = '';
  $implements = module_implements('mailkeys');
  foreach ($implements as $module_name) {
    $function = '_' . $module_name . '_mail_' . $key;
    if (function_exists($function)) {
      $text = t($function(), [], ['langcode' => $langcode]);
      // Added notrack attribute to exclude a link from being tracked by mailjet.
      $text = str_replace('<a ', '<a rel="notrack" ', $text);
    }
  }

  if ($replace) {
    // We do not sanitize the token replacement, since the output of this
    // replacement is intended for an e-mail message, not a web browser.
    return token_replace($text, $variables, [
      'language' => $language,
      'sanitize' => FALSE,
      'clear' => TRUE
    ]);
  }

  return $text;
}

/**
 * Get Search_API $index and $service provider.
 *
 * @param string $index_name
 *   Index name.
 *
 * @return array
 *   Array($index, $service);
 */
function _souriau_common_get_search_api_objects($index_name) {
  $search_api_objects = &drupal_static(__FUNCTION__);
  if (isset($search_api_objects[$index_name])) {
    return $search_api_objects[$index_name];
  }
  // Create new search api objects.
  $index = search_api_index_load($index_name);
  $server = search_api_server_load($index->server);
  $service_info = search_api_get_service_info($server->class);
  $service = new $service_info['class']($server);

  $search_api_objects[$index_name] = [
    $index,
    $service,
  ];

  return $search_api_objects[$index_name];
}

/**
 * Search context getter for find a part number button.
 *
 * @param object $node
 *   Node object.
 * @param object $node_wrapper
 *   Node entity wrapper.
 *
 * @return array
 *   Search context for given node.
 */
function souriau_common_get_search_context(&$node, &$node_wrapper) {
  $search_context = [];
  switch ($node->type) {
    case SOURIAU_COMMON_CATEGORY_CT:
      $search_context['category'] = $node->nid;
      break;

    case SOURIAU_COMMON_SUBCATEGORY_CT:
      $categories = views_get_view_result('get_catogory_from_subcategory', 'default', $node->nid);
      if (empty($categories)) {
        break;
      }
      $search_context['category'] = $categories[0]->nid;
      $search_context['subcategory'] = $node->nid;
      break;

    case SOURIAU_COMMON_APPLICATION_DOMAIN_CT:
    case SOURIAU_COMMON_APPLICATION_CT:
      $search_context['field_sku_application'] = $node->nid;
      break;

    case SOURIAU_COMMON_PRODUCT_RANGE_CT:
    case SOURIAU_COMMON_PRODUCT_RANGE_HUB_CT:
      $categories = souriau_common_get_categories_for_product_ranges($node);
      if (empty($categories)) {
        break;
      }
      $search_context['category'] = reset($categories);
      $subcategories = views_get_view_result('get_subcategory_from_productrange', 'default', $node->nid);
      if (!empty($subcategories)) {
        $search_context['subcategory'] = $subcategories[0]->nid;
      }
      $product_series = souriau_common_get_product_series($node);
      if (!empty($product_series)) {
        $search_context['product_series'] = $product_series->tid;
      }
      break;

    default:
      $search_context = [];
  }

  return $search_context;
}

/**
 * Product series value getter from product.
 */
function souriau_common_get_product_series_value_from_product($product, $field) {
  $ret = [];
  $part_number = souriau_common_load_part_number_by_sku($product->sku);
  if (!$part_number) {
    return $ret;
  }
  return souriau_common_get_product_series_value($part_number, $field);
}

/**
 * Product series value getter from Part Number.
 */
function souriau_common_get_product_series_value($part_number, $field) {
  $product_series_values = [];

  // Load product ranges.
  $product_ranges = souriau_common_get_product_ranges($part_number);
  if (!$product_ranges) {
    return $product_series_values;
  }

  foreach ($product_ranges as $product_range) {
    // Load taxonomy term.
    $product_series = souriau_common_get_product_series($product_range);
    if (!$product_series) {
      continue;
    }
    $value = $product_series->{$field};
    if (is_array($value)) {
      // For custom fields.
      foreach ($value as $langcode => $item) {
        if (!in_array($item[0]['value'], $product_series_values)) {
          $product_series_values[$product_series->tid . '_' . $langcode] = $item[0]['value'];
        }
      }
    }
    else {
      // For properties of terms, like tid etc.
      $product_series_values[$product_series->tid] = $value;
    }
  }

  return $product_series_values;
}

/**
 * Product series display name.
 */
function souriau_common_get_product_series_name($product_series_value) {
  if (empty($product_series_value)) {
    return '';
  }
  global $language;
  $product_series_wrapper = entity_metadata_wrapper('taxonomy_term', $product_series_value)->language($language->language);
  $product_series_title = !empty($product_series_wrapper->field_display_name)
    ? $product_series_wrapper->field_display_name->value() : (!empty($product_series_wrapper->name_field)
    ? $product_series_wrapper->name_field->value() : $product_series_wrapper->name->value());

  if (empty($product_series_title)) {
    $product_series_title = $product_series_value->name;
  }
  return $product_series_title;
}

/**
 * Get contact recipients.
 */
function souriau_common_get_contact_recipients($submission_render) {
  $selected_category = !empty($submission_render['category']['#value']) ? array_shift($submission_render['category']['#value']) : '';
  $selected_country = !empty($submission_render['country']['#value']) ? array_shift($submission_render['country']['#value']) : '';
  // Get the global settings variable for contact receipeints.
  $default_value = variable_get('souriau_site_settings_variables');
  $global_contact_receipients = $default_value['contact']['default_recepient'];
  $contact_receipients_value = explode("\n", $global_contact_receipients);
  // No receipeints set.
  if (empty($contact_receipients_value)) {
    // Defaule recipient.
    return SOURIAU_COMMON_WEBMASTER;
  }
  foreach ($contact_receipients_value as $row) {
    $receipient_data = explode('|', $row);
    if (empty($receipient_data)) {
      continue;
    }
    // Set 'send to' mail ids here.
    list($receipient_country, $receipient_category, $receipient_mail) = $receipient_data;
    $receipient_mail_ids = !empty($receipient_mail) ? str_replace(';', ',', $receipient_mail) : '';
    // Set mail id for default country.
    if ($selected_category != $receipient_category) {
      continue;
    }
    if ($selected_country == $receipient_country) {
      $recipients = $receipient_mail_ids;
      break;
    }
    elseif ($receipient_country == "default" && (empty($selected_country) || (!empty($selected_country) && $selected_country != $receipient_country))) {
      // Default receipient for the subject.
      $recipients = $receipient_mail_ids;
    }
  }
  return empty($recipients) ? SOURIAU_COMMON_WEBMASTER : trim($recipients);
}

/**
 * Implements hook_metatag_info_alter().
 */
function souriau_common_metatag_info_alter(&$info) {
  $info['tags']['robots']['form']['#default_value'] = [
    "index", "follow"
  ];
  if (user_access('edit all meta fields')) {
    return;
  }
  $info['tags']['robots']['form']['#options'] = [
    'index' => t('Allow search engines to index this page (assumed).'),
    'follow' => t('Allow search engines to follow links on this page (assumed).'),
  ];
}
