<?php

include "Database.php";

$id = $_GET['updateid']; // Get the id from the form

// Fetch the existing data
$sql = "SELECT * FROM users";
$result = mysqli_query($conn, $sql);
$row = mysqli_fetch_assoc($result);
$first_name = $row['first_name'];
$last_name = $row['last_name'];
$address = $row['address'];
$number = $row['number'];

if (isset($_POST["update"])){
    $first_name = $_POST["first_name"];
    $last_name = $_POST["last_name"];
    $address = $_POST["address"];
    $number = $_POST["number"];

    // Update the data
    $sql = "UPDATE users SET first_name='$first_name', last_name='$last_name', address='$address', number='$number' WHERE id='$id'";

    if (mysqli_query($conn, $sql)){
        header("Location: display.php"); // Redirect to display page after update
    } else{
        echo "Error updating Table";
    }
}
?>

<body>
<h1>FORM</h1>
<form method = "POST" action = "">

    <label for="first_name">First Name:</label>
    <input type="text" id="first_name" name="first_name" value = "<?php echo $first_name ?>"><br><br>

    <label for="last_name">Last Name:</label>
    <input type="text" id="last_name" name="last_name" value = "<?php echo $last_name ?>"><br><br>

    <label for="address">Address:</label>
    <input type="text" id="address" name="address" value = "<?php echo $address ?>"><br><br>

    <label for="number">Number:</label>
    <input type="tel" id="number" name="number" value = "<?php echo $number ?>"><br><br>

    <input type="submit" name = "update" value="Update">
    
</form>
</body>
</html>