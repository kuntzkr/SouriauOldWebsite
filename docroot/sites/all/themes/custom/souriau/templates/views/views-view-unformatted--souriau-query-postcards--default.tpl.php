<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
    <?php print $row; ?>
<?php endforeach; ?>
<!-- Modal -->
<div class="modal fade inform-popup b-popup" id="informModal" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
  <div class="vertical-alignment-helper">
    <div class="modal-dialog vertical-align-center" role="document">
      <div class="modal-body">
        <div class="modal-content" style="padding: 10px">
          <a class="p_share" href="#"><img class="p_image" src="" alt="Postcard"></a>
          <p class="p_body"></p>
        </div>
      </div>
    </div>
  </div>
</div>
