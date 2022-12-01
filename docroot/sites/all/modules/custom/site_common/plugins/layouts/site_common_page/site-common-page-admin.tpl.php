<?php
/**
 * @file
 * Template for a 1 column panel layout.
 */
?>
<table>
  <tbody>
    <tr>
      <td colspan="3"><?php print $content['above']; ?></td>
    </tr>
    <tr>
      <td colspan="3"><?php print $content['header']; ?></td>
    </tr>
    <tr>
      <td style="width: 25%;"><?php print $content['left']; ?></td>
      <td><?php print $content['content']; ?></td>
      <td style="width: 25%;"><?php print $content['right']; ?></td>
    </tr>
    <tr>
      <td colspan="3"><?php print $content['footer']; ?></td>
    </tr>
    <tr>
      <td colspan="3"><?php print $content['below']; ?></td>
    </tr>
  </tbody>
</table>
