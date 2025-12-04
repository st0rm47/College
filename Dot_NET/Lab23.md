# Lab Report 23: Implementation of Action Methods in ASP.NET MVC

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab23)-> Create  -> Select Empty -> check MVC -> OK

2. SolutionExplorer -> Lab23 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Index)

4. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (About)

### HomeController.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab23.Controllers {
    public class HomeController : Controller {
        // GET: Home
        public ActionResult Index() {
            return View();
        }

        [HttpPost]
        public ActionResult About(string name, string message)
        {
            ViewBag.Name = name;
            ViewBag.Message = message;
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

<h2>Welcome</h2>
<p>Welcome to the Home Page</p>

<form method = "post" action = "/Home/About">
    <input type = "text" name = "name" placeholder = "Enter your name" />
    <br /><br />
    <textarea name = "message" placeholder = "Enter your message"></textarea>
    <br /><br />
    <button type = "submit">Submit</button>
</form>
```

### About.cshtml
```html
@{
    ViewBag.Title = "About";
}

<h2>About Me</h2>

<p>Thank you, @ViewBag.Name, for your message:</p>
<p><strong>@ViewBag.Message</strong></p>
```

