<?php
/**
 * @file
 * Define custom layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function site_common_site_content_two_col_bottom_panels_layouts() {
  return array(
    'site_content_two_col_bottom' => array(
      'title'       => t('Site Content: two col bottom', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'icon'        => 'site_content_two_col_bottom.png',
      'category'    => t('Site Common', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'theme'       => 'site_content_two_col_bottom',
      'admin theme' => 'site_content_two_col_bottom_admin',
      'regions'     => array(
        'above'   => t('ABOVE', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'center' => t('CENTER', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'left' => t('LEFT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'right' => t('RIGHT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'bottom' => t('BOTTOM', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      ),
    ),
  );
}
