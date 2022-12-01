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
<div class="b-back-link">
  <div class="container">
    <a class="btn-back" href="<?php print url("user") ?>">
      <span aria-hidden="true" class="glyphicon glyphicon-menu-left"></span>
      <?php print t('BACK TO MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_USER]); ?>
    </a>
  </div>
</div>
<div class="b-projects">
  <div class="container">
    <div class="w-new-project">
      <div class="w-btn hidden-xs">
        <?php print ctools_modal_text_button(
        t('+ CREATE NEW PROJECT', [], ['context' => SOURIAU_COMMON_T_USER]),
        'souriau/ajax/project/create/nojs',
        '',
        'ctools-modal-souriau-modal-style btn blue-btn');
        ?>
      </div>
      <div class="w-btn">
        <div class="visible-xs-block">
          <a class="btn blue-btn" href="/user/project/create">
            <?php print t('+ CREATE NEW PROJECT', [], ['context' => SOURIAU_COMMON_T_USER]); ?>
          </a>
        </div>
      </div>
      <h1><?php print t('My projects', [], ['context' => SOURIAU_COMMON_T_USER]); ?></h1>
    </div>

    <?php if ($rows): ?>
      <div class="view-content">
        <?php print $rows; ?>
      </div>
    <?php endif; ?>
  </div>
</div>
