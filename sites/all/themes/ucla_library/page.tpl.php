<?php
?>

  <div id="page" class="page">
    <div id="page-inner" class="page-inner">

      <!-- header-group region: width = grid_width -->
      <div id="header-group-wrapper" class="header-group-wrapper full-width clearfix">
      <div id="header-group" class="header-group region clearfix <?php print $grid_width; ?>">

        <?php if ($logo || $site_name || $site_slogan): ?>
        <div id="header-site-info" class="header-site-info block">
          <div id="header-site-info-inner" class="header-site-info-inner inner">
            <?php if ($logo): ?>
            <div id="logo">
              <a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /></a>
            </div>
            <?php endif; ?>
            <?php if ($site_name || $site_slogan): ?>
            <div id="site-name-wrapper" class="clearfix">
              <?php if ($site_name): ?>
              <span id="site-name"><a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a></span>
              <?php endif; ?>
              <?php if ($site_slogan): ?>
              <span id="slogan"><?php print $site_slogan; ?></span>
              <?php endif; ?>
            </div><!-- /site-name-wrapper -->
            <?php endif; ?>
          </div><!-- /header-site-info-inner -->
        </div><!-- /header-site-info -->
        <?php endif; ?>

        <?php print render($page['header']); ?>
      </div><!-- /header-group -->
      </div><!--/header-group-wrapper -->
 
  <div id="main-menu-wrapper" class="main-menu-wrapper full-width clearfix">  
       <?php print render($page['main_menu']); ?> 
	</div><!--/main-menu-wrapper -->	
	
      <?php print render($page['preface_top']); ?>
      <!-- main region: width = grid_width -->
      <div id="main" class="main region clearfix <?php print $grid_width; ?>">
        <?php print render($page['sidebar_first']); ?>
        
        <!-- content group: width = grid_width - sidebar_first_width - sidebar_second_width -->
        <div id="content-group" class="content-group region nested <?php print $content_group_width; ?>">
         <?php print render($page['preface_bottom']); ?>
          <a name="main-content-area" id="main-content-area"></a>
          <?php print theme('grid_block', array('content' => $breadcrumb, 'id' => 'breadcrumbs')); ?>
          <?php print theme('grid_block', array('content' => $messages, 'id' => 'content-messages')); ?>
          
          	<!-- title -->
           <?php print render($title_prefix); ?>
                <?php if ($title && !$is_front && !$node_page_master): ?>
                <h1 class="title"><?php print $title; ?></h1>
                <?php endif; ?>
                <?php print render($title_suffix); ?>
                <!-- title -->
          <?php print theme('grid_block', array('content' => render($tabs), 'id' => 'content-tabs')); ?>
          <?php print theme('grid_block', array('content' => render($page['help']), 'id' => 'content-help')); ?>
          <div id="content-inner" class="content-inner block">
            <div id="content-inner-inner" class="content-inner-inner inner">
             
              <?php if ($action_links): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
              <?php endif; ?>
              <div id="content-content" class="content-content">
                <?php print render($page['content']); ?>
              </div><!-- /content-content -->
            </div><!-- /content-inner-inner -->
          </div><!-- /content-inner -->
        </div><!-- /content-group -->
          <?php print render($page['sidebar_second']); ?>
      
      </div><!-- /main -->

     <?php if($page['footer']):?>
       <div id="footer-wrapper" class="footer-wrapper full-width clearfix">
      <?php print render($page['footer']); ?>
      </div><!--/footer-wrapper-->
      <?php endif; ?>
                 <?php if($page['footer2']):?>
       <div id="footer-wrapper2" class="footer-wrapper2 full-width clearfix">
      <?php print render($page['footer2']); ?>
      </div><!--/footer-wrapper2-->
      <?php endif; ?>
          
          <?php if($page['footer3']):?>
       <div id="footer-wrapper3" class="footer-wrapper3 full-width clearfix">
      <?php print render($page['footer3']); ?>
      </div><!--/footer-wrapper3-->
      <?php endif; ?>
    </div><!-- /page-inner -->
  </div><!-- /page -->
