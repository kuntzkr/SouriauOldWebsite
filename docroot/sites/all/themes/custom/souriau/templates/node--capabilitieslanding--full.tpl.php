<?php
/**
 * @file
 * Template.
 */
?>

<div class="b-app-description">
  <div class="container">
    <div class="b-title">
      <h1><?php print render($content['title_field']); ?></h1>
    </div>
    <div class="b-text">
      <?php print render($content['field_description']); ?>
    </div>
  </div>
</div>

<div class="b-application variant-2">
  <div class="b-app-list">
    <?php print $_html['capability_domains']; ?>
  </div>
</div>
