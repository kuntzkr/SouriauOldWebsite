<?php
/**
 * @file
 * This is a template file for a pop-up prompting user to give their consent for the website to set cookies.
 */
?>
<div class="page">
  <div class="b-cookies">
    <div class="container">
      <div class="w-btn a-right">
        <a href="#" class="btn agree-button"><?php print t('I ACCEPT %and CLOSE', ['%and' => '&'], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
      </div>
      <div class="b-text">
        <?php print $message ?>
      </div>
    </div>
  </div>
</div>
