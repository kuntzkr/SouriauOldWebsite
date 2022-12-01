<?php
/**
 * @file
 * Define custom layout for Souriau theme.
 */

/**
 * Implements hook_panels_layouts().
 */
function souriau_common_souriau_one_col_panels_layouts() {
  return array(
    'souriau_one_col' => array(
      'title'       => t('SOURIAU Site: One Column, no wrappers'),
      'icon'        => 'souriau_one_col.png',
      'category'    => t('SOURIAU Site'),
      'theme'       => 'souriau_one_col',
      'admin theme' => 'souriau_one_col_admin',
      'regions'     => array(
        'content'     => t('CONTENT'),
      ),
    ),
  );
}
