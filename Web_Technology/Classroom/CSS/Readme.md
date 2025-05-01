# CSS Cascading Style Sheet
- CSS is a language that describes the style of an HTML document.
- CSS describes how HTML elements should be displayed.

## CSS Types
- Inline CSS
- Internal CSS
- External CSS

## Inline CSS
- Inline CSS is used to apply a unique style to a single HTML element.
- Inline CSS uses the style attribute in the relevant tag.

```html
    <h1 style="color: red;">This is a heading</h1>
    <p style="color: blue;">This is a paragraph.</p>
```

## Internal CSS
- Internal CSS is used to define a unique style for a single HTML page.
- Internal CSS is defined in the head section of an HTML page, by using the <style> element.

```html
    <head>
        <style>
            body {
                background-color: linen;
            }
            h1 {
                color: maroon;
                margin-left: 40px;
            }
        </style>
    </head>
```

## External CSS
- External CSS is used to define the style for many HTML pages.
- External CSS is written in a separate file.
- External CSS file should not contain any HTML tags.
- External CSS file should be saved with a .css extension.

```html
    <head>
        <link rel="stylesheet" type="text/css" href="mystyle.css">
    </head>
```

## CSS Selectors
- CSS selectors are used to "find" (or select) the HTML elements you want to style.
- We can divide CSS selectors into five categories:
    - Simple selectors (select elements based on name, id, class)
    - Combinator selectors (select elements based on a specific relationship between them)
    - Pseudo-class selectors (select elements based on a certain state)
    - Pseudo-elements selectors (select and style a part of an element)
    - Attribute selectors (select elements based on an attribute or attribute value)






## CSS Position
- The position property specifies the type of positioning method used for an element.
- There are five different position values:
    - static : default value
    - relative : relative to its normal position
    - fixed : relative to the browser window, unscrollable
    - absolute : relative to the nearest positioned ancestor, 
    - sticky : fixed position within its container, based on the user's scroll position

