<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<section class="b-questions" 
         id="section-<?php print $view->result[$view->row_index]->taxonomy_term_data_node_tid; ?>">
  <div class="container">
      <?php if (!empty($title)): ?>
        <h2><?php print $title; ?></h2>
      <?php endif; ?>
    <ul aria-multiselectable="true" role="tablist" 
        id="accordion<?php print $view->result[$view->row_index]->taxonomy_term_data_node_tid; ?>" 
        class="panel-group">
      <?php foreach ($rows as $id => $row): ?>
        <li class="panel">
          <?php print $row; ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>