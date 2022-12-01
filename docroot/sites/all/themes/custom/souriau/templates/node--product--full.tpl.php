<?php
/**
 * @file
 * Template.
 */
?>
<div id="product-overview" class="b-part-number scroll-section">
  <div class="container">
    <?php if (!empty($_data['image'])): ?>
    <div class="b-pic">
      <?php print drupal_render($_data['image']);?>
      <div class="w-btn text-center visible-lg-block">
        <?php print $_html['model'];?>
      </div>
    </div>
    <?php endif;?>
    <div class="b-main" itemscope itemtype="http://schema.org/Product">
      <div class="title">
        <h1 itemprop="name"><?php print $_html['title'];?></h1>
        <?php if ($_data['sticky']): ?>
        <div class="b-new-icon">
          <?php print t('NEW', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>
        </div>
        <?php endif;?>
      </div>
      <?php if (!empty($_html['pn'])):?>
      <div class="b-part-numb">
        <?php print $_html['pn'];?>
      </div>
      <?php endif;?>
      <div class="b-wrapper">
        <div class="b-main-info">
          <div class="b-row">
            <div class="b-stock-info <?php print $_html['available'];?> a-right hidden-xs">
              <?php print $_html['stock_label'];?>
            </div>
            <?php if (!empty($_html['series'])): ?>
            <div class="b-add-info">
              <?php print $_html['series'];?>
            </div>
            <?php endif;?>
          </div>
          <?php if (!empty($_html['description'])):?>
          <div class="b-description" itemprop="description">
            <?php print $_html['description'];?>
          </div>
          <?php endif;?>
        </div>
        <div class="b-wrapper-btns">
          <div class="w-btn">
            <?php print $_html['where_to_buy'];?>
          </div>
          <?php if (!$_data['d_system'] || $_data['legacy']): ?>
          <div class="b-stock-info <?php print $_html['available'];?> a-right visible-xs-block">
            <?php print $_html['stock_label'];?>
          </div>
          <?php endif;?>
          <div class="b-links">
            <?php print $_html['b_links'];?>
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
<?php if (!empty($_html['key_features'])): ?>
<div id="key-features" class="grey-bg scroll-section">
  <section class="b-features">
    <div class="container">
      <div class="b-main-info">
        <?php print $_html['key_features'];?>
      </div>
      <div class="title">
        <h3><?php print t('Key features and benefits', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></h3>
      </div>
    </div>
  </section>
</div>
<?php endif;?>
<?php if (!empty($_html['downloads'])): ?>
<section id="downloads" class="b-downloads-links scroll-section">
  <div class="container">
    <div class="col-text">
      <h2><?php print t('Downloads', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
    </div>
    <div class="col-links">
      <?php print $_html['downloads']; ?>
    </div>
  </div>
</section>
<?php endif; ?>
<?php if (!empty($_html['tech_data'])): ?>
  <div id="tech-data" class="scroll-section">
  <?php print $_html['tech_data'];?>
  </div>
<?php endif; ?>
<?php if (!empty($_html['complementary'])): ?>
<div id="complementary-products" class="b-part-number-products scroll-section">
  <div class="container">
    <h2><?php print t('Complementary <span>Products</span>', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></h2>
    <div class="b-tabs">
      <?php print $_html['compl_groups'];?>
      <div class="tab-content">
        <?php print $_html['complementary'];?>
      </div>
    </div>
  </div>
</div>
<?php endif; ?>
<?php if (!empty($_html['advices']) || !empty($_html['advices_description'])): ?>
<section id="advices" class="b-services scroll-section">
  <div class="b-main-description">
    <div class="container">
      <div class="b-text">
        <h2><?php print t('Help and Advice', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
        <?php print $_html['advices_description'];?>
      </div>
      <?php if ($_html['advices_image']): ?>
        <div class="b-pic">
          <?php print $_html['advices_image']; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <?php foreach ($_html['advices'] as $advice): ?>
    <div class="b-advice">
      <div class="container">
        <div class="b-pic">
          <?php if ($advice['video_id']): ?>
            <div class="b-video">
              <iframe width="1280" height="720" src="http://www.youtube.com/embed/<?php print $advice['video_id']; ?>" frameborder="0" allowfullscreen></iframe>
            </div>
          <?php elseif ($advice['image']): ?>
            <?php print drupal_render($advice['image']); ?>
          <?php endif; ?>
        </div>
        <div class="b-text">
          <h2><?php print $advice['title']; ?></h2>
          <p><?php print $advice['description']; ?></p>
        </div>
      </div>
    </div>
  <?php endforeach; ?>
</section>
<?php endif; ?>
<?php if (!empty($_html['recommendation'])): ?>
<div id="recommended-products" class="b-part-number-products recommended-products scroll-section">
  <div class="container">
    <h2><?php print t('Recommended <span>Products</span>', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h2>
    <div class="b-tabs">
      <?php print $_html['rec_groups'];?>
      <div class="tab-content">
        <?php print $_html['recommendation'];?>
      </div>
    </div>
  </div>
</div>
<?php endif;?>
<ul class="sticky-left">
  <li class="icon-ui-bulle-pleine active" title="<?php print t('Product overview', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>">
      <span class="circle"></span><span class="sticky-left-line"></span><a href="#product-overview"><?php print t('Product overview', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></a>
  </li>
  <?php if (!empty($_html['key_features'])): ?>
  <li class="icon-ui-bulle-pleine" title="<?php print t('Key features and benefits', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>">
      <span class="circle"></span><span class="sticky-left-line"></span><a href="#key-features"><?php print t('Key features and benefits', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></a>
  </li>
  <?php endif;?>    
  <?php if (!empty($_html['downloads'])): ?>
  <li class="icon-ui-bulle-pleine" title="<?php print t('Downloads', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>">
      <span class="circle"></span><span class="sticky-left-line"></span><a href="#downloads"><?php print t('Downloads', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></a>
  </li>
  <?php endif;?>
  <?php if (!empty($_html['tech_data'])): ?>
  <li class="icon-ui-bulle-pleine" title="<?php print t('Technical data', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>">
      <span class="circle"></span><span class="sticky-left-line"></span><a href="#tech-data"><?php print t('Technical data', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></a>
  </li>
  <?php endif;?>
  <?php if (!empty($_html['complementary'])): ?>
  <li class="icon-ui-bulle-pleine" title="<?php print t('Complementary products', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>">
      <span class="circle"></span><span class="sticky-left-line"></span><a href="#complementary-products"><?php print t('Complementary products', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></a>
  </li>
  <?php endif;?>
  <?php if (!empty($_html['advices']) || !empty($_html['advices_description'])): ?>
  <li class="icon-ui-bulle-pleine" title="<?php print t('Advices', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>">
      <span class="circle"></span><span class="sticky-left-line"></span><a href="#advices"><?php print t('Advices', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></a>
  </li>
  <?php endif;?>
  <?php if (!empty($_html['recommendation'])): ?>
  <li class="icon-ui-bulle-pleine" title="<?php print t('Recommended products', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>">
      <span class="circle"></span><span class="sticky-left-line"></span><a href="#recommended-products"><?php print t('Recommended products', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></a>
  </li>
  <?php endif;?>
</ul>
<div class="b-to-compare hidden-xs">
  <div class="b-to-fixed">
    <div class="container">
      <div class="align-center">
        <div class="text"><?php print $_html['comparator_string']; ?></div>
        <div class="w-btn">
          <a class="btn orange-btn-hover" href="<?php print url('compare-part-numbers'); ?>"><?php print t('GO TO COMPARATOR', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
        </div>
      </div>
    </div>
  </div>
</div>
