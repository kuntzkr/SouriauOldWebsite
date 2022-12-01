<?php
/**
 * @file
 * Template.
 */
?>

<div class="b-single-news">
  <div class="container">
    <div class="w-tags">
      <?php if (!empty($_html['tags'])): ?>
        <?php foreach ($_html['tags'] as $tag): ?>
        <div class="b-tag">
          <span class="ico ico-tag">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico"><use xlink:href="#ico-tag"></use></svg>
            <!--<![endif]-->
          </span>
          <?php print $tag; ?>
        </div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>

    <h1><?php print $_html['title']; ?></h1>

    <div class="publicate-date"><?php print $_html['date']; ?></div>

    <div class="b-kicker">
      <?php print $_html['kicker']; ?>
    </div>

    <div class="wysiwyg">
      <?php print $_html['body']; ?>
    </div>
  </div>
</div>

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
