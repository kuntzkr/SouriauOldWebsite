<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-product-item" data-mh="result-group">
  <?php print $_html['image']; ?>
  <div class="b-info">
    <div class="b-product-info full-width">
      <h3><a href="<?php print $node_url; ?>"><?php print $_html['title']; ?></a></h3>
      <div class="b-add-info"><p><?php print $_html['content_type']; ?></p></div>
    </div>
    <p><?php print $_html['body']; ?></p>
  </div>
</div>
