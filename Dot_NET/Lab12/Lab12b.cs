using System;

namespace Lab12b {
    internal class Program {
        static void Main(string[] args) {
            int a = 10;
            int b = 20;

            Console.WriteLine($"a = {a}, b = {b}\n");
            Console.WriteLine($"Is a equal to b?                 {a == b}");
            Console.WriteLine($"Is a not equal to b?             {a != b}");
            Console.WriteLine($"Is a greater than b?             {a > b}");
            Console.WriteLine($"Is a less than b?                {a < b}");
            Console.WriteLine($"Is a greater than or equal to b? {a >= b}");
            Console.WriteLine($"Is a less than or equal to b?    {a <= b}");
            Console.WriteLine("\nMade by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
