/**
 * Custom JS for the site.
 */
(function($) {
  $(document).ready(function() {

  $("#treeview").hummingbird();
  $("#treeview").hummingbird("expandNode",{attr:"id",name: "node-0"});
  $(".b-download-center .customForms-processed .searchbox button[type=submit]").click(function() {
     $("#treeview").hummingbird("uncheckAll");
     var searchText = $(".b-download-center .customForms-processed .searchbox input").val();
     $(".result-col .text-results").text("Displaying results for " + searchText);
     return false;
  });


  $('.b-download-center a.clear-filter').click(function(){
    $("#treeview").hummingbird("uncheckAll");
    $("#treeview").hummingbird("collapseAll");
    $('#edit-dc-keyword').val('');
  });
  // Code to handle treeview switching.
  $(".b-download-center #documents-filter .b-choose-view a").click(function() {
    var switch_to = $(this).data('view');
    var switch_from = (switch_to == 'table-view') ? 'list-view' : 'table-view';
    $('.b-choose-view a.active').removeClass('active');
    $(this).addClass('active');
    $('#all-results').removeClass(switch_from);
    $('#all-results').addClass(switch_to);
  });

  // Code to make visible sliding filters on button click for download center in mobile devices.
  $("#filter-nav-mobile a.tree-filter").click(function() {
    $("#treeview_container").css({
      "display": "block",
      "-webkit-animation": "slide-in 0.5s forwards",
      "-ms-animation": "slide-in 0.5s forwards",
      "-moz-animation": "slide-in 0.5s forwards",
      "-o-animation": "slide-in 0.5s forwards",
      "animation": "slide-in 0.5s forwards",
    }).animate({opacity:1});
    $("#filter-nav-mobile a.tree-filter").css({
      "display": "none",
    }).animate({opacity:1}, "slow");
    $("#treeview_container .filter-close").removeClass("hidden");
  });

  // Code to set icons for filter labels.
  $("#treeview ul li").click(function() {
    var $this = $(this);
    if ($this.prev("i").hasClass("fa-plus")) {
      $this.prev("i").addClass("fa-minus");
      $this.prev("i").removeClass("fa-plus");
    }
    if ($this.prev("i").addClass("fa-minus")) {
      $this.prev("i").addClass("fa-plus");
      $this.prev("i").removeClass("fa-minus");
    }
  });
    $("#documents-filter .link").on('click', function(){
      $('#dc_view_type').val($(this).data('view'));
    });
  });
})(jQuery);
