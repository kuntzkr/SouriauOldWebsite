<?php
/**
 * @file
 * Pages.
 */

/**
 * Ajax callback for loading news by tag filter on landing page.
 */
function souriau_news_landing_tags_news_filter_ajax_callback() {
  $commands = [];
  $post = $_POST;

  $displays = ['news_most_recent', 'news_list'];

  $tags = [];
  if (isset($post['tags'])) {
    unset($post['tags']['All']);
    $tags = array_keys($post['tags']);
  }

  if ($post['_triggering_element_name'] == 'tags[All]') {
    $tags = [];
  }

  $_view = views_get_view('souriau_news', TRUE);
  foreach ($displays as $display_id) {

    $view = $_view->clone_view();
    $view->set_display($display_id);

    if (count($tags) > 0) {
      $view->set_arguments([implode('+', $tags)]);
    }

    $view->preview();

    $tag_id = 'news-landing-' . str_replace('_', '-', $display_id);

    $output = '<div class="news-wrapper" id="' . $tag_id . '">';
    $renderer = $view->style_plugin->row_plugin;
    foreach ($view->result as $index => $row) {
      $view->row_index = $index;
      $output .= $renderer->render($row);
    }
    $output .= '</div>';

    if ($display_id == 'news_list') {
      if ($view->query->pager->get_total_items() > count($view->result)) {
        $commands[] = ajax_command_invoke("#news-landing-news-list-load-more", 'removeClass', ['hidden']);
      }
      else {
        $commands[] = ajax_command_invoke("#news-landing-news-list-load-more", 'addClass', ['hidden']);
      }
    }

    $commands[] = ajax_command_replace('#' . $tag_id, $output);
  }

  $commands[] = ajax_command_data('#news-landing-news-list-load-more span', 'page', 0);

  return ['#type' => 'ajax', '#commands' => $commands];
}


/**
 * Load more ajax callback.
 */
function souriau_news_landing_load_more_ajax_callback() {
  $commands = [];
  $post = $_POST;

  $tags = [];
  if (isset($post['tags'])) {
    unset($post['tags']['All']);
    $tags = array_keys($post['tags']);
  }

  $page_current = isset($post['page']) ? $post['page'] : 0;
  $page_next = $page_current + 1;

  $view = views_get_view('souriau_news', TRUE);
  $view->set_display('news_list');

  if (count($tags) > 0) {
    $view->set_arguments([implode('+', $tags)]);
  }

  $view->set_current_page($page_next);
  $view->preview();

  $output = '';
  $renderer = $view->style_plugin->row_plugin;
  foreach ($view->result as $index => $row) {
    $view->row_index = $index;
    $output .= $renderer->render($row);
  }

  if ($view->query->offset < $view->total_rows) {
    $commands[] = ajax_command_data('#news-landing-news-list-load-more span', 'page', $page_next);
  }
  else {
    $commands[] = ajax_command_invoke("#news-landing-news-list-load-more", 'addClass', ['hidden']);
  }

  $commands[] = ajax_command_append('#news-landing-news-list', $output);

  return ['#type' => 'ajax', '#commands' => $commands];
}
