var souriau = souriau || {};

(function ($){

souriau.souriauPrj = (function() { "use strict";

  var souriauPrj = {};

  souriauPrj.fastClick = function(context, settings) {
    $('body', context).once('fastClick', function() {
    //  FastClick && FastClick.attach(document.body);
    });
  };

  souriauPrj.checkStickyPosition = function($cur_block){
    var $wrapper_fixed = $cur_block.find('.b-to-fixed');

    if ($(window).scrollTop() + $(window).height() <= $cur_block.offset().top + $wrapper_fixed.outerHeight()) {
      $wrapper_fixed.css('position','fixed');
    } else {
      $wrapper_fixed.css('position','relative');
    }
  };

  souriauPrj.checkStickyMobile = function($cur_block) {
    var mqA = window.matchMedia('only screen and (max-width: 767px)');

    if (mqA.matches) {
      souriauPrj.checkStickyPosition($cur_block);
    }
  };

  souriauPrj.stickyCompare = function(context, settings) {
    context = $(context);

    context.find('.b-to-compare').once('stickyCompare', function () {
      var $this = $(this);

      souriauPrj.checkStickyPosition($this);

      $(window).on('scroll', function(){
        souriauPrj.checkStickyPosition($this);
      });

      $(window).on('resize orientationchange', function(){
        souriauPrj.checkStickyPosition($this);
      });

      $('a[data-toggle="tab"]').on('shown.bs.tab', function (e) {
        souriauPrj.checkStickyPosition($this);
      });
    });
  };

  souriauPrj.stickyViewAll = function(context, settings) {
    context = $(context);

    context.find('.view-all-wrapper').once('stickyViewAll', function () {
      var $this = $(this);
      var $link_view_all_results = $this.find('.link-view-all-results');

      $link_view_all_results.on('click', function(e){
        e.preventDefault();
        $(this).parents('.w-search').find('button.link-view-all-results').trigger('click');
      })

      souriauPrj.checkStickyMobile($this);

      $(window).on('scroll', function(){
        souriauPrj.checkStickyMobile($this);
      });

      $(window).on('resize orientationchange', function(){
        souriauPrj.checkStickyMobile($this);
      });
    });
  };

  souriauPrj.autocomplete = function(context, settings) {
    context = $(context);

    context.find('.autocomplete').once('autocomplete', function () {
      var $this = $(this);
      var $result_box = $('#b-search-autocomplete');
      var $view_all_link_wrapper = $('.view-all-wrapper');

      var availableTags = [
        "Test",
        "Test2",
        "Test3",
        "Test4",
        "Test4",
        "Test4"
      ];

      var $example_block = $('.example-autocomplete').html();

      $this.autocomplete({
        source: availableTags,
        minLength: 3,
        appendTo: $result_box,
        open: function( event, ui ) {
          souriauPrj.checkStickyMobile($view_all_link_wrapper);
        },
        close: function( event, ui ) {
          souriauPrj.checkStickyMobile($view_all_link_wrapper);
        }
      })
      .autocomplete( "instance" )._renderItem = function( ul, item ) {
        return $( "<li>" ).append($example_block).appendTo( ul );
      };
    });
  };

  souriauPrj.checkLinkvisible = function(context, settings) {
    context = $(context);

    context.find('.link-view-all-results').once('checkLinkvisible', function () {
      var $this = $(this);
      var $autocomplete = $('body').find('input.autocomplete');
      var cnt_symbols = 1;

      check_behavior();

      $autocomplete.on("change input", function(e) {
        check_behavior();
      });

      function check_behavior(){
        if ($autocomplete.val().length < cnt_symbols) {
          $this.addClass('hidden-btn');
        } else {
          $this.removeClass('hidden-btn');
        }
      }
    });
  };

  souriauPrj.customForm = function(context, settings) {
    context = $(context);

    context.find('form, .b-inner-form').once('customForms', function () {
      $(this).each(function(){
        jcf.setOptions('Select', {
          wrapNative: false,
          wrapNativeOnMobile: false,
          useCustomScroll: true,
          fakeDropInBody: false,
          fakeDropStructure: '<div class="jcf-select-drop"><div class="jcf-select-drop-content"><div class="w-btns"><a class="link-check-all" href="javascript:;">'+Drupal.t("check all")+'</a><a class="link-uncheck-all" href="javascript:;">'+Drupal.t("uncheck all")+'</a></div></div></div>'
        });

        jcf.replaceAll();
      });

      $('body').on('click', '.link-check-all' ,function(e){
        e.preventDefault();
        e.stopPropagation();

        var $this = $(this);
        var $cur_select = $this.parents('.jcf-select').prev().find('option').prop("selected", 'true');
        jcf.replaceAll();
      });

      $('body').on('click', '.link-uncheck-all' ,function(e){
        e.preventDefault();
        e.stopPropagation();

        var $this = $(this);
        var $cur_select = $this.parents('.jcf-select').prev().find('option:selected').removeAttr('selected');
        jcf.replaceAll();
      });
    });
  };

  souriauPrj.langSelect = function(context, settings) {
    context = $(context);

    context.find('.lang-select').once('lang-select', function () {
      $(this).each(function(){
        var wrapper = $(this);
        var ul = wrapper.find('ul');
        var list = ul.find('li a');
        var selectedItem = list.find('[data-selected = "selected"]').length ? list.find('[data-selected = "selected"]') : list.find('>:first-child');
        var label = wrapper.find('.lang-label');

        label.html(selectedItem.html());

        label.click(function(e) {
          e.preventDefault();
          ul.toggle();
        });

        ul.toggle = function() {
          if (ul.hasClass('active')) ul.removeClass('active');
          else {
            ul.attr('style', '');
            ul.addClass('active');
            ul.reposition();
          }
        };

        ul.reposition = function () {
          var ulHeight = ul.outerHeight(),
              ulBounds = ul[0].getBoundingClientRect(),
              winHeight = $(window).height();

          if (ulHeight > winHeight - ulBounds.top) {
            ul.css({
              top: 'auto',
              bottom: '100%'
            });
          }
        };

        list.click(function() {
          list.attr('data-selected', '');
          $(this).attr('data-selected', 'selected');
          label.html($(this).html());
          ul.toggle();
        });

        $("body").click(function(){
          ul.removeClass('active');
        });
        
        wrapper.click(function() {
          return false;
        })
      });
    });
  };

  souriauPrj.openSearch = function(context, settings) {
    var offline_params = Drupal.settings.souriau_common.search_offline_params;
    // Redirect users if the eCatlog is disabled.
    $('.link_search').on('click', function(e){
      if (offline_params.disabled) {
        e.preventDefault();
        e.stopPropagation();
        window.location = offline_params.redirect_url;
        return;
      }
    });
    context = $(context);
    context.find('.search-link').once('openSearch', function () {
      var $blockToOpen = $('#' + $(this).attr('data-open-search'));
      var h_block = $blockToOpen.children('div').outerHeight();
      var $fixed_poll = $('.b-poll');
      var $close_btn = $blockToOpen.find('.close-btn');

      $close_btn.on('click', function(e){
        e.preventDefault();
        e.stopPropagation();

        searchBehavior($(this));
      });

      $(this).on('click', function(e){
        e.preventDefault();
        e.stopPropagation();
        // Redirect users if the eCatlog is disabled.
        if (offline_params.disabled) {
          window.location = offline_params.redirect_url;
          return;
        }

        var $this = $(this);
        if (!$blockToOpen.hasClass('b-always-visible')) {
          searchBehavior($this);
        } else {
          setTimeout(function(){
            $blockToOpen.find('input[type=text]').focus();
          },100)
        }
      });

      function searchBehavior($btn) {
        ///remove double click
        if( $btn.hasClass("clicked") ){
          return false;
        }
        $btn.addClass("clicked");
        ///

        $blockToOpen.toggleClass('visible-search');

        if ($blockToOpen.hasClass('visible-search')) {
          if ($fixed_poll.length) {$fixed_poll[0].style.marginTop = h_block+'px';}

          setTimeout(function(){
            $blockToOpen.find('input[type=text]').focus();
          },360);
        } else {
         // $blockToOpen.find('input[type=text]').val('');
          $blockToOpen.find('.link-view-all-results').addClass('hidden-btn');

          if ($fixed_poll.length) {$fixed_poll[0].style.marginTop = '0px';}
        };

        ///remove double click
        setTimeout(function(){
          $btn.removeClass("clicked");
        },360);
        ///
      };
    });
  };

  souriauPrj.clickableRow = function(context, settings) {
    context = $(context);

    context.find('.clickable-row').once('clickableRow', function () {
      $(this).on('click', function(e){
        e.preventDefault();
        var $this = $(this);

        if ($this.data('href') !=undefined || $this.data('href') != "") {
          if ($this.hasClass('new-tab')) {
            window.open($this.data("href"), '_blank');
            window.focus();
          } else {
            window.document.location = $this.data("href");
          }
        }
      })
    });
  };

  souriauPrj.menuBehavior = function(context, settings) {
    context = $(context);

    context.find('.w-menu').once('menu', function () {
      var $this = $(this);
      var $block_menu = $this.find('.block-header-nav');

      ariaBehavior();

      $this.find('.icon-header-nav-mobile').on('click', function(){
        $('html').toggleClass('nav-active');
        $block_menu.attr('aria-hidden', 'false');
      });

      $this.find('.close-btn').on('click', function(){
        closeMenu();
      });

      $('body').on('click', function(e){
        var target = e.target;

        if(!$(target).closest('.w-menu').length > 0) {
          closeMenu();
        }
      })

      $(window).on('resize orientationchange', function() {
        ariaBehavior();
      });

      function closeMenu() {
        $('html').removeClass('nav-active');
        $block_menu.attr('aria-hidden', 'true');
        $block_menu.find('.open-menu').removeClass('open-menu').find('a[aria-expanded]').attr('aria-expanded', 'false');
      }

      function ariaBehavior() {
        var mqA = window.matchMedia('only screen and (min-width: 960px)');

        if(mqA.matches){
          $block_menu.attr('aria-hidden', 'false');
          $block_menu.find('.open-menu').removeClass('open-menu').find('a[aria-expanded]').attr('aria-expanded', 'false');
          var $search = $('.w-search').find('input');

          $block_menu.find('nav li').mouseenter(function(){
            var attr_control = $(this).children('a').attr('aria-controls');

            if (attr_control != undefined) {
              $(this).children('a').attr('aria-expanded', 'true');
            }
          })
          .mouseleave(function() {
            var attr_control = $(this).children('a').attr('aria-controls');
            $search.focus();

            if (attr_control != undefined) {
              $(this).children('a').attr('aria-expanded', 'false');
            }
          });
        } else {
          $block_menu.attr('aria-hidden', 'true');
          $block_menu.find('nav li').unbind('mouseenter');
          $block_menu.find('nav li').unbind('mouseleave');
          $('.b-sub-menu').css('visibility', 'hidden');

          var attr_control = $(this).children('a').attr('aria-controls');

          if (attr_control != undefined) {
            $(this).children('a').attr('aria-expanded', 'false');
          }

          $block_menu.find('.arrow').on('click', function(e){
            e.preventDefault();
            e.stopPropagation();

            var is_open  = $(this).parent('li').hasClass('open-menu');
            $('.b-sub-menu').css('visibility', 'hidden');
            if (!is_open) {
              $block_menu.find('.open-menu').removeClass('open-menu').find('a[aria-expanded]').attr('aria-expanded', 'false');
              $(this).prev('a').attr('aria-expanded', 'true').parent('li').addClass('open-menu');
              $block_menu.find('.open-menu').find('.b-sub-menu').css('visibility', 'visible');
            } else {
              $(this).prev('a').attr('aria-expanded', 'false').parent('li').removeClass('open-menu');
            }
          });
        }
      }
    });
  };


  souriauPrj.ariaChange = function(context, settings) {
    context = $(context);

    context.find('.change-aria').once('change-aria', function () {
      var $this = $(this);
      var $parent = $($this.data('parent'));

      $parent.hover(function(){
        $this.attr('aria-hidden', 'false');
      }, function(){
        $this.attr('aria-hidden', 'true');
      })
    });
  };

  souriauPrj.slider = function(context, settings) {
    context = $(context);

    context.find('.b-top-products .product-items, .b-part-number-products .product-items').once('slider', function () {
      var $this = $(this);

      var mqA = window.matchMedia('only screen and (max-width: 767px)');

      if (mqA.matches) {
        slider($this);
      }

      $(window).on('resize orientationchange', function() {
        mqA = window.matchMedia('only screen and (max-width: 767px)');
        var isSlider = $this.hasClass('slick-slider');

        if (!mqA.matches && isSlider) {
          $this.slick("unslick");
        }
        else if (mqA.matches && !isSlider){
          slider($this);
        }
      });

      function slider($cur_elem){
        $cur_elem.slick({
          dots: true,
          arrows: false,
          infinite: true,
          speed: 300,
          slidesToShow: 1
        });
      }
    });
  };

  souriauPrj.contactsSlider = function(context, settings) {
    context = $(context);

    context.find('.slider-address').once('contactsSlider', function () {
      var $this = $(this);

      $this.slick({
        dots: false,
        arrows: true,
        infinite: true,
        speed: 300,
        slidesToShow: 2,
        slidesToScroll: 2,
        prevArrow: $('.prev'),
        nextArrow: $('.next'),
        responsive: [{
          breakpoint: 767,
          settings: {
            slidesToShow: 1,
            slidesToScroll: 1
          }
        }]
      });
    });
  };

  souriauPrj.mainSlider = function(context, settings) {
    context = $(context);

    context.find('.b-main-slider').once('mainSlider', function () {
      var $this = $(this);

      if ( !Modernizr.objectfit ) {
        var selectors = $('.slide .pic img');

        $(selectors, context).once('initObjectFit').each(function() {
          var $this = $(this);
          var imgUrl;

          imgUrl = $this.prop('src');
          if (imgUrl) {
            $this.parents('figure').css('backgroundImage', 'url(' + imgUrl + ')');
          };
        });
      }

      $this.slick({
        dots: true,
        dotsClass: 'slider-pagination',
        arrows: false,
        infinite: true,
        autoplaySpeed: 5000,
        autoplay: true,
        slidesToShow: 1,
        slidesToScroll: 1,
        customPaging : function(slider, i) {
          var title = $(slider.$slides[i]).data('pagination');
          return '<a href="javascript:;">'+title+'</a>';
        }
      });
    });
  };

  souriauPrj.logInSlider = function(context, settings) {
    context = $(context);

    context.find('.b-sign-in-up .align-container').once('slider', function () {
      var $this = $(this);
      var mqA = window.matchMedia('only screen and (max-width: 767px)');

      if (mqA.matches) {
        slider($this);
      }

      $(window).on('resize orientationchange', function() {
        mqA = window.matchMedia('only screen and (max-width: 767px)');
        var isSlider = $this.hasClass('slick-slider');

        if (!mqA.matches && isSlider) {
          $this.slick("unslick");
        }
        else if (mqA.matches && !isSlider){
          slider($this);
        }
      });

      function slider($cur_elem){
        $cur_elem.on('init', function(event, slick){
          $('#b-tabs-navigation a').filter('[data-to-open = '+$cur_elem.find('.slick-slide.slick-current').data('open')+']').addClass('active-tab');
        });

        $cur_elem.on('afterChange', function(event, slick, currentSlide){
          $('#b-tabs-navigation a.active-tab').removeClass('active-tab');
          $('#b-tabs-navigation a').filter('[data-to-open = '+$cur_elem.find('.slick-slide.slick-current').data('open')+']').addClass('active-tab');
        });

        $('#b-tabs-navigation a').on('click', function(){
          if ($(this).hasClass('active-tab')) {return false;}

          var index_slide = $cur_elem.find('.slick-slide').filter('[data-open = '+ $(this).data('to-open') +']').data('slick-index');
          $cur_elem.slick('slickGoTo', parseInt(index_slide));
          return false;
        })

        $cur_elem.slick({
          dots: true,
          arrows: false,
          infinite: true,
          speed: 300,
          slidesToShow: 1,
          initialSlide: 0
        });
      }
    });
  };

  souriauPrj.appList = function(context, settings) {
    context = $(context);

    context.find('.b-app-list').once('appList', function () {
      var $this = $(this);
      var count = $this.find('.item').length;

      if (count % 3 == 1) {
        for (var i = count - 1; i > count - 5; i--) {
          $this.find('.item').eq(i).addClass("lg-two-line");
        }
      }

      if (count % 3 == 2) {
        for (var i = count - 1; i > count - 3; i--) {
          $this.find('.item').eq(i).addClass("lg-two-line");
        }
      }

      if (count % 2 == 1) {
        $this.find('.item').eq(count-1).addClass("sm-one-line");
      }
    });
  };

  souriauPrj.moreVisible = function(context, settings) {
    context = $(context);

    context.find('.b-downloads-links .more-visible').once('moreVisible', function () {
      var $this = $(this);
      var block_attr = $(this).data('block');

      var $list_blocks = context.find('.b-downloads-links').filter('[data-attr="'+ block_attr+'"]');
      var link_text = $this.text();

      $this.click(function(e){
        $list_blocks.find('.hide-link').toggleClass('visible-link');
        $list_blocks.find('.more-visible').text(($this.text() == Drupal.t(link_text)) ? Drupal.t('- Hide') : Drupal.t(link_text));
        return false;
      })
    });

    $('.b-questions .panel').on('show.bs.collapse', function(e) {
      $(this).find('.panel-heading').addClass('active-panel');
    })
    .on('hide.bs.collapse', function(e) {
      $(this).find('.panel-heading').removeClass('active-panel');
    });
  };

  souriauPrj.video = function(context, settings) {
    context = $(context);

    context.find('.b-video').once('video-resize', function () {
      var $this = $(this);
      var $cur_video = $this.find('iframe');

      var width_video = $cur_video.attr('width');
      var height_video = $cur_video.attr('height');
      var width_wrapper = $(this).width();

      var timerId;
      $(window).resize(function() {
        clearTimeout(timerId);
        timerId = setTimeout(function() {
            resize();
        }, 90);
      });

      resize();

      function resize(){
        width_wrapper = parseInt($this.width());

        var persent = width_wrapper / width_video;
        var new_height = persent * height_video;
        $cur_video.height(new_height);
      }
    });
  };

  souriauPrj.labelBehavior = function(context, settings) {
    context = $(context);

    context.find('.b-form, .b-inner-form').once('labelBehavior', function () {
      var $this = $(this);
      var $inputs = $this.find('input[type="text"], input[type="email"], input[type="password"], textarea');

      if ('WebkitAppearance' in document.documentElement.style) {
        var chkReadyState = setInterval(function() {
          if (document.readyState == "complete" && $this.is(':visible')) {
            // clear the interval
            clearInterval(chkReadyState);

            $this.find('input:-webkit-autofill').each(function(){
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
    });
  };

  souriauPrj.autoLoadPopup = function(context, settings) {
    context = $(context);

    context.find('.autoload[data-toggle = modal]').once('autoload', function () {
      var $this = $(this);

      $this.trigger('click');
    });
  };

  souriauPrj.modalPopupOpen = function(context, settings) {
    context = $(context);

    context.find('body').once('loadPopup', function () {
      var $this = $(this);
      var scrollLocation;

      if( navigator.userAgent.match(/iPhone|iPad|iPod/i) ) {
        $('.modal').on('show.bs.modal', function() {
          var $cur_modal = $(this);
          setTimeout(function () {

            scrollLocation = $(window).scrollTop();
            $cur_modal.addClass('modal-ios').height($(window).height()).css({'margin-top': scrollLocation + 'px'});
          }, 0);
        });

        $('input').on('blur', function(){
          setTimeout(function() {
            // This causes iOS to refresh, fixes problems when virtual keyboard closes
            $(window).scrollLeft(0);

            var $focused = $(':focus');
            // Needed in case user clicks directly from one input to another
            if(!$focused.is('input')) {
              // Otherwise reset the scoll to the top of the modal
              $(window).scrollTop(scrollLocation);
            }
          }, 0);
        })
      }

      $(".btn[data-toggle='modal']").click(function(e){
        e.preventDefault();

        $(this).closest(".modal").removeClass('fade').modal('hide').addClass('fade');
        var child_popup = $(this).data('child-target');
        setTimeout(function(){ $(child_popup).modal('show'); }, 1);
      });
    });
  };

  souriauPrj.editableBlock = function(context, settings) {
    context = $(context);

    context.find('.w-editable').once('editable', function () {
      var $this = $(this);
      var default_empty_text = Drupal.t('Please add description');

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

      $this.find(".b-editable-area").each(function() {
        var $cur_elem = $(this);
        var empty_title = $cur_elem.data('empty-title');

        if(empty_title == undefined || empty_title == "") {
          empty_title = default_empty_text;
        }

        var val = $.trim($cur_elem.text());

        if(val == '') {
          $cur_elem.text(empty_title);
        }

        $cur_elem.on('click',function(e){
          e.preventDefault();
          e.stopPropagation();

          if ($cur_elem.hasClass('ico-edit')){
            $cur_elem.addClass('hide');
          }

          $this.addClass('editable');

          var val = $.trim($cur_elem.text());

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
        });
      });
    });
  };

  souriauPrj.addressBehavior = function(context, settings) {
    context = $(context);

    context.find('.js-block_edit').once('addressBehavior', function () {
      var $blockEdit = $(this);
      var $btn_open_addr = $(this).find('.btn-addr-open');
      var $modBlock = $(this).find('.js-load-form');
      var $wrapperModBlock = $(this).find('.js-load-form-wrapper');
      var $timeAnnim = 400;
      var cur_height = 0;
      var is_loading = false;
      var $btn_to_hide;
      var loadFileUrl;

      $blockEdit.on('click', '.close-btn', function(e){
        e.preventDefault();
        var $this = $(this);

        closeBlock(true);
      });

      $btn_open_addr.on('click', function(e) {
        e.stopPropagation();
        e.preventDefault();

        if(!is_loading) {
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


      function loadBlock(){
        souriauPrj.labelBehavior(context);
        souriauPrj.customForm(context);

        cur_height = $modBlock.outerHeight() + 62;

        $wrapperModBlock.addClass('active');
        $modBlock.css('margin-top', -cur_height);

        $modBlock.animate({
          'margin-top': 0
        }, $timeAnnim);
      };

      function closeBlock(isOnlyClose){
        if (!$modBlock.is(':empty')) {
          $wrapperModBlock.removeClass('active');
          cur_height = $modBlock.outerHeight() + 62;

          $modBlock.stop(true, false).animate({
            'margin-top': -cur_height
          }, $timeAnnim, function(){
            $blockEdit.find('.hide-btn').removeClass('hide-btn active');

            if (!isOnlyClose) {
              loadFile();
            } else {
              $modBlock.empty();
              $('body, html').animate({scrollTop: $wrapperModBlock.offset().top - 150});
            }
          });
        } else {
          $blockEdit.find('.hide-btn').removeClass('hide-btn active');

          if (!isOnlyClose) {
            loadFile();
          }
        }
      }

      function loadFile() {
        $wrapperModBlock.find('.loader').addClass('active');
        $btn_to_hide.addClass('hide-btn active');

        $('body, html').animate({scrollTop: $wrapperModBlock.offset().top - 150});

        if (loadFileUrl != '' && loadFileUrl!="#") {
          $modBlock.load(loadFileUrl, function(response, status, xhr) {
            if(status == 'success'){
              $wrapperModBlock.find('.loader').removeClass('active');
              loadBlock();
            }
          });
        }
      }

      context.find('#select-address-block').once('selectAddressBehavior', function () {
        var $this = $(this);
        var input_class = '.select-address-input';

        //if new address block will have cancel button this block with code will be need
       /* $this.on('click','.close-btn',function(){
          if($this.find('.b-create-new-address input:radio').is(':checked')) {
            $this.find('.b-create-new-address input:radio').prop('checked', false);
            jcf.refreshAll();
          }
        })*/

        $this.find('input'+input_class).change(function(){
          var $select_input = $(this);

          if ($select_input.closest('.b-create-new-address').length) {
            $this.find('label[for='+$(this).attr('id')+']').find('.btn-addr-open').click();

          } else {
            if($this.find('.close-btn').length) {
              $('.close-btn').trigger('click');
            }
            else {
              closeBlock(true);
            }
          }
        });

        $this.find('.edit-link').click(function(){
          $(this).closest('.b-address-item').find('input'+input_class).prop('checked', true);
          jcf.refreshAll();
        })

        $this.find('.b-address-item').click(function(e){
          $(this).find('input'+input_class).prop('checked', true).change();
          jcf.refreshAll();
        })
      })
    });
  };

  souriauPrj.quizz = function(context, settings) {
    context = $(context);

    context.find('.b-beginner-steps').once('quizz', function () {
      var $main_block = $(this);
      var $steps_wrapper = $main_block.find('.w-steps');
      var $first_step = $main_block.find('.b-step-1');
      var $back_to_app = $main_block.find('.back-to-app');

      //default settings
      $first_step.attr('data-cur-height', $first_step.outerHeight());
      $main_block.height($first_step.attr('data-cur-height'));

      //select application
      $main_block.find('.select-app').click(function(e){
        e.preventDefault();
        var cur_app = $(this).attr('href');

        //load application
        souriauPrj.quizzLoad(cur_app, $main_block, $steps_wrapper);
      });

      // back to applications
      $('body').on('click', '.back-to-app' ,function(e){
        e.preventDefault();

        $main_block.height($first_step.attr('data-cur-height'));
        $steps_wrapper.css('margin-top', 0);
        $main_block.find('.selected-step').removeClass('selected-step').attr('aria-hidden', 'true');
        $first_step.addClass('selected-step').attr('aria-hidden', 'false');
      });


      $(window).on('resize orientationchange', function() {
        $steps_wrapper.find('div[class*=b-step-]').each(function(){
          $(this).attr('data-cur-height', $(this).outerHeight());
        });

        $main_block.height($main_block.find('.selected-step').attr('data-cur-height'));

        if ($main_block.find('.selected-step').hasClass('b-step-2')) {
          $steps_wrapper.css('margin-top', $first_step.attr('data-cur-height') * -1);
        };
      });
    });
  };

  souriauPrj.quizzLoad = function(cur_app, $main_block, $steps_wrapper) {
    $main_block.find('.b-step-2').load(cur_app, function(response, status, xhr) {
      if(status == 'success'){
        souriau.souriauPrj.bannerImages($(this));
        souriauPrj.quizzLoadSuccess($(this), $main_block, $steps_wrapper);
      }
    });
  };

  souriauPrj.quizzLoadSuccess = function($load_step, $main_block, $steps_wrapper) {
    $load_step.attr('data-cur-height', $load_step.outerHeight());
    $main_block.height($load_step.attr('data-cur-height'));

    $steps_wrapper.css('margin-top', $main_block.find('.selected-step').attr('data-cur-height') * -1);
    $main_block.find('.selected-step').removeClass('selected-step').attr('aria-hidden', 'true');
    $load_step.addClass('selected-step').attr('aria-hidden', 'false');
  }

  souriauPrj.tableAccordion = function(context, settings) {
    context = $(context);

    context.find('.table-accordion').once('table-accordion', function () {
      var $this = $(this);

      $this.find('.collapse').on('show.bs.collapse', function (e) {
        var actives = $this.find('.in, .collapsing');
        actives.each( function (index, element) {
          $(element).collapse('hide');
        })
      })
    });
  };

  souriauPrj.bannerImages = function(context, settings) {
    context = $(context);

    context.find('.w-banner-block .b-banner').once('bannerImages', function () {
      var $this = $(this);
      var img_url = $this.find("img").attr('src');

      if (img_url != undefined && img_url != '') {
        $this.css('background-image', 'url("'+img_url+'")');
      }
    });
  };

  souriauPrj.confMessages = function(context, settings) {
    context = $(context);

    context.find('.messages').once('confMessages', function () {
      var $this = $(this);
      var $cur_obj = $this[0];
      var $close_btn;
      var sub_class;

      $this.append('<a class="close-btn"><span class="glyphicon glyphicon-remove" aria-hidden="true"></span><span class="screen-reader-text">Close message</span></a>');
      $close_btn = $this.find('.close-btn');

      $close_btn.on('click', function () {
        $cur_obj.style.opacity = 0;
        $cur_obj.style.height = 0;
        $cur_obj.style.paddingTop = 0;
        $cur_obj.style.paddingBottom = 0;
        $cur_obj.style.marginTop = 0;
        $cur_obj.style.marginBottom = 0;

        setTimeout(function(){
          $this.remove();
        }, 300);
      })

      if ($this.hasClass('status')) {
        sub_class = 'glyphicon-ok';
      } else if ($this.hasClass('warning')) {
        sub_class = 'glyphicon-alert';
      } else if ($this.hasClass('error')) {
        sub_class = 'glyphicon-remove';
      }

      $this.append('<div class="b-ico"><span class="glyphicon '+sub_class+'" aria-hidden="true"></span></div>');
    })
  };

  souriauPrj.matchHeight = function(context, settings) {
    context = $(context);

    context.find('.matchHeight').once('matchHeight', function () {
      var $this = $(this);

      $this.find('.item-row').matchHeight();
    });
  };

  souriauPrj.clearFilters = function(context, settings) {
    context = $(context);

    context.find('.clear-filter').once('clearFilters', function () {
      var $this = $(this);

      $this.on('click', function(e){
        e.preventDefault();
        var $block_clear = $(this).data('block-clear');

        $('#'+ $block_clear).find('input[type="checkbox"], input[type="radio"]').prop('checked', '');
        $('#'+ $block_clear).find('option:selected').removeAttr("selected");
        jcf.refreshAll();
      })
    });
  };

  souriauPrj.checkAll = function(context, settings) {
    context = $(context);

    context.find('.all-filter-wrapper').once('checkedAll', function () {
      var $this = $(this);
      var $filterAll = $this.find('.check-all');
      var $listFilters = $this.find('input[type="checkbox"]');

      $listFilters.on('change', function(){
        checkAll($(this));
      })

      function checkAll($cur_checkbox) {
        if ($cur_checkbox.is(':checked')) {
          if ($cur_checkbox.hasClass('check-all')) {
            $this.find('input[type="checkbox"]').not($cur_checkbox).prop('checked', '');
          } else {
            $filterAll.prop('checked', '');
          }
        }

        jcf.refreshAll();
      }
    });
  };

  souriauPrj.openListTags = function(context, settings) {
    context = $(context);

    context.find('.list-tags').once('listTags', function () {
      var $this = $(this);

      $this.find('.view-all-tags').click(function(e){
        e.preventDefault();

        $this.find('.hide-tag').toggleClass('visible');
        $(this).hide();

        if ($this.parents('.masonry-processed').length) {
          var msnry = Masonry.data( $this.parents('.masonry-processed')[0] );

          if(msnry != undefined) {
            $(msnry.element).masonry('layout');
          }
        }

        if ($this.closest("[data-mh]").length) {
          $.fn.matchHeight._update();
        }
      });
    });
  };

  souriauPrj.addToFavourite = function(context, settings) {
    context = $(context);

    context.find('.link-favourite').once('favoutite', function () {
      var $this = $(this);

      $this.click(function(e){
        e.preventDefault();

        $this.toggleClass('active');
      });
    });
  };

  souriauPrj.changeView = function(context, settings) {
    context = $(context);

    context.find('.b-choose-view').once('changeView', function () {
      var $this = $(this);
      var $views = $this.find('a');
      var list_class = '';
      var $cur_list = $this.data('list-view');

      $views.each(function(){
        list_class = list_class + ' ' + $(this).data('view');
      })

      $views.on('click',function(e){
        e.preventDefault();

        if($(this).hasClass('active')) {
          return false;
        }

        $views.filter('.active').removeClass('active');
        $(this).addClass('active');
        $('#' + $cur_list).removeClass(list_class).addClass($views.filter('.active').data('view'));


        $.fn.matchHeight._update();

        if ($('body').find('.b-to-compare').length > 0) {
          var $b_compare = $('body').find('.b-to-compare');

          souriauPrj.checkStickyPosition($b_compare);
        }
      });
    });
  };

  souriauPrj.addToCompare = function(context, settings) {
    context = $(context);

    context.find('.compare-link').once('addToCompare', function () {
      var $this = $(this);

      $this.click(function(e){
        e.preventDefault();

        $this.toggleClass('active');
      });
    });
  };

  souriauPrj.openFilters = function(context, settings) {
    context = $(context);

    context.find('.link-filter').once('openFilters', function () {
      var $this = $(this);
      var $filter_block = $('#'+$(this).data('filter-open'));

      setTimeout(function(){
        souriauPrj.caclIndent($filter_block);
      }, 100);

      $this.on('click', function(e){
        e.preventDefault();
        $('body').addClass('fixed-body');
        $filter_block.attr('aria-hidden', 'false').addClass('open');
      });

      $filter_block.find('.close-link').on('click', function(){
        souriauPrj.closeMenu($filter_block);
      });

      $('.close-filters').on('click', function(){
        souriauPrj.closeMenu($filter_block);
      });

      $(window).on('resize orientationchange', function() {
        souriauPrj.caclIndent($filter_block);
      });
    });


  };

  // Code to make sliding filters for download center in mobile devices.
  souriauPrj.closeFilters = function(context, settings) {
    context = $(context);
    context.find('.filter-close').once('closeFilters', function () {
      var $this = $(this);
      var $close_btn = $this.find('.close-link');
      $close_btn.click(function(e) {
        $this.parent("#treeview_container").css({
          "-webkit-animation": "slide-out 0.5s forwards",
          "-ms-animation": "slide-out 0.5s forwards",
          "-moz-animation": "slide-out 0.5s forwards",
          "-o-animation": "slide-out 0.5s forwards",
          "animation": "slide-out 0.5s forwards",
        }).animate({opacity:1}, "slow");
        $("#filter-nav-mobile").find("a.tree-filter").css({
          "display": "block",
        }).animate({opacity:1}, "slow");
        $('body').removeClass('fixed-body');
      });
    });
 };

  souriauPrj.closeMenu = function($filter_block) {
    $('body').removeClass('fixed-body');
    $filter_block.attr('aria-hidden', 'true');
    $filter_block.removeClass('open');
  };

  souriauPrj.caclIndent = function($filter_block) {
    var $header_h = $filter_block.find('.b-header').outerHeight(true);
    var $wrapper = $filter_block.find('.wrapper');

    $wrapper.css('paddingTop', $header_h);
  };

  souriauPrj.removeFilter = function(context, settings) {
    context = $(context);

    context.find('.filter-item').once('removeFilter', function () {
      var $this = $(this);
      var $close_btn = $this.find('.close-link');

      $close_btn.click(function(e){
        e.preventDefault();

        $this.remove();

        if ($('body').find('.b-to-compare').length > 0) {
          var $b_compare = $('body').find('.b-to-compare');

          souriauPrj.checkStickyPosition($b_compare);
        }
      });
    });
  };

  souriauPrj.masonry = function(context, settings) {
    context = $(context);

    context.find('.b-list-recent-news .news-wrapper').once('masonry', function () {
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
  };

  souriauPrj.compareBehavior = function(context, settings) {
    context = $(context);

    context.find('.b-compare').once('compare', function () {
      var $this = $(this);
      var $first_panel = $this.find('.b-compare-first');
      var $second_panel = $this.find('.b-compare-second');
      var f_panel_offset = $first_panel.offset();
      var fixed = false;

      souriauPrj.calcRowHeight($second_panel);

      $first_panel.find(".compare_scroller").scroll(function(){
        $second_panel.find(".compare_scroller").scrollLeft($first_panel.find(".compare_scroller").scrollLeft());
      });


      $(window).on('scroll', function(){
        if($(this).scrollTop() >= f_panel_offset.top && $(this).scrollTop() <= ($second_panel.offset().top + $second_panel.height() - parseInt($second_panel.css('marginTop')) - $first_panel.height())){
          if(!fixed){
            $first_panel.addClass('hide_el');
            var f_panel_height = $first_panel.find('.fixed').height();
            fixed = true;
          }
          $first_panel.find('.fixed').addClass('fix_compare');
          $second_panel.css({'margin-top': f_panel_height});
        }
        else{
          $first_panel.find('.fixed').removeClass('fix_compare');
          $first_panel.removeClass('hide_el');
          $second_panel.css({'margin-top':'0px'});
          fixed = false;
        }
      })
    });
  };

  souriauPrj.tableWrapper = function(context, settings) {
    context = $(context);

    context.find('.main-content table').once('tableWrapper', function () {
      var $this = $(this);
      var exclude_list = '.b-compare-common';

      if (!$this.parent('.w-table').length > 0 && !$this.closest(exclude_list).length > 0) {
        $this.wrapAll('<div class="w-table"></div>');
      }
    });
  };

  // Fix filter display issue while resizing window from small screen to large.
  souriauPrj.resizeFilterDisplay = function(context, settings) {
    context = $(context);
    context.find('#treeview_container').once('resizeFilterDisplay', function () {
      var viewportWidth = $(window).width();
      if (viewportWidth > 600) {
        $("#treeview_container").css("animation","none");
        $("#treeview_container .filter-close").addClass("hidden");
      }
      $(window).resize(function () {
        if (viewportWidth > 600) {
          $("#treeview_container").css("animation","none");
          $("#treeview_container .filter-close").addClass("hidden");
        }
      });
    });
  };

  souriauPrj.calcRowHeight = function($cur_panel) {
    var $panel = $cur_panel;
    var $left_part = $panel.find('.b-compare-left');
    var $right_part = $panel.find('.b-compare-right');

    $left_part.find('tr').each(function(){

      var $el = $(this);
      var index = $el.index();
      var $right_el = $right_part.find('tr').eq(index);

      var l_height = $el.outerHeight();
      var r_height = $right_el.outerHeight();
      var bl_height = (l_height > r_height) ? l_height : r_height;

      var l_div = $el.find('div');
      var r_div = $right_el.find('div');

      l_div.css({height: bl_height});
      r_div.css({height: bl_height});
    });
  };

  return souriauPrj;
})();

})(jQuery);

Drupal.behaviors.souriauPrj = {

  attach: function(context, settings){
    souriau.souriauPrj.customForm(context, settings);
    souriau.souriauPrj.langSelect(context, settings);
    souriau.souriauPrj.openSearch(context, settings);
    souriau.souriauPrj.menuBehavior(context, settings);
    souriau.souriauPrj.ariaChange(context, settings);
    souriau.souriauPrj.slider(context, settings);
    souriau.souriauPrj.contactsSlider(context, settings);
    souriau.souriauPrj.logInSlider(context, settings);
    souriau.souriauPrj.appList(context, settings);
    souriau.souriauPrj.moreVisible(context, settings);
    souriau.souriauPrj.video(context, settings);
    souriau.souriauPrj.labelBehavior(context, settings);
    souriau.souriauPrj.autoLoadPopup(context, settings);
    souriau.souriauPrj.modalPopupOpen(context, settings);
    souriau.souriauPrj.editableBlock(context, settings);
    souriau.souriauPrj.addressBehavior(context, settings);
    souriau.souriauPrj.clickableRow(context, settings);
    souriau.souriauPrj.tableAccordion(context, settings);
    souriau.souriauPrj.fastClick(context, settings);
    souriau.souriauPrj.confMessages(context, settings);
    souriau.souriauPrj.matchHeight(context, settings);
    souriau.souriauPrj.clearFilters(context, settings);
    souriau.souriauPrj.bannerImages(context, settings);
    souriau.souriauPrj.quizz(context, settings);
    souriau.souriauPrj.masonry(context, settings);
    souriau.souriauPrj.checkAll(context, settings);
    souriau.souriauPrj.openListTags(context, settings);
    souriau.souriauPrj.addToFavourite(context, settings);
    souriau.souriauPrj.compareBehavior(context, settings);
    souriau.souriauPrj.changeView(context, settings);
    souriau.souriauPrj.addToCompare(context, settings);
    souriau.souriauPrj.removeFilter(context, settings);
    souriau.souriauPrj.openFilters(context, settings);
    souriau.souriauPrj.autocomplete(context, settings);
    souriau.souriauPrj.checkLinkvisible(context, settings);
    souriau.souriauPrj.stickyCompare(context, settings);
    souriau.souriauPrj.stickyViewAll(context, settings);
    souriau.souriauPrj.tableWrapper(context, settings);
    souriau.souriauPrj.mainSlider(context, settings);
    souriau.souriauPrj.closeFilters(context, settings);
    souriau.souriauPrj.resizeFilterDisplay(context, settings);
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
  Drupal.behaviors.souriauPrj.attach(context, settings);
}
