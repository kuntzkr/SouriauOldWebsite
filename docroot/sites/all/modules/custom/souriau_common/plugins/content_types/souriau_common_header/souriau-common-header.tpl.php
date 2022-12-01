<?php

/**
 * @file
 * Template.
 */
print $svg_icons_set;
?>
<?php if (!empty($_html['poll_link'])): ?>
  <?php print $_html['poll_link']; ?>
<?php endif ?>
<header class="main-header cookie-alert">
  <div class="header-container-wrapper">
    <div class="container">
      <div class="top-header">
        <div class="b-language pull-left">
          <?php print $_html['country']; ?>
        </div>
      </div>

      <div class="b-account pull-right">
        <?php print $_html['user_menu_fist']; ?>
        <?php if ($_html['user_menu']) : ?>
          <div class="w-popup-account change-aria" data-parent=".b-account" aria-hidden="true">
            <div class="wrapper">
              <?php print $_html['user_menu']; ?>
            </div>
          </div>
        <?php endif ?>
      </div>

      <div class="b-cart pull-right" data-ajax-url="<?php print $_html['minicart_url']; ?>">
        <?php print $_html['cart']; ?>

        <div class="w-popup-cart change-aria" data-parent=".b-cart" aria-hidden="true">
          <div class="wrapper" id="cart-minicart-block">
            <!-- Minicart content goes here -->
          </div>
        </div>
      </div>
      <div class="clearfix"></div>
    </div>
  </div>
  <?php if ($_html['alert_banner']['show'] && !empty($_html['alert_banner']['banner_message']['value'])): ?>
    <div class="search-alert-banner"><?php print $_html['alert_banner']['banner_message']['value']; ?></div>
  <?php endif ?>
  <div class="top-row">
    <div class="container">

      <div class="col a-left">
        <h1><?php print $_html['logo']; ?></h1>
      </div>

      <a class="search-link a-right btn" data-open-search="header-search">
        <span class="ico ico-search">
          <!--[if gte IE 9]><!-->
            <svg class="svg-ico"><use xlink:href="#ico-search"></use></svg>
          <!--<![endif]-->
        </span>
        <span class="text visible-lg-block"><?php print t('SEARCH FOR PART NUMBER, KEYWORDS, RANGE', [], ['context' => SOURIAU_COMMON_T_HEADER]); ?></span>
      </a>
    </div>
  </div>

  <div class="bottom-row">
    <div class="container">
      <div class="b-links">
        <?php print $_html['b_links']; ?>
      </div>
      <div class="w-menu">
        <div class="icon-header-nav-mobile">
          <span class="ico ico-menu">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico" ><use xlink:href="#ico-menu"></use></svg>
            <!--<![endif]-->
          </span>
        </div>
        <div class="block-header-nav">
          <nav>
            <?php print $_html['menu']; ?>
            <div class="additional-link hidden-lg">
              <?php print $_html['additional_links']; ?>
              <hr />
              <div class="top-header">
                <div class="b-language">
                  <?php print $_html['country']; ?>
                </div>
              </div>
            </div>
          </nav>

          <a href="#" class="close-btn">
            <span class="ico ico-close">
              <!--[if gte IE 9]><!-->
                <svg class="svg-ico" ><use xlink:href="#ico-close"></use></svg>
              <!--<![endif]-->
            </span>
            <span class="screen-reader-text">
              <?php print t('Close popup', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
            </span>
          </a>
        </div>
      </div>
    </div>
  </div>
  <div class="w-search<?php print $_html['search_class']; ?>" id="header-search">
    <div class="container">
      <?php print $_html['search_form']; ?>
      <div class="b-autocomplete-wrapper">
        <div class="b-search-autocomplete" id="b-search-autocomplete"></div>
        <div class="view-all-wrapper">
          <a href="#" class="link-view-all-results visible-xs-block b-to-fixed">
            ALL RESULTS

            <span class="ico ico-arrow-right">
              <!--[if gte IE 9]><!-->
                <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-arrow-right"></use></svg>
              <!--<![endif]-->
            </span>
          </a>
        </div>
      </div>
    </div>
  </div>
</header>
