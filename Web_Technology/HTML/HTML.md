# HTML
- HTML stands for Hyper Text Markup Language
- HTML is the standard markup language for creating Web pages
- HTML describes the structure of a Web page
- HTML uses markup tags to describe Web pages
- HTML tags are surrounded by angle brackets: `<tagname>`
- HTML tags normally come in pairs like `<p>` and `</p>`
- The first tag in a pair is the opening tag, the second tag is the closing tag.
---

# Structure of HTML Document
```html
<!DOCTYPE html>
<html>
    <head>
    <title>Page Title</title>
    </head>

    <body>
        <h1>This is a Heading</h1>
        <p>This is a paragraph.</p>
    </body>
</html>
```
- The `<!DOCTYPE html>` declaration defines this document to be HTML5
- The `<html>` element is the root element of an HTML page
- The `<head>` element contains meta information about the document
- The `<title>` element specifies a title for the document
- The `<body>` element contains the visible page content
- The `<h1>` element defines a large heading
- The `<p>` element defines a paragraph
---

# HTML Elements
- An HTML element is defined by a start tag, some content, and an end tag:
```html
<tagname>Content goes here...</tagname>
```
- The HTML element is everything from the opening tag to the closing tag.
- Some HTML elements have no content (like the `<br>` element). These elements are called empty elements.
- Empty elements do not have closing tags.
- HTML elements can be nested (elements can contain elements).
- All HTML documents consist of nested HTML elements.
---

# HTML Headings
- HTML headings are defined with the `<h1>` to `<h6>` tags.
- `<h1>` defines the most important heading. `<h6>` defines the least important heading.
- They have both opening and closing tags.
---

# HTML Paragraphs
- HTML paragraphs are defined with the `<p>` tag.
- Paragraphs can be separated by new lines.
- They have both opening and closing tags.
---

# HTML Comments
- Comments are not displayed in the browser.
- You can use comments to explain your code, which can help you when you edit the source code at a later date.
- Comments are written with `<!--` and `-->`
- Comments can span multiple lines.
---

# HTML Line Breaks
- HTML line breaks are defined with the `<br>` tag.
- The `<br>` tag is an empty tag which means that it has no closing tag.
---

# HTML Formatting Tags
- HTML formatting tags are used to format the text for better readability.
- The `<b>` tag is used to bold the text.
- The `<i>` tag is used to italicize the text.
- The `<small>` tag is used to make the text smaller.
- The `<sub>` tag is used to make the text subscript.
- The `<sup>` tag is used to make the text superscript.
- The `<strong>` tag is used to highlight the important text. This makes the text bold.
- The `<em>` tag is used to emphasize the text. This makes the text italic.
---

# HTML Spacing Tags
- HTML spacing tags are used to add space between the elements.
- The `<br>` tag is used to add a single line break.
- The `<hr>` tag is used to add a horizontal line.
- The `<pre>` tag is used to define preformatted text.
- The `&nbsp;` entity is used to add a single space.
---


# Image Element
- The `<img>` tag is used to embed an image in an HTML page.
- The `<img>` tag has two required attributes:
    - `src` - Specifies the path to the image
    - `alt` - Specifies an alternate text for the image, if the image for some reason cannot be displayed
- The `width` and `height` attributes are used to specify the width and height of the image.
``` html
<img src="image.jpg" alt="Image" width = "100" height = "100">
```
---

# HTML Links
- HTML links are defined with the `<a>` tag.
- This is also called anchor tag.
- The link text is the part that will be visible to the user.
- The `href` attribute specifies the URL of the page the link goes to.
- The `target` attribute specifies where to open the linked document.
``` html
<a href="https://www.google.com" target="_blank">Visit Google</a>
```
---

