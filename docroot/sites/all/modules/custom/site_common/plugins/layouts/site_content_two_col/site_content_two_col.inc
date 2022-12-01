<?php
/**
 * @file
 * Define custom layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function site_common_site_content_two_col_panels_layouts() {
  return array(
    'site_content_two_col' => array(
      'title'       => t('Site Content: two col', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'icon'        => 'site_content_two_col.png',
      'category'    => t('Site Common', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'theme'       => 'site_content_two_col',
      'admin theme' => 'site_content_two_col_admin',
      'regions'     => array(
        'content' => t('CONTENT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'left' => t('LEFT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      ),
    ),
  );
}
