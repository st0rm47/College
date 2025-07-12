using System;

namespace Lab10a {
    internal class Program {
        static void Main(string[] args) {
            Console.WriteLine("Enter first number");
            float a = float.Parse(Console.ReadLine());
            Console.WriteLine("Enter second number");
            float b = float.Parse(Console.ReadLine());
            float c = a + b;
            Console.WriteLine(c);
            Console.WriteLine("\n Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
