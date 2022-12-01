<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<div class="b-themes-list">
  <div class="container">
      <div class="items">
        <?php foreach ($rows as $id => $row): ?>
          <div>
            <?php print $row; ?>
          </div>
        <?php endforeach; ?>
    </div>
  </div>
</div>