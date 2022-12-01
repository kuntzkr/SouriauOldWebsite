<?php
/**
 * @file
 * Template.
 */
?>
<a class="item-search" href="<?php print url('node/' . $nid);?>">
  <span class="group a-left"><?php print t('Subcategory', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></span>
  <div class="wrapper-info">
    <h2><?php print $_html['title']; ?></h2>
  </div>
</a>
