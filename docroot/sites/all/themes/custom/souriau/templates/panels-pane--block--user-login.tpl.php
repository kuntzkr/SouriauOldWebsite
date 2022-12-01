<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-sign-in-up">
  <div class="container">
    <div class="b-two-columns">
      <div class="b-tabs-navigation" id="b-tabs-navigation">
        <a href="#" data-to-open="b-sign-in">Sign in</a>
        <a href="#" data-to-open="b-sign-up">Sign up</a>
      </div>
      <div class="align-container slick-slider">
        <div class="col b-sign-in" data-open="b-sign-in">
          <?php print render($content); ?>
        </div>

        <div class="col b-sign-up" data-open="b-sign-up">
          <div class="b-wrapper">
            <h1><?php print t('Sign up', [], ['context' => SOURIAU_COMMON_T_USER]); ?></h1>
            <div class="text">
              <p>
                <?php print t('Create an account to be able to order sample, create your own project, manage your training...', [], ['context' => SOURIAU_COMMON_T_USER]);?>
              </p>
            </div>
          </div>
          <div class="w-btn">
            <a href="/user/register" class="btn orange-btn-hover gtm_element" data-gtm-category="Button" data-gtm-action="Account" data-gtm-label="user login">
              <?php print t('CREATE AN ACCOUNT', [], ['context' => SOURIAU_COMMON_T_USER]);?>
            </a>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
