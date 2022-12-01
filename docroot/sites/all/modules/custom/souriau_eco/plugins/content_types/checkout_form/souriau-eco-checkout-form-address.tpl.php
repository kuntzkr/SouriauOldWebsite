<?php
/**
 * @file
 * Template .
 */
?>

<?php $children = element_children($element) ?>
<?php if (count($children) > 1) : ?>
  <div class="b-list-address">
    <div class="b-title">
      <?php print t('CHOOSE AN ADDRESS:', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
    </div>
    <div class="b-row matchHeight">
      <?php foreach(element_children($element) as $element_name): ?>
        <?php if ($element_name != 'none'): ?>
          <?php print $element[$element_name]['#children']; ?>
        <?php endif; ?>
      <?php endforeach; ?>
    </div>
  </div>
<?php endif ?>

<div class="w-btn text-center b-create-new-address clearfix">
  <?php print $element['none']['#children']; ?>
</div>
