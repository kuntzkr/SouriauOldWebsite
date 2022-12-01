/**
 * Custom JS for the site.
 */
(function($) {
  
  $("#treeview").hummingbird();
  
  $("#checkAll").click(function(e) {
    e.preventDefault();
    $("#treeview").hummingbird("checkAll");
  });
  
  $("#uncheckAll").click(function(e) {
    e.preventDefault();
    $("#treeview").hummingbird("uncheckAll");
  });
  
  $("#collapseAll").click(function(e) {
    e.preventDefault();
    $("#treeview").hummingbird("collapseAll");
  });
  
  $("#expandAll").click(function(e) {
    e.preventDefault();
    $("#treeview").hummingbird("expandAll");
  });

  $(document).ready(function() {
    $("#treeview input").click(function() {
      if ($("#treeview li label input[type='checkbox']:checked").length > 0) {
        $(".result-col .text-results").text("Displaying 20 Results");
      }
      else {
        $(".result-col .text-results").text("Last Updates");
      }
    });
  });

  // Result changes on keyword changes.
  $(".b-download-center .customForms-processed .searchbox button[type=submit]").click(function() {
     $("#treeview").hummingbird("uncheckAll");
     var searchText = $(".b-download-center .customForms-processed .searchbox input").val();
     $(".result-col .text-results").text("Displaying results for " + searchText);
     return false;
  });

  $(".b-download-center #documents-filter a.list-view").click(function() {
    $(".b-download-center #documents-filter a.list-view").addClass("active");
    $(".b-result-view #list-view").addClass('active in');
    $(".b-download-center #documents-filter a.table-view").removeClass("active");
    $(".b-result-view #table-view").removeClass('active in');
  });
  $(".b-download-center #documents-filter a.table-view").click(function() {
    $(".b-download-center #documents-filter a.table-view").addClass("active");
    $(".b-result-view #table-view").addClass('active in');
    $(".b-download-center #documents-filter a.list-view").removeClass("active");
    $(".b-result-view #list-view").removeClass('active in');
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

})(jQuery);
