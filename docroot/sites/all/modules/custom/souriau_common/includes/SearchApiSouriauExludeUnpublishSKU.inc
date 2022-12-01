<?php

/**
 * @file
 * Contains the SearchApiSouriauExludeUnpublishSKU class.
 */

/**
 * Exclude nodes with empty or unpublished SKU from index.
 */
class SearchApiSouriauExludeUnpublishSKU extends SearchApiAbstractAlterCallback {

  /**
   * Check whether this data-alter callback is applicable for a certain index.
   *
   * Returns TRUE only for indexes on nodes.
   *
   * @param SearchApiIndex $index
   *   The index to check for.
   *
   * @return bool
   *   TRUE if the callback can run on the given index; FALSE otherwise.
   */
  public function supportsIndex(SearchApiIndex $index) {
    return $index->getEntityType() === 'node';
  }

  /**
   * Alter items before indexing.
   *
   * Items which are removed from the array won't be indexed, but will be marked
   * as clean for future indexing.
   *
   * @param array $items
   *   An array of items to be altered, keyed by item IDs.
   */
  public function alterItems(array &$items) {
    foreach ($items as $nid => &$item) {
      if ('product' != $item->type) {
        continue;
      }
      if (empty($item->field_sku_products)) {
        unset($items[$nid]);
      }
      else {
        $value = field_get_items('node', $item, 'field_sku_products');
        if (empty($value[0]['product_id'])) {
          unset($items[$nid]);
          continue;
        }
        $sku = commerce_product_load($value[0]['product_id']);
        if (!$sku || !$sku->status) {
          unset($items[$nid]);
        }
      }
    }
  }

}
