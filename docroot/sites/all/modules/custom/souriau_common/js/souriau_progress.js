/**
 * @file
 * Souriau custom progress.
 */
(function($) {
  var beforeSend = Drupal.ajax.prototype.beforeSend;
  var success = Drupal.ajax.prototype.success;
  var error = Drupal.ajax.prototype.error;

  /**
   * Prepare the Ajax request before it is sent.
   */
  Drupal.ajax.prototype.beforeSend = function(xmlhttprequest, options) {
    beforeSend.call(this, xmlhttprequest, options);

    if (this.progress.type == "souriau_hover_progress") {
      var progress_markup = '<div class="ajax-progress ajax-progress-souriau-hover"><div class="throbber">&nbsp;</div></div>';
      var parent_form = $(this.element).parents('form');
      parent_form.prepend(progress_markup);
    }
  };

  /**
   * Handler for the form redirection completion.
   */
  Drupal.ajax.prototype.success = function(xmlhttprequest, options) {
    success.call(this, xmlhttprequest, options);

    if (this.progress.type == "souriau_hover_progress") {
      var overlay_selector = '.ajax-progress-souriau-hover';
      var parent_form = $(this.element).parents('form');
      parent_form.children(overlay_selector).remove();
    }
  };

  /**
   * Handler for the form redirection error.
   */
  Drupal.ajax.prototype.error = function (response, uri) {
    error.call(this, response, uri);

    if (this.progress.type == "souriau_hover_progress") {
      var overlay_selector = '.ajax-progress-souriau-hover';
      var parent_form = $(this.element).parents('form');
      parent_form.children(overlay_selector).remove();
    }
  };
})(jQuery);
