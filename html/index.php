<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="utf-8">

<meta name="viewport" content="width=device-width, initial-scale=1">

<!-- <link rel="shortcut icon" type="image/x-icon" href="favicon.ico"> -->
<!-- <link rel="apple-touch-icon" href="apple-touch-icon.png"> -->
<!-- Place favicon.ico and apple-touch-icon.png in the root directory -->

<title>SOURIAU - SUNBANK Connection Technologies</title>

<link type="text/css" rel="stylesheet" media="all" href="css/screen.css">
<style>

  .main-header h1 {
    text-align: center;
    width: 180px;
    margin: 20px auto;
  }

  .main-header h1 a {
    display: inline-block;
  }

  .main-header {
    border-bottom: 1px solid #F2F3F5;
  }

  .btn-default {
    color: #FFF;
    background: #003865;
    border-radius: 3px;
  }

  .row {
    display: block;
    float: left;
    width: 100%;
    margin: 20px 0;
  }

  .row h3 {
    text-align: center;
    text-transform: uppercase;
    margin: 0 0 20px;
    font-family: AvenirStd, Helvetica, Arial, sans-serif;
    color: #2a4278;
    font-size: 24px;
    font-weight: 400;
    line-height: 30px;
  }

  h4 {
    font-size: 15px;
    font-family: AvenirNext, Helvetica, Arial, sans-serif;
    color: #2a4278;
    line-height: 18px;
    margin: 5px 0;
  }
</style>

