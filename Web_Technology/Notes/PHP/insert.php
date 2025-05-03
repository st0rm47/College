<?php

include "Database.php";

if (isset($_POST["submit"])){
    $first_name = $_POST["first_name"];
    $last_name = $_POST["last_name"];
    $address = $_POST["address"];
    $number = $_POST["number"];

    // Insert the data
    $sql = "INSERT INTO users (first_name, last_name, address, number) 
    VALUES ('$first_name' , '$last_name', '$address', '$number')";

    if (mysqli_query($conn, $sql)){
        header("Location: display.php"); // Redirect to display page after insert
    } else{
        echo "Error Inserting Data";
    }
}
?>

<body>
<h1>FORM</h1>
<form method = "POST" action = "">

    <label for="first_name">First Name:</label>
    <input type="text" id="first_name" name="first_name"><br><br>

    <label for="last_name">Last Name:</label>
    <input type="text" id="last_name" name="last_name"><br><br>

    <label for="address">Address:</label>
    <input type="text" id="address" name="address"><br><br>

    <label for="number">Number:</label>
    <input type="tel" id="number" name="number"><br><br>

    <input type="submit" name = "submit" value="Submit">
    <input type="reset" name = "reset" value="Reset"> 
    
</form>
</body>
</html>