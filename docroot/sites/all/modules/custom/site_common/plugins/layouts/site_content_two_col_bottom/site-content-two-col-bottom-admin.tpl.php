<?php
/**
 * @file
 * Template for a 2 column panel layout.
 */
?>
<table>
  <tbody>
    <tr><td colspan="2"><?php print $content['above']; ?></td></tr>
    <tr><td colspan="2"><?php print $content['center']; ?></td></tr>
    <tr>
      <td width="50%"><?php print $content['left']; ?></td>
      <td><?php print $content['right']; ?></td>
    </tr>
    <tr><td colspan="2"><?php print $content['bottom']; ?></td></tr>
  </tbody>
</table>
