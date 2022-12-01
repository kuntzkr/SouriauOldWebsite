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
              <li class="without-link">FAQ</li>
            </ul>
          </div>
        </div>
      </div>

      <div class="container">
        <h1 class="faq-title">Need some help ?</h1>
      </div>

      <?php include "inc/blocks/block-popular-questions.php"; ?>

      <div class="b-themes-list">
        <div class="container">
          <div class="items">
            <a class="item" href="#general">
              <div class="b-align">
                <h5>General</h5>
                <span class="b-count">4 QUESTIONS</span>
              </div>
            </a>

            <a class="item" href="#support">
              <div class="b-align">
                <h5>Technical support</h5>
                <span class="b-count">4 QUESTIONS</span>
              </div>
            </a>

            <a class="item" href="#sales">
              <div class="b-align">
                <h5>Sales</h5>
                <span class="b-count">4 QUESTIONS</span>
              </div>
            </a>

            <a class="item" href="#tab">
              <div class="b-align">
                <h5>Tab</h5>
                <span class="b-count">4 QUESTIONS</span>
              </div>
            </a>
          </div>
        </div>
      </div>

      <div class="w-questions">
        <?php include "inc/blocks/block-general-questions.php"; ?>
        <?php include "inc/blocks/block-support-questions.php"; ?>
        <?php include "inc/blocks/block-sales-questions.php"; ?>
        <?php include "inc/blocks/block-tab-questions.php"; ?>
      </div>

      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>