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
      <div class="b-back-link">
        <div class="container">
          <a href="#" class="btn-back">
            <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
            BACK TO MY PROJECTS
          </a>
        </div>
      </div>

      <div class="b-projects">
        <div class="container">
          <div class="b-project-description">
            <div class="w-editable center-text">
              <h1 class="b-editable-area" data-empty-title="Please add title">
                Project Number 1
              </h1>
              <span class="ico ico-edit">
                <!--[if gte IE 9]><!-->
                  <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
                <!--<![endif]-->
                <span class="screen-reader-text">Edit</span>
              </span>
            </div>

            <div class="b-text">
              <div class="w-editable center-text">
                <div class="b-editable-area">Short description of the project</div>

                <span class="ico ico-edit">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
                  <!--<![endif]-->
                  <span class="screen-reader-text">Edit</span>
                </span>
              </div>
            </div>
          </div>
          <div class="w-btn text-right hidden-xs">
            <a href="#" class="link-export">
              <span class="ico ico-export">
                <!--[if gte IE 9]><!-->
                  <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-export"></use></svg>
              <!--<![endif]-->
              </span>
              EXPORT TO CSV
            </a>
          </div>

          <?php include "inc/blocks/block-list-projects.php"; ?>

          <div class="w-btn text-center">
            <a href="#" class="btn blue-btn"  data-toggle="modal" data-target="#removeModal">DELETE PROJECT</a>
          </div>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>

  <!-- Modal -->
  <?php include "inc/blocks/block-remove-popup.php"; ?>
</body>
</html>