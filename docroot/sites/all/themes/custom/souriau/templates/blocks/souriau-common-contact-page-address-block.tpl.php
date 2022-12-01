<?php
/**
 * @file
 * Template.
 */
?>
<div id="contact_address_list" class="b-address-list">
  <?php if(!empty($_html['address'])) : ?>
    <div class="slider-address">
      <?php foreach ($_html['address'] as $address_val) : ?>
        <div class="address-item">
          <h6><?php print $address_val['name']; ?></h6>
          <p><?php print $address_val['address1']; ?></p>
          <p><?php print $address_val['address2']; ?></p>
          <p><?php print $address_val['postal_code']; ?> <?php print $address_val['city']; ?></p>
          <p><?php print $address_val['country']; ?></p>
          <p><?php print $address_val['phone_no']; ?></p>
          <p><?php print $address_val['fax_no']; ?></p>
          <p>
            <?php if (!empty($address_val['email'])): ?>
              <a href="mailto:<?php print $address_val['email'] ?>">
                <?php print $address_val['email']; ?>
              </a>
            <?php endif ?>
          </p>
        </div>
    <?php endforeach;?>
    </div>
    <?php if (count($_html['address']) > 2) : ?>
      <div class="slider-arrows">
        <a href="#" class="prev"><span class="screen-reader-text">prev slide</span></a>
        <a href="#" class="next"><span class="screen-reader-text">next slide</span></a>
      </div>
    <?php endif; ?>
  <?php else : ?>
    <?php print t('No contacts found.', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
  <?php endif; ?>
</div>
