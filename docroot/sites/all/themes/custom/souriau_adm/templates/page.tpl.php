<?php
/**
 * @file
 * Page template.
 */
?>
  <div id="branding" class="clearfix">
    <?php print $breadcrumb; ?>
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
      <h1 class="page-title"><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php print render($primary_local_tasks); ?>
  </div>

  <?php if (function_exists('menu_load')): ?>
    <?php if (menu_load('menu-admin-menu')): ?>
      <div class="dashboard-menu">
      <div class="limiter clearfix">
        <?php print theme('links', array(
          'links' => menu_navigation_links('menu-admin-menu'),
          'attributes' => array('class' => array('links', 'primary-tabs links clearfix')),
          ));?>
      </div>
      <div class="limiter clearfix">
        <?php print theme('links', array(
          'links' => menu_navigation_links('menu-admin-menu', 1),
          'attributes' => array('class' => array('links', 'primary-tabs links clearfix')),
          ));?>
      </div>
      </div>
    <?php endif; ?>
  <?php endif; ?>

  <div id="page">
    <?php if ($secondary_local_tasks): ?>
      <div class="tabs-secondary clearfix"><?php print render($secondary_local_tasks); ?></div>
    <?php endif; ?>

    <div id="content" class="clearfix">
      <div class="element-invisible"><a id="main-content"></a></div>
      <?php if ($messages): ?>
        <div id="console" class="clearfix"><?php print $messages; ?></div>
      <?php endif; ?>
      <?php if ($page['help']): ?>
        <div id="help">
          <?php print render($page['help']); ?>
        </div>
      <?php endif; ?>
      <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
      <?php print render($page['content']); ?>
    </div>

    <div id="footer">
      <?php print $feed_icons; ?>
    </div>

  </div>
