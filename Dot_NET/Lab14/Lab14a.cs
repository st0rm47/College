using System;

namespace Lab14a {
    internal class Program {
        static void Main(string[] args) {
            int x = 10;
            int y = 5;
            Console.WriteLine($"Initial values:\nx = {x}, y = {y}\n");
            x += y;
            Console.WriteLine($"After x += y:\nx = {x}");

            Console.WriteLine("\n Made by: Subodh Ghimire");
            Console.ReadLine();
        }
    }
}
