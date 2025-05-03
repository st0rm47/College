<?php

// Connecting to the database
$hostname = "localhost";    // Database server name
$username = "root";         // Database username
$password = "";             // Database password
$dbname = "web";         // Database name

// Create connection
$conn = mysqli_connect($hostname, $username, $password, $dbname);

// Check connection
if (!$conn){
    die("Connection failed: " . mysqli_connect_error());
}else{
    echo "Connected Successfully";
}

// Create database
$sql = "CREATE DATABASE web";

if (mysqli_query($conn, $sql)){
    echo "Database Created Successfully";
} else{
    echo "Error creating Database";
}

// Create Table
$sql = "CREATE TABLE users(
        id INT(10) AUTO_INCREMENT PRIMARY KEY,
        first_name VARCHAR(40) NOT NULL,
        last_name VARCHAR(40) NOT NULL,
        address VARCHAR(60) NOT NULL,
        number VARCHAR(20) NOT NULL
        )";

if (mysqli_query($conn, $sql)){
    echo "Table Created Successfully";
} else{
    echo "Error creating Table";
}
?>