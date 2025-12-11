# Lab Report 30: Implementation of ASP.NET Web Application for XML/JSON format

### Steps
1. Visual Studio -> Create New Project -> ASP.NET Core Web Application (.NET Framework) -> Select Project Name(Lab30)-> Create  -> Select MVC -> Click on Web API -> OK

2. SolutionExplorer -> Lab30 -> Controller(Right Click) -> Add Controller -> MVC 5 Controller-Empty -> ControllerName (HomeController) -> Add

4. Solution Explorer -> Lab30 -> Models(Right Click) -> Add -> Class -> Class Name (Student) -> Add

4. Solution Explorer -> Lab30 -> Models(Right Click) -> Add -> Class -> Class Name (XmlResult) -> Add

### Student.cs
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace Lab30.Models {
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
using System.Web.Razor.Tokenizer.Symbols;
using Lab30.Models;

namespace Lab30.Controllers {
    public class HomeController : Controller {
        public ActionResult JsonData() {
            var students = new Student {
                Id = 1,
                Name = "Subodh Ghimire",
                Symbol = 79011027
            };
            return Json(students, JsonRequestBehavior.AllowGet);
        }

        public ActionResult XmlData() {
            var students = new Student {
                Id = 1,
                Name = "Subodh Ghimire",
                Symbol = 79011027
            };
            return new XmlResult(students);
        }
    }
}
```

### XMLResult.cs
```csharp
using System.Text;
using System.Web.Mvc;
using System.Xml.Serialization;
using System.IO;

namespace Lab30.Controllers {
    public class XmlResult : ActionResult{
        private object _data;

        public XmlResult(object data){
            _data = data;
        }

        public override void ExecuteResult(ControllerContext context){
            if (_data == null) return;

            context.HttpContext.Response.ContentType = "application/xml";

            var serializer = new XmlSerializer(_data.GetType());
            using (var writer = new StringWriter()){
                serializer.Serialize(writer, _data);
                context.HttpContext.Response.Write(writer.ToString());
            }
        }
    }
}
```