<div class="modal fade poll-popup b-popup" id="pollModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
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
            <h2 id="myModalLabel">What do you think about our new design?</h2>
          </div>
          <div class="b-form">
            <form>
              <fieldset class="text-center">
                <legend>Choose your anwser and see the results of the survey.</legend>
                <div class="form-item form-radios">
                  <div class="form-item form-type-radio">
                    <input id="name41" class="form-radio" type="radio" value="" name="name41">
                    <label for="name41">It’s the best !</label>
                  </div>
                  <div class="form-item form-type-radio">
                    <input id="name42" class="form-radio" type="radio" value="" name="name41">
                    <label for="name42">I’m neutral.</label>
                  </div>
                  <div class="form-item form-type-radio">
                    <input id="name43" class="form-radio" type="radio" value="" name="name41">
                    <label for="name43">I don’t like it…</label>
                  </div>
                </div>
              </fieldset>

              <div class="form-block form-actions text-center">
                <a href="#" data-toggle="modal" data-child-target="#pollModalResult" class="btn orange-btn-hover">VOTE</a>
              </div>
            </form>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>