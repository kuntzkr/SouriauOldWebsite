<?php

/**
 * @file
 * Draft moderation translations.
 */

/**
 * Check if the Entity Translation is empty or not.
 */
function draft_moderation_translation_is_empty($entity_type, $entity, $langcode) {
  if (function_exists('title_entity_label')) {
    list (, , $bundle) = entity_extract_ids($entity_type, $entity);
    $entity_info = entity_get_info($entity_type);
    if (!empty($entity_info['entity keys']['label'])) {
      $legacy_field = $entity_info['entity keys']['label'];
      if (title_field_replacement_enabled($entity_type, $bundle, $legacy_field)) {
        $title = title_entity_label($entity, $entity_type, $langcode);
        if (!empty($title)) {
          return FALSE;
        }
      }
    }
  }
  return TRUE;
}

/**
 * Update Entity translations.
 */
function draft_moderation_translations_update($entity, $entity_type, $hook = 'presave') {
  draft_moderation_translations_initiate($entity, $entity_type);
}

/**
 * Delete Entity translations.
 */
function draft_moderation_translations_delete($entity, $entity_type, $langcode) {
  if (!empty($entity->is_draft) && !empty($entity->edition_id)) {
    $deleted = &drupal_static('draft_moderation_node_delete', array());
    // Doesn't update translations when source node deleted.
    if (!in_array($entity->edition_id, $deleted)) {
      $production_entity = entity_load_single($entity_type, $entity->edition_id);
      $handler_prod = entity_translation_get_handler($entity_type, $production_entity);
      $handler_prod->removeTranslation($langcode);
      entity_save($entity_type, $production_entity);
    }
  }
}

/**
 * Important: Initiate all translations.
 *
 * Initiate with default language of Central domain.
 */
function draft_moderation_translations_initiate($entity, $entity_type, $force = FALSE) {
  list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  if (!module_exists('entity_translation') || !entity_translation_enabled_bundle($entity_type, $bundle)) {
    // Nothing to do.
    return;
  }

  // Do nothing if not creating entity.
  $handler = entity_translation_get_handler($entity_type, $entity, TRUE);
  $translations = $handler->getTranslations();

  if (empty($translations)) {
    // Nothing to do.
    return;
  }

  if (isset($translations->hook) && !$force) {
    // Do nothing if not creating entity.
    if (empty($translations->hook[$translations->original]) || ('insert' != $translations->hook[$translations->original]['hook'])) {
      return;
    }
  }

  // Languages.
  $original_langcode = $translations->original;
  $langcode = $handler->getFormLanguage();

  if ($force) {
    $force_full_update = TRUE;
  }
  else {
    // If it is first import we need to FORCE update of all fields.
    // FOR MASTER FILE IMPORT.
    $force_full_update = FALSE;
    if (isset($entity->created) && $entity->created == 1) {
      $force_full_update = TRUE;
      $entity->created = $entity->changed;
    }
    elseif ('node' == $entity_type) {
      // Do nothing if creating entity from BO.
      return;
    }
    if ($langcode != $original_langcode) {
      $force_full_update = FALSE;
      return;
    }
    /* end FOR MASTER FILE IMPORT. */
  }

  // Get Central.
  $domain_id = domain_default_id();
  if (!empty($entity->domains_raw) && is_array($entity->domains_raw)) {
    $domain_id = reset($entity->domains_raw);
  }
  elseif (!empty($entity->domains) && is_array($entity->domains)) {
    $domain_id = reset($entity->domains);
  }

  if ($domain_id) {
    $domains_languages = _domain_locale_get_domains_languages();
    if (isset($domains_languages[$domain_id])) {

      // Unset($domains_languages[$domain_id][$original_langcode]).
      if (isset($translations->data[$original_langcode])) {
        $new_t9n = $translations->data[$original_langcode];
        $new_t9n['translate'] = 1;
        if (!isset($new_t9n['status'])) {
          $new_t9n['status'] = 0;
        }
        $new_t9n['source'] = $original_langcode;
        foreach (field_info_instances($entity_type, $bundle) as $instance) {
          $field = field_info_field_by_id($instance['field_id']);
          $field_name = $field['field_name'];
          if (!empty($entity->$field_name) && field_is_translatable($entity_type, $field)) {
            foreach ($domains_languages[$domain_id] as $langcode => $weight) {
              if (($force_full_update || !isset($translations->data[$langcode])) && isset($entity->{$field_name}[$original_langcode])) {
                // Init translation from ORIGINAL.
                if ($force_full_update || empty($entity->{$field_name}[$langcode])) {
                  // Copy filed value with support for Field_Collection.
                  draft_moderation_copy_field_translation($entity_type, $entity, $entity, $field, $original_langcode, $langcode);
                }
              }
              elseif (isset($entity->{$field_name}[LANGUAGE_NONE])) {
                // Init defaults from LANGUAGE_NONE.
                if (empty($entity->{$field_name}[$langcode])) {
                  $entity->{$field_name}[$langcode] = $entity->{$field_name}[LANGUAGE_NONE];
                }
              }
            }
          }
        }

        list($entity_id, $revision_id) = entity_extract_ids($entity_type, $entity);
        foreach ($domains_languages[$domain_id] as $langcode => $weight) {
          if (!isset($translations->data[$langcode])) {
            $new_t9n['language'] = $langcode;
            $new_t9n['status'] = 0;

            $source_langcode = _get_source_langcode($langcode);
            // For Create Content Translation only.
            // Set translation status:
            // 0 = uptodate for all affiliated languages,
            // 1 = outdated for all other languages.
            $new_t9n['translate'] = ($source_langcode == $original_langcode) ? 0 : 1;

            $handler->setTranslation($new_t9n);
          }

          // Meta tags support.
          if (($original_langcode != $langcode) && isset($entity->metatags[$original_langcode])) {
            $_metatags = array($langcode => $entity->metatags[$original_langcode]);
            if (module_exists('metatag')) {
              // Ensure that correct function declaration is used.
              metatag_metatags_save($entity_type, $entity_id, $revision_id, $_metatags, $langcode);
            }
          }
        }
      }
    }
  }
}

