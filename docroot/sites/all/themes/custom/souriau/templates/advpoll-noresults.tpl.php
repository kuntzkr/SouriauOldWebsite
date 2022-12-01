<?php
/**
 * @file
 * Default template for an advanced poll when results are not available.
 *
 * Conditions under which template will display:
 * 1. When results are set to 'Never' - results will only be visible to those
 *    with permission to view them.
 * 2. When results are set to 'After Close' - results will only be visible when
 *    poll is set to closed.
 *
 * Variables available:
 * - $votes
 * - $nid: Node id of the poll.
 * - $cancel_form: Provides a form for deleting user's votes when they have
 *   permission to do so.
 *
 *   An array containing unique ids of the choice(s) selected by the user.
 * - $data:
 *   object containing the following fields.
 *   choices:
 *      array containing:
 *        choice_id = the unique hex id of the choice
 *        choice =    The text for a given choice.
 *        write_in =  a boolean value indicating whether or not the choice was a
 *                    write in.
 *   start_date:      (int) Start date of the poll
 *   end_date:        (int) End date of the poll
 *   mode:            The mode used to store the vote: normal, cookie, unlimited
 *   cookie_duration: (int) If mode is cookie, the number of minutes to delay votes.
 *   state:           Is the poll 'open' or 'close'
 *   behavior:        approval or pool - determines how to treat multiple vote/user
 *                    tally. When plugin is installed, voting will default to tabulating
 *                    values returned from voting API.
 *   max_choices:     (int) How many choices a user can select per vote.
 *   show_results:    When to display results - aftervote, afterclose or never.
 *   electoral:       Boolean - voting restricted to users in an electoral list.
 *   write_in:        Boolean - all write-in voting.
 *   block:           Boolean - Poll can be displayed as a block.
 */
?>

<div class="b-result" id="advpoll-<?php print $nid; ?>">
  <?php if ($votes): ?>
    <?php if($data->newly_voted): ?>
      <div class="b-message text-center"><?php print t('Thank you for taking part to our survey!', [], ['context' => SOURIAU_COMMON_T_HEADER]); ?></div>
    <?php else: ?>
      <div class="b-message text-center"><?php print t('You already completed this survey, thank you!', [], ['context' => SOURIAU_COMMON_T_HEADER]); ?></div>
    <?php endif; ?>
  <?php endif; ?>
  <?php print $cancel_form; ?>
</div>