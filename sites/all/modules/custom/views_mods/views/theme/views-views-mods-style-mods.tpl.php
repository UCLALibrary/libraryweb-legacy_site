<?php
/**
 * @file views-views-mods-style-mods.tpl.php
 * Default template for the Views MODS style plugin using the MODS schema
 *
 * Variables
 * - $view: The View object.
 * - $rows: Array of row objects as rendered by _views_xml_render_fields
 * - $entries Array of Atom entries as created by template_preprocess_views_views_xml_style_atom
 *
 * @ingroup views_templates
 */

global $base_url;
$content_type = ($options['content_type'] == 'default') ? 'application/mods+xml' : $options['content_type'];
$xml = '<?xml version="1.0" encoding="UTF-8" ?>' . "\n";

// loop through the entries and create mods elements
foreach($entries as $entry) {
  $xml .= '<mods xmlns:xlink="http://www.w3.org/1999/xlink" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.loc.gov/mods/v3" version="3.4" xsi:schemaLocation="http://www.loc.gov/mods/v3 http://www.loc.gov/standards/mods/v3/mods-3-4.xsd">' . "\n";    

  // loop throught he fields and create elements with attributs and content 
  foreach ($entry as $fields) {

    // set $el to the appropriate tag name, and assign it to the start and end tags
    $el = $fields['label'];
    $start_tag = $el;
    $end_tag = $el; 

    // add an attribute to certain tags
    if ($el == 'corporate') {
      $start_tag = 'name type="corporate"';
      $end_tag = 'name';
    }
    elseif ($el == 'dataformat') {
      $start_tag = 'note type="system details"';
      $notes = explode(',', $fields['content']);
      $fields['content'] = t('data/file formats: @notes', array('@notes' => $fields['content']));
      $end_tag = 'note';
    }
    elseif ($el == 'dateIssuedStart') {
      $start_tag = 'dateIssued point="start" encoding="w3cdtf"';
      $end_tag = 'dateIssued';
    }
    elseif ($el == 'dateIssuedStop') {
      $start_tag = 'dateIssued point="end" encoding="w3cdtf"';
      $end_tag = 'dateIssued';
    }

    // At this point, content could be a string or array.
    $v = $fields['content'];


    // build the element
    $xml .= "  <$start_tag>";
    if (is_array($v)) {
      foreach($v as $i => $j) {
        $xml .= ($options['escape_as_CDATA'] == 'yes') ? "\n    <![CDATA[$j]]>\n" : "$j";
      }
    }
    else
      $xml .= ($options['escape_as_CDATA'] == 'yes') ? "<![CDATA[$v]]>" : "$v";
    $xml .= "</$end_tag>\n";
  }

  $xml .= "</mods>\n";
}

// If we are inside Views live preview, escape output
if ($view->override_path) {
  print htmlspecialchars($xml);
}
// if we're in Views API mode
else if ($options['using_views_api_mode']) {     // We're in Views API mode.
  print $xml;
}
else {
  drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
  print $xml;
  exit;
}
