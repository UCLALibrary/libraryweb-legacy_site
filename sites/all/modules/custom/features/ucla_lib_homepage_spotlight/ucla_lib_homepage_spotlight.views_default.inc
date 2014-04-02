<?php
/**
 * @file
 * ucla_lib_homepage_spotlight.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function ucla_lib_homepage_spotlight_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_feature';
  $view->description = 'This view creates the site\'s homepage. It features one randomly-chosen image from the Homepage Features content type';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage (Random Feature)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'UCLA Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_spotlight_link' => 0,
    'field_spotlight' => 0,
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 'title',
    'field_spotlight_link' => 0,
    'field_spotlight' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '4000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Spotlight link */
  $handler->display->display_options['fields']['field_spotlight_link']['id'] = 'field_spotlight_link';
  $handler->display->display_options['fields']['field_spotlight_link']['table'] = 'field_data_field_spotlight_link';
  $handler->display->display_options['fields']['field_spotlight_link']['field'] = 'field_spotlight_link';
  $handler->display->display_options['fields']['field_spotlight_link']['label'] = '';
  $handler->display->display_options['fields']['field_spotlight_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spotlight_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_spotlight_link']['type'] = 'plain';
  $handler->display->display_options['fields']['field_spotlight_link']['group_column'] = 'url';
  /* Field: Content: spotlight */
  $handler->display->display_options['fields']['field_spotlight']['id'] = 'field_spotlight';
  $handler->display->display_options['fields']['field_spotlight']['table'] = 'field_data_field_spotlight';
  $handler->display->display_options['fields']['field_spotlight']['field'] = 'field_spotlight';
  $handler->display->display_options['fields']['field_spotlight']['label'] = '';
  $handler->display->display_options['fields']['field_spotlight']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_spotlight']['alter']['path'] = '[field_spotlight_link]';
  $handler->display->display_options['fields']['field_spotlight']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_spotlight']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_spotlight']['group_column'] = 'fid';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'homepage_feature' => 'homepage_feature',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = '0';

  /* Display: Homepage random feature */
  $handler = $view->new_display('page', 'Homepage random feature', 'page');
  $handler->display->display_options['display_description'] = 'This views page is the homepage of the website. It displays one random "Homepage Feature" node';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_spotlight_link' => 0,
    'field_spotlight' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_spotlight_link' => 0,
    'field_spotlight' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_hover'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '4000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'all' => 'all',
    'article' => 'article',
    'page' => 'page',
    'data' => 'data',
    'homepage_feature' => 'homepage_feature',
    'webform' => 'webform',
    'page_master' => 'page_master',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = '0';
  $handler->display->display_options['path'] = 'homepage';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Spotlight link */
  $handler->display->display_options['fields']['field_spotlight_link']['id'] = 'field_spotlight_link';
  $handler->display->display_options['fields']['field_spotlight_link']['table'] = 'field_data_field_spotlight_link';
  $handler->display->display_options['fields']['field_spotlight_link']['field'] = 'field_spotlight_link';
  $handler->display->display_options['fields']['field_spotlight_link']['label'] = '';
  $handler->display->display_options['fields']['field_spotlight_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_spotlight_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight_link']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_spotlight_link']['type'] = 'plain';
  $handler->display->display_options['fields']['field_spotlight_link']['group_column'] = 'url';
  /* Field: Content: spotlight */
  $handler->display->display_options['fields']['field_spotlight']['id'] = 'field_spotlight';
  $handler->display->display_options['fields']['field_spotlight']['table'] = 'field_data_field_spotlight';
  $handler->display->display_options['fields']['field_spotlight']['field'] = 'field_spotlight';
  $handler->display->display_options['fields']['field_spotlight']['label'] = '';
  $handler->display->display_options['fields']['field_spotlight']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_spotlight']['alter']['path'] = '[field_spotlight_link]';
  $handler->display->display_options['fields']['field_spotlight']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_spotlight']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_spotlight']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_spotlight']['group_column'] = 'fid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_spotlight_link]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Spotlight Description */
  $handler->display->display_options['fields']['field_spotlight_description']['id'] = 'field_spotlight_description';
  $handler->display->display_options['fields']['field_spotlight_description']['table'] = 'field_data_field_spotlight_description';
  $handler->display->display_options['fields']['field_spotlight_description']['field'] = 'field_spotlight_description';
  $handler->display->display_options['fields']['field_spotlight_description']['label'] = '';
  $handler->display->display_options['fields']['field_spotlight_description']['alter']['max_length'] = '140';
  $handler->display->display_options['fields']['field_spotlight_description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_spotlight_description']['element_label_colon'] = FALSE;
  $export['homepage_feature'] = $view;

  return $export;
}
