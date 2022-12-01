<div class="b-tabs grey-bg">
  <div class="container">
    <ul class="nav nav-tabs">
      <li><a data-toggle="tab" href="#all" aria-expanded="false">ALL</a></li>
      <li class="active"><a data-toggle="tab" aria-expanded="true" href="#shapes">BY SHAPES (2)</a></li>
      <li><a data-toggle="tab" href="#standarts" aria-expanded="false">BY STANDARDS (2)</a></li>
      <li><a data-toggle="tab" href="#CAPABILITIES" aria-expanded="false">BY CAPABILITIES (2)</a></li>
    </ul>
  </div>
  <div class="tab-content">
    <div id="all" class="tab-pane  fade">
      <?php include "inc/blocks/block-sub-categories.php"; ?>
    </div>

    <div id="shapes" class="tab-pane fade active in">
      <div class="container">
        <section class="b-sub-categories">
          <div class="items">
            <a class="item" href="#">
              <div class="b-pic">
                <figure class="pic">
                  <img src="images/temp/sub-cat-7.png" alt="sub category image" />
                </figure>
              </div>

              <div class="text">
                <div class="title"><h5>Miniature Backshell 7</h5></div>
                <div class="view-more">VIEW MORE</div>
              </div>
            </a>

            <a class="item" href="#">
              <div class="b-pic">
                <figure class="pic">
                  <img src="images/temp/sub-cat-2.png" alt="sub category image" />
                </figure>
              </div>

              <div class="text">
                <div class="title"><h5>Miniature Backshell 2</h5></div>
                <div class="view-more">VIEW MORE</div>
              </div>
            </a>
          </div>
        </section>
      </div>
    </div>

    <div id="standarts" class="tab-pane fade ">
      <?php include "inc/blocks/block-sub-categories.php"; ?>
    </div>

    <div id="CAPABILITIES" class="tab-pane fade ">
      <?php include "inc/blocks/block-sub-categories.php"; ?>
    </div>
  </div>
</div>