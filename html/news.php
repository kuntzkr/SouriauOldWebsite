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
              <li><a href="#">NEWS</a></li>
              <li class="without-link">TITLE OF THE ARTICLE</li>
            </ul>
          </div>
        </div>
      </div>

      <?php include "inc/blocks/block-single-news.php"; ?>

      <?php include "inc/blocks/block-news2.php"; ?>

      <?php include "inc/blocks/block-newsletter.php"; ?>

    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>