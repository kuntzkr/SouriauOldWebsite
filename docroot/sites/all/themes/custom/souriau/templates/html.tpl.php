<?php

/**
 * @file
 * Template.
 */
?>
<!DOCTYPE html>
<html lang="en" class="no-js">
<head>
  <?php print $google_optimize['anti-flicker']; ?>
  <?php print $google_optimize['snippet']; ?>
  <?php print $gtm['script']; ?>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="apple-touch-icon" href="/sites/all/themes/custom/souriau/html/apple-touch-icon.png">
  <?php if (!empty($meta_title)): ?>
    <meta name="title" content="<?php print $meta_title; ?>" />
  <?php endif; ?>
  <?php if (!empty($meta_description)): ?>
    <meta name="description" content="<?php print $meta_description; ?>" />
  <?php endif; ?>
  <?php if (!empty($meta_keywords)): ?>
    <meta name="keywords" content="<?php print $meta_keywords; ?>" />
  <?php endif; ?>
  <?php print $styles;?>
  <?php print $scripts;?>
</head>
<body>
  <?php print $gtm['noscript']; ?>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>
