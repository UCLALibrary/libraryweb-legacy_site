<?php 

function ucla_library_preprocess_page(&$vars) {

 $vars['node_page_master'] = FALSE;
if(isset($vars['node'])){
  $node = $vars['node'];
  if($node->type == 'page_master') {
     $vars['node_page_master'] = TRUE;
  }
 }
}

function ucla_library_preprocess_node(&$vars) {
  
 if(isset($vars['content']['field_image450x225']) || isset($vars['content']['field_image150x225'])|| isset($vars['content']['field_image300x225'])){
   $vars['content']['print_links']['#prefix'] = '<span class="print-link with-images">';
 } 
}


/**
* Add unique class (mlid) to all menu items.
*/
function ucla_library_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  $element['#attributes']['class'][] = 'menu-' . $element['#original_link']['mlid'];

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}



function ucla_library_form_alter(&$form, &$form_state, $form_id){
  if ($form['#form_id'] == 'search_block_form'){ 
      $form['search_block_form']['#size'] = 26;
      $form['actions']['submit']['#value'] = 'Ok';
  }
}