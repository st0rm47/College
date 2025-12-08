# Lab Report 27: Implementation of ValidationMessage and ValidationSummary Helper methods in ASP.NET Core MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab27)-> Create  -> Select MVC -> OK

2. SolutionExplorer -> Lab27 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Register)

4. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Success)

### HomeController.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
namespace Lab27.Controllers
{
    public class HomeController : Controller
    {
        [HttpGet]
        public ActionResult Register()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Register(string FullName, string Email, int Age)
        {
            if (string.IsNullOrEmpty(FullName))
                ModelState.AddModelError("FullName", "Full Name is required");

            if (string.IsNullOrEmpty(Email))
                ModelState.AddModelError("Email", "Email is required");

            if (Age == null)
                ModelState.AddModelError("Age", "Age is required");

            // If validation fails, return same view
            if (!ModelState.IsValid)
            {
                return View();
            }

            // Success
            ViewBag.FullName = FullName;
            ViewBag.Email = Email;
            ViewBag.Age = Age;
            return View("Success");
        }
    }
}
```

### Register.cshtml
```html
@{
    ViewBag.Title = "Register";
}

<h2>Registration Form</h2>
@using (Html.BeginForm()) {
    @Html.ValidationSummary(true, "", new { @class = "text-danger" })

    <div>
        @Html.Label("FullName")
        @Html.TextBox("FullName", "", new { @class = "form-control" })
        @Html.ValidationMessage("FullName", "", new { @class = "text-danger" })
    </div> <br />

    <div>
        @Html.Label("Email")
        @Html.TextBox("Email", "", new { @class = "form-control" })
        @Html.ValidationMessage("Email", "", new { @class = "text-danger" })
    </div> <br />

    <div>
        @Html.Label("Age")
        @Html.TextBox("Age", "", new { @class = "form-control", type = "number"})
        @Html.ValidationMessage("Age", "", new { @class = "text-danger" })
    </div> <br />
    <button type="submit">Register</button>
}
```

### Success.cshtml
```html
@{
    ViewBag.Title = "Success";
}

<h2>Registration Successful</h2>
<p><strong>Name:</strong> @ViewBag.FullName</p>
<p><strong>Email:</strong> @ViewBag.Email</p>
<p><strong>Age:</strong> @ViewBag.Age</p>
```


