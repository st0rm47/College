# Lab Report 26: Creation of form with HTML Helper method in ASP.NET MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab26)-> Create  -> Select Empty -> check MVC -> OK

2. SolutionExplorer -> Lab26 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Register)

4. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (RegistrationSuccess)

### HomeController.cs
```csharp
using System.Web.Mvc;
namespace Lab26.Controllers {
    public class HomeController : Controller {
        public ActionResult Register() {
            return View();
        }

        [HttpPost]
        public ActionResult Register(string FullName, string Email, string Password, string Gender, string[] Hobbies, string Course, string Comments){
            ViewBag.FullName = FullName;
            ViewBag.Email = Email;
            ViewBag.Password = Password;
            ViewBag.Gender = Gender;
            ViewBag.Hobbies = Hobbies != null ? string.Join(", ", Hobbies) : "None selected";
            ViewBag.Course = Course;
            ViewBag.Comments = Comments;
            return View("RegistrationSuccess");
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
@using (Html.BeginForm("Register", "Home", FormMethod.Post))
{
    <div class="form-group">
        @Html.Label("Full Name:")
        <br />
        @Html.TextBox("FullName", "", new { @class = "form-control" })
        <br />

        @Html.Label("Email:")
        <br />
        @Html.TextBox("Email", "", new { @class = "form-control" })
        <br />

        @Html.Label("Password:")
        <br />
        @Html.Password("Password", "", new { @class = "form-control" })
        <br />

        @Html.Label("Gender:")
        <br />
        @Html.RadioButton("Gender", "Male") <span>Male</span>
        &nbsp;&nbsp;
        @Html.RadioButton("Gender", "Female") <span>Female</span>
        <br /><br />

        @Html.Label("Hobbies:")
        <br />
        @Html.CheckBox("Hobbies", false, new { value = "Coding" }) <span>Coding</span>
        &nbsp;&nbsp;
        @Html.CheckBox("Hobbies", false, new { value = "Music" }) <span>Music</span>
        &nbsp;&nbsp;
        @Html.CheckBox("Hobbies", false, new { value = "Sports" }) <span>Sports</span>
        <br /><br />

        @Html.Label("Course:")
        <br />
        @Html.DropDownList("Course",
            new SelectList(new[] { "BIT", "CSIT", "BCA" }),
            "Select Course")
        <br />
        <br />

        @Html.Label("Comments: ")
        <br />
        @Html.TextArea("Comments", "", new { rows = 4, cols = 40 })
        <br />
        <br />

        <button type="submit">Register</button>
}
```

### RegistrationSuccess.cshtml
```html

@{
    ViewBag.Title = "RegistrationSuccess";
}

<h2>Registration Successful</h2>

<p><strong>Name:</strong> @ViewBag.FullName</p>
<p><strong>Email:</strong> @ViewBag.Email</p>
<p><strong>Gender:</strong> @ViewBag.Gender</p>
<p><strong>Hobbies:</strong> @ViewBag.Hobbies</p>
<p><strong>Course:</strong> @ViewBag.Course</p>
<p><strong>Comments:</strong> @ViewBag.Comments</p>
```