# Lab Report 25: Implementation of HTML Helper method in ASP.NET MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab25)-> Create  -> Select Empty -> check MVC -> OK

2. SolutionExplorer -> Lab25 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Index)

### HomeController.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
namespace Lab25.Controllers {
    public class HomeController : Controller {
        public ActionResult Index() {
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

<h2>Enter Your Details</h2>
@Html.Label("fullname", "Full Name:")
@Html.TextBox("fullname")
<br /> <br />

@Html.Label("message", "Message:")
@Html.TextArea("message")
<br /><br />

@Html.CheckBox("subscribe", false)
@Html.Label("subscribe", "Get News Updates")
```