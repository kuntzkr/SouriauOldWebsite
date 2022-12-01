<?php

/**
 * @file
 * Template.
 */
 $tid = 0;
?>
<div class="w-questions">
  <?php foreach ($_html['faq_data'] as $key => $faq): ?>
    <?php if ($tid != $faq->taxonomy_term_data_node_tid): ?>
      <section class="b-questions" id="section-<?php print $faq->taxonomy_term_data_node_tid; ?>">
        <div class="container">
          <?php $tid = $faq->taxonomy_term_data_node_tid; ?>
          <h2><?php print $faq->taxonomy_term_data_node_name;  ?></h2>
          <?php $flag = 0; ?>
          <?php foreach (views_get_view_result('souriau_query_get_product_range_with_faq', 'default', $faq->taxonomy_term_data_node_tid) as $product_range): ?>
            <ul aria-multiselectable="true" role="tablist" id="accordion<?php print $product_range->node_field_data_field_faq_product_range_nid; ?>" class="panel-group">
            <?php print $product_range->node_field_data_field_faq_product_range_title;?>
            <?php foreach (views_get_view_result('faq_per_product_range', 'default', $product_range->node_field_data_field_faq_product_range_nid, $faq->taxonomy_term_data_node_tid) as $key => $faq_data): ?>
              <?php $flag = 1; ?>
              <li class="panel">
                <div id="heading<?php print $faq->taxonomy_term_data_node_tid . $product_range->node_field_data_field_faq_product_range_nid . $key; ?>" 
                    role="tab" class="panel-heading">
                  <a aria-controls="question<?php print $faq->taxonomy_term_data_node_tid . $product_range->node_field_data_field_faq_product_range_nid . $key; ?>" 
                    aria-expanded="false" 
                    href="#question<?php print $faq->taxonomy_term_data_node_tid . $product_range->node_field_data_field_faq_product_range_nid . $key; ?>" 
                    data-parent="#accordion<?php print $product_range->node_field_data_field_faq_product_range_nid; ?>" 
                    data-toggle="collapse" role="button">
                    <?php print $faq_data->node_title; ?>
                  </a>
                </div>

                <div id="question<?php print $faq->taxonomy_term_data_node_tid . $product_range->node_field_data_field_faq_product_range_nid . $key; ?>" 
                    class="panel-collapse collapse" aria-expanded="false" 
                    aria-labelledby="heading<?php print $faq->taxonomy_term_data_node_tid . $product_range->node_field_data_field_faq_product_range_nid . $key; ?>" 
                    role="tabpanel">
                  <div class="panel-body">
                    <?php print $faq_data->field_body[0]['rendered']['#markup']; ?>
                    <?php if ($faq_data->node_field_data_field_faq_product_range_nid): ?>
                      <p>
                        <a class="link-more" href="<?php print drupal_get_path_alias('node/' . $faq_data->node_field_data_field_faq_product_range_nid); ?>">
                            <span aria-hidden="true" class="glyphicon glyphicon-menu-right"></span>
                            <?php print t('PRODUCT RANGE LINK', [], ['context' => 'SOURIAU: other']); ?>
                        </a>
                      </p>
                    <?php endif; ?>
                  </div>
                </div>
              </li>
            <?php endforeach; ?>
            </ul>
          <?php endforeach; ?>
          <ul aria-multiselectable="true" role="tablist" id="accordion-others<?php print $faq->taxonomy_term_data_node_tid; ?>" class="panel-group">
            <?php $faqs_unassigned = views_get_view_result('souriau_query_get_faq_wihtout_pr_per_theme', 'default', $faq->taxonomy_term_data_node_tid); ?>
            <?php if ($flag == 1 && count($faqs_unassigned) > 0): ?>
              <?php print t('Others', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
            <?php endif ?>
            <?php foreach ($faqs_unassigned as $key => $faq_unassigned): ?>
              <li class="panel">
                  <div id="heading-others<?php print $faq->taxonomy_term_data_node_tid . $key; ?>" 
                      role="tab" class="panel-heading">
                    <a aria-controls="question-others<?php print $faq->taxonomy_term_data_node_tid . $key; ?>" 
                      aria-expanded="false" 
                      href="#question-others<?php print $faq->taxonomy_term_data_node_tid . $key; ?>" 
                      data-parent="#accordion-others<?php print $faq->taxonomy_term_data_node_tid; ?>" 
                      data-toggle="collapse" role="button">
                      <?php print $faq_unassigned->node_title; ?>
                    </a>
                  </div>

                  <div id="question-others<?php print $faq->taxonomy_term_data_node_tid . $key; ?>" 
                      class="panel-collapse collapse" aria-expanded="false" 
                      aria-labelledby="heading-others<?php print $faq->taxonomy_term_data_node_tid . $key; ?>" 
                      role="tabpanel">
                    <div class="panel-body">
                      <?php print $faq_unassigned->field_body[0]['rendered']['#markup']; ?>
                    </div>
                  </div>
                </li>
          <?php endforeach; ?>
          </ul>
        </div>
      </section>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
