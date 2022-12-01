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
                <li class="without-link">PRODUCTS</li>
              </ul>
            </div>
          </div>
        </div>

        <div class="b-banner">
          <figure class="pic">
            <img src="images/temp/product-banner2.jpg" alt="banner image">
          </figure>
        </div>

        <div class="container">
          <div class="b-content">
            <div class="b-title"><h1>Products</h1></div>
          </div>
        </div>
      </div>

      <?php include "inc/blocks/block-products-category.php"; ?>

      <div class="b-pr-description">
        <div class="container">
          <p>Souriau is one of the major suppliers of industrial interconnect technologies.<br>
          Offering a wide array of solutions from standard to harsh environment for<br>signal and power transmission either with copper or fiber optics technologies.
          </p>
        </div>
      </div>

      <?php include "inc/blocks/block-interest.php"; ?>

      <div class="b-top-products">
        <div class="container">
          <h2>Our top products</h2>
          <?php include "inc/blocks/block-product-items.php"; ?>
        </div>
      </div>

      <?php include "inc/blocks/block-brand.php"; ?>
      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>