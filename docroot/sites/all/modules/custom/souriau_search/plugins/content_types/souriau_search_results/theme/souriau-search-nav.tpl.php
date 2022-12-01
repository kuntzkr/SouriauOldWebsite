<?php
/**
 * @file
 * Search result tabs template.
 */
?>

<?php if ($tabs): ?>
  <ul class="nav nav-tabs">
    <?php foreach ($tabs as $id => $tab): ?>
            <li <?php if ($tab['active']) {print 'class="active in"';} ?>>
              <a data-toggle="tab" href="#<?php print $tab['html_id']; ?>" class="text-uppercase"><?php print $tab['name']; ?> (<?php print $tab['total']; ?>)</a>
            </li>
          <?php endforeach; ?>
  </ul>
<?php endif; ?>
