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
      <div>
        <div class="w-breadcrumb show-share">
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
                <li class="without-link">Training inquiry</li>
              </ul>
            </div>
          </div>
        </div>
      </div>
      <div class="b-resorce-content">
        <div class="container">
          <h1>Training inquiry</h1>
          <div class="divider"></div>
          <div class="b-resorce-info">
            <?php include "inc/blocks/block-training-inquiry-form.php"; ?>
          </div>
        </div>
      </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>