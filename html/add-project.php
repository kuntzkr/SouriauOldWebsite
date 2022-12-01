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
    <?php include "inc/main-header-with-empty-card.php"; ?>
    <div class="main-content">
      <div class="b-back-link">
        <div class="container">
          <a href="#" class="btn-back">
            <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
            BACK TO MY PROJECTS
          </a>
        </div>
      </div>

      <div class="b-projects">
        <div class="container">
          <div class="b-add-project">
            <div class="popup-title">
              <h2>Create a new project</h2>
            </div>
            <div class="b-form">
              <form>
                <div class="form-item form-type-textfield">
                  <label for="pr-name">Project name</label>
                  <input id="pr-name" class="form-text" type="text" value="" name="pr-name"/>
                </div>

                <div class="form-item form-type-textarea">
                  <label for="pr-description" >Project description</label>
                  <textarea id="pr-description" class="form-area" name="pr-description"></textarea>
                </div>

                <div class="form-block form-actions wide-btns">
                  <button class="btn blue-btn btn-cancel" aria-label="CANCEL" data-dismiss="modal">
                    CANCEL
                  </button>
                  <div class="w-btn-stretch">
                    <button class="btn orange-btn-hover">CONFIRM</button>
                  </div>
                </div>
              </form>
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