<?php

/**
 * @file
 * Template.
 */
?>
<div class="b-search-contacts col a-right">
  <h2><?php print t('I need to reach you out', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
  <div class="b-select-country">
    <?php print render($form); ?>
  </div>
  <?php print $address_list;?>
</div>
