<?php
/**
 * @file
 * View template to render view fields as MODS.
 *
 * - $view: The view in use.
 * - $rows: Array of row objects as rendered by _views_json_render_fields
 * - $attachment: not used currently
 * - $options: The options for the style passed in from the UI.
 *
 * @ingroup views_templates
 * @see views_mods.views.inc
 */

/**
 * Template preprocess for the Mods format
 * @param $vars
 * @return unknown_type
 */
function template_preprocess_views_views_mods_style_mods(&$vars) {
  global $base_url;
  $view = $vars["view"];
  $rows = $vars["rows"];
  $options = $vars["options"];
  $link = $view->display_handler->get_path();
  $url_options = array('absolute' => TRUE);
  if (!empty($view->exposed_raw_input)) {
    $url_options['query'] = $view->exposed_raw_input;
  }
  $base = $view->base_table;
  $root = "mods";
  $plaintext_output = $options["plaintext_output"];
  $vars["content_type"] = ($options['content_type'] == 'default') ? 'application/mods+xml' : $options['content_type'];
  $header  = $options["header"];
  if (!$header) {
    $vars["title"] = check_plain(($view->get_title() ? $view->get_title(): $view->name));
    $vars["id"] = check_url($view->get_url());
    $vars["updated"] = format_date(time(), 'custom', DATE_ATOM);
    if ($options["author"]) $vars["author"] = _views_mods_format_author($options["author"]);
    $vars['link'] = check_url(url($view->display_handler->get_path(), $url_options));
  }
  else {
    $vars["header"] = $header;
  }
  $entries = array();
  foreach ($rows as $row) {
    $entry = array();
    foreach ($row as $field) {
      if ($options["field_output"] == "normal") {
        if ($field->label)
          $label = $plaintext_output ? check_plain(html_entity_decode(strip_tags($field->label))) : $field->label;
        else  $label = $plaintext_output ? check_plain(html_entity_decode(strip_tags($field->id))) : $field->id;
        if (!$field->is_multiple)
          $content = $plaintext_output ? check_plain(html_entity_decode(strip_tags($field->content))) : $field->content;
        else {
          $content = array();
          foreach ($field->content as $n => $oc) $content[$n] = $plaintext_output ? check_plain(html_entity_decode(strip_tags($oc))) : $oc;
        }
      }
      elseif ($options["field_output"] == "raw") {
        $label = $plaintext_output ? check_plain(html_entity_decode(strip_tags($field->id))) : $field->id;
        if (!$field->is_multiple)
          $content = $plaintext_output ? check_plain(html_entity_decode(strip_tags($field->content))) : $field->raw;
        else {
          $content = array();
          foreach ($field->raw as $n => $oc) $content[$n] = $plaintext_output ? check_plain(html_entity_decode(strip_tags($oc))) : $oc;
        }
      }
      $label = _views_mods_strip_illegal_xml_name_chars(html_entity_decode(check_plain(strip_tags($label))));
      // if (($options["skip_empty_fields"] == TRUE) && (is_null($content) || $content === "")) continue;
      
      if (empty($content) && !empty($field->content)) {
        $content = decode_entities(strip_tags($field->content));
        $content = _views_mods_strip_illegal_xml_attribute_value_chars($content);
      }
      if (stristr($content, 'Institution:')) {
        $inst_namePart = explode('Department:', $content);
        $dept_namePart = 'Department: ' . trim(preg_replace('/\s+/', ' ', $inst_namePart[1]), chr(0xC2).chr(0xA0).' \n\r');
        $inst_namePart = explode(':', $inst_namePart[0]);
        $inst_namePart = 'Institution: ' . trim(preg_replace('/\s+/', ' ', $inst_namePart[1]), chr(0xC2).chr(0xA0).' \n\r');
        $content = $inst_namePart . '|namePart;;' . $dept_namePart . '|namePart;;Institution and Department|roleTerm';
      }
      
      $parents = array(
        'roleTerm' => 'role',
      );
      $nested_labels = array (
        'titleInfo' => TRUE,
        'name' => TRUE,
        'corporate' => TRUE,
        'subject' => TRUE,
        'recordInfo' => TRUE,
        'originInfo' => TRUE,
        'location' => TRUE,
      );
      $explode_csv = array (
        'topic' => TRUE,
      );
      if(!empty($nested_labels[$label])){
        $nested_content = '';
        $children = explode(';;',$content);
        if (is_array($children)){
          foreach($children as $child){
            $child_content = '';
            $parts = explode('|',$child);
            $child_field = $parts[0];
            $child_field_tag = $parts[1];
            if(!empty($explode_csv[$child_field_tag])){
              $grandchildren = explode(',',$child_field);
              $child_content .= "\n";
              foreach($grandchildren as $grandchild){
                 $child_content .= "    <$child_field_tag>" . trim($grandchild) . "</$child_field_tag>\n";
              }
              $child_content = rtrim($child_content);
            } else {
              $child_content = "\n    <$child_field_tag>" . $child_field . "</$child_field_tag>";
            }
            if(array_key_exists($child_field_tag, $parents)){
              $child_content = "\n    <" . $parents[$child_field_tag] . ">\n      " . trim($child_content) . "\n    </" . $parents[$child_field_tag] . ">";
            }
            $nested_content .= $child_content;
          }
        }
        $content = $nested_content . "\n  ";
      }
      // Otherwise just use the $label and $content as element name and value
      $entry[] = array('label' => $label, 'content' => $content);
    } //for
    
    $entries[] = $entry;

  }//for

  $vars["entries"] = $entries;
}
