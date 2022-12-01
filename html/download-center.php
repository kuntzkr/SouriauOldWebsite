<!DOCTYPE html>
<html lang="en" class="no-js">
<head>
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <?php include "inc/head.php"; ?>
  <link href="css/download-center.css" rel="stylesheet" type="text/css">

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
          <div class="main-title"><h1>Download center</h1>
          </div>
          <div class="clearfix"></div>
          <form class="customForms-processed">
            <div class="filter-col">
              <?php include "inc/blocks/block-filters.php"; ?>
            </div>
            <div class="result-col">
                <div class="form-item searchbox">
                  <input class="form-text autocomplete autocomplete-processed ui-autocomplete-input" placeholder="Enter Search Keywords" autocomplete="off" type="text">
                  <button class="btn link-view-all-results checkLinkvisible-processed" type="submit">
                    <span class="ico ico-search">
                      <!--[if gte IE 9]><!-->
                        <svg class="svg-ico"><use xlink:href="#ico-search"></use></svg>
                    <!--<![endif]-->
                    </span>
                  </button>
                </div>
                <div id="filter-nav-mobile" class="w-btn-filter a-left">
                  <a href="#" class="link-filter tree-filter">
                    <span class="ico ico-controls">
                      <!--[if gte IE 9]><!-->
                       <svg class="svg-ico"><use xlink:href="#ico-controls"></use></svg>
                      <!--<![endif]-->
                    </span>
                    CLICK HERE TO REFINE YOUR RESULTS
                  </a>
                </div>
                <div class="b-filters" id="documents-filter">
                  <div class="b-form">
                    <div class="b-type-filters">
                      <div class="form-item form-type-checkbox">
                        <input id="catalogues" class="form-checkbox" value="" name="catalogues" type="checkbox">
                        <label for="catalogues">Catalogs</label>
                      </div>

                      <div class="form-item form-type-checkbox">
                        <input id="datasheets" class="form-checkbox" value="" name="datasheets" type="checkbox">
                        <label for="datasheets">Datasheets</label>
                      </div>

                      <div class="form-item form-type-checkbox">
                        <input id="capabilities" class="form-checkbox" value="" name="capabilities" type="checkbox">
                        <label for="capabilities">Capabilities</label>
                      </div>

                      <div class="form-item form-type-checkbox">
                        <input id="selector-guides" class="form-checkbox" value="" name="selector-guides" type="checkbox">
                        <label for="selector-guides">Selector Guides</label>
                      </div>

                      <div class="form-item form-type-checkbox">
                        <input id="certificates" class="form-checkbox" value="" name="certificates" type="checkbox">
                        <label for="certificates">Certificates</label>
                      </div>
                    </div>
                  </div>
                  <div class="b-view-params">
                    <div class="b-params">
                      <div class="b-choose-view hidden-xs changeView-processed" data-list-view="part-number-results">
                        <a class="link-list-view link list-view" data-view="list-view">
                          <span class="ico ico-list">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-list"></use></svg>
                            <!--<![endif]-->
                          </span>

                          <span class="screen-reader-text">Change to list view</span>
                        </a>

                        <a class="link-table-view link table-view active" data-view="table-view">
                          <span class="ico ico-table">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-table"></use></svg>
                            <!--<![endif]-->
                          </span>

                          <span class="screen-reader-text">Change to table view</span>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>

            </div>
          </form>
          <div class="result-col">
            <?php include "inc/blocks/block-list-documents.php"; ?>
          </div>
        </div>
      </div>
    </div>
    <script src="js/hummingbird-treeview.js"></script>
    <script src="js/custom.js"></script>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>
