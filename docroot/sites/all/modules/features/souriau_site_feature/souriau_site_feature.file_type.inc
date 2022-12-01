<?php
/**
 * @file
 * souriau_site_feature.file_type.inc
 */

/**
 * Implements hook_file_default_types().
 */
function souriau_site_feature_file_default_types() {
  $export = array();

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = '3d_model';
  $file_type->label = '3D model';
  $file_type->description = '3D models. *.stp';
  $file_type->mimetypes = array(
    0 => 'application/vnd.ms-access',
  );
  $export['3d_model'] = $file_type;

  $file_type = new stdClass();
  $file_type->disabled = FALSE; /* Edit this to true to make a default file_type disabled initially */
  $file_type->api_version = 1;
  $file_type->type = 'ipaper';
  $file_type->label = 'iPaper';
  $file_type->description = '';
  $file_type->mimetypes = array(
    0 => 'souriau/iPaper',
  );
  $export['ipaper'] = $file_type;

  return $export;
}
