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
<div class="b-project-item">
  <?php if (isset($_html['image'])): ?>
    <?php print $_html['image']; ?>
  <?php endif; ?>
  <div class="w-btn">
    <?php print l(t('SEE MY PROJECT', [], ['context' => SOURIAU_COMMON_T_USER]), "user/{$fields['uid']->content}/projects/{$fields['id']->content}", ['attributes' => ['class' => ['btn', 'orange-btn-hover']]]); ?>
  </div>
  <div class="b-info">
    <h3><?php print $fields['field_project_title']->content; ?></h3>
    <p>
      <?php print $fields['field_project_description']->content; ?>
    </p>
    <?php if ($fields['item_id']->content): ?>
      <p>
        <?php print $fields['item_id']->content; ?> 
        <?php print t('Part Numbers', [], ['context' => SOURIAU_COMMON_T_USER]); ?>
      </p>
    <?php endif; ?>
  </div>
</div>
