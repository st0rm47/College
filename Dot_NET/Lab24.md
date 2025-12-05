# Lab Report 24: Implementation of ViewData in ASP.NET MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab24)-> Create  -> Select Empty -> check MVC -> OK

2. SolutionExplorer -> Lab24 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Index)

### HomeController.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
namespace Lab24.Controllers {
    public class HomeController : Controller {
        // GET: Home
        public ActionResult Index() {
            ViewData["Name"] = "I am Subodh Ghimire";
            ViewData["Time"] = DateTime.Now.ToString("t");
            string[] cars = { "Toyota", "Honda", "Ford", "Chevrolet", "BMW" };
            ViewData["Cars"] = cars;
            return View();
        }
    }
}
```

### Index.cshtml
```html
@{
    ViewBag.Title = "Index";
}

<h2>Index</h2>
<p>@ViewData["Name"]</p> 
<p>@ViewData["Time"]</p>
<ul>
    @{ 
        foreach (string car in (string[])ViewData["Cars"]) {
                <li>@car</li>
        }
    }
</ul>
```