# *1. What is CSS Media Query? Show the use of max-width and min-width properties.*

## CSS MEDIA QUERY
- CSS Media Queries help make websites responsive, meaning they adjust their layout and style depending on the device's screen size (like phones, tablets, or desktops).
- This ensures a great user experience, whether you're on a small mobile screen or a large desktop monitor.
- They check the screen size and apply specific CSS rules only if the condition matches.

Syntax:
```css 
@media (condition) {
  /* CSS rules here */
}
```


### Key properties:
- min-width: Styles apply if width ≥ value
- max-width: Styles apply if width ≤ value

Example:
```html
<html>
<head>
  <title>Responsive Example</title>
  <style>
    .box {
      padding: 20px;
      text-align: center;
      font-size: 20px;
      color:white;
    }

    @media (max-width: 599px) {
      .box {
        background-color: gray;
        font-size: 16px;
      }
    }

    @media (min-width: 600px) and (max-width: 1023px) {
      .box {
        background-color: black;
        font-size: 18px;
      }
    }

    @media (min-width: 1024px) {
      .box {
        background-color: blue;
        font-size: 24px;
      }
    }
  </style>

</head>
<body>
  <div class="box">
    <h1>Responsive Design in Action</h1>
  </div>
</body>
</html>
```
----

# *2. List the properties associated with 2d effects and transformations. Show examples.*

## 2D TRANSFORMATIONS
- 2D transformations are used to manipulate elements in 2D space.
- They include translation, rotation, scaling, and skewing.
- These transformations can be applied to any HTML element using CSS.

### Key properties:
- transform: Applies a 2D or 3D transformation to an element.
- transform-origin: Sets the origin for an element's transformations.
- translate(): Moves an element from its current position.
- rotate(): Rotates an element clockwise or counterclockwise.
- scale(): Increases or decreases the size of an element.
- skew(): Skews an element along the X and Y-axis.
- matrix(): Combines all the 2D transformations into one.

## 2D EFFECTS
- CSS 2D Effects enhance the visual appearance of elements by adding shadows, gradients, and transitions.
- They can be used to create depth, texture, and movement in web design.

### Key properties:
- box-shadow: Adds a shadow to an element.
- text-shadow: Adds a shadow to text.
- linear-gradient(): Creates a gradient background.
- radial-gradient(): Creates a radial gradient background.
- transition: Adds a smooth transition effect to an element.
- border-radius: Rounds the corners of an element.

Example:
```html
<html>
<head>
  <title>2D Transformations Example</title>
  <style>
    .box {
      width: 150px;
      height: 150px;
      background: gray;
      color: white;
      margin: 20px;
      text-align: center;
      line-height: 150px;
      border-radius: 15px;
      box-shadow: 5px 5px 15px rgb(0, 0, 0, 0.3);
      transition: all 0.5s ease;
    }

    .translate:hover {
      transform: translate(40px, 30px);
    }

    .rotate:hover {
      transform: rotate(90deg);
    }

    .scale:hover {
      transform: scale(1.3, 1.3);
    }

    .skew:hover {
      transform: skew(15deg, -10deg);
    }

    .matrix:hover {
      transform: matrix(1, 0.5, -0.5, 1, 30, 30);
    }
  </style>
</head>
<body>
  <div class="box translate">Translate</div>
  <div class="box rotate">Rotate</div>
  <div class="box scale">Scale</div>
  <div class="box skew">Skew</div>
  <div class="box matrix">Matrix</div>
</body>
</html>
```
----

# *3. What is CSS 3 animation? Demonstrate it by dragging a box in any one direction.*

## CSS 3 ANIMATION
- CSS 3 Animation allows you to create animated effects on web pages without using JavaScript.
- Animations are created using the @keyframes rule along with the animation property.

### Key properties:
- @keyframes: Defines the animation sequence.
- animation-name: Specifies the name of the @keyframes rule.
- animation-duration: Specifies the duration of the animation.
- animation-timing-function: Specifies the speed curve of the animation.
- animation-delay: Specifies when the animation will start.
- animation-iteration-count: Specifies the number of times an animation should run.
- animation-direction: Specifies whether the animation should play in reverse.

Example:
```html
<html>
<head>
  <title>CSS 3 Animation</title>
  <style>
    .box {
      width: 100px;
      height: 100px;
      background-color: gray;
      position: absolute;
      border-radius: 20px;
      animation: slide 4s infinite alternate;
    }

    @keyframes slide {
      from {
        left: 0px;
      }
      to {
        left: 50%;
      }
    }
  </style>
</head>
<body>
  <div class="box"></div>
</body>
</html>
```
----

# *4. Show the use of active, focus and hover effects.*

## ACTIVE, FOCUS, HOVER EFFECTS
- CSS pseudo-classes like :active, :focus, and :hover allow you to style elements based on user interaction.
- They help create interactive and engaging web pages by changing the appearance of elements when they are clicked, focused, or hovered over.

### Key properties:
- :active: Applies styles when an element is being activated (clicked).
- :focus: Applies styles when an element is focused (selected).
- :hover: Applies styles when an element is hovered over.

Example:
```html
<html>
<head>
  <title>Interactive Effects</title>
  <style>
    .button {
      padding: 10px 20px;
      background-color: rgb(0, 0, 0);
      color: white;
      text-align: center;
      display: inline-block;
      text-decoration: none;
      border-radius: 15px;
      margin: 10px;
    }

    .button:hover {
      background-color: gray;
      color: black;
    }

    .button:active {
      background-color: blue;
    }

    .input {
      padding: 10px;
      border: 1px solid gray;
      border-radius: 5px;
      margin: 10px;
    }

    .input:focus {
      background-color: black;
    }
  </style>
</head>
<body>
  <a href="#" class="button">Button</a>
  <input type="text" class="input" placeholder="Focus Me">
</body>
</html>
```
---

