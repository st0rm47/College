# Lab Report 22: Implementation of Razor View Engine (MVC-Model View Controller)

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab22)-> Create  -> Select Empty -> check MVC -> OK

2. SolutionExplorer -> Lab22 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

3. Solution Explorer -> Views -> Home -> Right Click -> Add -> View -> MVC5 View -> Add -> View Name (Index)
    
### HomeController.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace Lab22.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()
        {
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
<table border= "1"
       <tr>
           <th width= "100px">Name</th>
           <td width=" 100px">Value</td>
       </tr>
        <tr>
            <td>Day</td>
            <td>@DateTime.Now.Day</td>
        </tr>
        <tr>
            <td>Hour</td>
            <td>@DateTime.Now.Hour</td>
        </tr>
        <tr>
            <td>Minutes</td>
            <td>@DateTime.Now.Minute</td>
        </tr>
        <tr>
            <td>Second</td>
            <td>@DateTime.Now.Second</td>
        </tr>

</table>
```