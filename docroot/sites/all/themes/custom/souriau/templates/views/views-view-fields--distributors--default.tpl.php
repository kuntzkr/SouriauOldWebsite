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
<div class="item-locator">
  <h3><?php print $fields['field_distributor_name']->content; ?></h3>
  <div class="b-type">
    <?php print $fields['field_type']->content; ?> / <?php print $fields['field_distributor_brand']->content; ?>
    <?php if (!empty($fields['field_vad_series']->content)): ?>
      <div><?php print $fields['field_vad_series']->content; ?></div>
    <?php endif; ?>
  </div>
  <div class="b-address-info">
    <?php if (!empty($fields['field_contact_person'])): ?>
      <p><?php print $fields['field_contact_person']->label_html . $fields['field_contact_person']->content; ?></p>
    <?php endif; ?>
    <p><?php print $fields['field_postal_address_thoroughfare']->content; ?></p>
    <p><?php print $fields['field_postal_address_premise']->content; ?></p>
    <?php if ($fields['field_postal_address_country']->content != 'United States'): ?>
      <p><?php print $fields['field_postal_address_postal_code']->content . ' ' . $fields['field_postal_address_locality']->content; ?></p>
    <?php else: ?>
      <p><?php print $fields['field_postal_address_locality']->content . ', ' . $fields['field_postal_address_postal_code']->content; ?></p>
    <?php endif ?>
    <p><?php print $fields['field_postal_address_country']->content; ?></p>
  </div>
  <div class="b-add-info">
    <?php if (!empty($fields['field_postal_address_data'])): ?>
      <p><?php print $fields['field_postal_address_data']->label_html . $fields['field_postal_address_data']->content; ?></p>
    <?php endif; ?>
    <?php if (!empty($fields['field_postal_address_data_1'])): ?>
      <p><?php print $fields['field_postal_address_data_1']->label_html . $fields['field_postal_address_data_1']->content; ?></p>
    <?php endif; ?>
    <?php if (!empty($fields['field_email']->content)): ?>
      <p><a href="mailto:<?php print $fields['field_email']->content; ?>"><?php print $fields['field_email']->content; ?></a></p>
    <?php endif; ?>
  </div>
  <?php if (!empty($fields['field_url']->content)): ?>
    <div class="w-btn">
      <a target="_blank" class="web-link" href="<?php print $fields['field_url']->content; ?>">
        <span class="ico ico-website">
          <!--[if gte IE 9]><!-->
          <svg class="svg-ico"><use xlink:href="#ico-website"/></svg>
          <!--<![endif]-->
        </span>
        <?php print t('GO TO WEBSITE', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
      </a>
    </div>
  <?php endif; ?>
</div>
