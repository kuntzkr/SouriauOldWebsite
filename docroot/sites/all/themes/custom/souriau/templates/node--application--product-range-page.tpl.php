<?php
/**
 * @file
 * Template.
 */
?>
<a class="item" href="<?php print $_html['href'];?>">
  <?php print $_html['image'];?>
  <div class="b-content">
    <div class="a-center">
      <div class="b-title">
        <h3><?php print $_html['title'];?></h3>
      </div>
      <?php if (isset($_html['catchline'])):?>
      <div class="b-text">
        <?php print $_html['catchline'];?>
      </div>
      <?php endif;?>
    </div>
  </div>
</a>