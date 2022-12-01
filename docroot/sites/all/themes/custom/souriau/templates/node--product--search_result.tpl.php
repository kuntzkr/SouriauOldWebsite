<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-product-item" data-mh="result-group">
  <?php print $_html['image']; ?>
  <div class="b-info">
    <div class="b-product-info">
      <h3>
        <a class="gtm_element" href="<?php print $node_url; ?>" data-gtm-category="Button" data-gtm-action="Results" data-gtm-label="<?php print $_html['pn']; ?>">
          <?php print $_html['title']; ?>
        </a>
      </h3>
      <div class="b-add-info">
        <p><?php print $_html['brand'] . $_html['divider']; ?>
        <b><?php print $_html['series']; ?></b>
        </p>
      </div>
    </div>

    <div class="b-part-numb a-right"><?php print $_html['pn']; ?></div>
    <?php if (!empty($_html['stock_label'])): ?>
      <div class="b-stock-info <?php print $_html['available']; ?> a-right"><?php print $_html['stock_label']; ?></div>
    <?php endif; ?>
    <div class="b-links">
      <?php print $_html['links']; ?>
    </div>
  </div>
</div>
