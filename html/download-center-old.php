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
              <li class="without-link">DOWNLOAD CENTER</li>
            </ul>
          </div>
        </div>
      </div>

      <div class="b-download-center">
        <div class="container">
          <div class="b-title-with-link">
            <h1>Download center</h1>
            <div class="right-link">
              <a href="#" data-block-clear="documents-filter" class="clear-filter">CLEAR FILTERS</a>
            </div>
          </div>

          <?php include "inc/blocks/block-filters.php"; ?>

          <?php include "inc/blocks/block-list-documents.php"; ?>

          <div class="w-btn text-center">
            <a href="#" class="view-more blue-btn">LOAD MORE</a>
          </div>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>