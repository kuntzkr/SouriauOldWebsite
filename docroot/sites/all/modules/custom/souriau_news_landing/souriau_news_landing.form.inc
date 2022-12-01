<?php
/**
 * @file
 * Souriau News Landing Forms.
 */

/**
 * Implements hook_form_alter().
 */
function souriau_news_landing_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id != 'views_exposed_form') {
    return;
  }

  if ($form_state['view']->name != 'souriau_news' || $form_state['display']->id != 'news_most_recent') {
    return;
  }

  $form['tags'] = $form['field_tags_tid'];
  $form['field_tags_tid']['#access'] = FALSE;
  $form['tags']['#type'] = 'checkboxes';

  $tags = empty($_GET['selected']) ? ['All'] : preg_split('/ |\+|,/', $_GET['selected']);

  $form['tags']['#options'] = [
    'All' => t('All', [], ['context' => SOURIAU_COMMON_T_OTHER]),
  ] + $form['tags']['#options'];

  $form['tags']['#value'] = [];
  foreach ($tags as $tag) {
    if (!isset($form['tags']['#options'][$tag])) {
      continue;
    }
    $form['tags']['#value'][$tag] = $form['tags']['#options'][$tag];
  }

  $form['tags']['#ajax'] = [
    'path' => 'souriau/ajax/landing-news/tags-news-filter',
    'event' => 'change',
  ];
}
