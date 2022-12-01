<?php
/**
 * @file
 * Template.
 */
?>
<div class="filter-col">
  <div class="form-item searchbox">
    <?php print drupal_render($form['dc_keyword']); ?>
    <?php print drupal_render($form['dc_keyword_button']); ?>
  </div>
  <div id="treeview_container" class="hummingbird-treeview well h-scroll-large b-top-filters">
    <div class="filter-close hidden">
      <a class="close-link" aria-label="Close" href="#">
        <span class="ico ico-close">
          <!--[if gte IE 9]><!-->
            <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-close"></use></svg>
          <!--<![endif]-->
        </span>
        <span class="screen-reader-text">remove</span>
      </a>
    </div>
    <ul id="treeview" class="hummingbird-base">
      <li class="parent"><i class="fa fa-plus"></i>
        <label><input id="node-0" data-id="custom-0" type="checkbox"> <?php print t('Application', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></label>
        <ul>
          <?php print drupal_render($form['filters']['application']); ?>
        </ul>
      </li>
      <li class="parent"><i class="fa fa-plus"></i>
        <label><input id="node-1" data-id="custom-1" type="checkbox"> <?php print t('Products', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></label>
          <?php foreach ($form['filters']['range'] as $parent_name => $range_filters): ?>
            <?php if (substr($parent_name, 0, 1) !== '#'): ?>
              <ul><li class="sub-parent main-connectors">
                <i class="fa fa-plus"><label><?php print $parent_name; ?></label></i>
                <ul>
                  <?php print drupal_render($range_filters['range']); ?>
                </ul>
              </li></ul>
            <?php endif; ?>
          <?php endforeach ?>
      </li>
    </ul>
  </div>
  <p>
      <a href="<?php print url('souriau/ajax/download_center/clear'); ?>" data-block-clear="documents-filter" class="btn blue-btn clear-filter use-ajax">
        <?php print t('Reset Filters', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
      </a>
  </p>
  <p>
      <a target="_blank" href="https://ipaper.ipapercms.dk/SOURIAU/resources-available/" class="btn blue-btn document-index">
        <?php print t('Document Index', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
      </a>
  </p>
</div>
<div class="result-col">
  <div id="filter-nav-mobile" class="w-btn-filter a-left">
    <a href="#" class="link-filter tree-filter">
      <span class="ico ico-controls">
        <!--[if gte IE 9]><!-->
         <svg class="svg-ico"><use xlink:href="#ico-controls"></use></svg>
        <!--<![endif]-->
      </span>
      <?php print t('CLICK HERE TO REFINE YOUR RESULTS', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
    </a>
  </div>


  <div class="b-filters" id="documents-filter">
    <div class="b-form labelBehavior-processed">
      <div class="b-type-filters">
        <?php print drupal_render($form['types']); ?>
      </div>
    </div>
    <span class="b-cnt-result">
      <?php print drupal_render($form['results']); ?>
    </span>
    <div class="b-view-params">
      <div class="b-params">
        <div class="b-choose-view hidden-xs changeView-processed" data-list-view="part-number-results">
          <a class="link-list-view link list-view active" data-view="list-view">
            <span class="ico ico-list">
              <!--[if gte IE 9]><!-->
               <svg class="svg-ico"><use xlink:href="#ico-list"></use></svg>
              <!--<![endif]-->
            </span>

            <span class="screen-reader-text">Change to list view</span>
          </a>
          <a class="link-table-view link table-view" data-view="table-view">
            <span class="ico ico-table">
              <!--[if gte IE 9]><!-->
               <svg class="svg-ico"><use xlink:href="#ico-table"></use></svg>
              <!--<![endif]-->
            </span>

            <span class="screen-reader-text">Change to table view</span>
          </a>
        </div>
      </div>
    </div>
  </div>
</div>
<div class="hidden">
<?php print drupal_render_children($form); ?>
</div>
