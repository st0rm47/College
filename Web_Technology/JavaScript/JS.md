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
