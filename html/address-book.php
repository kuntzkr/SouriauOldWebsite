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

      <div class="b-address-book">
        <div class="container">
          <h1>Address Book</h1>

          <div class="js-block_edit">
            <div class="b-list-address">
              <div class="b-row matchHeight">
                <div class="item-row b-address-item a-left">
                  <div class="b-info">
                    <p>
                      <strong>Name of the address</strong>
                    </p>
                    <p>Jason Werner</p>
                    <p>460 Jewess Motorway</p>
                    <p>460 Jewess Motorway</p>
                    <p>556777 Jillianborough</p>
                    <p>Sweden</p>
                    <p>814-611-7408</p>
                    <p>814-611-7408</p>
                  </div>
                  <div class="b-btns-edit">
                    <a href="" class="edit-link btn-addr-open">
                      <span class="ico ico-edit">
                        <!--[if gte IE 9]><!-->
                          <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
                        <!--<![endif]-->
                      </span>
                      <span class="screen-reader-text">Edit</span>
                    </a>

                    <a href="#" class="remove-link" data-toggle="modal" data-target="#removeModal">
                      <span class="ico ico-remove">
                        <!--[if gte IE 9]><!-->
                         <svg class="svg-ico"><use xlink:href="#ico-remove"></use></svg>
                        <!--<![endif]-->
                      </span>
                      <span class="screen-reader-text">Remove product from shopping cart</span>
                    </a>
                  </div>
                </div>

                <div class="item-row b-address-item a-right">
                  <div class="b-info">
                    <p>
                      <strong>Name of the address</strong>
                    </p>
                    <p>Jason Werner</p>
                    <p>460 Jewess Motorway</p>
                    <p>556777 Jillianborough</p>
                    <p>Sweden</p>
                    <p>814-611-7408</p>
                  </div>
                  <div class="b-btns-edit">
                    <a href="../../inc/blocks/block-edit-address.php" class="edit-link btn-addr-open">
                      <span class="ico ico-edit">
                        <!--[if gte IE 9]><!-->
                          <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
                        <!--<![endif]-->
                      </span>
                      <span class="screen-reader-text">Edit</span>
                    </a>

                    <a href="#" class="remove-link" data-toggle="modal" data-target="#removeModal">
                      <span class="ico ico-remove">
                        <!--[if gte IE 9]><!-->
                         <svg class="svg-ico"><use xlink:href="#ico-remove"></use></svg>
                        <!--<![endif]-->
                      </span>
                      <span class="screen-reader-text">Remove product from shopping cart</span>
                    </a>
                  </div>
                </div>
              </div>
            </div>

            <div class="w-btn text-center b-create-new-address clearfix">
              <a href="../../inc/blocks/block-new-address.php" class="hide-btn btn-addr-open active">+ Add an address</a>
            </div>

            <div class="form-wrapper">
              <div class="js-load-form-wrapper active onload-visible">
                <div class="loader"></div>
                <div class="js-load-form">
                  <?php include "inc/blocks/block-new-address.php"; ?>
                </div>
              </div>
            </div>
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