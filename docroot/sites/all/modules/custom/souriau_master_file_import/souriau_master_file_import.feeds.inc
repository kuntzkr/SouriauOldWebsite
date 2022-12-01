<?php
/**
 * @file
 * Feeds target.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 */
function souriau_master_file_import_feeds_processor_targets_alter(array &$targets, $entity_type, $bundle) {
  foreach (field_info_instances($entity_type, $bundle) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'entityreference') {
      $targets[$name . ':sku'] = array(
        'name'        => t('@label (Entity reference by SKU)', [
          '@label' => $instance['label'],
        ]),
        'callback'    => 'souriau_master_file_import_feeds_set_target',
        'description' => t('The field instance @label of @id matched by SKU.', [
          '@label' => $instance['label'],
          '@id'    => $name,
        ]),
        'real_target' => $name,
      );

      $targets[$name . ':application'] = array(
        'name'        => t('@label (Entity reference by application and application domain)', [
          '@label' => $instance['label'],
        ]),
        'callback'    => 'souriau_master_file_import_feeds_set_target',
        'description' => t('The field instance @label of @id matched by SKU.', [
          '@label' => $instance['label'],
          '@id'    => $name,
        ]),
        'real_target' => $name,
      );
    }
  }
}

/**
 * Callback for mapping.
 */
function souriau_master_file_import_feeds_set_target($source, $entity, $target, $value) {
  // Don't do anything if we weren't given any data.
  if (empty($value) || (is_array($value) && empty(array_filter($value)))) {
    return;
  }

  // Determine the field we are matching against.
  list($target, $match_key) = explode(':', $target, 2);
  if (!in_array($match_key, ['sku', 'application'])) {
    return;
  }

  // Get some useful field information.
  $info = field_info_field($target);

  // Set the language of the field depending on the mapping.
  $language = isset($mapping['language']) ? $mapping['language'] : LANGUAGE_NONE;

  // Iterate over all values.
  $field = isset($entity->$target) ? $entity->$target : array();
  $entity_ids = souriau_master_file_import_load_entity_by_target($match_key, $value, $source);
  if ($entity_ids) {
    $field[$language] = $entity_ids;
    if ($info['cardinality'] == 1) {
      $field[$language] = [0 => reset($entity_ids)];
    }
  }
  // Add the field to the entity definition.
  $entity->{$target} = $field;
}

/**
 * Helper function for return target entity ID.
 */
function souriau_master_file_import_load_entity_by_target($match_key, $values, $source) {
  $error_lvl = variable_get('import_log_level', IMPORT_LOG_DISABLE);
  if (!is_array($values)) {
    $values = [$values];
  }
  switch ($match_key) {
    case 'sku':
      $target_ids = souriau_master_file_import_commerce_product_get_ids_by_sku($values, $source);
      break;

    case 'application':
      $target_ids = array_merge(
        souriau_common_get_nids('application', 'field_machine_name', $values, 0),
        souriau_common_get_nids('applicationdomain', 'field_machine_name', $values, 0)
      );

      break;

    default:
      $target_ids = [];
      break;
  }

  if ($error_lvl != IMPORT_LOG_DISABLE && count($target_ids) != count($values)) {
    $message = t('Could not find next entities:');
    if (!empty($target_ids)) {
      $founded = [];
      $type = ($match_key == 'sku') ? 'commerce_product' : 'node';
      $entities = entity_load($type, $target_ids);
      foreach ($entities as $entity) {
        if ($type == 'commerce_product') {
          $founded[] = $entity->sku;
        }
        if ($type == 'node' && isset($entity->field_machine_name)) {
          $wrapper = entity_metadata_wrapper($type, $entity);
          $founded[] = $wrapper->field_machine_name->value();
        }
      }
      $values = array_diff($values, $founded);
    }
    $message .= '<br>' . $match_key . ': ' . implode(', ', $values);
    $source->log('import', $message);
  }

  if (empty($target_ids)) {
    return FALSE;
  }

  foreach ($target_ids as &$id) {
    $id = ['target_id' => $id];
  }

  return $target_ids;
}

/**
 * Helper function for get active product_ids by sku.
 *
 * @param array $sku
 *   Array with sku values.
 *
 * @return array
 *   return array with IDs.
 */
function souriau_master_file_import_commerce_product_get_ids_by_sku($sku = []) {
  if (empty($sku)) {
    return [];
  }
  if (!is_array($sku)) {
    $sku = [$sku];
  }

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'commerce_product')
      ->propertyCondition('status', 1)
      ->propertyCondition('sku', $sku, 'IN')
      ->addMetaData('account', user_load(1));
  $result = $query->execute();

  if (empty($result['commerce_product'])) {
    return [];
  }

  return array_keys($result['commerce_product']);
}
