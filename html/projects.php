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
            BACK TO MY ACCOUNT
          </a>
        </div>
      </div>

      <div class="b-projects">
        <div class="container">
          <div class="w-new-project">
            <div class="w-btn hidden-xs">
              <a href="#" class="btn blue-btn" data-toggle="modal" data-target="#projectModal">+ CREATE NEW PROJECT</a>
            </div>

            <div class="w-btn">
              <div class="visible-xs-block">
                <a href="add-project.php" class="btn blue-btn">+ CREATE NEW PROJECT</a>
              </div>
            </div>
            <h1>My projects</h1>
          </div>

          <div class="b-project-item">
            <figure class="pic">
              <img src="images/temp/project-img.png" alt="project image">
            </figure>
            <div class="w-btn">
              <a href="#" class="btn orange-btn-hover">SEE MY PROJECT</a>
            </div>
            <div class="b-info">
              <h3>Project number 1</h3>
              <p>
                Short description of the project
              </p>
              <p>
                3 Part Numbers
              </p>
            </div>
          </div>
          <div class="b-project-item">
            <figure class="pic">
              <img src="images/temp/project-img.png" alt="project image">
            </figure>
            <div class="w-btn">
              <a href="#" class="btn orange-btn-hover">SEE MY PROJECT</a>
            </div>
            <div class="b-info">
              <h3>Project number 2</h3>
              <p>
                Short description of the project
              </p>
              <p>
                3 Part Numbers
              </p>
            </div>
          </div>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>

  <!-- Modal -->
  <?php include "inc/blocks/block-project-popup.php"; ?>
</body>
</html>