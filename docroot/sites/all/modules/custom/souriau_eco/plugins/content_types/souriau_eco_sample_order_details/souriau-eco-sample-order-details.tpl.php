<?php
/**
 * @file
 * Template Sample Order Details.
 */
?>

<div class="w-breadcrumb">
  <div class="container">
    <div class="breadcrumb">
      <ul>
        <li><?php print l(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>'); ?></li>
        <li><?php print l(t('SAMPLE ORDERS', [], ['context' => SOURIAU_COMMON_T_OTHER]), 'user/' . $uid . '/sample-orders'); ?></li>
        <li class="without-link"><?php print t('Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?> #<?php print $order->order_number; ?></li>
      </ul>
    </div>
  </div>
</div>
<div class="b-order-detail">
  <div class="container">
    <?php if(!empty($order)): ?>
      <h1><?php print t('Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?> <span>#<?php print $order->order_number;?></span></h1>
      <div class="b-order-info">
        <div class="b-shipping a-left">
          <h2><?php print t('Shipping Adress', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></h2>
          <div class="name">
            <p><?php print $shipping_info['first_name'] . ' ' . $shipping_info['last_name']; ?></p>
          </div>
          <p><?php print $shipping_info['premise']; ?></p>
          <p><?php print $shipping_info['locality']; ?></p>
          <p><?php print $shipping_info['postal_code'] . ' ' . $shipping_info['administrative_area']; ?></p>
          <p><?php print $shipping_info['country']; ?></p>
        </div>
        <div class="b-info a-right">
          <div class="b-row">
            <div class="title"><?php print t('Order creation date', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></div>
            <div class="description"><?php print $created_date; ?></div>
          </div>
          <div class="b-row">
            <div class="title"><?php print t('Order last update date', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></div>
            <?php if (!empty($order->changed)): ?>
              <div class="description"><?php print $changed_date; ?></div>
            <?php endif; ?>
          </div>
          <div class="b-row">
            <div class="title"><?php print t('Order status', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></div>
            <div class="description">
              <?php if (isset($order->field_commerce_mouser_status[LANGUAGE_NONE][0]['value'])): ?>
                <?php print $order->field_commerce_mouser_status[LANGUAGE_NONE][0]['value']; ?>
              <?php else: ?>
                <?php print $order->status; ?>
              <?php endif; ?>
            </div>
          </div>
          <?php if (isset($order->field_commerce_shipping_link[LANGUAGE_NONE][0]['value'])): ?>
            <div class="b-row">
              <div class="title"><?php print t('Track', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></div>
              <div class="description">
                <a href="<?php print $order->field_commerce_shipping_link[LANGUAGE_NONE][0]['value']; ?>" target="_blank">
                  <?php print t('Track Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
                </a>
              </div>
            </div>
          <?php endif; ?>
        </div>
      </div>
    <?php print $lineitems; ?>
    <?php endif; ?>
  </div>
</div>
