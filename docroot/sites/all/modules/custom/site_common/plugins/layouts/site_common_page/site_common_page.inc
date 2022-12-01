<?php
/**
 * @file
 * Define custom layout.
 */

/**
 * Implements hook_panels_layouts().
 */
function site_common_site_common_page_panels_layouts() {
  return array(
    'site_common_page' => array(
      'title'       => t('Site Page', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'icon'        => 'site_common_page.png',
      'category'    => t('Site Common', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      'theme'       => 'site_common_page',
      'admin theme' => 'site_common_page_admin',
      'regions'     => array(
        'above'   => t('ABOVE', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'header'  => t('HEADER', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'left'  =>   t('LEFT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'content' => t('CONTENT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'right'  =>  t('RIGHT', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'footer'  => t('FOOTER', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
        'below'   => t('BELOW', array(), array('context' => SITE_COMMON_TCONTEXT_ADMIN)),
      ),
    ),
  );
}
