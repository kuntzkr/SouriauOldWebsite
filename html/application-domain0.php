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
      <div class="w-banner-block landing-app-banner">
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
                <li><a href="#">APPLICATIONS</a></li>
                <li class="without-link">INDUSTRIAL</li>
              </ul>
            </div>
          </div>
        </div>

        <div class="b-banner">
          <figure class="pic">
            <img src="images/temp/app-domain-banner.jpg" alt="banner image" />
          </figure>
        </div>
      </div>

      <div class="b-app-description">
        <div class="container">
          <div class="b-title wide-title">
            <h1>Industrial</h1>
          </div>

          <div class="b-row">
            <div class="b-text a-left">
              <p>LCD screens are uniquely modern in style, and the liquid crystals that make them work have allowed humanity to create slimmer, more portable technology than we’ve ever had access to before. </p>
            </div>

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
          </div>
        </div>
      </div>

      <?php include "inc/blocks/block-application3.php"; ?>

      <?php include "inc/blocks/block-news.php"; ?>

      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>