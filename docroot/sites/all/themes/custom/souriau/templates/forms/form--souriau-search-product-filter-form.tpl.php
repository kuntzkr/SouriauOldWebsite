<?php
/**
 * @file
 * Template.
 */
?>
<div class="wrapper">
  <div class="b-header">
    <a class="close-link" aria-label="Close" href="#">
            <span class="ico ico-close">
              <!--[if gte IE 9]><!-->
                <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-close"></use></svg>
              <!--<![endif]-->
            </span>
      <span class="screen-reader-text">remove</span>
    </a>

    <div class="w-inside">
      <?php print drupal_render($form['actions']); ?>
      <h2><?php print t('More filters', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
    </div>
  </div>

  <div class="b-content" id="search-filters">
    <?php print drupal_render_children($form); ?>
  </div>
</div>
