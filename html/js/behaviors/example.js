var souriau = souriau || {};

(function ($){

souriau.example = (function() { "use strict";

  var example = {};

  example.init = function (context, settings) {

    $('body', context).once('example').each(function () {

      console.log('Example behavior works!');

    });
  }

  return example;

})();

})(jQuery);

Drupal.behaviors.example = {

  attach: function(context, settings){
    souriau.example.init(context, settings);
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
  Drupal.behaviors.example.attach(context, settings);
}

