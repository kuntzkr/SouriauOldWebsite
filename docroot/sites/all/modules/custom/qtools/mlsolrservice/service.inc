<?php
/**
 * @file
 * Search Api Service class.
 */

/**
 * Basically we just reuse existing solr class overrigin thing we don't like.
 */
class MLSearchApiSolrService extends SearchApiSolrService {

  /**
   * Get supported features.
   */
  public function supportsFeature($feature) {
    if ($feature == 'search_api_spellcheck') {
      return TRUE;
    }
    else {
      return parent::supportsFeature($feature);
    }
  }

  /**
   * Get multifield names.
   */
  public function getMultiFields($index_name = NULL) {
    $lines = explode(PHP_EOL, $this->options['qtools_solrservice_custom']['multifields']);
    $mlfields = array();
    foreach ($lines as $line) {
      list($index, $fields) = explode('|', trim($line));
      if (!empty($index) && !empty($fields)) {
        foreach (explode(',', $fields) as $field) {
          $mlfields[$index][] = trim($field);
        }
      }
    }
    if (!empty($index_name)) {
      $result = !empty($mlfields[$index_name])
        ? $mlfields[$index_name]
        : array();
    }
    else {
      $result = $mlfields;
    }
    return $result;
  }

  /**
   * Get multifield conditions.
   *
   * Default condition is current site language.
   */
  public function getMultiFieldConditions(SearchApiQueryInterface $query) {
    global $language;

    $multifield_conditions = array();

    // Get mlfields list.
    $mlfields = $this->getMultiFields($query->getIndex()->machine_name);

    // Default condition is current language.
    foreach ($mlfields as $field_name) {
      $multifield_conditions[$field_name] = $language->language;
    }

    // Now send it to other modules for alter.
    $context = array(
      'service' => $this,
      'query' => $query,
    );
    drupal_alter('qtools_solrservice_multifield_conditions', $multifield_conditions, $context);
    return $multifield_conditions;
  }

  /**
   * Get Multifield values.
   */
  public function getMultiFieldValues(SearchApiIndex $index, $id, $key, $field) {

    $index_id = $index->machine_name;
    $fields = $this->getFieldNames($index);

    $entity_type = $index->item_type;
    $entity_id = $id;
    $field_name = $key;

    // Default value is translated values.
    if ($entity = current(entity_load($entity_type, array($entity_id)))) {

      // Create metawrapper.
      $wrapper = entity_metadata_wrapper($entity_type, $entity);

      // Iterate all languages.
      foreach (language_list() as $lang_id => $language) {
        $wrapper->language($lang_id);

        // Text fields have a bug when some of instance plain and some fileter.
        if ($field['type'] == 'text') {
          $name_part = explode(':', $field_name);
          if ((count($name_part) > 1) && (end($name_part) == 'value')) {
            array_pop($name_part);
            $field_name = implode(':', $name_part);
          }
        }
        $values = search_api_extract_fields($wrapper, array($field_name => array('type' => 'text')), array());
        $multifield_values[$lang_id] = $values[$field_name]['value'];
      }

    }

    // Now send it to other modules for alter.
    $context = array(
      'service' => $this,
      'index' => $index,
      'entity_type' => $entity_type,
      'entity_id' => $id,
      'field_name' => $key,
      'field' => $field,
    );
    drupal_alter('qtools_solrservice_multifield_values', $multifield_values, $context);
    return $multifield_values;
  }

  /**
   * Index items support multilingual.
   */
  public function indexItems(SearchApiIndex $index, array $items) {
    $documents = array();
    $ret = array();
    $index_id = $index->machine_name;
    $fields = $this->getFieldNames($index);
    $mlfields = $this->getMultiFields($index_id);

    foreach ($items as $id => $item) {
      try {
        $doc = new Apache_Solr_Document();
        $doc->setField('id', $this->createId($index_id, $id));
        $doc->setField('index_id', $index_id);
        $doc->setField('item_id', $id);

        foreach ($item as $key => $field) {
          if (!isset($fields[$key])) {
            throw new SearchApiException(t('Unknown field @field.', array('@field' => $key)));
          }
          $this->addIndexField($doc, $fields[$key], $field['value'], $field['type']);

          // Add multifields.
          if (in_array($key, $mlfields)) {
            $multi_values = $this->getMultiFieldValues($index, $id, $key, $field);
            foreach ($multi_values as $prefix => $value) {
              $this->addIndexField($doc, $fields[$key] . '_' . $prefix, $value, $field['type']);
            }
          }

        }

        $documents[] = $doc;
        $ret[] = $id;
      }
      catch (Exception $e) {
        watchdog_exception('search_api_solr', $e, "%type while indexing @type with ID @id: !message in %function (line %line of %file).", array('@type' => $index->item_type, '@id' => $id), WATCHDOG_WARNING);
      }
    }

    if (!$documents) {
      return array();
    }
    try {
      $this->connect();
      $response = $this->solr->addDocuments($documents);
      if ($response->getHttpStatus() == 200) {
        if (!empty($index->options['index_directly'])) {
          $this->scheduleCommit();
        }
        return $ret;
      }
      throw new SearchApiException(t('HTTP status @status: @msg.',
          array('@status' => $response->getHttpStatus(), '@msg' => $response->getHttpStatusMessage())));
    }
    catch (Exception $e) {
      watchdog_exception('search_api_solr', $e, "%type while indexing: !message in %function (line %line of %file).");
    }
    return array();
  }

