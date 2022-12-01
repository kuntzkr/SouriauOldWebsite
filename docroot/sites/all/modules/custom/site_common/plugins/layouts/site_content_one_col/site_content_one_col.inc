<?php
/**
 * @file
 * Define custom layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function site_common_site_content_one_col_panels_layouts() {
  return array(
    'site_content_one_col' => array(
      'title'       => t('Site Content: one col', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'icon'        => 'site_content_one_col.png',
      'category'    => t('Site Common', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'theme'       => 'site_content_one_col',
      'admin theme' => 'site_content_one_col_admin',
      'regions'     => array(
        'above' => t('Above', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'content' => t('CONTENT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'below' => t('Below', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      ),
    ),
  );
}
