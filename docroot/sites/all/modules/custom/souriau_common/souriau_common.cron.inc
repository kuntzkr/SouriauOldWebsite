<?php
/**
 * @file
 * Souriau common cron jobs.
 */

/**
 * Cron function to prepare the queue.
 */
function souriau_common_google_imagemap_export() {
  foreach (language_list() as $language) {
    $page = 0;
    do {
      $view = views_get_view('souriau_google_imagemap', TRUE);
      $view->set_display('default');
      $view->set_items_per_page(100);
      $view->set_current_page($page);
      $view->pre_execute();
      $view->execute();
      $view->post_execute();

      // Add the item to the queue.
      DrupalQueue::get('souriau_common_sitemap')->createItem(
        [
          'page' => $page,
          'language' => $language
        ]
      );
      $page += 1;
    } while (count($view->result) > 0);

    // Last item for processing footer.
    DrupalQueue::get('souriau_common_sitemap')->createItem(
      ['page' => SOURIAU_COMMON_IMAGEMAP_LAST, 'language' => $language]
    );
  }
}

/**
 * Cron callback for clearing database from translations.
 */
function souriau_common_et_db_clear() {
  $languages = language_list('language');
  if (empty($languages)) {
    // Nothing to do here.
    return;
  }

  if (isset($languages['en'])) {
    // We will remove EN translation.
    // Note: en-en is default, not EN.
    unset($languages['en']);
  }
  $items = [];
  $start = 0;
  $limit = 100;
  do {
    $select = db_select('entity_translation', 'et')
      ->fields('et', ['entity_type', 'entity_id'])
      ->condition('language', array_keys($languages), 'NOT IN')
      ->groupBy('entity_id')
      ->range($start, $limit)
      ->execute();
    $result = $select->fetchAll();
    if (!empty($result)) {
      $items[] = $result;
    }
    $start += $limit;
    $limit += $limit;
  } while (!empty($result));

  if (empty($items)) {
    // Nothing to do here.
    return;
  }

  // Set queue.
  foreach ($items as $queue_items) {
    DrupalQueue::get('souriau_common_et_db_clear')->createItem($queue_items);
  }

}
