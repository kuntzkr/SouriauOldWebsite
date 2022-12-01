<?php
/**
 * @file
 * Entity controllers.
 */

if (class_exists('NodeController') && class_exists('EntityCacheNodeController')) {
  /**
   * Node controller replacement.
   */
  class CacheCommonNodeController extends EntityCacheNodeController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('node', $entities);

      return $entities;
    }

  }
}
elseif (class_exists('NodeController')) {
  /**
   * Node controller replacement.
   */
  class CacheCommonNodeController extends NodeController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('node', $entities);

      return $entities;
    }

  }
}

if (class_exists('TaxonomyTermController') && class_exists('EntityCacheTaxonomyTermController')) {
  /**
   * Taxonomy term conroller replacement.
   */
  class CacheCommonTaxonomyTermController extends EntityCacheTaxonomyTermController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('taxonomy_term', $entities);

      return $entities;
    }

  }
}
elseif (class_exists('TaxonomyTermController')) {
  /**
   * Taxonomy term conroller replacement.
   */
  class CacheCommonTaxonomyTermController extends TaxonomyTermController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('taxonomy_term', $entities);

      return $entities;
    }

  }
}

if (class_exists('CommentController') && class_exists('EntityCacheCommentController')) {
  /**
   * Comment controller replacement.
   */
  class CacheCommonCommentController extends EntityCacheCommentController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('comment', $entities);

      return $entities;
    }

  }
}
elseif (class_exists('CommentController')) {
  /**
   * Comment controller replacement.
   */
  class CacheCommonCommentController extends CommentController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('comment', $entities);

      return $entities;
    }

  }
}

if (class_exists('CommerceProductEntityController')) {
  /**
   * Commerce product controller replacement.
   */
  class CacheCommonCommerceProductController extends CommerceProductEntityController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('commerce_product', $entities);

      return $entities;
    }

  }
}

if (class_exists('EntityAPIController')) {
  /**
   * Asset conroller replacement.
   */
  class CacheCommonAssetController extends EntityAPIController {

    /**
     * Implements DrupalEntityControllerInterface::load().
     */
    public function load($ids = array(), $conditions = array()) {

      // Fetch default entities.
      $entities = parent::load($ids, $conditions);

      // Track them as assecced.
      _cache_common_cache_tags_apply('asset', $entities);

      return $entities;
    }

  }
}
