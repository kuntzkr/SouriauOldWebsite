<?php

/**
 * @file
 * Template.
 */
?>
<div class="w-breadcrumb show-share">
  <div class="container">
    <?php print souriau_common_get_share_buttons(); ?>
    <?php print $_html['breadcrumbs']; ?>
  </div>
</div>

<div class="b-app-description">
  <div class="container">
    <div class="b-title wide-title">
      <h1><?php print t('Training inquiry', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h1>
    </div>
  </div>
</div>

<?php if (!empty($_html['webform'])): ?>
  <div class="b-register-course">
    <h2><?php print t('Training inquiry', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
    <?php print drupal_render($_html['webform']); ?>
  </div>
<?php endif ?>
