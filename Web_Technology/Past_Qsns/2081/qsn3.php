<?php

$hostname = "localhost";
$username = "root";
$password = "";
$dbname = "web";

$conn = mysqli_connect($hostname, $username, $password, $dbname);

// Create SQL table
$sql = "CREATE TABLE users (
        id INT(10) AUTO_INCREMENT PRIMARY KEY,
        first_name VARCHAR(40) NOT NULL,
        last_name VARCHAR(40) NOT NULL,
        address VARCHAR(60) NOT NULL
        )";

mysqli_query($conn, $sql);

// Method insertdb()
function insertdb($conn, $first_name, $last_name, $address){
    $sql = "INSERT INTO users(first_name, last_name, address)
        VALUES
        ('$first_name', '$last_name', '$address')";
    
    if (mysqli_query($conn, $sql)){
        echo "Data Inserted Successfully";
    } else {
        echo "Error Inserting Data: " . mysqli_error($conn);
    }
}

// Method display()
function display(){
    global $conn;
    $sql = "SELECT * FROM users";
    $result = mysqli_query($conn, $sql);
    
    if ($result){
        echo "<table border='1'>
        <tr>
        <th>ID</th>
        <th>First Name</th>
        <th>Last Name</th>
        <th>Address</th>
        </tr>";
        
        while ($row = mysqli_fetch_assoc($result)){
            $id = $row["id"];
            $first_name = $row["first_name"];
            $last_name = $row["last_name"];
            $address = $row["address"];
            
            echo "<tr>
            <td>$id</td>
            <td>$first_name</td>
            <td>$last_name</td>
            <td>$address</td>
            </tr>";
        }
        echo "</table>";
    } else {
        echo "Error Displaying Data: " . mysqli_error($conn);
    }
}

// Check if form is submitted
if (isset($_POST['submit'])){
    $first_name = $_POST['first_name'];
    $last_name = $_POST['last_name'];
    $address = $_POST['address'];
    
    // Call insertdb() method
    insertdb($conn, $first_name, $last_name, $address);
}
?>

<body>
    <form method = "POST" action = "">
    
    <label for="first_name">First Name:</label>
    <input type="text" id="first_name" name="first_name"><br><br>

    <label for="last_name">Last Name:</label>
    <input type="text" id="last_name" name="last_name"><br><br>

    <label for="address">Address:</label>
    <input type="text" id="address" name="address"><br><br>

    <input type="submit" name = "submit" value="Submit">
    </form>

<?php
display();
?>

</body>