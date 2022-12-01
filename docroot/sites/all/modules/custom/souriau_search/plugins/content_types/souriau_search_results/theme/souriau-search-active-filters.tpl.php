<?php
/**
 * @file
 * Search page filter template.
 */
?>
<div class="b-list-filters">
  <?php foreach ($items as $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>
</div>
