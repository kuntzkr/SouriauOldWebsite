<?php

/**
 * @file
 * Contain forms.
 */

/**
 * Implements hook_form().
 */
function souriau_distributor_upload_form($form, &$form_state) {
  $template_url = file_create_url('public://distributors-template.csv');
  $items[] = t('<strong>Please use this <a href="@url">template</a> to import data. In the CSV file, the columns marked * are mandatory.</strong><br />', [
    '@url' => $template_url,
  ], ['context' => SOURIAU_COMMON_T_ADMIN]);
  $items[] = ($max_size = parse_size(ini_get('upload_max_filesize'))) ? t('Due to server restrictions, the <strong>maximum upload file size is !max_size</strong>. Files that exceed this size will be disregarded.', ['!max_size' => format_size($max_size)], ['context' => SOURIAU_COMMON_T_ADMIN]) : '';
  $items[] = t('<strong>Country Code:*</strong> Should be the country ISO. For France it is FR, India IN, Germany DE etc.', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
  $items[] = t('<strong>State/Province Code:</strong> Is also standard code, which is actually not mandatory. But if available for the country, it is better if we can fill this field. Eg: Kerala it is KL. I can provide the codes for any country if you need.', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
  $items[] = t('<strong>Type:*</strong> This column can have any of these values: distributor or reseller or vad . All small letters. Any values other than these will not save the distributor properly.', [], ['context' => SOURIAU_COMMON_T_ADMIN]);
  $items[] = t('<strong>Brand:*</strong> This is a multiple option field. Can have values like: souriau or sunbank or souriau|sunbank.All small letters.', [], ['context' => SOURIAU_COMMON_T_ADMIN]);

  $template_description = theme_item_list([
    'items' => $items,
    'title' => t('NOTE', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'type' => 'ul',
    'attributes' => []
  ]);
  $form = [];
  $form['#attributes'] = [
    'enctype' => 'multipart/form-data'
  ];
  $form['csvfile'] = [
    '#title' => t('CSV File', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#type'  => 'file',
    '#description' => $template_description,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#value' => t('Import', [], ['context' => SOURIAU_COMMON_T_ADMIN])
  ];
  $form['#validate'] = [
    'souriau_distributor_validate_fileupload',
  ];
  return $form;
}

/**
 * Validate csv file extension.
 */
function souriau_distributor_validate_fileupload(&$form, &$form_state) {
  $validators = [
    'file_validate_extensions' => ['csv'],
  ];

  if ($file = file_save_upload('csvfile', $validators, 'private://distributor-import/', FILE_EXISTS_REPLACE)) {
    $form_state['values']['csvupload'] = $file->destination;
  }
  else {
    form_set_error('souriau_distributor_upload', t('Unable to copy uploaded file.', [], ['context' => SOURIAU_COMMON_T_ADMIN]));
  }
}

/**
 * CSV import submit handler.
 */
function souriau_distributor_upload_form_submit($form, &$form_state) {
  $batch = [
    'title' => t('Importing CSV...', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'operations' => [],
    'init_message' => t('Commencing', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'progress_message' => t('Processed @current out of @total.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'error_message' => t('An error occurred during processing', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    'finished' => 'souriau_distributor_import_finished',
    'file' => drupal_get_path('module', 'souriau_distributor') . '/souriau_distributor.forms.inc',
  ];
  if (isset($form_state['values']['csvupload'])) {
    if ($handle = fopen($form_state['values']['csvupload'], 'r')) {
      $batch['operations'][] = ['souriau_distributor_remember_filename', [$form_state['values']['csvupload']]];
      $line = fgetcsv($handle, 4096, ';');
      while ($line = fgetcsv($handle, 4096, ';')) {
        $batch['operations'][] = ['souriau_distributor_import_line', [$line]];
      }
      fclose($handle);
    }
  }
  batch_set($batch);
}

/**
 * CSV import finished.
 */
function souriau_distributor_import_finished($success, $results, $operations) {
  drupal_set_message(t('The CSV import has completed.', [], ['context' => SOURIAU_COMMON_T_ADMIN]));
}

/**
 * Helper function to remember the uploaded file name.
 */
function souriau_distributor_remember_filename($filename, &$context) {
  $context['results']['rows_imported'] = 0;
  $context['results']['uploaded_filename'] = $filename;
}

/**
 * CSV import line by line callback.
 */
function souriau_distributor_import_line($line, &$context) {
  // Check mandatory fields.
  if (empty($line[0]) || empty($line[2]) || empty($line[4]) || empty($line[5]) || empty($line[13])) {
    return;
  }

  $context['results']['rows_imported']++;

  // Check if distributor already exists.
  $distributor = souriau_distributor_get_distributor_by_distributor_code($line[2]);
  if ($distributor === FALSE) {
    // Invalid distributor code, so create new distributor.
    $distributor = entity_create('distributor', ['type' => 'distributor']);
  }

  // Create a Entity Wrapper of that new/existing entity.
  $entity = entity_metadata_wrapper('distributor', $distributor);
  $entity->title = "$line[0] (Code: $line[2])";
  $entity->field_distributor_name = $line[0];
  $entity->field_url = $line[1];
  $entity->field_distributor_code = $line[2];
  $entity->field_contact_person = $line[3];
  $entity->field_postal_address->country = $line[4];
  $entity->field_postal_address->thoroughfare = $line[5];
  $entity->field_postal_address->premise = $line[6];
  $entity->field_postal_address->locality = $line[7];
  $entity->field_postal_address->administrative_area = $line[8];
  $entity->field_postal_address->postal_code = $line[9];
  $entity->field_postal_address->phone_number = $line[10];
  $entity->field_postal_address->fax_number = $line[11];
  $entity->field_email = $line[12];
  $entity->field_type = $line[13];
  $entity->field_distributor_brand = explode('|', $line[14]);
  $entity->save();
}

/**
 * Implements hook_form().
 */
function souriau_distributor_form($form, &$form_state) {
  $form = [];

  $form['souriau_distributor_settings'] = [
    '#tree' => TRUE,
  ];
  $default_value = variable_get('souriau_distributor_settings', []);

  // Settings.
  $form['souriau_distributor_settings']['manage'] = [
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Stock management', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
  ];
  $form['souriau_distributor_settings']['manage']['setting'] = [
    '#type' => 'radios',
    '#title' => NULL,
    '#options' => [
      '0' => t('Worldwide', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      '1' => t('ECIA', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    ],
    '#description' => t('In Worldwide system, the information “In stock” and “Out of stock” is available on Part Number page and preview block.
    In case of ECIA, stock information label is not displayed. Stock information is retrieved “in live” when clicking on “Where to buy” popup link.', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#default_value' => isset($default_value['manage']['setting']) ? $default_value['manage']['setting'] : '0',
  ];
  // Default distributors list values.
  $form_state['default_distributors'] = !empty($form_state['default_distributors'])
    ? $form_state['default_distributors'] : $default_value['default'];
  foreach ($form_state['default_distributors'] as $distributor) {
    if ($distributor === FALSE) {
      continue;
    }
    $form['souriau_distributor_settings']['default'][] = [
      '#type' => 'entityreference',
      '#title' => t('Distributor', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
      '#era_entity_type' => 'distributor',
      '#era_bundles' => ['distributor'],
      '#era_cardinality' => 1,
      '#era_query_settings' => [
        'limit' => 15,
      ],
      '#default_value' => $distributor,
    ];
  }
  $form['add_item'] = [
    '#type' => 'submit',
    '#value' => t('Add item', [], ['context' => SOURIAU_COMMON_T_ADMIN]),
    '#submit' => ['souriau_distributor_add_item'],
  ];

  return system_settings_form($form);
}

/**
 * Callback for add item.
 */
function souriau_distributor_add_item($form, &$form_state) {
  $form_state['default_distributors'][] = '';
  $form_state['rebuild'] = TRUE;
}
