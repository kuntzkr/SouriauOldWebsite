<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-category-description grey-bg">
  <div class="container">
    <?php print $_html['description']; ?>
  </div>
</div>
<?php if($_html['is_grouped']): ?>
<div class="b-tabs grey-bg">
  <div class="container">
    <?php print $_html['groups']; ?>
  </div>

<div class="tab-content">
  <?php print $_html['subcategories']; ?>
</div>
</div>
<?php endif;?>
<?php if(!$_html['is_grouped']): ?>
<section class="b-sub-categories">
  <div class="container">
    <div class="items">
      <?php print $_html['subcategories']; ?>
    </div>
  </div>
</section>
<?php endif;?>
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
<?php if(!empty($_html['discover'])): ?>
<div class="b-top-products">
  <div class="container">
    <h2><?php print t('Discover our products', [], ['context' => 'SOURIAU: other']); ?></h2>
    <div class="product-items">
      <?php print $_html['discover']; ?>
    </div>
  </div>
</div>
<?php endif; ?>
