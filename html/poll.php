<!DOCTYPE html>
<html lang="en" class="no-js">
<head>
  <?php include "inc/head.php"; ?>
</head>
<body class="homepage">
  <!-- icons set -->
    <!--[if gte IE 9]><!-->
      <div id="site-svg-target"></div>
      <script type="text/javascript" src="js/svg/svg.js"></script>
    <!--<![endif]-->
  <!-- /icons set -->

  <a class="b-poll" href="#" data-toggle="modal" data-target="#pollModal">
    Participate to our exclusive survey
  </a>
  <div class="page">
    <?php include "inc/main-header.php"; ?>
    <div class="main-content">
      <?php include "inc/blocks/block-main-slider.php"; ?>

      <?php include "inc/blocks/block-promotions.php"; ?>

      <div class="b-top-products">
        <div class="container">
          <h4>Our top products</h4>
          <?php include "inc/blocks/block-product-items3.php"; ?>
        </div>
      </div>

      <div class="b-help">
        <div class="container">
          <a class="view-more" href="#">GET STARTED</a>
          <div class="text">
            <h4>Need help to find your product?</h4>
            <p>Our beginner guide will help you step by step</p>
          </div>
        </div>
      </div>

      <div class="b-list-events">
        <div class="container">
          <h4>News and events</h4>

          <?php include "inc/blocks/block-events.php"; ?>
        </div>
      </div>

      <div class="divider hidden-xs"></div>

      <div class="b-toolkit">
        <div class="container">
          <h4>Our tools</h4>

          <div class="b-boxes-list">
            <div class="b-col">
              <a href="#" class="b-blue-box">
                <figure class="pic">
                  <img src="images/temp/tool-img.jpg" alt="tool image">
                </figure>

                <div class="v-align">
                  <div class="b-catchline">
                    build a
                  </div>
                  <h4>
                    Backshell
                  </h4>
                </div>
              </a>
            </div>

            <div class="b-col">
              <a href="#" class="b-blue-box">
                <figure class="pic">
                  <img src="images/temp/tool-img.jpg" alt="tool image">
                </figure>

                <div class="v-align">
                  <div class="b-catchline">
                    CONDUIT SIZE
                  </div>
                  <h4>
                    Calculator
                  </h4>
                </div>
              </a>
            </div>

            <div class="b-col">
              <a href="#" class="b-blue-box">
                <figure class="pic">
                  <img src="images/temp/tool-img.jpg" alt="tool image">
                </figure>

                <div class="v-align">
                  <h4>
                    Cross Referencing
                  </h4>
                </div>
              </a>
            </div>

            <div class="b-col">
              <a href="#" class="b-blue-box">
                <figure class="pic">
                  <img src="images/temp/tool-img.jpg" alt="tool image">
                </figure>

                <div class="v-align">
                  <div class="b-catchline">
                    ARINC600
                  </div>
                  <h4>
                    Configurator
                  </h4>
                </div>
              </a>
            </div>
          </div>
        </div>
      </div>

      <div class="b-presentation hidden-xs">
        <figure class="pic">
          <img src="images/temp/img-3.jpg" alt="brand image">
        </figure>
        <div class="text">
          <div class="b-align">
            <div class="b-align">
              <p>SOURIAU - SUNBANK Connection technologies<br> is the consolidation of <span class="one-line">Souriau and Sunbank,</span><br> two leading interconnect product manufacturers</p>
            </div>
          </div>
        </div>
      </div>

      <?php include "inc/blocks/block-newsletter.php"; ?>

      <div class="b-bottom-slogan  hidden-xs">
        <div class="container">
          <p>Reliable People, Reliable Solutions</p>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
  <!-- Modal -->
  <?php include "inc/blocks/block-poll-popup.php"; ?>
  <?php include "inc/blocks/block-poll-result-popup.php"; ?>
</body>
</html>