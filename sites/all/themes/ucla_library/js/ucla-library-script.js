(function ($) {
Drupal.behaviors.fusionEqualSidebars = {
  attach: function (context, settings) {
    if (!$.browser.msie || ($.browser.version > 6)) {
    var $mainHeight = $('#main').innerHeight();

    $('.sidebar-first-inner').css('min-height', $mainHeight);
    $('.sidebar-second-inner').css('min-height', $mainHeight);
  }
  }
};

Drupal.behaviors.uclaEqualHeights = {
  attach: function (context, settings) {
    if (jQuery().equalHeights) {  
      $("#preface-top div.equal-heights div.content").equalHeights();
    }
  }
};

Drupal.behaviors.chooseSearch = {
  attach: function (context, settings) {
  
  $("#block-search-form").hide();
     $("#search-choice").change(function() {
         $("#worldcatsearch").toggle();
         $("#block-search-form").toggle();
      });
  }
};
}(jQuery));