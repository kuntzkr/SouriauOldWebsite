<?php
/**
 * @file
 * Template.
 */
?>
<a class="item" href="<?php print $_html['href'];?> ">
  <div class="b-pic">
    <?php print $_html['image'];?>
  </div>

  <div class="text">
    <div class="title">
      <h5><?php print $_html['title'];?></h5>
    </div>
    <div class="view-more">
      <?php print t('VIEW MORE', [], ['context' => 'SOURIAU: other']);?>
    </div>
  </div>
</a>
