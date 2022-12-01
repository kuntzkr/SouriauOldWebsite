<?php
/**
 * @file
 * Template.
 */
?>
<div class="b-resorce-content">
    <div class="container">
      <?php if (!empty($_html['resource']['video']) || !empty($_html['resource']['image'])): ?>
        <div class="b-visual-content">
            <?php if (!empty($_html['resource']['video'])): ?>
              <div class="b-video">
                <iframe width="1280" height="720" src="https://www.youtube.com/embed/<?php print $_html['resource']['video']['video_id']; ?>" frameborder="0" allowfullscreen=""></iframe>
              </div>
            <?php else: ?>
              <?php print $_html['resource']['image']; ?>
            <?php endif ?>
        </div>
      <?php endif ?>
      <div class="b-resorce-info">
        <div class="w-tags">
          <?php foreach ($_html['resource']['tags'] as $tag): ?>
            <div class="b-tag">
              <span class="ico ico-tag">
                <!--[if gte IE 9]><!-->
                  <svg class="svg-ico"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="#ico-tag"></use></svg>
                <!--<![endif]-->
              </span>
              <?php print $tag; ?>
            </div>
          <?php endforeach ?>
        </div>

        <h1><?php print $_html['resource']['title']; ?></h1>
        <div class="b-main-info">
          <div class="b-course"><?php print $_html['resource']['resource_type']; ?></div>
          <div class="publicate-date"><?php print $_html['resource']['date']; ?></div>
          <?php if (!user_is_anonymous()): ?>
            <?php print flag_create_link('favourate_resource', $_html['resource']['nid'], ['is_landing' => FALSE]); ?>
          <?php endif ?>
        </div>

        <div class="wysiwyg">
          <?php print $_html['resource']['body']; ?>
        </div>
      </div>
    </div>
</div>

<?php if (!empty($_html['registration_form'])): ?>
  <div class="b-register-course">
    <h2><?php print t('Register to this course', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
    <?php print drupal_render($_html['registration_form']); ?>
  </div>
<?php endif ?>

<?php if (!empty($_html['related_resources'])): ?>
  <div class="b-list-resources">
    <div class="container">
      <h2><?php print t('Related content', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
      <div class="wrapper">
        <?php foreach ($_html['related_resources'] as $related_resource): ?>
          <div class="b-item-resorce" data-mh="resorce-group">
            <div class="b-top">
              <?php if (!empty($related_resource['image'])): ?>
                <?php print $related_resource['image']; ?>
                <?php if (user_is_anonymous() && $related_resource['is_private']): ?>
                  <div class="b-no-permision">
                    <span><?php print t('CONNECT TO SEE THE CONTENT', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></span>
                  </div>
                <?php endif ?>
              <?php endif ?>
              <div class="b-links">
                <?php print flag_create_link('favourate_resource', $related_resource['nid'], ['is_landing' => TRUE]); ?>
              </div>
            </div>
            <div class="b-content">
              <div class="info">
                <span class="title"><?php print $related_resource['resource_type']; ?></span> <?php print $related_resource['date']; ?>
              </div>
              <div class="w-tags list-tags">
                <?php foreach ($related_resource['tags'] as $key => $category): ?>
                  <div class="b-tag<?php print ($key) ? ' hide-tag' : ''; ?>">
                    <span class="ico ico-tag">
                      <!--[if gte IE 9]><!-->
                        <svg class="svg-ico"><use xlink:href="#ico-tag" xmlns:xlink="http://www.w3.org/1999/xlink"/></svg>
                      <!--<![endif]-->
                    </span>
                    <?php print $category; ?>
                  </div>
                <?php endforeach ?>

                <?php if (count($related_resource['tags']) > 1): ?>
                  <a class="view-all-tags" href="#">
                    <span class="ico ico-view-all">
                      <!--[if gte IE 9]><!-->
                        <svg class="svg-ico"><use xlink:href="#ico-view-all"/></svg>
                      <!--<![endif]-->
                    </span>
                  </a>
                <?php endif ?>
              </div>
              <h3><?php print $related_resource['title']; ?></h3>
              <div class="w-btn text-center">
                <?php if (user_is_anonymous() && $related_resource['is_private']): ?>
                  <a class="btn orange-btn-hover" href="<?php print url("node/login") ?>"><?php print t('CONNECT TO MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
                <?php else: ?>
                  <a class="btn orange-btn-hover" href="<?php print url("node/{$related_resource['nid']}") ?>"><?php print t('WATCH', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
                <?php endif ?>
              </div>
            </div>
          </div>
        <?php endforeach ?>
      </div>
    </div>
  </div>
<?php endif ?>

<?php if (!empty($_html['top_products'])): ?>
  <div class="b-top-products">
    <div class="container">
      <h2><?php print t('Discover our products', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
      <div class="product-items">
        <?php print $_html['top_products']; ?>
      </div>
    </div>
  </div>
<?php endif ?>
