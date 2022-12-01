// $, Theme and Drupal Namespaces.

var souriau = souriau || {};
var Drupal = Drupal || {};

// If Drupal is not available - we are in slice enviroment.
if (!Drupal.t) {

  Drupal.settings = {};
  Drupal.settings.souriau = {};

  // Prepare behavior root.
  Drupal.behaviors = {};

  // Implement drupal translate.
  Drupal.t = function (text) {
    return text;
  }

  // Act as drupal behavior.
  $(document).on('ready', function () {
    Drupal.attachBehaviors($(document), {});
  });

  Drupal.attachBehaviors = function (context, settings) {

    context = context || document;
    settings = settings || Drupal.settings;
    // Execute all of them.
    $.each(Drupal.behaviors, function () {
      var behavior = this;
      if ($.isFunction(behavior.attach)) {
        behavior.attach(context, settings);
      }
    });
  };
}
