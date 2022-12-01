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
<h1>
  <?php print t('Your sample orders history', [], ['context' => SOURIAU_COMMON_T_COMMERCE]); ?>
</h1>
<div class="w-table">
  <table>
    <colgroup>
      <col class="ar-num-col">
      <col class="creation-col">
      <col class="update-col">
      <col class="acknow-col">
      <col class="id-col">
      <col>
    </colgroup>
    <?php if (!empty($header)) : ?>
      <thead>
        <tr>
          <?php foreach ($header as $field => $label): ?>
            <th>
              <?php print $label; ?>
            </th>
          <?php endforeach; ?>
            <th>&nbsp;</th>
        </tr>
      </thead>
    <?php endif; ?>
      <tbody>
        <?php foreach ($rows as $row_count => $row): ?>
          <tr class="clickable-row new-tab" data-href='<?php print url("user/{$user->uid}/sample-orders/{$row['order_id']}");?>'>
            <?php foreach ($row as $field => $content): ?>
              <td>
                <?php print $content; ?>
              </td>
            <?php endforeach; ?>
             <td>
                <span class="b-view">
                  <span class="ico ico-view">
                    <!--[if gte IE 9]><!-->
                      <svg class="svg-ico"><use xlink:href="#ico-view"></use></svg>
                    <!--<![endif]-->
                    </span>
                  <span class="screen-reader-text"><?php print t('view sample order', [], ['context' => SOURIAU_COMMON_T_COMMERCE]) ?></span>
              </span>
            </td>
          </tr>
        <?php endforeach; ?>
      </tbody>
  </table>
</div>
