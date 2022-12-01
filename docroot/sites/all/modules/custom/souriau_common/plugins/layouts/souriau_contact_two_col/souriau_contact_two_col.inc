<?php
/**
 * @file
 * Define custom layout for Souriau theme.
 */

/**
 * Implements hook_panels_layouts().
 */
function souriau_common_souriau_contact_two_col_panels_layouts() {
  return [
    'souriau_contact_two_col' => [
      'title'       => t('SOURIAU Site: Contact page, Two Cols', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
      'icon'        => 'souriau_contact_two_col.png',
      'category'    => t('SOURIAU Site', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
      'theme'       => 'souriau_contact_two_col',
      'admin theme' => 'souriau_contact_two_col_admin',
      'regions'     => [
        'top_left' => t('TOP LEFT', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
        'top_right' => t('TOP RIGHT', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
        'content' => t('CONTENT', [], ['context' => SITE_COMMON_TCONTEXT_ADMIN]),
      ],
    ],
  ];
}
