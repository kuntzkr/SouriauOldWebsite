<?php
/**
 * @file
 * Template.
 */
?>

<div class="container">
  <h1><?php print $_html['title']; ?></h1>
  <?php print render($content['field_image']); ?>
  <?php print $_html['description']; ?>
</div>
