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

<!-- # HTML Attributes
- All HTML elements can have attributes
- Attributes provide additional information about elements
- Attributes are always specified in the opening tags.
- Attributes usually come in name/value pairs like: name="value" -->


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

<!-- # HTML Text Formatting
- HTML text formatting tags are used to format the text for better readability.
- The `<mark>` tag is used to highlight the text. -->

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
