<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-form" id="newsletter-groups">
  <div class="popup-title">
    <h2><?php print t('I’m interested in', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
  </div>
  <form action="<?php print $_html['url']; ?>" method="post">
    <?php foreach ($_data['groups'] as $group): ?>
      <?php foreach ($group->interests as $key => $option): ?>
        <div class="form-item form-type-checkbox">
          <input id="<?php print $group->id . $key; ?>" class="form-checkbox" type="checkbox" value="<?php print $option->id; ?>" name="groups[<?php print $group->id . $key; ?>]">
          <label for="<?php print $group->id . $key; ?>"><?php print $option->name; ?></label>
        </div>
      <?php endforeach; ?>
    <?php endforeach; ?>
    <?php if (!empty($_html['error'])): ?>
      <div class="error-msg"><?php print $_html['error']; ?></div>
    <?php endif; ?>
    <input class="form-text" type="hidden" value="<?php print $_html['email']; ?>" name="field_email_field">
    <input class="form-text" type="hidden" value="1" name="field_is_popup">
    <?php print $_html['button']; ?>
  </form>
</div>
