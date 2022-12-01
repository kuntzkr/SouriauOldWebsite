<?php
/**
 * @file
 * Template for ERP User Orders Page.
 *
 * @var $progress_orders array
 * @var $completed_orders array
 */
?>

<div class="b-back-link">
  <div class="container">
    <a href="<?php print url("user/{$user->uid}/edit-profile") ?>" class="btn-back">
      <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
      <?php print t('BACK TO MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
    </a>
  </div>
</div>

<div class="b-orders-list">
  <div class="container">
    <h1><?php print t('My orders', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></h1>

    <?php print drupal_render($progress_orders) ?>

    <div class="b-past-orders">
      <h2><?php print t('Past orders', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></h2>

      <?php print drupal_render($completed_orders) ?>
    </div>
  </div>
</div>