# HTML Lists
- HTML lists are used to specify lists of information.
- They are of three types:
    - Unordered Lists: Lists that begin with a bullet point.
    - Ordered Lists: Lists that begin with a number.
    - Description Lists: Lists that are used to describe terms.

    ## Unordered Lists
    - An unordered list is a list of items marked with bullets and not by numbers.
    - The `<ul>` tag is used to define an unordered list.
    - The `<li>` tag is used to define each list item.
    - The `start` attribute of the `<ul>` tag is used to specify the starting number of the list.
    ``` html
    <ul>
        <li>Item 1</li>
        <li>Item 2</li>
        <li>Item 3</li>
    </ul>
    ```
    - The `type` attribute of the `<ul>` tag is used to specify the type of bullet point.
    - The `type` attribute can have the following values:
        - disc: Default value. Filled circle.
        - circle: Hollow circle.
        - square: Filled square.
    ``` html
    <ul type="circle">
        <li>Item 1</li>
        <li>Item 2</li>
        <li>Item 3</li>
    </ul>
    ```
    ---

    ## Ordered Lists
    - An ordered list is a list of items marked with numbers.
    - The `<ol>` tag is used to define an ordered list.
    - The `start` attribute of the `<ol>` tag is used to specify the starting number of the list.
    ``` html
    <ol>
        <li>Item 1</li>
        <li>Item 2</li>
        <li>Item 3</li>
    </ol>
    ```
    -  The `type` attribute of the `<ol>` tag is used to specify the type of numbering.
    - The `type` attribute can have the following values:
        - 1: Default value. Numbers.
        - A: Uppercase letters.
        - a: Lowercase letters.
        - I: Uppercase Roman numerals.
        - i: Lowercase Roman numerals.
    ``` html
    <ol type="A" start = "4">
        <li>Item 1</li>
        <li>Item 2</li>
        <li>Item 3</li>
    </ol>
    ```
    ---

    ## Description Lists
    - A description list is a list of terms, with a description of each term.
    - The `<dl>` tag is used to define a description list.
    - The `<dt>` tag is used to define the term.
    - The `<dd>` tag is used to define the description.
    ``` html
    <dl>
        <dt>Term 1</dt>
        <dd>Description 1</dd>

        <dt>Term 2</dt>
        <dd>Description 2</dd>
    </dl>
    ```
---

# HTML Tables
### Structure
- HTML tables are used to display data in tabular form.
- HTML tables allow web developers to arrange data into rows and columns.
- The `<table>` tag is used to define a table.
- The `<tr>` tag is used to define a row in a table.
- The `<td>` tag is used to define a data cell in a table.

### Table Heading and Caption
- The `<th>` tag is used to define a header cell in a table. The text in `<th>` elements are bold and centered by default.
- The `<caption>` tag is used to add a caption to a table.

### Border, CellSpacing and CellPadding
- The `border` attribute of the `<table>` tag is used to specify the border of the table.
- The `border` attribute can have the following values:
        - 0: No border.
        - 1: Border.
- The `cellpadding` attribute of the `<table>` tag is used to specify the space between the cell wall and the cell content.
- The `cellspacing` attribute of the `<table>` tag is used to specify the space between the cells.

### Spanning Rows and Columns
- The `colspan` attribute of the `<td>` tag is used to specify the number of columns a cell should span.
- The `rowspan` attribute of the `<td>` tag is used to specify the number of rows a cell should span.

### Table Height, Width and Background Color
- The `width` attribute of the `<table>` tag is used to specify the width of the table.
- The `height` attribute of the `<table>` tag is used to specify the height of the table.
- The `bgcolor` attribute of the `<table>` tag is used to specify the background color of the table.
- The `width`, `height`, and `bgcolor` attributes can also be used with the `<td>`, `<th>`, and `<tr>` tags.

### Table Sections
- The table can be divided into sections using the `<thead>`, `<tbody>`, and `<tfoot>` tags.
- The `<thead>` tag is used to group the header content in a table.
- The `<tbody>` tag is used to group the body content in a table.
- The `<tfoot>` tag is used to group the footer content in a table.

