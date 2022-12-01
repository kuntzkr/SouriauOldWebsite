<?php
/**
 * @file
 * Webform:contact form template.
 */
?>
<div class="col a-left">
  <?php print drupal_render($form['submitted']['notice']); ?>
  <?php print drupal_render($form['submitted']['category']); ?>
  <?php print drupal_render($form['submitted']['message']); ?>
  <?php print drupal_render($form['submitted']['attachments']); ?>
</div>
<div class="col a-right">
  <?php print drupal_render($form['submitted']['first_name']); ?>
  <?php print drupal_render($form['submitted']['last_name']); ?>
  <?php print drupal_render($form['submitted']['e_mail']); ?>
  <?php print drupal_render($form['submitted']['phone_number']); ?>
  <?php print drupal_render($form['submitted']['country']); ?>
  <?php print drupal_render($form['submitted']['state']); ?>
  <?php print drupal_render($form['submitted']['city']); ?>
  <?php print drupal_render($form['submitted']['zip_code']); ?>
  <?php print drupal_render($form['submitted']['company']); ?>
  <?php print drupal_render($form['submitted']['job_position']); ?>
  <?php print drupal_render($form['submitted']['company_address']); ?>
</div>
<div class="b-accept text-center">
  <?php print drupal_render($form['submitted']['accepte_contact_phone']); ?>
</div>
<?php print drupal_render($form['actions']); ?>
<div class="element-hidden">
  <?php print drupal_render_children($form);?>
</div>
