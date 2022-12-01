<?php
/**
 * @file
 * Template .
 */
?>

<div class="w-table">
  <table>
    <colgroup>
      <col class="ar-num-col">
      <col class="creation-col">
      <col class="update-col">
      <col class="acknow-col">
      <col class="id-col">
      <col>
    </colgroup>
    <thead>
    <tr>
      <th><?php print t('AR NUMBER', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></th>
      <th><?php print t('CREATION DATE', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></th>
      <th><?php print t('LAST UPDATE', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></th>
      <th><?php print t('ACKNOWLEDGEMENT', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></th>
      <th><?php print t('CSR ID', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></th>
      <th>&nbsp;</th>
    </tr>
    </thead>
    <tbody>
    <?php foreach ($orders as $order) : ?>

      <tr class='clickable-row new-tab' data-href='<?php print url("user/{$user->uid}/erp-orders/{$order->so_no}");?>'>
        <td><?php print $order->so_no ?></td>
        <td><?php print $order->so_creation_date ? format_date(strtotime($order->so_creation_date), 'souriau_date_short') : ''; ?></td>
        <td><?php print $order->so_last_update_date ? format_date(strtotime($order->so_last_update_date), 'souriau_date_short') : ''; ?></td>
        <td><?php print $order->so_ack_date ? format_date(strtotime($order->so_ack_date), 'souriau_date_short') : ''; ?></td>
        <td><?php print $order->csr_firstname . ' ' . $order->csr_surname ?></td>
        <td>
            <span class="b-view">
              <span class="ico ico-view">
                <!--[if gte IE 9]><!-->
                  <svg class="svg-ico"><use xlink:href="#ico-view"></use></svg>
                <!--<![endif]-->
                </span>
              <span class="screen-reader-text"><?php print t('view order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></span>
            </span>
        </td>
      </tr>

    <?php endforeach ?>
    </tbody>
  </table>
</div>


<?php print $pager ?>
