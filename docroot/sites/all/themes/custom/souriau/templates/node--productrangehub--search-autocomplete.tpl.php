<?php
/**
 * @file
 * Template.
 */
?>
<a class="item-search" href="<?php print url('node/' . $nid);?>">
  <span class="group a-left"><?php print t('Product Range HUB', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></span>
  <span class="part-number a-right"></span>
  <div class="wrapper-info">
    <h2><?php print $_html['title']; ?></h2>
    <?php if(isset($_html['series'])): ?>
    <div class="b-add-info a-right">
      <?php print $_html['series']; ?>
    </div>
    <?php endif; ?>
  </div>
</a>
