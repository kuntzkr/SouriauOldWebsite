<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-toolkit-description">
  <div class="container">
    <div class="b-title a-left">
      <h1><?php print $_data['title']; ?></h1>
    </div>
    <div class="b-description">
      <?php print $_data['description']; ?>
    </div>
  </div>
</div>
<?php if(isset($form)): ?>
<div class="b-tool-feature">
  <div class="container">
    <?php print render($form); ?>
  </div>
</div>
<?php endif; ?>
<div class="grey-bg with-border">
  <div class="b-results">
    <div class="container">
      <div id="tools-form-result"></div>
      <div class="b-legal-text">
        <div class="wrapper">
          <?php print $_data['legal_information']; ?>
        </div>
      </div>
    </div>
  </div>
</div>
