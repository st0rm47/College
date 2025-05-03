<?php

$hostname = "localhost";
$username = "root";
$password = "";
$dbname = "web";

$conn = mysqli_connect($hostname, $username, $password, $dbname);



// Create table if it doesn't exist
$sql = "CREATE TABLE IF NOT EXISTS books (
    id INT(6) AUTO_INCREMENT PRIMARY KEY,
    search_type VARCHAR(30) NOT NULL,
    book_name VARCHAR(30) NOT NULL,
    download BOOLEAN NOT NULL
)";


// Insert data into the table if the form is submitted
if (isset($_POST['submit'])) {
    $search_type = $_POST['search_type'];
    $search_value = $_POST['search_value'];
    $download = $_POST['download'] === 'true' ? 1 : 0;

    $sql2 = "INSERT INTO books (book_name, search_type, download) VALUES ('$search_value', '$search_type', '$download')";

    if (mysqli_query($conn, $sql2)) {
        echo "Data Inserted Successfully";
    } else {
        echo "Error Inserting Data: " . mysqli_error($conn);
    }
}
?>

<body>
    <h1>Search Form</h1>
    <form method = "POST" action = "">
        <select name ="search_type" id ="search_type">Search Type
            <option value = "">Select a search type</option>
            <option value = "SAD">SAD</option>
            <option value = "WEB">WEB</option>
            <option value = "DAA">DAA</option>
            <option value = "MM">MM</option>
        </select><br><br>

        <label for ="search_value">Search for a book:</label><br>
        <input type = "text" name = "search_value" id = "search_value" placeholder = "Enter book name"><br><br>   

        <label for ="download">Download Type:</label><br>
        <input type = 'radio' name = "download" id="true" value = "true">True
        <input type = 'radio' name = "download" id="false" value = "false">False <br><br>

        <input type = "submit" name = "submit" id = "submit" value = "Submit">
    </form>

    <h2>Data from Database</h2>
    <table border="1">
        <thead>
            <tr>
                <th>ID</th>
                <th>Book Name</th>
                <th>Search Type</th>
                <th>Download</th>
            </tr>
        </thead>
        <tbody>
            <?php
            // Fetch data from the database and display it in the table
            $sql = "SELECT * FROM books";
            $result = mysqli_query($conn, $sql);

            if ($result) {
                while ($row = mysqli_fetch_assoc($result)) {
                    $id = $row["id"];
                    $book_name = $row["book_name"];
                    $search_type = $row["search_type"];
                    $download = $row["download"] ? 'True' : 'False';

                    echo "<tr>
                        <td>$id</td>
                        <td>$book_name</td>
                        <td>$search_type</td>
                        <td>$download</td>
                    </tr>";
                }
            } else {
                echo "Error fetching data: " . mysqli_error($conn);
            }
            ?>
        </tbody>
    </table>
</body>