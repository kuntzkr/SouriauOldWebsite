<?php
/**
 * @file
 * Rules integration file.
 */

/**
 * Implements hook_rules_action_info().
 */
function souriau_eco_rules_action_info() {
  return array(
    // Add rules action which sends the transaction code.
    'souriau_eco_gtm_send_order' => array(
      'label' => t('Send order to google analytics via GTM'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Order in checkout'),
        ),
      ),
      'callback' => array(
        'execute' => 'souriau_eco_gtm_send_order',
      ),
    ),
  );
}
