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
          <div class="breadcrumb">
            <ul>
              <li><a href="#">HOME</a></li>
              <li class="without-link">Order #424-362-2049-424-362</li>
            </ul>
          </div>
        </div>
      </div>

      <div class="b-order-detail">
        <div class="container">
          <h1>Order <span>#424-362-2049-424-362</span></h1>

          <div class="b-order-info">
            <div class="b-shipping a-left">
              <h2>Shipping Adress</h2>
              <div class="name">
                <p>FIRST NAME, LAST NAME</p>
              </div>
              <p>Adress 1</p>
              <p>Adress 2</p>
              <p>Zip code, City</p>
              <p>Country</p>
            </div>
            <div class="b-info a-right">
              <div class="b-row">
                <div class="title">Customer Number</div>
                <div class="description">424-362-2049-424-362</div>
              </div>
              <div class="b-row">
                <div class="title">Order number</div>
                <div class="description">424-362-2049-424-362</div>
              </div>
              <div class="b-row">
                <div class="title">AR</div>
                <div class="description">424-362-2049-424-362</div>
              </div>
              <div class="b-row">
                <div class="title">Order creation date</div>
                <div class="description">424-362-2049-424-362</div>
              </div>
              <div class="b-row">
                <div class="title">Order last update date</div>
                <div class="description">424-362-2049-424-362</div>
              </div>
            </div>
          </div>

          <?php include "inc/blocks/block-order-lines.php"; ?>

        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>