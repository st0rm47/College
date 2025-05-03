<?php

//Create a cookie
setcookie("username", "Ram", time() + 3600, "/");

// Retrieve a Cookie
if(isset($_COOKIE["username"])){
    echo "Values: . $_COOKIE[username]";
}else{
    echo "Cookie is not set";
}

// Delete a cookie
setcookie("username", "Ram", time() - 3600, "/");

// Retrieve a Cookie
if(!isset($_COOKIE["username"])){
    echo "Cookie is deleted";
}else{
    echo "Cookie is still set";
}
?>