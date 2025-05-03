function validateForm() {
    // Validate First Name
    var fname = document.getElementById("fname").value;
    if (fname == "") {
        alert("First name is required.");
        return false;
    }

    // Validate Last Name
    var lname = document.getElementById("lname").value;
    if (lname == "") {
        alert("Last name is required.");
        return false;
    }

    // Validate Email
    var email = document.getElementById("email").value;
    var emailPattern = /^[a-zA-Z0-9._-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,6}$/;
    if (email == "") {
        alert("Email is required.");
        return false;
    } else if (!emailPattern.test(email)) {
        alert("Please enter a valid email address.");
        return false;
    }

    // Validate Password 
    var password = document.getElementById("password").value;
    if (password == "") {
        alert("Password is required.");
        return false;
    }

    // Validate Age (Number)
    var age = document.getElementById("age").value;
    if (age < 18 || age > 100) {
        alert("Age must be between 18 and 100.");
        return false;
    }

    // Validate Interests (Checkboxes)
    var interests = document.querySelectorAll('input[name="interests"]:checked');
    if (interests.length == 0) {
        alert("Please select at least one interest");
        return false;
    }

    // Validate Gender (Radio Buttons)
    var gender = document.querySelector('input[name="gender"]:checked');
    if (!gender) {
        alert("Please select a gender");
        return false; 
    }

    // Validate Country (Dropdown)
    var country = document.getElementById("country").value;
    if (country == "") {
        alert("Please select a country.");
        return false;
    }

    // Validate Message (Text Area)
    var message = document.getElementById("message").value;
    if (message == "") {
        alert("Message is required.");
        return false;
    }

    // Validate File Upload (Optional, if you want to ensure file upload)
    var file = document.getElementById("file").value;
    if (file == "") {
        alert("Please upload a file.");
        return false;
    }

    // If everything is valid, the form will be submitted
    return true;
}