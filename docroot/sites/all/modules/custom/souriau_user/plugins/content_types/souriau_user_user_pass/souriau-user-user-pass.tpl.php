<?php
/**
 * @file
 * Template.
 */
?>

<div class="b-forgot-passwd">
  <div class="container">
    <div class="b-wrapper">
      <h1>
        <?php print t('Forgotten password?',
            [], ['context' => SOURIAU_COMMON_T_USER]); ?>
      </h1>
      <div class="b-inside-wrapper">
        <div class="b-text">
          <p>
            <?php print t("Enter your email address associated with your
              SOURIAU - SUNBANK Connection Technologies account. You'll receive
              instructions to reset your password by email.",
              [], ['context' => SOURIAU_COMMON_T_USER]); ?>
          </p>
        </div>

        <?php print render($form);?>
      </div>
    </div>
  </div>
</div>
