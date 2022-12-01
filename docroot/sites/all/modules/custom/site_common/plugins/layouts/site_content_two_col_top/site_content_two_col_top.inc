<?php
/**
 * @file
 * Define custom layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function site_common_site_content_two_col_top_panels_layouts() {
  return array(
    'site_content_two_col_top' => array(
      'title'       => t('Site Content: two col top', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'icon'        => 'site_content_two_col_top.png',
      'category'    => t('Site Common', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'theme'       => 'site_content_two_col_top',
      'admin theme' => 'site_content_two_col_top_admin',
      'regions'     => array(
        'top' => t('TOP', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'right' => t('RIGHT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'left' => t('LEFT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      ),
    ),
  );
}