  /**
   * Transforms a query filter into a flat array of Solr filter queries, using
   * the field names in $fields.
   */
  protected function createFilterQueries(SearchApiQueryFilterInterface $filter, array $solr_fields, array $fields) {
    $or = $filter->getConjunction() == 'OR';
    $fq = array();
    foreach ($filter->getFilters() as $f) {
      if (is_array($f)) {
        if (!isset($fields[$f[0]])) {
          throw new SearchApiException(t('Filter term on unknown or unindexed field @field.', array('@field' => $f[0])));
        }
        if ($f[1] !== '') {
          $field_name = $solr_fields[$f[0]];
          if (!empty($fields[$f[0]]['condition'])) {
            $field_name .= '_' . $fields[$f[0]]['condition'];
          }
          $fq[] = $this->createFilterQuery($field_name, $f[1], $f[2], $fields[$f[0]]);
        }
      }
      else {
        $q = $this->createFilterQueries($f, $solr_fields, $fields);
        if ($filter->getConjunction() != $f->getConjunction()) {
          // $or == TRUE means the nested filter has conjunction AND, and vice versa
          $sep = $or ? ' ' : ' OR ';
          $fq[] = count($q) == 1 ? reset($q) : '((' . implode(')' . $sep . '(', $q) . '))';
        }
        else {
          $fq = array_merge($fq, $q);
        }
      }
    }
    return ($or && count($fq) > 1) ? array('((' . implode(') OR (', $fq) . '))') : $fq;
  }

  /**
   * Helper method for creating the facet field parameters.
   */
  protected function getFacetParams(array $facets, array $fields, array &$fq = array()) {
    if (!$facets) {
      return array();
    }
    $facet_params['facet'] = 'true';
    $facet_params['facet.sort'] = 'count';
    $facet_params['facet.limit'] = 10;
    $facet_params['facet.mincount'] = 1;
    $facet_params['facet.missing'] = 'false';
    $taggedFields = array();
    foreach ($facets as $info) {
      if (empty($fields[$info['field']])) {
        continue;
      }
      // String fields have their own corresponding facet fields.
      $field = $fields[$info['field']];
      // Check for the "or" operator.
      if (isset($info['operator']) && $info['operator'] === 'or') {
        // Remember that filters for this field should be tagged.
        $escaped = SearchApiSolrConnection::escapeFieldName($fields[$info['field']]);
        $taggedFields[$escaped] = "{!tag=$escaped}";
        // Add the facet field.
        $facet_params['facet.field'][] = "{!ex=$escaped}$field";
      }
      else {
        // Add the facet field.
        $facet_params['facet.field'][] = $field;
      }
      // Set limit, unless it's the default.
      if ($info['limit'] != 10) {
        $facet_params["f.$field.facet.limit"] = $info['limit'] ? $info['limit'] : -1;
      }
      // Set mincount, unless it's the default.
      if ($info['min_count'] != 1) {
        $facet_params["f.$field.facet.mincount"] = $info['min_count'];
      }
      // Set missing, if specified.
      if ($info['missing']) {
        $facet_params["f.$field.facet.missing"] = 'true';
      }
    }
    // Tag filters of fields with "OR" facets.
    foreach ($taggedFields as $field => $tag) {
      $regex = '#(?<![^( ])' . preg_quote($field, '#') . ':#';
      foreach ($fq as $i => $filter) {
        // Solr can't handle two tags on the same filter, so we don't add two.
        // Another option here would even be to remove the other tag, too,
        // since we can be pretty sure that this filter does not originate from
        // a facet – however, wrong results would still be possible, and this is
        // definitely an edge case, so don't bother.
        if (preg_match($regex, $filter) && substr($filter, 0, 6) != '{!tag=') {
          $fq[$i] = $tag . $filter;
        }
      }
    }

    return $facet_params;
  }

