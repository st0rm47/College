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


// Insert data into the database
if (isset($_POST['submit'])) {
    $first_name = $_POST['first_name'];
    $last_name = $_POST['last_name'];
    $address = $_POST['address'];

    $sql = "INSERT INTO users (first_name, last_name, address) VALUES ('$first_name', '$last_name', '$address')";

    if (mysqli_query($conn, $sql)) {
        echo "Data Inserted Successfully";
    } else {
        echo "Error Inserting Data: " . mysqli_error($conn);
    }
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

    <h2>Data from Database</h2>
    <table border="1">
        <thead>
            <tr>
                <th>ID</th>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Address</th>
            </tr>
        </thead>
        <tbody>
            <?php
            // Display data from the database
            $sql = "SELECT * FROM users";
            $result = mysqli_query($conn, $sql);

            if ($result) {
                while ($row = mysqli_fetch_assoc($result)) {
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
            } else {
                echo "Error fetching data: " . mysqli_error($conn);
            }
            ?>
        </tbody>
    </table>
</body>
</html>