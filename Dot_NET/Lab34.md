# Lab Report 34: Implementation of Form Validation using ReactJS

### Steps
1. Visual Studio -> Create New Project -> React App -> Name: Lab34 -> Create
2. Open `Lab34` folder in Visual Studio Code.
3. Open `src` folder -> Open `App.jsx` file.
4. Replace the existing code in `App.jsx` with the following code:
```jsx
import React, { useState } from "react";
import "./App.css";

function FormValidation() {
    const [formData, setFormData] = useState({
        name: "",
        email: "",
        password: "",
        gender: "",
        agree: false,
        comments: ""
    });

    const [errors, setErrors] = useState({});
    const [success, setSuccess] = useState("");

    const handleChange = (e) => {
        const { name, value, type, checked } = e.target;
        setFormData({
            ...formData,
            [name]: type === "checkbox" ? checked : value
        });
    };

    const validate = () => {
        let temp = {};

        if (!formData.name) temp.name = "Name is required";
        if (!formData.email) temp.email = "Email is required";
        else if (!/\S+@\S+\.\S+/.test(formData.email))
            temp.email = "Invalid email format";

        if (!formData.password) temp.password = "Password is required";
        else if (formData.password.length < 6)
            temp.password = "Minimum 6 characters required";

        if (!formData.gender) temp.gender = "Please select gender";
        if (!formData.agree) temp.agree = "You must agree to continue";

        setErrors(temp);
        return Object.keys(temp).length === 0;
    };

    const handleSubmit = (e) => {
        e.preventDefault();
        if (validate()) {
            setSuccess("Form submitted successfully!");
            setFormData({
                name: "",
                email: "",
                password: "",
                gender: "",
                agree: false,
                comments: ""
            });
            setErrors({});
        }
    };

    return (
        <div className="container">
            <h2>Registration Form</h2>

            {success && <p className="success">{success}</p>}

            <form onSubmit={handleSubmit}>
                {/* Name */}
                <div className="form-group">
                    <label>Name</label>
                    <input type="text" name="name" value={formData.name} onChange={handleChange} />
                    <span className="error">{errors.name}</span>
                </div>

                {/* Email */}
                <div className="form-group">
                    <label>Email</label>
                    <input type="email" name="email" value={formData.email} onChange={handleChange} />
                    <span className="error">{errors.email}</span>
                </div>

                {/* Password */}
                <div className="form-group">
                    <label>Password</label>
                    <input type="password" name="password" value={formData.password} onChange={handleChange} />
                    <span className="error">{errors.password}</span>
                </div>

                {/* Gender */}
                <div className="form-group">
                    <label>Gender</label>
                    <div className="radio-group">
                        <label><input type="radio" name="gender" value="Male" onChange={handleChange} /> Male</label>
                        <label><input type="radio" name="gender" value="Female" onChange={handleChange} /> Female</label>
                    </div>
                    <span className="error">{errors.gender}</span>
                </div>


                {/* Checkbox */}
                <div className="form-group">
                    <label><input type="checkbox" name="agree" checked={formData.agree} onChange={handleChange} /> I agree to the terms and conditions</label>
                    <br />
                    <span className="error">{errors.agree}</span>
                </div>

                {/* Comments */}
                <div className="form-group">
                    <label>Comments</label>
                    <textarea
                        name="comments"
                        rows="3"
                        value={formData.comments}
                        onChange={handleChange}
                    ></textarea>
                </div>

                <button type="submit">Submit</button>
            </form>
        </div>
    );
}

export default FormValidation;
```

5. Save the file.

6. Open `src/App.css` file and add the following styles:
```css
* {
    box-sizing: border-box;
    font-family: "Segoe UI", Tahoma, sans-serif;
}

body {
    background: #f2f4f8;
    margin: 0;
    padding: 0;
}

.container {
    width: 420px;
    margin: auto 160px;
    background: #ffffff;
    padding: 30px;
    border-radius: 10px;
    box-shadow: 0 8px 20px rgba(0, 0, 0, 0.12);
}

h2 {
    text-align: center;
    margin-bottom: 25px;
    color: #333;
}

.form-group {
    margin-bottom: 18px;
}

label {
    display: block;
    font-weight: 600;
    margin-bottom: 6px;
    color: #333;
}

input[type="text"],
input[type="email"],
input[type="password"],
textarea {
    width: 100%;
    padding: 10px;
    border: 1px solid #ccc;
    border-radius: 6px;
    font-size: 14px;
    transition: border 0.3s;
}

    input:focus,
    textarea:focus {
        border-color: #007bff;
        outline: none;
    }

textarea {
    resize: none;
}

input[type="radio"] {
    margin-right: 6px;
}

.radio-group {
    display: flex;
    gap: 15px;
    align-items: center;
}

.checkbox-group {
    display: flex;
    align-items: center;
    gap: 8px;
}

button {
    width: 100%;
    padding: 12px;
    background: #007bff;
    border: none;
    border-radius: 6px;
    color: white;
    font-size: 16px;
    cursor: pointer;
    margin-top: 10px;
    transition: background 0.3s;
}

    button:hover {
        background: #0056b3;
    }

.error {
    color: #e63946;
    font-size: 13px;
    margin-top: 4px;
}

.success {
    background: #e6fffa;
    color: #00695c;
    padding: 10px;
    border-radius: 6px;
    margin-bottom: 15px;
    text-align: center;
    font-weight: 500;
}
```
7. Save the file.
8. Open package.json file and ensure the start script is present:
```json"scripts": {
    "start": "vite",
    ...
}
```
9. Open terminal in Visual Studio Code and run the following command to start the React application:
```
npm start
```

