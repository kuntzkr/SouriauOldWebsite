(function ($) {
  Drupal.behaviors.SouriauSearchPager = {
    attach: function (context, settings) {

      $('a.view-more', context).once('load-more', function () {
          $(this).on('click', function (event) {
            event.preventDefault();
            if ($(this).hasClass('progress-disabled')) {
              // Load more already in progress. Nothing to do here.
              return;
            }
            // Get current tab ID.
            var tabname = $('.tab-pane.active').attr('id');
            // Get Next page number for current search tab.
            var NextPage = settings.souriauSearchPager.NextPage[tabname];
            // Parse Url query.
            var keyword = window.location.pathname.split('/').pop();
            // plane keyword
            keyword = Drupal.checkPlain(keyword);
            var data = {};
            $('.tab-pane.active .b-list-filters .filter-item a.close-link').each(function(){
              var filter_id = $(this).data('filter-id');
              var filter_value = $(this).data('filter-value');
              var number_val = filter_value;
              var filter_type = $(this).data('filter-type');
              if (filter_type == 'souriau_common_number_compare') {
                number_val = number_val.split(" ");
                filter_value = {};
                filter_value['sign'] = number_val.shift();
                filter_value[0] = number_val.shift();
              }
              if (filter_type == 'souriau_common_boolean') {
                filter_value = {};
                filter_value[0] = number_val;
              }
              // Emulate filter form post structure.
              data[filter_id] = {};
              data[filter_id][filter_id] = filter_value;
            });
            data.index = settings.souriauSearchPager.IndexName;
            data.sort = $('.tab-pane.active a.list-sort').data('sort');
            data.view_type = $('.b-choose-view a.active').data('view');
            var url = '/souriau/ajax/search-pager/' + tabname +'/'+ keyword + '?page=' + NextPage;
            var name = '#' + tabname;
            var custom_settings = {
              element: $(this),
              progress: {
                type: 'throbber'
              }
            };
            souriau_main.ajax_call(name, url, data,'post', 1000, 2000, false, custom_settings);
          });
        });

      $('.b-list-filters a.close-link', context).once('close-link', function () {
        $(this).on('click', function (event) {
          event.preventDefault();
          var filter_id = $(this).data('filter-id');
          var filter_value = $(this).data('filter-value');
          var filter_type = $(this).data('filter-type');
          switch (filter_type) {
            case 'souriau_common_number_compare':
              filter_value = filter_value.split(' ').pop();
              $('form.souriau-search-filer-form *[data-filter-id="' + filter_id + '"][value="' + filter_value + '"]').attr('checked', false);
              break;
            case 'souriau_common_boolean':
            case 'souriau_common_radios':
              $('form.souriau-search-filer-form *[data-filter-id="' + filter_id + '"]').prop('checked', false);
              break;
            case 'souriau_common_dropdown_list':
              $('form.souriau-search-filer-form *[data-filter-id="' + filter_id + '"]').find("option").attr("selected", false);
              break;
            default:
              $('form.souriau-search-filer-form *[data-filter-id="' + filter_id + '"][data-filter-value="' + filter_value + '"]')
                .val('')
                .removeAttr('checked')
                .removeAttr('selected');
          }
          jcf.refreshAll();
          $('form.souriau-search-filer-form [name="op"]').mousedown();
        });
      });

      $('.b-params a.list-sort', context).once('list-sort', function () {
        $(this).on('click', function (event) {
          event.preventDefault();
          if ($(this).data('sort') == 'ASC') {
            $(this).data('sort', 'DESC');
          }
          else {
            $(this).data('sort', 'ASC');
          }
          // Get current tab ID.
          var tabname = $('.tab-pane.active').attr('id');
          // Parse Url query.
          var keyword = window.location.pathname.split('/').pop();
          // plane keyword
          keyword = Drupal.checkPlain(keyword);
          var data = {};
          $('.tab-pane.active .b-list-filters .filter-item a.close-link').each(function(){
            var filter_id = $(this).data('filter-id');
            var filter_value = $(this).data('filter-value');
            var filter_type = $(this).data('filter-type');
            if (filter_type == 'souriau_common_number_compare') {
              filter_value = filter_value.substring(1);
            }
            // Emulate filter form post structure.
            data[filter_id] = {};
            data[filter_id][filter_id] = {};
            data[filter_id][filter_id][0] = filter_value;
          });
          data.index = settings.souriauSearchPager.IndexName;
          data.sort = $(this).data('sort');
          var url = '/souriau/ajax/search-pager/' + tabname +'/'+ keyword;
          var name = '#' + tabname;
          souriau_main.ajax_call(name, url, data);
        });
      });

      $('.clear-filter', context).once('clear-filter').on('click', function (event) {
        event.preventDefault();
        var $block_clear = $(this).data('block-clear');

        $('#'+ $block_clear).find('input[type="checkbox"], input[type="radio"]').prop('checked', false);
        $('#'+ $block_clear).find('option:selected').removeAttr("selected");
        jcf.refreshAll();
        $('form.souriau-search-filer-form [name="op"]').mousedown();
      });
      $('.souriau-search-filer-form .close-link').once('close-form-link').on('click', function(e){
        e.preventDefault();
        e.stopPropagation();

        $filter_block = $('#b-filters');
        souriau.souriauPrj.closeMenu($filter_block);
      });
    }
  };

  // Maintain the scroll position after selecting a filter.
  Drupal.ajax.prototype.commands.search_filter_scroller = function(ajax, response, status) {
    var scrollPosition = $('#' + response.triggering_element).closest('fieldset').position().top - $('.b-main-filter-area .b-content').position().top;
    $('.b-main-filter-area .b-content').animate({
      scrollTop: scrollPosition
    }, 1000);
  };
})(jQuery);
