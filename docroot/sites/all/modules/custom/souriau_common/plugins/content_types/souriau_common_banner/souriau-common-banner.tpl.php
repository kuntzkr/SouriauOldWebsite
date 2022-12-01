<?php
/**
 * @file
 * Template.
 */
?>
<?php if($_html['is_banner']): ?>
<div class="<?php print $_html['b_type'];?> w-banner-block">
<?php endif; ?>
  <div class="w-breadcrumb show-share">
    <div class="container">
      <?php print $_html['share']; ?>
      <?php print $_html['breadcrumb']; ?>
    </div>
  </div>
<?php if($_html['is_banner']): ?>
  <div class="b-banner">
    <?php print $_html['image']; ?>
  </div>
  <?php if (!isset($_html['application_banner'])): ?>
  <div class="container">
    <div class="b-content">
      <?php if (!empty($_html['node_type']) && $_html['node_type'] == 'productlanding'): ?>
        <div class="b-title">
          <h1><?php print $_html['title']; ?></h1>
        </div>
      <?php elseif (!empty($_html['node_type']) && $_html['node_type'] == 'productrange'): ?>
        <div class="title">
          <div class="title-inner">
            <h1><?php print $_html['title']; ?></h1>
            <?php if (!empty($_html['second_level_title'])): ?>
              <h2><?php print $_html['second_level_title']; ?></h2>
            <?php endif ?>
          </div>
        </div>
      <?php else: ?>
        <div class="title">
          <h1><?php print $_html['title']; ?></h1>
        </div>
      <?php endif; ?>
      <div class="b-bottom">
        <?php if ($_html['part_number_available']): ?>
          <div class="w-search-row">
            <?php print $_html['search']; ?>
          </div>
        <?php endif; ?>
        <?php print $_html['share']; ?>
      </div>
    </div>
    <?php if (!empty($_html['downloads'])) : ?>
    <div class="b-downloads-links visible-lg-block" data-attr="block-links">
      <div class="wrapper">
        <div class="col-text">
          <h2><?php print t('Downloads', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
        </div>
        <div class="col-links">
          <?php print $_html['downloads']; ?>
        </div>
      </div>
    </div>
    <?php endif; ?>
  </div>
  <?php endif;?>
</div>
  <?php if (!empty($_html['downloads'])) : ?>
    <div class="visible-sm-block">
    <div class="b-downloads-links" data-attr="block-links">
      <div class="container">
        <div class="col-text">
          <h2><?php print t('Downloads', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
        </div>
        <div class="col-links">
          <?php print $_html['mobile_downloads']; ?>
        </div>
      </div>
    </div>
    <div class="divider"></div>
  </div>
  <?php endif; ?>
<?php endif; ?>
