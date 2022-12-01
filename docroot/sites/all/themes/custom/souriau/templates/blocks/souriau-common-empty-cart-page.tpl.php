<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-summary-cart">
  <div class="container">
    <div class="b-empty-card cart-empty-page">
      <p> <?php print t('Your cart is empty.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?> </p>
      <div class="w-btn">
        <a class="link-more" href="#">
          <span aria-hidden="true" class="glyphicon glyphicon-menu-right"></span>
          <?php print t('BROWSE CATALOG', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
        </a>
      </div>
    </div>
  </div>
</div>
