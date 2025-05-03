<?php

// Create a session
session_start();



// Session Data Store
session_start();
$_SESSION["username"] = "Ram";
$_SESSION["email"] = "ram@gmail.com"



// Session Data Retrieve
session_start();

$username = $_SESSION["username"];
$email = $_SESSION["email"];

echo "Username: $username";
echo "Email: $email";



// Session Destroy
session_start();

session_unset();

session_destroy();
?>