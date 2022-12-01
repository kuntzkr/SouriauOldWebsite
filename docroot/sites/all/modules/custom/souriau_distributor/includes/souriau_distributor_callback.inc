<?php
/**
 * @file
 * Souriau Newsletter.inc.
 */

/**
 * Distributors stock callback.
 */
function souriau_distributor_callback($pn, $ajax) {
  // Get distributor managing system.
  $brand = NULL;
  $souriau_setting = variable_get('souriau_distributor_settings', []);
  $distributor_system = isset($souriau_setting['manage']['setting']) ? $souriau_setting['manage']['setting'] : FALSE;
  $default_distributors = !empty($souriau_setting['default']) ? array_filter($souriau_setting['default']) : [];

  // Get company of the part number.
  $node = souriau_common_load_part_number_by_sku($pn);
  $node_wrapper = entity_metadata_wrapper('node', $node);
  $sku = $node_wrapper->field_sku_products->value();
  $brand = souriau_common_get_field_value('commerce_product', $sku, 'field_sku_company');

  if (!$distributor_system) {
    // Return worldwide callback.
    return souriau_distributor_worldwide_callback($pn, $default_distributors, $brand);
  }
  // Return tipity callback.
  return souriau_distributor_tipity_callback($pn, $default_distributors, $brand);
}


/**
 * Distributors tipity ajax callback.
 */
function souriau_distributor_tipity_callback($part_number, $default, $brand = NULL) {
  try {
    $distributors = souriau_common_tipity_service($part_number);
    $is_default = FALSE;
    $show_stock_info = TRUE;
    if (!$distributors) {
      if (empty($default)) {
        $contact_link = l(t('contact us.', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'contact');
        $error = t('Default Distributors weren\'t defined. If you need further assistance, please', ['context' => SOURIAU_COMMON_T_OTHER]) . ' ' . $contact_link;
        throw new Exception($error);
      }
      // Load default distributors.
      $distributors = _souriau_distributor_get_default_distributors($default);
      // Need only the distributors that has brands that matches the
      // selected part-number's company.
      foreach ($distributors as $key => &$distributor) {
        $distributor_wrapper = entity_metadata_wrapper('distributor', $distributor);
        $distributor_brand = $distributor_wrapper->field_distributor_brand->value();
        if (in_array(strtolower($brand), $distributor_brand)) {
          continue;
        }
        unset($distributors[$key]);
      }
      // Enable tracker for distributors.
      $is_default = TRUE;
    }

    if ($is_default) {
      $distributors = souriau_distributor_generate_entity($distributors);
      $distributors = souriau_distributor_prepare_distributors($distributors, $is_default);
    }

    // Pass an extra parameter to template if the partnumber brand is 'Sunbank'.
    if ($brand == 'SUNBANK') {
      $show_stock_info = FALSE;
    }

    $output = theme('distributor_popup', [
      '_html' => [
        'distributors' => $distributors,
        'manage' => 'tipity',
        'is_default' => $is_default,
        // If $is_default, then stock level always will be '0'. So we'll hide it.
        'show_stock' => $is_default ? FALSE : $show_stock_info,
      ]
    ]);

    $commands[] = ctools_modal_command_display('', $output);
    $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['where-to-buy-popup']);
    return ['#type' => 'ajax', '#commands' => $commands];
  }
  catch (Exception $e) {
    watchdog('distributors_callback', $e->getMessage());
    $commands[] = ctools_modal_command_display('', $e->getMessage());
    $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['where-to-buy-popup']);
    return ['#type' => 'ajax', '#commands' => $commands];
  }
}

/**
 * Distributors worldwide ajax callback.
 *
 * @param string $part_number
 *   Part number.
 * @param array $default
 *   Default distributors ID.
 *
 * @return array
 *   Ajax command array
 */
function souriau_distributor_worldwide_callback($part_number, $default, $brand = NULL) {
  try {
    module_load_include('inc', 'souriau_common', 'souriau_common.rdb');
    $distributors = souriau_common_rdb_get_part_number_stock_status($part_number);
    $is_default = FALSE;
    $show_stock_info = TRUE;
    if (!$distributors) {
      if (empty($default)) {
        $contact_link = l(t('contact us.', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'contact');
        $error = t('Default Distributors weren\'t defined. If you need further assistance, please', ['context' => SOURIAU_COMMON_T_OTHER]) . ' ' . $contact_link;
        throw new Exception($error);
      }
      // Load default distributors.
      $distributors = _souriau_distributor_get_default_distributors($default);
      // Need only the distributors that has brands that matches the
      // selected part-number's company.
      foreach ($distributors as $key => &$distributor) {
        $distributor_wrapper = entity_metadata_wrapper('distributor', $distributor);
        $distributor_brand = $distributor_wrapper->field_distributor_brand->value();
        if (in_array(strtolower($brand), $distributor_brand)) {
          continue;
        }
        unset($distributors[$key]);
      }
      // Enable tracker for distributors.
      $is_default = TRUE;
    }
    // Pass an extra parameter to template if the partnumber brand is 'Sunbank'.
    if ($brand == 'SUNBANK') {
      $show_stock_info = FALSE;
    }

    $distributors = souriau_distributor_prepare_distributors($distributors, $is_default);

    $output = theme('distributor_popup', [
      '_html' => [
        'distributors' => $distributors,
        'manage' => 'worldwide',
        // If $is_default, then stock level always will be '0'. So we'll hide it.
        'show_stock' => $is_default ? FALSE : $show_stock_info,
      ]
    ]);

    $commands[] = ctools_modal_command_display('', $output);
    $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['where-to-buy-popup']);
    return ['#type' => 'ajax', '#commands' => $commands];
  }
  catch (Exception $e) {
    watchdog('distributors_callback', $e->getMessage());
    $commands[] = ctools_modal_command_display('', $e->getMessage());
    $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['where-to-buy-popup']);
    return ['#type' => 'ajax', '#commands' => $commands];
  }
}

/**
 * Helper Function for generate distributor entities.
 *
 * @param array $distributors
 *   Dsitributors array.
 *
 * @return array|bool
 *   Generated entities objects array or FALSE on error.
 */
function souriau_distributor_generate_entity($distributors) {
  if (!is_array($distributors) || empty($distributors)) {
    return FALSE;
  }
  $entities = [];
  foreach ($distributors as $distributor) {
    $entity = entity_create('distributor', ['type' => 'distributor']);
    foreach ($distributor as $field_name => $value) {
      $entity->$field_name = $value;
    }
    $entities[] = $entity;
  }
  return $entities;
}

/**
 * Helper function for add Distributor Info by distributor code.
 */
function souriau_distributor_prepare_distributors($distributors, $is_default) {
  foreach ($distributors as $key => &$distributor) {
    // Add tracker for default distributors.
    $distributor->is_default = $is_default;

    if (!isset($distributor->type)) {
      $distributor->type = 'distributor';
      $distributor = get_object_vars($distributor);
      $distributor = entity_create('distributor', $distributor);
    }

    $distributor->getInfo();
  }
  return $distributors;
}

/**
 * Default distributors getter.
 *
 * @param array $default_ids
 *   Array with default distributors ids.
 *
 * @return mixed
 *   return array with distributor entities.
 */
function _souriau_distributor_get_default_distributors($default_ids) {
  foreach ($default_ids as &$id) {
    $id = $id['entity_id'];
  }
  return entity_load('distributor', $default_ids);
}
