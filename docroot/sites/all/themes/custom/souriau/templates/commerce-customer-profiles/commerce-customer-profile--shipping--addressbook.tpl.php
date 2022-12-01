<?php
/**
 * @file
 * Template to display a customer address.
 *
 * @var $commerce_customer_profile object
 */
?>

<div class="item-row b-address-item <?php print ($zebra == 'odd') ? 'a-left' : 'a-right' ?>">
  <div class="b-info">
    <p>
      <strong><?php print $address->address_name ?></strong>
    </p>
    <p><?php print $address->customer_name ?></p>
    <p><?php print $address->address_line_1 ?></p>
    <?php if (!empty($address->address_line_2)) : ?>
      <p><?php print $address->address_line_2 ?></p>
    <?php endif ?>
    <p><?php print $address->postal_code ?> <?php print $address->city ?></p>
    <p><?php print $address->country ?></p>
    <p><?php print $address->phone_number ?></p>
    <?php if (!empty($address->mobile_number)) : ?>
        <p><?php print $address->mobile_number ?></p>
    <?php endif ?>
  </div>

  <div class="b-btns-edit">
    <?php
      $href_edit = url("souriau/ajax/address/edit/form/{$commerce_customer_profile->profile_id}");
      $href_delete = url("souriau/ajax/address/delete/confirm/{$commerce_customer_profile->profile_id}");
    ?>

    <a href="<?php print $href_edit ?>" class="edit-link btn-addr-open js-edit-address-link">
      <span class="ico ico-edit">
        <!--[if gte IE 9]><!-->
        <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
        <!--<![endif]-->
          </span>
      <span class="screen-reader-text"><?php print t('Edit') ?></span>
    </a>

    <a href="<?php print $href_delete ?>" class="remove-link ctools-use-modal ctools-modal-souriau-modal-style" data-toggle="modal" data-target="#removeModal">
          <span class="ico ico-remove">
            <!--[if gte IE 9]><!-->
            <svg class="svg-ico"><use xlink:href="#ico-remove"></use></svg>
            <!--<![endif]-->
          </span>
      <span class="screen-reader-text"><?php print t('Remove product from shopping cart') ?></span>
    </a>
  </div>
</div>
