<?php
/**
 * @file
 * Result template.
 */
?>
<div id="tools-form-result">
  <div class="container">
    <h4><?php print t('We found a matching product for you %part_number', ['%part_number' => $input], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
    <div class="b-list">
      <?php print $_html['part_numbers']; ?>
    </div>
  </div>
</div>
