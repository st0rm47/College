<?php
class Car {
    // Properties
    public $color;
    public $model;

    // Constructor
    public function __construct($color, $model) {
        $this->color = $color; // Assign color to the property
        $this->model = $model; // Assign model to the property
    }

    // Method
    public function displayInfo() {
        return "Car Model: " . $this->model . ", Color: " . $this->color; // Returns car information
    }
}
// Creating an object of the Car class
$myCar = new Car("Red", "Toyota"); // Creates a new object of the Car class with color Red and model Toyota

// Accessing properties and methods of the object
echo $myCar->color; // Outputs: Red
echo $myCar->model; // Outputs: Toyota
echo $myCar->displayInfo(); // Outputs: Car Model: Toyota, Color: Red

?>