/**
 * @file
 * Implements logic to support jquery mobile.
 */

// Namespace.
var site_common = site_common || {};

// Init jQuery sign.
(function ($) {

// Init main object.
site_common.jquery_mobile = site_common.jquery_mobile || {
  _inited: false,
  _redirect: ''
};

// On ajax complete we need to check for redirects.
/*$(document).ajaxSuccess(function(event, xhr, settings) {
  var responce_header = xhr.getResponseHeader('X-Site-Common-URL');
  if (responce_header && responce_header.length > 0) {
    console.log(settings);
  }
});*/

// ==================== REGISTER EVENTS START ==========================

// On before navigate. Prevent redirect navigation and inner page navigation.
$(window).on('beforenavigate', function(event, data) {
  site_common.jquery_mobile.beforenavigate(event, data);
});

// On page create, replace all links actions with navigate event.
$(window).on('pagecreate', function (event) {
  site_common.jquery_mobile.pagecreate(event);
});

// On page before show - replace Drupal.settings with settings for this page.
$(window).on('pagecontainerbeforeshow', function(event, data) {
  // Only triggers on page transitions.
  if (data.toPage.hasClass('page') && (data.prevPage.length == 0 || data.prevPage.hasClass('page'))) {
    site_common.jquery_mobile.pagecontainerbeforeshow(event, data);
  }
});

// On page show - trigger behavirs that listen to this event.
$(window).on('pagecontainershow', function(event, data) {
  // Only triggers on page transitions.
  if (data.toPage.hasClass('page') && (data.prevPage.length == 0 || data.prevPage.hasClass('page'))) {
    site_common.jquery_mobile.pagecontainershow(event, data);
  }
});

// On page beforehide - update Drupal.settings in container if they were changed.
$(window).on('pagecontainerbeforehide', function(event, data) {
  // Only triggers on page transitions.
  if (data.toPage.hasClass('page') && (data.prevPage.length == 0 || data.prevPage.hasClass('page'))) {
    site_common.jquery_mobile.pagecontainerbeforehide(event, data);
  }
});

// On page hide - update Drupal.settings in container if they were changed.
$(window).on('pagecontainerhide', function(event, data) {
  // Only triggers on page transitions.
  if (data.toPage.hasClass('page') && (data.prevPage.length == 0 || data.prevPage.hasClass('page'))) {
    site_common.jquery_mobile.pagecontainerhide(event, data);
  }
});

// On page load reattach behaviors.
$(window).on('pagecontainerload', function (event, data) {
  site_common.jquery_mobile.pagecontainerload(event, data);
});

// ==================== REGISTER EVENTS END ==========================

// ==================== BEHAVIORS START ==============================

// Overrige drupal attach behaviors.
site_common.jquery_mobile.DrupalAttachBehaviors = Drupal.attachBehaviors;
Drupal.attachBehaviors = function (context, settings, event) {
  var $context = $(context);
  if ($context.length > 0) {
    site_common.jquery_mobile.attachBehaviors($context, settings, event);
  }
}

/**
 * Default attach to links, should be overriden in your theme!
 */
Drupal.behaviors.site_common_jquery_mobile = {
  attach: function ($context, settings) {
    site_common.jquery_mobile.attach($context, settings);
  }
};

/**
 * Admin behaviors.
 */
Drupal.admin = Drupal.admin || {};
Drupal.admin.behaviors = Drupal.admin.behaviors || {};
Drupal.admin.behaviors.site_common_jquery_mobile = function ($context, settings) {
  site_common.jquery_mobile.attach($context, settings);
};

/**
 * Attach behaviors replacement.
 *
 * Supported events are: pagecontainerbeforeshow, pagecontainershow, pagecontainerload.
 */
site_common.jquery_mobile.attachBehaviors = function (context, settings, event) {
  // Do nothing if not inited.
  if (!site_common.jquery_mobile._inited) {
    return;
  }

  // Default event is pagecontainerload.
  if (!event) {
    event = 'pagecontainerload';
  }

  // Get list of behaviors we need to attach on this events.
  var behaviorList = [];
  $.each(Drupal.behaviors, function (index) {
    if ($.isFunction(this.attach)) {
      // Check for event restrictions.
      var behaviorEvent = this.event || 'pagecontainerload';
      if (event == behaviorEvent) {
        behaviorList.push(index);
      }
    }
  });

  // Log behaviors list.
  qtools.log('SCJQM: attachBehaviors [' + event + ']:', behaviorList);

  // If list empty - exit.
  if (behaviorList.length == 0) {
    return;
  }

  // Get apropriate context.
  if (!context) {
    $context = site_common.jquery_mobile.getPageContext();
  }
  else {
    // Make sure jQuery as context.
    $context = $(context);
  }

  // Get apropriate settings.
  if (!settings) {
    settings = Drupal.settings;
  }

  // Log action.
  qtools.log('SCJQM: attachBehaviors [' + event + '] to:', $context);

  // Attach selected behaviors.
  // See Drupal.attachBehaviors().
  for (var i = 0; i < behaviorList.length; i++) {
    var index = behaviorList[i];
    Drupal.behaviors[index].attach(context, settings, event);
  }
}

/**
 * Behavior implementation.
 */
site_common.jquery_mobile.attach = function ($context, settings) {

  // Enhance content if it wasn't page load.
  if (!$context._noEnhance) {
    qtools.log('SCJQM: enhance:', $context);
    $context.trigger("create");
  }

  var current_url = qtools.parseUrl(window.location.href);
  var l_selector = 'a[href^="http://' + current_url.host +'"], a[href^="https://' + current_url.host +'"], a:not([href*=":"]), .site-common-jqm-navigate';
  var l_ignored = '.site-common-jqm-navigate-ignored, .ui-btn, [href^="#"], [rel="external"], [target], [data-ajax="false"], [data-rel="dialog"]';

  // Define a click binding for all links in the page.
  $context.find(l_selector).not($context.find(l_ignored)).once('site-common-jqm-navigate', function () {
    $(this).click(function(event) {
      var $this = $(this);

      // Exit if this event suprpessed.
      if (event.defaultPrevented) {
        return;
      }

      // Prevent the usual navigation behavior.
      event.preventDefault();

      // Skip navigation if item disabled.
      if ($this.hasClass('site-common-jqm-navigate-disabled')) {
        qtools.log('SCJQM: link disabled:', $this);
        return false;
      }

      if ($this.hasClass('site-common-jqm-navigate-suppressed')) {
        qtools.log('SCJQM: link suppressed:', $this);
        return false;
      }

      // Get destination url.
      var href = $this.attr('data-navigate-href');
      if (!href) {
        href = $this.attr('href');
      }

      // Ignore anchor and empty links.
      var url = qtools.parseUrl(href);
      qtools.log('SCJQM: link checking:', url);
      if (!href || href == '' || url.hash != '' || (url.path == '' && href != '/')) {
        qtools.log('SCJQM: non link clicked:', href);
        return false;
      }
      if (url.href == window.location.href) {
        qtools.log('SCJQM: already on this page:', href);
        return false;
      }

      // Direct navigate for excluded (admin?) links.
      var pattern = Drupal.settings.site_common.jquery_mobile.exclude;
      if (url.href.match(pattern) || $this.parents('#admin-menu').length > 0) {
        window.location.href = href;
        return false;
      }
      else {
        qtools.log('SCJQM: check fails:', [url.href, pattern]);
      }

      // Get list of attributes that needs to be stored.
      var attrlist = $this.attr('data-navigate-params');
      var params = {};
      if (attrlist && attrlist != '') {
        attrlist = attrlist.split(',');
        for (var key in attrlist) {
          params[attrlist[key]] = $this.attr('data-' + attrlist[key]);
        }
      }

      // Pass to internal naviagtion function.
      site_common.jquery_mobile.navigate(href, params);
    });
  });
}

// ==================== BEHAVIORS END ================================

// ==================== ENEVTS CALLBACKS START =======================

/**
 * Handle before navigate event.
 */
site_common.jquery_mobile.beforenavigate = function (event) {
  // If this is due to redirect, we prevent actual Ajax request.
  if (site_common.jquery_mobile._redirect != '') {
    qtools.log('SCJQM: redirect suppressed: ', site_common.jquery_mobile._redirect);
    site_common.jquery_mobile._redirect = '';
    event.preventDefault();
  }

  // At this point browser URL already changed.
  var href = window.location.href;

  // If this local page - prevent actual Ajax request.
  var params = site_common.jquery_mobile.local_page_get(href);

  if (params) {
    event.preventDefault();
    qtools.log('SCJQM: local page: ', href, params);

    // Only function type supported for now.
    if (params['type'] == 'function') {
      params['function'](href, params);
    }
  }
  else {
    qtools.log('SCJQM: other page: ', href, params);
  }
}

/**
 * Perform initialisation, you may override this.
 */
site_common.jquery_mobile.pagecreate = function (event) {

  // Only init once.
  if (!site_common.jquery_mobile._inited) {

    // Mark as inited.
    site_common.jquery_mobile._inited = true;

    // Save main page settings.
    Drupal.settings._site_common_jquery_mobile_url = window.location.href + '(default)';
    site_common.jquery_mobile._original_settings = Drupal.settings;

    // Save settings.
    event.target._drupalSettings = Drupal.settings;

    // Attach behaviors to whole doc at first load.
    var $context = $(document);

    // Content is already enhanced.
    $context._noEnhance = true;
    Drupal.attachBehaviors($context, Drupal.settings);
  }
}

/**
 * Handle pagecontainerload.
 */
site_common.jquery_mobile.pagecontainerload = function (event, data) {

  // Get context and settings.
  var $context = data.toPage;
  $context[0]._drupalSettings = {};

  // Getting settings a bit harder.
  var response_text = '';
  var find_settings = data.xhr.responseText.match(/jQuery\.extend\(Drupal\.settings\,(.*)/);
  if (find_settings && find_settings.length > 0) {
    response_text = find_settings[1];
  }

  // Looking for a redirect.
  var find_redirect = data.xhr.getResponseHeader('X-Site-Common-Location');
  if (find_redirect) {
    data.absUrl = find_redirect;
    qtools.log('SCJQM: redirect found: ', find_redirect);
    site_common.jquery_mobile._redirect = find_redirect;
    $.mobile.navigate(find_redirect, {});
  }

  // At this point we know we not redirecting.
  if (response_text && response_text != '') {
    var eval_text = 'var site_common_drupal_settings = (' + response_text;
    eval(eval_text);
    if (site_common_drupal_settings) {
      // Save data to DOM element.
      site_common_drupal_settings._site_common_jquery_mobile_url = data.absUrl;
      $context[0]._drupalSettings = site_common_drupal_settings;
    }
    else {
      // Fallback to default settings.
      $context[0]._drupalSettings = site_common.jquery_mobile._original_settings;
    }
  }

  // Looking for JS that are not present on original page.
  // TODO: maybe i found out some proper way to do this.
  /*var find_scripts = [];
  var re = /<script.*?src="([^("|\?)]*)("|\?)/g;
  var match;
  while (match = re.exec(data.xhr.responseText)) {
    if (match.length > 1) {
      find_scripts.push(match[1]);
    }
  }
  if (find_scripts.length > 0) {
    var existing_scripts = [];
    $('script[src]').each(function () {
      existing_scripts.push($(this).attr('src').match(/[^?]+/)[0]);
    });
    var diff = $(find_scripts).not(existing_scripts).get();
    if (diff.length > 0) {
      // Create sync scripts for every new entry we have.
      for (var i = 0; i < diff.length; i++) {
        site_common.async.add_js(diff[i]);
      }
    }
  }*/

  // Attach Behaviors to new page.
  // We use timeout to offload behaviors from current thread as content is not yet in DOM
  // despite JQM says otherwise.
  setTimeout(function () {
    Drupal.attachBehaviors($context, Drupal.settings);
  }, 0);
}

/**
 * Handle before show event.
 */
site_common.jquery_mobile.pagecontainerbeforeshow = function (event, data) {

  // Restore settings from page we navigating to.
  Drupal.settings = data.toPage[0]._drupalSettings || {};
  qtools.log('SCJQM: populate settings for:', Drupal.settings._site_common_jquery_mobile_url);

  // Turn ON CKeditros that we flushed by us in pagecontainerbeforehide.
  data.toPage.find('.site-common-jqm-cke-flushed').each(function () {
    if (Drupal.ckeditorOn) {
      var $this = $(this);
      qtools.log('SCJQM: CKEditor On for :', $this.attr('id'));
      Drupal.ckeditorOn($this.attr('id'));
      $(this).removeClass('site-common-jqm-cke-flushed');
    }
  });

  // Attach behaviors to this events.
  Drupal.attachBehaviors(data.toPage, false, 'pagecontainerbeforeshow');
}

/**
 * Handle show event.
 */
site_common.jquery_mobile.pagecontainershow = function (event, data) {
  // Attach behaviors to this events.
  Drupal.attachBehaviors(data.toPage, false, 'pagecontainershow');
}


/**
 * Handle beforehide event.
 */
site_common.jquery_mobile.pagecontainerbeforehide = function (event, data) {

  // Fix CKeditor (turn off any enabled ckeditors).
  data.prevPage.find('textarea.ckeditor-processed').each(function () {
    if (Drupal.ckeditorOff) {
      var $this = $(this);
      qtools.log('SCJQM: CKEditor Off for :', $this.attr('id'));
      Drupal.ckeditorOff($this.attr('id'));
      $(this).addClass('site-common-jqm-cke-flushed');
    }
  });
  data.prevPage[0]._drupalSettings = Drupal.settings;
  qtools.log('SCJQM: update settings for:', Drupal.settings._site_common_jquery_mobile_url);
}

/**
 * Handle hide event.
 */
site_common.jquery_mobile.pagecontainerhide = function (event, data) {
  // Placeholder.
}

// ==================== ENEVTS CALLBACKS END =======================

// ==================== API/UTILITY FUNCTIONS START =======================

/**
 * Performs navigate.
 */
site_common.jquery_mobile.navigate = function (href, params) {
  qtools.log('SCJQM: navigating to:', href);

  if (href == window.location.href) {
    qtools.log('SCJQM: navigation skipped, same page.');
    return;
  }


  // Alter the url according to the given params.
  $.mobile.navigate(href, params);
}

/**
 * Add local page.
 */
site_common.jquery_mobile.local_page_add = function (href, params) {
  // Add local page to set of local pages in drupal settings.
  if (!Drupal.settings.__site_common_jquery_mobile_local_pages) {
    Drupal.settings.__site_common_jquery_mobile_local_pages = {};
  }

  if (!Drupal.settings.__site_common_jquery_mobile_local_pages[href]) {
    Drupal.settings.__site_common_jquery_mobile_local_pages[href] = params || {};
    qtools.log('SCJQM: local page [1] added to [2]:', href, Drupal.settings._site_common_jquery_mobile_url);
  }
  else {
    qtools.log('SCJQM: local page EXISTS [1] added to [2]:', href, Drupal.settings._site_common_jquery_mobile_url);
  }
}

/**
 * Check if local page exists and return its settings.
 */
site_common.jquery_mobile.local_page_get = function (href) {
  // Add local page to set of local pages in drupal settings.
  if (!Drupal.settings.__site_common_jquery_mobile_local_pages) {
    Drupal.settings.__site_common_jquery_mobile_local_pages = {};
  }
  if (Drupal.settings.__site_common_jquery_mobile_local_pages[href]) {
    return Drupal.settings.__site_common_jquery_mobile_local_pages[href];
  }
}

/**
 * Add inner page state.
 */
site_common.jquery_mobile.history_push = function (href, params) {
  // Alter the url according to the given params.
  $.mobile.navigate(href, params);
  qtools.log('SCJQM: navigate to:', href);
}

/**
 * Return current page.
 */
site_common.jquery_mobile.getPageContext = function () {
  var $context = $('.page.ui-page-active');
  if ($context.length == 0) {
    $context = $('.page[data-role="page"]');
  }
  return $context;
}

// ==================== API/UTILITY FUNCTIONS END =======================

})(jQuery);

