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
      <div class="w-banner-block capability-banner">
        <div class="w-breadcrumb show-share">
          <div class="container">
            <div class="b-share b-white">
              <a href="#" class="share-link">
                <span class="ico ico-share">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-share"></use></svg>
                <!--<![endif]-->
                </span>
                SHARE
              </a>
            </div>
            <div class="breadcrumb b-white">
              <ul>
                <li><a href="#">HOME</a></li>
                <li><a href="#">CAPABILITIES</a></li>
                <li><a href="#">SIGNAL</a></li>
                <li class="without-link">TITLE #1</li>
              </ul>
            </div>
          </div>
        </div>

        <div class="b-banner">
          <figure class="pic">
            <img src="images/temp/capability-banner.jpg" alt="banner image" />
          </figure>
        </div>

        <div class="container">
          <div class="b-content">
            <div class="title">
              <h1>Title #1</h1>
            </div>
          </div>
        </div>
      </div>

      <?php include "inc/blocks/block-features2.php"; ?>

      <div class="divider"></div>

      <?php include "inc/blocks/block-list-info2.php"; ?>

      <div class="b-top-products">
        <div class="container">
          <h2>Our Top Products</h2>
          <?php include "inc/blocks/block-product-items.php"; ?>
        </div>
      </div>

      <?php include "inc/blocks/block-downloads2.php"; ?>

      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>