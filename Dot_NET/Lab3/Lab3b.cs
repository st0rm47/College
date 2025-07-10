using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3b {
    internal class Program {
        static void Main(string[] args) {
            Console.WriteLine("Enter your First name:");
            string fName = Console.ReadLine();
            Console.WriteLine("Enter your Last name:");
            string lName = Console.ReadLine();
            Console.WriteLine("Your Full Name is: {0} {1}", fName,lName);
            Console.ReadLine();
        }
    }
}
