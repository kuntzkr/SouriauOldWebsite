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
              <li class="without-link">NEWS</li>
            </ul>
          </div>
        </div>
      </div>

      <div class="b-news-description">
        <div class="container">
          <div class="b-title a-left">
            <h1>News</h1>
          </div>
          <div class="b-description">
            <p>LCD screens are uniquely modern in style, and the liquid crystals that make them work have allowed humanity to create slimmer, more portable technology than we’ve ever had access to before. </p>
          </div>
        </div>
      </div>

      <div class="grey-bg">
        <div class="b-filters">
          <div class="container">
            <div class="b-form">
              <form>
                <div class="b-tag-filters all-filter-wrapper">
                  <div class="form-item form-type-checkbox">
                    <input checked id="all" class="form-checkbox check-all" type="checkbox" value="" name="all">
                    <label for="all">all</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="tag-number" class="form-checkbox" type="checkbox" value="" name="tag-number">
                    <label for="tag-number">TAG NUMBER 1</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="technical-data" class="form-checkbox" type="checkbox" value="" name="technical-data">
                    <label for="technical-data">TECHNICAL DATA</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="certificates" class="form-checkbox" type="checkbox" value="" name="certificates">
                    <label for="certificates">CERTIFICATES</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="brochures" class="form-checkbox" type="checkbox" value="" name="brochures">
                    <label for="brochures">BROCHURES</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="selector-guides" class="form-checkbox" type="checkbox" value="" name="selector-guides">
                    <label for="selector-guides">SELECTOR GUIDES</label>
                  </div>
                </div>
              </form>
            </div>
          </div>
        </div>

        <?php include "inc/blocks/block-list-recent-news.php"; ?>
      </div>

      <?php include "inc/blocks/block-list-news.php"; ?>

      <?php include "inc/blocks/block-newsletter.php"; ?>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>