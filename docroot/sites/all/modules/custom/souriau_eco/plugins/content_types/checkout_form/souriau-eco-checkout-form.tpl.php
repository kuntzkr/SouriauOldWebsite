<?php
/**
 * @file
 * Template souriau-eco-checkout-form.
 */
?>

<div class="b-shipping-info">
  <div class="container">
    <h1><?php print t('Shipping information', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></h1>
    <?php print drupal_render($form) ?>
  </div>
</div>
