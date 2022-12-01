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
      <div class="b-edit-account">
        <div class="container">
          <div class="form-wrapper">
            <h1>Edit my account</h1>
            <div class="b-form">
              <form>
                <fieldset>
                  <legend>LOGIN AND PASSWORD:</legend>
                  <div class="form-item form-type-textfield full-field">
                    <label for="email">Email address</label>
                    <input id="email" disabled class="form-text" type="text" value="jason.warner@gmail.com" name="email" />
                  </div>

                  <div class="form-item form-type-password full-field">
                    <label for="password">Password</label>
                    <input id="password" class="form-text" type="password" value="password" name="password" />
                  </div>

                  <div class="form-item form-type-password full-field">
                    <label for="password2">Confirm password</label>
                    <input id="password2" class="form-text" type="password" value="password" name="password2" />
                  </div>
                </fieldset>
                <fieldset>
                  <legend>YOUR INFOS:</legend>
                  <div class="form-item form-type-textfield full-field">
                    <label for="name">First name</label>
                    <input id="name" class="form-text" type="text" value="Jason Alexander" name="name" />
                  </div>

                  <div class="form-item form-type-textfield full-field">
                    <label for="name2">Last name</label>
                    <input id="name2" class="form-text" type="text" value="Warner" name="name2" />
                  </div>

                  <div class="form-item form-type-textfield full-field">
                    <label for="company">Company</label>
                    <input id="company" class="form-text" type="text" value="Bell Corporate" name="company" />
                  </div>

                  <div class="form-item form-type-textfield full-field">
                    <label for="pos">Job position</label>
                    <input id="pos" class="form-text" type="text" value="Marketing Manager / Sales Director" name="pos" />
                  </div>

                  <div class="form-item form-type-textfield full-field">
                    <label for="m-phone">Mobile phone</label>
                    <input id="m-phone" class="form-text" type="text" value="601-466-5662" name="m-phone" />
                  </div>

                  <div class="form-item form-type-textfield full-field">
                    <label for="phone">Phone</label>
                    <input id="phone" class="form-text" type="text" value="896-676-1520" name="phone" />
                  </div>
                </fieldset>
                <div class="form-item form-type-checkbox">
                  <input id="sms" checked class="form-checkbox" type="checkbox" value="" name="sms" />
                  <label for="sms">Receive SMS notifications</label>
                </div>

                <div class="form-block form-actions text-center">
                  <div class="align-btn-center">
                    <button class="btn blue-btn">
                      UPDATE INFOS
                    </button>
                  </div>
                </div>
              </form>
            </div>
          </div>

          <div class="b-settings">
            <div class="col b-newsl-settings">
              <div class="b-form">
                <h2>Newsletter thematics</h2>
                <form>
                  <div class="form-item form-type-checkbox">
                    <input id="thematic1" class="form-checkbox" type="checkbox" value="thematic1" name="thematic1" />
                    <label for="thematic1">Thematics 1</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="thematic2" class="form-checkbox" type="checkbox" value="thematic2" name="thematic2" />
                    <label for="thematic2">Thematics 2</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="thematic3" class="form-checkbox" type="checkbox" value="thematic3" name="thematic3" />
                    <label for="thematic3">Thematics 3</label>
                  </div>

                  <div class="form-block form-actions text-center">
                    <div class="align-btn-center">
                      <button class="btn blue-btn">
                        SUBSCRIBE THEMATICS
                      </button>
                      <div class="w-btn">
                        <a href="#" class="unsubscribe-link">UNSUBSCRIBE</a>
                      </div>
                    </div>
                  </div>
                </form>
              </div>
            </div>

            <div class="col b-resricted">
              <div class="b-form">
              <h2>Restricted access</h2>
                <form>
                  <p>Request an access to the order history:</p>
                  <div class="form-item form-type-textfield">
                    <label for="c-id">ECT customer ID</label>
                    <input id="c-id" class="form-text" type="text" value="" name="c-id" />
                  </div>
                  <div class="form-block form-actions text-center">
                    <div class="align-btn-center">
                      <button class="btn blue-btn">
                        SEND REQUEST
                      </button>
                    </div>
                  </div>
                </form>
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