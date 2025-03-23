# JS Objects
- JS objects are containers for named values called properties or methods.
- Properties are values associated with an object.
- Methods are actions that can be performed on objects.

Objects can be created using 3 ways:
1. Object literal
2. Constructor
3. Object() constructor

## Object Literal
- The simplest way to create an object is using an object literal.
- An object literal is a list of name-value pairs inside curly braces {}.
- The names are strings, and the values are any data type.

```javascript
var person = {
  firstName: "John",
  lastName: "Doe",
  age: 50,
  eyeColor: "blue"
};

console.log(person.firstName);
```

## Constructor
- A constructor is a function that initializes an object.
- You can define a constructor function and use the new keyword to create an object.

```javascript
function Person(first, last, age, eye) {
  this.firstName = first;
  this.lastName = last;
  this.age = age;
  this.eyeColor = eye;
}

var myFather = new Person("John", "Doe", 50, "blue");
```

## Object() Constructor
- The Object() constructor creates an object wrapper.
- It allows you to create an object with a specified prototype or without a prototype.

```javascript
var person = new Object();
person.firstName = "John";
person.lastName = "Doe";
person.age = 50;
person.eyeColor = "blue";

console.log(person.firstName);
```

## Accessing Object Properties
- You can access object properties in two ways:
1. Dot notation
2. Bracket notation

```javascript
var person = {
  firstName: "John",
  lastName: "Doe",
  age: 50,
  eyeColor: "blue"
};

console.log(person.firstName); // Dot notation
console.log(person["firstName"]); // Bracket notation
```

## Accessing Object Methods
- You can access object methods using the same two notations.
- You can call the method using the object name followed by the method name.

```javascript
var person = {
  firstName: "John",
  lastName: "Doe",
  fullName: function() {
    return this.firstName + " " + this.lastName;
  }
};

console.log(person.fullName());
```

## Object Properties
- You can add new properties to an object using the same two notations.
- You can delete a property using the delete keyword.

```javascript
var person = {
  firstName: "John",
  lastName: "Doe",
  age: 50,
  eyeColor: "blue"
};

delete person.age;
person.hairColor = "black";
```

## JavaScript DOM
- The Document Object Model (DOM) is a programming interface for web documents.
- It represents the structure of a document as a tree of objects.
- The DOM allows you to manipulate the document structure, style, and content.

## DOM Methods
- The DOM provides methods to access and manipulate elements in the document.
- You can use these methods to create, delete, and modify elements.

```javascript
document.getElementById(id) // Get an element by its id
document.getElementsByTagName(name) // Get elements by tag name
document.getElementsByClassName(name) // Get elements by class name
element.innerHTML = new html content // Change the inner HTML of an element
element.attribute = new value // Change the attribute value of an element
element.style.property = new style // Change the style of an element
document.createElement(element) // Create an element
document.removeChild(element) // Remove an element


### document.getElementById()
- The getElementById() method returns the element that has the ID attribute with the specified value.
- This method is one of the most common methods in the DOM.
- It is used to get an element by its ID.
- The ID attribute is unique within a document.
- If no element has the specified ID, the method returns null.
- The method is called on the document object.
```javascript
var element = document.getElementById("demo");
element.innerHTML = "Hello, World!";
```

### document.getElementsByName()
- The getElementsByName() method returns a collection of elements with the specified name attribute.
- This method is used to get elements by their name attribute.
- The name attribute is not unique within a document.
- The method returns a NodeList object, which is an array-like object.
- The method is called on the document object.

```javascript
var elements = document.getElementsByName("demo");
elements[0].innerHTML = "Hello, World!";
```

### document.getElementsByTagName()
- The getElementsByTagName() method returns a collection of elements with the specified tag name.
- This method is used to get elements by their tag name.
- The tag name is not unique within a document.
- The method returns a NodeList object, which is an array-like object.
- The method is called on the document object.

```javascript
var elements = document.getElementsByTagName("p");
elements[0].innerHTML = "Hello, World!";
```


### innerHTML
- The innerHTML property sets or returns the HTML content of an element.
- The property is used to get or set the content of an element.
- The content is represented as a string of HTML code.
- The property is used to change the content of an element.
- The property is called on an element object.

```javascript
document.getElementById("demo").innerHTML = "Hello, World!";
```


## Form Validation
- Form validation is the process of checking if the form data is valid before submitting it to the server.
- It helps to ensure that the data is accurate and complete.
- You can use JavaScript to validate form data on the client side.

### Basic Form Validation
- The form must be checked to make sure all the mandatory fields are filled out.

```javascript
function validateForm() {
  var x = document.getElementById("fname").value;
  if (x == "") {
    alert("Name is required");
    return false;
  }
}
```

### Data Format Validation
- The data entered in the form fields must be in the correct format.

```javascript
function validateForm() {
  var age = document.getElementById("age").value;
  if (age < 18 || age > 60) {
    alert("Age must be between 18 and 60");
    return false;
  }
```

### Numeric Validation
- The data entered in the form fields must be numeric.

```javascript
function validateForm() {
  var x = document.getElementById("age").value;
  var pattern = /^[0-9]+$/;
  if (!x.match(pattern)) {
    alert("Age must be a number");
    return false;
  }
}
```

### Email Validation
- The email address entered in the form field must be in the correct format.

```javascript
function validateForm() {
  var email = document.getElementById("email").value;
  var pattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,4}$/;
  if (!email.match(pattern)) {
    alert("Invalid email address");
    return false;
  }
}
```

### Password Validation
- The password entered in the form field must meet certain criteria.

```javascript
function validateForm() {
  var password = document.getElementById("password").value;
  var pattern = /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{6,20}$/;
  if (!password.match(pattern)) {
    alert("Password must contain at least one digit, one lowercase and one uppercase letter, and be between 6 and 20 characters");
    return false;
  }
}
```

### Checkbox Validation
- At least one checkbox must be checked.

```javascript
function validateForm() {
  var interests = document.getElementsByName("interests"),checked;
  if (interests.length == 0) {
    alert("Please select at least one interest");
    return false;
  }
}
```

### Radio Button Validation
- At least one radio button must be selected.

```javascript
function 
