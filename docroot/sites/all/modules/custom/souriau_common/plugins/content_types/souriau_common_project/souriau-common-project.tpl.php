<?php

/**
 * @file
 * Template.
 */
?>

<div class="b-back-link">
  <div class="container">
    <a href="<?php print $_html['myprojects-link']; ?>" class="btn-back">
      <span class="glyphicon glyphicon-menu-left" aria-hidden="true"></span>
      <?php print t('Back to my projects', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
    </a>
  </div>
</div>

<div class="b-projects">
  <div class="container">
    <div class="b-project-description">
      <div class="b-editable">
        <div class="w-editable center-text">
          <h1 class="b-editable-area" data-empty-title="Please add title" id="prj-title-edit" data-prj-id="<?php print $_html['id']; ?>" data-prj-title="<?php print $_html['title']; ?>" data-ajax-url="<?php print $_html['data-ajax-url']; ?>" >
            <?php print $_html['title']; ?>
          </h1>
          <span class="ico ico-edit">
            <!--[if gte IE 9]><!-->
            <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
            <!--<![endif]-->
            <span class="screen-reader-text">
              <?php print t('Edit', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
            </span>
          </span>
        </div>
      </div>

      <div class="b-text">
        <div class="w-editable center-text">
          <div class="b-editable-area" id="prj-desc-edit" data-prj-id="<?php print $_html['id']; ?>" data-prj-title="<?php print $_html['description']; ?>" data-ajax-url="<?php print $_html['data-ajax-url']; ?>">
            <?php print $_html['description']; ?>
          </div>
          <span class="ico ico-edit">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
            <!--<![endif]-->

            <span class="screen-reader-text">
              <?php print t('Edit', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
            </span>
          </span>
        </div>
      </div>
    </div>
    <div class="w-btn text-right hidden-xs">
      <a href="<?php print $_html['csv-link']; ?>" class="link-export">
        <span class="ico ico-export">
          <!--[if gte IE 9]><!-->
            <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-export"></use></svg>
          <!--<![endif]-->
        </span>
        <?php print t('Export to csv', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
      </a>
    </div>

    <div class="b-list-projects">
      <?php foreach ($_html['lineitems'] as $part_number): ?>
      <div class="item">
        <figure class="pic">
          <a href="<?php print $part_number['url'];?>">
            <?php if (!empty($part_number['part-number']['sku-image'])) : ?>
            <img src="<?php print $part_number['part-number']['sku-image']['url']; ?>" alt="<?php print $part_number['part-number']['sku-image']['alt']; ?>"/>
            <?php endif; ?>
          </a>
        </figure>
        <div class="w-info">
          <a href="<?php print $part_number['item-delete-link']['url']; ?>" class="<?php print $part_number['item-delete-link']['classes']; ?>">
        <span class="ico ico-remove">
          <!--[if gte IE 9]><!-->
           <svg class="svg-ico"><use xlink:href="#ico-remove"></use></svg>
          <!--<![endif]-->
        </span>
            <span class="screen-reader-text">
              <?php print t('Remove product from shopping cart', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
            </span>
          </a>

          <div class="b-main-info">
            <div class="b-title">
              <a href="<?php print $part_number['url'];?>"><?php print $part_number['part-number']['title']; ?></a>
            </div>
            <div class="b-part-numb">
              <p><?php print $part_number['part-number']['sku']; ?></p>
            </div>
            <div class="b-add-info">
              <p>
                <?php print $part_number['part-number']['sku-brand']; ?> /
                <?php print $part_number['part-number']['sku-series']; ?>
              </p>
            </div>
            <div class="b-short-descr">
              <p><?php print $part_number['part-number']['description']; ?></p>
            </div>
            <div class="w-btn hidden-lg">
              <a href="#" class="link-search-small">
                <span class="ico ico-search">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-search"></use></svg>
                  <!--<![endif]-->
                </span>
                <?php print t('See product range in catalog', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
              </a>
            </div>
          </div>

          <div class="b-add-info">
            <div class="w-btn visible-lg-block">
              <a href="#" class="link-search-small">
                <span class="ico ico-search">
                  <!--[if gte IE 9]><!-->
                    <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-search"></use></svg>
                  <!--<![endif]-->
                </span>
                <?php print t('See product range in catalog', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
              </a>
            </div>

            <div class="b-notes">
              <div class="b-notes-title">
                <?php print t('NOTES', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
              </div>
              <div class="w-editable">
                <p class="b-editable-area prj-partno-notes" id="<?php print 'prj_partno_' . $part_number['partno']; ?>" data-prj-id="<?php print $_html['id']; ?>" data-part-id="<?php print $part_number['partno']; ?>" data-prj-title="<?php print $part_number['notes']; ?>" data-ajax-url="<?php print $_html['data-ajax-url']; ?>">
                  <?php print $part_number['notes']; ?>
                </p>
                <span class="ico ico-edit">
                  <!--[if gte IE 9]><!-->
                  <svg class="svg-ico"><use xlink:href="#ico-edit"></use></svg>
                  <!--<![endif]-->
                  <span class="screen-reader-text">
                    <?php print t('Edit', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
                  </span>
                </span>
              </div>
            </div>
          </div>
        </div>
      </div>
      <?php endforeach; ?>
    </div>
  </div>

  <div class="w-btn text-center">
    <?php print $_html['delete-link']; ?>
  </div>
</div>
