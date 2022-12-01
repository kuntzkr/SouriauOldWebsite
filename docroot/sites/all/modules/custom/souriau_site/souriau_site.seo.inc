<?php
/**
 * @file
 * Provides special SEO.
 */

/**
 * Html head link (rel="next" and rel="prev") generator.
 */
function souriau_site_seo_generate_html_head_rel_links($total_pages, $pager_index = 0) {

  $query_pager = pager_get_query_parameters();
  $query = array_merge($_GET, $query_pager);
  $query['page'] = isset($query['page']) ? $query['page'] : 0;
  unset($query['q']);

  $pagers = explode(',', $query['page']);
  $pagers[$pager_index] = isset($pagers[$pager_index]) ? $pagers[$pager_index] : 0;

  $current_page = $pagers[$pager_index];
  $next_page = $current_page + 1;
  $prev_page = $current_page - 1;

  // Generate next link.
  if ($next_page < $total_pages) {
    $pagers[$pager_index] = $next_page;
    $query['page'] = implode(',', $pagers);
    drupal_add_html_head_link([
      'rel' => 'next',
      'href' => url($_GET['q'], ['query' => $query])
    ]);
  }

  // Generate prev link.
  if ($prev_page >= 0) {
    $query['page'] = $prev_page;
    $pagers[$pager_index] = $prev_page;
    $query['page'] = implode(',', $pagers);
    if ($prev_page == 0) {
      unset($query['page']);
    }

    drupal_add_html_head_link([
      'rel' => 'prev',
      'href' => url($_GET['q'], ['query' => $query])
    ]);
  }
}

/**
 * Generate hidden link "Next page" for "Load more" pagination.
 */
function souriau_site_seo_generate_next_page_link($total_pages) {
  $query_pager = pager_get_query_parameters();
  $query = array_merge($_GET, $query_pager);
  $query['page'] = isset($query['page']) ? $query['page'] : 0;
  unset($query['q']);

  $current_page = $query['page'];
  $next_page = $current_page + 1;

  if ($next_page < $total_pages) {
    $query['page'] = $next_page;
    return l(
      t('Next page @page', ['@page' => $query['page']], ['context' => SOURIAU_COMMON_T_OTHER]),
      $_GET['q'],
      ['query' => $query, 'attributes' => ['class' => ['hidden']]]
    );
  }
}
