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
              <li class="without-link">TRAINING CENTER</li>
            </ul>
          </div>
        </div>
      </div>

      <div class="b-resorces">
        <div class="container">
          <h1>Training center</h1>
        </div>

        <div class="b-list-resources">
          <div class="container">
            <h2>Popular</h2>

            <?php include "inc/blocks/block-resources.php"; ?>
          </div>
        </div>

        <div class="divider  hidden-xs"></div>

        <div class="b-list-resources">
          <div class="container">
            <h2>My favorites</h2>

            <?php include "inc/blocks/block-resources.php"; ?>
          </div>
        </div>

        <div class="divider  hidden-xs"></div>

        <div class="b-list-resources">
          <div class="container">
            <h2>Filtered</h2>
            <div class="b-filters">
              <div class="b-form">
                <form>
                  <div class="b-theme-filters">
                    <div class="form-item form-type-select">
                      <label for="themes"></label>
                      <select id="themes" class="default">
                        <option class="hideme">Themes</option>
                        <option>Theme 1</option>
                        <option>Theme 2</option>
                        <option>Theme 3</option>
                        <option>Theme 4</option>
                        <option>Theme 5</option>
                      </select>
                    </div>
                  </div>
                </form>
              </div>
            </div>

            <?php include "inc/blocks/block-resources.php"; ?>
          </div>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>