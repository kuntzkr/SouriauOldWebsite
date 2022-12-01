<!DOCTYPE html>
<html lang="en" class="no-js">
<head>
  <?php include "inc/head.php"; ?>
</head>
<body>
  <!-- icons set -->
    <!--[if gte IE 9]><!-->
      <div id="site-svg-target"></div>
      <script type="text/javascript" src="js/svg/svg.js"></script>
    <!--<![endif]-->
  <!-- /icons set -->
  <div class="page">
    <?php include "inc/main-header.php"; ?>
    <div class="main-content">
      <div class="w-banner-block product-banner">
        <div class="w-breadcrumb">
          <div class="container">
            <div class="b-share">
              <a href="#" class="share-link">
                <span class="ico ico-share">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-share"></use></svg>
                <!--<![endif]-->
                </span>
                SHARE
              </a>
            </div>
            <div class="breadcrumb">
              <ul>
                <li><a href="#">HOME</a></li>
                <li><a href="#">PRODUCTS</a></li>
                <li><a href="#">CONDUITS</a></li>
                <li class="without-link">BULK CONDUITS</li>
              </ul>
            </div>
          </div>
        </div>

        <div class="b-banner">
          <figure class="pic">
            <img src="images/temp/product-range-banner.jpg" alt="banner image" />
          </figure>
        </div>

        <div class="container">
          <div class="b-content">
            <div class="title">
              <h1>Bulk Conduits</h1>
            </div>
            <div class="b-bottom">
              <div class="w-search-row">
                <a class="btn link_search" href="#">
                  <span class="ico ico-search">
                    <!--[if gte IE 9]><!-->
                      <svg class="svg-ico"><use xlink:href="#ico-search"></use></svg>
                  <!--<![endif]-->
                  </span>
                  <span class="btn-txt">FIND A PART NUMBER</span>
                </a>
              </div>
              <div class="b-share">
                <a href="#" class="share-link">
                  <span class="ico ico-share">
                    <!--[if gte IE 9]><!-->
                      <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-share"></use></svg>
                  <!--<![endif]-->
                  </span>
                  SHARE
                </a>
              </div>
            </div>
          </div>
        </div>
      </div>

      <div class="b-downloads-links" data-attr="block-links">
        <div class="container">
          <div class="col-text">
            <h2>Downloads</h2>
          </div>
          <div class="col-links">
            <ul>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Full Catalog
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Products Overview Products Overview Products Overview
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Contact Layouts
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Full Catalog
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Products Overview
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                8D Aluminum
              </a></li> 
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Common Section
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Contact Layouts
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                8D Aluminum
              </a></li>
              <li><a href="#">
                <span class="ico ico-pdf">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-pdf"></use></svg>
                  <!--<![endif]-->
                </span>
                Common Section
              </a></li>
            </ul>           
          </div>
        </div>
      </div>

      <div class="divider hidden-xs"></div>

      <?php include "inc/blocks/block-features.php"; ?>

      <div class="divider"></div>

      <?php include "inc/blocks/block-list-info.php"; ?>

      <?php include "inc/blocks/block-tool-promotion.php"; ?>

      <?php include "inc/blocks/block-application.php"; ?>

      <div class="b-top-products">
        <div class="container">
          <h2>Similar Product ranges</h2>
          <?php include "inc/blocks/block-product-items.php"; ?>
        </div>
      </div>

      <div class="b-top-products dark-bg">
        <div class="container">
          <h2>Complementary <span>Product ranges</span></h2>
          <?php include "inc/blocks/block-product-items.php"; ?>
        </div>
      </div>

      <?php include "inc/blocks/block-news.php"; ?>

      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>