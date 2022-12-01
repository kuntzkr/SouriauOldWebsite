<?php
/**
 * @file
 * Default template file souriau-contact-two-col.tpl.php.
 */
?>
<div class="b-contact">
  <div class="container">
    <h1><?php print t('Contact', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></h1>
    <div class="b-two-cols">
      <?php if (!empty($content['top_left'])): ?>
        <?php print $content['top_left']; ?>
      <?php endif; ?>
      <?php if (!empty($content['top_right'])): ?>
        <?php print $content['top_right']; ?>
      <?php endif; ?>
    </div>
    <div class="b-add-question">
      <h2><?php print t('I have a question', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
      <?php if (!empty($content['content'])): ?>
        <?php print $content['content']; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
