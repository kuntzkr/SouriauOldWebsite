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
      <div class="w-banner-block application-banner">
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
                <li><a href="#">INDUSTRIAL</a></li>
                <li class="without-link">OFF-ROAD</li>
              </ul>
            </div>
          </div>
        </div>

        <div class="b-banner">
          <figure class="pic">
            <img src="images/temp/application-banner.jpg" alt="banner image" />
          </figure>
        </div>

        <div class="container">
          <div class="b-content">
            <div class="title">
              <h1>Off-Road</h1>
            </div>
            <div class="b-bottom">
              <div class="w-search-row">
                <div class="b-search-num">
                  <form>
                    <div class="w-btn">
                      <button class="btn btn_search">
                        <span class="ico ico-search">
                          <!--[if gte IE 9]><!-->
                            <svg class="svg-ico"><use xlink:href="#ico-search"></use></svg>
                        <!--<![endif]-->
                        </span>
                        <span class="btn-txt">search</span>
                      </button>
                    </div>

                    <div class="form-item form-type-textfield">
                      <input class="form-text" type="text" placeholder="FIND A PART NUMBER"/>
                    </div>
                  </form>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>

      <?php include "inc/blocks/block-features2.php"; ?>

      <div class="divider"></div>

      <?php include "inc/blocks/block-list-info.php"; ?>

      <div class="b-top-products">
        <div class="container">
          <h2>Discover our products</h2>
          <?php include "inc/blocks/block-product-items.php"; ?>
        </div>
      </div>

      <?php include "inc/blocks/block-downloads.php"; ?>

      <div class="divider"></div>

      <?php include "inc/blocks/block-example-items.php"; ?>

      <?php include "inc/blocks/block-news.php"; ?>

      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>