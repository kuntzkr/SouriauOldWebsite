<?php

/**
 * @file
 * Contains the SouriauSearchDatasourceController class.
 */

/**
 * Provides multilingual versions of all entity types.
 */
class SouriauSearchDatasourceController extends SearchApiEtDatasourceController {

  /**
   * {@inheritdoc}
   */
  public function _startTracking_nodes(array $indexes) {
    if (!$this->table) {
      return;
    }
    // We first clear the tracking table for all indexes, so we can just insert
    // all items again without any key conflicts.
    $this->stopTracking($indexes);

    if (!empty($this->entityInfo['base table']) && $this->idKey) {
      foreach ($indexes as $index) {

        $query = db_select('node', 'n');
        $query->leftJoin('entity_translation', 't', 't.entity_id=n.nid');
        $db_or_entity_type = db_or();
        $db_or_entity_type->condition('t.entity_type', 'node');
        $db_or_entity_type->condition('t.entity_type', NULL);
        $query->condition($db_or_entity_type);
        $query->addExpression(':index_id', 'index_id', array(':index_id' => $index->id));
        $query->addExpression("CONCAT(n.nid, '/', IFNULL(t.language, 'und'))", 'item_id');
        $query->addExpression('1', 'changed');
        $db_or_status = db_or();
        $db_or_status->condition('t.status', 1);
        $db_or_status->condition('t.status', NULL);
        $query->condition($db_or_status);

        if ($bundles = $this->getIndexBundles($index)) {
          $bundle_column = 'n.type';
          if ($bundles) {

            // Remove Part Numbers. They don't have drafts nodes.
            unset($bundles['product']);
            // Prepare subCondition.
            $db_status_type_not_product = db_and();
            $db_status_type_not_product->condition($bundle_column, $bundles);
            $db_status_type_not_product->condition('n.status', 1);

            // Create 'or' condition.
            // Not Product and published.
            // or just type = Product.
            $db_status_type = db_or();
            $db_status_type->condition($db_status_type_not_product);
            $db_status_type->condition($bundle_column, 'product');

            // Set status condition into query.
            $query->condition($db_status_type);
          }
        }

        // INSERT ... SELECT ...
        db_insert($this->table)
          ->from($query)
          ->execute();
      }
    }
    else {
      $this->startTrackingFallback($indexes);
    }
  }

}
