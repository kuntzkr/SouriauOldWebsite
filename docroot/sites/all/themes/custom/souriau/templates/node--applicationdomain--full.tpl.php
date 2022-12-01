<?php
/**
 * @file
 * Template.
 */
?>
<?php if(!empty($_html['discover'])): ?>
<?php endif; ?>
<div class="b-app-description">
  <div class="container">
    <div class="b-title wide-title">
      <h1><?php print $_html['title'];?></h1>
    </div>
    <div class="b-row">
      <div class="b-text a-left">
        <?php print $_html['description'];?>
      </div>
      <?php if ($_html['part_number_available']): ?>
        <?php print $_html['search'];?>
      <?php endif; ?>
    </div>
  </div>
</div>
<?php if (!empty($_html['applications'])): ?>
<div class="b-application">
  <div class="b-app-list">
    <?php print $_html['applications']; ?>
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
