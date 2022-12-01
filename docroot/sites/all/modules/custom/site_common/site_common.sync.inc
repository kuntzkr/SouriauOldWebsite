<?php
/**
 * @file
 * Synchronise publick files from remote server after database migration.
 */

/**
 * Batch finished callback.
 */
function site_common_sync_batch_finished($success, $results) {
  if ($success) {
    drupal_set_message(t('Import successfull.'));
  }
  else {
    drupal_set_message(t('Import successfull.'), 'error');
  }

  if (module_exists('devel')) {
    dpm($results);
  }
  else {
    drupal_set_message(t('Enable devel module to see details.'), 'error');
  }
}

/**
 * Batch processing function.
 */
function site_common_sync_batch_process($origin, &$context) {
  $base_query = db_select('file_managed', 'f')
    ->fields('f', array('fid'))
    ->orderBy('fid');

  if (!isset($context['sandbox']['progress'])) {
    $context['results'] = array();
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = $base_query->countQuery()->execute()->fetchField();
  }

  $limit = 10;
  $items = $base_query
    ->range($context['sandbox']['progress'], $limit)
    ->execute()
    ->fetchAll();

  $max_size = variable_get('site_common_sync_maxsize', 100 * 1024 * 1024);
  foreach ($items as $item) {
    $context['sandbox']['progress']++;
    $file = file_load($item->fid);

    // Ignore private files.
    if (strpos($file->uri, 'private://') !== FALSE) {
      $context['results']['private'][$file->fid] = $file->uri;
      continue;
    }

    // Ignore big files.
    if ($file->filesize > $max_size) {
      $context['results']['toobig'][$file->fid] = $file->uri . ' (' . $file->filesize . ')';
      continue;
    }

    // Ignore existing files.
    if (file_exists($file->uri)) {
      $context['results']['exists'][$file->fid] = $file->uri;
      continue;
    }

    // At this point we good to go.
    if (strpos($origin, '/files/') === FALSE) {
      $external = parse_url(file_create_url($file->uri));
      $external = $origin . $external['path'];
    }
    else {
      $external = parse_url($file->uri);
      $external = $origin . $external['host'] . $external['path'];
    }

    // Request for file.
    $response = drupal_http_request($external);
    if ($response->code == 200) {
      if (file_prepare_directory(drupal_dirname($file->uri), FILE_CREATE_DIRECTORY)) {
        file_put_contents($file->uri, $response->data);
        $context['results']['new'][$file->fid] = $file->uri;
      }
      else {
        $context['results']['error_dir'][$file->fid] = $file->uri;
      }
    }
    else {
      $context['results']['error'][$file->fid] = $file->uri;
    }
  }

  if ($context['sandbox']['progress'] != $context['sandbox']['max'] && !empty($context['sandbox']['max'])) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
  else {
    $context['finished'] = 1;
  }
}

/**
 * Validate handler.
 */
function site_common_sync_settings_form_validate($form, &$form_state) {
  if ($form_state['clicked_button']['#submit_value'] == 'sync') {
    $origin = $form_state['values']['origin'];

    // Check if origin reacheble.
    $data = drupal_http_request($origin);
    if ($data->code != 200) {
      drupal_set_message(t('Cant access "@site" (error: @code @status_message)', array(
        '@site' => $origin,
        '@code' => $data->code,
        '@status_message' => $data->status_message,
      )), 'error');
    }
  }
}

/**
 * Submit handler.
 */
function site_common_sync_settings_form_submit($form, &$form_state) {
  if ($form_state['clicked_button']['#submit_value'] == 'sync') {
    $origin = $form_state['values']['origin'];

    // Create batch.
    $batch = array(
      'operations' => array(
        array('site_common_sync_batch_process', array($origin)),
      ),
      'finished' => 'site_common_sync_batch_finished',
      'title' => t('Processing files list'),
      'init_message' => t('Starting.'),
      'progress_message' => t('Processed @current out of @total.'),
      'error_message' => t('Batch has encountered an error.'),
      'file' => drupal_get_path('module', 'site_common') . '/site_common.sync.inc',
    );
    batch_set($batch);
  }
}

/**
 * Form builder.
 */
function site_common_sync_settings_form() {
  $form['origin'] = array(
    '#type' => 'textfield',
    '#title' => t('Origin domain (site)'),
    '#required' => TRUE,
  );

  $form['sync'] = array(
    '#type' => 'submit',
    '#value' => t('Start file sync'),
    '#submit_value' => 'sync',
  );
  return $form;
}
