<?php
/**
 * @file
 * Template.
 */
?>
<a class="item" href="<?php print $_html['href']; ?>">
  <div class="b-pic">
    <?php print $_html['image']; ?>
  </div>
  <h3><?php print $_html['title']; ?></h3>
  <?php if ($_html['second_level_title']): ?>
    <h2><?php print $_html['second_level_title']; ?></h2>
  <?php endif; ?>
  <div class="text">
    <div class="block-behavior">
      <?php print $_html['description']; ?>
    </div>
    <div class="w-btn">
      <span class="btn orange-btn"><?php print $_html['discover']; ?></span>
    </div>
  </div>
</a>
