# 1. Use jQuery library and show effects like show/hide, fadeIn/fadeOut, slideUp/slideDown.

```html
<!DOCTYPE html>
<html>
<head>
    <title>jQuery Effects</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
</head>
<body>
    <button id="show">Show</button>
    <button id="hide">Hide</button>
    <button id="fadeIn">Fade In</button>
    <button id="fadeOut">Fade Out</button>
    <button id="slideUp">Slide Up</button>
    <button id="slideDown">Slide Down</button>

    <div id="box" style="width: 200px; height: 100px; background-color: lightblue; margin: 20px;"></div> 

    <script>
        $(document).ready(function() {
            $("#show").click( () => $("#box").show());
            $("#hide").click(() => $("#box").hide());
            $("#fadeIn").click(() => $("#box").fadeIn());
            $("#fadeOut").click(() => $("#box").fadeOut());
            $("#slideUp").click(() => $("#box").slideUp());
            $("#slideDown").click(() => $("#box").slideDown())
        });
    </script>
</body>
</html>
```

<div align="center">
  <img src="images/1.1.png " alt="jQuery Effects Example" width="600">
</div>

<div align="center">
  <img src="images/1.2.png " alt="jQuery Effects Example" width="600">
</div>

---

# 2. Use jQuery to demonstrate append() and prepend() methods.

```html
<!DOCTYPE html>
<html>
<head>
    <title>jQuery Append and Prepend</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
</head>
<body>
    <button id="append">Append</button>
    <button id="prepend">Prepend</button>

    <div id="container" style="border: 1px solid black; margin: 20px; padding:20px;">
        <p>Initial Content</p>
    </div>

    <script>
        $(document).ready(function() {
            $("#append").click(() => $("#container").append("<p>Appended Content</p>"));
            $("#prepend").click(() => $("#container").prepend("<p>Prepended Content</p>"));
        });
    </script>
</body>
</html>
```
<div align="center">
  <img src="images/2.1.png " alt="jQuery Append and Prepend Example" width="600">
</div>

<div align="center">
  <img src="images/2.2.png " alt="jQuery Append and Prepend Example" width="600">

---

# 3. Use jQuery to create plugins like slider, ligthbox, accordin, zoom and toast messages.

```html
<!DOCTYPE html>
<html>
<head>
    <title>jQuery Plugins</title>
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <style>
    body {
            font-family: Arial;
            margin: 20px;
        }
        h2 {
            margin-top: 40px;
        }

        /* Slider */
        .slider {
            width: 300px;
            overflow: hidden;
            border: 1px solid #ccc;
        }
        .slides {
            display: flex;
            transition: 0.5s;
        }
        .slide {
            min-width: 300px;
            background: #87cefa;
            padding: 20px;
        }

        /* Lightbox */
        #lightbox {
            display: none;
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: rgba(0, 0, 0, 0.8);
            text-align: center;
        }

        /* Accordion */
        .accordion h3 {
            cursor: pointer;
            background: #eee;
            padding: 10px;
            margin: 0;
        }
        .accordion div {
            padding: 10px;
            display: none;
            border: 1px solid #ccc;
        }

        /* Toast */
        .toast {
            position: fixed;
            bottom: 20px;
            left: 50%;
            transform: translateX(-50%);
            background: #333;
            color: #fff;
            padding: 10px 20px;
            border-radius: 5px;
            display: none;
        }

        /* Zoom */
        #zoom-img {
            transition: 0.3s;
            cursor: zoom-in;
            margin: 20px;
        }
        #zoom-img.zoomed {
            transform: scale(1.3);
            cursor: zoom-out;
        }
    </style>
</head>
<body>
    <h2>1. Slider</h2>
    <div id="slider" class="slider">
        <div class="slides">
        <div class="slide">Slide 1</div>
        <div class="slide">Slide 2</div>
        </div>
    </div>
    <button id="next">Next</button>

    <h2>2. Lightbox</h2>
    <img src="images/lightbox.png" class="lightbox-thumb" />
    <div id="lightbox">
        <img src="" id="lightbox-img" />
    </div>

    <h2>3. Accordion</h2>
    <div class="accordion">
        <h3>Section 1</h3>
        <div>Content for section 1</div>
        <h3>Section 2</h3>
        <div>Content for section 2</div>
    </div>

    <h2>4. Zoom Image</h2>
    <img src="images/lightbox.png" id="zoom-img" alt="Zoom Image" />

    <h2>5. Toast Message</h2>
    <button id="show-toast">Show Toast</button>
    <div class="toast" id="toast">This is a toast message!</div>

    <script>
        // Slider
        let index = 0;
        $("#next").click(() => {
            index = (index + 1) % 2;
            $(".slides").css("transform", `translateX(-${index * 300}px)`);
        });

        // Lightbox
        $(".lightbox-thumb").click(function () {
            $("#lightbox-img").attr("src", $(this).attr("src"));
            $("#lightbox").fadeIn();
        });
        $("#lightbox").click(() => $("#lightbox").fadeOut());

        // Accordion
        $(".accordion h3").click(function () {
            $(this).next().slideToggle().siblings("div").slideUp();
        });

        // Zoom
        $("#zoom-img").click(function () {
            $(this).toggleClass("zoomed");
        });

        // Toast
        $("#show-toast").click(function () {
            $("#toast").fadeIn().delay(2000).fadeOut();
        });
    </script>
</body>
</html>
```

<div align="center">
  <img src="images/3.1.png " alt="jQuery Plugins Example" width="600">
</div>

<div align="center">
  <img src="images/3.2.png " alt="jQuery Plugins Example" width="600">
</div>

<div align="center">
  <img src="images/3.3.png " alt="jQuery Plugins Example" width="600">
</div>

