<?php
/**
 * @file
 * Search page filter template.
 */
?>
<div class="filter-item">
  <?php print $title; ?>

  <a class="close-link" aria-label="Close" href="#" data-filter-id="<?php print $machine_name; ?>" data-filter-value="<?php print $value; ?>" data-filter-type="<?php print $type; ?>">
    <span class="ico ico-close">
      <!--[if gte IE 9]><!-->
      <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-close"></use></svg>
      <!--<![endif]-->
    </span>
    <span class="screen-reader-text">remove</span>
  </a>
</div>
