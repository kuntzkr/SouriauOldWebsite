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
            BACK TO HOMEPAGE
          </a>
        </div>
      </div>

      <div class="b-generic-box">
        <div class="container">
          <h1>My account</h1>

          <div class="b-description">
            <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse ut augue suscipit purus mollis pharetra nec in diam. Maecenas commodo in justo eu viverra. Nunc suscipit rutrum mattis. Vivamus eleifend massa ultrices velit pulvinar, in cras amet.</p>
          </div>

          <div class="b-boxes-list">
            <div class="b-col">
              <a href="#" class="b-blue-box">
                <div class="v-align">
                  <h4>
                    Edit my account
                  </h4>
                </div>
              </a>
            </div>

            <div class="b-col">
              <a href="#" class="b-blue-box">
                <div class="v-align">
                  <h4>
                    My orders
                  </h4>
                </div>
              </a>
            </div>

            <div class="b-col">
              <a href="#" class="b-blue-box">
                <div class="v-align">
                  <h4>
                    My projects
                  </h4>
                </div>
              </a>
            </div>

            <div class="b-col">
              <a href="#" class="b-blue-box">
                <div class="v-align">
                  <h4>
                    My address book
                  </h4>
                </div>
              </a>
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