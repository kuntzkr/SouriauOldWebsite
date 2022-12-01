/**
 * Provide the HTML to create the modal dialog.
 */
(function ($) {
  var souriau = souriau || {};

  Drupal.theme.prototype.souriau_common_popup = function () {
    var html = ''
    html += '<div id="ctools-modal">';
    html += '  <div class="vertical-alignment-helper">';
    html += '    <div class="modal-dialog vertical-align-center" role="document">';
    html += '       <div class="modal-body">';
    html += '         <button type="button" class="close ctools-close-modal" aria-hidden="true">';
    html += '           <span class="ico ico-close">+</span>';
    html += '           <span class="screen-reader-text">Close popup</span>';
    html += '         </button>';
    html += '         <div class="modal-content">';
    html += '           <div id="modal-content">';
    html += '           </div>';
    html += '         </div>';
    html += '      </div>';
    html += '    </div>';
    html += '  </div>';
    html += '</div>';

    return html;
  };

  Drupal.behaviors.soiriau_modal_dismiss = {
    "attach": function (context, settings) {
      // Close ctools-modal popups.
      $(context).find('.modal-dialog a[data-dismiss="modal"]').bind('click', Drupal.CTools.Modal.modal_dismiss);
    },
    detach: function (context, settings, trigger) {
      $(context).find('.modal-dialog a[data-dismiss="modal"]').unbind('click', Drupal.CTools.Modal.modal_dismiss);
    }
  };

  souriau.show_info_popup = function (popup) {
    // Kind of copy of Drupal.CTools.Modal.modal_display();
    if ($('#modalContent').length == 0) {
      Drupal.CTools.Modal.show('souriau-modal-style');
    }
    $('#modalContent').addClass('inform-popup');
    $('#modal-title').html(popup.title);
    // Simulate an actual page load by scrolling to the top after adding the
    // content. This is helpful for allowing users to see error messages at the
    // top of a form, etc.
    $('#modal-content').html(popup.output).scrollTop(0);
    var $ok_btn = $('<div class="w-btn text-center">' +
            '<a class="btn orange-btn-hover" href="#" aria-label="Ok" data-dismiss="modal">OK</a>' +
          '</div>');
    $('#modal-content').append($ok_btn);

    var settings = popup.settings || Drupal.settings;
    Drupal.attachBehaviors('#modalContent', settings);

    $('#modalContent').addClass('inform-popup');
    setTimeout(function(){ $('#modalContent').addClass('in'); }, 500);

    if ($('#modal-content').hasClass('ctools-modal-loading')) {
      $('#modal-content').removeClass('ctools-modal-loading');
    }
    else {
      // If the modal was already shown, and we are simply replacing its
      // content, then focus on the first focusable element in the modal.
      // (When first showing the modal, focus will be placed on the close
      // button by the show() function called above.)
      $('#modal-content :focusable:first').focus();
    }
    $('#modalContent').show();
  }

  // @deprecated.
  // $(function() {
  //   // DISPLAY STATUS MESSAGES IN POPUP IF ANY.
  //   var messages = $('.messages.status').html();
  //   if (!messages) {
  //     return;
  //   }
  //   var popup = {
  //     "title": Drupal.t('Your request has been sent'),
  //     "output": '<div class="b-text">' + messages + '</div>',
  //   };
  //   souriau.show_info_popup(popup);
  // });

})(jQuery);
