<?php
/**
 * @file
 * Default simple view template to display a rows in a grid.
 *
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 *
 * @var $rows array
 *
 * @ingroup views_templates
 */
?>

<?php if (!empty($title)) : ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php if (count($rows) > 0) : ?>

  <?php foreach ($rows as $row_num => $columns) : ?>
    <div class="b-row matchHeight">
      <?php foreach ($columns as $column) : ?>
        <?php print $column ?>
      <?php endforeach ?>
    </div>
  <?php endforeach ?>

<?php endif ?>