</head>
<body>
  <div class="main-header">
    <div class="container">
      <h1><a href="index.php" class="logo">
      <img src="images/new-logo.png" alt="SOURIAU - SUNBANK Connection Technologies">
    </a></h1>
    </div>
  </div>
  <div class="page">
    <div class="container">
      <div class="row">
        <!--<div class="col-xs-6 col-sm-4 col-md-3 col-lg-3">
          <figure class="thumbnail">
            <a href="homepage.php">
              <img alt="page" src="data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbmNvZGluZz0iVVRGLTgiIHN0YW5kYWxvbmU9Im5vIj8+PHN2ZyAgIHhtbG5zOmRjPSJodHRwOi8vcHVybC5vcmcvZGMvZWxlbWVudHMvMS4xLyIgICB4bWxuczpjYz0iaHR0cDovL2NyZWF0aXZlY29tbW9ucy5vcmcvbnMjIiAgIHhtbG5zOnJkZj0iaHR0cDovL3d3dy53My5vcmcvMTk5OS8wMi8yMi1yZGYtc3ludGF4LW5zIyIgICB4bWxuczpzdmc9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIiAgIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgICB4bWxuczpzb2RpcG9kaT0iaHR0cDovL3NvZGlwb2RpLnNvdXJjZWZvcmdlLm5ldC9EVEQvc29kaXBvZGktMC5kdGQiICAgeG1sbnM6aW5rc2NhcGU9Imh0dHA6Ly93d3cuaW5rc2NhcGUub3JnL25hbWVzcGFjZXMvaW5rc2NhcGUiICAgd2lkdGg9IjE5MiIgICBoZWlnaHQ9IjIwMCIgICB2aWV3Qm94PSIwIDAgMTkyIDIwMCIgICBwcmVzZXJ2ZUFzcGVjdFJhdGlvPSJub25lIiAgIGlkPSJzdmcyIiAgIHZlcnNpb249IjEuMSIgICBpbmtzY2FwZTp2ZXJzaW9uPSIwLjkxIHIxMzcyNSIgICBzb2RpcG9kaTpkb2NuYW1lPSJkb3dubG9hZC5zdmciPiAgPG1ldGFkYXRhICAgICBpZD0ibWV0YWRhdGExNyI+ICAgIDxyZGY6UkRGPiAgICAgIDxjYzpXb3JrICAgICAgICAgcmRmOmFib3V0PSIiPiAgICAgICAgPGRjOmZvcm1hdD5pbWFnZS9zdmcreG1sPC9kYzpmb3JtYXQ+ICAgICAgICA8ZGM6dHlwZSAgICAgICAgICAgcmRmOnJlc291cmNlPSJodHRwOi8vcHVybC5vcmcvZGMvZGNtaXR5cGUvU3RpbGxJbWFnZSIgLz4gICAgICA8L2NjOldvcms+ICAgIDwvcmRmOlJERj4gIDwvbWV0YWRhdGE+ICA8c29kaXBvZGk6bmFtZWR2aWV3ICAgICBwYWdlY29sb3I9IiNmZmZmZmYiICAgICBib3JkZXJjb2xvcj0iIzY2NjY2NiIgICAgIGJvcmRlcm9wYWNpdHk9IjEiICAgICBvYmplY3R0b2xlcmFuY2U9IjEwIiAgICAgZ3JpZHRvbGVyYW5jZT0iMTAiICAgICBndWlkZXRvbGVyYW5jZT0iMTAiICAgICBpbmtzY2FwZTpwYWdlb3BhY2l0eT0iMCIgICAgIGlua3NjYXBlOnBhZ2VzaGFkb3c9IjIiICAgICBpbmtzY2FwZTp3aW5kb3ctd2lkdGg9IjExMjciICAgICBpbmtzY2FwZTp3aW5kb3ctaGVpZ2h0PSI4NzgiICAgICBpZD0ibmFtZWR2aWV3MTUiICAgICBzaG93Z3JpZD0iZmFsc2UiICAgICBpbmtzY2FwZTpzbmFwLXRleHQtYmFzZWxpbmU9ImZhbHNlIiAgICAgaW5rc2NhcGU6em9vbT0iMS40MDAyNjY3IiAgICAgaW5rc2NhcGU6Y3g9IjI0My41OTQ5IiAgICAgaW5rc2NhcGU6Y3k9IjUxLjU2OTM5NiIgICAgIGlua3NjYXBlOndpbmRvdy14PSIxODkiICAgICBpbmtzY2FwZTp3aW5kb3cteT0iMCIgICAgIGlua3NjYXBlOndpbmRvdy1tYXhpbWl6ZWQ9IjAiICAgICBpbmtzY2FwZTpjdXJyZW50LWxheWVyPSJnMTEiIC8+ICAgIDxkZWZzICAgICBpZD0iZGVmczQiPiAgICA8c3R5bGUgICAgICAgdHlwZT0idGV4dC9jc3MiICAgICAgIGlkPSJzdHlsZTYiPjwhW0NEQVRBWyNob2xkZXJfMTUwYWZkZWI5NjQgdGV4dCB7IGZpbGw6I0FBQUFBQTtmb250LXdlaWdodDpib2xkO2ZvbnQtZmFtaWx5OkFyaWFsLCBIZWx2ZXRpY2EsIE9wZW4gU2Fucywgc2Fucy1zZXJpZiwgbW9ub3NwYWNlO2ZvbnQtc2l6ZToxMHB0IH0gXV0+PC9zdHlsZT4gIDwvZGVmcz4gIDxnICAgICBpZD0iaG9sZGVyXzE1MGFmZGViOTY0IiAgICAgdHJhbnNmb3JtPSJzY2FsZSgxLjA0MTY2NjcsMSkiPiAgICA8cmVjdCAgICAgICB3aWR0aD0iMTkyIiAgICAgICBoZWlnaHQ9IjIwMCIgICAgICAgaWQ9InJlY3Q5IiAgICAgICB4PSIwIiAgICAgICB5PSIwIiAgICAgICBzdHlsZT0iZmlsbDojZWVlZWVlIiAvPiAgICA8ZyAgICAgICBpZD0iZzExIj4gICAgICA8dGV4dCAgICAgICAgIHg9IjcwLjA1NDY4OCIgICAgICAgICB5PSIxMDQuNSIgICAgICAgICBpZD0idGV4dDEzIiAgICAgICAgIHN0eWxlPSJmb250LXdlaWdodDpib2xkO2ZvbnQtc2l6ZToxMi41cHg7Zm9udC1mYW1pbHk6QXJpYWwsIEhlbHZldGljYSwgJ09wZW4gU2FucycsIHNhbnMtc2VyaWYsIG1vbm9zcGFjZTtmaWxsOiNhYWFhYWEiPjIwMHgyMDA8L3RleHQ+ICAgIDwvZz4gIDwvZz48L3N2Zz4=" style="width: 100%; display: block;">
            </a>
            <figcaption class="caption">
              <h4>Homepage</h4>
              <p>Additional inforamtion</p>
              <p><a class="btn btn-block btn-default" target="_blank" href="javascript:void(0)"><span class="glyphicon glyphicon-new-window"></span>&nbsp;PSD</a></p>
            </figcaption>
          </figure>
        </div>-->
        <div class="row">
          <h3>Category pages</h3>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="category.php">
                <img alt="page" src="images/preview/category-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Category page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/category-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="category-with-groups.php">
                <img alt="page" src="images/preview/category-desctop-group.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Category with groups</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/category-desctop-group.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="sub-category.php">
                <img alt="page" src="images/preview/sub-category-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Sub category</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/sub-category-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>

        <div class="row">
          <h3>Search pages</h3>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="search.php">
                <img alt="page" src="images/preview/search-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Seacrh page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/search-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>

        <div class="row">
          <h3>Product pages</h3>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="product-landing.php">
                <img alt="page" src="images/preview/product-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Product landing</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/product-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="product-range.php">
                <img alt="page" src="images/preview/product-range-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Product range</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/product-range-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>

        <div class="row">
          <h3>Application pages</h3>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="application.php">
                <img alt="page" src="images/preview/application-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Application page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/application-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="landing-application.php">
                <img alt="page" src="images/preview/landing-app-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Landing application</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/landing-app-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="application-domain.php">
                <img alt="page" src="images/preview/application-domain-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Application domain</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/application-domain-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>

        <div class="row">
          <h3>Capability pages</h3>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="landing-capabilities.php">
                <img alt="page" src="images/preview/landing-capab.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Landing capabilities</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/landing-capab.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="capabilities-domain.php">
                <img alt="page" src="images/preview/capabilities-domain.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Capabilities domain</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/capabilities-domain.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="capability.php">
                <img alt="page" src="images/preview/capability.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Capability page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/capability.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>


        <div class="row">
          <h3>Resource pages</h3>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="resources-landing.php">
                <img alt="page" src="images/preview/resources-desctop-Recovered.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Landing resources</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/resources-desctop-Recovered.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="resource.php">
                <img alt="page" src="images/preview/resource-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Resource page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/resource-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="resource-register.php">
                <img alt="page" src="images/preview/resource-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Resource with register</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/resource2.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>


        <div class="row">
          <h3>General pages</h3>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="homepage.php">
                <img alt="page" src="images/preview/01a---Homepage.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Home page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/01a---Homepage.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="poll.php">
                <img alt="page" src="images/preview/poll.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Poll page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/poll.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="faq.php">
                <img alt="page" src="images/preview/faq-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Faq page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/faq-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="landing-news.php">
                <img alt="page" src="images/preview/land-news-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>News list page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/land-news-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="news.php">
                <img alt="page" src="images/preview/single-news-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>News single page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/single-news-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="404.php">
                <img alt="page" src="images/preview/404.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>404 page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/404.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="information-popup.php">
                <img alt="page" src="images/preview/inform-popup-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Information popup</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/inform-popup-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="confirmation-popup.php">
                <img alt="page" src="images/preview/delete-popup-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Confirmation popup</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/delete-popup-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="part-number.php">
                <img alt="page" src="images/preview/part-number-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Part number</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/part-number-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="part-number2.php">
                <img alt="page" src="images/preview/part-number2-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Part number 2</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/part-number2-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="download-center.php">
                <img alt="page" src="images/preview/downloads-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Download center</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/downloads-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="beginner-quizz.php">
                <img alt="page" src="images/preview/beginner-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Beginner quizz</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/beginner-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="contact.php">
                <img alt="page" src="images/preview/contact-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Contact page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/contact-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="where-to-buy.php">
                <img alt="page" src="images/preview/locators.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Where to buy page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/locators.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="toolkit-landing.php">
                <img alt="page" src="images/preview/toolkit-landing.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Toolkit landing</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/toolkit-landing.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="toolkit2.php">
                <img alt="page" src="images/preview/toolkit-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Toolkit page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/toolkit-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="toolkit.php">
                <img alt="page" src="images/preview/toolkit2.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Toolkit without result</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/toolkit2.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="comparison.php">
                <img alt="page" src="images/preview/compare-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Compare page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/compare-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="cookies.php">
                <img alt="page" src="images/preview/cookies.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Cookies page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/cookies.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="generic-landing.php">
                <img alt="page" src="images/preview/generic-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Generic landing</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/generic-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>

        <div class="row">
          <h3>My account pages</h3>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="my-account.php">
                <img alt="page" src="images/preview/my-account-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>My account page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/my-account-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="projects.php">
                <img alt="page" src="images/preview/projects-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Projects page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/projects-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="project-single.php">
                <img alt="page" src="images/preview/project-single-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Project single page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/project-single-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="edit-account.php">
                <img alt="page" src="images/preview/edit-my-account.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Edit account page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/edit-my-account.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="create-account.php">
                <img alt="page" src="images/preview/create-account.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Create account page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/create-account.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="forgot-password.php">
                <img alt="page" src="images/preview/forgot-pass-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Forgot password page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/forgot-pass-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="sign-in-up.php">
                <img alt="page" src="images/preview/sign-in-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Sign in / sign up</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/sign-in-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="address-book.php">
                <img alt="page" src="images/preview/address-book.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Address book</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/address-book.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="orders.php">
                <img alt="page" src="images/preview/order-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>My orders</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/order-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="order-detail.php">
                <img alt="page" src="images/preview/order-signle-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Order detail</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/order-signle-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

        </div>

        <div class="row">
          <h3>Checkout pages</h3>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="cart-summary.php">
                <img alt="page" src="images/preview/cart-s-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Cart Summary page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/cart-s-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="cart-summary-empty.php">
                <img alt="page" src="images/preview/cart-s-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Cart Summary empty</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/cart-s-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="shipping-info.php">
                <img alt="page" src="images/preview/ship-address-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Shipping info</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/ship-address-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="shipping-info-empty-list.php">
                <img alt="page" src="images/preview/ship-address-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Shipping info</h4>
                <p>with empty address list</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/ship-address-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="confirmation-page.php">
                <img alt="page" src="images/preview/cart-s-desctop.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Confirmation page</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/cart-s-desctop.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>

        <div class="row">
          <h3>Emails</h3>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <a href="email/template1.php">
                <img alt="page" src="images/preview/email.jpg" style="width: 100%; display: block;">
              </a>
              <figcaption class="caption">
                <h4>Email template 1</h4>
                <p>Additional information</p>
                <p><a class="btn btn-block btn-default" target="_blank" href="images/preview/export/email.jpg"><span class="glyphicon glyphicon-new-window"></span> PSD</a></p>
              </figcaption>
            </figure>
          </div>
        </div>

        <div class="row">
          <h3>Additional pages</h3>
          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <figcaption class="caption">
                <h4><a href="default-form.php">Default form</a></h4>
                <p>Additional information</p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <figcaption class="caption">
                <h4><a href="add-project.php">Add project page</a></h4>
                <p>Additional information</p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <figcaption class="caption">
                <h4><a href="messages.php">Messages page</a></h4>
                <p>Additional information</p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <figcaption class="caption">
                <h4><a href="pagination.php">Pagination</a></h4>
                <p>Additional information</p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <figcaption class="caption">
                <h4><a href="simple-page.php">Simple page</a></h4>
                <p>Additional information</p>
              </figcaption>
            </figure>
          </div>

          <div class="col-xs-12 col-sm-4 col-md-3 col-lg-3">
            <figure class="thumbnail">
              <figcaption class="caption">
                <h4><a href="comparison-empty.php">Comparison empty</a></h4>
                <p>Additional information</p>
              </figcaption>
            </figure>
          </div>
        </div>
      </div>
    </div>
  </div>
  <div class="page-footer">
    <div class="container">
      <p class="text-center">Adyax team. With <span class="text-danger">&#10084;</span>.</p>
    </div>
  </div>
</body>
</html>

