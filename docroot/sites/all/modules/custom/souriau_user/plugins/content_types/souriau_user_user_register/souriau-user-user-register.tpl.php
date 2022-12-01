<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-create-account">
  <div class="container">
    <div class="form-wrapper">
      <h1><?php print t('Create an Account', [], ['context' => SOURIAU_COMMON_T_USER]); ?></h1>
      <div class="b-text">
        <p>
        <?php print render($text); ?>
        </p>
      </div>

      <?php print render($form);?>
    </div>
  </div>
</div>
