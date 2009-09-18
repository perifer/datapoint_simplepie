<?php
function datapoint_simplepie_vertex_schema() {
  //GTODO: Some indexes please?
  return array(
    'description' => t('Feed item information parsed by SimplePie'),
    'fields'      => array(
      'description' => array(
        'description' => t('The content of the feed item.'),
        'type'        => 'text',
        'size'        => 'medium',
        'not null'    => FALSE,
        'default'     => '',
      ),
      'url'         => array(
        'description' => t('The url for the feed item.'),
        'type'        => 'varchar',
        'length'      => 255,
        'not null'    => TRUE,
        'default'     => '',
      ),
      'published'   => array(
        'description' => t('The Unix timestamp for when the item was published.'),
        'type'        => 'int',
        'not null'    => FALSE,
        'default'     => 0,
      ),
      'iterator'    => array(
        'description' => t('The iterator used.'),
        'type'        => 'varchar',
        'length'      => 255,
        'not null'    => TRUE,
        'default'     => '',
      ),
      'statevalue'  => array(
        'description' => t('The value of the state of the iterator returned.'),
        'type'        => 'varchar',
        'length'      => 255,
        'not null'    => TRUE,
        'default'     => '',
      ),
    ),
  );
}