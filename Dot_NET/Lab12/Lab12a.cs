using System;

namespace Lab12a {
    internal class Program {
        static void Main(string[] args) {
            int a = 30, b = 15, c, d, e, f, g;
            c = a + b;
            d = a - b;
            e = a / b; 
            f = a * b;
            g = a % b;

            Console.WriteLine($"a = {a}, b = {b}\n");
            Console.WriteLine($"Addition (a + b): {c}");
            Console.WriteLine($"Subtraction (a - b): {d}");
            Console.WriteLine($"Division (a / b): {e}");
            Console.WriteLine($"Multiplication (a * b): {f}");
            Console.WriteLine($"Modulus (a % b): {g}\n");

            Console.WriteLine("Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