/**
 * Update the translation from original.
 */
function draft_moderation_translations_update_from_original($entity, $entity_type, $langcode) {
  list(, , $bundle) = entity_extract_ids($entity_type, $entity);
  if (!module_exists('entity_translation') || !entity_translation_enabled_bundle($entity_type, $bundle)) {
    return;
  }

  $handler = entity_translation_get_handler($entity_type, $entity);
  $handler->setFormLanguage($langcode);
  $translations = $handler->getTranslations();

  if (empty($translations)) {
    // Nothing to do.
    return;
  }

  $original_langcode = $translations->original;
  // If Current $language is Original
  // then there is nothing to do.
  if ($original_langcode == $langcode) {
    return;
  }

  // Find source langcode.
  $source_langcode = draft_moderation_get_source_langcode($langcode, $original_langcode);

  // Load Production Entity if exists.
  // @important:
  // translations are copied from published Production Entity to Draft.
  if (!empty($entity->is_draft) && !empty($entity->edition_id)) {
    $production_entity = entity_load_single($entity_type, $entity->edition_id);
    $handler_prod = entity_translation_get_handler($entity_type, $production_entity);
    $translations = $handler_prod->getTranslations();
  }
  else {
    $production_entity = clone $entity;
  }

  if (isset($translations->data[$original_langcode])) {
    foreach (field_info_instances($entity_type, $bundle) as $instance) {
      $field = field_info_field_by_id($instance['field_id']);
      $field_name = $field['field_name'];
      if (!empty($production_entity->$field_name) && field_is_translatable($entity_type, $field)) {
        // Copy field value from original translation
        // with support for Field Collection.
        draft_moderation_copy_field_translation($entity_type, $production_entity, $entity, $field, $original_langcode, $langcode, $source_langcode);
      }
    }

    // Meta tags support.
    if (isset($production_entity->metatags[$original_langcode])) {
      $entity->metatags[$langcode] = $production_entity->metatags[$original_langcode];
    }
    else {
      $entity->metatags = NULL;
    }

    // Update legacy title from original.
    if (isset($production_entity->title_field[$original_langcode][0]['value'])) {
      $entity->title = $production_entity->title_field[$original_langcode][0]['value'];
    }
  }
}

/**
 * Helper function to publish $draft node.
 *
 * Copies content of the $draft node to $production (published node).
 */
