<?php
/**
 * @file
 * Defines routines for searching various custom targets.
 */

/**
 * Route searches to appropriate target handler.
 */
function ucla_search_route_search($search_info) {
  // Docs say drupal_goto is for "local" URLs but works fine with absolute off-site URLs too
  // ... is there a better choice? Maybe drupal_http_request for GET/POST consistency?

  switch ($search_info['search_target']) {
    case "catalog":
      ucla_search_catalog($search_info);
      break;
    case "reserves":
      ucla_search_reserves($search_info);
      break;
    case "articles":
      serial_solutions_360($search_info);
      break;
    case "database":
      ucla_search_database($search_info);
      break;
    case "guides":
      ucla_search_guides($search_info);
      break;
    case "melvyl":
      ucla_search_melvyl($search_info);
      break;
    case "oac":
      ucla_search_oac($search_info);
      break;
    case "sfx":
      ucla_search_sfx($search_info);
      break;
    case "site":
      ucla_search_site($search_info);
      break;
    default:
      // TODO: change this to write error to log
      drupal_set_message("WHAT???");
  }
}

function ucla_search_catalog($search_info) {
//$target_url = 'http://catalog.library.ucla.edu/cgi-bin/Pwebrecon.cgi?DB=local&Search_Arg=';
  $target_url = 'http://catalog.library.ucla.edu/vwebv/search?searchArg=';
    $extra_params = '&searchCode=';
	//$extra_params = '&Search_Code=';
	  if ($search_info['search_code']) {
	      $extra_params .= $search_info['search_code'];
		    } else {
			    $extra_params .= 'GKEY^';
				  }
				    $extra_params .= '&searchType=1';
					//$extra_params .= '&SL=None&CNT=50&HIST=1';
					  // Replace space with plus, but do NOT url encode the terms
					    $target_url .= str_replace(' ', '+', $search_info['search_terms']);
						  // Extra params must be after the search terms in the URL
						    $target_url .= $extra_params;
							  drupal_goto($path = $target_url);
							  }

function ucla_search_reserves($search_info) {

  if( $search_info['search_inst'] == 'Any' ){
    $search_inst = '';
  } else {
    $search_inst = rawurlencode( $search_info['search_inst'] );
  }
  if( $search_info['search_dept'] == 'Any' ){
    $search_dept = '';
  } else {
    $search_dept = rawurlencode( $search_info['search_dept'] );
  }
  if( $search_info['search_crse'] == 'Any' ){
    $search_crse = '';
  } else {
    $search_crse = rawurlencode( $search_info['search_crse'] );
  }

  $base_url = 'http://catalog.library.ucla.edu/cgi-bin/Pwebrecon.cgi';
  $target_url = 'http://catalog.library.ucla.edu/cgi-bin/Pwebrecon.cgi?DB=local&INST=';
  $target_url .= $search_inst;
  $target_url .= '&DEPT=';
  $target_url .= $search_dept;
  $target_url .= '&CRSE=';
  $target_url .= $search_crse;
  $target_url .= '&CNT=50';
  drupal_goto($path = $target_url);
}

function serial_solutions_360($search_info) {
  $target_url = 'http://mb5hp5vz2c.cs.serialssolutions.com/results';
  $extra_params = '?SS_LibHash=MB5HP5VZ2C&locale=en-us&action=start&dbIDList=&term=';
  $extra_params .= str_replace(' ', '+', $search_info['search_terms']);
  $extra_params .= '&field0=';
  $extra_params .= $search_info['search_code'];
  $extra_params .= '&boolop1=and&term1=&field1=keyword&boolop2=and&term2=&field2=keyword&boolop4=And&term4=&field4=';
  $extra_params .= $search_info['search_year'];
  $extra_params .= str_replace(' ', '&catID=', $search_info['search_categories']);
  $target_url .= $extra_params;
  drupal_goto($path = $target_url);
}

function ucla_search_database($search_info) {
/*****
  // 2013-08-30 akohler: having trouble getting POST to work, but
  // keeping this code as a sample in case other forms require POST.
  $target_url = 'http://unitdev.library.ucla.edu/search/databases-title-result-AK.cfm';
  // This currently requires an HTTP POST, so can't use drupal_goto which is GET only
  $headers = array('Content-Type' => 'application/x-www-form-urlencoded'); // required for POST
  $data = array(
    'FORM.keyword' => $search_info['search_terms'],
    'FORM.method' => 'contains', // contains or starts // TEMP TEST
  );
  watchdog('SEARCH_POST', http_build_query($data));
  $response = drupal_http_request($target_url, $headers, 'POST', http_build_query($data));
  watchdog('SEARCH_RESPONSE', $response->request . ' *** ' . $response->redirect_code);
*****/

  $target_url = 'http://unitproj.library.ucla.edu/search/databases-title-result.cfm';
  // Replace space with plus, but do NOT url encode the terms
  $target_url .= '?keyword=' . str_replace(' ', '+', $search_info['search_terms']);
  if ($search_info['search_type']) {
    $target_url .= '&method=' . map_database_search_type($search_info['search_type']);
  }
  drupal_goto($path = $target_url);
}

function ucla_search_guides($search_info) {
  $target_url = 'http://guides.library.ucla.edu/search.php?iid=261&c=0&search=';
  // Replace space with plus, but do NOT url encode the terms
  $target_url .= str_replace(' ', '+', $search_info['search_terms']);
  drupal_goto($path = $target_url);
}

function ucla_search_melvyl($search_info) {
  $target_url = 'http://ucla.worldcat.org/search?qt=wc_org_ucla&scope=1&q=';
  // Don't replace space with plus - URL-encode as-is
  $target_url .= drupal_encode_path($search_info['search_terms']);
  drupal_goto($path = $target_url);
}

function ucla_search_oac($search_info) {
  // Online Archive of California
  $target_url = 'http://www.oac.cdlib.org/search?query=';
  // Replace space with plus, but do NOT url encode the terms
  $target_url .= str_replace(' ', '+', $search_info['search_terms']);
  drupal_goto($path = $target_url);
}

function ucla_search_sfx($search_info) {
  $target_url = 'http://ucelinks.cdlib.org:8888/sfx_ucla/az/default';
  $extra_params = '?param_perform_value=searchTitle&param_jumpToPage_value=&param_type_value=textSearch&param_chinese_checkbox_active=1&param_chinese_checkbox_value=0';
  $target_url .= $extra_params;
  // Replace space with plus, but do NOT url encode the terms
  $target_url .= '&param_pattern_value=' . str_replace(' ', '+', $search_info['search_terms']);
  if ($search_info['search_type']) {
    $target_url .= '&param_textSearchType_value=' . map_sfx_search_type($search_info['search_type']);
  }
  drupal_goto($path = $target_url);
}

function ucla_search_site($search_info) {
  $target_url = 'search/node/' . trim($search_info['search_terms']);
  drupal_goto($path = $target_url);
}

// Utility functions

function map_database_search_type($ucla_value) {
  // ucla form value => databases required value
  $mappings = array (
    'contains' => 'contains',
    'starts' => 'starts',
  );
  return $mappings[$ucla_value];
}

function map_sfx_search_type($ucla_value) {
  // ucla form value => sfx required value
  $mappings = array (
    'within' => 'contains',
    'exact' => 'exactMatch',
    'starts' => 'startsWith',
  );
  return $mappings[$ucla_value];
}
