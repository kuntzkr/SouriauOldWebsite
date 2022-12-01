<?php
/**
 * @file
 * This is a template file for a pop-up informing a user that he has already agreed to cookies.
 */
?>
<div class="page">
  <div class="b-cookies">
    <div class="container">
      <div class="w-btn a-right">
        <a href="#" class="btn hide-popup-button"><?php print t('CLOSE', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
      </div>
      <div class="b-text">
        <?php print $message ?>
      </div>
    </div>
  </div>
</div>
