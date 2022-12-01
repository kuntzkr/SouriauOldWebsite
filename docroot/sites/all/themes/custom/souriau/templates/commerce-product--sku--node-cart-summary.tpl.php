<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-item-info">
  <?php print $_html['image']; ?>
    <a href="#" class="remove-link souriau-proxy-click">
      <span class="ico ico-remove">
        <!--[if gte IE 9]><!-->
          <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-remove"></use></svg>
        <!--<![endif]-->
      </span>
      <span class="screen-reader-text">Remove product from shopping cart</span>
    </a>
  <div class="b-info">
    <div class="b-title">
      <a href="<?php print $_data['partnumber_url']; ?>"> <?php print $_data['partnumber_title']; ?></a>
    </div>
    <p><?php print $_data['display_name']; ?></p>
  </div>
</div>
