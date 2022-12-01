<?php
/**
 * @file
 * Default template for an advanced poll bar - based on default Drupal Poll template.
 *
 * Variables available:
 * - $title: The title of the poll.
 * - $votes: The number of votes for this choice
 * - $percentage: The percentage of votes for this choice.
 * - $vote: The choice number of the current user's vote.
 * - $voted: Set to TRUE if the user voted for this choice.
 */

// Add extra class to wrapper so that user's selected vote can have a different style.
$voted_class = '';
if ($voted) {
    $voted_class = ' voted';
}
?>

<div class="item">
  <div class="progress">
    <div class="progress-bar <?php print $voted_class; ?>" role="progressbar" aria-valuenow="<?php print $percentage; ?>" aria-valuemin="0" aria-valuemax="100" style="width: <?php print $percentage; ?>%;"></div>
  </div>
  <div class="b-name-progress">
    <div class="b-title"><?php print $title; ?></div>
    <div class="b-cnt-persent">
      <?php print $percentage; ?>% (<?php print format_plural($votes, '1 vote', '@count votes'); ?>)
    </div>
  </div>
</div>
