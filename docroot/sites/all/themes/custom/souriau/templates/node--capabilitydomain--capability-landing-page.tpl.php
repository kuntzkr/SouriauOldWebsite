<?php
/**
 * @file
 * Template.
 */
?>
<a class="item" href="<?php print $node_url; ?>">
  <?php print $_html['image']; ?>
  <div class="b-content">
    <div class="a-center">
      <div class="b-title">
        <h3><?php print render($content['title_field']); ?></h3>
      </div>
      <div class="b-text">
        <p><?php print render($content['field_catchline']); ?></p>
      </div>
    </div>
  </div>
</a>
