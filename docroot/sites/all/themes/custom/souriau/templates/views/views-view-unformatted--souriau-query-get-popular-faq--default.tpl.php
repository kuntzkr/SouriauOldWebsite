<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="w-breadcrumb show-share">
  <div class="container">
    <?php print souriau_common_get_share_buttons(); ?>
    <?php print $_html['breadcrumbs']; ?>
  </div>
</div>
<div class="container">
  <h1 class="faq-title">
    <?php print t('Need some help ?', [], ['context' => 'SOURIAU: other']); ?>
  </h1>
</div>
<section class="b-questions">
  <div class="container">
    <h2>
      <?php print t('Popular questions', [], ['context' => 'SOURIAU: other']); ?>
    </h2>
    <ul aria-multiselectable="true" role="tablist" 
        id="accordion" class="panel-group">
      <?php foreach ($rows as $id => $row): ?>
      <li class="panel">
          <?php print $row; ?>
      </li>
      <?php endforeach; ?>
    </ul>
  </div>
</section>
