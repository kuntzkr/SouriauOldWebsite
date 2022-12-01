<?php
/**
 * @file
 * Template file.
 */
?>
<div class="col-xs-12 main">
  <?php if (!empty($content['above'])): ?>
    <?php print $content['above']; ?>
  <?php endif; ?>
</div>
<div class="col-xs-12 main">
  <?php if (!empty($content['content'])): ?>
    <?php print $content['content']; ?>
  <?php endif; ?>
</div>
<div class="col-xs-12 main">
  <?php if (!empty($content['below'])): ?>
    <?php print $content['below']; ?>
  <?php endif; ?>
</div>