  /**
   * Execute search allow for multilingual fields.
   */
  public function search(SearchApiQueryInterface $query) {
    $time_method_called = microtime(TRUE);
    // Reset request handler
    $this->request_handler = NULL;
    // Get field information
    $index = $query->getIndex();
    $fields = $this->getFieldNames($index);

    // Get mlconditions.
    $conditions = $this->getMultiFieldConditions($query);

    // Extract keys
    $keys = $query->getKeys();
    if (is_array($keys)) {
      $keys = $this->flattenKeys($keys);
    }

    // Set searched fields
    $options = $query->getOptions();
    $search_fields = $query->getFields();
    // Get the index fields to be able to retrieve boosts.
    $index_fields = $index->getFields();
    $qf = array();
    /*foreach ($search_fields as $f) {
      $boost = '';
      $boost = isset($index_fields[$f]['boost']) ? '^' . $index_fields[$f]['boost'] : '';
      $qf[] = $fields[$f] . $boost;
    }*/
    /** Multilingual boost/FullTextSearch start */
    foreach ($search_fields as $f) {
      $boost = '';
      $boost = isset($index_fields[$f]['boost']) ? '^' . $index_fields[$f]['boost'] : '';
      $field_name = $fields[$f];
      if (!empty($conditions[$f])) {
        $field_name .= '_' . $conditions[$f];
      }
      $qf[] = $field_name . $boost;
    }
    /** Multilingual boost/FullTextSearch end */

    // Extract filters
    /*$filter = $query->getFilter();
    $fq = $this->createFilterQueries($filter, $fields, $index->options['fields']);
    $fq[] = 'index_id:' . $index->machine_name;*/
    /** Multilingual filter start */
    $filter = $query->getFilter();
    $fields_options = $index->options['fields'];
    foreach ($conditions as $field_name => $condition) {
      $fields_options[$field_name]['condition'] = $condition;
    }
    $fq = $this->createFilterQueries($filter, $fields, $fields_options);
    $fq[] = 'index_id:' . $index->machine_name;
    /** Multilingual filter end */


    // Extract sort
    /*$sort = array();
    foreach ($query->getSort() as $f => $order) {
      $f = $fields[$f];
      if (substr($f, 0, 3) == 'ss_') {
        $f = 'sort_' . substr($f, 3);
      }
      $order = strtolower($order);
      $sort[] = "$f $order";
    }*/
    /** Multilingual sort start */
    $sort = array();
    foreach ($query->getSort() as $field_name => $order) {
      $f = $fields[$field_name];
      if (!empty($conditions[$field_name])) {
        $f .= '_' . $conditions[$field_name];
      }
      $order = strtolower($order);
      $sort[] = "$f $order";
    }
    /** Multilingual sort end */

    // Get facet fields
    /*$facets = $query->getOption('search_api_facets', array());
    $facet_params = $this->getFacetParams($facets, $fields, $fq);*/
    /** Multilingual facet start */
    $facets = $query->getOption('search_api_facets', array());
    foreach ($facets as &$facet) {
      if (!empty($conditions[$facet['field']])) {
        $facet['field'] .= '_' . $conditions[$facet['field']];
      }
    }
    $facet_params = $this->getFacetParams($facets, $fields, $fq);
    /** Multilingual facet end */

    // Handle highlighting
    $highlight_params = $this->getHighlightParams($query);

    // Handle More Like This query
    $mlt = $query->getOption('search_api_mlt');
    if ($mlt) {
      $mlt_params['qt'] = 'mlt';
      // The fields to look for similarities in.
      $mlt_fl = array();
      foreach($mlt['fields'] as $f) {
        $mlt_fl[] = $fields[$f];
        // For non-text fields, set minimum word length to 0.
        if (isset($index->options['fields'][$f]['type']) && !search_api_is_text_type($index->options['fields'][$f]['type'])) {
          $mlt_params['f.' . $fields[$f] . '.mlt.minwl'] = 0;
        }
      }
      $mlt_params['mlt.fl'] = implode(',', $mlt_fl);
      $keys = 'id:' . SearchApiSolrConnection::phrase($this->createId($index->machine_name, $mlt['id']));
    }

    // Set defaults
    if (!$keys) {
      $keys = NULL;
    }
    $offset = isset($options['offset']) ? $options['offset'] : 0;
    $limit = isset($options['limit']) ? $options['limit'] : 1000000;

    // Collect parameters
    $params = array(
      'fl' => 'item_id,score',
      'qf' => $qf,
      'fq' => $fq,
    );
    if (!empty($sort)) {
      $params['sort'] = implode(', ', $sort);
    }
    if (!empty($facet_params['facet.field'])) {
      $params += $facet_params;
    }
    if (!empty($highlight_params)) {
      $params += $highlight_params;
    }
    if (!empty($options['search_api_spellcheck'])) {
      $params['spellcheck'] = 'true';
    }
    if (!empty($mlt_params['mlt.fl'])) {
      $params += $mlt_params;
    }
    if (!empty($this->options['retrieve_data'])) {
      $params['fl'] = '*,score';
    }
    $call_args = array(
      'query'  => &$keys,
      'offset' => &$offset,
      'limit'  => &$limit,
      'params' => &$params,
    );
    if ($this->request_handler) {
      $this->setRequestHandler($this->request_handler, $call_args);
    }

    try {
      // Send search request
      $time_processing_done = microtime(TRUE);
      $this->connect();

      // Save sort order.
      $sort_old = !empty($call_args['params']['sort'])
        ? explode(',', $call_args['params']['sort'])
        : array();

      drupal_alter('search_api_solr_query', $call_args, $query);

      $sort_new = !empty($call_args['params']['sort'])
        ? explode(',', $call_args['params']['sort'])
        : array();

      $call_args['params']['sort'] = implode(',', array_unique(array_merge($sort_old, $sort_new)));
      $this->preQuery($call_args, $query);

      // Retrieve http method from server options.
      $http_method = !empty($this->options['http_method']) ? $this->options['http_method'] : Apache_Solr_Service::METHOD_POST;
      $response = $this->solr->search($keys, $offset, $limit, $params, $http_method);
      $time_query_done = microtime(TRUE);

      if ($response->getHttpStatus() != 200) {
        throw new SearchApiException(t('The Solr server responded with status code @status: @msg.',
            array('@status' => $response->getHttpStatus(), '@msg' => $response->getHttpStatusMessage())));
      }

      // Extract results
      $results = $this->extractResults($query, $response);

      // Extract facets
      if ($facets = $this->extractFacets($query, $response)) {
        $results['search_api_facets'] = $facets;
      }

      drupal_alter('search_api_solr_search_results', $results, $query, $response);
      $this->postQuery($results, $query, $response);

      // Compute performance
      $time_end = microtime(TRUE);
      $results['performance'] = array(
        'complete' => $time_end - $time_method_called,
        'preprocessing' => $time_processing_done - $time_method_called,
        'execution' => $time_query_done - $time_processing_done,
        'postprocessing' => $time_end - $time_query_done,
      );

      // Spellcheck.
      if (!empty($options['search_api_spellcheck'])) {
        $spellckeck = new SearchApiSpellcheck();
        if (!empty($results['raw']['spellcheck'])) {
          foreach ($results['raw']['spellcheck']->suggestions as $original => $suggestion) {
            $spellckeck->addSuggestion(new SearchApiSpellcheckSuggestion($original, $suggestion->suggestion[0]));
          }
        }
        $results['search_api_spellcheck'] = $spellckeck;
      }

      return $results;
    }
    catch (Exception $e) {
      throw new SearchApiException(t('An error occurred while trying to search with Solr: @msg.', array('@msg' => $e->getMessage())));
    }
  }

