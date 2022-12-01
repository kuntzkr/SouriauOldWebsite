var souriau = souriau || {};

(function ($){

souriau.exampleWithSettings = (function() { "use strict";

  var _defaults = {
        myOption: true
      },
      _options,
      exampleWithSettings = {};

  exampleWithSettings.init = function (context, settings) {

    $('body', context).once('exampleWithSettings').each(function () {
      settings = settings || {};
      settings.souriau = settings.souriau || {};
      settings.souriau.exampleWithSettings = settings.souriau.exampleWithSettings || {};
      _options = $.extend({}, _defaults, settings.souriau.exampleWithSettings);

      console.log('ExampleWithSettings behavior Works and \'myOption\' is set to: \'' + _options.myOption + '\'');

    });
  }

  return exampleWithSettings;

})();

})(jQuery);

Drupal.behaviors.exampleWithSettings = {

  attach: function(context, settings){
    souriau.exampleWithSettings.init(context, settings);
  }
}

// Init self in case we are loaded async.
if (jQuery.isReady) {
  // It is up to script to define scope and settings it should be applied to
  // in case of jquery mobile integration used you can use site_common.jquery_mobile.getPageContext()
  // to get only current page's context.
  // In this implementation we use global scope.
  var context = document;
  var settings = Drupal.settings;
  Drupal.behaviors.exampleWithSettings.attach(context, settings);
}

