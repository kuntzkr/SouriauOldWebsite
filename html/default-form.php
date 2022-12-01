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
              <li><a href="#">PRODUCTS</a></li>
              <li class="without-link">CONDUITS</li>
            </ul>
          </div>
        </div>
      </div>

      <div class="container">
        <div class="form-wrapper">
          <h1>Default form styles</h1>
          <div class="b-form">
            <form>
              <fieldset>
                <legend>Section 1:</legend>
                <div class="form-item form-type-textfield error">
                  <label for="name1">Field 1</label>
                  <input id="name1" class="form-text" type="text" value="" name="name1" />
                  <div class="error-msg">This field is not valid</div>
                </div>

                <div class="form-item form-type-textfield">
                  <label for="name2">Field 2</label>
                  <input id="name2" class="form-text" type="text" value="" name="name2" />
                </div>

                <div class="form-item form-type-textfield">
                  <label for="name3">Field 3</label>
                  <input id="name3" class="form-text" type="text" value="" name="name3" />
                </div>

                <div class="form-item form-type-select">
                  <label for="field13">Field 13</label>
                  <select id="field13" aria-multiselectable="false" class="default">
                    <option>Option 1</option>
                    <option>Option 2</option>
                    <option>Option 1</option>
                    <option>Option 1</option>
                    <option>Option 1</option>
                    <option>Option 1</option>
                  </select>
                </div>
              </fieldset>

              <fieldset>
                <legend>Section 2:</legend>

                <div class="form-item form-type-textfield">
                  <label for="name31">Field 4</label>
                  <input id="name31" class="form-text" type="text" value="" name="name31" />
                </div>

                <div class="form-item form-type-textarea">
                  <label for="description">Description</label>
                  <textarea id="description" class="form-area" name="description"></textarea>
                </div>

                <div class="form-item form-type-checkbox">
                  <input id="name5" class="form-checkbox" type="checkbox" value="" name="name5" />
                  <label for="name5">Receive SMS 2</label>
                </div>
                <div class="form-item form-type-checkbox error">
                  <input id="name4" class="form-checkbox" type="checkbox" value="" name="name4" />
                  <label for="name4">Receive SMS 1</label>
                  <div class="error-msg">This field is not valid</div>
                </div>

                <div class="form-item form-type-radio">
                  <input id="name41" class="form-radio" type="radio" value="" name="name41" />
                  <label for="name41">description</label>
                </div>
                <div class="form-item form-type-radio error">
                  <input id="name52" class="form-radio" type="radio" value="" name="name41" />
                  <label for="name52">description</label>
                  <div class="error-msg">This field is not valid</div>
                </div>

                <div class="inline-checkboxes">
                  <div class="form-item form-type-checkbox error">
                    <input id="name6" class="form-checkbox" type="checkbox" value="" name="name6" />
                    <label for="name6">Receive SMS 3</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="name7" class="form-checkbox" type="checkbox" value="" name="name7" />
                    <label for="name7">Receive SMS 4</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="name8" class="form-checkbox" type="checkbox" value="" name="name8" />
                    <label for="name8">Receive SMS 5</label>
                  </div>
                  <div class="form-item form-type-checkbox">
                    <input id="name9" class="form-checkbox" type="checkbox" value="" name="name9" />
                    <label for="name9">Receive SMS 6</label>
                  </div>
                  <div class="error-msg">This field is not valid</div>
                </div>

                <div class="inline-radios">
                  <div class="form-item form-type-radio error">
                    <input id="name100" class="form-radio" type="radio" value="" name="name100" />
                    <label for="name100">description</label>
                  </div>
                  <div class="form-item form-type-radio">
                    <input id="name101" class="form-radio" type="radio" value="" name="name100" />
                    <label for="name101">description</label>
                  </div>
                  <div class="form-item form-type-radio">
                    <input id="name102" class="form-radio" type="radio" value="" name="name100" />
                    <label for="name102">description</label>
                  </div>
                  <div class="form-item form-type-radio">
                    <input id="name103" class="form-radio" type="radio" value="" name="name100" />
                    <label for="name103">description</label>
                  </div>
                  <div class="error-msg">This field is not valid</div>
                </div>
              </fieldset>

              <div class="form-block form-actions text-center">
                <div class="align-btn-center">
                  <button class="btn orange-btn-hover a-right">CONFIRM</button>
                  <button class="btn blue-btn">
                    CANCEL
                  </button>
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