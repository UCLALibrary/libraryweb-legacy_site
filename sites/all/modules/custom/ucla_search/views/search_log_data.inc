<?php
// Created view using GUI, exported code is below
$view = new view();
$view->name = 'search_log_data';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'ucla_search_log';
$view->human_name = 'Search Log Data';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Search Log Data';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  2 => '2',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'search_date' => 'search_date',
  'search_target' => 'search_target',
  'search_terms' => 'search_terms',
  'browser_ip' => 'browser_ip',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'search_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'search_target' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'search_terms' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'browser_ip' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'Example Search: Fill out both boxes and keep in mind the log is tracking each day starting at Midnight 00:00:00. If you want to see the search log for one day, March 20, 2013, you would fill the form out as follows to make sure you gather the entire day: 
<strong>Search Date</strong> 2013-03-20 
<strong>And</strong> 2013-03-21 

To export data to Excel, click the small orange XLS button below the data. Excel may show a warning message about file formats; this is OK, click "Yes" to show the data in Excel. You may want to use Excel\'s "Save As..." function to re-save the file in a real Excel format. ';
$handler->display->display_options['header']['area']['format'] = 'filtered_html';
/* Field: Search data: Search Date */
$handler->display->display_options['fields']['search_date']['id'] = 'search_date';
$handler->display->display_options['fields']['search_date']['table'] = 'ucla_search_log';
$handler->display->display_options['fields']['search_date']['field'] = 'search_date';
$handler->display->display_options['fields']['search_date']['date_format'] = 'custom';
$handler->display->display_options['fields']['search_date']['custom_date_format'] = 'Y-m-d H:i:s';
/* Field: Search data: Search Target */
$handler->display->display_options['fields']['search_target']['id'] = 'search_target';
$handler->display->display_options['fields']['search_target']['table'] = 'ucla_search_log';
$handler->display->display_options['fields']['search_target']['field'] = 'search_target';
/* Field: Search data: Search Terms */
$handler->display->display_options['fields']['search_terms']['id'] = 'search_terms';
$handler->display->display_options['fields']['search_terms']['table'] = 'ucla_search_log';
$handler->display->display_options['fields']['search_terms']['field'] = 'search_terms';
/* Field: Search data: Browser IP */
$handler->display->display_options['fields']['browser_ip']['id'] = 'browser_ip';
$handler->display->display_options['fields']['browser_ip']['table'] = 'ucla_search_log';
$handler->display->display_options['fields']['browser_ip']['field'] = 'browser_ip';
/* Field: Search data: Search Form */
$handler->display->display_options['fields']['search_form']['id'] = 'search_form';
$handler->display->display_options['fields']['search_form']['table'] = 'ucla_search_log';
$handler->display->display_options['fields']['search_form']['field'] = 'search_form';
/* Filter criterion: Search data: Search Date */
$handler->display->display_options['filters']['search_date']['id'] = 'search_date';
$handler->display->display_options['filters']['search_date']['table'] = 'ucla_search_log';
$handler->display->display_options['filters']['search_date']['field'] = 'search_date';
$handler->display->display_options['filters']['search_date']['operator'] = 'between';
$handler->display->display_options['filters']['search_date']['exposed'] = TRUE;
$handler->display->display_options['filters']['search_date']['expose']['operator_id'] = 'search_date_op';
$handler->display->display_options['filters']['search_date']['expose']['label'] = 'Search Date';
$handler->display->display_options['filters']['search_date']['expose']['description'] = 'Search dates, in YYYY-MM-DD format';
$handler->display->display_options['filters']['search_date']['expose']['operator'] = 'search_date_op';
$handler->display->display_options['filters']['search_date']['expose']['identifier'] = 'search_date';
$handler->display->display_options['filters']['search_date']['expose']['remember'] = TRUE;
$handler->display->display_options['filters']['search_date']['expose']['remember_roles'] = array(
  2 => 0,
  1 => 0,
  3 => 0,
);
/* Filter criterion: Search data: Search Target */
$handler->display->display_options['filters']['search_target']['id'] = 'search_target';
$handler->display->display_options['filters']['search_target']['table'] = 'ucla_search_log';
$handler->display->display_options['filters']['search_target']['field'] = 'search_target';
$handler->display->display_options['filters']['search_target']['exposed'] = TRUE;
$handler->display->display_options['filters']['search_target']['expose']['operator_id'] = '';
$handler->display->display_options['filters']['search_target']['expose']['label'] = 'Search Target';
$handler->display->display_options['filters']['search_target']['expose']['description'] = 'Target';
$handler->display->display_options['filters']['search_target']['expose']['operator'] = 'search_target_op';
$handler->display->display_options['filters']['search_target']['expose']['identifier'] = 'search_target';
$handler->display->display_options['filters']['search_target']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
);
$handler->display->display_options['filters']['search_target']['is_grouped'] = TRUE;
$handler->display->display_options['filters']['search_target']['group_info']['label'] = 'Search Target';
$handler->display->display_options['filters']['search_target']['group_info']['identifier'] = 'search_target';
$handler->display->display_options['filters']['search_target']['group_info']['group_items'] = array(
  1 => array(
    'title' => 'Site',
    'operator' => '=',
    'value' => 'site',
  ),
  2 => array(
    'title' => 'Catalog',
    'operator' => '=',
    'value' => 'catalog',
  ),
  3 => array(
    'title' => 'LibGuides',
    'operator' => '=',
    'value' => 'guides',
  ),
  4 => array(
    'title' => 'Melvyl',
    'operator' => '=',
    'value' => 'melvyl',
  ),
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['path'] = 'search-log-data';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Search log data';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['path'] = 'search-log-data/export';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'default' => 0,
);
// End of exported code

$views[$view->name] = $view;
