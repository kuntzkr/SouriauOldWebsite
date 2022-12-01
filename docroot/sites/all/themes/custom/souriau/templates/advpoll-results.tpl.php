<?php

/**
 * @file
 * Default template for wrapping bar results - includes count of votes.
 *
 * Variables available:
 * - $nid: The nid of the poll
 * - $cancel_form: Provides a form for deleting user's votes when they have
 *   permission to do so.
 * - $bars: The output of all styled bars displaying votes.
 * - $total: Total number of votes.
 * - $voted: An array indicating which unique choice ids were selected by the user.
 */
?>
<div class="b-result" id="advpoll-<?php print $nid; ?>">
  <?php if ($voted): ?>
    <div class="b-message text-center">
      <?php if ($newly_voted): ?>
        <?php print t('Thank you for taking part to our survey!', [], ['context' => SOURIAU_COMMON_T_HEADER]) ?>
      <?php else: ?>
        <?php print t('You already completed this survey, thank you!', [], ['context' => SOURIAU_COMMON_T_HEADER]) ?>
      <?php endif; ?>
    </div>
  <?php endif ?>
  <h4>
    <?php print t('Results', [], ['context' => SOURIAU_COMMON_T_HEADER]) ?>
  </h4>
  <div class="b-progress-result">
    <?php print $bars; ?>
  </div>
  <h4>
    <?php print t('Total votes: @total', ['@total' => $total], ['context' => SOURIAU_COMMON_T_HEADER]); ?>
  </h4>

  <?php print $cancel_form; ?>
</div>
