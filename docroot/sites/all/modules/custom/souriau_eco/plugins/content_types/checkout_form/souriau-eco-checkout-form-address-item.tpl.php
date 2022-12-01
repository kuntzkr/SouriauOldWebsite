<?php
/**
 * @file
 * Template .
 */
?>
<?php if($element['#return_value'] == 'none'): ?>
  <?php print $element['#children']; ?>
<?php else: ?>
  <div class="item-row b-address-item a-<?php print $element['#align'] ?>">
    <div class="b-check">
      <?php print $element['#children']; ?>
    </div>
    <div class="b-info">
      <?php foreach ($element['#info'] as $name => $value) : ?>
        <p>
          <?php if ($name == 'title'): ?>
            <strong> <?php print $value; ?> </strong>
            <?php else : ?>
            <?php print $value ?>
           <?php endif; ?>
        </p>
      <?php endforeach; ?>
    </div>
    <div class="b-btns-edit">

      <a href="#" class="edit-link btn-addr-open">
        <span class="ico ico-edit">
              <!--[if gte IE 9]><!-->
                <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
          <!--<![endif]-->
            </span>
        <span class="screen-reader-text"><?php print t('Edit', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></span>
      </a>

    </div>
  </div>
<?php endif; ?>
