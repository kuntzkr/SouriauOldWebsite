<?php
/**
 * @file
 * Template.
 */
?>
<footer class="main-footer">
  <div class="top-footer">
    <div class="container">
      <div class="col col-1">
        <iframe class="mj-w-res-iframe" frameborder="0" scrolling="no" marginheight="0" marginwidth="0" src="<?php print $_html['newsletter_widget_url']; ?>" width="100%"></iframe>
      </div>
      <div class="col col-2">
        <div class="b-col">
          <?php print $_html['contact_information']; ?>
        </div>
        <div class="b-col mobile-hide">
          <?php print $_html['footer_links']; ?>
        </div>
      </div>

      <div class="col col-3">
        <div class="b-social">
          <?php print $_html['social']; ?>
        </div>
        <div class="b-language">
          <?php print $_html['country']; ?>
        </div>
        <div class="b-parent-logo">
          <?php print $_html['parent_logo_img']; ?>
        </div>
      </div>
    </div>
  </div>
  <div class="bottom-footer">
    <div class="container">
      <div class="col a-right">
        <?php print $_html['footer_menu']; ?>
      </div>

      <div class="b-copyright">
        <?php print $_html['copyright']; ?>
      </div>
    </div>
  </div>
</footer>
