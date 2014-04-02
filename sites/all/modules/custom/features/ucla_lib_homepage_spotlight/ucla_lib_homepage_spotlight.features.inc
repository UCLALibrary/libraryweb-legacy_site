<?php
/**
 * @file
 * ucla_lib_homepage_spotlight.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ucla_lib_homepage_spotlight_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ucla_lib_homepage_spotlight_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function ucla_lib_homepage_spotlight_node_info() {
  $items = array(
    'homepage_feature' => array(
      'name' => t('Homepage feature'),
      'base' => 'node_content',
      'description' => t('Customized home page elements'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
