<?php
/**
 * @file
 * Template.
 */
?>
<section class="b-interest">
  <a class="b-item" href="<?php print url($params['3dmodel_url']); ?>">
    <div class="inside-container">
      <div class="b-icon">
        <div class="b-aling">
          <span class="ico ico-model">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico"><use xlink:href="#ico-model"/></svg>
            <!--<![endif]-->
          </span>
        </div>
      </div>
      <div class="b-text">
        <div class="b-aling">
          <span class="sub-title">
            <?php print t('YOU MAY BE INTERESTED IN', array(), array('context' => SOURIAU_COMMON_T_OTHER)); ?>
          </span>
          <div class="b-title">
            <h4><?php print t('Download Center', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
          </div>
        </div>
      </div>
    </div>
  </a>
  <a class="b-item b-right" href="<?php print url($params['technical_support']); ?>">
    <div class="inside-container">
      <div class="b-icon">
        <div class="b-aling">
          <span class="ico ico-support">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico"><use xlink:href="#ico-customer-support"/></svg>
            <!--<![endif]-->
          </span>
        </div>
      </div>
      <div class="b-text">
        <div class="b-aling">
          <span class="sub-title">
            <?php print t('YOU MAY BE INTERESTED IN', array(), array('context' => SOURIAU_COMMON_T_OTHER)); ?>
          </span>
          <div class="b-title">
            <h4><?php print t('Technical Support', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h4>
          </div>
        </div>
      </div>
    </div>
  </a>
</section>
