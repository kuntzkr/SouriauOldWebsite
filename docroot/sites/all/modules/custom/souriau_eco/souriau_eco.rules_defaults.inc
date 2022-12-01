<?php
/**
 * @file
 * Rules integration file.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function souriau_eco_default_rules_configuration() {
  $rule = rules_reaction_rule();
  $rule->label = t('Send transaction details via GTM on checkout completion');
  $rule->active = TRUE;
  $rule->event('commerce_checkout_complete')
    ->action('souriau_eco_gtm_send_order', array('commerce_order:select' => 'commerce_order'));
  $configs['souriau_eco_gtm_send_order'] = $rule;
  return $configs;
}


/**
 * Implements hook_default_rules_configuration_alter().
 */
function souriau_eco_default_rules_configuration_alter(&$configs) {
  // Disable default rule 'Send an order notification e-mail'.
  $configs['commerce_checkout_order_email']->active = FALSE;
}
