<?php
/**
 * @file
 * Template.
 */
?>

<?php if (!empty($_html['paragraphs'])) : ?>
  <section class="b-list-info">
    <?php print $_html['paragraphs']; ?>
  </section>
<?php endif; ?>

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
<?php if (!empty($_html['downloads'])): ?>
<section class="b-downloads-links">
  <div class="container">
    <div class="col-text">
      <h2><?php print t('Downloads', [], ['context' => 'SOURIAU: other']);?></h2>
    </div>
    <div class="col-links">
      <?php print $_html['downloads']; ?>
    </div>
  </div>
</section>
<?php endif; ?>
<div class="divider"></div>
<?php if (!empty($_html['news'])): ?>
  <section class="b-news v2">
    <div class="b-info">
      <div class="container">
        <?php print $_html['news_more']; ?>
        <div class="text">
          <h2><?php print t('News', [], ['context' => 'SOURIAU: other']); ?></h2>
          <?php print $_html['news_catchline']; ?>
        </div>
      </div>
    </div>
    <div class="news-items">
      <?php print $_html['news']; ?>
    </div>
    <div class="w-btn"><?php print $_html['news_more_blue']; ?></div>
  </section>
<?php endif; ?>