```html
<table border="1" cellpadding="10" cellspacing="5" width ="400" height="200" bgcolor="yellow">
    <thead>
        <tr>
            <th>Header 1</th>
            <th>Header 2</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>Row 1, Cell 1</td>
            <td>Row 1, Cell 2</td>
        </tr>
        <tr>
            <td>Row 2, Cell 1</td>
            <td>Row 2, Cell 2</td>
        </tr>
    </tbody>
    <tfoot>
        <tr>
            <td colspan = "2">Footer 1</td>
        </tr>
    </tfoot>
</table>
```
---

# HTML Frames
- HTML frames are used to divide the browser window into multiple sections where each section can load a separate HTML document.
- The `<frameset>` tag is used to define a set of frames.
- The `<frame>` tag is used to define each individual frame.
- The `src` attribute of the `<frame>` tag is used to specify the URL of the document that should be loaded into the frame.

```html
<frameset cols="25%,50%,25%">
    <frame src="frame_a.htm">
    <frame src="frame_b.htm">
    <frame src="frame_c.htm">
</frameset>
```

### HTML iframe
- An `<iframe>` is used to display a web page within a web page.
- The `src` attribute of the `<iframe>` tag is used to specify the URL of the page that should be loaded into the iframe.
- Iframes are often used to display advertisements on a web page.
```html
<iframe src="https://www.w3schools.com"></iframe>
<iframe src="https://www.w3schools.com" width="200" height="200"></iframe>
```
---

# HTML Forms
- HTML forms are used to collect user input.
- The `<form>` tag is used to create an HTML form.
- The `action` attribute of the `<form>` tag is used to specify the URL of the page the form data should be submitted to.
- The `method` attribute of the `<form>` tag is used to specify the HTTP method to be used when submitting the form data.
- The `method` attribute can have two values:
    - get: The form data is appended to the URL in name/value pairs.
    - post: The form data is sent to the server as a separate HTTP message.

### Form Input
- The `<input>` tag is used to create an input field.
- The `type` attribute of the `<input>` tag is used to specify the type of input field.
- The `name` attribute of the `<input>` tag is used to specify the name of an input field.
- The `value` attribute of the `<input>` tag is used to specify the value of an input field.
- The `<textarea>` tag is used to create a multi-line text input field.
- The `<maxlength>` attribute of the `<input>` tag is used to specify the maximum number of characters allowed in an input field.
- The `required` attribute of the `<input>` tag is used to specify that an input field must be filled out before submitting the form.
- The `placeholder` attribute of the `<input>` tag is used to specify a short hint that describes the expected value of an input field.


```html
<form action="submit.php" method="post">
    First name: <input type="text" name="fname" maxlength="10"><br>
    Last name: <input type="text" name="lname"><br>
    Password: <input type="password" name="password" required><br>
    <input type="submit" value="Submit">
</form>
```

- The types of text input fields are:
    - text: Single-line text input field.
    - password: Password input field.
    - radio: Radio button.
    - select: Drop-down list.
    - checkbox: Checkbox.
    - submit: Submit button.
    - reset: Reset button.
    - button: Button.
    - file: File upload field.
    - hidden: Hidden input field.
    - image: Image as a submit button.
    - email: Email input field.
    - url: URL input field.
    - tel: Telephone input field.
    - number: Number input field.
    - range: Range input field.
    - date: Date input field.
    - month: Month input field.
    - week: Week input field.
    - time: Time input field.
    - datetime-local: Local date and time input field.
    - color: Color input field.
    - search: Search input field.


### Checkboxes
- If the `type` attribute is set to `checkbox`, the input field will be a checkbox.
```html
<input type="checkbox" name="vehicle1" value="Bike"> I have a bike<br>
<input type="checkbox" name="vehicle2" value="Car"> I have a car<br>
<input type="checkbox" name="vehicle3" value="Boat"> I have a boat<br>
```

### Radio Buttons
- If the `type` attribute is set to `radio`, the input field will be a radio button.
- Radio buttons are used when you want to let the user select one of a limited number of choices.
```html
<input type = "radio" value = "Male"> I am a Male <br>
<input type = "radio" value = "Female"> I am a Female <br>
```

