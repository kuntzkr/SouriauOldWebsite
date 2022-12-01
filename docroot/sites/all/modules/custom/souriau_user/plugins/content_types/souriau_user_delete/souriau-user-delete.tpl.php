<?php
/**
 * @file
 * Template souriau-user-delete.tpl.php.
 *
 * @var $user object
 * @var $user_links array
 */
?>
<div class="b-back-link">
  <div class="container">
    <a href="<?php print url('user/space'); ?>" class="btn-back">
      <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
      <?php print t('BACK TO MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_USER]); ?>
    </a>
  </div>
</div>

<div class="b-generic-box">
  <div class="container">
    <h1><?php print t('Delete my account', [], ['context' => SOURIAU_COMMON_T_USER]) ?></h1>

    <div class="b-description">
      <p>
        <?php print t("We are sorry you asked for closing your ECT Website account.
If you think you will never access ECT Website, and want to remove you account, we can take it over .
Please note that you will be not able to reactivate your account, and recover the content and information.",
          [], ['context' => SOURIAU_COMMON_T_USER]); ?>
      </p>
    </div>

    <div class="w-btn text-center">
      <?php print $_html['delete-link']; ?>
    </div>
  </div>
</div>
