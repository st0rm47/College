
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Product List</title>
</html>
<body>
    <h1>Product List</h1>
    <table border="1">
        <tr>
            <th>Product Code</th>
            <th>Product Name</th>
            <th>Price</th>
        </tr>
        <?php
        // Sample data for products
        $product = [
            ['pcode' => 'P001', 'pname' => 'Product 1', 'price' => 100],
            ['pcode' => 'P002', 'pname' => 'Product 2', 'price' => 200],
            ['pcode' => 'P003', 'pname' => 'Product 3', 'price' => 300],
        ];

        foreach ($product as $item) {
            echo "<tr>";
            echo "<td>" . $item['pcode'] . "</td>";
            echo "<td>" . $item['pname'] . "</td>";
            echo "<td>" . $item['price'] . "</td>";
            echo "</tr>";
        }
        ?>
    </table>
</body> 
</html>
