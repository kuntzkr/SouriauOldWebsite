/**
 * Created by dmn_dvs on 25.04.16.
 */
// Namespace.
var souriau_main = souriau_main || {};
var souriau = souriau || {};

(function($) {

    Drupal.behaviors.attach = {
        attach: function(context, settings) {
            souriau_main.attach($(context), settings);
        }
    };

    souriau_main.attach = function(context, settings) {

        // Redirect on change value of select form.
        souriau_main.county_selector($(context), settings);

        // On subscribe form.
        souriau_main.attach_ajax($(context), settings);

        // On subscribe form.
        souriau_main.attach_proxy($(context), settings);

        //Minicart block
        souriau_main.attach_minicart($(context), settings);

        //Compare button
        souriau_main.compare_button($(context), settings);
        souriau.souriauPrj.compareRemoveBehavior($(context), settings);

        // Part Number preview, matchHeight.
        souriau_main.productsPreview($(context), settings);

        // GTM datalayer.
        souriau_main.gtm_data_prepare($(context), settings);

        // Webform submit handler.
        souriau_main.webform_submit($(context), settings);

        // User registration submit handler.
        souriau_main.user_register_submit($(context), settings);

        // Webform product page scroller.
        souriau_main.page_scroller($(context), settings);

        // Did you know page.
        souriau_main.postcard_click($(context), settings);
    };

    souriau_main.webform_submit = function(context, settings) {
      var submittedAlready = false;
      // Made the submit disabled after first form submit.
      $('form.webform-client-form', context).submit(function() {
        if (submittedAlready) {
          return false;
        }
        submittedAlready = true;
      });
    }

    souriau_main.user_register_submit = function(context, settings) {
      var submittedAlready = false;
      // Made the submit disabled after first form submit.
      $('#user-register-form', context).submit(function() {
        if (submittedAlready) {
          return false;
        }
        submittedAlready = true;
      });
    }

    souriau_main.gtm_data_prepare = function(context, settings) {
      // Share button click.
      $('.a2a_dd', context).once('gtm', function () {
        $(this).click(function() {
          dataLayer.push({
            'Category': 'Button',
            'Action': 'Share',
            'Label': document.title,
            'CurrentPageTitle': document.title,
            'CurrentPageURL': window.location.href
          });
        });
      });

      // Download center filter click.
      $('#souriau-dc-search-form select', context).once('gtm', function () {
        $(this).change(function() {
          var dimension_data = [];
          $.each($("option:selected", this), function(){
            dimension_data.push($(this).text());
          });
          if (dimension_data.length > 0) {
            dataLayer = [];
            dataLayer.push({
              'Dimension': $(this).attr('placeholder').replace('All ', ''),
              'Data': dimension_data,
              'Page': 'Download Center',
            });
          }
        });
      });

      $('.gtm_crossref_element', context).once('gtm', function () {
        $(this).click(function() {
          dataLayer.push({
            'Category': 'Button',
            'Action': 'Competitor-part-number',
            'Label': $('#edit-part-number').val(),
            'CurrentPageTitle': document.title,
            'CurrentPageURL': window.location.href
          });
        });
      });

      // Track other gtm elements click.
      $('.gtm_element', context).once('gtm', function () {
        $(this).click(function(e) {
          dataLayer.push({
            'Category': $(this).data('gtmCategory'),
            'Action': $(this).data('gtmAction'),
            'Label': $(this).data('gtmLabel'),
            'CurrentPageTitle': document.title,
            'CurrentPageURL': window.location.href
          });
        });
      });

      // Track compare button click.
      $('.b-to-compare .btn', context).once('compare-btn', function() {
        var $this = $(this);
        var gtm_data = [];
        $this.click(function(e){
          $('.compare-link').each(function(i, val) {
            if($(val).hasClass('active') && $.inArray($(val).data('gtm-label'), gtm_data) < 0) {
              gtm_data.push($(val).data('gtm-label'));
            }
          });
          dataLayer.push({
            'Category': 'Button',
            'Action': 'Compare',
            'Label': gtm_data.toString(),
            'CurrentPageTitle': document.title,
            'CurrentPageURL': window.location.href
          });
        });
      });
    };

    // Part Number preview, matchHeight.
    souriau_main.productsPreview = function(context, settings) {
        // PartNumbers Preview.
        $('.product-items .b-part-number-preview', context).matchHeight();
        // Product Range Preview.
        $('.product-items .item', context).matchHeight();
    };
    souriau_main.compare_button = function (context, settings) {
      $(".b-result-view .b-tabs li").click(function() {
          var selected_tab_value = $(this).find('a').attr('href').split('#')[1];
          if (selected_tab_value === 'all' || selected_tab_value === 'part-number') {
            if ($('.b-to-compare').hasClass('hidden')) {
              $('.b-to-compare').removeClass('hidden');
            }
          }
          else {
            $('.b-to-compare').addClass('hidden');
          }
      });

      $('.compare-link', context).once('compare-button', function () {
        var $this = $(this);

        $this.click(function(e){
          e.preventDefault();

          // This code runs after one from html folder so class active already available.
          if ($this.hasClass('active')) {
            souriau.souriauPrj.comparePartNumbers.add($this.data('part-number'));
          }
          else {
            souriau.souriauPrj.comparePartNumbers.remove($this.data('part-number'));
          }
          var items_string = '';
          if ($.cookie('Drupal.visitor.part_numbers') != null) {
            var count = $.cookie('Drupal.visitor.part_numbers').split(',').filter(String).length;
            if (count == 0) {
              $('.b-to-compare').hide('slow');
            } else if (count == 1) {
              $('.b-to-compare').show('slow');
              $(window).scrollTop($(window).scrollTop() + 1);
            }
            items_string = Drupal.formatPlural(count, '1 item added', '@count items added');
          }
          $('.b-to-compare .text').text(items_string);
        });
      });
    };

    // Language redirect.
    souriau_main.county_selector = function(context, settings) {
      var list = $(context).find('.lang-select').find('li a');
      list.click(function(e) {
        e.preventDefault();
        var url = $(this).attr( 'data-link' );
        var souriau_common = Drupal.settings.souriau_common || {};
        var cookie_domain = souriau_common.cookie_domain || false;
        var iso_cookie = {};
        var country_iso = $(this).attr( 'data-iso' );
        if (country_iso) {
          iso_cookie['iso_code'] = country_iso;
          iso_cookie['lang_code'] = $(this).attr( 'data-lang' );
          $.cookie("country", JSON.stringify(iso_cookie), {path: '/', expires: 30, domain: cookie_domain});
        }
        if (url) {
          window.location = url;
        }
        return false;
      });
    };

    /**
     * Attach Ajax.
     */
    souriau_main.attach_ajax = function ($context, settings) {

        // Anonymous subscribe AJAX form.
        $context.delegate("#souriau-newsletter-ajax-subscribe-submit", "click", function() {
            if (!$(this).hasClass('disabled')) {
                var $this = $(this);
                $this.addClass('disabled');
                var $form = $this.parents('form');
                var data = $form.serialize();
                var url = $this.attr('data-ajax-url');
                var name = '#souriau-newsletter-ajax-subscribe-submit';
                //var ajax = new Drupal.ajax(name, $(document.body), {url: url});
                //ajax.eventResponse(ajax, {data: data});
                souriau_main.ajax_call(name, url, data);
            }
            return false;
        });

        // Anonymous subscribe AJAX popup form.
        $context.delegate("#souriau-newsletter-ajax-popup-submit", "click", function() {
            if (!$(this).hasClass('disabled')) {
                var $this = $(this);
                $this.addClass('disabled');
                var $form = $this.parents('form');
                var data = $form.serialize();
                var url = $this.attr('data-ajax-url');
                var name = '#souriau-newsletter-ajax-popup-submit';
                //var ajax = new Drupal.ajax(name, $(document.body), {url: url});
                //ajax.eventResponse(ajax, {data: data});
                souriau_main.ajax_call(name, url, data);
            }
            return false;
        });

    };

    if (typeof Drupal.ajax == 'function') {
        souriau_main.ajax_call = function (name, url, data, method, spam, unlock, skip_queue, custom_settings) {

            // Check for spam and save firngerprint.
            spam = spam || 1000;
            unlock = unlock || spam + 1000;
            skip_queue = skip_queue || false;
            var forbidden = '';
            var _fingerid = name;

            // Simple settings.
            custom_settings = custom_settings || {};
            custom_settings.name = name;
            custom_settings.url = url;
            custom_settings.event = 'onload';
            custom_settings.keypress = false;
            custom_settings.prevent = false;
            custom_settings.submit = data;
            custom_settings.fingerid = _fingerid || false;
            var element = custom_settings.element || $(document.body);

            // Create new ajax and execute.
            Drupal.ajax[name] = new Drupal.ajax(null, element, custom_settings);

            if (Drupal.ajax[name]) {

                // Swap ajax mehod if required.
                Drupal.ajax[name].options.type = method || 'post';

                // Trigger ajax call.
                Drupal.ajax[name].specifiedResponse();
            }

            // Return object for future user.
            return Drupal.ajax[name];
        };

        Drupal.ajax.prototype.specifiedResponse = function() {
            var ajax = this;

            // Do not perform another ajax command if one is already in progress.
            if (ajax.ajaxing) {
                return false;
            }

            try {
                $.ajax(ajax.options);
            }
            catch (err) {
                alert('An error occurred while attempting to process ' + ajax.options.url);
                return false;
            }

            return false;
        };

        Drupal.ajax.prototype.commands.jcf = function(ajax, data, status) {
          var jcf_context = data.selector;
          if (jcf_context === null) {
            jcf_context = ajax.element;
          }
          window.jcf[data.method](jcf_context);
        };

      Drupal.ajax.prototype.commands.calc_indent = function(ajax, data, status) {
        var context = jQuery(data.selector);
        if (context === null) {
          context = ajax.element;
        }
        souriau.souriauPrj.caclIndent(context);
      };

    }

    souriau.souriauPrj.editableBlock = function(context, settings) {
        context = $(context);

        context.find('.w-editable').once('editable', function () {
          var $this = $(this);

          // Set the empty placeholder, if the field is null on page load.
          var $edit_el = $this.children('.b-editable-area');

          var val = $.trim($edit_el.text());
          if(val == undefined || val === "") {
            empty_title = 'Please add description';
            $edit_el.text(empty_title);
          }

          function adjustTextAreaHeight($elem) {
            if( $elem[0].scrollHeight !== parseInt($elem.attr('data-scroll'), 10) ) {
              $elem.css('height', $elem[0].scrollHeight +'px');
              $elem.attr('data-scroll', $elem[0].scrollHeight);
            }
          };

          $this.find('.ico-edit').on('click', function(){
            var $cur_btn = $(this);

            $this.find(".b-editable-area").trigger('click');
          })

          $this.find(".b-editable-area").each(function( index ) {
            var $cur_elem = $(this);

            $cur_elem.on('click',function(e){
              e.preventDefault();
              e.stopPropagation();

              if ($cur_elem.hasClass('ico-edit')){
                $cur_elem.addClass('hide');
              }

              var val = $.trim($cur_elem.text());
              var empty_title = $cur_elem.data('empty-title');

              $this.addClass('editable');

              if(empty_title == undefined || empty_title == "") {
                empty_title = 'Please add description';
              }

              if (val != '' && val != empty_title) {
                $cur_elem.html('<textarea style="width: 100%;">'+val+'</textarea>').focus();
              } else {
                $cur_elem.html('<textarea style="width: 100%;"></textarea>').focus();
              }

              var $textarea = $cur_elem.find('textarea');

              adjustTextAreaHeight($textarea);

              setTimeout(function(){
                $textarea.focus();
              },0)

              $textarea.click(function(e){
                e.preventDefault();
                e.stopPropagation();
              })

              $textarea.on('blur', function(){
                var new_val = $.trim($(this).val());

                if(new_val == '') {
                  new_val = empty_title;
                }

                $cur_elem.html(new_val).find('textarea').remove();
                  $this.removeClass('editable');
                  if ($cur_elem.hasClass('ico-edit')){
                    $cur_elem.removeClass('hide');
                  }
              });

              $textarea.on('paste change keyup input', function(){
                adjustTextAreaHeight($textarea);
              });
              // Binds and Unbinds onchange action for project page inline edit.

              $('#prj-title-edit').once('inline-title').on('change', function(e) {
                var $titleVal = $(this).find('textarea').val();
                prjInlineEdit($(this), $titleVal, 'prj-title-edit');
              });
              $('#prj-desc-edit').once('inline-desc').on('change', function(e) {
                var $descVal = $(this).find('textarea').val();
                prjInlineEdit($(this), $descVal, 'prj-desc-edit');
              });
              $('.prj-partno-notes').once('partno-notes-edit').on('change', function(e) {
                var $notesVal = $(this).find('textarea').val();
                prjInlineEdit($(this), $notesVal, 'prj-partno-notes');
              });
            });
            function prjInlineEdit($elem, $val, $fieldtype) {
              var $data = $val;
              var $old_data = $elem.attr('data-prj-title');
              if ($val != undefined && $val != null && $val != $old_data) {
                var $id = $elem.attr('id');
                // inline editing.
                var data = {
                  id: $elem.attr('data-prj-id'),
                  partno: $elem.attr('data-part-id'),
                  value: $val,
                  type: $fieldtype
                };
                var url = $elem.attr('data-ajax-url');
                var name = '#' + $fieldtype;
                souriau_main.ajax_call(name, url, data);
              }
            };
          });
        });
      };

    souriau.souriauPrj.customForm = function(context, settings) {
        $(context).find('input, select').once('customForms', function() {

            if ($(context).find('select').length > 0) {

                jcf.setOptions('Select', {
                    wrapNative: false,
                    wrapNativeOnMobile: false,
                    useCustomScroll: true,
                    fakeDropInBody: false,
                    fakeDropStructure: '<div class="jcf-select-drop"><div class="jcf-select-drop-content"><div class="w-btns"><a class="link-check-all" href="javascript:;">'+Drupal.t("check all")+'</a><a class="link-uncheck-all" href="javascript:;">'+Drupal.t("uncheck all")+'</a></div></div></div>'
                });
            }

            jcf.replaceAll(context);

        });

        $('body').once('link-check-uncheck-all', function() {
            var $body = $('body');

            $body.on('click', '.link-check-all', function(e){
                e.preventDefault();
                e.stopPropagation();

                var $cur_select = $(this).parents('.jcf-select').prev();
                $cur_select.find('option').prop("selected", 'true');
                jcf.replace($cur_select);
                $cur_select.trigger('change');
            });

            $body.on('click', '.link-uncheck-all' ,function(e){
                e.preventDefault();
                e.stopPropagation();

                var $cur_select = $(this).parents('.jcf-select').prev();
                $cur_select.find('option:selected').removeAttr('selected');
                jcf.replace($cur_select);
                $cur_select.trigger('change');
            });
        })


    };

    souriau.souriauPrj.labelBehavior = function(context, settings) {
        context = $(document);

        var $this = context.find('.b-form, .b-inner-form');
        var $inputs = $this.find('input[type="text"], input[type="email"], input[type="password"], textarea');

        if ('WebkitAppearance' in document.documentElement.style) {
            var chkReadyState = setInterval(function() {
                if (document.readyState == "complete" && $this.is(':visible')) {
                    // clear the interval
                    clearInterval(chkReadyState);

                    $this.find('input:-webkit-autofill').each(function(){
                        console.log('autofill');
                        $(this).parents('.form-item').addClass('full-field');
                    });
                }
            }, 100);
        }

        $inputs.each(function(){
            var $cur_input = $(this);
            var $parent = $(this).parents('.form-item');

            if ($cur_input.val() != "") {
                $parent.addClass('full-field');
            } else {
                $parent.removeClass('full-field');
            }

            $cur_input.on("change input", function(e) {
                if ($cur_input.val() != "") {
                    $parent.addClass('full-field');
                } else {
                    $parent.removeClass('full-field');
                }
            });

            $cur_input.focus(function(e) {
                $parent.addClass('full-field');
                $parent.addClass('focus-label');
            }).blur(function(e) {
                if ($(this).val() == "") {
                    $parent.removeClass('full-field');
                }
                $parent.removeClass('focus-label');
            });
        })
    };

    souriau.souriauPrj.addressBehavior = function (context, settings) {

        context = $(document);

        var $blockEdit = context.find('.js-block_edit');
        var $btn_open_addr = context.find('.btn-addr-open.js-edit-address-link');
        var $modBlock = context.find('.js-load-form');
        var $wrapperModBlock = context.find('.js-load-form-wrapper');
        var $timeAnnim = 400;
        var cur_height = 0;
        var is_loading = false;
        var $btn_to_hide;
        var loadFileUrl;

        $blockEdit.on('click', '.close-btn', function (e) {
            e.preventDefault();
            var $this = $(this);

            closeBlock(true);
        });

        $btn_open_addr.on('click', function (e) {
            e.stopPropagation();
            e.preventDefault();

            if (!is_loading) {
                var $this = $(this);

                if ($this.hasClass('active')) {
                    return false;
                }

                is_loading = true;
                $btn_to_hide = $this;
                loadFileUrl = $this.attr('href');
                closeBlock(false);
                is_loading = false;
            }
        });


        function loadBlock() {
            souriau.souriauPrj.labelBehavior(context);
            souriau.souriauPrj.customForm(context);

            cur_height = $modBlock.outerHeight() + 62;

            $wrapperModBlock.addClass('active');
            $modBlock.css('margin-top', -cur_height);

            $modBlock.animate({
                'margin-top': 0
            }, $timeAnnim);
        }

        function closeBlock(isOnlyClose) {
            if (!$modBlock.is(':empty')) {
                $wrapperModBlock.removeClass('active');
                cur_height = $modBlock.outerHeight() + 62;

                $modBlock.stop(true, false).animate({
                    'margin-top': -cur_height
                }, $timeAnnim, function () {
                    $blockEdit.find('.hide-btn').removeClass('hide-btn active');

                    if (!isOnlyClose) {
                        loadForm();
                    } else {
                        $modBlock.empty();
                        $('body, html').animate({scrollTop: $wrapperModBlock.offset().top - 150});
                    }
                });
            } else {
                $blockEdit.find('.hide-btn').removeClass('hide-btn active');

                if (!isOnlyClose) {
                    loadForm();
                }
            }
        }

        function loadForm() {
            $wrapperModBlock.find('.loader').addClass('active');

            if (typeof $btn_to_hide != 'undefined') {
                $btn_to_hide.addClass('hide-btn active');
            }

            $('body, html').animate({scrollTop: $wrapperModBlock.offset().top - 150});

            if (typeof loadFileUrl != 'undefined' && loadFileUrl != '' && loadFileUrl != "#") {
                souriau_main.ajax_call('#js-create-new-address', loadFileUrl);
                $wrapperModBlock.find('.loader').removeClass('active');
                loadBlock();
            }
        }

        context.find('#select-address-block').once('selectAddressBehavior', function () {

            var $this = $(this);
            var input_class = '.select-address-input';

            $this.find('.edit-link').on('click', function (e) {
                e.stopPropagation();
                e.preventDefault();

                $this.find('.edit-link').removeClass('hide-btn active');

                $(this).addClass('hide-btn active');

                $(this).closest('.b-address-item').find('input' + input_class).prop('checked', true).change();
                loadForm();

                $wrapperModBlock.find('.loader').removeClass('active');
                loadBlock();

                return false;
            });

            $this.find('.b-address-item').on('click', function (e) {
                e.stopPropagation();

                $(this).find('input' + input_class).prop('checked', true).change();
                $this.find('.edit-link').removeClass('hide-btn active');

                if ($wrapperModBlock.hasClass('active')) {
                    $wrapperModBlock.removeClass('active');
                    $modBlock.removeAttr('style');
                }
            });

            $this.find('input' + input_class).on('change', function(e) {
                $('.pane-page-messages').remove();
                if ($(this).val() == 'none') {
                    loadForm();

                    $this.find('.edit-link').removeClass('hide-btn active');

                    $wrapperModBlock.find('.loader').removeClass('active');
                    loadBlock();
                }
            });
        });
    };

    souriau.souriauPrj.masonry = function(context, settings) {

        $('.b-list-recent-news .news-wrapper').once('masonry', function () {
            var $this = $(this);
            var $items = $this.find(".item-recent-news");
            var isPluginInited = false;

            if ($items.length <= 0) {
                return;
            }

            $(window).resize(function(){
                onResize();
            }).trigger('resize');

            function onResize() {
                var mqA = window.matchMedia('only screen and (max-width: 767px)');
                var tqa = window.matchMedia('only screen and (max-width: 959px)');

                if (mqA.matches) {
                    if (isPluginInited) {
                        $this.masonry('destroy');
                        isPluginInited = false;
                    }
                } else {
                    if (!isPluginInited) {
                        setTimeout(function(){
                            $this.masonry();
                            isPluginInited = true;
                        }, 500);
                    }
                }
            }
        });

        var $loadMoreButton = $('#news-landing-news-list-load-more span');
        if ($loadMoreButton.length == 0) {
            return;
        }

        $loadMoreButton.once('news-landing-news-list-load-more').on('click', function(event) {
            event.preventDefault();

            var name = 'news-landing-news-list-load-more',
                url = $(this).data('ajax-url'),
                data = $('#views-exposed-form-souriau-news-news-most-recent').serialize(),
                page = $(this).data('page')
            ;

            data += '&page=' + page;
            souriau_main.ajax_call(name, url, data);
        });
    };

    souriau.souriauPrj.checkAll = function(context, settings) {

        $('.all-filter-wrapper', context).once('checkedAll', function () {
            var $this = $(this);
            var $filterAll = $this.find('.check-all');
            var $listFilters = $this.find('input[type="checkbox"]');

            $listFilters.on('click', function() {
                if ($(this).hasClass('check-all')) {
                    var is_checked = $(this).is(':checked');
                    if (!is_checked) {
                        return false;
                    } else {
                        $listFilters.not($(this)).prop('checked', false);
                    }
                } else {
                    $filterAll.prop('checked', false);
                }
            });
        });
    };

    // Attach proxy actions.
    souriau_main.attach_proxy = function (context, settings) {
      // Proxy clicks on cart summary.
      $(context).find('.souriau-proxy-click').once('souriau-proxy-click', function (delta) {
        $(this).click(function () {
          if (!$(this).hasClass('disabled')) {
            var target = $(this).parents('td').find('.element-hidden a.remove-link');
            $(target).click();
          }
        });
      });
    };

    // Attach minicart.
    souriau_main.attach_minicart = function (context, settings) {
      $(context).find('.b-cart').once('b-cart', function () {
        var data = "";
        var url = $('.b-cart').attr('data-ajax-url');
        var name = '.b-cart';
        // name, url, data, method, spam, unlock, skip_queue, custom_settings
        souriau_main.ajax_call(name, url, data, 'get', null, null, null, {"progress": {"type": "none"}});
      });
    };

    // Attach cookie consent.
    document.addEventListener('DOMContentLoaded', function () {
      cookieconsent.run({"notice_banner_type":"headline","consent_type":"implied","palette":"light","change_preferences_selector":"#changePreferences","language":"en","website_name":"souriau.com","cookies_policy_url":"https://www.souriau.com/en-en/privacy-statement#Use-of-Cookies"});
    });

    souriau.souriauPrj.comparePartNumbers = {
        cookieName: 'Drupal.visitor.part_numbers',
        cookieExpires: 30, //days

        add: function(partNumber) {
          var _this = this;
          partNumber = partNumber.toString();

          var part_numbers = [];
          if ($.cookie(_this.cookieName)) {
            part_numbers = $.cookie(_this.cookieName).split(',');
          }

          part_numbers.push(partNumber);
          _this._save(part_numbers);
        },

        remove: function(partNumber) {
          partNumber = partNumber.toString();
          var part_numbers = $.cookie(this.cookieName).split(',');
          var index = part_numbers.indexOf(partNumber);
          if (index >= 0) {
            delete part_numbers[index];
          }

          this._save(part_numbers);
          if (part_numbers.length < 3) {
            var html_data = '<div class="panel-pane pane-part-number-list"><div class="b-info-message text-center"><div class="container">You need to select at least 2 part numbers to start comparison</div></div></div>';
            $('div.b-compare').html(html_data);
          }
        },

        _save: function(partNumbers) {
          var _partNumbers = [];
          $.each(partNumbers, function (index, element) {
            if (typeof element != 'undefined' && element.length > 0) {
              _partNumbers.push(element);
            }
          });

          $.cookie(this.cookieName, _partNumbers.join(','), {
            expires: this.cookieExpires,
            path: '/'
          })
        }
    };

    souriau.souriauPrj.compareRemoveBehavior = function(context, settings) {
      $('.js-compare-remove-product').once('compare-remove-product').on('click', function (event) {
        event.preventDefault();
        var part_number_id = $(this).data('part-number-id');
        souriau.souriauPrj.comparePartNumbers.remove(part_number_id);
        var $compare = $('.b-compare');

        var $first_panel = $compare.find('.b-compare-first');
        var $second_panel = $compare.find('.b-compare-second');
        $first_panel.find('td[data-part-number-id="' + part_number_id + '"]').remove();
        $second_panel.find('td[data-part-number-id="' + part_number_id + '"]').remove();
        souriau.souriauPrj.calcRowHeight($second_panel);
      });
    };

    souriau.souriauPrj.autocomplete = function(context, settings) {
        // Do not use autocomplete from example.
        // @see souriau_common module.
        return;
    };

    // Override Drupal core validateExtension. Was added souriau.souriauPrj.confMessages().
    if(Drupal.file) {
      Drupal.file.validateExtension = function (event) {
        // Remove any previous errors.
        $('.file-upload-js-error').remove();

        // Add client side validation for the input[type=file].
        var extensionPattern = event.data.extensions.replace(/,\s*/g, '|');
        if (extensionPattern.length > 1 && this.value.length > 0) {
          var acceptableMatch = new RegExp('\\.(' + extensionPattern + ')$', 'gi');
          if (!acceptableMatch.test(this.value)) {
            var formManagedFile = $(this).closest('div.form-managed-file');
            var error = Drupal.t("The selected file %filename cannot be uploaded. Only files with the following extensions are allowed: %extensions.", {
              // According to the specifications of HTML5, a file upload control
              // should not reveal the real local path to the file that a user
              // has selected. Some web browsers implement this restriction by
              // replacing the local path with "C:\fakepath\", which can cause
              // confusion by leaving the user thinking perhaps Drupal could not
              // find the file because it messed up the file path. To avoid this
              // confusion, therefore, we strip out the bogus fakepath string.
              '%filename': this.value.replace('C:\\fakepath\\', ''),
              '%extensions': extensionPattern.replace(/\|/g, ', ')
            });
            formManagedFile.prepend('<div class="messages error file-upload-js-error" aria-live="polite">' + error + '</div>');
            // Additional styles.
            souriau.souriauPrj.confMessages(formManagedFile);
            return false;
          }
        }
      };
    }

    souriau.souriauPrj.changeView = function(context, settings) {
      context = $(context);

      context.find('.b-choose-view').once('changeView', function () {
        var $this = $(this);
        var $views = $this.find('a');
        var list_class = '';
        var $cur_list = $this.data('list-view');

        $views.each(function(){
            list_class = list_class + ' ' + $(this).data('view');
        });

        $views.on('click',function(e){
          e.preventDefault();

          if($(this).hasClass('active')) {
            return false;
          }

          $views.filter('.active').removeClass('active');
          $(this).addClass('active');
          $('#' + $cur_list).removeClass(list_class).addClass($views.filter('.active').data('view'));
          // Height update on view type selection.
          $('#' + $cur_list + '.b-view-results .b-product-item').matchHeight();
          if ($('body').find('.b-to-compare').length > 0) {
            var $b_compare = $('body').find('.b-to-compare');

            souriau.souriauPrj.checkStickyPosition($b_compare);
          }

          // Resize Search Images.
          var SearchResults = $this.parents('.tab-pane').find('.b-view-results');
          $.fn.resizeSearchImages(SearchResults);
        });
      });
    };

    $.fn.resizeSearchImages = function(context) {
      var $this = $(context);
      var index = 1;
      var images;
      var imageclass;

      if ($this.hasClass('list-view') && $this.hasClass('resize-table-view')) {
        $this.removeClass('resize-table-view');
        index = 1 / 0.938;
        imageclass = 'resize-list-view';
        images = $this.find('img').removeClass('resize-table-view');

      }
      if ($this.hasClass('table-view')) {
        $this.removeClass('resize-list-view');
        index = 0.938;
        imageclass = 'resize-table-view';
        images = $this.find('img').removeClass('resize-list-view');
      }

      if (!images) {
        return;
      }

      $this.addClass(imageclass);
      images.not('.' + imageclass).each(function() {
        var height = $(this).attr('height') * index;
        $( this ).attr('height', height);
        $( this).addClass(imageclass);
      });
    }

  souriau_main.postcard_click = function(context, settings) {
    $('body').on('click', '.b-item-dyn a', function(e){
      $('#informModal p.p_body').html($(this).parent().find('.hidden').html());
      $('#informModal img.p_image').attr('src', $(this).find('img').attr('src'));
      $('#informModal a.p_share').attr('href', $(this).data('p-share'));
    });
  }
  souriau_main.page_scroller = function(context, settings) {
    if ($('.scroll-section').length) {
      var sections = $('.scroll-section'), nav_height = $('.sticky-left').offset().top;
      // Left menu button click.
      $('.sticky-left li', context).once('page-scroller-li', function () {
        $(this).click(function() {
          var $el = $(this).find('a'), id = $el.attr('href');
          $('html, body').animate({
            scrollTop: $(id).offset().top - nav_height + 10
          }, 'slow');
          return false;
        });
      });
      $(window).on('scroll', function () {
        var cur_pos = $(this).scrollTop();
        sections.each(function() {
          var top = $(this).offset().top - nav_height,
          bottom = top + $(this).outerHeight();
          if (cur_pos >= top && cur_pos <= bottom) {
            $('.sticky-left').find('li').removeClass('active');
            sections.removeClass('active');

            $(this).addClass('active');
            $('.sticky-left').find('a[href="#'+$(this).attr('id')+'"]').parent().addClass('active');
          }
        });
      });
    }
    $('.agree-button').click(function() {
     Drupal.CTools.Modal.dismiss();
    });
  };
  // Webform contact form HR request notice.
  $('.webform-client-form #edit-submitted-category', context).once('contact-webform', function () {
    $(this).change(function() {
      if ($(this).val() == 'hr') {
        $('#edit-submitted-notice').show('slow');
      } else {
        $('#edit-submitted-notice').hide('slow');
      }
    });
  });

  if ($.cookie('Drupal.visitor.part_numbers') != null) {
    var count = $.cookie('Drupal.visitor.part_numbers').split(',').filter(String).length;
    if (count !== 0) {
      $('.b-to-compare').show();
      // Fix to make the sticky element appear.
      $(window).scrollTop($(window).scrollTop() + 1);
    }
  }
})(jQuery);
