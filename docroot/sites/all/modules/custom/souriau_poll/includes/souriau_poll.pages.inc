<?php
/**
 * @file
 * Poll menu callbacks and ctools forms.
 */

/**
 * Call back for poll form.
 */
function souirau_poll_poll_popup_callback($ajax = NULL) {
  if ($ajax !== 'ajax') {
    return;
  }
  // Get the latest nid.
  $view_data = views_get_view_result('souriau_query_get_latest_poll', 'default');

  foreach ($view_data as $row) {
    $nid = $row->nid;
  }
  if (empty($nid)) {
    return;
  }
  ctools_include('ajax');
  ctools_include('modal');
  $node = node_load($nid);
  if (empty($node)) {
    return;
  }
  $contents = render(node_view($node));

  $commands[] = ctools_modal_command_display('', $contents);
  $commands[] = ajax_command_invoke('#modalContent', 'addClass', ['poll-popup']);
  return ['#type' => 'ajax', '#commands' => $commands];
}
