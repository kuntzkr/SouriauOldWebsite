<?php
/**
 * @file
 * Template Order Details.
 */
?>

<div class="w-breadcrumb">
  <div class="container">
    <div class="breadcrumb">
      <ul>
        <li><?php print l(t('HOME', [], ['context' => SOURIAU_COMMON_T_OTHER]), '<front>') ?></li>
        <li class="without-link"><?php print t('Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?> #<?php print $order->cust_po_no;?></li>
      </ul>
    </div>
  </div>
</div>
<div class="b-order-detail">
  <div class="container">
    <?php if(!empty($order)): ?>
    <h1><?php print t('Order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?> <span>#<?php print $order->cust_po_no;?></span></h1>

    <div class="b-order-info">
      <div class="b-shipping a-left">
        <h2><?php print t('Shipping Adress', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?></h2>
        <div class="name">
          <p><?php print $order->cust_name;?></p>
        </div>
        <p><?php print $order->ship_to_ad_line1;?></p>
        <p><?php print $order->ship_to_ad_line2;?></p>
        <p><?php print $order->ship_to_ad_zip . ' ' . $order->ship_to_ad_city;?></p>
        <p><?php print $order->ship_to_ad_country;?></p>
      </div>
      <div class="b-info a-right">
        <div class="b-row">
          <div class="title"><?php print t('Customer Number', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?></div>
          <div class="description"><?php print $order->cust_erp_code;?></div>
        </div>
        <div class="b-row">
          <div class="title"><?php print t('AR', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?></div>
          <div class="description"><?php print $order->so_no;?></div>
        </div>
        <div class="b-row">
          <div class="title"><?php print t('Order creation date', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?></div>
          <?php if (!empty($order->so_creation_date)): ?>
            <div class="description"><?php print format_date(strtotime($order->so_creation_date), 'souriau_date_short');?></div>
          <?php endif;?>
        </div>
        <div class="b-row">
          <div class="title"><?php print t('Order last update date', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);?></div>
          <?php if (!empty($order->so_last_update_date)): ?>
            <div class="description"><?php print format_date(strtotime($order->so_last_update_date), 'souriau_date_short');?></div>
          <?php endif;?>
        </div>
      </div>
    </div>

      <?php if (!empty($table)): ?>
      <div class="b-order-lines">
        <div class="w-table panel-group table-accordion" id="accordion" role="tablist" >
          <?php print $table;?>
        </div>
      </div>
      <?php endif;?>
    <?php endif;?>
  </div>
</div>
