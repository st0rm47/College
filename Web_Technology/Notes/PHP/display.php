<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Data Table</title>
    <style>
        table,
        th,
        td {
            border: 1px solid black;
            border-collapse: collapse;
            padding: 5px;
            text-align: center;
        }

        th {
            background-color: gray;
        }

        .container {
            margin: 20px;
        }

        button {
            border-radius: 10px;
            background-color: skyblue;
            padding: 10px 20px;
            text-align: center;
        }
    </style>
</head>

<body>
    <h2>User Data</h2>
    <table>
        <button><a href="insert.php">Add User</a></button><br>
        <thead>
            <tr>
                <th> SN </th>
                <th> First Name </th>
                <th> Last Name </th>
                <th> Address </th>
                <th> Number </th>
                <th> Operations </th>
            </tr>
        </thead>
        <tbody>
            <?php
            include 'Database.php';
            $sql = "SELECT * FROM users";
            $result = mysqli_query($conn, $sql);
            if ($result) {

                // Fetch all rows as an associative array
                while ($row = mysqli_fetch_assoc($result)) {
                    $id = $row['id'];
                    $first_name = $row['first_name']; // Ensure column names match your DB
                    $last_name = $row['last_name']; // 
                    $address = $row['address'];
                    $number = $row['number'];

                    echo "<tr>
                                <td> $id </td>
                                <td> $first_name </td>
                                <td> $last_name </td>
                                <td> $address </td>
                                <td> $number </td>
                                <td> <button> <a href='update.php?updateid=$id'> Update </a></button>
                                     <button> <a href='delete.php?deleteid=$id'> Delete </a></button>
                                </td>
                            </tr>";
                }
            } else {
                echo "No data found";
            }
            ?>
        </tbody>
    </table>
</body>
</html>