<?php
/**
 * @file
 * Template .
 *
 * @var $product_title string
 * @var $product_code string
 * @var $product_image string
 * @var $product_id int
 * @var $product_series string
 */
?>
<div class="b-compare-prod">
  <a href="#" class="close-btn js-compare-remove-product"
     data-part-number-id="<?php print $product_id ?>">
    <span class="ico ico-close">
      <!--[if gte IE 9]><!-->
        <svg class="svg-ico" ><use xlink:href="#ico-close"></use></svg>
      <!--<![endif]-->
    </span>
    <span class="screen-reader-text">
      <?php print t('Remove product from compare list', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?>
    </span>
  </a>
  <?php print $product_image ?>
  <div class="b-part-numb"><?php print $product_code ?></div>
  <div class="w-btn">
    <?php print $where_to_buy ?>
  </div>

  <?php
  $_link_text = t('VIEW DESCRIPTION', [], ['context' => SOURIAU_COMMON_T_COMMERCE]);
  $_link_attr = [
    'attributes' => [
      'class' => ['link-view-description'],
    ],
  ];

  print l($_link_text, 'node/' . $product_id, $_link_attr) ?>
</div>
