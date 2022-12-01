# souriau

## Getting Started.

Just before you will start you need to instal [PHP][], [node.js][], [grunt-cli][] and [bower][].

If you are using Windows, please check out [Server stuff](#server-stuff) section before everything else.

After installation run `npm install && bower install && grunt` in you command line, wait untill it finishes and you are ready to contribute.

[PHP]: http://php.net/manual/faq.installation.php
[node.js]: https://nodejs.org/en/download/
[grunt-cli]: http://gruntjs.com/getting-started
[Grunt]: http://gruntjs.com/getting-started#working-with-an-existing-grunt-project
[bower]: http://bower.io/#install-bower

## Grunt and Grunt tasks.
[Grunt][] the task runner is being used to buld all projects files.

### Modernizr.
To add new tests in Modernizr edit `modernizr-test.json`.

## Bower and Bower components.
jQuery and jQuery Once are excluded from automatic concatenate process, main files from those components are copied by `grunt-contrib-copy` and used only on slice.

### jQuery.
A strict version `1.10.2` of `jquery` is used to provide backwards compatibility with Drupal jQuery Update module.

### jQurey Once.
A strict version `1.2.6` of `jquery-once` is used to provide backwards compatibility with Drupal modules. In newer versions removed callback support. For details look at [jquery-once changelog][].

[jquery-once changelog]: https://github.com/RobLoach/jquery-once/blob/master/CHANGELOG.md#200---january-20th-2015

## Server stuff.

Build process includes [on-demand][] PHP server, mainly because it's the [only][] way to use BrowserSync with PHP. It assumes your local environment have PHP (version 5.4+) installed and added to system's `PATH` environment variable. If you are Windows user please proceed to FAQ, [How do I add my PHP directory to the PATH on Windows?][]

[on-demand]: http://php.net/manual/en/features.commandline.webserver.php
[only]: http://fettblog.eu/php-browsersync-grunt-gulp/
[How do I add my PHP directory to the PATH on Windows?]: http://php.net/manual/ru/faq.installation.php#faq.installation.addtopath

## Hotfixing.

To add site-specific CSS or JS use `../custom.css` and `../custom.js` files.

(more coming soon)