### Select Box
- The `<select>` tag is used to create a drop-down list.
- The `<option>` tag is used to define the options in the drop-down list.
```html
<select>
    <option value="volvo">Volvo</option>
    <option value="saab">Saab</option>
    <option value="mercedes">Mercedes</option>
    <option value="audi">Audi</option>
</select>
```

### File Upload Box
- The `<input>` tag with `type="file"` is used to create a file upload box.
```html
<input type="file" name="pic" accept="image/*">
```

### Button Controls
- The `<input>` tag with `type="submit"` is used to create a submit button.
- The `<input>` tag with `type="reset"` is used to create a reset button.
- The `<button>` tag is used to create a button.
```html
<input type="submit" value="Submit">
<input type="reset" value="Reset">
<button type="button">Click Me!</button>
```
---

# HTML Attributes
- HTML attributes provide additional information about HTML elements.
- Attributes are always specified in the start tag.
- Attributes are always specified in name/value pairs like this: `name="value"`
- HTML attributes are case insensitive.
- HTML attributes can be used with any HTML element.

## Id and Class Attributes
- The `id` attribute is used to specify a unique id for an HTML element.
- The `class` attribute is used to specify a class for an HTML element.
- The `class` attribute can be used to specify multiple classes for an HTML element.
- The `class` attribute can be used to apply CSS styles to multiple elements.
```html
<p id="p1">This is a paragraph.</p>
<p class="p1">This is another paragraph.</p>
<p class="p1 p2">This is a third paragraph.</p>
```
- The `style` attribute is used to specify inline CSS styles for an HTML element.
```html
<p style="color:blue;">This is a blue paragraph.</p>
<p style="color:red; font-size:20px;">This is a red paragraph.</p>
```
---

# HTML Meta Tags
- HTML meta tags are used to provide metadata about the HTML document.
- Metadata is data (information) about data.
- Metadata is not displayed on the page, but is machine parsable.
- Metadata is used by browsers (how to display content or reload page), search engines (keywords), and other web services.
- The `<meta>` tag is used to define metadata about an HTML document.
- The `<meta>` tag is always placed inside the `<head>` section.
- The `<meta>` tag has two required attributes:
    - `name` - Specifies the name of the metadata.
    - `content` - Specifies the value of the metadata.

- The `<meta>` tag can also have the `http-equiv` attribute, which is used to provide an HTTP header for the information/value of the content attribute.
- The `http-equiv` attribute can have the following values:
    - content-type: Specifies the character set of the document.
    - refresh: Specifies the number of seconds before the page should be refreshed.
    - default-style: Specifies the default style sheet for the document.
    - pragma: Specifies that the page should not be cached.
    - expires: Specifies the expiration date of the page.
```html
<head>
<meta name="description" content="This is a description of the page.">
<meta name="keywords" content="HTML, CSS, JavaScript">
<meta name="author" content="John Doe">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="refresh" content="30">
</head>
```
---

# HTML Audio and Video
- HTML5 introduced new elements for embedding audio and video in web pages.
- The `<audio>` tag is used to embed audio files in a web page.
- The `<video>` tag is used to embed video files in a web page.
- The `controls` attribute is used to add audio controls like play, pause, and volume.
- The `autoplay` attribute is used to specify that the audio or video should start playing as soon as it is loaded.
```html
<audio controls autoplay>
    <source src="audio.mp3" type="audio/mpeg">
    Your browser does not support the audio element.
</audio>

<video width="320" height="240" controls autoplay>
    <source src="movie.mp4" type="video/mp4">
    Your browser does not support the video tag.
</video>
```

# HTML Canvas
- The `<canvas>` element is used to draw graphics on a web page.
- The `<canvas>` element is a container for graphics.
- The `<canvas>` element has a `width` and `height` attribute to specify the size of the canvas.
- The `<canvas>` element can be used to draw shapes, text, images, and other graphics.
- The `<canvas>` element is used with JavaScript to draw graphics on the canvas.
```html
<canvas id="myCanvas" width="200" height="100" style="border:1px solid #000000;"></canvas>
<script>
var c = document.getElementById("myCanvas");
var ctx = c.getContext("2d");
ctx.fillStyle = "#FF0000";
ctx.fillRect(20, 20, 150, 50);
</script>
```
---

