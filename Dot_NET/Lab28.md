# Lab Report 28: Implementation of Data Annotations in ASP.NET MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab28)-> Create  -> Select MVC -> OK

2. SolutionExplorer -> Lab28 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Register)

4. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Success)

5. Solution Explorer -> Lab28 -> Models(Right Click) -> Add -> Class -> Class Name (RegisterModel) -> Add

### RegisterModel.cs
```csharp
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Lab28.Models {
    public class RegisterModel {
        [Required(ErrorMessage = "Full Name is required")]
        public string FullName { get; set; }

        [Required(ErrorMessage = "Email is required")]
        [EmailAddress(ErrorMessage = "Invalid email format")]
        public string Email { get; set; }

        [Required(ErrorMessage = "Age is required")]
        [Range(18, 60, ErrorMessage = "Age must be between 18 and 60")]
        public int Age { get; set; }

        [Required(ErrorMessage = "Password is required")]
        [MinLength(6, ErrorMessage = "Password must be at least 6 characters")]
        public string Password { get; set; }
    }
}
```

### HomeController.cs
```csharp
using System.Web.Mvc;
using Lab28.Models;

namespace Lab28.Controllers {
    public class HomeController : Controller {
        [HttpGet]
        public ActionResult Register() {
            return View();
        }

        [HttpPost]
        public ActionResult Register(RegisterModel model) {
            if (ModelState.IsValid) {
                return View("Success", model);
            }
            return View(model);
        }
    }
}
```

### Register.cshtml
```html
@{
    ViewBag.Title = "Register";
}
@model Lab28.Models.RegisterModel
<h2>Registration Form</h2>

@using (Html.BeginForm()) {
    @Html.ValidationSummary(true, "", new { @class = "text-danger" })

    @Html.LabelFor(m => m.FullName)
    @Html.TextBoxFor(m => m.FullName, new { @class = "form-control" })
    @Html.ValidationMessageFor(m => m.FullName, "", new { @class = "text-danger" })
    <br />

    @Html.LabelFor(m => m.Email)
    @Html.TextBoxFor(m => m.Email, new { @class = "form-control" })
    @Html.ValidationMessageFor(m => m.Email, "", new { @class = "text-danger" })
    <br />

    @Html.LabelFor(m => m.Age)
    @Html.TextBoxFor(m => m.Age, new { @class = "form-control" })
    @Html.ValidationMessageFor(m => m.Age, "", new { @class = "text-danger" })
    <br />

    @Html.LabelFor(m => m.Password)
    @Html.PasswordFor(m => m.Password, new { @class = "form-control" })
    @Html.ValidationMessageFor(m => m.Password, "", new { @class = "text-danger" })
    <br />

    <button type="submit">Register</button>
}
```

### Success.cshtml
```html
@{
    ViewBag.Title = "Success";
}
@model Lab28.Models.RegisterModel

<h2>Registration Successful</h2>
<p><strong>Name:</strong> @Model.FullName</p>
<p><strong>Email:</strong> @Model.Email</p>
<p><strong>Age:</strong> @Model.Age</p>
```


