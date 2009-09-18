<?php
// $Id$

/**
 * @file
 *
 * Provide views data and handlers for the datapoint simplepie
 */

/**
 * Implementation of hook_views_data()
 */
function datapoint_simplepie_views_data() {
  $data = array();

  $data['datapoint_simplepie_vertex']['table']['group']  = t('Datapoint');

  $data['datapoint_simplepie_vertex']['url'] = array(
    'title' => t('URL'),
    'help' => t('The URL of the datapoint vertex.'),
    'field' => array(
      'handler' => 'views_handler_field_url',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['datapoint_simplepie_vertex']['name_url'] = array(
    'real field' => 'url',
    'title' => t('Linked Name'),
    'help' => t('The name of the datapoint linked to the external URL.'),
    'field' => array(
      'handler' => 'views_handler_field_datapoint_simplepie_link_name',
     ),
  );

  $data['datapoint_simplepie_vertex']['iterator'] = array(
    'title' => t('Iterator'),
    'help' => t('Possibly the iterator of the datapoint vertex.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['datapoint_simplepie_vertex']['statevalue'] = array(
    'title' => t('Statevalue'),
    'help' => t('Possibly the statevalue of the datapoint vertex.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['datapoint_simplepie_vertex']['published'] = array(
    'title' => t('Published'),
    'help' => t('When the feed item states that it is published.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_data_alter().
 */
function datapoint_simplepie_views_data_alter(&$data) {
  $data['datapoint']['datapoint_simplepie_vertex'] = array(
    'group' => t('Datapoint'),
    'title' => t('Datapoint Simplepie'),
    'help' => t('Include Datapoint Simplepie data'),
    'relationship' => array(
      'base' => 'datapoint_simplepie_vertex',
      'base field' => 'vid',
      'relationship field' => 'vid',
      'datapoint source type' => 'feedsimplepie',
      'handler' => 'views_handler_relationship_datapoint_vertex',
      'label' => t('Datapoint Simplepie data'),
    ),
  );
}

/**
 * Implementation of hook_views_handlers() to register all of the basic handlers
 * views uses.
 */
function datapoint_simplepie_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'datapoint_simplepie') . '/includes',
    ),
    'handlers' => array(
      // fields
      'views_handler_field_datapoint_simplepie_link_name' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}