<?php
 
include 'Database.php';

if(isset($_GET['deleteid'])){
    $id = $_GET['deleteid'];   // Get the id from the form

    // Delete the data
    $sql = "DELETE FROM users WHERE id=$id";

    $result = mysqli_query($conn,$sql);
    if($result){
        header('location:display.php');
    }else{
        die(mysqli_error($conn));
    }

    mysqli_close($conn); // Close the database connection
}
?>