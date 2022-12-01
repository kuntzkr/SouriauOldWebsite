/**
 * @file
 * Contains SVG images.
 */
var svg_target = document.getElementById('site-svg-target');
if (svg_target) {
  var diorbc_svg = function(){/*
    <!--[if gte IE 9]><!-->
      include "../inc/svg.php"
    <!--<![endif]-->
   */}.toString().slice(15,-4);
  svg_target.innerHTML = diorbc_svg;
}
