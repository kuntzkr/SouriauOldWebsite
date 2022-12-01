<?php
/**
 * @file
 * Define custom layout for Souriau theme.
 */

/**
 * Implements hook_panels_layouts().
 */
function souriau_common_souriau_main_panels_layouts() {
  return array(
    'souriau_main' => array(
      'title'       => t('SOURIAU Site: default template'),
      'icon'        => 'souriau_main.png',
      'category'    => t('SOURIAU Site'),
      'theme'       => 'souriau_main',
      'admin theme' => 'souriau_main_admin',
      'regions'     => array(
        'header'      => t('HEADER'),
        'content'     => t('CONTENT'),
        'footer'      => t('FOOTER'),
      ),
    ),
  );
}
