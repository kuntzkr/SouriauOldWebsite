<?php
/**
 * @file
 * Template.
 *
 * @var $addresses array
 * @var $form array
 */
?>
<div class="content">
  <div class="b-back-link">
    <div class="container">
      <a href="<?php print url("user/{$user->uid}/edit-profile") ?>" class="btn-back">
        <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
        <?php print t('BACK TO MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
      </a>
    </div>
  </div>

  <div class="b-address-book">
    <div class="container">
      <h1><?php print t('Address Book', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></h1>

      <div class="js-block_edit">
        <div class="b-list-address" id="js-commerce-addressbook-addresses">
          <?php print $addresses ?>
        </div>

        <div class="w-btn text-center b-create-new-address clearfix">
          <?php print l(
            t('@plus Add an address', ['@plus' => '+'], ['context' => SOURIAU_COMMON_T_COMMERCE]),
            "souriau/ajax/address/create/form",
            ['attributes' => ['class' => 'btn-addr-open hide-btn active', 'id' => 'js-create-new-address']]) ?>
        </div>

        <div class="form-wrapper">
          <div class="js-load-form-wrapper active onload-visible">
            <div class="loader"></div>
            <div class="js-load-form" id="js-commerce-addressbook-customer-profile-form">
              <?php print render($form) ?>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
