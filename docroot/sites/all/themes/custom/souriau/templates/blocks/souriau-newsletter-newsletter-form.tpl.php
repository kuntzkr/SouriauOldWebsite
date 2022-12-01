<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-form">
  <form action="<?php print $_html['url']; ?>" method="post" id="anonymous-subscriber-form" accept-charset="UTF-8">
    <div class="form-block form-actions a-right">
      <?php print $_html['button']; ?>
    </div>
    <div class="form-item form-type-textfield <?php print $_html['error']; ?>">
      <label for="subscribe"><?php print t('Your email address', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></label>
      <input id="subscribe" class="form-text" type="text" value="<?php print $_html['email']; ?>" name="field_email_field">
      <?php if (!empty($_html['error_msg'])):;?>
        <div class="error-msg"><?php print $_html['error_msg']; ?></div>
      <?php endif; ?>
    </div>
    <div class="element-hidden">
      <label for="field_interests">Interests</label>
      <input type="text" name="field_interests" value="" id="field_interests" />
    </div>
  </form>
</div>
