<div class="modal fade projects-popup b-popup" id="projectModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
  <div class="vertical-alignment-helper">
    <div class="modal-dialog vertical-align-center" role="document">
      <div class="modal-body">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close">
          <span class="ico ico-close">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico" ><use xlink:href="#ico-close"></use></svg>
            <!--<![endif]-->
          </span>
          <span class="screen-reader-text">Close popup</span>
        </button>
        <div class="modal-content">
          <div class="popup-title">
            <h2 id="myModalLabel">Create a new project</h2>
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
</div>