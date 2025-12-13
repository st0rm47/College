# Lab Report 32: Implementation of ADO.NET in ASP.NET Framework for Database Connectivity

### Steps:
1. Create Database and Table in SSMS
 - Connect to your SQL Server Instance
 - Right Click on Database → New Database → Database Name(Student) → Ok
 - Create New Query → Write code below to create the Table(Students):
 - Source Code:
    ```sql
    USE Student;
    CREATE TABLE Students (
        Id INT PRIMARY KEY IDENTITY,
        Name VARCHAR(50),
        Age INT,
        Course VARCHAR(50)
    );
    INSERT INTO Students VALUES ('Subodh', 21, 'CSIT');
    INSERT INTO Students VALUES ('Saugat', 22, 'BBM');
    INSERT INTO Students VALUES ('Diwakar', 21, 'BIT');
    ```
    
2. Create ASP.NET MVC Project
 - Open Visual Studio → Create New Project → ASP.NET Core Web Application (.NET Framework) → Select Project Name → Create → Select MVC →OK

3. Install MySQL Connector
 - Visual Studio → Tools → NuGet Package Manager → Manage NuGet Packages for Solution. 
 - Search for MySql.Data → Install for your project. 

4. Configure Web.config
 - Solution Explorer  →  Web.Config
 - Add the Connection String below.
    ```xml
    <connectionStrings>
        <add name="DefaultConnection"
            connectionString="Data Source=.\SQLEXPRESS;Initial Catalog=Student;Integrated Security=True"
            providerName="System.Data.SqlClient" />
    </connectionStrings>
    ```

5. SolutionExplorer -> Lab32 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

6. Solution Explorer -> Lab32 -> Models(Right Click) -> Add -> Class -> Class Name (Student) -> Add

7. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Index)


### Student.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
namespace Lab32.Models {
    public class Student {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public string Course { get; set; }
    }

}
```

### HomeController.cs
```csharp
using System.Collections.Generic;
using System.Configuration;
using System.Data.SqlClient;
using System.Web.Mvc;
using Lab32.Models;

namespace Lab32.Controllers {
    public class HomeController : Controller {
        string cs= ConfigurationManager.ConnectionStrings["DefaultConnection"].ConnectionString;

        public ActionResult Index() {
            List<Student> students = new List<Student>();

            using (SqlConnection con = new SqlConnection(cs)) {
                SqlCommand cmd = new SqlCommand("SELECT * FROM Students", con);
                con.Open();
                SqlDataReader dr = cmd.ExecuteReader();

                while (dr.Read()) {
                    students.Add(new Student {
                        Id = (int)dr["Id"],
                        Name = dr["Name"].ToString(),
                        Age = (int)dr["Age"],
                        Course = dr["Course"].ToString()
                    });
                }
            }
            return View(students);
        }
    }
}
```

### Index.cshtml
```html
@{
    ViewBag.Title = "Home Page";
}
@model IEnumerable<Lab32.Models.Student>
<h2>Student List</h2>
<table border="1" style="border-collapse: collapse;">
    <thead>
        <tr>
            <th style="border: 1px solid black; padding: 5px;">ID</th>
            <th style="border: 1px solid black; padding: 5px;">Name</th>
            <th style="border: 1px solid black; padding: 5px;">Age</th>
            <th style="border: 1px solid black; padding: 5px;">Course</th>
        </tr>
    </thead>
    <tbody>
        @foreach (var item in Model)
        {
            <tr>
                <td style="border: 1px solid black; padding: 5px;">@item.Id</td>
                <td style="border: 1px solid black; padding: 5px;">@item.Name</td>
                <td style="border: 1px solid black; padding: 5px;">@item.Age</td>
                <td style="border: 1px solid black; padding: 5px;">@item.Course</td>
            </tr>
        }
    </tbody>
</table>
```