<?php
/**
 * @file
 * Souriau cron functionality.
 */

/**
 * Cron callback.
 */
function souriau_master_file_import_feeds_cron() {
  $autoimport_dir = 'private://autoimport/';

  file_prepare_directory($autoimport_dir, FILE_CREATE_DIRECTORY);

  $filenames = [
    'masterfile' => $autoimport_dir . 'Master_File_Products_' . format_date(REQUEST_TIME, 'custom', 'ymd') . '.csv',
  ];

  $files = [];

  foreach ($filenames as $filetype => $filename) {
    // Query existing files.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'file');
    $query->propertyCondition('uri', $filename);
    // Get the result.
    $result = $query->execute();
    if (!isset($result['file']) && file_exists($filename)) {
      $file = new stdClass();
      $file->uid = 1;
      $file->filename = drupal_basename($filename);
      $file->uri = $filename;
      $file->filemime = file_get_mimetype($filename);
      $file->filesize = filesize($filename);
      $file->status = FILE_STATUS_PERMANENT;
      $files[$filetype] = file_save($file);
      file_usage_add($file, 'feeds', 'FeedsFileFetcher', 0);
    }
    elseif (isset($result['file'])) {
      $fid = key($result['file']);
      $files[$filetype] = file_load($fid);
    }
  }

  extract($files);

  if (!isset($masterfile) || !is_object($masterfile)) {
    return;
  }

  $errors = souriau_master_file_csv_mapping_validation($masterfile->uri);

  $importers = ['souriau_master_file_sku_importer'];
  $sources = db_query("SELECT feed_nid, id FROM {feeds_source} WHERE id IN (:ids)", array(':ids' => $importers));

  foreach ($sources as $source) {
    if ($errors && $errors['type'] == 'error') {
      feeds_log($source->id, $source->feed_nid, 'import', $errors['message']);
      return;
    }
    $feed = feeds_source($source->id, $source->feed_nid);
    if ($errors) {
      $feed->log('import', $errors['message']);
    }
    $config = $feed->getConfig();
    $config['FeedsFileFetcher']['fid'] = $masterfile->fid;
    $config['FeedsFileFetcher']['source'] = $masterfile->uri;
    $feed->setConfig($config);
    $feed->save();
    $feed->importer->addConfig(['process_in_background' => 1]);
    $feed->importer->save();
    feeds_cache_clear(FALSE);
    $job = array(
      'type' => $feed->id,
      'id' => $feed->feed_nid,
      'period' => 0,
      'periodic' => FALSE,
    );
    JobScheduler::get('feeds_source_import')->set($job);
  }

  feeds_reschedule(FALSE);
}
