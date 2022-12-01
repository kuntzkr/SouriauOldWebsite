<?php
if (isset($_ENV['AH_SITE_ENVIRONMENT'])) {
  $conf['environment_indicator_overwrite'] = TRUE;
  switch ($_ENV['AH_SITE_ENVIRONMENT']) {
    case 'dev':
      $conf['environment_indicator_overwritten_name'] = 'DEV server';
      $conf['environment_indicator_overwritten_color'] = '#00b615';
      $cookie_domain = '.dev.souriau.com';
      $env = [
        'name' => 'develop',
        'main_domain' => 'dev.souriau.com',
        'admin_login' => 'admin',
        'admin_pwd' => 'admin',
      ];
      break;

    case 'test':
      $conf['environment_indicator_overwritten_name'] = 'STAGE server';
      $conf['environment_indicator_overwritten_color'] = '#e2f51f';
      $cookie_domain = '.stage.souriau.com';
      $env = [
        'name' => 'stage',
        'main_domain' => 'stage.souriau.com',
        'admin_login' => 'souriau_admin',
        'admin_pwd' => 'st98sI728Y2&w24sxvb',
      ];
      break;

    case 'prod':
    default:
      $conf['environment_indicator_overwritten_name'] = 'PROD server';
      $conf['environment_indicator_overwritten_color'] = '#aa3333';
      $cookie_domain = '.souriau.com';
      $env = [
        'name' => 'prod',
        'main_domain' => 'souriau.com',
        'admin_login' => 'souriau_admin',
        'admin_pwd' => 'pr$fd%scA@7fg7a',
      ];
      break;

  }
  $conf['enviroment'] = &$env;
}
