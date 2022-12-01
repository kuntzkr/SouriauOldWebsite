<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-info">
  <?php print $_data['image']; ?>
  <div class="b-product-info full-width">
    <h4>
      <span class="ico <?php print $_data['file_mimetype_class']; ?>" style="width: 20px;height: 20px;float: left;">
        <!--[if gte IE 9]><!-->
          <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-pdf"></use></svg>
        <!--<![endif]-->
      </span>
      <label class="table-view-label document-type" for="<?php print (empty($_data['file_type'])) ? 'document' : strtolower($_data['file_type']); ?>">
        <?php print (empty($_data['file_type'])) ? 'Document' : $_data['file_type']; ?>
      </label>
      <a href="<?php print $_data['file_url']; ?>" data-gtm-category="Download" data-gtm-action="Document" data-gtm-label="<?php print $_data['file_title']; ?>" target="_blank">
        <span class="list-view-label"><?php print $_data['file_title']; ?></span>
        <span class="table-view-label"><?php print (drupal_strlen($_data['file_title']) > 35) ? drupal_substr($_data['file_title'], 0, 35) . '...' : $_data['file_title']; ?></span>
      </a>
    </h4>
    <label class="list-view-label document-type" for="<?php print (empty($_data['file_type'])) ? 'document' : strtolower($_data['file_type']); ?>">
      <?php print (empty($_data['file_type'])) ? 'Document' : $_data['file_type']; ?>
    </label>
  </div>
</div>
