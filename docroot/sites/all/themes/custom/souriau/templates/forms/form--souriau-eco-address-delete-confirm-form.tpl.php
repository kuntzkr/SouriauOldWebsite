<?php
/**
 * @file
 * Template for souriau_eco_address_delete_confirm_form form.
 *
 * @var array $form
 */
?>

<div class="popup-title">
  <h2 id="modal-title" class="modal-title"><?php print drupal_render($form['title'])?></h2>
</div>
<div class="b-text">
  <p><?php print drupal_render($form['description'])?></p>
</div>

<?php print drupal_render_children($form) ?>
