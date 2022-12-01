<?php
/**
 * @file
 * Template souriau-eco-checkout-form-complete.
 */
?>

<div class="b-confirmation">
  <div class="container">
    <h1><?php print t('Thank you <span>for samples order!</span>', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></h1>

    <div class="b-text">
      <p><?php print t('You will soon receive a confirmation email.', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></p>
    </div>

    <div class="w-btn text-center">
      <div class="align-btn-center">
        <a href="<?php print url('<front>') ?>" class="btn blue-btn"><?php print t('BACK TO HOME', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></a>
        <a href="<?php print url('user') ?>" class="btn orange-btn-hover a-right"><?php print t('SEE MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></a>
      </div>
    </div>

  </div>
</div>
</div>
