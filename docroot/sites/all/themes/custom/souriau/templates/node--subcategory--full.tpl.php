<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-category-description grey-bg">
  <div class="container">
    <?php print $_html['description'];?>
  </div>
</div>
<?php if(!empty($_html['product_ranges'])): ?>
<div class="list-products">
  <div class="container">
    <div class="product-items">
    <?php print $_html['product_ranges'];?>
    </div>
  </div>
</div>
<?php endif; ?>
<?php if(!empty($_html['downloads'])): ?>
  <section class="b-downloads-links">
    <div class="container">
      <div class="col-text">
        <h2><?php print t('Downloads', [], ['context' => 'SOURIAU: other']); ?></h2>
      </div>
      <div class="col-links">
        <?php print $_html['downloads']; ?>
      </div>
    </div>
  </section>
<?php endif; ?>
<?php print $_html['block_interest']; ?>
<?php if(!empty($_html['cross_sell'])): ?>
<div class="b-top-products">
  <div class="container">
    <h2>Discover our products</h2>
    <div class="product-items">
      <?php print $_html['cross_sell']; ?>
    </div>
  </div>
</div>
<?php endif; ?>
