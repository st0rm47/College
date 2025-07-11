using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7 {
    internal class Program {
        static void Main(string[] args) {
            string a1 = "Welcome to .NET";
            string a2 = "\"Welcome to .NET\"";   
            string a3 = "\\Welcome to C#\\"; 
            string a4 = "Welcome to C#\nTwo";

            Console.WriteLine(a1);
            Console.WriteLine(a2);
            Console.WriteLine(a3);
            Console.WriteLine(a4);

            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
