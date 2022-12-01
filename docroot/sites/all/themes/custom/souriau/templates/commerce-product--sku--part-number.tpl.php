<?php

/**
 * @file
 * Template.
 */
?>
<section class="b-technical-data">
<?php if (!empty($_html['tech_data'])): ?>
  <div class="container">
    <h2><?php print t('Technical Data', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></h2>
    <div class="b-data">
      <div class="b-row-title">
        <div class="col"><?php print t('DESCRIPTION', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></div>
        <div class="col"><?php print t('INFO', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></div>
      </div>
      <?php foreach ($_html['tech_data'] as $item): ?>
        <div class="b-row">
          <div class="col">
            <?php print t($item['label'], [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
          </div>
          <div class="col">
            <?php print souriau_eco_clean_decimal($item['value']); ?>
          </div>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
<?php endif; ?>
</section>
