<div class="container">
  <div class="wrapper">

    <div class="b-item-resorce b-item-dyn" data-mh="resorce-group" style="min-height: auto">
      <a href="#"  data-toggle="modal" data-target="#informModal">
        <figure class="pic">
          <img class="tint" src="images/temp/did_you_know_1.jpg" alt="recource image">
        </figure>
      </a>
    </div>


    <div class="b-item-resorce b-item-dyn" data-mh="resorce-group" style="min-height: auto">
      <a href="#"  data-toggle="modal" data-target="#informModal">
      <figure class="pic">
        <img class="tint" src="images/temp/did_you_know_2.jpg" alt="recource image">
      </figure>
      </a>
    </div>

    <div class="b-item-resorce b-item-dyn" data-mh="resorce-group" style="min-height: auto">
      <a href  data-toggle="modal" data-target="#informModal">
      <figure class="pic tint">
        <img src="images/temp/did_you_know_1.jpg" alt="recource image">
      </figure>
      </a>
    </div>

    <div class="b-item-resorce b-item-dyn" data-mh="resorce-group" style="min-height: auto">
      <a href="#"  data-toggle="modal" data-target="#informModal">
      <figure class="pic">
        <img class="tint" src="images/temp/did_you_know_2.jpg" alt="recource image">
      </figure>
      </a>
    </div>

    <div class="b-item-resorce b-item-dyn" data-mh="resorce-group" style="min-height: auto">
      <a href="#"  data-toggle="modal" data-target="#informModal">
      <figure class="pic">
        <img class="tint" src="images/temp/did_you_know_1.jpg" alt="recource image">
      </figure>
      </a>
    </div>

    <div class="b-item-resorce b-item-dyn" data-mh="resorce-group" style="min-height: auto">
      <a href="#"  data-toggle="modal" data-target="#informModal">
      <figure class="pic">
        <img class="tint" src="images/temp/did_you_know_2.jpg" alt="recource image">
      </figure>
      </a>
    </div>
  </div>
</div>
<style>
  .b-item-dyn .pic:before {
    content: "";
    display: block;
    position: absolute;
    top: 0;
    bottom: 0;
    left: 0;
    right: 0;
    background: rgba(0,0,0, 0.5);
    -moz-transition: all .3s linear;
    -webkit-transition: all .3s linear;
    -ms-transition: all .3s linear;
    -o-transition: all .3s linear;
    transition: all .3s linear;
  }

  .b-item-dyn .pic:hover:before {
    background: none;
  }

  @media (max-width: 959px) {
     .b-item-dyn {
       padding: 0!important;
       width: 300px!important;
       display: inline-block!important;
       min-height: auto!important;
       margin: 0 16px 20px 0!important; } }
</style>
<!-- Modal -->
<div class="modal fade inform-popup b-popup" id="informModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
  <div class="vertical-alignment-helper">
    <div class="modal-dialog vertical-align-center" role="document">
      <div class="modal-body">

        <div class="modal-content" style="padding: 10px">
          <img src="images/temp/did_you_know_1.jpg" alt="recource image">

          <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit,
            sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam,
            quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. </p>
        </div>
      </div>
    </div>
  </div>
</div>
