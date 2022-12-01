<?php
/**
 * @file
 * Template.
 */
?>

<a class="item">
  <?php print $params['paragraph_image'];?>
  <div class="b-content">
    <div class="a-center">
      <div class="b-title">
        <h3><?php print $params['paragraph_title'];?></h3>
      </div>
      <?php if (isset($params['catchline'])):?>
      <div class="b-text">
        <p><?php print $params['catchline'];?></p>
      </div>
      <?php endif;?>
    </div>
  </div>
</a>
