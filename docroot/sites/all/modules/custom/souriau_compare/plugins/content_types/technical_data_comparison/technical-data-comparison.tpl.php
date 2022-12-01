<?php
/**
 * @file
 * Template .
 */
?>

<?php if (count($part_numbers) < 2) {
  return;
} ?>

<div class="b-compare-common b-compare-second js-compare-second">
  <div class="container">
    <div class="b-compare-left">
      <table cellpadding="0" cellspacing="0">
        <tbody>

        <?php foreach ($tech_data as $label => $values) : ?>
          <tr>
            <td>
              <div class="padder"><?php print $label ?></div>
            </td>
          </tr>
        <?php endforeach ?>

        </tbody>
      </table>
    </div>

    <div class="b-compare-right">
      <div class="compare_scroller">
        <table cellpadding="0" cellspacing="0">
          <tbody>

          <?php foreach ($tech_data as $values): ?>
            <tr>
              <?php foreach ($values as $product_id => $value): ?>
                <td style="vertical-align: top" data-part-number-id="<?php print $product_id; ?>">
                  <div class="padder" style="display: inline-block"><?php print $value ?></div>
                </td>
              <?php endforeach ?>
            </tr>
          <?php endforeach ?>

          </tbody>
        </table>
      </div>
    </div>
  </div>
</div>
