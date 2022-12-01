<?php
/**
 * @file
 * Result template.
 */
?>
<div id="tools-form-result">
  <div class="container">
    <h4><?php print t('Sorry, we didn’t find any matching part number. Please contact us so we can help you.', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
    <div class="w-btn">
      <?php print $_html['link']; ?>
    </div>
  </div>
</div>
