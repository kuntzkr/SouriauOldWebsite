<?php
/**
 * @file
 * Template.
 */
?>
<span class="ico ico-search">
  <!--[if gte IE 9]><!-->
     <svg class="svg-ico"><use xlink:href="#ico-search"></use></svg>
  <!--<![endif]-->
</span>
<a class="close-btn" href="#" aria-label="Close">
  <span class="ico ico-close">
    <!--[if gte IE 9]><!-->
      <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-close"></use></svg>
    <!--<![endif]-->
  </span>
  <span class="screen-reader-text"><?php print t('Close popup', [], ['context' => SOURIAU_COMMON_T_HEADER]); ?></span>
</a>
<?php print drupal_render_children($form); ?>
