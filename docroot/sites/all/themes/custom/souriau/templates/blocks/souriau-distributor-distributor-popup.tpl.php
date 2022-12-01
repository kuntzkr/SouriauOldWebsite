<?php
/**
 * @file
 * Template.
 */
?>
<div class="popup-title">
  <h2><?php print t('Where to buy', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
</div>
<div class="list-locators">
  <?php if (empty($_html['distributors'])): ?>
    <?php print t('Available distributors weren\'t found', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
  <?php elseif ($_html['manage'] == 'tipity' && empty($_html['is_default'])): ?>
    <?php foreach ($_html['distributors'] as $distributor): ?>
      <div class="item-locator">
        <h3>
          <a href="<?php print $distributor['pn_link']; ?>" target="_blank">
            <?php print $distributor['name']; ?>
          </a>
        </h3>
        <?php if ($_html['show_stock'] == TRUE): ?>
          <div class="b-stock-quantity">
            <?php print t('Stock availability: @stock', [
              '@stock' => !empty($distributor['quantity']) ? $distributor['quantity'] : '0'
            ],
            ['context' => SOURIAU_COMMON_T_OTHER]);
            ?>
          </div>
        <?php endif; ?>
      </div>
    <?php endforeach; ?>
  <?php else: ?>
    <?php foreach ($_html['distributors'] as $distributor): ?>
      <div class="item-locator">
        <h3><?php print $distributor->name; ?></h3>
        <div class="b-type">
          <?php print $distributor->distributor_type; ?> / <?php print $distributor->brand; ?>
        </div>
        <?php if ($_html['show_stock'] == TRUE): ?>
          <div class="b-stock-quantity">
            <?php print t('Stock availability: @stock', [
              '@stock' => !empty($distributor->quantity) ? $distributor->quantity : '0'
            ],
            ['context' => SOURIAU_COMMON_T_OTHER]);
            ?>
          </div>
        <?php endif; ?>
        <div class="b-address-info">
          <p><?php print $distributor->address_line_1; ?></p>
          <p><?php print $distributor->address_line_2; ?></p>
          <?php if (!empty($distributor->city) || !empty($distributor->postal_code)): ?>
            <p>
              <?php print $distributor->city; ?><?php print (!empty($distributor->city) && !empty($distributor->postal_code)) ? ',' : ''?> 
              <?php print $distributor->postal_code; ?>
            </p>
          <?php endif ?>
          <p><?php print $distributor->country; ?></p>
        </div>
        <div class="b-add-info">
          <p><?php print $distributor->phone; ?></p>
          <p><?php print $distributor->email; ?></p>
        </div>
        <?php if (!is_null($distributor->product_external_url) || !is_null($distributor->url)): ?>
          <div class="w-btn">
            <a class="web-link" href="<?php print (!is_null($distributor->product_external_url)) ? $distributor->product_external_url : $distributor->url; ?>" target="_blank">
              <span class="ico ico-website">
                <!--[if gte IE 9]><!-->
                <svg class="svg-ico"><use xlink:href="#ico-website"/></svg>
                <!--<![endif]-->
              </span>
              <?php print t('GO TO WEBSITE', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
            </a>
          </div>
        <?php endif ?>
      </div>
    <?php endforeach; ?>
  <?php endif; ?>
</div>
