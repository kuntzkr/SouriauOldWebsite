<?php
/**
 * @file
 * User_login_form template.
 */
?>
<div class="b-wrapper">
  <h1><?php print t('Sign in', [], ['context' => SOURIAU_COMMON_T_USER]); ?></h1>
  <?php hide($form['actions']);?>
  <?php print drupal_render_children($form);?>
</div>
<?php print render($form['actions']);?>
