<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-item-resorce" data-mh="news-group">
  <div class="b-top">
    <?php print $_html['image']; ?>
  </div>
  <div class="b-content">
    <div class="info">
      <span class="b-date"><?php print $_html['date']; ?></span>
    </div>

    <h4><?php print $_html['title']; ?></h4>
    <div class="w-btn text-center top-indent">
      <?php print $_html['more']; ?>
    </div>
  </div>
</div>