# HTML Header and Footer
- The `<header>` tag is used to define a header for a document or a section.
- The `<footer>` tag is used to define a footer for a document or a section.
- The `<header>` and `<footer>` tags can contain headings, paragraphs, links, images, and other HTML elements.
```html
<header>
    <h1>This is a header</h1>
    <p>This is a paragraph in the header.</p>
</header>
<footer>
    <h1>This is a footer</h1>
    <p>This is a paragraph in the footer.</p>
</footer>
```
---

# HTML Main and Section
- The `<main>` tag is used to define the main content of a document.
- The `<section>` tag is used to define a section in a document.
- The `<main>` and `<section>` tags can contain headings, paragraphs, links, images, and other HTML elements.
```html
<main>
    <h1>This is the main content</h1>
    <p>This is a paragraph in the main content.</p>
</main>
<section>
    <h1>This is a section</h1>
    <p>This is a paragraph in the section.</p>
</section>
```
---

# HTML Figure and Figcaption
- The `<figure>` tag is used to define self-contained content, like illustrations, diagrams, photos, code listings, etc.
- The `<figcaption>` tag is used to define a caption for the `<figure>` element.
- The `<figure>` and `<figcaption>` tags can contain headings, paragraphs, links, images, and other HTML elements.
```html
<figure>
    <img src="image.jpg" alt="Image">
    <figcaption>This is a caption for the image.</figcaption>
</figure>
```
---

# HTML Div and Span
- The `<div>` tag is used to define a division or a section in an HTML document.
- The `<div>` tag is a block-level element and is used to group block elements together.
- The `<span>` tag is used to define a section in an HTML document.
- The `<span>` tag is an inline element and is used to group inline elements together.
- The `<div>` and `<span>` tags can be used to apply CSS styles to a group of elements.
```html
<div style="background-color:lightblue;">
    <h1>This is a heading</h1>
    <p>This is a paragraph.</p>
</div>

<span style="color:blue;">This is a blue text.</span>
```
---

# HTML Events
- HTML events are actions that can be detected by JavaScript.
- HTML events can be triggered by user actions like clicking a button, submitting a form, moving the mouse, etc.
- HTML events can be used to execute JavaScript code when an event occurs.
- HTML events can be used to create interactive web pages.
- HTML events can be used with HTML elements like `<button>`, `<input>`, `<form>`, `<a>`, etc.
- HTML events can be used with JavaScript functions to execute code when an event occurs.

## Window Events
- The `onload` event occurs when the browser has finished loading the page.
- The `onresize` event occurs when the browser window is resized.
- The `onscroll` event occurs when the user scrolls the page.
- The `onunload` event occurs when the user leaves the page.

## HTML Form Events
- The `onsubmit` event occurs when the form is submitted.
- The `onreset` event occurs when the form is reset.
- The `onchange` event occurs when the value of an input field changes.
- The `onfocus` event occurs when an input field gains focus.
- The `onblur` event occurs when an input field loses focus.
- The `oninput` event occurs when the value of an input field is changed.
- The `onselect` event occurs when the user selects some text in an input field.

## Keyboard Events
- The `onkeydown` event occurs when the user presses a key on the keyboard.
- The `onkeyup` event occurs when the user releases a key on the keyboard.
- The `onkeypress` event occurs when the user presses a key on the keyboard and releases it.
- The `onkeypress` event is deprecated and should not be used.

## Mouse Events
- The `onclick` event occurs when the user clicks on an element.
- The `ondblclick` event occurs when the user double-clicks on an element.
- The `onmousedown` event occurs when the user presses the mouse button down on an element.
- The `onmouseup` event occurs when the user releases the mouse button on an element.
- The `onmouseover` event occurs when the user moves the mouse pointer over an element.
- The `onmouseout` event occurs when the user moves the mouse pointer out of an element.
- The `onmousemove` event occurs when the user moves the mouse pointer over an element.
---

# Examples





