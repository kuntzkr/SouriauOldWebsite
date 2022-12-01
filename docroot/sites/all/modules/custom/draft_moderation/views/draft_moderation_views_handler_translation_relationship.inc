<?php
/**
 * @file
 * Contains the relationship plugin for relating entities to translation metadata.
 */

/**
 * Add a relationship to the entity translation table.
 */
class draft_moderation_views_handler_translation_relationship extends views_handler_relationship {

  function query() {
    $table_data = views_fetch_data($this->definition['base']);
    $base_field = empty($this->definition['base field']) ? $table_data['table']['base']['field'] : $this->definition['base field'];

    $this->ensure_my_table();

    $def = $this->definition;
    $def['table'] = $this->definition['base'];
    $def['field'] = $base_field;
    $def['left_table'] = $this->table_alias;
    $def['left_field'] = $this->real_field;
    if (!empty($this->options['required'])) {
      $def['type'] = 'INNER';
    }

    if (!empty($this->definition['extra'])) {
      $def['extra'] = $this->definition['extra'];
    }

    if (!empty($def['join_handler']) && class_exists($def['join_handler'])) {
      $join = new $def['join_handler'];
    }
    else {
      $join = new views_join();
    }

    $join->definition = $def;
    $join->options = $this->options;
    $join->construct();
    $join->adjusted = TRUE;

    // use a short alias for this:
    $alias = $def['table'] . '_' . $this->table;

    // We need to add a condition on entity type to the join to avoid getting
    // relationships to entities with other types.
    $join->extra = "$alias.entity_type = '{$def['entity type']}'";

    $this->alias = $this->query->add_relationship($alias, $join, $this->definition['base'], $this->relationship);

    // Add access tags if the base table provide it.
    if (empty($this->query->options['disable_sql_rewrite']) && isset($table_data['table']['base']['access query tag'])) {
      $access_tag = $table_data['table']['base']['access query tag'];
      $this->query->add_tag($access_tag);
    }
  }
}
