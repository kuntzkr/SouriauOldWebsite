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

      <div class="b-steps">
        <div class="container">
          <ul>
            <li>CART</li>
            <li class="active">SHIPPING INFORMATION</li>
            <li>CONFIRMATION</li>
          </ul>
        </div>
      </div>

      <div class="b-shipping-info">
        <div class="container">
          <h1>Shipping information</h1>

          <div class="b-form">
            <form>
              <div class="js-block_edit" id="select-address-block">
                <div class="b-list-address">
                  <div class="b-title">
                    CHOOSE AN ADDRESS:
                  </div>
                  <div class="b-row matchHeight">
                    <div class="item-row b-address-item a-left">
                      <div class="b-check">
                        <div class="form-item form-type-radio">
                          <input id="s_address1" class="form-radio select-address-input" type="radio" value="1" name="s_address"/>
                          <label for="s_address1"><span class="screen-reader-text">select address</span></label>
                        </div>
                      </div>
                      <div class="b-info">
                        <p>
                          <strong>Name of the address</strong>
                        </p>
                        <p>Jason Werner</p>
                        <p>460 Jewess Motorway</p>
                        <p>556777 Jillianborough</p>
                        <p>Sweden</p>
                        <p>814-611-7408</p>
                        <p>814-611-7408</p>
                      </div>
                      <div class="b-btns-edit">
                        <a href="../../inc/blocks/block-edit-address2.php" class="edit-link btn-addr-open">
                          <span class="ico ico-edit">
                            <!--[if gte IE 9]><!-->
                              <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
                            <!--<![endif]-->
                          </span>
                          <span class="screen-reader-text">Edit</span>
                        </a>
                      </div>
                    </div>

                    <div class="item-row b-address-item a-right">
                      <div class="b-check">
                        <div class="form-item form-type-radio">
                          <input id="s_address2" class="form-radio select-address-input" type="radio" value="2" name="s_address"/>
                          <label for="s_address2"><span class="screen-reader-text">select address</span></label>
                        </div>
                      </div>
                      <div class="b-info">
                        <p>
                          <strong>Name of the address</strong>
                        </p>
                        <p>Jason Werner</p>
                        <p>460 Jewess Motorway</p>
                        <p>460 Jewess Motorway2</p>
                        <p>556777 Jillianborough</p>
                        <p>Sweden</p>
                        <p>814-611-7408</p>
                        <p>814-611-7408</p>
                      </div>
                      <div class="b-btns-edit">
                        <a href="../../inc/blocks/block-edit-address2.php" class="edit-link btn-addr-open">
                          <span class="ico ico-edit">
                            <!--[if gte IE 9]><!-->
                              <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
                            <!--<![endif]-->
                          </span>
                          <span class="screen-reader-text">Edit</span>
                        </a>
                      </div>
                    </div>
                  </div>
                </div>

                <div class="w-btn text-center b-create-new-address clearfix">
                  <div class="form-item form-type-radio">
                    <input id="s_address3" class="form-radio select-address-input" type="radio" value="3" name="s_address"/>
                    <label for="s_address3">Or create a new address<a href="../../inc/blocks/block-new-address2.php" class="hide-btn btn-addr-open"></a></label>
                  </div>
                </div>

                <div class="form-wrapper">
                  <div class="js-load-form-wrapper">
                    <div class="loader"></div>
                    <div class="js-load-form"></div>
                  </div>

                  <div class="w-row-btns">
                    <div class="form-block form-actions text-center">
                      <div class="align-btn-center">
                        <a href="#" class="btn blue-btn">BACK TO CART</a>
                        <button class="btn orange-btn-hover a-right">CONFIRM ORDER</button>
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </form>
          </div>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>