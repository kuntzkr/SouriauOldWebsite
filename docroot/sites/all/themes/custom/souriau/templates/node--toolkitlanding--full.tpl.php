<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-generic-box">
  <div class="container">
    <h1><?php print $_html['title']; ?></h1>
    <div class="b-description">
      <?php print $_html['description']; ?>
    </div>

    <?php if (!empty($_html['tools'])): ?>
      <div class="b-boxes-list">
        <?php print $_html['tools']; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
