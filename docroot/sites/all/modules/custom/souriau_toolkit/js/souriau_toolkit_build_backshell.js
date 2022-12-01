/**
 * @file
 * Ajax js.
 */

// jQuery sign.
(function ($, Drupal) {
    // Show button if all list values are selected.
    Drupal.ajax.prototype.commands.afterAjaxCallComponent = function (ajax, response, status) {
        // Checking all input fields.
        var showBtn = 'YES';
        $("#component_container select").each(function () {
            if ($(this).val() == '0' || $(this).find('option').length == 0) {
                showBtn = 'NO';
                return false;
            }
        });

        if (response.isErrorOn > 0) {
            showBtn = 'NO';
        }
        if (showBtn == 'YES') {
            if ($("#btn_container").css('display') == 'none') {
                $("#btn_container").show();
            }
        }
        else {
            if (response.isRelation == 1 && $("#btn_container").is(":visible")) {
                $("#btn_container").hide();
            }
        }
    }

    // PartNumber assigning.
    Drupal.ajax.prototype.commands.changePartNumber = function (ajax, response, status) {
       // Redirect to Partnumber.
        $(".partnumberCss").val(response.part_id).change();
    }

    Drupal.ajax.prototype.commands.backshell_error_display = function (ajax, response, status) {
        if (response.partnumber_image != null) {
            $('#tools-form-result').find('h4').after("<p>" + response.partnumber_image + "</p>");
        }
        if (response.error_message != null) {
            $('#tools-form-result').find('h4').after("<p class='error-msg'>" + response.error_message + "</p>");
        }
        if (response.finish_part_msg != null) {
            $('#tools-form-result').find('h4').after("<p>" + response.finish_part_msg + "</p>");
        }
        $("html, body").animate({ scrollTop: $('#tools-form-result').offset().top}, 1000);
    }

    Drupal.behaviors.printPartnumber = {
      attach: function (context, settings) {
        $('#print_button').once().on('click', function () {
          var contents = $("#tools-form-result").html();
          var frame1 = $('<iframe />');
          frame1[0].name = "frame1";
          frame1.css({ "position": "absolute", "top": "-1000000px" });
          $("body").append(frame1);
          var frameDoc = frame1[0].contentWindow ? frame1[0].contentWindow : frame1[0].contentDocument.document ? frame1[0].contentDocument.document : frame1[0].contentDocument;
          frameDoc.document.open();
          // Create a new HTML document.
          frameDoc.document.write('<html><body>');
          // Append the DIV contents.
          frameDoc.document.write(contents);
          frameDoc.document.write('</body></html>');
          frameDoc.document.close();
          setTimeout(function () {
            window.frames["frame1"].focus();
            window.frames["frame1"].print();
            frame1.remove();
          }, 500);
        });
      }
    };
}(jQuery, Drupal));
