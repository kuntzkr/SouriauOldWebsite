<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-product-item">
  <?php print $_html['image']; ?>
  <div class="b-info">
    <div class="b-product-info">
      <h3><a href="<?php print url('node/' . $nid);?>"><?php print $_html['title']; ?></a></h3>
      <div class="b-add-info"><?php print $_html['series'];?></div>
    </div>
    <div class="b-part-numb a-right"><?php print $_html['pn']; ?></div>
      <div class="b-links">
        <?php print $_html['b_links']; ?>
      </div>
  </div>
</div>
