<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any.
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <div class="w-breadcrumb">
    <div class="container">
      <?php print souriau_common_get_share_buttons(); ?>
      <?php print $_html['breadcrumbs']; ?>
    </div>
  </div>
  <div class="b-locators">
    <div class="container">
    <h1><?php print t('Our distributors', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></h1>
    <?php if (!empty($_html['souriau_distributors_google_map_link'])): ?>
      <div><iframe src="<?php print $_html['souriau_distributors_google_map_link']; ?>" width="940" height="480"></iframe></div>
    <?php endif; ?>
    <?php if ($exposed): ?>
      <div class="b-filter-locators">
        <?php print $exposed; ?>
      </div>
    <?php endif; ?>

    <?php if ($rows): ?>
      <div class="view-content list-locators">
        <?php print $rows; ?>
      </div>
    <?php elseif ($empty): ?>
      <div class="view-empty">
        <?php print !empty($_html['empty_distributors']) ? $_html['empty_distributors'] : $empty; ?>
      </div>
    <?php endif; ?>
    <?php if ($pager): ?>
      <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($more): ?>
      <?php print $more; ?>
    <?php endif; ?>
    </div>
  </div>
</div><?php /* class view */ ?>
