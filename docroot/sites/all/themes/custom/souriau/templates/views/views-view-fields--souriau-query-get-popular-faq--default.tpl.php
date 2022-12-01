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
<div id="heading-popular<?php print $fields['counter']->content; ?>" 
     role="tab" class="panel-heading">
  <a aria-expanded="false" 
     href="#question-popular<?php print $fields['counter']->content; ?>" 
     data-parent="#accordion" data-toggle="collapse" 
     role="button" class="collapsed" 
     aria-controls="question-popular<?php print $fields['counter']->content; ?>" >
    <?php print $fields['title']->content; ?>
  </a>
</div>

<div aria-expanded="false" 
     aria-labelledby="heading-popular<?php print $fields['counter']->content; ?>" 
     role="tabpanel" class="panel-collapse collapse" 
     id="question-popular<?php print $fields['counter']->content; ?>">
  <div class="panel-body">
    <?php print $fields['body']->content; ?>
    <?php if ($fields['field_faq_product_range']->content): ?>
      <p>
        <a class="link-more" href="<?php print $fields['path']->content; ?>">
            <span aria-hidden="true" class="glyphicon glyphicon-menu-right"></span>
            <?php print t('PRODUCT RANGE LINK', [], ['context' => 'SOURIAU: other']); ?>
        </a>
      </p>
    <?php endif; ?>
  </div>
</div>