<?php

/**
 * @file
 * Template.
 */
?>

<div class="main-content">
  <div class="b-not-found">
    <div class="container">
      <h1>403</h1>
      <div class="b-text">
        <h5><?php print t('ERROR', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h5>
        <p>
          <?php print t("You don't have permission to access this page.", [],
            ['context' => SOURIAU_COMMON_T_OTHER]); ?>
        </p>
      </div>
      <div class="w-btn">
        <a href="<?php print $home_link; ?>" class="btn orange-btn-hover">
          <?php print t('RETURN HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
        </a>
      </div>
    </div>
  </div>
</div>
