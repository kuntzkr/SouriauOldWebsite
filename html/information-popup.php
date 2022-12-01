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
          <form>
            <div class="b-form">
              <table>
                <thead>
                  <tr>
                    <th>
                      <div class="b-item-info">ADDED ITEMS</div>
                      <div class="b-part-numb">PART NUMBER</div>
                      <div class="b-qty">QUANTITY</div>
                    </th>
                  </tr>
                </thead>
                <tbody>
                  <tr>
                    <td>
                      <div class="b-item-info">
                        <figure class="pic">
                          <a href="#"><img src="images/temp/product-img-1.png" alt="application image" /></a>
                        </figure>
                        <a href="#" class="remove-link" data-toggle="modal" data-target="#removeModal">
                          <span class="ico ico-remove">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-remove"></use></svg>
                            <!--<![endif]-->
                          </span>
                          <span class="screen-reader-text">Remove product from shopping cart</span>
                        </a>
                        <div class="b-info">
                          <div class="b-title">
                            <a href="#">DHL Series with a long name</a>
                          </div>
                          <p>Product range</p>
                        </div>
                      </div>

                      <div class="b-part-numb"><p>UST53667788</p></div>
                      <div class="b-qty">
                        <div class="form-item form-type-number">
                          <input class="jcf-real-element" value="1" min="0" max="20" step="1" type="number">
                        </div>
                      </div>
                    </td>
                  </tr>
                  <tr>
                    <td>
                      <div class="b-item-info">
                        <figure class="pic">
                          <a href="#"><img src="images/temp/product-img-1.png" alt="application image" /></a>
                        </figure>
                        <a href="#" class="remove-link" data-toggle="modal" data-target="#removeModal">
                          <span class="ico ico-remove">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-remove"></use></svg>
                            <!--<![endif]-->
                          </span>
                          <span class="screen-reader-text">Remove product from shopping cart</span>
                        </a>
                        <div class="b-info">
                          <div class="b-title">
                            <a href="#">DHL Series with a long name</a>
                          </div>
                          <p>Product range</p>
                        </div>
                      </div>

                      <div class="b-part-numb"><p>UST53667788</p></div>
                      <div class="b-qty">
                        <div class="form-item form-type-number">
                          <input class="jcf-real-element" value="1" min="0" max="20" step="1" type="number">
                        </div>
                      </div>
                    </td>
                  </tr>
                  <tr>
                    <td>
                      <div class="b-item-info">
                        <figure class="pic">
                          <a href="#"><img src="images/temp/product-img-1.png" alt="application image" /></a>
                        </figure>
                        <a href="#" class="remove-link" data-toggle="modal" data-target="#removeModal">
                          <span class="ico ico-remove">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-remove"></use></svg>
                            <!--<![endif]-->
                          </span>
                          <span class="screen-reader-text">Remove product from shopping cart</span>
                        </a>
                        <div class="b-info">
                          <div class="b-title">
                            <a href="#">DHL Series with a long name</a>
                          </div>
                          <p>Product range</p>
                        </div>
                      </div>

                      <div class="b-part-numb"><p>UST53667788</p></div>
                      <div class="b-qty">
                        <div class="form-item form-type-number">
                          <input class="jcf-real-element" value="1" min="0" max="20" step="1" type="number">
                        </div>
                      </div>
                    </td>
                  </tr>
                </tbody>
              </table>

              <div class="form-block form-actions text-right">
                <button class="btn orange-btn-hover">PROCEED TO CHECKOUT</button>
              </div>
            </div>
          </form>
        </div>
      </div>

    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>

  <a href="#" class="hide autoload" data-toggle="modal" data-target="#informModal"></a>

  <!-- Modal -->
  <?php include "inc/blocks/block-inform-popup.php"; ?>
</body>
</html>