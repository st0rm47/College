# Lab Report 33: Implementation of CRUD Operations using Entity Framework in ASP.NET MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab33)-> Create  -> Select MVC -> OK

2. Configure Entity Framework
    - Visual Studio → Tools → NuGet Package Manager → Manage NuGet Packages for Solution. 
    - Search for EntityFramework → Install for your project.

3. Configure Web.config
    - Solution Explorer  →  Web.Config
    - Add the Connection String below.
    ```xml
    <connectionStrings>
        <add name="DefaultConnection"
            connectionString="Data Source=.\SQLEXPRESS;Initial Catalog=StudentEF;Integrated Security=True"
            providerName="System.Data.SqlClient" />
    </connectionStrings>
    ```

4. Solution Explorer -> Lab33 -> Models(Right Click) -> Add -> Class -> Class Name (Student) -> Add
### Student.cs
```csharp
using System.ComponentModel.DataAnnotations;

namespace Lab33.Models {
    public class Student {
        public int Id { get; set; }

        [Required]
        public string Name { get; set; }

        public int Age { get; set; }

        public string Course { get; set; }
    }
}
```

5. Solution Explorer -> Lab33 -> Models(Right Click) -> Add -> Class -> Class Name (StudentContext) -> Add
### StudentContext.cs
```csharp
using System.Data.Entity;

namespace Lab33.Models {
    public class StudentContext : DbContext {
        public StudentContext() : base("DefaultConnection") { }

        public DbSet<Student> Students { get; set; }
    }
}
```


6.Enable Migrations and Create Database
 - Open Package Manager Console (Tools -> NuGet Package Manager -> Package Manager Console)
 - Run the following commands:
   ```
   Enable-Migrations
   Add-Migration InitialCreate
   Update-Database
   ```

7.Create CRUD Controller and Views
 SolutionExplorer -> Lab33 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller with views, using Entity Framework -> Add -> Model Class (Student) -> Data Context Class (StudentContext) -> Add




