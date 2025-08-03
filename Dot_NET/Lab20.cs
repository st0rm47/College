using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab20
{
    public delegate void Calculations(int a, int b);
    internal class Program
    {
        public static void Addition(int a, int b)
        {
            int result = a + b;
            Console.WriteLine("Addition: " + result);
        }

        public static void Subtraction(int a, int b)
        {
            int result = a - b;
            Console.WriteLine("Subtraction: " + result);
        }

        public static void Multiplication(int a, int b)
        {
            int result = a * b;
            Console.WriteLine("Multiplication: " + result);
        }

        public static void Division(int a, int b)
        {
            if (b != 0)
            {
                double result = (double)a / b;
                Console.WriteLine("Division: " + result);
            }
            else
            {
                Console.WriteLine("Division by zero is not allowed.");
            }
        }

        static void Main(string[] args)
        {
            Calculations  calc = new Calculations(Program.Addition);
            calc.Invoke(10, 5);

            Calculations calc2 = new Calculations(Program.Subtraction);
            calc2.Invoke(10, 5);

            Calculations calc3 = new Calculations(Program.Multiplication);
            calc3.Invoke(10, 5);

            Calculations calc4 = new Calculations(Program.Division);
            calc4.Invoke(10, 5);

            Console.WriteLine("\n Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
