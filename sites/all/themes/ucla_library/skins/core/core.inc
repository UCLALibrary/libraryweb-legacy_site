<?php


function ucla_library_fusion_apply_skin_core_info() {

  $skins = array();
 
 //Custom 10 column grid
 $skins['fusion_skins_grid10_width'] = array(
    'title' => t('Width (10 column grid)'),
    'description' => t("Change the width of this block. Fluid grid % widths are relative to the parent region's width. Default widths: sidebar blocks default to the sidebar width; in other regions width is divided equally among all blocks."),    
    'type' => 'select',
    'group' => 'fusion_layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => _fusion_skins_grid_options(10, 960),   
  );
  
  $skins['ucla_library_border_styles'] = array(
    'title' => t('Border styles'),
    'type' => 'checkboxes',
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => array(
      'nogutter' => array(
        'title' => 'No gutters on block',
        'class' => array('no-gutter'),
      ),
      'borderleft' => array(
        'title' => 'Block Left Border',
        'class' => array('border-left'),
      ),
      'borderbottom' => array(
        'title' => 'Block Bottom Border',
        'class' => array('border-bottom'),
      ), 
      'borderright' => array(
        'title' => 'Block Right Border',
        'class' => array('border-right'),
      ),
      'bordertop' => array(
        'title' => 'Block Top Border',
        'class' => array('border-top'),
      ),
    ),
  );
  
  $skins['ucla_library_block_styles'] = array(
    'title' => t('Block styles'),
    'type' => 'checkboxes',
    'group' => 'layout',
    'theme hooks' => array('block','node'),
    'default status' => TRUE,
    'options' => array(
      'large_gutters' => array(
        'title' => 'Large gutter (20px)',
        'class' => array('large_gutter'),
      ),
    ),
  );

  $skins['ucla_library_header_styles'] = array(
    'title' => t('Header styles'),
    'type' => 'checkboxes',
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => array(
      'italics_header' => array(
        'title' => 'Italics Header',
        'class' => array('italics-header'),
      ),
    ),
  );
  
  
  $skins['ucla_library_page_styles'] = array(
    'title' => t('Page Background styles'),
    'type' => 'select',
    'group' => 'layout',
    'theme hooks' => array('node'),
    'default status' => TRUE,
    'options' => array(
      'graypage' => array(
        'title' => 'Gray Page Background',
        'class' => array('gray'),
      ),
      'blackpage' => array(
        'title' => 'Black Page Background',
        'class' => array('black'),
      ),
    ),
  );
  

  $skins['ucla_library_menu_styles'] = array(
    'title' => t('Menu Styles (Horizontal or Vertical)'),
    'type' => 'select',
    'group' => 'layout',
    'theme hooks' => array('block'),
    'default status' => TRUE,
    'options' => array(
      'horizontal-menu' => array(
        'title' => 'Horizontal Menu Style',
        'class' => array('horizontal-menu'),
      ),
      'vertical-menu' => array(
        'title' => 'Vertical Menu Style',
        'class' => array('vertical-menu'),
      ),
    ),
  );

  return $skins;
}

