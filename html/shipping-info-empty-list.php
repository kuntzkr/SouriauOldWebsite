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
                <div class="w-btn text-center b-create-new-address clearfix">
                  <div class="form-item form-type-radio">
                    <input id="s_address3" class="form-radio select-address-input" checked type="radio" value="3" name="s_address"/>
                    <label for="s_address3">Create a new address<a href="../../inc/blocks/block-new-address2.php" class="hide-btn active btn-addr-open"></a></label>
                  </div>
                </div>

                <div class="form-wrapper">
                  <div class="js-load-form-wrapper active onload-visible">
                    <div class="loader"></div>
                    <div class="js-load-form">
                      <?php include "inc/blocks/block-new-address2.php"; ?>
                    </div>
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