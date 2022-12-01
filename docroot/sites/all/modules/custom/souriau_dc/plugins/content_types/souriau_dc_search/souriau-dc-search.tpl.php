<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-download-center">
  <div class="container">
    <div class="main-title"><h1><?php print t('Download center', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?></h1>
    </div>
    <div class="clearfix"></div>
    <?php print drupal_render($form); ?>
    <div class="result-col b-list-documents b-result-view">
      <div class="b-result-wrapper grey-bg">
        <div class="b-view-results list-view" id="all-results">
          <?php print $results; ?>
        </div>
      </div>
    </div>
  </div>
  <div class="w-btn text-center">
    <div class="view-more blue-btn">
      <?php print t('LOAD MORE', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?>
    </div>
    <?php print $next_page_link ?>
  </div>
</div>
