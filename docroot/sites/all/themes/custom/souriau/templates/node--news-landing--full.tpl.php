<?php
/**
 * @file
 * Template .
 *
 * @var $content array
 */
?>

<div class="b-news-description">
  <div class="container">
    <div class="b-title a-left">
      <h1><?php print $_html['title'] ?></h1>
    </div>
    <div class="b-description">
      <?php print $_html['description'] ?>
    </div>
  </div>
</div>

<div class="grey-bg">
  <?php print $_html['most_recent'] ?>
</div>

<section class="b-news b-list-news">
  <?php print $_html['news_list'] ?>
</section>
