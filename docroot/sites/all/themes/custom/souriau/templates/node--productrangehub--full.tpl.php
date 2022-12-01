<?php
/**
 * @file
 * Template.
 */
?>
<?php if (!empty($_html['downloads'])): ?>
<div class="b-downloads-links">
  <div class="container">
    <div class="col-text">
      <h2><?php print t('Downloads', [], ['context' => 'SOURIAU: other']);?></h2>
    </div>
    <div class="col-links">
      <?php print $_html['downloads']; ?>
    </div>
  </div>
</div>
<?php endif; ?>
<section class="b-features">
  <div class="container">
    <div class="b-main-info">
        <?php print $_html['features']; ?>
    </div>
    <div class="title">
      <h3><?php print t('Key features and benefits', [], ['context' => 'SOURIAU: other']); ?></h3>
    </div>
  </div>
</section>
<div class="divider"></div>
<?php if (!empty($_html['paragraphs'])) : ?>
<section class="b-list-info">
  <?php print $_html['paragraphs']; ?>
</section>
<?php endif; ?>
<?php print $_html['promotion']; ?>
<?php if (!empty($_html['applications'])) : ?>
<div class="b-application">
  <div class="b-app-info">
    <div class="container">
      <div class="b-title">
        <h3><?php print t('Examples of application field', [], ['context' => 'SOURIAU: other']);?></h3>
      </div>
      <div class="b-text">
        <?php print $_html['catchline']; ?>
      </div>
    </div>
  </div>
  <div class="b-app-list">
    <?php print $_html['applications'];?>
  </div>
</div>
<?php endif; ?>
<?php if (!empty($_html['similar_products'])) : ?>
<div class="b-top-products">
  <div class="container">
    <h2><?php print t('Similar Product Ranges', [], ['context' => 'SOURIAU: other']);?></h2>
    <div class="product-items">
      <?php print $_html['similar_products'] ?>
    </div>
  </div>
</div>
<?php endif; ?>
<?php if (!empty($_html['complementary'])) : ?>
<div class="b-top-products dark-bg">
  <div class="container">
    <h2><?php print t('Complementary Product Ranges', [], ['context' => 'SOURIAU: other']);?></h2>
    <div class="product-items">
      <?php print $_html['complementary']; ?>
    </div>
  </div>
</div>
<?php endif; ?>
<?php if (!empty($_html['news'])) : ?>
<section class="b-news">
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
