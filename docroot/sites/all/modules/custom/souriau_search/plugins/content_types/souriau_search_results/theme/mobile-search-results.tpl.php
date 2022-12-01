<?php
/**
 * @file
 * Search results section template.
 */
?>

<div class="block <?php print $_data['classes'] ?>">
  <div class="grid">
    <?php if (!empty($title)): ?>
      <h2 class="list-title"><?php print $title ?></h2>
    <?php endif;?>
    <ul>
      <?php if($items): ?>
        <?php foreach ($items as $item): ?>
            <li>
              <?php print render($item); ?>
            </li>
        <?php endforeach; ?>
      <?php else: ?>
        <div class="search-results-empty">
          <p>
            <?php print t('Vous avez recherché “@keyword”, nous avons trouvé', array('@keyword' => isset($_GET['keyword']) ? $_GET['keyword'] : ''), array('context' => 'Guerlain: mobile'));?>
            <strong>
            <?php print t('0 résultat.', array(), array('context' => 'Guerlain: mobile'));?>
            </strong>
          </p>
        </div>
      <?php endif;?>
    </ul>
  </div>
</div>

<?php if ($pager): ?>
  <div class="block block-buttons block-buttons-d block-buttons-more">
    <div class="grid">
      <div class="buttons">
        <div class="button">
          <a class="ui-btn ui-btn-b ui-btn-large">
            <span>
              <?php print t('voir plus de résultats', array(), array('context' => 'Guerlain: mobile'));?>
            </span>
          </a>
        </div>
      </div>
    </div>
  </div>
<?php endif; ?>