function draft_moderation_publish($draft, $production, $langcode = NULL) {
  $entity_type = 'node';
  $bundle = $draft->type;
  $check_outdated = TRUE;

  $t9n_draft_handler = entity_translation_get_handler($entity_type, $draft);
  $t9n_handler = entity_translation_get_handler($entity_type, $production, TRUE);
  $draft_t9ns = $t9n_draft_handler->getTranslations();

  if (!$langcode) {
    $langcode = $t9n_draft_handler->getFormLanguage();
  }

  // Important to handle correctly
  // which translation is published.
  $t9n_draft_handler->setFormLanguage($langcode);
  $t9n_handler->setFormLanguage($langcode);

  $original_langcode = $draft_t9ns->original;
  // Check right here and right now
  // and initiate other translations if required.
  if (($original_langcode == $langcode) && (count($draft_t9ns->data) < 2)) {
    // Initiate translations.
    draft_moderation_translations_initiate($draft, $entity_type, $force = TRUE);
    // Save the initiated translations.
    // @important, don't save if no new translation was added.
    $draft_t9ns = $t9n_draft_handler->getTranslations();
    if (count($draft_t9ns->data) >= 2) {
      entity_save($entity_type, $draft);
    }
    $check_outdated = FALSE;
  }

  $lang_codes = (array) $langcode;
  foreach ($lang_codes as $lang_code) {
    $is_original = ($t9n_draft_handler->getTranslations()->original == $lang_code);

    if (is_array($draft_t9ns->data) && isset($draft_t9ns->data[$lang_code])) {
      $t9n = $draft_t9ns->data[$lang_code];
      $t9n['status'] = 1;
      $t9n['translate'] = 0;
      $t9n['workflow'] = DRAFT_MODERATION_WORKFLOW_VALIDATED;
      $outdated = FALSE;

      foreach (field_info_instances($entity_type, $bundle) as $instance) {
        $field = field_info_field_by_id($instance['field_id']);
        $field_name = $field['field_name'];

        $skip_fields = array(
          DRAFT_MODERATION_FIELD_REF,
          DRAFT_MODERATION_FIELD_FLAG,
          DRAFT_MODERATION_FIELD_LOG,
          DRAFT_MODERATION_FIELD_MODIFICATION_TYPE,
        );
        if (!in_array($field_name, $skip_fields)) {
          if (field_is_translatable($entity_type, $field)) {
            if (isset($draft->{$field_name}[$lang_code])) {
              // If we updating.
              if ($is_original && (!isset($production->{$field_name}[$lang_code]) || $production->{$field_name}[$lang_code] != $draft->{$field_name}[$lang_code])) {
                // Mark translations as outdated later.
                $outdated = TRUE;
              }
              // Copy field value from original translation
              // with support for Field Collection.
              draft_moderation_copy_field_translation($entity_type, $draft, $production, $field, $lang_code, $lang_code);
            }
            else {
              $production->{$field_name}[$lang_code] = array();
            }
          }
          elseif ($is_original) {
            // Copy untranslatable fields.
            $production->{$field_name} = $draft->{$field_name};
          }
        }
      }

      $t9n_draft_handler->setTranslation($t9n);

      $t9n_handler->setTranslation($t9n);
      if ($check_outdated && $outdated) {
        // Mark all affiliated translations as outdated.
        $t9n_draft_handler->setOutdated(1);
      }
    }
  }

  $t9n_draft_handler->saveTranslations();
  $t9n_handler->saveTranslations();

  $production->status = 1;

  // @Important: sync legacy_field title.
  if (isset($draft->title_field[$lang_code][0]['value'])) {
    $production->title = $draft->title_field[$lang_code][0]['value'];
  }
  elseif (!empty($draft->title)) {
    $production->title = $draft->title;
  }

  // Meta tags support.
  if (isset($draft->metatags[$langcode])) {
    $production->metatags[$langcode] = $draft->metatags[$langcode];
  }
  else {
    $production->metatags = NULL;
  }

  // Pathalias.
  foreach ($lang_codes as $lang_code) {
    if (module_exists('path')) {
      $draft_uri = entity_uri($entity_type, $draft);
      $draft_alias = drupal_get_path_alias($draft_uri['path'], $lang_code);

      if ($entity_type == 'node' && $draft_alias == $draft_uri['path'] && module_exists('pathauto')) {
        if (pathauto_pattern_load_by_entity($entity_type, $draft->type, $lang_code)) {
          module_load_include('inc', 'pathauto');
          $draft_alias_path = pathauto_create_alias('node', 'insert', $draft_uri['path'], array('node' => $draft), $draft->type, $lang_code);
          if (is_array($draft_alias_path) && isset($draft_alias_path['alias'])) {
            $draft_alias = $draft_alias_path['alias'];
          }
        }
      }

      if (!empty($draft_alias) && $draft_alias != $draft_uri['path']) {
        $prod_alias = str_replace('draft/', '', $draft_alias);
        $p_uri = entity_uri($entity_type, $production);
        $conditions = array('source' => $p_uri['path']);
        $conditions['language'] = $lang_code;
        $path = path_load($conditions);
        if ($path === FALSE) {
          $path = array(
            'pid' => NULL,
            'source' => 'node/' . $production->nid,
            'alias' => $prod_alias,
            'language' => $lang_code,
            'pathauto' => 0,
          );
          path_save($path);
        }
        elseif ($prod_alias !== $path['alias']) {
          $path = array_merge($path, array(
            'source' => 'node/' . $production->nid,
            'alias' => $prod_alias,
            'language' => $lang_code,
            'pathauto' => 0,
          ));
          path_save($path);
        }
      }
    }
  }
  if (!isset($production->path['pathauto'])) {
    $production->path['pathauto'] = 0;
  }
  /* End Pathalias. */

  // Save facets settings for category to published nid.
  if ($production->type == 'category') {
    $_domain = domain_get_domain();
    $global_facet_settings = variable_get('souriau_common_fasets');
    $draft_facet_settings = variable_get("souriau_common_fasets_$draft->nid", $global_facet_settings);
    domain_conf_variable_set($_domain['domain_id'], "souriau_common_fasets_$production->nid", $draft_facet_settings);
  }

  $production_wrapper = entity_metadata_wrapper($entity_type, $production);
  $production_wrapper->save();
}

