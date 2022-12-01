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
    <?php include "inc/main-header-search.php"; ?>
    <div class="main-content">
      <div class="b-result-view">
        <div class="b-tabs">
          <div class="container">
            <ul class="nav nav-tabs">
              <li><a data-toggle="tab" href="#all" aria-expanded="false">ALL RESULTS (33)</a></li>
              <li class="active"><a data-toggle="tab" aria-expanded="true" href="#part-number">PART NUMBERS (25)</a></li>
              <li><a data-toggle="tab" href="#range" aria-expanded="false">PRODUCTS RANGE (5)</a></li>
              <li><a data-toggle="tab" href="#application" aria-expanded="false">APPLICATIONS (3)</a></li>
              <li><a data-toggle="tab" href="#capabilities" aria-expanded="false">Capabilities (5)</a></li>
              <li><a data-toggle="tab" href="#news" aria-expanded="false">News (3)</a></li>
            </ul>
          </div>

          <div class="tab-content grey-bg">
            <div id="all" class="tab-pane fade">
              <div class="b-result-wrapper">
                <div class="container">
                  <div class="b-view-params">
                    <div class="b-params">
                      <a class="list-sort link" href="#">
                        <span class="ico ico-arrow-down">
                          <!--[if gte IE 9]><!-->
                           <svg class="svg-ico"><use xlink:href="#ico-arrow-down"></use></svg>
                          <!--<![endif]-->
                        </span>
                        <span class="text">
                          <sup>A</sup>
                          <sub>Z</sub>
                        </span>
                      </a>

                      <div class="b-choose-view hidden-xs" data-list-view="all-results">
                        <a href="#" class="link-list-view active link" data-view="list-view">
                          <span class="ico ico-list">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-list"></use></svg>
                            <!--<![endif]-->
                          </span>

                          <span class="screen-reader-text">Change to list view</span>
                        </a>

                        <a href="#" class="link-table-view link" data-view="table-view">
                          <span class="ico ico-table">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-table"></use></svg>
                            <!--<![endif]-->
                          </span>

                          <span class="screen-reader-text">Change to list view</span>
                        </a>
                      </div>
                    </div>
                  </div>
                  <div class="b-view-results list-view" id="all-results">
                    <div class="b-product-item">
                      <figure class="pic">
                        <a href="#"><img src="images/temp/product-img-12.jpg" alt="application image"></a>
                      </figure>
                      <div class="b-info">
                        <div class="b-product-info full-width">
                          <h3><a href="#">Head for shandles crimp tooling</a></h3>
                          <div class="b-add-info"><p>SOURIAU / <b>UTO SERIES</b></p></div>
                          <p>
                            Lorem ipsum dolor sit amet, consectetur adipiscing elit. Integer gravida nec est vitae posuere. Pellentesque at nisi elit. Sed sit amet maximus ante, at congue ipsum. Cras semper neque amet.
                          </p>
                        </div>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>

            <div id="part-number" class="tab-pane fade active in">
              <?php include "inc/blocks/block-part-number-tab.php"; ?>
            </div>

            <div id="range" class="tab-pane  fade">

            </div>

            <div id="application" class="tab-pane  fade">

            </div>

            <div id="capabilities" class="tab-pane  fade">

            </div>

            <div id="news" class="tab-pane  fade">

            </div>
          </div>
        </div>
      </div>

      <div class="b-to-compare hidden-xs">
        <div class="b-to-fixed">
          <div class="container">
            <div class="align-center">
              <div class="text">2 items added</div>
              <div class="w-btn">
                <a class="btn orange-btn-hover" href="#">GO TO COMPARATOR</a>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>

    <?php include "inc/blocks/block-main-filter-area.php"; ?>
  </div>

</body>
</html>