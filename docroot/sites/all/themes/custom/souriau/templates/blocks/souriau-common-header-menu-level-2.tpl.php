<?php
/**
 * @file
 * Template.
 */
?>
<span class="arrow  hidden-lg">
  <?php print drupal_render($_data['icon']);?>
  <span class="screen-reader-text"><?php print t('open/close sub menu', [], ['context' => SOURIAU_COMMON_T_HEADER]);?></span>
</span>
<div class="b-sub-menu" id="<?php print $_data['block_id'];?>">
  <div class="container">
    <div class="wrapper">
      <h3><?php print $_html['parent_title'];?></h3>
      <?php print $_html['links'];?>
    </div>
  </div>
</div>
