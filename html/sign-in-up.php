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
      <div class="b-sign-in-up">
        <div class="container">
          <div class="b-two-columns">
            <div class="b-tabs-navigation" id="b-tabs-navigation">
              <a href="#" data-to-open="b-sign-in">Sign in</a>
              <a href="#" data-to-open="b-sign-up">Sign up</a>
            </div>
            <div class="align-container">
              <div class="col b-sign-in" data-open="b-sign-in">
                <!--<h1>Sign in</h1>-->
                <div class="b-form">
                  <form>
                    <div class="b-wrapper">
                      <h1>Sign in</h1>
                      <div class="form-item form-type-textfield full-field">
                        <label for="email">Email address</label>
                        <input id="email" class="form-text" type="text" value="jason.warner@gmail.com" name="email" />
                      </div>

                      <div class="form-item form-type-password full-field">
                        <label for="pass">PASSWORD</label>
                        <input id="pass" class="form-text" type="password" value="PASSWORD" name="pass" />
                      </div>

                      <div class="w-btn text-right">
                        <a href="#" class="link-forgot-pass">Forgotten password ?</a>
                      </div>
                    </div>

                    <div class="form-block form-actions text-center">
                      <div class="align-btn-center">
                        <button class="btn orange-btn-hover">CONNECT TO MY ACCOUNT</button>
                      </div>
                    </div>
                  </form>
                </div>
              </div>

              <div class="col b-sign-up" data-open="b-sign-up">
                <div class="b-wrapper">
                  <h1>Sign up</h1>
                  <div class="text">
                    <p>
                      Create an account to be able to order sample, create your own project, manage your training...
                    </p>
                  </div>
                </div>
                <div class="w-btn">
                  <a href="#" class="btn orange-btn-hover">CREATE AN ACCOUNT</a>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
    <?php include "inc/main-footer.php"; ?>
  </div>
</body>
</html>