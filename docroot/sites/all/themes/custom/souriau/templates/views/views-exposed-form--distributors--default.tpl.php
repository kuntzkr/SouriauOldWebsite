<?php

/**
 * @file
 * This template handles the layout of the views exposed filter form.
 *
 * Variables available:
 * - $widgets: An array of exposed form widgets. Each widget contains:
 * - $widget->label: The visible label to print. May be optional.
 * - $widget->operator: The operator for the widget. May be optional.
 * - $widget->widget: The widget itself.
 * - $sort_by: The select box to sort the view using an exposed form.
 * - $sort_order: The select box with the ASC, DESC options to define order. May be optional.
 * - $items_per_page: The select box with the available items per page. May be optional.
 * - $offset: A textfield to define the offset of the view. May be optional.
 * - $reset_button: A button to reset the exposed filter applied. May be optional.
 * - $button: The submit button for the form.
 *
 * @ingroup views_templates
 */
?>
<?php foreach ($widgets as $id => $widget): ?>
  <div id="<?php print $widget->id; ?>-wrapper" class="form-item form-type-select <?php if ($widget->id == 'edit-field-postal-address-country-selective'): ?>b-country-filter<?php endif; ?>">
    <?php if (!empty($widget->label)): ?>
      <label for="<?php print $widget->id; ?>">
        <?php print $widget->label; ?>
      </label>
    <?php endif; ?>
    <?php print $widget->widget; ?>
  </div>
<?php endforeach; ?>
<div class="views-exposed-widget views-submit-button">
  <?php print $button; ?>
</div>
