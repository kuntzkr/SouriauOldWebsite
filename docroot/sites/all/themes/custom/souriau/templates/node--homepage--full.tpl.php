<?php
/**
 * @file
 * Template.
 */
?>
<div class="main-content">
  <?php if (!empty($_html['slider'])): ?>
    <div class="b-main-slider">
      <?php print $_html['slider']; ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($_html['messages'])): ?>
    <div class="b-promotions">
      <div class="container">
        <?php print $_html['messages']; ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($_html['top_products'])): ?>
    <div class="b-top-products">
      <div class="container">
        <h4><?php print t('Our top products', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
        <div class="product-items">
          <?php print $_html['top_products'];?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($_html['banner_title']) || !empty($_html['banner_description'])): ?>
  <div class="b-help">
    <div class="container">
      <?php print $_html['guide_link']; ?>
      <div class="text">
        <h4><?php print $_html['banner_title']; ?></h4>
        <p><?php print $_html['banner_description']; ?></p>
      </div>
    </div>
  </div>
  <?php endif; ?>

  <?php if (!empty($_html['news'])): ?>
    <div class="b-list-events">
      <div class="container">
        <h4><?php print t('News and events', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
        <div class="wrapper">
          <?php print $_html['news']; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <div class="divider hidden-xs"></div>

  <?php if (!empty($_html['tools'])): ?>
    <div class="b-toolkit">
      <div class="container">
        <h4><?php print t('Our tools', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
        <div class="b-boxes-list">
          <?php print $_html['tools']; ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <div class="b-presentation hidden-xs">
    <?php print $_html['eck_image']; ?>
    <div class="text">
      <div class="b-align">
        <div class="b-align">
          <?php print $_html['eck_description']; ?>
        </div>
      </div>
    </div>
  </div>
</div>
