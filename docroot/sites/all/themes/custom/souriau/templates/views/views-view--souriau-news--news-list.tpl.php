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
 * @var $view view
 *
 * @ingroup views_templates
 */
?>

<div class="news-items" id="news-landing-news-list">
  <?php print $rows; ?>
</div>

<div class="w-btn <?php print ($_html['is_hidden'] ? 'hidden' : '') ?>" id="news-landing-news-list-load-more">

  <span class="view-more blue-btn" data-page="<?php print $_html['current_page'] ?>" data-ajax-url="<?php print $_html['load_more_url'] ?>">
    <?php print t('LOAD MORE', [], ['context' => SOURIAU_COMMON_T_OTHER]) ?>
  </span>

  <?php print $_html['next_page_link'] ?>

</div>
