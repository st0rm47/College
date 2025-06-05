# 1. How to declare variables and print statements in PHP?

PHP variables are declared using the `$` symbol followed by the variable name. To print statements, you can use `echo` or `print`. Here's an example:

```php
<?php
$name  = "Subodh";
$roll = 79011027;

echo "My name is $name and my roll number is $roll.";
?>
```

<div align="center">
    <img src="images/1.png" alt="Variable Declaration in PHP" />
</div>



# 2. Use GET and POST methods in PHP to handle form data.

```php
<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];
    echo "Name: $name<br>Email: $email";
} else {
?>
<!DOCTYPE html>
<html>
<head>
    <title>Form Submission</title>
</head>
<body>
    
    <form method="POST" action="">
        Name: <input type="text" name="name" required><br>
        Email: <input type="email" name="email" required><br>
        <input type="submit" value="Submit">
    </form>
<?php
}
?>
</body>
</html>
```
