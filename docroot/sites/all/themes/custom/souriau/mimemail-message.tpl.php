<?php

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xmlns:v="urn:schemas-microsoft-com:vml" style="font-size: 100%;">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title><?php print t('Souriau - Sunbank Connection Technologies', [], ['context' => SOURIAU_COMMON_T_OTHER]);?></title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
  <style>
    @media only screen and (max-width: 767px){
      body{
        font-size: 0.875em  !important; /*16px*/
        line-height: 130% !important;
      }
      .main-table {
        width: 100% !important;
      }
    }
  </style>
</head>
<body bg-color="#ffffff" style="padding: 0; margin: 0; background-color: #ffffff; font-size: 16px; line-height: 30px; -webkit-text-size-adjust:none; -ms-text-size-adjust: 100%;">
<table class="main-table" cellpadding="0" cellspacing="0" align="center" style="margin: 0 auto; width: 500px; color: #4a5763; font-family: Arial, sans-serif;">
  <tbody>
  <tr>
    <!-- header -->
    <td valign="top" align="center" colspan="3" style="border-top: 4px solid #003865; padding: 19px 0 56px;">
      <a rel="notrack" href="<?php print url('<front>', array('absolute' => TRUE));?>" target="_blank"><img style="width: 180px; height: 113px; display: block;" border="0" src="<?php print $_data['email_images'] . 'logo.png'; ?>"  width="180" height="113" /></a>
    </td>
  </tr>
  <tr>
    <td valign="top" width="13%"></td>
    <td valign="top" style="padding: 0 0 90px;"><?php print $body; ?></td>
    <td valign="top" width="13%"></td>
  </tr>
  <tr>
    <!-- footer -->
    <td valign="top" align="center" bg-color="#f2f3f5" colspan="3" style="padding: 57px 0 50px; background: #f2f3f5;">
      <a rel="notrack" href="#" target="_blank"><img style="width: 214px; height: 134px; display: block;" border="0" src="<?php print $_data['email_images'] . '/new-logo.png';?>" alt="<?php print t('Souriau - Sunbank Connection Technologies', [], ['context' => SOURIAU_COMMON_T_OTHER]);?>" width="214" height="134" /></a>
      <table cellpadding="0" cellspacing="0" border="0" style="margin: 0 auto;">
        <tr>
          <?php if (!empty($_data['social_links']['facebook'])): ?>
            <td valign="top" style="padding: 51px 11px 0;">
              <a rel="notrack" href="<?php print $_data['social_links']['facebook'];?>" target="_blank">
                <img border="0" src="<?php print $_data['email_images'] . 'facebook.png';?>" alt="facebook" width="9" height="15"  style="display: block;"/>
              </a>
            </td>
          <?php endif; ?>

          <?php if (!empty($_data['social_links']['twitter'])): ?>
            <td valign="top" style="padding: 51px 11px 0;">
              <a rel="notrack" href="<?php print $_data['social_links']['twitter'];?>" target="_blank">
                <img border="0" src="<?php print $_data['email_images'] . 'twitter.png';?>" alt="twitter" width="19" height="15"  style="display: block;"/>
              </a>
            </td>
          <?php endif; ?>

          <?php if (!empty($_data['social_links']['in'])): ?>
            <td valign="top" style="padding: 51px 11px 0;">
              <a rel="notrack" href="<?php print $_data['social_links']['in'];?>" target="_blank">
                <img border="0" src="<?php print $_data['email_images'] . 'linkedin.png';?>" alt="linkedin" width="17" height="15"  style="display: block;"/>
              </a>
            </td>
          <?php endif; ?>

          <?php if (!empty($_data['social_links']['google'])): ?>
            <td valign="top" style="padding: 51px 11px 0;">
              <a rel="notrack" href="<?php print $_data['social_links']['google'];?>" target="_blank">
                <img border="0" src="<?php print $_data['email_images'] . 'google.png';?>" alt="google+" width="16" height="15"  style="display: block;"/>
              </a>
            </td>
          <?php endif; ?>

          <?php if (!empty($_data['social_links']['youtube'])): ?>
            <td valign="top" style="padding: 51px 11px 0;">
              <a rel="notrack" href="<?php print $_data['social_links']['youtube'];?>" target="_blank">
                <img border="0" src="<?php print $_data['email_images'] . 'youtube.png';?>" alt="youtube" width="17" height="15"  style="display: block;"/>
              </a>
            </td>
          <?php endif; ?>
        </tr>
      </table>
  </tr>
  </tbody>
</table>
</body>
</html>
