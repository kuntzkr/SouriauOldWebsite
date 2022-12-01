<?php
/**
 * @file
 * Template souriau-user-landing.tpl.php.
 *
 * @var $user object
 * @var $user_links array
 */
?>
<div class="b-back-link">
  <div class="container">
    <a href="<?php print url('<front>'); ?>" class="btn-back">
      <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
      <?php print t('BACK TO HOMEPAGE', [], ['context' => SOURIAU_COMMON_T_USER]); ?>
    </a>
  </div>
</div>

<div class="b-generic-box">
  <div class="container">
    <h1><?php print t('My account', [], ['context' => SOURIAU_COMMON_T_USER]) ?></h1>

    <?php if (!empty($landing_text)): ?>
      <div class="b-description">
        <p><?php print t($landing_text, [], ['context' => SOURIAU_COMMON_T_USER]); ?></p>
      </div>
    <?php endif; ?>

    <div class="b-boxes-list">
      <?php foreach ($user_links as $path => $title) : ?>
        <div class="b-col">
          <a href="<?php print url($path) ?>" class="b-blue-box">
            <div class="v-align">
              <h4><?php print $title ?></h4>
            </div>
          </a>
        </div>
      <?php endforeach ?>
    </div>
  </div>
</div>
