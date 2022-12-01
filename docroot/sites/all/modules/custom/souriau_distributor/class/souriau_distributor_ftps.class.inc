<?php

/**
 * @file
 * Distributor FTPS Class.
 */

/**
 * Class ftps.
 */
class Ftps {
  private $server;
  private $username;
  private $password;
  private $curlhandle;
  private $port;
  public $dir = '/';

  /**
   * Constructor.
   */
  public function __construct($server, $username, $password, $port) {
    $this->server = $server;
    $this->username = $username;
    $this->password = $password;
    $this->port = $port;
    $this->curlhandle = curl_init();
  }

  /**
   * Set some common curl options.
   */
  private function common($remote) {
    curl_reset($this->curlhandle);
    curl_setopt($this->curlhandle, CURLOPT_URL, $this->server . '/' . $remote);
    curl_setopt($this->curlhandle, CURLOPT_USERPWD, $this->username . ':' . $this->password);
    curl_setopt($this->curlhandle, CURLOPT_SSL_VERIFYPEER, FALSE);
    curl_setopt($this->curlhandle, CURLOPT_SSL_VERIFYHOST, FALSE);
    curl_setopt($this->curlhandle, CURLOPT_FTP_USE_EPRT, TRUE);
    curl_setopt($this->curlhandle, CURLOPT_FTP_SSL, CURLFTPSSL_TRY);
    curl_setopt($this->curlhandle, CURLOPT_FTPSSLAUTH, CURLFTPAUTH_TLS);
    curl_setopt($this->curlhandle, CURLOPT_PORT, $this->port);

    return $this->curlhandle;
  }

  /**
   * Get directory list from folder.
   */
  public function dirList() {
    curl_setopt($this->curlhandle, CURLOPT_DIRLISTONLY, TRUE);
    $files_list = curl_exec($this->curlhandle);

    return $files_list;
  }

  /**
   * Download the file from FTP to local.
   */
  public function download($filepath, $local = FALSE) {
    $filename = basename($filepath);
    $remote   = dirname($filepath);
    if ($remote == '.') {
      $remote = $this->dir;
    }
    else {
      $remote = $remote . '/';
    }
    $local = $local . $filename;
    if ($local === FALSE) {
      $local = $filename;
    }

    if ($fp = fopen($local, 'w')) {
      $this->curlhandle = self::common($remote . $filename);
      curl_setopt($this->curlhandle, CURLOPT_UPLOAD, 0);
      curl_setopt($this->curlhandle, CURLOPT_FILE, $fp);
      curl_exec($this->curlhandle);
      if (curl_errno($this->curlhandle)) {
        throw new \RuntimeException('curl error: ' . curl_errno($this->curlhandle) . ': ' . curl_error($this->curlhandle));
      }
      else {
        return $local;
      }
    }
    return FALSE;
  }

  /**
   * Upload the file from local to FTP.
   */
  public function upload($filepath) {
    $filename = basename($filepath);
    $remote   = basename(dirname($filepath));
    if ($remote == '.') {
      $remote = $this->dir;
    }

    if ($fp = fopen($filepath, 'r')) {
      $this->curlhandle = self::common($remote . '/' . $filename);
      curl_setopt($this->curlhandle, CURLOPT_UPLOAD, 1);
      curl_setopt($this->curlhandle, CURLOPT_INFILE, $fp);
      curl_setopt($this->curlhandle, CURLOPT_INFILESIZE, filesize($filepath));
      curl_exec($this->curlhandle);
      if (curl_errno($this->curlhandle)) {
        throw new \RuntimeException('curl error: ' . curl_errno($this->curlhandle) . ': ' . curl_error($this->curlhandle));
      }
      else {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Get all file names in a directory.
   */
  public function ftpGetFileNames($filepath) {
    $this->curlhandle = self::common($filepath);
    $file_names = array();
    curl_setopt($this->curlhandle, CURLOPT_RETURNTRANSFER, TRUE);
    curl_setopt($this->curlhandle, CURLOPT_DIRLISTONLY, TRUE);
    $files_list = curl_exec($this->curlhandle);
    // The list of all files names on folder.
    $file_names_array = explode("\n", $files_list);
    // Filter and exclude array elements not valid.
    foreach ($file_names_array as $key => $file_name) {
      if ((strstr($file_name, date('ymd')) || (date('Ymd') == substr($file_name, 0, 8))) && (strtolower(substr(trim($file_name), -3)) === 'csv')) {
        $file_names[] = trim($file_name);
      }
    }

    return $file_names;
  }

  /**
   * Close the curl handle.
   */
  public function closeHandle() {
    curl_close($this->curlhandle);
  }

}
