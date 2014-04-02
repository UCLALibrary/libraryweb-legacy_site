<?php
/**
 * @file
 * Views style plugins to render nodes in the MODS data format.
 *
 * @see views_plugin_style_mods.inc
 * @ingroup views_plugins
 */

/**
 * Implements hook_views_plugins().
 */
function views_mods_views_plugins() {
  $formats = views_mods_views_formats();
  $additional_themes = array();
  foreach ($formats as $format => $description) {
    $additional_themes['views_views_mods_style_' . $format] = 'style';
  }

  $path = drupal_get_path('module', 'views_mods') . '/views';
  return array(
    'module' => 'views_mods',
    'style' => array(
      'views_mods_style' => array(
        'title'           => t('MODS data document'),
        'path'            => $path . '/plugins',
        'help'            => t('Display a view as an MODS document.'),
        'handler'         => 'views_plugin_style_mods',
        'theme'           => 'views_views_mods_style',
        'theme file'      => 'views_views_mods_style.theme.inc',
        'theme path'      => $path . '/theme',
        'additional themes' => $additional_themes,
        'uses row plugin' => FALSE,
        'uses fields'     => TRUE,
        'uses options'    => TRUE,
        'type'            => 'normal',
        'help_topic'      => 'style-mods',
        'even empty'      => TRUE,
      ),
    ),
  );
}

/**
 * All recognised MODS output formats
 */
function views_mods_views_formats() {
  return module_invoke_all('views_mods_formats');
}

/**
 * Implements hook_views_mods_formats().
 */
function views_mods_views_mods_formats() {
  $formats = array(
    'mods' => t('MODS XML'),
    'raw' => t('Raw XML')
  );
  return $formats;
}
