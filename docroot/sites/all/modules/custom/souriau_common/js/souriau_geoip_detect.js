/**
 * @file
 * Souriau GroIP detect.
 */
(function($) {
  /**
   * GroIP detect and redirect user to respective domains.
   */
  function souriau_geoip_detect() {
    // Number of days before expire.  
    // (One month-30days by defalt)  
    var geo_expires = 30;
    var new_location = new_location || null;
    var cookie_country = $.cookie('country') || null;
    var cookie_domain = Drupal.settings.souriau_common.cookie_domain || false;
    var country = JSON.parse(cookie_country);

    var domain_urls = Drupal.settings.souriau_common.domains;
    var current_domain_countries = domain_urls.current.countries;
    
    if (typeof console === "undefined" || typeof console.log === "undefined") {  
      console = {};  
      console.log = function() {  
        //  Donothing in IE.  
      };
    }

    var onSuccess = function (geoipResponse) {
      $.cookie("country", JSON.stringify(geoipResponse.country),  { path: '/', expires: geo_expires, domain: cookie_domain });
      console.log("SGEO: Country detected from GEOIP.", geoipResponse.country);
      doRedirect(geoipResponse.country.iso_code);
    };
    
    var doRedirect = function(user_country) {
      // if user country exists in current domain, then do nothing.
      // And also if current and default domains are same, do nothing (user already redirected or cause infinite redirect).
      if (current_domain_countries.hasOwnProperty(user_country)) {
        console.log("SGEO: Current domain matches to users country.");
        return;
      }

      // Check if the country is binded with a domain.
      if (domain_urls.hasOwnProperty(user_country)) {
        new_location = domain_urls[user_country]['path'];
      } else {
        // Load default URL.
        new_location = domain_urls['default']['path'];
      }
      // For Country switcher case.
      if (country && country.lang_code) {
        new_location += country.lang_code;
      }
      // Current location.
      var current_location = "//" + window.location.hostname.replace(/(secure-)/gi, "");
      if (new_location.match(current_location)){
        // Nothing to do here. Current location is matching to proposed.
        console.log("SGEO: Current location matches to suggested one.");
        return;
      }
      var separator = (new_location.substr(-1) !== '/') ? '/' : '';
      window.location = new_location + separator + domain_urls['destination'];
      return;
    }

    // In case of error do nothing.
    var onError = function (error) {
      console.log(JSON.stringify(error));
    };

    if (country && country.iso_code) {
      console.log("SGEO: Country detected from cookie.", country.iso_code);
      // if cookie is set, then redirect to respective domain.
      doRedirect(country.iso_code);
    } else {
      geoip2.country(onSuccess, onError);
   }
  }

  // Function to check if the request comes from bot or not.
  function botCheck(){
    var botPattern = "(googlebot\/|Googlebot-Mobile|Googlebot-Image|Google favicon|Mediapartners-Google|bingbot|slurp|java|wget|curl|Commons-HttpClient|Python-urllib|libwww|httpunit|nutch|phpcrawl|msnbot|jyxobot|FAST-WebCrawler|FAST Enterprise Crawler|biglotron|teoma|convera|seekbot|gigablast|exabot|ngbot|ia_archiver|GingerCrawler|webmon|httrack|webcrawler|grub.org|UsineNouvelleCrawler|antibot|netresearchserver|speedy|fluffy|bibnum.bnf|findlink|msrbot|panscient|yacybot|AISearchBot|IOI|ips-agent|tagoobot|MJ12bot|dotbot|woriobot|yanga|buzzbot|mlbot|yandexbot|purebot|Linguee Bot|Voyager|CyberPatrol|voilabot|baiduspider|citeseerxbot|spbot|twengabot|postrank|turnitinbot|scribdbot|page2rss|sitebot|linkdex|Adidxbot|blekkobot|ezooms|dotbot|Mail.RU_Bot|discobot|heritrix|findthatfile|europarchive.org|NerdByNature.Bot|sistrix crawler|ahrefsbot|Aboundex|domaincrawler|wbsearchbot|summify|ccbot|edisterbot|seznambot|ec2linkfinder|gslfbot|aihitbot|intelium_bot|facebookexternalhit|yeti|RetrevoPageAnalyzer|lb-spider|sogou|lssbot|careerbot|wotbox|wocbot|ichiro|DuckDuckBot|lssrocketcrawler|drupact|webcompanycrawler|acoonbot|openindexspider|gnam gnam spider|web-archive-net.com.bot|backlinkcrawler|coccoc|integromedb|content crawler spider|toplistbot|seokicks-robot|it2media-domain-crawler|ip-web-crawler.com|siteexplorer.info|elisabot|proximic|changedetection|blexbot|arabot|WeSEE:Search|niki-bot|CrystalSemanticsBot|rogerbot|360Spider|psbot|InterfaxScanBot|Lipperhey SEO Service|CC Metadata Scaper|g00g1e.net|GrapeshotCrawler|urlappendbot|brainobot|fr-crawler|binlar|SimpleCrawler|Livelapbot|Twitterbot|cXensebot|smtbot|bnf.fr_bot|A6-Indexer|ADmantX|Facebot|Twitterbot|OrangeBot|memorybot|AdvBot|MegaIndex|SemanticScholarBot|ltx71|nerdybot|xovibot|BUbiNG|Qwantify|archive.org_bot|Applebot|TweetmemeBot|crawler4j|findxbot|SemrushBot|yoozBot|lipperhey|y!j-asr|Domain Re-Animator Bot|AddThis)";
    var re = new RegExp(botPattern, 'i');
    var userAgent = navigator.userAgent;
    if (re.test(userAgent)) {
      return true;
    } else {
      return false;
    }
  }

  try {
    if (!botCheck()) {
      $(window).load(function() {
        souriau_geoip_detect();
      });
    }
  }
  catch(e) {
    console.log(e.message);
  }
})(jQuery);
