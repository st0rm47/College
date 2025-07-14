using System;

namespace Lab13b {
    internal class Program {
        static void Main(string[] args) {
            int a = 40;
            int b = 30;
            bool c = (a > b) || (b < a);

            Console.WriteLine($"a = {a}, b = {b}\n");
            Console.WriteLine($"(a > b) || (b < a): {c}");
            Console.WriteLine("\n Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
