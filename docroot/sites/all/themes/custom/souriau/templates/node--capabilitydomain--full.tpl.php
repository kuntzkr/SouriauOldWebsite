<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-app-description">
  <div class="container">
    <div class="b-title">
      <h1><?php print $_html['title'];?></h1>
    </div>
    <div class="b-text">
      <?php print $_html['description'];?>
    </div>
  </div>
</div>
<?php if (!empty($_html['capabilities'])): ?>
<div class="b-application">
  <div class="b-app-list">
    <?php print $_html['capabilities']; ?>
  </div>
</div>
<?php endif; ?>
<?php if (!empty($_html['news'])): ?>
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
