<?php
    $host = "localhost";
    $username = "root"; // DBMS username
    $password = ""; // DBMS password
    $db = ""; // DBMS database name

    $conn=mysqli_connect($host,'root','','$db');
    if (!$conn) {
        die("Connection failed: " . mysqli_connect_error());
    }
    echo "Connected successfully";

?>