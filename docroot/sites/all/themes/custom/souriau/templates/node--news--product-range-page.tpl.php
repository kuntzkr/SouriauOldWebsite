<?php
/**
 * @file
 * Template.
 */
?>
<a class="item gtm_element" href="<?php print $_html['href']; ?>" data-gtm-category="slider" data-gtm-action="News" data-gtm-label="<?php print $_html['title']; ?>">
  <div class="b-main">
    <div class="container">
      <h3><?php print $_html['title']; ?></h3>
      <div class="publicate-date"><?php print $_html['date']; ?></div>
      <?php if (!empty($_html['tag'])) : ?>
        <div class="b-tag">
          <?php print $_html['icon']; ?>
          <?php print $_html['tag']; ?>
        </div>
      <?php endif ?>
    </div>
  </div>
  <div class="b-duplicate">
    <div class="b-shift">
      <div class="container">
        <h3><?php print $_html['title']; ?></h3>
        <div class="publicate-date"><?php print $_html['date']; ?></div>
        <?php if (!empty($_html['tag'])) : ?>
          <div class="b-tag">
            <?php print $_html['icon']; ?>
            <?php print $_html['tag']; ?>
          </div>
        <?php endif ?>
      </div>
    </div>
  </div>
</a>
