<?php
/**
 * @file
 * User_login_form template.
 */
?>
<div class="js-block_edit" id="select-address-block">
  <?php $is_addresses = isset($form['customer_profile_shipping']['addressbook_entries']) ?>
  <?php print drupal_render($form['customer_profile_shipping']['addressbook']) ?>

  <?php $errors = form_get_errors() ?>

  <div class="form-wrapper">
    <div class="js-load-form-wrapper <?php print ($errors || !$is_addresses ? 'active' : '') ?>">
      <div class="loader"></div>
      <div class="js-load-form" <?php print ($errors || !$is_addresses ? 'style="margin-top: 0"' : '') ?>>
        <div class="b-inner-form">
          <?php print drupal_render($form['customer_profile_shipping']); ?>
        </div>
      </div>
    </div>
    <?php print drupal_render_children($form);?>
  </div>
</div>