/**
 * Translations overview page callback.
 *
 * Almost complete port from entity_translation.
 */
function draft_moderation_translation_overview($entity_type, $entity, $callback = NULL) {
  module_load_include('inc', 'entity_translation', 'entity_translation.admin');
  if ($entity_type !== 'node' || !($mode = draft_moderation_supported_type($entity->type, $entity_type)) || !isset($entity->is_draft) || !$entity->is_draft) {
    return entity_translation_overview($entity_type, $entity, $callback);
  }

  $workflow_mode = DRAFT_MODERATION_WORKFLOW == $mode;

  $handler = entity_translation_get_handler($entity_type, $entity);
  $handler->initPathScheme();

  $production = node_load($entity->edition_id);
  if (!$production) {
    return entity_translation_overview($entity_type, $entity, $callback);
  }

  $prod_handler = entity_translation_get_handler($entity_type, $production);
  $prod_translations = $prod_handler->getTranslations();

  // Initialize translations if they are empty.
  $translations = $handler->getTranslations();
  if (empty($translations->original)) {
    $handler->initTranslations();
    $handler->saveTranslations();
  }

  // Ensure that we have a coherent status between entity language and field
  // languages.
  if ($handler->initOriginalTranslation()) {
    // FIXME!
    field_attach_presave($entity_type, $entity);
    field_attach_update($entity_type, $entity);
  }

  $header = array(
    t('Language', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
    t('Translation', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
    t('Production status', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)),
  );
  if ($workflow_mode) {
    $header[] = t('Moderation status', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
  }
  $header[] = t('Operations', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
  $all_languages = language_list();
  $languages = entity_translation_languages();
  $source = $translations->original;
  $path = $handler->getViewPath();
  $rows = array();

  if (drupal_multilingual()) {
    // If we have a view path defined for the current entity get the switch
    // links based on it.
    if ($path) {
      $links = EntityTranslationDefaultHandler::languageSwitchLinks($path);
    }

    foreach ($languages as $language) {
      $options = array();
      $language_name = $language->name;
      $langcode = $language->language;
      $source_lang_code = _get_source_langcode($langcode);
      $edit_path = $handler->getEditPath($langcode);
      $add_path = "{$handler->getEditPath()}/add/$source/$langcode";

      if (!empty($language->source) && isset($all_languages[$language->source])) {
        $language_name .= ' (' . $all_languages[$language->source]->name . ')';
      }

      if ($edit_path) {
        $add_links = EntityTranslationDefaultHandler::languageSwitchLinks($add_path);
        $edit_links = EntityTranslationDefaultHandler::languageSwitchLinks($edit_path);
      }
      $workflow_status = '';
      if (isset($translations->data[$langcode])) {
        // Existing translation in the translation set: display status.
        $is_original = $langcode == $translations->original;
        $translation = $translations->data[$langcode];
        $workflow = $translation['workflow'];
        $prod_translation = isset($prod_translations->data[$langcode]) ? $prod_translations->data[$langcode] : NULL;

        $label = _entity_translation_label($entity_type, $entity, $langcode);
        $link = isset($links->links[$langcode]['href']) ? $links->links[$langcode] : array(
          'href' => $path,
          'language' => $language
        );
        $row_title = l($label, $link['href'], $link);

        if (empty($link['href'])) {
          $row_title = $is_original ? $label : t('n/a', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
        }

        if ($edit_path && $handler->getAccess('update') && $handler->getTranslationAccess($langcode) && _draft_moderation_check_access($mode, $translation)) {
          $link = isset($edit_links->links[$langcode]['href']) ? $edit_links->links[$langcode] : array(
            'href' => $edit_path,
            'language' => $language
          );
          $link['query'] = isset($_GET['destination']) ? drupal_get_destination() : FALSE;
          $options[] = l(t('Edit', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)), $link['href'], $link);
        }

        $row_class = '';
        $prod_status = t('New');
        if ($prod_translation) {
          if ($production->status && $prod_translation['status']) {
            $prod_status = t('Published', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
          }
          else {
            $prod_status = t('Not published', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
          }
        }

        $status = '';

        if ($workflow_mode) {
          $workflow_status = _draft_moderation_workflow_states($workflow);
        }

        if ($translation['translate']) {
          // Outdated.
          $row_class = 'red';
          $status = t('Outdated', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
        }
        else {
          if ($prod_translation) {
            if ($prod_translation['changed'] < $translation['changed']) {
              $row_class = 'blue';
              $status = t('Updated', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
            }
          }
          if ($workflow_mode) {
            switch ($workflow) {
              case DRAFT_MODERATION_WORKFLOW_TO_VALIDATE:
                $row_class = 'orange';
                break;

              case DRAFT_MODERATION_WORKFLOW_REFUSED:
                $row_class = 'error';
                break;

              case DRAFT_MODERATION_WORKFLOW_IN_PROGRESS:
                $row_class = 'red';
                break;

            }
          }
        }
        if ($workflow_mode) {
          if ($status) {
            $workflow_status .= " ($status)";
          }
          $status = $prod_status;
        }
        else {
          if ($status) {
            $status = $prod_status . " ($status)";
          }
          else {
            $status = $prod_status;
          }
        }
        if ($is_original) {
          $language_name = t('<strong>@language_name</strong>', array('@language_name' => $language_name));
        }
      }
      else {
        // No such translation in the set yet: help user to create it.
        $row_title = /*$source_name = */
          t('n/a', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));

        if ($source != $langcode && $handler->getAccess('update')) {
          list(, , $bundle) = entity_extract_ids($entity_type, $entity);
          $translatable = FALSE;

          foreach (field_info_instances($entity_type, $bundle) as $instance) {
            $field_name = $instance['field_name'];
            $field = field_info_field($field_name);
            if ($field['translatable']) {
              $translatable = TRUE;
              break;
            }
          }

          $link = isset($add_links->links[$langcode]['href']) ? $add_links->links[$langcode] : array(
            'href' => $add_path,
            'language' => $language
          );
          if (!$translatable) {
            $options[] = t('No translatable fields', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
          }
          else {
            if ($source_lang_code != $langcode && isset($translations->data[$source_lang_code])) {
              $add_from_source_path = "{$handler->getEditPath()}/add/$source_lang_code/$langcode";
              $link = array(
                'href' => $add_from_source_path,
                'language' => $language
              );
              $link['query'] = isset($_GET['destination']) ? drupal_get_destination() : FALSE;
              $options[] = l(t('Add from @language_name',
                array('@language_name' => $all_languages[$source_lang_code]->name),
                array('context' => DRAFT_MODERATION_T_CONTEXT)), $link['href'], $link);
            }
            else {
              $options[] = l(t('Add', array(), array('context' => DRAFT_MODERATION_T_CONTEXT)), $link['href'], $link);
            }
          }
        }
        $status = t('Not translated', array(), array('context' => DRAFT_MODERATION_T_CONTEXT));
        $row_class = 'error';
      }
      $row = array(
        'data' => array($language_name, $row_title, $status),
        'class' => array($row_class),
      );
      if ($workflow_mode) {
        $row['data'][] = $workflow_status;
      }
      $row['data'][] = implode(" | ", $options);
      $rows[] = $row;
    }
  }

  drupal_set_title(t('Translations of %label', array('%label' => $handler->getLabel()), array('context' => DRAFT_MODERATION_T_CONTEXT)), PASS_THROUGH);

  // Add metadata to the build render allow to let other modules know about
  // which entity this is.
  $build['#entity_type'] = $entity_type;
  $build['#entity'] = $entity;
  $build['entity_translation_overview'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}

/**
 * Copy Field collection Field values.
 *
 * @param string $entity_type
 *   Type of the entity.
 * @param object $orig_entity
 *   Entity to copy field value FROM.
 * @param object $dest_entity
 *   Entity to copy field value TO.
 * @param array $field
 *   The Field instance to copy.
 * @param string $original_langcode
 *   The original language of the Entity.
 * @param string $langcode
 *   The destination language to copy field value TO.
 * @param string $source_langcode
 *   The source language to copy field value FROM.
 *   Optional param If empty the value is taken from the original language.
 */
function draft_moderation_copy_field_translation($entity_type, &$orig_entity, &$dest_entity, $field, $original_langcode, $langcode, $source_langcode = NULL) {
  $field_name = $field['field_name'];
  // IF there is source_langcode translation - we use it.
  // OTHERWISE stick to original_langcode translation.
  if (!empty($source_langcode) && isset($orig_entity->{$field_name}[$source_langcode])) {
    $original_langcode = $source_langcode;
  }

  // Special hack for Field_Collection or paragraphs.
  if (('field_collection' == $field['type']) && !empty($orig_entity->{$field_name}[$original_langcode])) {
    $new_field_data = array();

    // Collect Field Collection Id's.
    $field_ids = _draft_moderation_collect_field_ids($orig_entity, $field_name, $original_langcode);

    // Process Field Collection fields.
    $items = field_collection_item_load_multiple($field_ids);
    foreach ($items as $item) {
      $new_fc_item = _draft_moderation_prepare_new_item($item, $entity_type, $dest_entity, $langcode);
      $new_field_data[] = array('value' => $new_fc_item->item_id);
    }

    $dest_entity->{$field_name}[$langcode] = $new_field_data;
  }
  elseif (('paragraphs' == $field['type']) && !empty($orig_entity->{$field_name}[$original_langcode])) {
    $new_field_data = array();

    // Collect Paragraphs Id's.
    $field_ids = _draft_moderation_collect_field_ids($orig_entity, $field_name, $original_langcode);

    // Process Paragraphs fields.
    $items = paragraphs_item_load_multiple($field_ids);
    foreach ($items as $item) {
      $new_paragraph = _draft_moderation_prepare_new_item($item, $entity_type, $dest_entity, $langcode);
      $new_field_data[] = array(
        'value' => $new_paragraph->item_id,
        'revision_id' => $new_paragraph->revision_id,
      );
    }

    $dest_entity->{$field_name}[$langcode] = $new_field_data;
  }
  else {
    // Check if original value exist.
    if (isset($orig_entity->{$field_name}[$original_langcode])) {
      $dest_entity->{$field_name}[$langcode] = $orig_entity->{$field_name}[$original_langcode];
    }
    else {
      // Init empty value if original value is not set.
      $dest_entity->{$field_name}[$langcode] = array();
    }
  }

}

/**
 * Helper function to collect field ids of Paragraphs or FieldCollection.
 */
function _draft_moderation_collect_field_ids($orig_entity, $field_name, $original_langcode) {
  $field_ids = array();
  foreach ($orig_entity->{$field_name}[$original_langcode] as $value) {
    if (isset($value)) {
      $field_ids[] = $value['value'];
    }
  }
  return $field_ids;
}

/**
 * Helper function to prepare field collection or paragraph items.
 */
function _draft_moderation_prepare_new_item($item, $entity_type, &$dest_entity, $langcode) {
  $new_item = clone $item;
  $new_item->item_id = NULL;
  if (isset($new_item->revision_id)) {
    $new_item->revision_id = NULL;
  }
  if (isset($new_item->is_new)) {
    $new_item->is_new = TRUE;
  }
  $new_item->setHostEntity($entity_type, $dest_entity, $langcode);
  $new_item->save($skip_host_save = TRUE);

  return $new_item;
}
