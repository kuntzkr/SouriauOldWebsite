/**
 * Provide the HTML to arrange the address fields.
 */
(function ($) {
  var souriau = souriau || {};

  Drupal.behaviors.address_fields_rearrange = {
    attach: function (context, settings) {
      $('.field-name-field-postal-address .street-block').insertAfter('.field-name-field-postal-address .form-item-field-postal-address-und-0-organisation-name');
    }
  };

  Drupal.behaviors.prevent_multiple_form_submit = {
    attach: function (context, settings) {
      $("input[value='user_register_form']", context).parent("form").submit(function(){
        $(this).find(':submit').attr( 'disabled','disabled' );
      });
    }
  };
})(jQuery);
