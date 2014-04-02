<?php

/**
 * @file
 * Views integration and data for the ucla_search module.
 */

/**
 * Implements hook_views_data()
 * Defines data elements so they can be used in Views
 */
function ucla_search_views_data() {
  $data = array();
  $data['ucla_search_log']['table']['group'] = t('Search data');

  // This isn't really Drupal data, so it needs to be a base table for views:
  //   can't be linked to from some other base table
  // Supposedly 'field' must be a single-field primary key (for joins), but
  //   this table has a compound primary key.
  // Since we won't be joining to other tables, try just the most distinct column....
  $data['ucla_search_log']['table']['base'] = array(
    'field' => 'search_date', // alleged primary key
    'title' => t('Search Data'), // for Table (in the "Show" drop-down when creating view)
    'help' => t('Date and time of search'),
    'weight' => -10  // All examples use this....
  );

  // search_date column
  $data['ucla_search_log']['search_date'] = array(
    'title' => t('Search Date'), 
    'help' => t('Date and time of search'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'allow empty' => TRUE,
    ),
  );

  // search_target column
  $data['ucla_search_log']['search_target'] = array(
    'title' => t('Search Target'),
    'help' => t('Target searched'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_equality',
      'allow empty' => TRUE,
    ),
  );

  // search_terms column
  $data['ucla_search_log']['search_terms'] = array(
    'title' => t('Search Terms'),
    'help' => t('Search terms'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  // browser_ip column
  $data['ucla_search_log']['browser_ip'] = array(
    'title' => t('Browser IP'),
    'help' => t('Browser IP address'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  // search_form column
  $data['ucla_search_log']['search_form'] = array(
    'title' => t('Search Form'),
    'help' => t('Form which submitted the search'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
  );

  return $data;
}

/**
 * Implements hook_views_default_views()
 */
function ucla_search_views_default_views() {
  $path = './' . drupal_get_path('module', 'ucla_search') . '/views/*.inc';
  $views = array();
  foreach (glob($path) as $views_filename) {
    require_once($views_filename);
  }
  return $views;
}

