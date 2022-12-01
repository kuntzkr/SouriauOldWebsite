<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-download-center">
  <div class="container" >
    <div class="b-title-with-link">
      <h1><?php print t('Download center', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?></h1>
      <div class="right-link">
        <a href="<?php print url('souriau/ajax/download_center/clear'); ?>" data-block-clear="documents-filter" class="clear-filter use-ajax">
          <?php print t('CLEAR FILTERS', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
        </a>
      </div>
    </div>
    <div class="b-filters" id="documents-filter">
      <?php print drupal_render($form); ?>
    </div>
    <div class="b-list-documents">
      <?php print $results; ?>
    </div>
    <div class="w-btn text-center">
      <div class="view-more blue-btn"><?php print t('LOAD MORE', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></div>
    </div>
  </div>
</div>
