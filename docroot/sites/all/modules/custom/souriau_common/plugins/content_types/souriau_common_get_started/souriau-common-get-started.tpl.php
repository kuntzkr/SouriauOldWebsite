<?php

/**
 * @file
 * Template.
 */
?>

<div class="b-beginner-steps">
  <div class="w-steps">
    <div class="b-step-1 selected-step" aria-hidden="false">
      <div class="w-banner-block b-beginner-app">
        <div class="w-breadcrumb show-share">
          <div class="container">
            <?php print souriau_common_get_share_buttons(TRUE); ?>
            <?php print $_html['breadcrumbs']; ?>
          </div>
        </div>
        <div class="b-banner">
          <?php if (isset($_html['image'])): ?>
            <?php print $_html['image']; ?>
          <?php endif; ?>
        </div>

        <div class="b-select-app">
          <div class="container">
            <h3><?php print t('Select an application domain:', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h3>
            <div class="links">
              <?php foreach ($_html['application_domains'] as $application_domain): ?>
                <a onclick="dataLayer = dataLayer || [];dataLayer.push({'Dimension': 'Application Domain', 'data': '<?php print $application_domain['title']; ?>', 'page': 'Beginner guide'});" class="select-app" href="<?php print url('souriau/ajax/application_domain/' . $application_domain['nid'] . '/applications', ['absolute' => TRUE]); ?>">
                  <?php print drupal_strtoupper($application_domain['title']); ?>
                </a>
              <?php endforeach; ?>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div class="b-step-2" aria-hidden="true"></div>
  </div>
</div>
