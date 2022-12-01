<?php
/**
 * @file
 * Template.
 */
?>
<div class="slide" data-pagination="<?php print $_html['pager_title']; ?>">
  <?php print $_html['image']; ?>
  <div class="container">
    <div class="text" style="<?php print $_html['slide_bg']; ?>">
      <div class="title" style="<?php print $_html['slide_color']; ?>">
        <h1><?php print $_html['title']; ?></h1>
      </div>
      <div class="description" style="<?php print $_html['slide_color']; ?>">
        <p><?php print $_html['description']; ?></p>
      </div>
      <div class="w-btn">
        <?php print $_html['link']; ?>
      </div>
    </div>
  </div>
</div>
