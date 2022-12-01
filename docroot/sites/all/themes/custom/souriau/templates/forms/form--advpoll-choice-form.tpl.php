<?php
/**
 * @file
 * Webform:contact form template.
 */
?>
<fieldset class="text-center">
  <legend>
    <?php print t('Choose your anwser and see the results of the survey.', [], ['context' => SOURIAU_COMMON_T_HEADER]) ?>
  </legend>
  <?php print drupal_render_children($form);?>
