<?php
/**
 * @file
 * Template.
 */
?>
<div class="w-banner-block  b-beginner-app">
  <div class="w-breadcrumb show-share">
    <div class="container">
      <?php print souriau_common_get_share_buttons(TRUE); ?>
      <?php print $_html['breadcrumbs']; ?>
    </div>
  </div>
  <div class="b-banner">
    <?php print $_html['guidance_image']; ?>
  </div>

  <div class="b-select-category">
    <div class="container">
      <h3><?php print t('Select an application:', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h3>

      <div class="links">
        <?php foreach ($_html['applications'] as $application): ?>
          <a onclick="dataLayer = dataLayer || [];dataLayer.push({'Dimension': 'Application', 'data': '<?php print $application['title']; ?>', 'page': 'Beginner guide'});" href="<?php print souriau_common_get_application_search_link($application['node']); ?>">
            <?php print drupal_strtoupper($application['title']); ?>
          </a>
        <?php endforeach; ?>
      </div>

      <div class="w-btn">
        <a href="#" class="back-to-app"><?php print t('BACK TO THE FIRST QUESTION', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
      </div>
    </div>
  </div>
</div>
