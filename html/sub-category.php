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
      <div class="category-banner w-banner-block">
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
            <img src="images/temp/sub-category-banner.jpg" alt="banner image" />
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

      <div class="b-category-description grey-bg">
        <div class="container">
          <p>Souriau offers a full range of aluminum backshells and caps. The best choice for a global solution provider. Impetus in et ore signa refertissimam tenuerunt postea ignorat omnis et ignorat ornatissimam et urbis tum signa maximis ornatissimam signa fuisse signis refertissimam refertissimam et totumque et custodita quis et.</p>
          <p>Impetus in et ore signa refertissimam tenuerunt postea ignorat omnis et ignorat ornatissimam et urbis tum signa maximis ornatissimam signa fuisse signis refertissimam refertissimam et totumque et custodita quis et.
          </p>
        </div>
      </div>

      <div class="list-products">
        <div class="container">
          <?php include "inc/blocks/block-product-items2.php"; ?>
        </div>
      </div>

      <?php include "inc/blocks/block-downloads.php"; ?>

      <?php include "inc/blocks/block-interest.php"; ?>

      <div class="b-top-products">
        <div class="container">
          <h2>Discover our products</h2>
          <?php include "inc/blocks/block-product-items.php"; ?>
        </div>
      </div>

      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>