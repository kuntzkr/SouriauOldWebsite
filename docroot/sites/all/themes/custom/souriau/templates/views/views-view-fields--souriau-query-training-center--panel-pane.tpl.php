<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<div class="b-item-resorce">
  <div class="b-top">
    <?php if (!empty($_html['image'])): ?>
      <?php print $_html['image']; ?>
      <?php if (user_is_anonymous() && $fields['field_resource_private']->content): ?>
        <div class="b-no-permision">
          <span><?php print t('CONNECT TO SEE THE CONTENT', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></span>
        </div>
      <?php endif ?>
    <?php endif ?>
    <?php if (!user_is_anonymous()): ?>
      <div class="b-links">
        <?php print flag_create_link('favourate_resource', $fields['nid']->content, ['is_landing' => TRUE]); ?>
      </div>
    <?php endif ?>
  </div>
  <div class="b-content">
    <div class="info">
      <span class="title"><?php print $fields['field_resource_type']->content; ?></span> <?php print $fields['created']->content; ?>
    </div>
    <div class="w-tags list-tags">
      <?php foreach (views_get_view_result('souriau_query_get_resource_categories', 'default', $fields['nid']->content) as $key => $category): ?>
        <div class="b-tag<?php print ($key) ? ' hide-tag' : ''; ?>">
          <span class="ico ico-tag">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico"><use xlink:href="#ico-tag" xmlns:xlink="http://www.w3.org/1999/xlink"/></svg>
            <!--<![endif]-->
          </span>
          <?php print $category->taxonomy_term_data_name; ?>
        </div>
      <?php endforeach ?>
      
      <?php if (isset($key) && $key > 0): ?>
        <a class="view-all-tags" href="#">
          <span class="ico ico-view-all">
            <!--[if gte IE 9]><!-->
              <svg class="svg-ico"><use xlink:href="#ico-view-all"/></svg>
            <!--<![endif]-->
          </span>
        </a>
      <?php endif ?>
    </div>
    
    <h3><?php print $fields['title']->content; ?></h3>
    <div class="w-btn text-center">
      <?php if (user_is_anonymous() && $fields['field_resource_private']->content): ?>
        <a class="btn orange-btn-hover" href="<?php print url("node/login") ?>"><?php print t('CONNECT TO MY ACCOUNT', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
      <?php else: ?>
        <a class="btn orange-btn-hover" href="<?php print url("node/{$fields['nid']->content}") ?>"><?php print t('WATCH', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?></a>
      <?php endif ?>
    </div>
  </div>
</div>
