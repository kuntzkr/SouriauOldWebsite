<?php
/**
 * @file
 * Template.
 */
?>
<a class="b-part-number-preview" href="<?php print url('node/' . $nid);?>">
  <div class="b-pic">
    <?php print $_html['image']; ?>
  </div>
  <h4><?php print $_html['title']; ?></h4>
  <div class="text">
    <div class="block-behavior">
      <div class="b-part-numb"><?php print $_html['pn']; ?></div>
      <div class="separator">&nbsp;</div>
      <div class="b-add-info"><?php print $_html['series'];?></div>
    </div>
    <div class="w-btn">
      <span class="btn orange-btn"><?php print t('DISCOVER', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></span>
    </div>
  </div>
</a>
