(function ($) {

  Drupal.behaviors.souriau_search_autocomplete = {
    attach: function (context, settings) {
      if (typeof settings.souriau_search_autocomplete == 'undefined') {
        return;
      }
      var $result_box = $('#b-search-autocomplete');
      var $view_all_link_wrapper = $('.view-all-wrapper');

      $("form#souriau-common-search-form").on('submit',function( event ) {
        event.preventDefault();
        event.stopPropagation();
        // Added loader gif for waiting indication to users.
        var img = $("#souriau-common-search-form .loader-image img");
        var gifSource = img.attr('src'); //get the source in the var  
        $("#souriau-common-search-form .loader-image").removeClass('invisible').addClass('visible');
        setTimeout(function() {
          img.attr('src', gifSource + '?' + Math.random());
        }, 0);

        $("#souriau-common-search-form .link-view-all-results").hide();

        var keyword = $("[name='search[search_key]']").val();
        // Added the replace for a bugfix in case when the search has / in the keyword leads to 404 as apache wont handle the error.
        window.location = window.location.origin + Drupal.settings.basePath + Drupal.settings.pathPrefix + 'search/' + encodeURIComponent(keyword).replace(/\%2F/g, '/');
        return false;
      });

      $.each(settings.souriau_search_autocomplete, function (index, value) {
        var input = $('input[id="' + index + '-search-key"]', context).autocomplete({
          source: Drupal.settings.basePath + Drupal.settings.pathPrefix + value.autocomplete_ui_path + '/' + value.server + '/' + value.index + '/' + value.fields,
          minLength: 3,
          appendTo: $result_box,
          focus: function( event, ui ) {},
          open: function( event, ui ) {
            souriau.souriauPrj.checkStickyMobile($view_all_link_wrapper);
          },
          close: function( event, ui ) {
            souriau.souriauPrj.checkStickyMobile($view_all_link_wrapper);
          }
        }).data("ui-autocomplete");
        if (!input) {
          return;
        }
        input._renderItem = function(ul, item) {
          return $("<li>").data( "item.autocomplete", item ).append(item.node).appendTo( ul );
        };
      });
    }
  };

}(jQuery));
