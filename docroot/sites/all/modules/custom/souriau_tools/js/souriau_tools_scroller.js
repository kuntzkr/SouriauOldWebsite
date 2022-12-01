/**
 * @file
 * Ajax js.
 */

// jQuery sign.
(function ($, Drupal) {
  Drupal.ajax.prototype.commands.scroll_to_results = function (ajax, response, status) {
    $("html, body").animate({ scrollTop: $('#tools-form-result').offset().top}, 1000);
  }
}(jQuery, Drupal));
