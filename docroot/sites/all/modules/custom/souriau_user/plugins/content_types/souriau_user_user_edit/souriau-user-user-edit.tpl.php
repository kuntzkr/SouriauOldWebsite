<?php
/**
 * @file
 * Template.
 */
?>
<div class="main-content">
  <div class="b-edit-account">
    <div class="container">
      <div class="form-wrapper">
        <h1><?php print t('Edit my account', [], ['context' => SOURIAU_COMMON_T_USER]); ?></h1>
        <?php print render($form); ?>
      </div>

      <?php if($newsletter_form || $access_form): ?>
        <div class="b-settings">
          <?php if($access_form): ?>
            <div class="col b-resricted">
              <h2><?php print t('Restricted access', [], ['context' => SOURIAU_COMMON_T_USER]); ?></h2>
              <?php print render($access_form); ?>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

    </div>
  </div>
</div>
