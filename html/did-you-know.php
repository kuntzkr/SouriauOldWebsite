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
          <div class="breadcrumb">
            <ul>
              <li><a href="#">HOME</a></li>
              <li class="without-link">DID YOU KNOW</li>
            </ul>
          </div>
        </div>
      </div>

      <div class="b-app-description">
        <div class="container">
          <div class="b-title wide-title">
            <h1>Did You Know?</h1>
          </div>

          <div class="b-row">
            <div class="b-text a-left">
              <p>Short description if any</p>
            </div>
          </div>
        </div>
      </div>

      <?php include "inc/blocks/block-did-you-know.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>
