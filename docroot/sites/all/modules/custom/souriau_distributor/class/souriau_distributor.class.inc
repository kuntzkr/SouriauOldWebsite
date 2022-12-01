<?php
/**
 * @file
 * Distributor Class.
 */

/**
 * Class Distributor.
 */
class Distributor extends Entity {

  /**
   * Set information about distributor in Object.
   */
  public function getInfo() {
    if (!empty($this->distributor_id)) {
      $this->code = $this->distributor_id;
    }
    elseif (!empty($this->field_distributor_code)) {
      $code = field_get_items('distributor', $this, 'field_distributor_code');
      $code = field_view_value('distributor', $this, 'field_distributor_code', $code[0]);
      $this->code = drupal_render($code);
    }

    if (empty($this->code)) {
      $this->createEmptyValues();
      return;
    }

    global $language;
    $country_list = country_get_list();
    $entity = $this->getEntity();
    if (empty($entity)) {
      $this->createEmptyValues();
      return;
    }

    $distributor_wrapper = entity_metadata_wrapper('distributor', $entity)->language($language->language);
    $postal_address = $distributor_wrapper->field_postal_address->value();
    $this->name = $distributor_wrapper->field_distributor_name->value();
    $this->contact_person = $distributor_wrapper->field_contact_person->value();
    $this->city = $postal_address['locality'];
    $this->country = !empty($postal_address['country']) ? $country_list[$postal_address['country']] : '';
    $this->postal_code = $postal_address['postal_code'];
    $this->address_line_1 = $postal_address['thoroughfare'];
    $this->address_line_2 = $postal_address['premise'];
    $this->phone = $postal_address['phone_number'];
    $this->fax = $postal_address['fax_number'];
    $this->email = $distributor_wrapper->field_email->value();
    $this->url = $distributor_wrapper->field_url->value();
    $this->links = $distributor_wrapper->field_links->value();
    $this->brand = implode(' ', $distributor_wrapper->field_distributor_brand->value());
    $this->distributor_type = $distributor_wrapper->field_type->value();
  }

  /**
   * Return Entity by distributor_code or FALSE.
   */
  private function getEntity() {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'distributor')
      ->entityCondition('bundle', 'distributor')
      ->fieldCondition('field_distributor_code', 'value', $this->code, '=')
      ->range(0, 1);
    $result = $query->execute();

    if (empty($result)) {
      return FALSE;
    }
    $distributor = array_shift($result['distributor']);
    $entity = entity_load_single('distributor', $distributor->id);

    return $entity;
  }

  /**
   * Create empty values.
   */
  public function createEmptyValues() {
    $this->name = '';
    $this->contact_person = '';
    $this->city = '';
    $this->country = '';
    $this->postal_code = '';
    $this->address_line_1 = '';
    $this->address_line_2 = '';
    $this->phone = '';
    $this->fax = '';
    $this->email = '';
    $this->url = '';
    $this->links = '';
  }

}
