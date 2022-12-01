<?php
/**
 * @file
 * Search page block template.
 */
?>
<?php if (!empty($result_bar['keyword'])): ?>
<div class="b-result-bar hidden-xs">
  <div class="container">
    <h1><?php print $result_bar['total']; ?> results found for <?php $result_bar['keyword'] ?> </h1>
  </div>
</div>
<?php endif; ?>
<div class="b-result-view">
  <div class="b-tabs">
    <div class="container">
        <?php print render($tabs); ?>
    </div>
  </div>
    <div class="tab-content grey-bg">
      <?php foreach ($tabs['#tabs'] as $type => $tab) : ?>

        <?php $items = isset($results[$type]) ? $results[$type] : [] ?>

        <?php $html_id = $tabs['#tabs'][$type]['html_id'] ?>

        <div id="<?php print $html_id ?>" class="tab-pane  fade <?php if ($tabs['#tabs'][$type]['active']) {print 'active in';} ?> ">

          <?php if ($items) : ?>

            <div class="b-result-wrapper">
              <div class="container">
                <div class="b-view-params">
                  <?php if (isset($filters[$type])): ?>
                    <?php print render($filters[$type]); ?>
                  <?php endif; ?>
                  <div class="b-params">
                    <a class="list-sort link" data-sort="<?php if (isset($filter_forms[$type]['sort']['#value'])) {print $filter_forms[$type]['sort']['#value'];} ?>" href="#">
                        <span class="ico ico-arrow-down">
                          <!--[if gte IE 9]><!-->
                           <svg class="svg-ico"><use xlink:href="#ico-arrow-down"></use></svg>
                          <!--<![endif]-->
                        </span>
                      <span class="text">
                          <sup>A</sup>
                          <sub>Z</sub>
                        </span>
                    </a>

                    <div class="b-choose-view hidden-xs" data-list-view="<?php print $tabs['#tabs'][$type]['html_id']; ?>-results">
                      <a href="#" class="link-list-view active link" data-view="list-view">
                          <span class="ico ico-list">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-list"></use></svg>
                            <!--<![endif]-->
                          </span>

                        <span class="screen-reader-text">
                          <?php print t('Change to list view', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?>
                        </span>
                      </a>

                      <a href="#" class="link-table-view link" data-view="table-view">
                          <span class="ico ico-table">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-table"></use></svg>
                            <!--<![endif]-->
                          </span>

                        <span class="screen-reader-text"><?php print t('Change to list view', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?></span>
                      </a>
                    </div>
                  </div>
                </div>
                <?php if (isset($search_infos[$type])): ?>
                  <?php print render($search_infos[$type]); ?>
                <?php endif; ?>
                <div class="b-view-results list-view" id="<?php print $html_id ?>-results">
                  <?php print render($items); ?>
                </div>
                <?php if ($next_page[$type] > 0) : ?>
                    <div class="w-btn text-center">
                        <a class="view-more blue-btn" href="#">
                          <?php print t('LOAD MORE', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?>
                        </a>
                    </div>
                <?php endif ?>
              </div>
            </div>
          <?php elseif (!empty($filter_forms[$type]) && empty($filter_forms[$type]['keyword']['#value'])): ?>
            <div class="b-result-wrapper">
              <div class="container">
                <div class="b-view-params">
                  <?php if (isset($filters[$type])): ?>
                    <?php print render($filters[$type]); ?>
                  <?php endif; ?>
                  <div class="b-params hidden">
                    <a class="list-sort link" data-sort="<?php if (isset($filter_forms[$type]['sort']['#value'])) {print $filter_forms[$type]['sort']['#value'];} ?>" href="#">
                        <span class="ico ico-arrow-down">
                          <!--[if gte IE 9]><!-->
                           <svg class="svg-ico"><use xlink:href="#ico-arrow-down"></use></svg>
                          <!--<![endif]-->
                        </span>
                      <span class="text">
                          <sup>A</sup>
                          <sub>Z</sub>
                        </span>
                    </a>

                    <div class="b-choose-view hidden-xs" data-list-view="<?php print $tabs['#tabs'][$type]['html_id']; ?>-results">
                      <a href="#" class="link-list-view active link" data-view="list-view">
                          <span class="ico ico-list">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-list"></use></svg>
                            <!--<![endif]-->
                          </span>

                        <span class="screen-reader-text">
                          <?php print t('Change to list view', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?>
                        </span>
                      </a>

                      <a href="#" class="link-table-view link" data-view="table-view">
                          <span class="ico ico-table">
                            <!--[if gte IE 9]><!-->
                             <svg class="svg-ico"><use xlink:href="#ico-table"></use></svg>
                            <!--<![endif]-->
                          </span>

                        <span class="screen-reader-text"><?php print t('Change to list view', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?></span>
                      </a>
                    </div>
                  </div>
                </div>
                <?php if (isset($search_infos[$type])): ?>
                  <?php print render($search_infos[$type]); ?>
                <?php endif; ?>
                <div class="b-view-results list-view" id="<?php print $html_id ?>-results">
                </div>
                <?php if ($next_page[$type] > 0) : ?>
                    <div class="w-btn text-center">
                        <a class="view-more blue-btn" href="#">
                          <?php print t('LOAD MORE', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?>
                        </a>
                    </div>
                <?php endif ?>
              </div>
            </div>
          <?php endif ?>
        </div>


      <?php endforeach; ?>
    </div>
</div>

<div class="b-main-filter-area" id="b-filters" aria-hidden="true">
  <?php foreach ($filter_forms as $tab => $filter_form): ?>
    <?php print render($filter_form); ?>
  <?php endforeach; ?>
</div>

<div class="b-to-compare hidden-xs">
  <div class="b-to-fixed">
    <div class="container">
      <div class="align-center">
        <div class="text"><?php print $comparator_string; ?></div>
        <div class="w-btn">
          <a class="btn orange-btn-hover" href="<?php print url('compare-part-numbers'); ?>"><?php print t('GO TO COMPARATOR', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
        </div>
      </div>
    </div>
  </div>
</div>
