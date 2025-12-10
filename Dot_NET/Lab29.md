# Lab Report 29: Implementation of Attribute Based Routing in ASP.NET Core MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab29)-> Create  -> Select MVC -> OK

2. SolutionExplorer -> Lab29 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Index)

4. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Student)

5. Solution Explorer -> App_Start -> RouteConfig.cs -> Modify for Attribute Routing

### RouteConfig.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;
namespace Lab29 {
    public class RouteConfig {
        public static void RegisterRoutes(RouteCollection routes){
            routes.IgnoreRoute("{resource}.axd/{*pathInfo}");

            // Enable Attribute Routing
            routes.MapMvcAttributeRoutes();

            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{id}",
                defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional }
            );
        }
    }
}
```

### HomeController.cs
```csharp
using System.Web.Mvc;
namespace Lab29.Controllers {
    [RoutePrefix("home")]
    public class HomeController : Controller {
        [HttpGet]
        [Route("")]
        public ActionResult Index() {
            return View();
        }

        [HttpGet]
        [Route("student/{id:int}/{name}")]
        public ActionResult Student(int id, string name)
        {
            ViewBag.Id = id;
            ViewBag.Name = name;
            return View();
        }
    }
}
```

### Index.cshtml
```html
@{
    ViewBag.Title = "Home Page";
}
<h2>Home Page</h2>
<p>Welcome to Attribute Routing Example</p>
```

### Student.cshtml
```html
@{
    ViewBag.Title = "Student";
}

<h2>Student Page</h2>
<p>Student ID: @ViewBag.Id</p>
<p>Student Name: @ViewBag.Name</p>
```


