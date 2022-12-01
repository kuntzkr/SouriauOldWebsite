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
            <li class="active">CART</li>
            <li>SHIPPING INFORMATION</li>
            <li>CONFIRMATION</li>
          </ul>
        </div>
      </div>

      <div class="b-summary-cart">
        <div class="container">
          <div class="b-empty-card">
            <p>
              Your cart is empty.
            </p>
            <div class="w-btn">
              <a href="#" class="link-more">
                <span class="glyphicon glyphicon-menu-right" aria-hidden="true"></span>BROWSE CATALOG
              </a>
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