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
      <h1><?php print t('Did you know?', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h1>
    </div>

    <div class="b-row">
      <div class="b-text a-left">
        <p><?php print $_html['description']; ?></p>
      </div>
    </div>
  </div>
</div>

<div class="container" style="text-align:center">
  <div class="wrapper">
    <?php print $_html['postcards']; ?>
  </div>
</div>
