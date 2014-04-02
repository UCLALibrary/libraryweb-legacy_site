<?php
/**
 * @file views-views-mods-style-raw.tpl.php
 * Default template for the Views XML style plugin using the raw schema
 *
 * Variables
 * - $view: The View object.
 * - $rows: Array of row objects as rendered by _views_xml_render_fields
 *
 * @ingroup views_templates
 * @see views_views_mods_style.theme.inc
 */
// If we are inside Views live preview, escape output
if (isset($view->override_path)) {
  print htmlspecialchars($xml);
}
// if we're in Views API mode
elseif ($options['using_views_api_mode']) {
  print $xml;
}
else {
  drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
  print $xml;
  exit;
}
