<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 *
 * @ingroup views_templates
 */
?>
<table>
  <thead>
  <tr>
    <th>
      <div class="b-item-info"><?php print t('ADDED ITEMS', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></div>
      <div class="b-part-numb"><?php print t('PART NUMBER', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></div>
      <div class="b-qty"><?php print t('QUANTITY', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?></div>
    </th>
  </tr>
  </thead>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr>
        <td>
          <?php print $row['commerce_product_1']; ?>
          <div class="b-part-numb"><p><?php print $row['commerce_product']; ?></p></div>
          <div class="b-qty"><?php print $row['edit_quantity']; ?></div>
          <div class="element-hidden">
            <?php print $row['edit_delete']; ?>
          </div>
        </td>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
