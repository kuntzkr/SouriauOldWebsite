<?php
/**
 * @file
 * Template for a 2 column panel layout.
 */
?>
<table>
  <tbody>
    <tr>
      <td width="50%"><?php print $content['top_left']; ?></td>
      <td width="50%"><?php print $content['top_right']; ?></td>
    </tr>
    <tr>
      <td colspan="2"><?php print $content['content']; ?></td>
    </tr>
  </tbody>
</table>
