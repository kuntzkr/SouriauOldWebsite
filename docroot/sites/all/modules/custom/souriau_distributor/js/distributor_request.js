(function ($) {
  Drupal.behaviors.distributor_tipity_request = {
    attach: function (context, settings) {
      $('#distributors_request').on("click", function () {
        var $this = $(this);
        var data = {partnumber: $this.attr('partnumber')};
        var url = $this.attr('data-ajax-url');
        var name = '#distributors_request';
        souriau_main.ajax_call(name, url, data);
      });
    }
  };
}(jQuery));
