#!/bin/sh

cp dev/pre-commit .git/hooks/pre-commit
chmod +x .git/hooks/pre-commit
ln -sf ../../../../drupal/coder/coder_sniffer/Drupal vendor/squizlabs/php_codesniffer/CodeSniffer/Standards/Drupal
