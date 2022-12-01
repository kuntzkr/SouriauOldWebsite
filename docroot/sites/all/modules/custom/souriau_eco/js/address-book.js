(function($){

    Drupal.ajax.prototype.commands.souriau_eco_reset_address_form = function(ajax, response, status) {
        souriau_main.ajax_call('reset_address_form', response.url);
    };

})(jQuery);
