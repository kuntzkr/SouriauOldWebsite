<?php
/**
 * @file
 * Template.
 */
?>
<section class="b-products-category">
  <div class="list">
    <?php print $_html['categories']; ?>
  </div>
</section>
<div class="b-pr-description">
  <div class="container">
    <?php print $_html['description']; ?>
  </div>
</div>
<?php print $_html['block_interest']; ?>
<?php if (!empty($_html['top_products'])): ?>
<div class="b-top-products">
  <div class="container">
    <h2><?php print t('Our top products', [], ['context' => 'SOURIAU: other']);?></h2>
    <div class="product-items">
      <?php print $_html['top_products']; ?>
    </div>
  </div>
</div>
<?php endif;?>
<section class="b-brand">
  <div class="b-presentation">
    <?php print $_html['presentation_image'];?>
    <div class="text">
      <div class="b-align">
        <div class="b-align">
          <?php print $_html['presentation_description'];?>
        </div>
      </div>
    </div>
  </div>
  <?php if (!empty($_html['souriau_description'])): ?>
  <div class="b-item">
    <div class="container">
      <div class="b-title">
        <h4><?php print $_html['souriau_title'];?></h4>
      </div>
      <div class="b-text">
        <?php print $_html['souriau_description'];?>
      </div>
    </div>
  </div>
  <?php endif;?>
  <?php if (!empty($_html['sunbank_description'])): ?>
  <div class="b-item b-sunbank">
    <div class="container">
      <div class="b-title">
        <h4><?php print $_html['sunbank_title'];?></h4>
      </div>
      <div class="b-text">
        <?php print $_html['sunbank_description'];?>
      </div>
    </div>
  </div>
  <?php endif;?>
</section>
