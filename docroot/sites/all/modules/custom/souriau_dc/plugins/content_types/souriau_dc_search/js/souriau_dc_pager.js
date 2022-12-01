(function ($) {
  Drupal.behaviors.SouriauDCPager = {
    attach: function (context, settings) {
      if (settings.searchDCPager.NextPage == 0) {
        $('.view-more').parent().hide();
      }
      $('.view-more', context).once('view-more').on('click', function () {
        // Hide the button and show a throbber after click to avoid multiple clicks.
        var progress_markup = '<div class="ajax-progress ajax-progress-souriau-hover"><div class="throbber">&nbsp;</div></div>';
        $('.view-more').parent().prepend(progress_markup);
        $('.view-more').hide();
        // Get Next page number for current search tab.
        var NextPage = settings.searchDCPager.NextPage;
        // guerlain.blockButtonsMoreShowLoader();
        var queries = {};
        // queries.range = $('.b-top-filters select[name="range[]"]').val();
        // queries.brand = $('.b-top-filters select[name="brand[]"]').val();
        // queries.application = $('.b-top-filters select[name="application[]"]').val();
        // queries.capability = $('.b-top-filters select[name="capability[]"]').val();
        // queries.language = $('.b-top-filters select[name="language[]"]').val();

        queries.application = [];
        $('#souriau-dc-search-form input[name="application"]:checked').each(function () {
          queries.application.push($(this).attr('name'));
        });
        queries.range = [];
        $('#souriau-dc-search-form input[name="range"]:checked').each(function () {
          queries.range.push($(this).attr('name'));
        });
        queries.types = [];
        $('#souriau-dc-search-form input[type="checkbox"]:checked').each(function () {
          queries.types.push($(this).attr('name'));
        });

        $.each(queries, function (key, value) {
          if (value) {
            if ($.inArray('all', value) >= 0) {
              value = ['all'];
            }
            if (value.length == 0) {
              queries[key] = 'all';
            }
            else {
              queries[key] = value.join('+');
            }
          }
          else {
            queries[key] = 'all';
          }
        });
        var dc_keyword = $('#edit-dc-keyword').val();
        if (dc_keyword == '') {
          dc_keyword = 'all';
        }

        // Request next page.
        $.get('souriau/ajax/dc-pager/' + queries.range + '/all/' + queries.application + '/all/' + dc_keyword + '/' + queries.types + '?page=' + NextPage, function (data) {
          var parsedData = data;
          $('.b-list-documents .view-content').append($($(parsedData.html).html()).html());
          // Update settings if next page more then 0.
          if (parsedData.next_page > 0) {
            settings.searchDCPager.NextPage = parsedData.next_page;
            if ($('.ajax-progress-souriau-hover').length) {
              $('.ajax-progress-souriau-hover').remove();
            }
            if ($('.view-more').parent().is(':hidden')) {
              $('.view-more').parent().show();
            }
            if ($('.view-more').is(':hidden')) {
              $('.view-more').show();
            }
          }
          // Hide button if no more pages.
          else {
            $('.view-more').parent().hide();
          }
        });
      });
    }
  };
})(jQuery);