  /**
   * Extract results from a Solr response.
   * Saving raw responce and add grouping to the results.
   *
   * @param Apache_Solr_Response $response
   *   A response object from SolrPhpClient.
   *
   * @return array
   *   An array with two keys:
   *   - result count: The number of total results.
   *   - results: An array of search results, as specified by
   *     SearchApiQueryInterface::execute().
   */
  protected function extractResults(SearchApiQueryInterface $query, Apache_Solr_Response $response) {

    // Invoke original function.
    $results = parent::extractResults($query, $response);

    // Save raw responce in the results.
    $results['raw'] = array(
      'responce' => $response,
      'service'  => $this,
      'grouped'  => !empty($response->grouped) ? $response->grouped : NULL,
      'spellcheck'  => !empty($response->spellcheck) ? $response->spellcheck : NULL,
    );

    return $results;
  }

  /**
   * Configuration form.
   */
  public function configurationForm(array $form, array &$form_state) {

    // Get original form.
    $form = parent::configurationForm($form, $form_state);

    // Add our options.
    $options = $this->options + array(
      'qtools_solrservice_custom' => array(),
    );

    $form['qtools_solrservice_custom'] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => t('Multi fields'),
      '#collapsible' => TRUE,
    );
    $form['qtools_solrservice_custom']['multifields'] = array(
      '#type' => 'textarea',
      '#title' => t('Multi* fields'),
      '#description' => t('Specify which fields are multifields (field names separated by comma).'),
      '#default_value' => $options['qtools_solrservice_custom']['multifields'],
      '#required' => FALSE,
    );

    return $form;
  }
}