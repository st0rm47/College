# Lab Report 31: Implementation of JSON with jQuery

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab31)-> Create  -> Select MVC -> Click on Web API -> OK

2. SolutionExplorer -> Lab31 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Lab31 -> Models(Right Click) -> Add -> Class -> Class Name (Student) -> Add

4. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Index)


### Student.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Lab31.Models {
    public class Student {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Symbol { get; set; }
    }
}
```

### HomeController.cs
```csharp
using System.Collections.Generic;
using System.Web.Mvc;
using Lab31.Models;

namespace Lab31.Controllers {
    public class HomeController : Controller {
        public ActionResult Index() {
            return View();
        }

        public JsonResult GetStudents() {
            var students = new List<Student> {
                new Student { Id = 1, Name = "Subodh", Symbol = 79011027 },
                new Student { Id = 2, Name = "Priyanka", Symbol  = 79011017 },
            };

            return Json(students, JsonRequestBehavior.AllowGet);
        }
    }
}
```

### Index.cshtml
```html
@{
    ViewBag.Title = "Student List with jQuery JSON";
}

<h2>Student List</h2>

<button id="loadStudents">Load Students Data</button>

<!-- Table hidden initially -->
<table id="studentTable" border="1" style="display:none;">
    <thead>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Symbol</th>
        </tr>
    </thead>
    <tbody>
        <!-- Data will be inserted here -->
    </tbody>
</table>

@section Scripts {
    <script src="https://code.jquery.com/jquery-3.6.0.min.js"></script>
    <script type="text/javascript">
        $(document).ready(function () {
            $("#loadStudents").click(function () {
                $.ajax({
                    url: '@Url.Action("GetStudents", "Home")',
                    type: "GET",
                    dataType: "json",
                    success: function (data) {
                        var tbody = $("#studentTable tbody");
                        tbody.empty(); // Clear previous data

                        $.each(data, function (index, student) {
                            tbody.append(
                                "<tr>" +
                                    "<td>" + student.Id + "</td>" +
                                    "<td>" + student.Name + "</td>" +
                                    "<td>" + student.Symbol + "</td>" +
                                "</tr>"
                            );
                        });

                        // Show the table after data is loaded
                        $("#studentTable").show();
                    },
                    error: function () {
                        alert("Error loading data");
                    }
                });
            });
        });
    </script>
}
```