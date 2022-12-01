<?php
/**
 * @file
 * Template.
 */
?>
<section class="b-newsletter">
  <div class="container">
    <div class="subscribe-messages"></div>
    <h3><?php print t('Subscribe to our newsletter', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h3>
    <?php print $_html['newsletter']; ?>
  </div>
</section>
