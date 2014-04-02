<?php
/**
 * @file
 * Defines routines for logging search information.
 */

/**
 * Logs search info to database.
 */
function ucla_search_log_search($search_info) {
  // Only certain elements are logged
  $data = array (
    'search_target' => $search_info['search_target'],
    'search_terms' => $search_info['search_terms'],
    'search_date' => $search_info['search_date'],
    'browser_ip' => $search_info['browser_ip'],
    'search_form' => $search_info['search_form'],
  );
  db_insert('ucla_search_log')->fields($data)->execute();
}

