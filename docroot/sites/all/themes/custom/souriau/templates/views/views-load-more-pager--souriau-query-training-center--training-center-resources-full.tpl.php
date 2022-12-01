<?php
/**
 * @file
 * Template.
 */
?>
<?php if (!$_html['is_last_page']): ?>
  <div class="w-btn text-center">
    <div class="pagination">
      <ul class="pager pager-load-more">
        <li>
          <a class="view-more blue-btn" href="<?php print $_html['url']; ?>">
            <?php print t('LOAD MORE', [], ['context' => SOURIAU_COMMON_T_OTHER]); ?>
          </a>
        </li>
      </ul>
    </div>
  </div>
<?php endif ?>
