<?php
/**
 * @file
 * Template .
 *
 * @var $_html array
 */
?>

<div class="item-recent-news">
  <div class="wrapper">
    <?php print $_html['image'] ?>

    <div class="b-content-wrapper">
      <?php if (count($_html['tags']) > 0) : ?>
        <div class="w-tags list-tags">

          <?php foreach ($_html['tags'] as $i => $tag) : ?>
            <div class="b-tag <?php print ($i > 0 ? 'hide-tag' : '') ?>">
              <span class="ico ico-tag">
                <!--[if gte IE 9]><!-->
                  <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-tag"></use></svg>
                <!--<![endif]-->
              </span>
              <?php print $tag ?>
            </div>
          <?php endforeach ?>

          <?php if (count($_html['tags']) > 1) : ?>
            <a href="#" class="view-all-tags">
              <span class="ico ico-view-all">
                <!--[if gte IE 9]><!-->
                  <svg class="svg-ico"><use xlink:href="#ico-view-all"></use></svg>
                <!--<![endif]-->
              </span>
            </a>
          <?php endif ?>
        </div>
      <?php endif ?>
      <h3><?php print l($_html['title'], 'node/' . $node->nid) ?></h3>
      <p><?php print $_html['description'] ?></p>
      <div class="b-date">
        <?php print format_date($node->created, 'souriau_date_short_slash') ?>
      </div>
    </div>
  </div>
</div>
