<?php
/**
 * @file
 * Default template file souriau-main.tpl.php.
 */
?>
<div class="page">
  <?php if (!empty($content['header'])): ?>
    <?php print $content['header']; ?>
  <?php endif; ?>
  <div class="main-content">
    <?php if (!empty($content['content'])): ?>
      <?php print $content['content']; ?>
    <?php endif; ?>
  </div>
  <?php if (!empty($content['footer'])): ?>
    <?php print $content['footer']; ?>
  <?php endif; ?>
</div>
