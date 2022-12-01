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
<div class="b-resorces">
  <div class="container">
    <h1><?php print t('Video Tutorials', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h1>
  </div>

  <div class="b-list-resources">
    <div class="container">
      <h2><?php print t('Popular', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
      <div class="wrapper">
        <?php print $_html['popular_resources']; ?>
      </div>
    </div>
  </div>

  <div class="divider hidden-xs"></div>

  <div class="b-list-resources">
    <div class="container">
      <h2><?php print t('My favorites', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
      <div class="wrapper">
        <?php print $_html['favorites_resources']; ?>
      </div>
    </div>
  </div>

  <div class="divider hidden-xs"></div>

  <div class="b-list-resources">
    <div class="container">
      <h2><?php print t('Filtered', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
      <?php print $_html['all_resources']; ?>
    </div>
  </div>
</div>
