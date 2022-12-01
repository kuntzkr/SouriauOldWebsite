<?php
/**
 * @file
 * Template .
 *
 * @var $part_numbers array
 */
?>



<?php if (count($part_numbers) < 2): ?>
  <div class="b-info-message text-center">
    <div class="container">
      <?php print t('You need to select at least 2 part numbers to start comparison', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
    </div>
  </div>
<?php else: ?>
  <div class="b-compare-common b-compare-first js-compare-first">
    <div class="fixed">
      <div class="container">
        <div class="b-compare-left">
          <table cellpadding="0" cellspacing="0">
            <tbody>
            <tr>
              <td>
                <div class="padder">
                  <h2><?php print t('Comparator', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></h2>
                </div>
              </td>
            </tr>
            </tbody>
          </table>
        </div>

      <div class="b-compare-right">
        <div class="compare_scroller">
          <table cellpadding="0" cellspacing="0">
            <tr>
              <?php foreach ($part_numbers as $product_id => $part_number) : ?>
                <td data-part-number-id="<?php print $product_id ?>">
                  <div class="padder">
                    <?php print $part_number ?>
                  </div>
                </td>
              <?php endforeach ?>
            </tr>
          </table>
        </div>
      </div>
    </div>
  </div>
</div>
<?php endif;?>
