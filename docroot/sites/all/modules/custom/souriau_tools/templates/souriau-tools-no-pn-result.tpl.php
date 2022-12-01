<?php
/**
 * @file
 * Result template.
 */
?>
<div id="tools-form-result">
  <div class="container">
    <h4><?php print t('We found a matching product for you %part_number', ['%part_number' => $missing], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
    <p>
      <?php print t('Please contact us for more information on this product:', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
    </p>
    <div class="w-btn">
      <?php print $_html['link']; ?>
    </div>
  </div>
</div>
